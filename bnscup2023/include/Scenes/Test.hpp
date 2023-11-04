#pragma once

#include "../SceneConfig.hpp"
#include "../Player.hpp"

class TestScene : public SceneBase
{
private:
	bool pause;
	bool hasGoaled = false;
	TileMap tile_map = TileMap{ getData().tile_assets, U"TileTest.csv" };
	Player player = Player{ getData().tile_assets, tile_map, Vec2(4, 4)};
	MenuManager mm{ true };
public:
	TestScene(const InitData& init)
		: SceneBase{ init }
	{
		tile_map.at(13, 14).test();
		mm.addButton([this] {this->changeScene(U"Title", .3s); }).setText(U"タイトルに戻る").setRectPos(Scene::Center().x - 100, 260);
		mm.addButton([this] {this->changeScene(U"TestScene", .3s); }).setText(U"リトライ").setRectPos(Scene::Center().x - 100, 360);
		mm.addButton([]{ System::Exit(); }).setText(U"ゲームを終了する").setRectPos(Scene::Center().x - 100, 460);
		mm.at(0).setUp(2).setDown(1);
		mm.at(1).setUp(0).setDown(2);
		mm.at(2).setUp(1).setDown(0);
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
		mm.update();
	}

	void draw() const override
	{
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		this->tile_map.draw();
		this->player.draw();
		if (pause) {
			//FontAsset(U"TitleFont")(U"PAUSE").drawAt(640, 360);
			mm.draw();
		}
	}
};
