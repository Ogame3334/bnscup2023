#pragma once

#include "../SceneConfig.hpp"

class TitleScene : public App::Scene
{
public:
	TitleScene(const InitData& init)
		: IScene{ init }
	{

	}

	void update() override
	{
		if (KeySpace.down())
			changeScene(U"TestScene", 500, CrossFade{ false });
	}

	void draw() const override
	{
		Scene::SetBackground(ColorF{ 0.3, 0.4, 0.5 });
		FontAsset(U"TitleFont")(U"My Game").drawAt(640, 200);
		FontAsset(U"Default")(U"Press Space Key").drawAt(640, 360);
	}
};
