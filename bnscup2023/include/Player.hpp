#pragma once
#include "TileAssets.hpp"
#include "TileMap.hpp"

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
		TileAssets& tile_assets;
		TileMap& tile_map;
		
	public:
		// Player() {}
		Player(TileAssets& ta, TileMap& tm)
			: tile_assets(ta), tile_map(tm) {}

		void access();
		void update();
		void draw() const;
	};
}
