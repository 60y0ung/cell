#pragma once
#include "Value.h"
#include "Pray.h"
#include "Player.h"


class CGameMgr
{
public:
	CGameMgr(void);
	~CGameMgr(void);

public :
	void Init( void );
	void Move( void );
	void Draw( void );
	void Destroy( void );

private:
	void RenderAngle(HDC hdc);


protected :
	DWORD dwTime;
	DWORD dwCount;
	HDC hdc, backDC;
	HBITMAP backBit, OldBit;

	list<CPray*> m_pPray;

	CPlayer* m_pPlayer;
};
