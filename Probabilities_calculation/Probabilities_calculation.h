
// Probabilities_calculation.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CProbabilities_calculationApp:
// � ���������� ������� ������ ��. Probabilities_calculation.cpp
//

class CProbabilities_calculationApp : public CWinApp
{
public:
	CProbabilities_calculationApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CProbabilities_calculationApp theApp;