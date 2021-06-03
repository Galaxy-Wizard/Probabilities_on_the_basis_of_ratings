
// Probabilities_calculation.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CProbabilities_calculationApp:
// О реализации данного класса см. Probabilities_calculation.cpp
//

class CProbabilities_calculationApp : public CWinApp
{
public:
	CProbabilities_calculationApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CProbabilities_calculationApp theApp;