#include "../include/MenuManager.hpp"
#include "../include/SceneBase.hpp"

using namespace bnscup2023;

MenuManager MenuManager::GameMenuManager() {
	MenuManager outmm{ true };
	outmm.addButton([]{}).setText(U"リトライ").setRectPos(Scene::Center().x - 100, 500);
	return outmm;
}

void MenuManager::update() {
	if (KeyEscape.down() and this->is_can_escape) {
		this->menu_button_manager.setNowSelected(0);
		this->is_enable ^= 1;
	}
	if (this->is_enable) {
		this->menu_button_manager.update();
	}
}

void MenuManager::draw() const {
	if (this->is_enable) {
		if(this->is_back) Rect{ Point{0, 0}, Scene::Size() }.draw(ColorF{ 0, 0, 0, 0.4 });
		this->menu_button_manager.draw();
	}
}
