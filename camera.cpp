#include "pch.h"
#include "camera.h"

HRESULT camera::init()
{

    //½ÇÁúÀû ½ÃÀÛ À§Ä¡


    //Ä«¸Þ¶ó ·ºÆ® Áß½É
    _camXrc = WINSIZEX / 2;
    _camYrc = WINSIZEY / 2;

    _cameraRc = RectMakeCenter(_camXrc, _camYrc, 150, 150);

    switch (_stage)
    {
    case FIRST_STAGE:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    case SECOND_STAGE:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage2");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel2");
        break;
    case THIRD_STAGE:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage3");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel3");
        break;
    case BOSS_STAGE1:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    case BOSS_STAGE2:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    default:
        break;
    }

    return S_OK;
}

void camera::release()
{
}

void camera::update()
{
<<<<<<< HEAD
    switch (_stageImg)
    {
    case FIRST_STAGE:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    case SECOND_STAGE:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage2");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel2");
        break;
    case THIRD_STAGE:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage3");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel3");
        break;
    case BOSS_STAGE1:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    case BOSS_STAGE2:
        _camX = 0;
        _camY = 0;
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    default:
        break;
    }
=======
  
>>>>>>> parent of 682375e (zorder ì¼ë‹¨êµ¬í˜„ ê°ì²´í™” í™•ì¸)
}

void camera::render()
{
    _backGroundImg->render(getMemDC(), 0, 0, _camX, _camY, WINSIZEX, WINSIZEY);

    if (KEYMANAGER->isToggleKey(VK_TAB))
    {
        _pixelImg->render(getMemDC(), 0, 0, _camX, _camY, WINSIZEX, WINSIZEY);
        Rectangle(getMemDC(), _cameraRc);
    }
    Rectangle(getMemDC(), _cameraRc);



    char str[128];

    sprintf_s(str, "camX : %.2f camY : %.2f", _camX, _camY);
    TextOut(getMemDC(), 10, 680, str, strlen(str));
}

void camera::cameraLock(float x, float y)
{
    _camXrc = WINSIZEX / 2;
    _camYrc = WINSIZEY / 2;

    _cameraRc = RectMakeCenter(_camXrc, _camYrc, 150, 150);
}