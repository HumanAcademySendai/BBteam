#include "../StdAfx.h"
#include "タイトルシーン.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool タイトルシーン::Initialize()
{
	// TODO: Add your initialization logic here

	タイトル背景 = GraphicsDevice.CreateSpriteFromFile(_T("タイトル背景.jpg"));

	フェードアウト = GraphicsDevice.CreateSprite(1280, 720, PixelFormat_RGBX8888);
	フェードアウト->ColorFill(nullptr, Color(0, 0, 0));

	フェードアウト数 = 0;
	秒 = 0;
	フェードアウト_state = 0;

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void タイトルシーン::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int タイトルシーン::Update()
{
    // TODO: Add your update logic here

	KeyboardState Keystate = Keyboard->GetState();
	KeyboardBuffer Key_buffer = Keyboard->GetBuffer();

	if (Key_buffer.IsPressed(Keys_Return)) {
		フェードアウト_state = 1;
	}

	if (フェードアウト_state == 1) {

		秒 += 1;

		if (秒 == 3) {
			フェードアウト数 += 0.01f;
			秒 = 0;
		}

		if (1 < フェードアウト数) {
			return GAME_SCENE(new GameMain);
		}
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void タイトルシーン::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SpriteBatch.Begin();

	SpriteBatch.Draw(*タイトル背景, Vector3(0.0f, 0.0f, 0.0f));
	SpriteBatch.Draw(*フェードアウト, Vector3(0.0f, 0.0f,-10.0f), フェードアウト数);

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
