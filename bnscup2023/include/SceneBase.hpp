#pragma once

#include "SceneConfig.hpp"

class SceneBase : public App::Scene
{
private:
	bool isPause;
public:
	explicit SceneBase(const InitData& init)
		: IScene{ init } {
		isPause = false;
	};

	bool getIsPause() {
		return isPause;
	}

	virtual void updateGame() {}
	virtual void updateUI() {}
	void update() override {

		if (KeyP.down()) {
			isPause = !isPause;
		}

		updateUI();

		if (!isPause) {
			updateGame();
		}
	}
};
