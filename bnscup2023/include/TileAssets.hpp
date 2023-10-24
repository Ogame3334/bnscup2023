#pragma once

#include <Siv3D.hpp>
#include <utility>
#include "Tile.hpp"

namespace bnscup2023 {
	class TileAssets {
	private:
		std::vector<std::pair<String, std::shared_ptr<BaseTile>>> assets;
	public:
		TileAssets() = default;
		template<class _T>
		void add(String&& key_and_texture_name) {
			Print << U"Assets\\Textures\\Tiles\\" + key_and_texture_name + U".png";
			TextureAsset::Register(key_and_texture_name, U"Assets\\Textures\\Tiles\\" + key_and_texture_name + U".png");
			assets.push_back(std::move(std::make_pair<String, std::shared_ptr<BaseTile>>(std::move(key_and_texture_name), std::shared_ptr<BaseTile>(new _T(key_and_texture_name)))));
		}
		template<class _T>
		void add(String&& key, String&& texture_name) {
			TextureAsset::Register(texture_name, U"Assets\\Textures\\Tiles\\" + texture_name + U".png");
			assets.push_back(std::move(std::make_pair<String, std::shared_ptr<BaseTile>>(std::move(key), std::shared_ptr<BaseTile>(new _T(texture_name)))));
		}
		BaseTile get(int index) {
			if (index < 0 or index >= assets.size()) return *(assets[0].second);
			else return *(assets[index + 1].second);
		}
		BaseTile operator[] (int index) { return this->get(index); }
		BaseTile operator[] (String&& key);
	};

	//namespace StringMethods {
	//	String Extruct(String sen, String chara) {
	//		sen.replace(U"\"", U"");
	//	}
	//}
}
