#include "GameMgr.h"


CGameMgr::CGameMgr(void)
{
	dwTime = GetTickCount();
	dwCount = 1000;

	m_pPlayer = new CPlayer();
}


CGameMgr::~CGameMgr(void)
{

}

void CGameMgr::Init( void )
{
	
}

void CGameMgr::Move( void )
{
	
}


void CGameMgr::Draw(void)
{
	HDC hdc = GetDC(hWnd);
	if (dwTime + dwCount < GetTickCount())
	{
		dwTime = GetTickCount();

		for (int i = 0; i < 30; i++)
		{
			CPray* pPray = new CPray();
			m_pPray.push_back(pPray);
		}
	}

	list<CPray*>::iterator iter;
	for (iter = m_pPray.begin(); iter != m_pPray.end(); iter++)
	{
		(*iter)->OnFrameRender(hdc);
	}

	m_pPlayer->OnFrameRender(hdc);

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
