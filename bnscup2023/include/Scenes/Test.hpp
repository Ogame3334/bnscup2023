#pragma once

#include "../SceneConfig.hpp"

class TestScene : public SceneBese
{
private:
	bool pause;
	TileMap tile_map = TileMap{ getData().tile_assets, U"TestField.csv" };
public:
	TestScene(const InitData& init)
		: SceneBese{ init }
	{

	}

	void updateGame() override {

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
		if (pause) {
			FontAsset(U"TitleFont")(U"PAUSE").drawAt(640, 360);
		}
	}
};
