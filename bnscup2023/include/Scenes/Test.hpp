#pragma once

#include "../SceneConfig.hpp"
#include "../Player.hpp"

class TestScene : public App::Scene
{
private:
	TileMap tile_map = TileMap{ getData().tile_assets, U"TestField.csv" };
	Player player = Player{ getData().tile_assets, tile_map, Vec2(4, 4)};
public:
	TestScene(const InitData& init)
		: IScene{ init }
	{

	}

	void update() override
	{
		this->player.update(1000/60.0);// TODO: 前フレームからの経過時間を渡す(秒orミリ秒)
	}

	void draw() const override
	{
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		this->tile_map.draw();
		this->player.draw();
	}
};
