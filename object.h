#pragma once
#include "gameNode.h"
#include "player.h"

enum OBJECTTYPE
{
	DESK,
	LPILLAR,
	RPILLAR,
	PARTICLE1,
	PARTICLE2,
	PARTICLE3
};

class object : public gameNode
{
private:
	//bool _isBreak;					//��� �Ҹ�
	//bool _isCheck;					//��� & ���� �浹
	//bool _isShot;						//��a ���� �߻�
	
	//player* _player;

	image* _objectImg;

	RECT _objectRc;

	OBJECTTYPE _objectType;

	float _objectMX, _objectMY;		//������Ʈ ���̵� ������ - ��ȯ��
	float _objectOX, _objectOY;		//������Ʈ ������

	float _particleAngle;			//��� ������ ������
	float _particleSpeed;			//��� ������ �ӵ���
	float _particleGravity;			//��� ������ �߷°�

public:
	object();
	~object();

	virtual HRESULT init();
	virtual HRESULT init(float x, float y, int type);
	virtual void release();
	virtual void update();
	virtual void render();

	////������Ʈ ����Ʈ ���� x
	float getObjectMX() { return _objectMX; }
	void setObjectMX(float objectMX) { _objectMX = objectMX; }
	
	//������Ʈ ����Ʈ ���� y
	float getObjectMY() { return _objectMY; }
	void setObjectMY(float objectMY) { _objectMY = objectMY; }
	
	//������Ʈ ���� x
	float getObjectOX() { return _objectOX; }
	void setObjectOX(float objectOX) { _objectOX = objectOX; }
	
	//������Ʈ ���� y
	float getObjectOY() { return _objectOY; }
	void setObjectOY(float objectOY) { _objectOY = objectOY; }
	
	//������ ����
	float getParticleAngle() { return _particleAngle; }
	void setParticleAngle(float particleAngle) { _particleAngle = particleAngle; }
	//
	//������ �ӵ�
	float getParticleSpeed() { return _particleSpeed; }
	void setParticleSpeed(float particleSpeed) { _particleSpeed = particleSpeed; }
	
	//������ �߷�
	float getParticleGravity() { return _particleGravity; }
	void setParticleGravity(float particleGravity) { _particleGravity = particleGravity; }

	//������Ʈ ��Ʈ & Ÿ��
	inline RECT getObjectRect() { return _objectRc; }
	int getObjectType() { return (int)_objectType; }
	
	//������Ʈ �̹���
	image* getObjectImg() { return	_objectImg; }
	void setObjectImg(image* objectImg) { _objectImg = objectImg; }

	//void setMemoryAddrsLink(player* player) { _player = player; }
};

