#include "../../include/Scenes/Title.hpp"

using namespace bnscup2023;

void TitleScene::MenuButtonInit(int i) {
	this->mm.reset();
	switch (i)
	{
	case 0:
		this->mm.addButton([this] {this->MenuButtonInit(1); }).setText(U"Play");
	}
}
