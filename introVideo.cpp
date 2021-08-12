#include "pch.h"
#include "introVideo.h"




introVideo::introVideo()
{
}

introVideo::~introVideo()
{
}

HRESULT introVideo::init()
{
    _vid = MCIWndCreate(_hWnd, NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, "Resource/VID/intro.wmv");

    MoveWindow(_vid, 0, 0, WINSIZEX, WINSIZEY, NULL);

    MCIWndPlay(_vid);

    



    return S_OK;
}

void introVideo::release()
{
}

void introVideo::update()
{
    if (MCIWndGetLength(_vid) <= MCIWndGetPosition(_vid))
    {
        SCENEMANAGER->changeScene("stage1");
        return;
    }
    
}

void introVideo::render()
{
    
}
