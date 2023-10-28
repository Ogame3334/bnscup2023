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
		Print << pos;

		// 位置の更新
		pos += vel;
		if (falling)vel += Vec2(0, G);

		// TODO: マップ内のタイルとの衝突判定
		if (false or pos.y>8/* 衝突判定 */) {
			if (falling) {
				// ジャンプ着地時
				falling = false;
				pos = pos_prev;
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
		Rect{ int(pos.x*BaseTile::TileSize), int(pos.y*BaseTile::TileSize), BaseTile::TileSize }
			(TextureAsset(U"error").resized(BaseTile::TileSize)).draw();
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
}
