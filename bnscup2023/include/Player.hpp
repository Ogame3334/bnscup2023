#pragma once

namespace bnscup2023 {
	enum class PLAYERPOSE {
		LEFT,
		LEFT_WALK,
		LEFT_JUMP,
		RIGHT,
		RIGHT_WALK,
		RIGHT_JUMP,
	};

	class Player {
	private:
		Vec2 pos;
		Vec2 vel;
		Point focusedPos;
		// TODO: プレイヤーアセットの保持
		PLAYERPOSE pose;
		
	public:
		Player() {}

		bool access();
		void update();
		void draw() const;
	};
}
