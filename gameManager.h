#pragma once
#include "gameNode.h"

struct UIBar
{
	image* _image;
	RECT _rc;
	float _x, _y;
};

class gameManager : public gameNode
{
private:
	UIBar _playerProfile;
	UIBar _playerHPBar;
	UIBar _playerHPPoint[24];
	UIBar _playerHPBackground;

	bool mapLocked;
	bool mapUnlocked;

	bool scriptStart;
	bool scriptEnd;
	RECT scriptRc;
	image* scriptImage;

	int _playerHP;

public:
	gameManager();
	~gameManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void scriptPlay();
};

