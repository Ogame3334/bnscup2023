# include <Siv3D.hpp> // Siv3D v0.6.12

void Main()
{
	Font font{ 30, Typeface::CJK_Regular_JP };
	while (System::Update())
	{
		font(U"いぇーい！\n二人とも見てる～！？！？").drawAt(Scene::CenterF(), Palette::White);
	}
}
