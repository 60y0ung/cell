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

	inline void SetR(int r)
	{
		m_iR += r;
	}

protected :
	int m_iSpeed;

protected :
	void Arrive(void);
	double GetAngle(int x1, int y1, int x2, int y2);

};
