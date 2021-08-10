#include "pch.h"
#include "pixelCollisionClass.h"
#include "player.h"

pixelCollisionClass::pixelCollisionClass()
{
}

pixelCollisionClass::~pixelCollisionClass()
{
}

HRESULT pixelCollisionClass::init()
{

	return S_OK;
}

HRESULT pixelCollisionClass::init(float x, float y, int stageType)
{
	_stageType = (STAGETYPE)stageType;
	
	if (_stageType == 0) _stage = IMAGEMANAGER->findImage("STAGE_stagePixel1");
	//if (_stageType == 1) _stage = IMAGEMANAGER->findImage("STAGE_stagePixel4");
	//if (_stageType == 2) _stage = IMAGEMANAGER->findImage("STAGE_normalPixel");
	//if (_stageType == 3) _stage = IMAGEMANAGER->findImage("STAGE_bossPixel");

	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, _stage->getWidth(), _stage->getHeight());

	_camera = new camera;
	_camera->init();

	return S_OK;
}

void pixelCollisionClass::release()
{
}

void pixelCollisionClass::update()
{
	_probeLX = _player->getShadowX() - (_player->getShadowImg()->getWidth()  / 2 );
	_probeRX = _player->getShadowX() + (_player->getShadowImg()->getWidth()  / 2 );
	_probeTY = _player->getShadowY() - (_player->getShadowImg()->getHeight() / 2 );
	_probeBY = _player->getShadowY() + (_player->getShadowImg()->getHeight() / 2 );

	//_probeLBox = RectMakeCenter(_player->getShadowX() - (_player->getShadowImg()->getWidth() / 2) - 50, _player->getShadowY(), 10, 10);
	//_probeRBox = RectMakeCenter(_player->getShadowX() + (_player->getShadowImg()->getWidth() / 2) + 50, _player->getShadowY(), 10, 10);
	//_probeTBox = RectMakeCenter(_player->getShadowX(), _player->getShadowY() - (_player->getShadowImg()->getHeight() / 2) - 50, 10, 10);
	//_probeTBox = RectMakeCenter(_player->getShadowX(), _player->getShadowY() + (_player->getShadowImg()->getHeight() / 2) + 50, 10, 10);

	Colloision();
}

void pixelCollisionClass::render()
{
	char str[256];
	sprintf_s(str, "%0.2f", ((_probeTY + _probeBY) / 2) + _camera->getCamY());

	TextOut(getMemDC(), 0, WINSIZEY / 2, str, strlen(str));

	//if(_stage != NULL) _stage->render(getMemDC(), _x, _y);
}

void pixelCollisionClass::Colloision()
{
	//for (int _stageType = 0; _stageType < 4; _stageType++)
	//{
	
		for (int i = _probeLX - 1; i < _probeRX + 1; i++)
		{
			//_stage = IMAGEMANAGER->findImage("STAGE_stagePixel1");
			//COLORREF color = GetPixel(_stage->getMemDC(), i + _camera->getCamX(), _player->getShadowY() + _camera->getCamY()); �⺻
			//COLORREF color = GetPixel(_stage->getMemDC(), i + _camera->getCamX(), _player->getShadowY() + _camera->getCamY() + 50); ��Ʈ������ + 50
			COLORREF color = GetPixel(_stage->getMemDC(), i + _camera->getCamX(), _player->getShadowY() + _camera->getCamY());

			int R = GetRValue(color);
			int G = GetGValue(color);
			int B = GetBValue(color);

			if (!(R == 255 && G == 0 && B == 255))
			{
				//��
				if (R == 255 && G == 0 && B == 0)//����
				{
					_player->setSpeed(6);
				}
				//å�� �ٴ�
				else if (R == 0 && G == 255 && B == 0)//�׸�
				{
					//_player->setShadowX(_player->getShadowX() + 8);
					_player->setSpeed(6);
				}
				//else if (R == 0 && G == 0 && B == 255)//�Ķ�
				//{
				//	_player->setSpeed(6);
				//}
				else if (R == 255 && G == 255 && B == 0)//���
				{
					_player->setSpeed(6);
				}
				//������ ���� ����
				else if (R == 0 && G == 255 && B == 255)//��Ʈ
				{
					_player->setSpeed(6);
					// �÷��̾� �ֺ��� �� �ִϸ��̼� ���

				}
				//�� �̿�
				else
				{
					_player->setSpeed(6);
				}
			}
			else
			{
				_player->setSpeed(6);
			}
		}
	
		for (int i = _probeTY - 1; i < _probeBY + 1; i++)
		{
			//_stage = IMAGEMANAGER->findImage("STAGE_stagePixel1");
			//COLORREF color = GetPixel(_stage->getMemDC(), _player->getShadowX() + _camera->getCamX(), i - _camera->getCamY()); �⺻
			//COLORREF color = GetPixel(_stage->getMemDC(), i + _camera->getCamX() + 50, _player->getShadowY() + _camaera->getCamY()); ��Ʈ�� y�� +50�� ���� ���� ����
			COLORREF color = GetPixel(_stage->getMemDC(), _player->getShadowX() + _camera->getCamX(), i + _camera->getCamY());

			int R = GetRValue(color);
			int  G = GetGValue(color);
			int  B = GetBValue(color);

			if (!(R == 255 && G == 0 && B == 255))
			{
				//��
				if (R == 255 && G == 0 && B == 0)//����
				{
					_player->setSpeed(6);
				}
				//å�� �ٴ�
				else if ((R == 0 && G == 255 && B == 0))//�׸�
				{
					//_player->setShadowY(_player->getShadowY() + 8);
					_player->setSpeed(6);
				}
				//else if (R == 0 && G == 0 && B == 255)//�Ķ�
				//{
				//	_player->setSpeed(6);
				//}
				else if ((R == 255 && G == 255 && B == 0))//���
				{
					_player->setSpeed(6);
				}
				//������ ���� ����
				else if ((R == 0 && G == 255 && B == 255))//��Ʈ
				{
					_player->setSpeed(6);

				}
				//�� �̿�
				else
				{
					_player->setSpeed(6);
				}
			}
			else
			{
				_player->setSpeed(6);
			}
		}

	//}
}
