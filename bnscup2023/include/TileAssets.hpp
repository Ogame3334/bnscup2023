#pragma once

#include <Siv3D.hpp>
#include <utility>
#include "Tile.hpp"

namespace bnscup2023 {
	class BaseTileContainerBase {
	public:
		virtual BaseTile getTile() { return BaseTile(); };
		virtual BaseTilePtr getNewPtr() { return BaseTilePtr(new BaseTile()); };
		virtual BaseTile& getTileRef() { BaseTile hoge{};  return hoge; };
	};
	template<class _T>
	class BaseTileContainer : public BaseTileContainerBase {
		using tile_type = _T;
		using tile_type_ptr = std::shared_ptr<_T>;
	private:
		tile_type_ptr value;
	public:
		BaseTileContainer() = default;
		BaseTileContainer(const BaseTileContainer&) = default;
		BaseTileContainer(BaseTileContainer&&) = default;
		BaseTileContainer(std::shared_ptr<_T> t) { this->value = t; }
		BaseTile getTile() override {
			return *(this->value);
		}
		BaseTilePtr getNewPtr() override {
			BaseTilePtr temp = BaseTilePtr(new tile_type{ *(this->value) });
			return temp;
		}
		BaseTile& getTileRef() override {
			return *(this->value);
		}
	};
	class TileAssets {
	private:
		std::vector<std::pair<String, std::shared_ptr<BaseTileContainerBase>>> assets;
	public:
		TileAssets() = default;
		template<class _T>
		void add(String&& key_and_texture_name) {
			TextureAsset::Register(key_and_texture_name, U"Assets\\Textures\\Tiles\\" + key_and_texture_name + U".png");
			assets.push_back(std::move(std::make_pair<String, std::shared_ptr<BaseTileContainerBase>>(
				std::move(key_and_texture_name),
				std::shared_ptr<BaseTileContainerBase>(new BaseTileContainer<_T>(std::shared_ptr<_T>(new _T(key_and_texture_name))))
			)));
		}
		template<class _T>
		BaseTile& add(String&& key, String&& texture_name) {
			TextureAsset::Register(texture_name, U"Assets\\Textures\\Tiles\\" + texture_name + U".png");
			assets.push_back(std::move(std::make_pair<String, std::shared_ptr<BaseTileContainerBase>>(
				std::move(key),
				std::shared_ptr<BaseTileContainerBase>(new BaseTileContainer<_T>(std::shared_ptr<_T>(new _T(texture_name))))
			)));
			return assets.back().second->getTileRef();
		}
		BaseTile get(int index) {
			if (index < 0 or index >= assets.size()) return assets[0].second->getTile();
			else return assets[index + 1].second->getTile();
		}
		std::shared_ptr<BaseTile> getNewPtr(int index) {
			if (index < 0 or index >= assets.size()) return assets[0].second->getNewPtr();
			else return assets[index + 1].second->getNewPtr();
		}
		std::shared_ptr<BaseTile> getNewPtr(String key) {
			for (auto asset : this->assets) {
				if (asset.first == key) return asset.second->getNewPtr();
			}
			return this->assets[0].second->getNewPtr();
		}
		BaseTile operator[] (int index) { return this->get(index); }
		BaseTile operator[] (String&& key);
	};
}
