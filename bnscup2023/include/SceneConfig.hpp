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
		tile_assets.add<NormalTile>(U"floor"); // 1
		tile_assets.add<NormalTile>(U"wall_inside"); // 2
		tile_assets.add<NormalTile>(U"wall_left", U"wall"); // 3
		tile_assets.add<NormalTile>(U"wall_right", U"wall").setHoriFlip(true); // 4
		tile_assets.add<NormalTile>(U"floor_end_lower_left", U"floor_end_lower"); // 5
		tile_assets.add<NormalTile>(U"floor_end_lower_right", U"floor_end_lower").setHoriFlip(true); // 6
		tile_assets.add<NormalTile>(U"floor_end_upper_left", U"floor_end_upper"); // 7
		tile_assets.add<NormalTile>(U"floor_end_upper_right", U"floor_end_upper").setHoriFlip(true); // 8
		tile_assets.add<PuddleTile>(U"puddle_full"); // 9
		tile_assets.add<MessageBoxTile>(U"message_box"); // 10
		tile_assets.add<LadderTile>(U"ladder"); // 11
	}
};

using App = SceneManager<String, GameData>;
