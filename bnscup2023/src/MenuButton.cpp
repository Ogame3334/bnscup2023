#include "../include/MenuButton.hpp"

using namespace bnscup2023;

//void MenuButton::update() {
//
//}

MenuButton& MenuButtonManager::add(std::function<void(void)> h) {
	this->menu_buttons.push_back(MenuButtonContainer{ h });
	if (this->now_selected == this->menu_buttons.size() - 1) this->menu_buttons.back().getButtonRef().setActive(true);
	return this->menu_buttons.back().getButtonRef();
}

void MenuButtonManager::setConnection(int index, int up, int right, int down, int left) {
	this->menu_buttons[index].getConnectionRef() = { up, right, down, left };
}

void MenuButton::draw() const {
	this->display_rect.draw(this->is_active ? this->active_color : this->normal_color);
	FontAsset(U"ButtonDefault")(this->display_text).drawAt(this->display_rect.center(), Palette::Black);
}

int getValue(int n, int now) {
	return n != -1 ? n : now;
}

void MenuButtonManager::update() {
	//Console << this->now_selected;
	if ((KeyUp | KeyRight | KeyDown | KeyLeft).down()) {
		if (this->now_selected == -1) {
			this->now_selected = 0;
			this->menu_buttons[this->now_selected].getButtonRef().setActive(true);
		}
		else {
			this->menu_buttons[this->now_selected].getButtonRef().setActive(false);
			auto connection = this->menu_buttons[this->now_selected].getConnection();
			if (KeyUp.down()) {
				this->now_selected = getValue(this->menu_buttons[this->now_selected].getConnection().up, this->now_selected);
			}
			else if (KeyRight.down()) {
				this->now_selected = getValue(this->menu_buttons[this->now_selected].getConnection().right, this->now_selected);
			}
			else if (KeyDown.down()) {
				this->now_selected = getValue(this->menu_buttons[this->now_selected].getConnection().down, this->now_selected);
			}
			else if (KeyLeft.down()) {
				this->now_selected = getValue(this->menu_buttons[this->now_selected].getConnection().left, this->now_selected);
			}
			this->menu_buttons[this->now_selected].getButtonRef().setActive(true);
		}
	}
	if (KeyEnter.down() and this->now_selected != -1) {
		this->menu_buttons[this->now_selected].getButton().execute();
	}
}
void MenuButtonManager::draw() const {
	for (const auto& b : this->menu_buttons) {
		b.getButton().draw();
	}
}
