// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));
	player = GraphicsDevice.CreateSpriteFromFile(_T("player.png"));
	bg = GraphicsDevice.CreateSpriteFromFile(_T("bg.png"));
	x = 0;
	y = 0;
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
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
int GameMain::Update()
{
	// TODO: Add your update logic here

	KeyboardBuffer Key_buffer = Keyboard->GetBuffer();

	if (Key_buffer.IsPressed(Keys_Return)) {
		return GAME_SCENE(new リザルトシーン);
	}

	KeyboardState key = Keyboard->GetState();
	if (key.IsKeyDown(Keys_Right))
	{
		x += 10;
	}
	if (key.IsKeyDown(Keys_Left))
	{
		x -= 10;
	}
	if (key.IsKeyDown(Keys_Down))
	{
		y += 10;
	}
	if (key.IsKeyDown(Keys_Up))
	{
		y -= 10;
	}
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();
	SpriteBatch.Draw(*bg, Vector3(0, 0, 0));
	SpriteBatch.Draw(*player, Vector3(x, y, 0));

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
