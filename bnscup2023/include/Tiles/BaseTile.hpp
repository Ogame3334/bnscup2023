#pragma once

#include <Siv3D.hpp>

namespace bnscup2023 {
	class BaseTile {
	private:
		virtual void whenAccessed() {};
	protected:
		//Texture texture;
		String texture_asset_name;
		bool isCollisionable;
	public:
		inline static int TileSize = 40;
		BaseTile() : texture_asset_name(U""), isCollisionable(false) {}
		BaseTile(const BaseTile& other) : texture_asset_name(other.texture_asset_name), isCollisionable(other.isCollisionable) {}

		void access() { this->whenAccessed(); };

		void setCollisionable(bool cond) { this->isCollisionable = cond; }
		bool getCollisionable() const noexcept { return this->isCollisionable; }

		void draw(int x, int y) const { Rect{ x, y, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void draw(Point pos) const { this->draw(pos.x, pos.y); }
		void drawAt(int x, int y) const { Rect{ x - TileSize / 2, y - TileSize / 2, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void drawAt(Point pos) const { this->drawAt(pos.x, pos.y); }
	};
}
