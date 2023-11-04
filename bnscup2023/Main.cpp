﻿#include <Siv3D.hpp> // Siv3D v0.6.12
#include "include/Tilemap.hpp"
#include "include/Tile.hpp"
#include "include/TileAssets.hpp"
#include "include/Scene.hpp"

void Main()
{
	Window::Resize(1280, 720);
	System::SetTerminationTriggers(UserAction::CloseButtonClicked);

	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	FontAsset::Register(U"Default", 30, Typeface::CJK_Regular_JP);
	FontAsset::Register(U"ButtonDefault", 15, Typeface::CJK_Regular_JP);

	AudioAsset::Register(U"menu_enter", U"Assets/SoundEffect/menu_enter.mp3");
	AudioAsset::Register(U"menu_move", U"Assets/SoundEffect/menu_move.mp3");
	// シーンマネージャーを作成
	App manager;

	// タイトルシーン（名前は "Title"）を登録
	manager.add<TitleScene>(U"Title");

	// ゲームシーン（名前は "Game"）を登録
	manager.add<TestScene>(U"TestScene");
	manager.add<OgameTest>(U"OgameTest");
	manager.add<MenuTest>(U"MenuTest");
	manager.add<AnimTestScene>(U"AnimTestScene");

	manager.init(U"Title", .3s);

	constexpr int FPS = 60; // 1秒間に1画面を書き換える回数
	Stopwatch sw;   //FPS60
	sw.start(); //FPS60
	while (System::Update())
	{
		//Cursor::RequestStyle(CursorStyle::Hidden);
		if (not manager.update())
		{
			break;
		}
		while (sw.msF() < 1000.0 / FPS);    //1/60秒経過するまでループ
		sw.restart();   //FPS60  ストップウォッチをリスタート
	}
}
