#pragma once
#include "gameNode.h"

class object : public gameNode
{
private:
	//bool _isBreak;					//기둥 소멸
	//bool _isCheck;					//기둥 & 보스 충돌
	//bool _isShot;						//기둧 파편 발사
	//
	//image* _objectImg;
	//RECT _objectRc;
	//
	//float _particleAngle;
	//float _particleSpeed;
	//float _particleGravity;
	//
	//float _objectMX, _objectMY;		//오브젝트 가이드 중점 값 - 반환형
	//float _objectOX, _objectOY;		//오브젝트 중점 값


public:
	object();
	~object();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	////오브젝트 가이트 중점 x
	//float getObjectMX() { return _objectMX; }
	//void setObjectMX(float objectMX) { _objectMX = objectMX; }
	//
	////오브젝트 가이트 중점 y
	//float getObjectMX() { return _objectMY; }
	//void setObjectMX(float objectMY) { _objectMX = objectMY; }
	//
	////오브젝트 중점 x
	//float getObjectMX() { return _objectMX; }
	//void setObjectMX(float objectMX) { _objectMX = objectMX; }
	//
	////오브젝트 중점 y
	//float getObjectMX() { return _objectMY; }
	//void setObjectMX(float objectMY) { _objectMX = objectMY; }
	//
	////파편의 각도
	//float getParticleAngle() { return _particleAngle; }
	//void setParticleAngle(float particleAngle) { _particleAngle = particleAngle; }
	//
	////파편의 속도
	//float getParticleSpeed() { return _particleSpeed; }
	//void setParticleSpeed(float particleSpeed) { _particleSpeed = particleSpeed; }
	//
	////파편의 중력
	//float getParticleGravity() { return _particleGravity; }
	//void setParticleGravity(float particleGravity) { _particleGravity = particleGravity; }
};

