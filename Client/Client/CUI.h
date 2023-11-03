#pragma once
#include "CObject.h"
class CUI :
    public CObject
{
private:


	CLONE(CUI)

public:
    void update() override;
	void render(HDC _dc) override;

public:
    CUI();
	~CUI();
};

