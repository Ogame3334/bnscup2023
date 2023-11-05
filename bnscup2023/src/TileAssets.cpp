#include "../include/TileAssets.hpp"

using namespace bnscup2023;

BaseTile TileAssets::operator[] (String&& key) {
	for (auto asset : this->assets) {
		if (asset.first == key) return asset.second->getTile();
	}
	return this->assets[0].second->getTile();
}
