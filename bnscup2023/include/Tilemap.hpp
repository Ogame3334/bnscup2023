#pragma once
#include <Siv3D.hpp>
#include "TileAssets.hpp"
#include "LoadField.hpp"

namespace bnscup2023 {
	class TileAssets;
	class TileMap {
	private:
		TileAssets& tile_assets;
		Grid<std::shared_ptr<BaseTile>> field{ Size{Width, Height}, std::shared_ptr<BaseTile>(nullptr) };

		Grid<std::shared_ptr<BaseTile>> ConvertToTileMap(const Grid<int>& field_id);
	public:
		inline static constexpr int Width = 32;
		inline static constexpr int Height = 18;

		void operator = (const TileMap& tm);
		void operator = (TileMap&& tm);
		TileMap(TileAssets& ta) : tile_assets(ta) {}
		TileMap(TileAssets& ta, const Grid<std::shared_ptr<BaseTile>>& _field) : tile_assets(ta), field(_field) {}
		TileMap(TileAssets& ta, Grid<std::shared_ptr<BaseTile>>&& _field) : tile_assets(ta), field(_field) {}
		TileMap(TileAssets& ta, String&& field_data) : tile_assets(ta), field(ConvertToTileMap(LoadCSVField(field_data, Width, Height))) {}

		BaseTile& at(int x, int y) { return *(this->field[y][x]); }
		BaseTile& at(Point pos) { return this->at(pos.x, pos.y); }

		void update();
		void draw() const;
	};
}
