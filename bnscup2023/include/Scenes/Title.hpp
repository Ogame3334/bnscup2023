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
		this->mm.setIsCanEscape(false);
		this->MenuButtonInit(0);
		AudioAsset(U"titlebgm").play();
	}

	~TitleScene() {
		AudioAsset(U"titlebgm").stop();
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
		TextureAsset(U"background").draw(0, 0);
		FontAsset(U"TitleFont")(U"Water Adventure").drawAt(640, 200);
		this->mm.draw();
	}
};
