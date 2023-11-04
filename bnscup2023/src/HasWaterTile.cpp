#include "../include/Player.hpp"
#include "../include/Tiles/HasWaterTile.hpp"

using namespace bnscup2023;

void HasWaterTile::updateTexture() {
	if (this->water_amount == 0) this->texture_asset_name = U"puddle_empty";
	else this->texture_asset_name = U"puddle_full";
}

void HasWaterTile::whenAccessed(Player& player) {
	if (this->water_amount == 0 and player.hasWater()) {
		player.setCanProcessing(false);
		player.useBucket();
		this->addWater();
	}
	else if (not (this->water_amount == 0) and not player.hasWater()) {
		player.setCanProcessing(false);
		player.fillBucket();
		this->subWater();
	}
	this->updateTexture();
}
