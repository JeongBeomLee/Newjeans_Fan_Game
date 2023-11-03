#include "pch.h"
#include "CCollider.h"

#include "CObject.h"
#include "CCore.h"

#include "SelectGDI.h"

#include "CCamera.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider() : m_pObject(nullptr), m_vFinalPos{}, m_vOffsetPos{}, m_vScale{}, m_iID(g_iNextID++) /*ID�� ����*/, m_iCol(0)
{

}

CCollider::CCollider(const CCollider& _origin)
	: m_pObject(nullptr)
	, m_vFinalPos{}
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_vScale(_origin.m_vScale)
	, m_iID(g_iNextID++) /*ID�� ����*/
	, m_iCol(0)
{
}

CCollider::~CCollider()
{

}

void CCollider::finalUpdate()
{
	// Object�� ��ġ�� ���󰣴�.
	m_vFinalPos = m_pObject->GetPos() + m_vOffsetPos;

	// �浹 ���ΰ� ������ �Ǹ� ����ó��
	assert(m_iCol >= 0);
}

void CCollider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	BRUSH_TYPE eBrush = BRUSH_TYPE::HOLLOW;

	if(m_iCol)
		ePen = PEN_TYPE::RED;

	SelectGDI _selectPen(_dc, ePen);
	SelectGDI _selectbrush(_dc, eBrush);

	// ������ ��ǥ�� ��ȯ
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);

	Rectangle(_dc,
		(int)(vRenderPos.x - m_vScale.x / 2.f),
		(int)(vRenderPos.y - m_vScale.y / 2.f),
		(int)(vRenderPos.x + m_vScale.x / 2.f),
		(int)(vRenderPos.y + m_vScale.y / 2.f));
}

void CCollider::OnCollision(CCollider* _pOther)
{
	m_pObject->OnCollision(_pOther);
}

void CCollider::EnterCollision(CCollider* _pOther)
{
	++m_iCol;
	m_pObject->EnterCollision(_pOther);
}

void CCollider::ExitCollision(CCollider* _pOther)
{
	--m_iCol;
	m_pObject->ExitCollision(_pOther);
}
