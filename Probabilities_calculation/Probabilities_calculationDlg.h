
// Probabilities_calculationDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CProbabilities_calculationDlg
class CProbabilities_calculationDlg : public CDialogEx
{
// Создание
public:
	CProbabilities_calculationDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_PROBABILITIES_CALCULATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int member_rating_type;
	int member_expectation_value_type;
	CEdit member_edit_rating_enter;
	CEdit member_edit_rating_1;
	CEdit member_edit_rating_2;
	CEdit member_edit_points_number;
	CEdit member_edit_parties_number;
	CEdit member_edit_accuracy_percent;
	CEdit member_edit_win_1_per_cent;
	CEdit member_edit_win_2_per_cent;
	CEdit member_edit_draw_per_cent;
	CEdit member_edit_points_1_per_cent;
	CEdit member_edit_points_2_per_cent;
	CEdit member_edit_win_1_number;
	CEdit member_edit_win_2_number;
	CEdit member_edit_draw_number;
	CEdit member_edit_party_result;
	CEdit member_edit_factor;
	CEdit member_edit_rating_1_new;
	CEdit member_edit_rating_2_new;
	CEdit member_edit_player_2_rating_performance;
	CButton member_button_expectation_value;
	CButton member_button_expectation_value_1;
	CButton member_button_rating;
	CButton member_button_rating_1;
	CButton member_button_rating_2;
	CButton member_calculate_initial_rating_2;

	CEdit member_edit_k;

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedRadioRating200();
	afx_msg void OnBnClickedRadioRating1200();
	afx_msg void OnBnClickedRadioRatingEnter();
	afx_msg void OnBnClickedRadioFide();
	afx_msg void OnBnClickedRadioAlternative();
	afx_msg void OnBnClickedCheckCalculateInitialRatingOfPlayer2();
	CStatic member_static_information;
};
