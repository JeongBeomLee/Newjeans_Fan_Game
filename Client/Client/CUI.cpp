#include "pch.h"
#include "CUI.h"

CUI::CUI()
{
}

CUI::~CUI()
{
}


void CUI::update()
{
}

void CUI::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc, 
		vPos.x, 
		vPos.y, 
		vPos.x + vScale.x, 
		vPos.y + vScale.y);
}