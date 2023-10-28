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
		bool isCollisionable = true;
		bool isClimbable = false;
	public:
		inline static int TileSize = 40;
		BaseTile() = default;
		BaseTile(const BaseTile& other) : texture_asset_name(other.texture_asset_name), isCollisionable(other.isCollisionable), isClimbable(other.isClimbable) {}

		void access(Player& player) { this->whenAccessed(player); };

		void setCollisionable(bool cond) { this->isCollisionable = cond; }
		bool getCollisionable() const noexcept { return this->isCollisionable; }
		void setClimbable(bool cond) { this->isClimbable = cond; }
		bool getClimbable() const noexcept { return this->isClimbable; }

		void draw(int x, int y) const { Rect{ x, y, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void draw(Point pos) const { this->draw(pos.x, pos.y); }
		void drawAt(int x, int y) const { Rect{ x - TileSize / 2, y - TileSize / 2, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void drawAt(Point pos) const { this->drawAt(pos.x, pos.y); }
	};
}
