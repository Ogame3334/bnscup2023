#pragma once

#include <Siv3D.hpp>
#include "MenuButton.hpp"

namespace bnscup2023 {
	class MenuManager {
	private:
		MenuButtonManager menu_button_manager;
		bool is_enable = false;
	public:
		MenuManager() = default;
		MenuManager(bool isDefaultSelect) : menu_button_manager(MenuButtonManager{ isDefaultSelect }) {}

		MenuButton& addButton(std::function<void(void)> h) {
			return this->menu_button_manager.add(h);
		}

		void setButtonConnection(int index, int up = -1, int right = -1, int down = -1, int left = -1) {
			this->menu_button_manager.setConnection(index, up, right, down, left);
		}
		auto& at(int index) { return this->menu_button_manager.at(index); }

		void setIsEnable(bool cond) { this->is_enable = cond; }
		constexpr bool getIsEnable() const noexcept { return this->is_enable; }

		void update();
		void draw() const;
	};
}
