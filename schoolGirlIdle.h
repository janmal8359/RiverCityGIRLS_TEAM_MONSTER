#pragma once
#include "schoolGirlState.h"

class schoolGirl;

class schoolGirlIdle : public schoolGirlState
{
public:
	schoolGirl* _SG;

	schoolGirlIdle();
	~schoolGirlIdle();
	
	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;

	void SetschoolGirl(schoolGirl* SG) { _SG = SG; }
};

