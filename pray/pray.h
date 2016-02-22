#pragma once
#include "CellBase.h"
#include "Value.h"

class CPray : public CCellBase
{
public:
	CPray();
	~CPray();

public:
	void OnFrameMove(const float c_fElapsedTime);
	void OnFrameRender(HDC hdc);

};

