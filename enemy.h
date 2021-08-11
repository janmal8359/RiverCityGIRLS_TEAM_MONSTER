#pragma once
#include "gameNode.h"
#include "enemyState.h"


class player;
class camera;

class enemy : public gameNode
{

private:
		
	player* _player;				//ÇÃ·¹ÀÌ¾î
	camera* _camera;				//Ä«¸Ş¶ó
	
	enemyState* _enemyState;		//¿¡³Ê¹Ì ½ºÅ×ÀÌÆ®

	image*	_enemyShadowImg;		//Àû ±×¸²ÀÚ ÀÌ¹ÌÁö
	RECT	_enemyShadowRc;			//±×¸²ÀÚ ·ºÆ®

	float _enemySX, _enemySY;		//±×¸²ÀÚ x,y
	float _enemySpeed, _enemyRes;	//¼Óµµ,¼ÓµµÁÙ¾îµë?

	float _enemyJP;					//Á¡ÇÁÆÄ¿ö

	bool _isEIdle;					//±âº» ºÒ°ª
	bool _isEJump;					//Á¡ÇÁ ºÒ°ª
	bool _isEChase;					//Ãß°İ ºÒ°ª
	bool _isEAttack;				//°ø°İ ºÒ°ª
	bool _isEHurt;					//ÇÇ°İ ºÒ°ª
	bool _isEWaitAttack;			//¾îÅÃ ´ë±â ºÒ°ª
	bool _isDie;					//Á×À½ ºÒ°ª
	bool _isRun;					//´Ş¸®´Â ºÒ°ª

	image* _enemyImg;				//Àû ÀÌ¹ÌÁö
	RECT _enemyRc;					//Àû ·ºÆ®
	
	int _enemyCount;					//¾îÅÃ µ¿ÀÛÄ«¿îÆ®


	float _enemyX, _enemyY;			//Àû x,y°ª
	float _enemyDistance;			//ÀûÀÌ ¿ŞÂÊ ¹Ù¶óº¼¶§ ÇÃ·¹ÀÌ¾î °Å¸®
	float _enemyDistanceR;			//ÀûÀÌ ¿À¸¥ÂÊ ¹Ù¶óº¼¶§ ÇÃ·¹ÀÌ¾î °Å¸®



	int _enemyDir;					//Àû ¹æÇâ

	

public:
	enemy();
	~enemy();

	HRESULT init();					//ÃÊ±âÈ­
	void release();					//¸Ş¸ğ¸® ÇØÁ¦
	void update();					//¿¬»êÇÔ¼ö
	void render();					//±×¸®±â ÇÔ¼ö

	void enemyStateRender(animation* motion);				//½ºÅ×ÀÌÆ® ·»´õ?
	void enemyMove();										//¿òÁ÷ÀÓ
	void enemyAttack();										//°ø°İ
	//void enemyChase();									//Ãß°İ

	void enemyAni();										//Àû ¾Ö´Ï¸ŞÀÌ¼Ç
	

	static void callBack(void* obj);
	
	//Á¢±ÙÀÚ ¹× ¼³Á¤ÀÚ

	//Àû x
	float getEnemyX() { return _enemyX; }
	void setEnemyX(float Ex) { _enemyX = Ex; }

	//Àû y
	float getEnemyY() { return _enemyY; }
	void seteEnemyY(float Ey) { _enemyY = Ey; }

	//Àû ±×¸²ÀÚ x
	float getEnemySX() { return _enemySX; }
	void setEnemySX(float ESx) {_enemySX = ESx; }

	//Àû ±×¸²ÀÚ y
	float getEnemySY() { return _enemySY; }
	void setEnemySY(float ESy) { _enemySY = ESy; }

	//Àû ½ºÇÇµå°ª
	float getEnemySpeed() { return _enemySpeed; }
	void setEnemySpeed(float ESpeed) { _enemySpeed = ESpeed; }

	//Àû Á¡ÇÁ°ª
	float getEnemyJumpPower() { return _enemyJP; }
	void setEnemyJumpPower(float EJump) { _enemyJP = EJump; }


	//Àû ÀÏ¹İ»óÈ²
	bool getIsEnemyIdle() { return _isEIdle; }
	void setIsEnemyIdle(bool isEIdle) { _isEIdle = isEIdle; }
	//Àû Á¡ÇÁ»óÈ²
	bool getIsEenmyJump() { return _isEJump; }
	void setIsEnemyJump(bool isEJump) { _isEJump = isEJump; }
	//Àû °ø°İ»óÈ²
	bool getIsEnemyAttack() { return _isEAttack; }
	void setIsEnemyAttack(bool isEattack) { _isEAttack = isEattack; }
	//Àû Ãß°İ»óÈ²
	bool getIsEenmyChase() { return _isEChase; }
	void setIsEnemyChase(bool isEchase) { _isEChase = isEchase; }
	//Àû ÇÇ°İ»óÈ²
	bool getIsEnemyHurt() { return _isEHurt; }
	void setIsEnemyHurt(bool isEhurt) { _isEHurt = isEhurt; }
	//Àû ¾îÅÃ´ë±â »óÈ²
	bool getIsEnemyWaitAttack() { return _isEWaitAttack; }
	void setIsEnemyWaitAttack(bool isEWaitAttack) { _isEWaitAttack = isEWaitAttack; }
	//Àû Á×À½ »óÈ²
	bool getIsEnemyDie() { return _isDie; }
	void setIsEnemyDie(bool isDie) { _isDie = isDie; }
	//Àû ´Ş¸®´Â »óÈ²
	bool getIsEnemyRun() { return _isRun; }
	void setIsEnemyRun(bool isRun) { _isRun = isRun; }
	
	//Àû°ú ÇÃ·¹ÀÌ¾î °Å¸®°ª
	float getEnemyDistance() { return _enemyDistance; }			//¿ŞÂÊ ¹Ù¶óº¼¶§
	float getEnemyDistanceR() { return _enemyDistanceR; }		//¿À¸¥ÂÊ ¹Ù¶óº¼¶§
	
	int getEnemyCount() { return _enemyCount; }								//¿¡³Ê¹Ì µ¿ÀÛ Ä«¿îÆ®
	void setEnemyCount(int enemyCount) { _enemyCount = enemyCount; }		

	//Àû ·ºÆ®
	RECT getEnemyRc() { return _enemyRc; }

	//Àû ¹æÇâ
	int getDir() { return (int)_enemyDir; }

	//Àû ÀÌ¹ÌÁö
	image* getEnemyImg() { return _enemyImg; }
	void setEnemyImg(image* EnemyIMG) { _enemyImg = EnemyIMG; }

	//Áß°£¿¡ ¸ğ¼ÇÀÌ ¹Ù²î¸é ·»´õ·Î ¹Ù²îÁö ¾ÊÀ¸ ÀÌ¹ÌÁö°¡ ·ÎµåµÊ updateºÎÅÍ ´Ù½Ã ½ÃÀÛÀÌ¶ø´Ï´Ù.
	void setEnemyState(enemyState* EState) { _enemyState = EState; update(); update(); }

	enemyState* getEnemyState() { return _enemyState; }

	//player¿Í ¿¬µ¿
	void setPlayerMemoryLink(player* player) { _player = player; }

<<<<<<< HEAD
	virtual float getPosY() { return _enemySY; }

	//camera¿Í ¿¬µ¿
	void setCameraMemoryLink(camera* camera) { _camera = camera; }
=======
>>>>>>> parent of 682375e (zorder ì¼ë‹¨êµ¬í˜„ ê°ì²´í™” í™•ì¸)
};

