#pragma once
#include "Value.h"
class CCellBase
{
public:
	CCellBase();
	virtual ~CCellBase();
	
protected :
	int m_iX;
	int m_iY;
	int m_iR;

protected:
	int R, G, B;
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

public :
	virtual void OnFrameMove(const float c_fElaspedTime) = 0;
	virtual void OnFrameRender(HDC hdc) = 0;
	
public :
	inline int GetX(void)
	{
		return m_iX;
	}

	inline int GetY(void)
	{
		return m_iY;
	}

	inline int GetR(void)
	{
		return m_iR;
	}

	inline void SetX(int x)
	{
		m_iX = x;
	}

	inline void SetY(int y)
	{
		m_iY = y;
	}

	inline void SetR(int r)
	{
		m_iR = r;
	}
};

