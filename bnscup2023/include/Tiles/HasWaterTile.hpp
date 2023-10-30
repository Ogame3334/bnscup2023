#pragma once

#include "BaseTile.hpp"

namespace bnscup2023 {
	class HasWaterTile : public BaseTile {
	protected:
		int water_amount = 0;
	public:
		HasWaterTile() = default;
		HasWaterTile(String texture_name) {
			this->texture_asset_name = texture_name;
			this->is_climbable = true;
		}

		[[deprecated]]
		constexpr void setWaterAmount(int wa) { this->water_amount = wa; }
		inline constexpr int getWaterAmount() const noexcept { return this->water_amount; }
		constexpr void addWater() { this->water_amount++; }
		constexpr void subWater() {
			this->water_amount--;
			if (this->water_amount > 0) this->water_amount = 0;
		}

	private:
		void whenAccessed(Player& /*player*/) override {
			// TODO ここにプレイヤーとの水の繋がりを書く
			if (this->water_amount == 0); // TODO テクスチャの変更
			/*else*/ // TODO テクスチャの変更
		}
	};
}
