# include <Siv3D.hpp> // Siv3D v0.6.12

struct GameData {

};

using App = SceneManager<String, GameData>;

class Title : public App::Scene
{
public:
	Title(const InitData& init)
		: IScene{ init }
	{

	}

	void update() override
	{
		if(Platform::Windows::Keyboard::GetEvents().size() != 0)
			changeScene(U"GameTest", 500, CrossFade{ false });
	}

	void draw() const override
	{
		Scene::SetBackground(ColorF{ 0.3, 0.4, 0.5 });
		FontAsset(U"TitleFont")(U"My Game").drawAt(640, 200);
		FontAsset(U"Default")(U"Press Any Key").drawAt(640, 360);
	}
};

class GameTest : public App::Scene
{
public:
	GameTest(const InitData& init)
		: IScene{ init }
	{

	}

	void update() override
	{

	}

	void draw() const override
	{

	}
};
void Main()
{
	Window::Resize(1280, 720);


	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	FontAsset::Register(U"Default", 30, Typeface::CJK_Regular_JP);
	// シーンマネージャーを作成
	App manager;

	// タイトルシーン（名前は "Title"）を登録
	manager.add<Title>(U"Title");

	// ゲームシーン（名前は "Game"）を登録
	manager.add<GameTest>(U"GameTest");

	while (System::Update())
	{
		//Cursor::RequestStyle(CursorStyle::Hidden);
		if (not manager.update())
		{
			break;
		}
	}
}
