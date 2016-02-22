#pragma once
#include "CellBase.h"
#include "Value.h"

class CPlayer : public CCellBase
{
public:
	CPlayer();
	~CPlayer();

public:
	void OnFrameMove(const float c_fElaspedTime);
	void OnFrameRender(HDC hdc);

protected :
	int m_iSpeed;
};
