#pragma once

#include <Siv3D.hpp>

namespace bnscup2023 {
	class BaseTile {
	protected:
		//Texture texture;
		String texture_asset_name;
	public:
		inline static int TileSize = 40;

		void draw(int x, int y) const { Rect{ x, y, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void draw(Vec2 pos) const { Rect{ pos.asPoint(), TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void drawAt(int x, int y) const { Rect{ x - TileSize / 2, y - TileSize / 2, TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
		void drawAt(Vec2 pos) const { Rect{ (pos - Vec2{TileSize / 2, TileSize / 2}).asPoint(), TileSize }(TextureAsset(this->texture_asset_name).resized(TileSize)).draw(); }
	};
}
