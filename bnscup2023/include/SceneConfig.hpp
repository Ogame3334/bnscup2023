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
		tile_assets.add<MessageBoxTile>(U"message_box");
		tile_assets.add<LadderTile>(U"ladder");
		tile_assets.add<PuddleTile>(U"puddle_full");
	}
};

using App = SceneManager<String, GameData>;
