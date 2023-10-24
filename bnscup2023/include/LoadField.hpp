#pragma once

#include <Siv3D.hpp>

namespace bnscup2023 {
	static Grid<int> LoadCSVField(const String& path, int width, int height) {
		const CSV csv{ U"Assets\\Fields\\" + path };

		if (not csv) // もし読み込みに失敗したら
		{
			throw Error{ U"Failed to load `config.csv`" };
		}

		Grid<int> out_data{ Size{width, height}, -1 };

		for (size_t row = 0; row < csv.rows(); ++row)
		{
			for (size_t column = 0; column < csv.columns(row); column++) {
				out_data[row][column] = Parse<int>(csv[row][column]);
			}
		}

		return out_data;
	}
}
