#pragma once
#pragma comment (lib,"Vfw32.lib")

#include "gameNode.h"
//#include <Windows.h>
#include <Vfw.h>


class introVideo : public gameNode
{
private:
	HWND _vid;

public:
	introVideo();
	~introVideo();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

