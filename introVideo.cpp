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
    SCENEMANAGER->init();
    //_count = 0;
    //_iskeydown = false;

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
        MCIWndDestroy(_vid);
        SCENEMANAGER->changeScene("stage1");

    }
    
    if (KEYMANAGER->isOnceKeyDown(VK_F5))
    {
        MCIWndDestroy(_vid);
        SCENEMANAGER->changeScene("stage1");
    
    }
    //if (KEYMANAGER->isOnceKeyUp(VK_RETURN))
    //{
    //    _iskeydown = false;
    //    _count = 0;
    //}
    //
    //if (_count >= 500)
    //{
    //    MCIWndDestroy(_vid);
    //    SCENEMANAGER->changeScene("stage1");
    //}
    //SCENEMANAGER->update();
}

void introVideo::render()
{
    //SCENEMANAGER->render();
}
