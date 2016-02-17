#pragma once
#include "Value.h"


class CGameMgr
{
public:
	CGameMgr(void);
	~CGameMgr(void);

public :
	void Init( void );
	void Move( void );
	void Draw( bool on );
	void Destroy( void );

private :
	void MakeCircle(int x, int y, HDC hdc);

};

