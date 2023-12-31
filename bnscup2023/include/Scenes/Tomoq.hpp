﻿#pragma once

#include "../SceneConfig.hpp"
#include "../Player.hpp"

class TomoqScene : public SceneBase
{
private:
	bool pause;
	bool hasGoaled = false;
	bool hasFailed = false;
	TileMap tile_map = TileMap{ getData().tile_assets, U"TomoqField.csv" };
	Player player = Player{ getData().tile_assets, tile_map, Vec2(1, 16) };
	MenuManager mm{ true };
	MenuManager clearMenu{ true };
	MenuManager failedMenu{ true };
public:
	TomoqScene(const InitData& init)
		: SceneBase{ init }
	{
		player.setRetryHandler([this] {this->setHasFailed(true); });
		tile_map.at(13, 14).test();
		mm.addButton([this] {this->changeScene(U"Title", .3s); }).setText(U"タイトルに戻る").setRectPos(Scene::Center().x - 100, 260);
		mm.addButton([this] {this->changeScene(U"TomoqScene", .3s); }).setText(U"リトライ").setRectPos(Scene::Center().x - 100, 360);
		mm.addButton([] { System::Exit(); }).setText(U"ゲームを終了する").setRectPos(Scene::Center().x - 100, 460);
		mm.at(0).setUp(2).setDown(1);
		mm.at(1).setUp(0).setDown(2);
		mm.at(2).setUp(1).setDown(0);
		AudioAsset(U"bgm").play();

		clearMenu.addButton([this] {this->changeScene(U"TomoqScene", .3s); }).setText(U"次のステージ").setRectPos(Scene::Center().x - 100, 360);
		clearMenu.addButton([this] {this->changeScene(U"Title", .3s); }).setText(U"タイトルに戻る").setRectPos(Scene::Center().x - 100, 460);
		clearMenu.at(0).setUp(1).setDown(1);
		clearMenu.at(1).setUp(0).setDown(0);
		clearMenu.setIsCanEscape(false);

		failedMenu.addButton([this] {this->changeScene(U"TomoqScene", .3s); }).setText(U"リトライ").setRectPos(Scene::Center().x - 100, 360);
		failedMenu.addButton([this] {this->changeScene(U"Title", .3s); }).setText(U"タイトルに戻る").setRectPos(Scene::Center().x - 100, 460);
		failedMenu.at(0).setUp(1).setDown(1);
		failedMenu.at(1).setUp(0).setDown(0);
		failedMenu.setIsCanEscape(false);
	}

	~TomoqScene() {
		AudioAsset(U"bgm").stop();
		for (int y = 0; y < TileMap::Height; y++) {
			for (int x = 0; x < TileMap::Width; x++) {
				this->tile_map.at(x, y).reset();
			}
		}
	}

	void setHasFailed(bool cond) { this->hasFailed = cond; }

	void updateGame() override {
		this->tile_map.update();
		if (not hasGoaled and not hasFailed) {
			hasGoaled = player.update(1000 / 60.0);// TODO: 前フレームからの経過時間を渡す(秒orミリ秒)
			if (hasGoaled) AudioAsset(U"stage_clear").playOneShot();
			if (this->hasFailed) AudioAsset(U"stage_failed").playOneShot();
		}
		else {
			this->setIsPause(true);
			if (this->hasGoaled)clearMenu.setIsEnable(true);
			if (this->hasFailed)failedMenu.setIsEnable(true);
		}
	}

	void updateUI() override
	{
		pause = getIsPause() or this->hasGoaled or this->hasFailed;
		if (this->pause) AudioAsset(U"bgm").pause();
		else AudioAsset(U"bgm").play();
		mm.update();
		if (this->hasGoaled)this->clearMenu.update();
		if (this->hasFailed) this->failedMenu.update();
	}

	void draw() const override
	{
		TextureAsset(U"background").draw(0, 0);
		this->tile_map.draw();
		this->player.draw();
		if (pause) {
			if (this->hasGoaled) {
				clearMenu.draw();
				FontAsset(U"TitleFont")(U"Stage Clear!!").drawAt(Scene::CenterF() + Point(0, -100));
			}
			else if (this->hasFailed) {
				this->failedMenu.draw();
				FontAsset(U"TitleFont")(U"Failed!!").drawAt(Scene::CenterF() + Point(0, -100));
			}
			else mm.draw();
		}
	}
};
