#pragma once

#include <Siv3D.hpp>

namespace bnscup2023 {
	class Player;
	class BaseTile {
	private:
		virtual void whenAccessed(Player& /*player*/) {};
	protected:
		//Texture texture;
		String texture_asset_name = U"";
		bool is_collisionable = true;
		bool is_climbable = false;
		bool is_flip_vertically = false;
		bool is_flip_horizontally = false;
	public:
		inline static int TileSize = 40;
		BaseTile() = default;
		BaseTile(const BaseTile& other) :
			texture_asset_name(other.texture_asset_name),
			is_collisionable(other.is_collisionable),
			is_climbable(other.is_climbable),
			is_flip_vertically(other.is_flip_vertically),
			is_flip_horizontally(other.is_flip_horizontally)
		{}

		void access(Player& player) { this->whenAccessed(player); };

		void setCollisionable(bool cond) { this->is_collisionable = cond; }
		bool getCollisionable() const noexcept { return this->is_collisionable; }
		void setClimbable(bool cond) { this->is_climbable = cond; }
		bool getClimbable() const noexcept { return this->is_climbable; }
		void setVertFlip(bool cond) { this->is_flip_vertically = cond; }
		bool getVertFlip() const noexcept { return this->is_flip_vertically; }
		void setHoriFlip(bool cond) { this->is_flip_horizontally = cond; }
		bool getHoriFlip() const noexcept { return this->is_flip_horizontally; }

		void draw(int x, int y) const {
			auto temp = TextureAsset(this->texture_asset_name).resized(TileSize);
			if (this->is_flip_horizontally) temp = temp.mirrored();
			if (this->is_flip_vertically) temp = temp.flipped();
			Rect{ x, y, TileSize }(temp).draw();
		}
		void draw(Point pos) const { this->draw(pos.x, pos.y); }
		void drawAt(int x, int y) const { this->draw(x - TileSize / 2, y - TileSize / 2); }
		void drawAt(Point pos) const { this->drawAt(pos.x, pos.y); }
	};
}
