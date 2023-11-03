#include "pch.h"
#include "CScene_Start.h"
#include "CKeyMgr.h"

#include "CCore.h"
#include "CBackground.h"

#include "CUI.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	///////////////////////
	// Background Object //
	///////////////////////
	CObject* pBGObj = new CBackground;
	pBGObj->SetName(L"Start Background");
	pBGObj->SetPos(Vec2(0.f, 0.f));
	pBGObj->SetScale(Vec2(vResolution.x, vResolution.y));

	// 애니메이터 생성
	pBGObj->CreateAnimator();

	CreateObject(pBGObj, GROUP_TYPE::BACKGROUND);
	///////////////////////

	///////////////
	// UI Object //
	///////////////

	CUI* pUI = new CUI;
	pUI->SetScale(Vec2(100.f, 30.f));
	pUI->SetPos(Vec2(vResolution.x / 2.f, vResolution.y / 2.f));
	AddObject(pUI, GROUP_TYPE::UI);

	///////////////


	CCamera::GetInst()->SetLookAt(vResolution / 2.f);
}

void CScene_Start::Exit()
{
	DeleteAll();
}

void CScene_Start::update()
{
	CScene::update();

	// + @
	if (KEY_TAP(KEY::LBOTTON)) {
		// 마우스 좌표를 받아온다.
		Vec2 vMousePos = CKeyMgr::GetInst()->GetMousePos();

		int i = 0;
		//ChangeScene(SCENE_TYPE::MAIN);
	}
}