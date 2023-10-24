#pragma once

#include "../SceneConfig.hpp"

class SceneBese : public App::Scene
{
private:
	bool isPause;
public:
	explicit SceneBese(const InitData& init)
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
