#include "../include/Player.hpp"

namespace bnscup2023 {
	void Player::access() {
		// TODO: 注目しているタイルのアクセス呼び出し
	}
	void Player::update(double dt) {
		Vec2 pos_prev = Vec2(pos);
		this->dt = dt;
		bool falling = isFalling();
		Print << onClimbable();
		bool climbable = onClimbable();

		if (vel.x < 0) {
			anim.setState(PlayerState::Left);
		}
		else if (vel.x > 0) {
			anim.setState(PlayerState::Right);
		}

		vel.x = 0;
		if (KeyD.pressed() or KeyRight.pressed()) walk(+1);
		if (KeyA.pressed() or KeyLeft.pressed()) walk(-1);
		if (KeySpace.pressed()) {
			if (climbable) {
				climb(+1);
			}
			else if(not falling) {
				jump();
			}
		}
		else if (climbable and falling and vel.y > 0) {
			climb(-1);
		}

		// 位置の更新
		if (falling)vel += Vec2(0, G);
		pos += vel;

		bool hasCollided = false;
		Grid<bool> hasCollidedGrid = {
			{false, false, false},
			{false, false, false},
			{false, false, false},
		};
		int i, j;
		Point thePoint;
		BaseTile theTile;
		for (j = -1; j <= 1; j++) {
			for (i = -1; i <= 1; i++) {
				thePoint = (pos.movedBy(.5,.5).asPoint() + Point(i, j));
				if (!thePoint.intersects(Rect(-1, -1, tile_map.Width+1, tile_map.Height+1)))continue;
				theTile = tile_map.at(thePoint);
				if (theTile.getCollisionable()) {
					hasCollidedGrid[j + 1][i + 1] = Rect(thePoint * BaseTile::TileSize, BaseTile::TileSize).intersects(getRect());
					hasCollided = hasCollided or hasCollidedGrid[j + 1][i + 1];
				}
			}
		}

		if (hasCollided) {
			if (!isFalling() && (hasCollidedGrid[2][0] or hasCollidedGrid[2][1] or hasCollidedGrid[2][2])) {
				// ジャンプ着地時
				pos.y = floor(pos.y);
				vel.y = 0;
			}
			else if (falling && hasCollidedGrid[0][1]) {
				// 天井への衝突
				pos.y = ceil(pos.y);
				vel.y = fmax(0,vel.y);
			}
			else if (hasCollidedGrid[1][0]) {
				// 壁への衝突(左)
				pos.x = ceil(pos.x) - paddingX;
			}
			else if (hasCollidedGrid[1][2]) {
				// 壁への衝突(右)
				pos.x = floor(pos.x) + paddingX;
			}
		}

		// アニメーションの更新
		anim.update();
	}
	void Player::draw() const {
		// TODO: 保持したプレイヤーアセットの描画
		 const ScopedRenderStates2D sampler{ SamplerState::ClampNearest };
		Rect{ int(pos.x*BaseTile::TileSize), int(pos.y*BaseTile::TileSize), BaseTile::TileSize }
			(anim.getNowTexture().resized(BaseTile::TileSize)).draw();

		// 当たり判定領域
		//getRect()(TextureAsset(U"error").resized(BaseTile::TileSize)).draw();
	}

	void Player::walk(double s) {
		vel.x = walk_speed * s;
		if (s < 0) {
			anim.setState(PlayerState::LeftWalk);
		} else {
			anim.setState(PlayerState::RightWalk);
		}
	}

	void Player::climb(double s) {
		if(vel.y >= 0) vel.y = - climb_speed * s;
		anim.setState(PlayerState::Behind);
	}

	void Player::jump() {
		vel.y = -jump_speed;
		if (vel.x < 0) {
			anim.setState(PlayerState::Left);
		}
		else {
			anim.setState(PlayerState::Right);
		}
	}

	Rect Player::getRect() const {
		return Rect((pos * BaseTile::TileSize).asPoint(), BaseTile::TileSize).scaled(1.-paddingX*2, 1.).asRect();
	}

	Rect Player::getFootRect() const {
		auto s = BaseTile::TileSize;
		return Rect((pos.movedBy(.3,.95) * s).asPoint(), s*.4, s*.1);
	}

	bool Player::isFalling() const {
		bool hasCollided = false;
		Point thePoint;
		BaseTile theTile;
		for (int j = 0; j <= 1 and !hasCollided; j++) {
			for (int i = -1; i <= 1 and !hasCollided; i++) {
				thePoint = (pos.movedBy(.5, .5).asPoint() + Point(i, j));
				if (!thePoint.intersects(Rect(-1, -1, tile_map.Width + 1, tile_map.Height + 1)))break;
				theTile = tile_map.at(thePoint);
				if (theTile.getCollisionable()) {
					hasCollided = hasCollided or Rect(thePoint * BaseTile::TileSize, BaseTile::TileSize).intersects(getFootRect());
				}
			}
		}
		return not hasCollided;
	}

	bool Player::onClimbable() const {
		return tile_map.at(pos.movedBy(.5, .5).asPoint()).getClimbable();
	}
}
