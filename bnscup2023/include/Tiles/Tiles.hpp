#pragma once
#include <Siv3D.hpp>
#include "BaseTile.hpp"
#include "HasWaterTile.hpp"

namespace bnscup2023 {
	class ErrorTile : public BaseTile {
	public:
		ErrorTile() = default;
		ErrorTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_collisionable = false;
		}
	};
	class AirTile : public BaseTile {
	public:
		AirTile() = default;
		AirTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_collisionable = false;
		}
	};
	class NormalTile : public BaseTile {
	public:
		NormalTile() = default;
		NormalTile(String texture_name) {
			this->texture_asset_name = texture_name;
		}
	};
	class MessageBoxTile : public BaseTile {
	private:
		void whenAccessed(Player& /*player*/) override {
			Console << U"Hi, I'm MessageTile!!";
		}
	public:
		MessageBoxTile() = default;
		MessageBoxTile(String texture_name) {
			this->texture_asset_name = texture_name;
		}
	};
	class LadderTile : public BaseTile {
	public:
		LadderTile() = default;
		LadderTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_climbable = true;
		}
	};
	class PuddleTile : public HasWaterTile {
	public:
		PuddleTile() = default;
		PuddleTile(String texture_name) {
			this->texture_asset_name = texture_name;
		}
	};
}
