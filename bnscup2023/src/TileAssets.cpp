#include "../include/TileAssets.hpp"

using namespace bnscup2023;

BaseTile TileAssets::operator[] (String&& key) {
	for (const auto& asset : this->assets) {
		if (asset.first == key) return *(asset.second);
	}
	return *(this->assets[0].second);
}
