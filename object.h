#pragma once
#include "gameNode.h"

class object : public gameNode
{
private:
	//bool _isBreak;					//��� �Ҹ�
	//bool _isCheck;					//��� & ���� �浹
	//bool _isShot;						//��a ���� �߻�
	//
	//image* _objectImg;
	//RECT _objectRc;
	//
	//float _particleAngle;
	//float _particleSpeed;
	//float _particleGravity;
	//
	//float _objectMX, _objectMY;		//������Ʈ ���̵� ���� �� - ��ȯ��
	//float _objectOX, _objectOY;		//������Ʈ ���� ��


public:
	object();
	~object();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	////������Ʈ ����Ʈ ���� x
	//float getObjectMX() { return _objectMX; }
	//void setObjectMX(float objectMX) { _objectMX = objectMX; }
	//
	////������Ʈ ����Ʈ ���� y
	//float getObjectMX() { return _objectMY; }
	//void setObjectMX(float objectMY) { _objectMX = objectMY; }
	//
	////������Ʈ ���� x
	//float getObjectMX() { return _objectMX; }
	//void setObjectMX(float objectMX) { _objectMX = objectMX; }
	//
	////������Ʈ ���� y
	//float getObjectMX() { return _objectMY; }
	//void setObjectMX(float objectMY) { _objectMX = objectMY; }
	//
	////������ ����
	//float getParticleAngle() { return _particleAngle; }
	//void setParticleAngle(float particleAngle) { _particleAngle = particleAngle; }
	//
	////������ �ӵ�
	//float getParticleSpeed() { return _particleSpeed; }
	//void setParticleSpeed(float particleSpeed) { _particleSpeed = particleSpeed; }
	//
	////������ �߷�
	//float getParticleGravity() { return _particleGravity; }
	//void setParticleGravity(float particleGravity) { _particleGravity = particleGravity; }
};

