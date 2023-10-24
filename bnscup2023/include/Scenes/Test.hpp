#pragma once

#include "../SceneConfig.hpp"

class TestScene : public App::Scene
{
private:
	TileMap tile_map = TileMap{ getData().tile_assets, U"TestField.csv" };
public:
	TestScene(const InitData& init)
		: IScene{ init }
	{

	}

	void update() override
	{

	}

	void draw() const override
	{
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		this->tile_map.draw();
	}
};
