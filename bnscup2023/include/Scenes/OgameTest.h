#pragma once

#include "../SceneConfig.hpp"
#include "../MenuButton.hpp"

class OgameTest : public App::Scene
{
private:
	TileMap tile_map = TileMap{ getData().tile_assets, U"TestField.csv" };
	MenuButtonManager mbm{ true };
public:
	OgameTest(const InitData& init)
		: IScene{ init }
	{
		mbm.add([] {Print << U"Hi!!"; }).setText(U"Hi!!");
		mbm.add([] {Print << U"Hoge!!"; }).setText(U"Hoge!!").setRectPos(100, 200);
		mbm.at(0).setUp(1).setDown(1);
		mbm.at(1).setUp(0).setDown(0);
	}

	void update() override
	{
		mbm.update();
	}

	void draw() const override
	{
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		this->tile_map.draw();
		mbm.draw();
	}
};
