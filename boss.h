#pragma once

class bossState;

class boss
{
private:
	bossState* _state;

public:
	boss() {}
	~boss() {}

	HRESULT init();
	void release();
	void update();
	void render();

	void setState(bossState* state) { _state = state; }

};

