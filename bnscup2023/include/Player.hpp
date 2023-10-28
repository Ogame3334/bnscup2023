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
		static constexpr double walk_speed = 1e-1;
		static constexpr double jump_speed = 2e-1;
		static constexpr double G = 1e-2;
		Vec2 pos = Vec2(0, 0);
		Vec2 vel = Vec2(0, 0);
		Point focusedPos;
		// TODO: プレイヤーアセットの保持
		PLAYERPOSE pose;
		TileAssets& tile_assets;
		TileMap& tile_map;
		double dt;
		bool falling = false;
		
	public:
		// Player() {}
		Player(TileAssets& ta, TileMap& tm)
			: tile_assets(ta), tile_map(tm) {
		}
		Player(TileAssets& ta, TileMap& tm, Vec2 pos)
			: tile_assets(ta), tile_map(tm), pos(pos) {
		}

		void access();
		void update(double dt);
		void draw() const;
		void walk(double s);
		void jump();
	};
}
