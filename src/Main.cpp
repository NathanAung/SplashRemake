# include <Siv3D.hpp>
# include "Title.h"
# include "Game.h"

#if true 


void Main()
{
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	const Texture texture{ U"Assets/Sprites/Player/pg_idle.png" };
	constexpr int32 patterns[4] = { 1, 2, 1, 0 };
	double timer = 0.0;
	int32 x = 0;
	int32 y = 0;

	while (System::Update())
	{
		const ScopedRenderStates2D sampler{ SamplerState::ClampNearest };

		/*
		const uint64 t = Time::GetMillisec();
		const int32 x = ((t / 2000 % 1) * 5);
		const int32 y = (t / 4000 % 4);
		const int32 n = (t / 250 % 4);
		*/
		

		
		timer += Scene::DeltaTime();
		if(timer > 0.1){
			x++;
			timer = 0.0;
		}

		if(x == 5){
			x = 0;
			y++;
		}
		if(y == 5){
			y = 0;
		}
		if(y == 4 && x == 4){
			x = 0;
			y++;
		}

		

		Rect{ (x * 77), (y * 77), (77), (77) }
		.draw(ColorF{ 0.3, 0.9, 0.8 });

		texture.scaled(0.2).draw();

		Rect{ 400, 100, 384, 384 }
			.draw(ColorF{ 0.5, 0.9, 0.5 });

		texture((x * 384), (y * 384), 384, 384)
			.scaled(1).draw(400, 100);

		//texture()

		
	}
}


#else

using App = SceneManager<String>;

void Main()
{
	Window::SetTitle(U"兵士はつらいよ");
	Window::Resize(1280, 720);

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 48, Typeface::Bold);

	// Create scene manager
	App manager;

	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");

	manager.setFadeColor(ColorF{ 0.8, 0.9, 1.0 });

	manager.init(U"Title", 0.75s);

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}

#endif