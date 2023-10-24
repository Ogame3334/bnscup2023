#pragma once
#include <Siv3D.hpp>
#include "TileAssets.hpp"
#include "LoadField.hpp"

namespace bnscup2023 {
	class TileMap {
	private:
		TileAssets& tile_assets;
		Grid<int> field{ Width, Height, -1};
	public:
		inline static constexpr int Width = 32;
		inline static constexpr int Height = 18;

		void operator = (const TileMap& tm) {
			this->tile_assets = tm.tile_assets;
			this->field = tm.field;
		}
		void operator = (TileMap&& tm) {
			this->tile_assets = tm.tile_assets;
			this->field = tm.field;
		}
		TileMap(TileAssets& ta) : tile_assets(ta) {}
		TileMap(TileAssets& ta, const Grid<int>& _field) : tile_assets(ta), field(_field) {}
		TileMap(TileAssets& ta, Grid<int>&& _field) : tile_assets(ta), field(_field) {}
		TileMap(TileAssets& ta, String&& field_data) : tile_assets(ta), field(LoadCSVField(field_data, Width, Height)) {}
		void update();
		void draw() const;
	};
}
