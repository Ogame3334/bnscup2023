#pragma once
#include <Siv3D.hpp>
#include "BaseTile.hpp"

namespace bnscup2023 {
	class AirTile : public BaseTile {
	public:
		AirTile() = default;
		AirTile(String texture_name) { this->texture_asset_name = texture_name; }
	};
}
