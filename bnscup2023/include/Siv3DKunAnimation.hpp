#pragma once

#include <Siv3D.hpp>

namespace bnscup2023 {
	enum class PlayerState {
		Left,
		Right,
		LeftWalk,
		RightWalk,
		Behind,
		UpDown,
		LeftGetWater,
		RightGetWater,
		LeftSprinkleWater,
		RightSprinkleWater,
	};
	class Siv3DKunAnimation {
	private:
		PlayerState state = PlayerState::Right;
		PlayerState pre_state = PlayerState::Right;
		Texture texture{ U"Assets/Player/siv3d-kun-bnscup2023.png" };
		std::array<int, 4> pattern = { 1, 0, 1, 2 };
		bool has_water = false;
		int64 anim_start = 0;
		int index = 0;
 
		static constexpr double anim_speed = 2;

		TextureRegion getTextureWithIndex(int _index) const;
		TextureRegion calcDrawTexture() const;
	public:
		constexpr void setState(PlayerState _state) {
			switch (this->state)
			{
			case PlayerState::LeftGetWater:
			case PlayerState::RightGetWater:
			case PlayerState::LeftSprinkleWater:
			case PlayerState::RightSprinkleWater:
				break;
			default:
				this->state = _state;
			}
		}
		constexpr PlayerState getState() const noexcept { return this->state; }
		constexpr void setHasWater(bool hasWater) { this->has_water = hasWater; }
		constexpr bool getHasWater() const noexcept { return this->has_water; }
		/// @brief const ScopedRenderStates2D sampler{ SamplerState::ClampNearest };を記述して描画してください。
		/// @return 現在描画するテクスチャ
		TextureRegion getNowTexture() const;

		void update();
	};
}
