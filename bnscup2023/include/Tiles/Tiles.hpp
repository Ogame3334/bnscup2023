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
		inline constexpr bool getIsAir() const noexcept override { return true; }
	};
	class NormalTile : public BaseTile {
	public:
		NormalTile() = default;
		NormalTile(String texture_name) {
			this->texture_asset_name = texture_name;
		}
	};
	class NormalNotCollisionTile : public BaseTile {
	public:
		NormalNotCollisionTile() = default;
		NormalNotCollisionTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_collisionable = false;
		}
	};
	class MessageBoxTile : public BaseTile {
	private:
		void whenAccessed(Player& /*player*/) override {
			Print << U"Hi, I'm MessageTile!!";
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
			this->is_collisionable = false;
		}
	};
	class PuddleTile : public HasWaterTile {
	public:
		PuddleTile() = default;
		PuddleTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->water_amount = 1;
		}
	};
	class VineBudTile : public BaseTile {
	public:
		VineBudTile() = default;
		VineBudTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_collisionable = false;
		}
		void whenAccessed(Player&) override;
	};
	class VineTile : public BaseTile {
	private:
		static constexpr int GrowMillisec = 500;
		int past_millisec = 0;
	public:
		VineTile() = default;
		VineTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_climbable = true;
			this->is_collisionable = false;
		}

		void update(TileMap&, Point) override;
	};
	class RootTile : public BaseTile {
	private:
		bool is_opened = false;
	public:
		RootTile() = default;
		RootTile(String texture_name) {
			this->texture_asset_name = texture_name;
		}

		void whenAccessed(Player&) override;
		void update(TileMap&, Point) override;
	};
	class GoalRootTile : public BaseTile {
	private:
		inline static bool isOpened = false;
	public:
		GoalRootTile() = default;
		GoalRootTile(String texture_name) {
			this->texture_asset_name = texture_name;
		}

		void whenAccessed(Player&) override;
		void update(TileMap&, Point) override;
	};
	class LavaTile : public BaseTile {
	protected:
		inline static bool is_cold = false;
	public:
		LavaTile() = default;
		LavaTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_lava = true;
			this->is_collisionable = false;
		}

		void reset() override { this->is_cold = false; }
		void whenAccessed(Player&) override;
		void update(TileMap&, Point) override;
	};
	class LavaOneTile : public LavaTile {
	public:
		LavaOneTile() = default;
		LavaOneTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_lava = true;
			this->is_collisionable = false;
		}
		void update(TileMap&, Point) override;
	};
	class LavaEndTile : public LavaTile {
	public:
		LavaEndTile() = default;
		LavaEndTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_lava = true;
			this->is_collisionable = false;
		}
		void update(TileMap&, Point) override;
	};
}
