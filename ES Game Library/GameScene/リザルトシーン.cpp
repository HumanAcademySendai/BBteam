#include "../StdAfx.h"
#include "���U���g�V�[��.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool ���U���g�V�[��::Initialize()
{
	// TODO: Add your initialization logic here

	���U���g�w�i = GraphicsDevice.CreateSpriteFromFile(_T("���U���g�w�i.jpg"));

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void ���U���g�V�[��::Finalize()
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
int ���U���g�V�[��::Update()
{
    // TODO: Add your update logic here


	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void ���U���g�V�[��::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SpriteBatch.Begin();

	SpriteBatch.Draw(*���U���g�w�i, Vector3(0.0f, 0.0f, 0.0f));

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
