#include "Player.h"


CPlayer::CPlayer()
{
	m_iX = 500;
	m_iY = 400;
	m_iR = 20;
	m_iSpeed = m_iR;
	R = 0;
	G = 0;
	B = 0;
}


CPlayer::~CPlayer()
{
}

void CPlayer::OnFrameMove(const float c_fElaspedTime)
{

}

void CPlayer::OnFrameRender(HDC hdc)
{
	hPen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	hBrush = CreateSolidBrush(RGB(R, G, B));

	oldPen = (HPEN)SelectObject(hdc, hPen);
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Ellipse(hdc, m_iX - (m_iR / 2), m_iY - (m_iR / 2), m_iX + (m_iR / 2), m_iY + (m_iR / 2));

	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);
}
