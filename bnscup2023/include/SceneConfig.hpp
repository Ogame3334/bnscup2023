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
		tile_assets.add<NormalTile>(U"wall_left", U"wall"); // 2
		tile_assets.add<NormalTile>(U"wall_inside"); // 3
		tile_assets.add<NormalTile>(U"wall_right", U"wall").setHoriFlip(true); // 4
		tile_assets.add<NormalTile>(U"floor_end_lower_left", U"floor_end_lower"); // 5
		tile_assets.add<NormalTile>(U"floor_end_lower_right", U"floor_end_lower").setHoriFlip(true); // 6
		tile_assets.add<NormalTile>(U"floor_end_upper_left", U"floor_end_upper"); // 7
		tile_assets.add<NormalTile>(U"floor_end_upper_right", U"floor_end_upper").setHoriFlip(true); // 8
		tile_assets.add<NormalTile>(U"floor_end_island_left", U"floor_end_island"); // 9
		tile_assets.add<NormalTile>(U"floor_end_island_right", U"floor_end_island").setHoriFlip(true); // 10
		tile_assets.add<PuddleTile>(U"puddle", U"puddle_full"); // 11
		TextureAsset::Register(U"puddle_empty", U"Assets/Textures/Tiles/puddle_empty.png");
		tile_assets.add<LadderTile>(U"ladder"); // 12
		tile_assets.add<VineBudTile>(U"vine_bud"); // 13
		tile_assets.add<VineTile>(U"vine"); // 14
		tile_assets.add<GoalRootTile>(U"goal_root", U"goal_root_closed"); // 15
		TextureAsset::Register(U"goal_root_opened", U"Assets/Textures/Tiles/goal_root_opened.png");
		tile_assets.add<LavaEndTile>(U"lava_left", U"lava_end"); // 16
		tile_assets.add<LavaTile>(U"lava", U"lava"); // 17
		TextureAsset::Register(U"lava_cold", U"Assets/Textures/Tiles/lava_cold.png");
		tile_assets.add<LavaEndTile>(U"lava_right", U"lava_end").setHoriFlip(true); // 18
		TextureAsset::Register(U"lava_end_cold", U"Assets/Textures/Tiles/lava_end_cold.png");
		tile_assets.add<LavaOneTile>(U"lava_one"); // 19
		TextureAsset::Register(U"lava_one_cold", U"Assets/Textures/Tiles/lava_one_cold.png");
		tile_assets.add<MessageBoxTile>(U"message_box"); // 20
	}
};

using App = SceneManager<String, GameData>;
