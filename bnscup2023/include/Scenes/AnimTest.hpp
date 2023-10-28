#pragma once

#include "../SceneConfig.hpp"
#include "../Player.hpp"
#include "../SceneBase.hpp"
#include "../Siv3DKunAnimation.hpp"

class AnimTestScene : public SceneBese
{
private:
	bool pause;
	TileMap tile_map = TileMap{ getData().tile_assets, U"TestField.csv" };
	Siv3DKunAnimation anim{};
	bool temp = true;
public:
	AnimTestScene(const InitData& init)
		: SceneBese{ init }
	{

	}

	void updateGame() override {
		this->anim.update();
	}

	void updateUI() override
	{
		this->temp = this->anim.getHasWater();
		pause = getIsPause();
		if (SimpleGUI::Button(U"Left", Vec2{ 30, 10 })) {
			this->anim.setState(PlayerState::Left);
		}
		if (SimpleGUI::Button(U"Right", Vec2{ 30, 90 })) {
			this->anim.setState(PlayerState::Right);
		}
		if (SimpleGUI::Button(U"LeftWalk", Vec2{ 30, 50 })) {
			this->anim.setState(PlayerState::LeftWalk);
		}
		if (SimpleGUI::Button(U"RightWalk", Vec2{ 30, 130 })) {
			this->anim.setState(PlayerState::RightWalk);
		}
		if (SimpleGUI::Button(U"Behind", Vec2{ 30, 170 })) {
			this->anim.setState(PlayerState::Behind);
		}
		if (SimpleGUI::Button(U"UpDown", Vec2{ 30, 210 })) {
			this->anim.setState(PlayerState::UpDown);
		}
		if (SimpleGUI::CheckBox(this->temp, U"HasWater", Vec2{ 30, 250 })) {
			this->anim.setHasWater(this->temp);
		}
		if (SimpleGUI::Button(U"LeftGetWater", Vec2{ 30, 290 })) {
			this->anim.setState(PlayerState::LeftGetWater);
		}
		if (SimpleGUI::Button(U"RightGetWater", Vec2{ 30, 330 })) {
			this->anim.setState(PlayerState::RightGetWater);
		}
		if (SimpleGUI::Button(U"LeftSprinkleWater", Vec2{ 30, 370 })) {
			this->anim.setState(PlayerState::LeftSprinkleWater);
		}
		if (SimpleGUI::Button(U"RightSprinkleWater", Vec2{ 30, 410 })) {
			this->anim.setState(PlayerState::RightSprinkleWater);
		}
	}

	void draw() const override
	{
		ClearPrint();
		Print << static_cast<int>(this->anim.getState());
		//getData().tile_assets[1].drawAt(Scene::CenterF());
		//getData().tile_assets[U"normal_ground"].drawAt(Scene::CenterF());
		//this->tile_map.draw();
		anim.getNowTexture().drawAt(Scene::CenterF());
	}
};
