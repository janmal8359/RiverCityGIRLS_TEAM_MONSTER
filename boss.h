#pragma once

class bossState;

enum class STATE
{
	IDLE,
	WALK,
	ATTACK,
	JUMP,
	SIT,
	GROGGY,
	LOSE
};

class boss
{
private:
	//bossState* _state;
	//STATE* _state;

public:
	boss() {}
	~boss() {}

	HRESULT init();
	void release();
	void update();
	void render();

	// setState(bossState* state) { _state = state; }

};

