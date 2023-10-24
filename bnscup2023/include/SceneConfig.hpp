#pragma once

#include <Siv3D.hpp> // Siv3D v0.6.12
#include "Tilemap.hpp"
#include "Tile.hpp"
#include "TileAssets.hpp"

using namespace bnscup2023;

struct GameData {
	TileAssets tile_assets;
	GameData() {
		tile_assets.add<ErrorTile>(U"error");
		tile_assets.add<AirTile>(U"air");
		tile_assets.add<NormalGroundTile>(U"normal_ground");
	}
};

using App = SceneManager<String, GameData>;
