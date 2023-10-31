#include "../include/Siv3DKunAnimation.hpp"

using namespace bnscup2023;

TextureRegion Siv3DKunAnimation::getTextureWithIndex(int _index) const {
	int x = _index % 6;
	int y = _index / 6;
	return this->texture(x * 20, y * 20, 20, 20);
}
TextureRegion Siv3DKunAnimation::calcDrawTexture() const {
	int64 t;
	int64 padding = 0;
	switch (this->state)
	{
	case PlayerState::Left:
	case PlayerState::Right:
	case PlayerState::Behind:
		t = 0;
		break;
	default:
		t = Time::GetMillisec() - this->anim_start;
		break;
	}
	auto state_num = static_cast<int>(this->state);
	if (state_num == 6 or state_num == 7 or state_num == 8 or state_num == 9) {
		return this->getTextureWithIndex(this->index + 18 + (state_num - 6) * 12).scaled(2);
	}
	else {
		switch (this->state)
		{
		case PlayerState::Left:
		case PlayerState::LeftWalk:
			padding = 0;
			break;
		case PlayerState::Right:
		case PlayerState::RightWalk:
			padding = 6;
			break;
		case PlayerState::Behind:
		case PlayerState::UpDown:
			padding = 12;
		default:
			break;
		}
		return this->getTextureWithIndex(this->pattern[t / static_cast<int>(500 / this->anim_speed) % 4] + static_cast<int>(padding) + (this->has_water ? 3 : 0)).scaled(2);
	}
}
void Siv3DKunAnimation::update() {
	if (this->state != this->pre_state) {
		this->pre_state = this->state;
		this->anim_start = Time::GetMillisec();
	}
	auto t = Time::GetMillisec() - this->anim_start;
	auto state_num = static_cast<int>(this->state);
	this->index = t / static_cast<int>(500 / this->anim_speed) % 12;
	if (state_num == 6 or state_num == 7 or state_num == 8 or state_num == 9) {
		if (this->index == 11) {
			if (state_num == 6 or state_num == 8) {
				this->state = PlayerState::Left;
			}
			else {
				this->state = PlayerState::Right;
			}
			if (state_num == 6 or state_num ==7) {
				this->has_water = true;
			}
			else {
				this->has_water = false;
			}
		}
	}
	Print << state_num;
}

TextureRegion Siv3DKunAnimation::getNowTexture() const {
	//const ScopedRenderStates2D sampler{ SamplerState::ClampNearest };
	return this->calcDrawTexture();
}
