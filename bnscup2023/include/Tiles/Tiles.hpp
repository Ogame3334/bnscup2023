#pragma once
#include <Siv3D.hpp>
#include "BaseTile.hpp"

namespace bnscup2023 {
	class ErrorTile : public BaseTile {
	public:
		ErrorTile() = default;
		ErrorTile(String texture_name) { this->texture_asset_name = texture_name; }
	};
	class AirTile : public BaseTile {
	public:
		AirTile() = default;
		AirTile(String texture_name) { this->texture_asset_name = texture_name; }
	};
	class NormalGroundTile : public BaseTile {
	public:
		NormalGroundTile() = default;
		NormalGroundTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->isCollisionable = true;
		}
	};
}
