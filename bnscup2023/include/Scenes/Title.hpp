#pragma once

#include "../SceneBase.hpp"
#include "../MenuManager.hpp"

class TitleScene : public SceneBase
{
private:
	MenuManager mm{ true };
public:
	TitleScene(const InitData& init)
		: SceneBase{ init }
	{
		this->mm.setIsEnable(true);
		this->mm.setIsBack(false);
		this->MenuButtonInit(0);
	}

	void MenuButtonInit(int i);

	void updateGame() override
	{

	}

	void updateUI() override
	{
		this->mm.update();
	}

	void draw() const override
	{
		Scene::SetBackground(ColorF{ 0.3, 0.4, 0.5 });
		FontAsset(U"TitleFont")(U"Water Adventure").drawAt(640, 200);
		//FontAsset(U"Default")(U"Press Space Key").drawAt(640, 360);
		this->mm.draw();
	}
};
