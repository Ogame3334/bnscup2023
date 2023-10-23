#include <Siv3D.hpp>

namespace bnscup2023 {
	enum class TileId {
		AIR,
		NORMAL_GRAND,
	};
	class Tile {
	private:
		inline static int TileSize = 10;
		Texture texture;
	public:
		Tile() = default;
		Tile(String texture_name) : texture(Texture{ texture_name }) {}
		Tile(Texture t) : texture(t) {}
		void setTexture(Texture t) { this->texture = t; }
		void setTexture(String texture_name) { this->texture = Texture{ texture_name }; }
		Texture getTexture() const noexcept { return this->texture; }
		void draw() const;
	};

	namespace Tiles {
		const Tile air{U"air"};
	}

	class TileMap {
	private:
	public:
		void update();
		void draw() const;
	};
}
