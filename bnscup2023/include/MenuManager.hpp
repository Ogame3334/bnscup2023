#pragma once

#include <Siv3D.hpp>
#include "MenuButton.hpp"

namespace bnscup2023 {
	class MenuManager {
	private:
		MenuButtonManager menu_button_manager;
		bool is_enable = false;
		bool is_back = true;
		bool is_can_escape = true;
	public:
		MenuManager() = default;
		MenuManager(bool isDefaultSelect) : menu_button_manager(MenuButtonManager{ isDefaultSelect }) {}
		MenuManager(const MenuManager& mm) : menu_button_manager(mm.menu_button_manager), is_enable(mm.is_enable), is_back(mm.is_back) {}

		MenuButton& addButton(std::function<void(void)> h) {
			return this->menu_button_manager.add(h);
		}

		static MenuManager GameMenuManager();

		void setButtonConnection(int index, int up = -1, int right = -1, int down = -1, int left = -1) {
			this->menu_button_manager.setConnection(index, up, right, down, left);
		}
		auto& at(int index) { return this->menu_button_manager.at(index); }

		void setIsEnable(bool cond) { this->is_enable = cond; }
		constexpr bool getIsEnable() const noexcept { return this->is_enable; }
		void setIsBack(bool cond) { this->is_back = cond; }
		constexpr bool getIsBack() const noexcept { return this->is_back; }
		void setIsCanEscape(bool cond) { this->is_can_escape = cond; }
		constexpr bool getIsCanEscape() const noexcept { return this->is_can_escape; }
		void setNowSelected(int i) { this->menu_button_manager.setNowSelected(i); }

		void reset() { this->menu_button_manager.reset(); }

		void update();
		void draw() const;
	};
}
