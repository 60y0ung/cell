#include "GameMgr.h"


CGameMgr::CGameMgr(void)
{
	dwTime = GetTickCount();
	dwCount = 10000;

	m_pPlayer = new CPlayer();
	
}


CGameMgr::~CGameMgr(void)
{
	SelectObject(backDC, OldBit);
	DeleteObject(backBit);

	ReleaseDC(hWnd, backDC);
	DeleteDC(backDC);

}

void CGameMgr::Init( void )
{

}

void CGameMgr::Move( void )
{
	m_pPlayer->OnFrameMove(0.1f);


	list<CPray*>::iterator iter;
	for (iter = m_pPray.begin(); iter != m_pPray.end();)
	{
		if (sqrt(((*iter)->GetX() - m_pPlayer->GetX())*((*iter)->GetX() - m_pPlayer->GetX()) + ((*iter)->GetY() - m_pPlayer->GetY())*((*iter)->GetY() - m_pPlayer->GetY())) < m_pPlayer->GetR() / 2)
		{
			delete (*iter);
			(*iter) = NULL;

			iter = m_pPray.erase(iter);

			m_pPlayer->SetR(2);
		}
		else
			iter++;
	}
}


void CGameMgr::Draw(void)
{

	hdc = GetDC(hWnd);

	backDC = CreateCompatibleDC(hdc);
	backBit = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	OldBit = (HBITMAP)SelectObject(backDC, backBit);

	BitBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, NULL, NULL, NULL, WHITENESS);
	if (dwTime + dwCount < GetTickCount())
	{
		dwTime = GetTickCount();

		for (int i = 0; i < 20; i++)
		{
			CPray* pPray = new CPray();
			m_pPray.push_back(pPray);
		}
	}
	
	list<CPray*>::iterator iter;
	for (iter = m_pPray.begin(); iter != m_pPray.end(); iter++)
	{
		(*iter)->OnFrameRender(backDC);
		
	}

	m_pPlayer->OnFrameRender(backDC);
	RenderAngle(backDC);
	BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, backDC, 0, 0, SRCCOPY);

	ReleaseDC(hWnd, hdc);
	
}

void CGameMgr::Destroy( void )
{
	if (m_pPlayer != NULL)
	{
		m_pPlayer = NULL;
		delete m_pPlayer;
	}

	list<CPray*>::iterator iter;
	for (iter = m_pPray.begin(); iter != m_pPray.end(); iter++)
	{
		(*iter) = NULL;
		delete (*iter);
	}
}

void CGameMgr::RenderAngle(HDC hdc)
{
	int x1 = WINSIZEX / 2;
	int y1 = WINSIZEY / 2;

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	float fDistance = sqrtf(pow(pt.x - x1, 2) + pow(pt.y - y1, 2));

	float fAngle;
	int nWidth = pt.x - x1;
	nWidth = nWidth < 0 ? -nWidth : nWidth;
	fAngle = acosf(nWidth/fDistance);
	if (pt.y > y1){
		fAngle = 2 * PI - fAngle;
		if (fAngle >= 2 * PI) fAngle -= 2 * PI;
	}
	fAngle = fAngle*PI / 180.0f;
	
}
