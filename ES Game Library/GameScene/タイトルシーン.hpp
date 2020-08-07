#pragma once

#include "GameScene.hpp"
#include "../ESGLib.h"

class �^�C�g���V�[�� : public CGameScene {
public:
	�^�C�g���V�[��()
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~�^�C�g���V�[��()
	{
		Finalize();

#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();
	}

	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();

private:
	// �ϐ��錾

	SPRITE �^�C�g���w�i;
	SPRITE �t�F�[�h�A�E�g;

	int �b;
	int �t�F�[�h�A�E�g_state;
	float �t�F�[�h�A�E�g��;

	// �֐��v���g�^�C�v

};
