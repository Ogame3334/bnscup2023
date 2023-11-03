#pragma once

#include "../SceneConfig.hpp"
#include "../MenuManager.hpp"
#include "../SceneBase.hpp"

class MenuTest : public SceneBase
{
private:
	TileMap tile_map = TileMap{ getData().tile_assets, U"TileTest.csv" };
	MenuManager mm{ true };
public:
	MenuTest(const InitData& init)
		: SceneBase{ init }
	{
		mm.addButton([] {Print << U"Hi!!"; }).setText(U"Play");
		mm.addButton([] {Print << U"Hoge!!"; }).setText(U"Hoge!!").setRectPos(100, 200);
		mm.addButton([this] {changeScene(U"AnimTestScene"); }).setRectPos(100, 300);
		mm.at(0).setUp(2).setDown(1);
		mm.at(1).setUp(0).setDown(2);
		mm.at(2).setUp(1).setDown(0);
	}

	void updateUI() override
	{
		mm.update();
	}

	void updateGame() override
	{

	}

	void draw() const override
	{
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		this->tile_map.draw();
		mm.draw();
	}
};
