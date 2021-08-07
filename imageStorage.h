#pragma once
#include "gameNode.h"
#include "animation.h"
class imageStorage : public gameNode
{
private:
	int _currentCount;

	image* _background;
	image* _loading;
	animation* _load;
	

public:
	imageStorage();
	~imageStorage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void playerImage();
	void npcImage();
	void enemyImage();
	void effectImage();
	void objectImage();

	static DWORD CALLBACK threadFunction(LPVOID lpParameter);
};
