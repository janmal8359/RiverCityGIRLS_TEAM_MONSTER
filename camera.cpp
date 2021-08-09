#include "pch.h"
#include "camera.h"

HRESULT camera::init()
{

    _camXrc = WINSIZEX / 2;
    _camYrc = WINSIZEY / 2;

    

    _cameraRc = RectMakeCenter(_camXrc, _camYrc, 150, 150);


    return S_OK;
}

void camera::release()
{
}

void camera::update()
{
    switch (_stage)
    {
    case FIRST_STAGE:
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    case SECOND_STAGE:
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage2");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel2");
        break;
    case THIRD_STAGE:
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage3");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel3");
        break;
    case BOSS_STAGE1:
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    case BOSS_STAGE2:
        _backGroundImg = IMAGEMANAGER->findImage("STAGE_stage1");
        _pixelImg = IMAGEMANAGER->findImage("STAGE_stagePixel1");
        break;
    default:
        break;
    }
}

void camera::render()
{
    
}
