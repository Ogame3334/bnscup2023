#pragma once
#include "TileAssets.hpp"
#include "TileMap.hpp"
#include "Siv3DKunAnimation.hpp"

namespace bnscup2023 {
	class Player {
	private:
		static constexpr double walk_speed = 7e-2;
		static constexpr double jump_speed = 1e-1;
		static constexpr double G = 4e-3;
		static constexpr double paddingX = .2;
		Vec2 pos = Vec2(0, 0);
		Vec2 vel = Vec2(0, 0);
		Point focusedPos;
		// TODO: プレイヤーアセットの保持
		TileAssets& tile_assets;
		TileMap& tile_map;
		double dt = 16;
		Siv3DKunAnimation anim = Siv3DKunAnimation();
		
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
		Rect getRect() const;
		Rect getFootRect() const;
		bool isFalling() const;
	};
}
