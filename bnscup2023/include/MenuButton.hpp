#pragma once

#include <Siv3D.hpp>

namespace bnscup2023 {
	class MenuButton {
	private:
		std::function<void(void)> handler = nullptr;
		String display_text = U"Button";
		Rect display_rect = Rect{100, 100, 200, 50};
		Color normal_color = Palette::Lightgray;
		Color active_color = Palette::Skyblue;
		bool is_active = false;

		std::shared_ptr<MenuButton> up = nullptr;
		std::shared_ptr<MenuButton> right = nullptr;
		std::shared_ptr<MenuButton> down = nullptr;
		std::shared_ptr<MenuButton> left = nullptr;
	public:
		MenuButton() = default;
		MenuButton(std::function<void(void)> h) : handler(h) {}

		void setFunction(std::function<void(void)> h) { this->handler = h; }
		void execute() { if (static_cast<bool>(this->handler)) this->handler(); }

		inline void setActive(bool _isActive) { this->is_active = _isActive; }
		MenuButton& setRectPos(int x, int y) {
			this->display_rect.x = x;
			this->display_rect.y = y;
			return *this;
		}
		MenuButton& setRectSize(int w, int h) {
			this->display_rect.w = w;
			this->display_rect.h = h;
			return *this;
		}
		MenuButton& setText(String text) {
			this->display_text = text;
			return *this;
		}

		void draw() const;
	};

	class MenuButtonManager {
	private:
		class MenuButtonContainer {
		private:
			struct quartet {
				int up = -1;
				int right = -1;
				int down = -1;
				int left = -1;
			};
			quartet connection;
			MenuButton button;
		public:
			MenuButtonContainer() = default;
			MenuButtonContainer(std::function<void(void)> h) : button(MenuButton{ h }) {}

			MenuButtonContainer& setUp(int i) { this->connection.up = i; return *this; }
			MenuButtonContainer& setRight(int i) { this->connection.right = i; return *this; }
			MenuButtonContainer& setDown(int i) { this->connection.down = i; return *this; }
			MenuButtonContainer& setLeft(int i) { this->connection.left = i; return *this; }
			MenuButton getButton() const { return this->button; }
			MenuButton& getButtonRef() { return this->button; }
			quartet getConnection() const { return this->connection; }
			quartet& getConnectionRef() { return this->connection; }
		};
		Array<MenuButtonContainer> menu_buttons;
		int now_selected = -1;
	public:
		MenuButtonManager() = default;
		MenuButtonManager(bool isDefaultSelect) : now_selected(isDefaultSelect ? 0 : -1) {}

		MenuButtonContainer operator[] (int index) { return this->menu_buttons[index]; }

		MenuButton& add(std::function<void(void)> h);

		void setConnection(int index, int up = -1, int right = -1, int down = -1, int left = -1);
		MenuButtonContainer& at(int index) { return this->menu_buttons[index]; }
		void setNowSelected(int i) { this->now_selected = i; }

		void update();
		void draw() const;
	};
}
