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
	if (_stageType == 1) _stage = IMAGEMANAGER->findImage("STAGE_stagePixel4");
	if (_stageType == 2) _stage = IMAGEMANAGER->findImage("STAGE_normalPixel");
	if (_stageType == 3) _stage = IMAGEMANAGER->findImage("STAGE_bossPixel");

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

	Colloision();
}

void pixelCollisionClass::render()
{
	char str[128];
	
	sprintf_s(str, "%0.2f,%0.2f", _camera->getCamY(), _player->getShadowY());

	TextOut(getMemDC(), 0, WINSIZEY / 2, str, strlen(str));
}

void pixelCollisionClass::Colloision()
{	
		for (int i = _probeLX - 1; i < _probeRX + 1; i++)
		{
			COLORREF color = GetPixel(_stage->getMemDC(), i + _camera->getCamX(), _player->getShadowY() + _camera->getCamY());

			int R = GetRValue(color);
			int G = GetGValue(color);
			int B = GetBValue(color);

			if (!(R == 255 && G == 0 && B == 255))
			{
				//��
				if (R == 255 && G == 0 && B == 0)			//����
				{
					//_player->setSpeed(6);					//0���� ����
				}
				//å�� �ٴ�
				else if (R == 0 && G == 255 && B == 0)		//�׸� - 0���� ����
				{
					//_player->setSpeed(6);
				}
				else if (R == 255 && G == 255 && B == 0)	//���
				{
					//_player->setSpeed(6);
				}
				//������ ���� ����
				else if (R == 0 && G == 255 && B == 255 && KEYMANAGER->isOnceKeyDown('J'))	//��Ʈ
				{
					//_player->setSpeed(6);
					// �÷��̾� �ֺ��� �� �ִϸ��̼� ���
					//Ư�� Ű �Է½� ���� ���������� �̵�
					_camera->setStage(2);
					_player->setShadowX(500);
					_player->setShadowY(600);
					_camera->setCamX(0);
					_camera->setCamY(0);
				} 
				
				//�� �̿�
				else
				{
					//_player->setSpeed(6);
				}
			}
			else
			{
				//_player->setSpeed(6);
			}
		}
	
		for (int i = _probeTY - 1; i < _probeBY + 1; i++)
		{
			COLORREF color = GetPixel(_stage->getMemDC(), _player->getShadowX() + _camera->getCamX(), _player->getShadowY() + _camera->getCamY());

			int R = GetRValue(color);
			int G = GetGValue(color);
			int B = GetBValue(color);

			if (!(R == 255 && G == 0 && B == 255))
			{
				//��
				if (R == 255 && G == 0 && B == 0)			//����
				{
					//_player->setSpeed(6);					//0���� ����
				}
				//å�� �ٴ�
				else if ((R == 0 && G == 255 && B == 0))	//�׸� - 0���� ����
				{
					//_player->setSpeed(6);
				}
				else if ((R == 255 && G == 255 && B == 0))	//���
				{
					//_player->setSpeed(6);
				}
				//������ ���� ����
				else if ((R == 0 && G == 255 && B == 255) && KEYMANAGER->isOnceKeyDown('J'))	//��Ʈ
				{
					//_player->setSpeed(6);
					//_player->setSpeed(6);
					// �÷��̾� �ֺ��� �� �ִϸ��̼� ���
						_camera->setStage(2);
						_player->setShadowX(500);
						_player->setShadowY(600);
						_camera->setCamX(0);
						_camera->setCamY(0);
				}
				//�� �̿�
				else
				{
					//_player->setSpeed(6);
				}
			}
			else
			{
				//_player->setSpeed(6);
			}
		}
}
