#include "../include/Tilemap.hpp"

namespace bnscup2023 {
	Grid<std::shared_ptr<BaseTile>> TileMap::ConvertToTileMap(const Grid<int>& field_id) {
		Grid<std::shared_ptr<BaseTile>> out_field{ field_id.size() };

		for (int y = 0; y < field_id.height(); y++) {
			for (int x = 0; x < field_id.width(); x++) {
				out_field[y][x] = tile_assets.getNewPtr(field_id[y][x]);
			}
		}

		return out_field;
	}

	void TileMap::operator = (const TileMap& tm) {
		this->tile_assets = tm.tile_assets;
		this->field = tm.field;
	}
	void TileMap::operator = (TileMap&& tm) {
		this->tile_assets = tm.tile_assets;
		this->field = tm.field;
	}

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
