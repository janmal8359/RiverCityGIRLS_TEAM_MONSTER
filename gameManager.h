#pragma once
#include "gameNode.h"
#include <string>
#include "progressBar.h"



class pixelCollisionClass;

class player;

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
	image* chainTop;
	image* chainBottom;
	image* chainLeft;
	image* chainRight;
	image* chainLock;
	int _count, _index;

	// 스크립트
	bool scriptStart;			// 시작
	bool scriptEnd;				// 끝
	RECT scriptRc;				// 렉트
	image* scriptImage;			// 배경이미지
	int _scriptIndex;			// 스크립트 인덱스
	int _txtIndex;				// 텍스트 인덱스
	vector<string> _vScript;	// 스크립트 벡터
	string _txt;				// 문자열
	image* scriptSkip;			// 스킵 이미지
	bool _scriptSkip;			// 스킵 여부

	image* kScript;				// 쿄코
	image* mScript;				// 미스즈
	image* scriptName;			// 스크립트 이름


	

	int _playerHP;

	player* _player;

	pixelCollisionClass* _pix;

public:
	gameManager();
	~gameManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void scriptPlay();

	void eventMap();

	bool getScriptEnd() { return scriptEnd; }
	void setScriptEnd(bool end) { scriptEnd = end; }

	bool getScriptStart() { return scriptStart; }
	void setScriptStart(bool start) { scriptStart = start; }




	void setPixelM(pixelCollisionClass* pixel) { _pix = pixel; }

	void setPlayer(player* pl) { _player = pl; }
};

