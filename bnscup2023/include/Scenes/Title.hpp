#pragma once

#include "../SceneBase.hpp"

class TitleScene : public SceneBase
{
public:
	TitleScene(const InitData& init)
		: SceneBase{ init }
	{

	}

	void updateGame() override
	{
		if (KeySpace.down())
			changeScene(U"MenuTest", 500, CrossFade{ false });
	}

	void updateUI() override
	{

	}

	void draw() const override
	{
		Scene::SetBackground(ColorF{ 0.3, 0.4, 0.5 });
		FontAsset(U"TitleFont")(U"My Game").drawAt(640, 200);
		FontAsset(U"Default")(U"Press Space Key").drawAt(640, 360);
	}
};
