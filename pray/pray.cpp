#include "Pray.h"


CPray::CPray()
{
	m_iX = rand() % 1024;
	m_iY = rand() % 768;
	m_iR = 15;

	R = rand() % 256;
	G = rand() % 256;
	B = rand() % 256;
}


CPray::~CPray()
{
}

void CPray::OnFrameMove(const float c_fElapsedTime)
{

}

void CPray::OnFrameRender(HDC hdc)
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
