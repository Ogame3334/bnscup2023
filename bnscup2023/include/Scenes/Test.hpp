﻿#pragma once

#include "../SceneConfig.hpp"
#include "../Player.hpp"

class TestScene : public SceneBase
{
private:
	bool pause;
	bool hasGoaled = false;
	TileMap tile_map = TileMap{ getData().tile_assets, U"TileTest.csv" };
	Player player = Player{ getData().tile_assets, tile_map, Vec2(4, 4)};
	const Audio audio{ U"Assets\\Audio\\Mixdown.mp3", Loop::Yes };
public:
	TestScene(const InitData& init)
		: SceneBase{ init }
	{
		tile_map.at(13, 14).test();
		audio.play();
	}

	void updateGame() override {
		if (not hasGoaled) {
			hasGoaled = player.update(1000 / 60.0);// TODO: 前フレームからの経過時間を渡す(秒orミリ秒)
		}
		else {
			Print << U"Goaled";
		}
	}

	void updateUI() override
	{
		pause = getIsPause();
	}

	void draw() const override
	{
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		this->tile_map.draw();
		this->player.draw();
		if (pause) {
			FontAsset(U"TitleFont")(U"PAUSE").drawAt(640, 360);
		}
	}
};
