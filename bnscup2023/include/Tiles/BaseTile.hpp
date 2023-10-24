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

		void access() { this->whenAccessed(); };

		void setCollisionable(bool cond) { this->isCollisionable = cond; }
		bool getCollisionable() const noexcept { return this->isCollisionable; }

		void draw(int x, int y) const { Rect{ x, y, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void draw(Vec2 pos) const { Rect{ pos.asPoint(), TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void drawAt(int x, int y) const { Rect{ x - TileSize / 2, y - TileSize / 2, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void drawAt(Vec2 pos) const { Rect{ (pos - Vec2{TileSize / 2, TileSize / 2}).asPoint(), TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
	};
}
