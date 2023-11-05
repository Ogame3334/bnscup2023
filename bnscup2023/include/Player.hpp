#pragma once
#include "TileAssets.hpp"
#include "TileMap.hpp"
#include "Siv3DKunAnimation.hpp"

namespace bnscup2023 {
	class BaseTile;
	class HasWaterTile;
	class TileAssets;
	class TileMap;
	class Player {
	private:
		static constexpr double walk_speed = 7e-2;
		static constexpr double climb_speed = 7e-2;
		static constexpr double jump_speed = 1e-1;
		static constexpr double G = 4e-3;
		static constexpr double paddingX = .2;
		Vec2 pos = Vec2(0, 0);
		Vec2 vel = Vec2(0, 0);
		Point focusedPos;
		TileAssets& tile_assets;
		TileMap& tile_map;
		double dt = 16;
		Siv3DKunAnimation anim = Siv3DKunAnimation();
		bool canProcessing = true;
		static constexpr int CantProcessingMillisec = 3000;
		int nowMillisec = 0;
		std::function<void(void)> retry_handler = nullptr;

	public:
		// Player() {}
		Player(TileAssets& ta, TileMap& tm)
			: tile_assets(ta), tile_map(tm) {
		}
		Player(TileAssets& ta, TileMap& tm, Vec2 pos)
			: tile_assets(ta), tile_map(tm), pos(pos) {
		}

		void access();
		/// @brief プレイヤーの更新
		/// @param dt 前フレームからの経過時間[ms]
		/// @return クリア条件を満たしたかどうかを表す真偽値(true:クリア)
		bool update(double dt);
		void draw() const;
		void walk(double s);
		void climb(double s);
		void jump();
		Rect getRect() const;
		Rect getFootRect() const;
		bool isFalling() const;
		bool onClimbable() const;
		int getDirection() const;
		bool fillBucket();
		bool useBucket();
		bool hasWater() const { return this->anim.getHasWater(); }
		TileMap& getTileMapRef() { return this->tile_map; }
		Point getFocusedPos() const noexcept { return this->focusedPos; }
		constexpr void setCanProcessing(bool cond) noexcept { this->canProcessing = cond; }
		constexpr bool getCanProcessing() const noexcept { return this->canProcessing; }
		void setRetryHandler(std::function<void(void)> h) { this->retry_handler = h; }
	};
}
