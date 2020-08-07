#include "../StdAfx.h"
#include "�^�C�g���V�[��.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool �^�C�g���V�[��::Initialize()
{
	// TODO: Add your initialization logic here

	�^�C�g���w�i = GraphicsDevice.CreateSpriteFromFile(_T("�^�C�g���w�i.jpg"));

	�t�F�[�h�A�E�g = GraphicsDevice.CreateSprite(1280, 720, PixelFormat_RGBX8888);
	�t�F�[�h�A�E�g->ColorFill(nullptr, Color(0, 0, 0));

	�t�F�[�h�A�E�g�� = 0;
	�b = 0;
	�t�F�[�h�A�E�g_state = 0;

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void �^�C�g���V�[��::Finalize()
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
int �^�C�g���V�[��::Update()
{
    // TODO: Add your update logic here

	KeyboardState Keystate = Keyboard->GetState();
	KeyboardBuffer Key_buffer = Keyboard->GetBuffer();

	if (Key_buffer.IsPressed(Keys_Return)) {
		�t�F�[�h�A�E�g_state = 1;
	}

	if (�t�F�[�h�A�E�g_state == 1) {

		�b += 1;

		if (�b == 3) {
			�t�F�[�h�A�E�g�� += 0.01f;
			�b = 0;
		}

		if (1 < �t�F�[�h�A�E�g��) {
			return GAME_SCENE(new GameMain);
		}
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void �^�C�g���V�[��::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SpriteBatch.Begin();

	SpriteBatch.Draw(*�^�C�g���w�i, Vector3(0.0f, 0.0f, 0.0f));
	SpriteBatch.Draw(*�t�F�[�h�A�E�g, Vector3(0.0f, 0.0f,-10.0f), �t�F�[�h�A�E�g��);

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
