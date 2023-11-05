#include "../../include/Tiles/Tiles.hpp"
#include "../../include/Tilemap.hpp"
#include "../../include/Player.hpp"

using namespace bnscup2023;

void VineBudTile::whenAccessed(Player& player) {
	if (player.hasWater()) {
		player.setCanProcessing(false);
		player.useBucket();
		TileMap& temp_tm = player.getTileMapRef();
		temp_tm.changeTile(player.getFocusedPos(), U"vine");
	}
}

void VineTile::update(TileMap& tm, Point pos) {
	this->past_millisec += static_cast<int>(Scene::DeltaTime() * 1000);
	if (this->past_millisec > GrowMillisec) {
		this->past_millisec = 0;
		if(tm.at(pos.x, pos.y - 1).getIsAir()) tm.changeTile(pos.x, pos.y - 1, U"vine");
	}
}

void GoalRootTile::whenAccessed(Player& player) {
	if (player.hasWater()) {
		player.setCanProcessing(false);
		player.useBucket();
		this->isOpened = true;
	}
}
void GoalRootTile::update(TileMap&, Point) {
	if (this->isOpened) {
		this->texture_asset_name = U"goal_root_opened";
		this->is_collisionable = false;
	}
}

void LavaTile::whenAccessed(Player& player) {
	if (player.hasWater()) {
		player.setCanProcessing(false);
		player.useBucket();
		this->is_cold = true;
		this->is_lava = false;
	}
}
void LavaTile::update(TileMap&, Point) {
	if (this->is_cold) {
		this->texture_asset_name = U"lava_cold";
		this->is_lava = false;
		this->is_collisionable = true;
	}
}
void LavaOneTile::update(TileMap&, Point) {
	if (this->is_cold) {
		this->texture_asset_name = U"lava_one_cold";
		this->is_lava = false;
		this->is_collisionable = true;
	}
}
void LavaEndTile::update(TileMap&, Point) {
	if (this->is_cold) {
		this->texture_asset_name = U"lava_end_cold";
		this->is_lava = false;
		this->is_collisionable = true;
	}
}
