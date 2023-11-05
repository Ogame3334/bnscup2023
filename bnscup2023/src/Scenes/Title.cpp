#include "../../include/Scenes/Title.hpp"

using namespace bnscup2023;

void TitleScene::MenuButtonInit(int i) {
	this->mm.reset();
	switch (i)
	{
	case 0:
		this->mm.addButton([this] {this->MenuButtonInit(1); }).setText(U"Select Stage").setRectPos(Scene::Center().x - 100, 500);
		this->mm.addButton(System::Exit).setText(U"ゲームを終了する").setRectPos(Scene::Center().x - 100, 600);
		this->mm.setNowSelected(0);
		this->mm.at(0).setUp(1).setDown(1);
		this->mm.at(1).setUp(0).setDown(0);
		break;
	case 1:
		this->mm.addButton([this] { this->changeScene(U"TestScene", 300); }).setText(U"Tutorial").setRectPos(Scene::Center().x - 475, 500);
		this->mm.addButton([this] {this->changeScene(U"OgameScene", 300); }).setText(U"Stage 1").setRectPos(Scene::Center().x - 225, 500);
		this->mm.addButton([this] {this->changeScene(U"TomoqScene", 300); }).setText(U"Stage 2").setRectPos(Scene::Center().x + 25, 500);
		this->mm.addButton([this] { this->MenuButtonInit(1); }).setText(U"Stage 3").setRectPos(Scene::Center().x + 275, 500);
		this->mm.addButton([this] {this->MenuButtonInit(0); }).setText(U"戻る").setRectPos(Scene::Center().x - 100, 600);
		this->mm.at(0).setLeft(3).setRight(1).setDown(4);
		this->mm.at(1).setLeft(0).setRight(2).setDown(4);
		this->mm.at(2).setLeft(1).setRight(3).setDown(4);
		this->mm.at(3).setLeft(2).setRight(0).setDown(4);
		this->mm.at(4).setUp(0).setDown(0);
		this->mm.setNowSelected(0);
		break;
	}
}
