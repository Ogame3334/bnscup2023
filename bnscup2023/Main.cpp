#include <Siv3D.hpp> // Siv3D v0.6.12
#include "include/Tilemap.hpp"
#include "include/Tile.hpp"
#include "include/TileAssets.hpp"
#include "include/Scene.hpp"

void Main()
{
	Window::Resize(1280, 720);

	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	FontAsset::Register(U"Default", 30, Typeface::CJK_Regular_JP);
	FontAsset::Register(U"ButtonDefault", 15, Typeface::CJK_Regular_JP);
	// シーンマネージャーを作成
	App manager;

	// タイトルシーン（名前は "Title"）を登録
	manager.add<TitleScene>(U"Title");

	// ゲームシーン（名前は "Game"）を登録
	manager.add<TestScene>(U"TestScene");
	manager.add<OgameTest>(U"OgameTest");

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
