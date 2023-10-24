#include "../include/Tilemap.hpp"

namespace bnscup2023 {
	void TileMap::update() {

	}
	void TileMap::draw() const {
		for (int y = 0; y < Height; y++) {
			for (int x = 0; x < Width; x++) {
				this->field[y][x]->draw(
					BaseTile::TileSize * x, BaseTile::TileSize * y
				);
			}
		}
	}
}
