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


protected :
	DWORD dwTime;
	DWORD dwCount;

	list<CPray*> m_pPray;

	CPlayer* m_pPlayer;

};

