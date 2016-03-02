#include "Player.h"


CPlayer::CPlayer()
{
	m_iX = 500;
	m_iY = 400;
	m_iR = 20;
	m_iSpeed = 2;
	R = 0;
	G = 0;
	B = 0;
	hPen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	hBrush = CreateSolidBrush(RGB(R, G, B));

}


CPlayer::~CPlayer()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
}

void CPlayer::OnFrameMove(const float c_fElaspedTime)
{
	Arrive();
}

void CPlayer::OnFrameRender(HDC hdc)
{
	oldPen = (HPEN)SelectObject(hdc, hPen);
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Ellipse(hdc, m_iX - (m_iR / 2), m_iY - (m_iR / 2), m_iX + (m_iR / 2), m_iY + (m_iR / 2));

}

void CPlayer::Arrive(void)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	double angle;
	angle = GetAngle(m_iX, m_iY, pt.x, pt.y);

//	printf("m_iX : %d m_iY\n", m_iX, m_iY);
//	printf("pt.x : %d pt.y: %d angle: %d\n", pt.x, pt.y,angle);
	printf("cos : %lf sin : %lf\n", cos(angle*(PI / 180))* m_iSpeed, sin(angle*(PI / 180))* m_iSpeed);

	m_iX -= cos(angle*(PI/180)) * m_iSpeed;
	m_iY -= sin(angle*(PI / 180)) * m_iSpeed;
//	printf("m_iX : %d m_iY : %d\n", m_iX, m_iY);
	/*
	if (m_iX != pt.x || m_iY != pt.y)
	{
		if (m_iX < pt.x)
		{
			m_iX += m_iSpeed;
		}
		else if (m_iX > pt.x)
		{
			m_iX -= m_iSpeed;
		}

		if (m_iY < pt.y)
		{
			m_iY += m_iSpeed;
		}
		else if (m_iY>pt.y)
		{
			m_iY -= m_iSpeed;
		}
	}

	*/
	
}

double CPlayer::GetAngle(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	double radian = atan2(dy, dx);

	double degree = (radian * 180) / 3.1415926535;

	return (degree + 180);
}
