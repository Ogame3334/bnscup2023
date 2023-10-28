#include "../include/Player.hpp"

namespace bnscup2023 {
	void Player::access() {
		// TODO: 注目しているタイルのアクセス呼び出し
	}
	void Player::update(double dt) {
		Vec2 pos_prev = Vec2(pos);
		this->dt = dt;

		vel.x = 0;
		if (KeyD.pressed() or KeyRight.pressed()) walk(+1);
		if (KeyA.pressed() or KeyLeft.pressed()) walk(-1);
		if (KeySpace.pressed()) jump();

		// 位置の更新
		pos += vel;
		if (falling)vel += Vec2(0, G);

		// TODO: マップ内のタイルとの衝突判定
		bool hasCollided = false;
		Point thePoint;
		BaseTile theTile;
		for (int j = -1; j <= 1 and !hasCollided; j++) {
			for (int i = -1; i <= 1 and !hasCollided; i++) {
				thePoint = (pos.movedBy(.5,.5).asPoint() + Point(i, j));
				if (!thePoint.intersects(Rect(-1, -1, tile_map.Width+1, tile_map.Height+1)))break;
				theTile = tile_map.at(thePoint);
				if (theTile.getCollisionable()) {
					hasCollided = hasCollided or Rect(thePoint*BaseTile::TileSize, BaseTile::TileSize).intersects(getRect());
				}
			}
		}
		if (hasCollided) {
			if (falling) {
				// ジャンプ着地時
				falling = false;
				pos.y = floor(pos.y);
				vel.y = 0;
			}
			else {
				pos = pos_prev;
			}
		}
	}
	void Player::draw() const {
		// TODO: 保持したプレイヤーアセットの描画
		// tile_assets[1].draw(pos * BaseTile::TileSize);
	/*	Rect{ int(pos.x*BaseTile::TileSize), int(pos.y*BaseTile::TileSize), BaseTile::TileSize }
			(TextureAsset(U"error").resized(BaseTile::TileSize)).draw();*/

		// 当たり判定領域
		getRect()(TextureAsset(U"error").resized(BaseTile::TileSize)).draw();
	}

	void Player::walk(double s) {
		vel.x += walk_speed * s;
	}

	void Player::jump() {
		if (not falling) {
			vel.y -= jump_speed;
			falling = true;
		}
	}

	Rect Player::getRect() const {
		return Rect((pos * BaseTile::TileSize).asPoint(), BaseTile::TileSize);
	}
}
