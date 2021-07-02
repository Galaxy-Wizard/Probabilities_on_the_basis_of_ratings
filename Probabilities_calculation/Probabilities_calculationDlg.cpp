
// Probabilities_calculationDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Probabilities_calculation.h"
#include "Probabilities_calculationDlg.h"
#include "afxdialogex.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CProbabilities_calculationDlg



CProbabilities_calculationDlg::CProbabilities_calculationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProbabilities_calculationDlg::IDD, pParent)
	, member_rating_type(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProbabilities_calculationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_FIDE, member_expectation_value_type);
	DDX_Radio(pDX, IDC_RADIO_RATING_200, member_rating_type);
	DDX_Control(pDX, IDC_EDIT_RATING_ENTER, member_edit_rating_enter);
	DDX_Control(pDX, IDC_EDIT_PLAYER_1_RATING, member_edit_rating_1);
	DDX_Control(pDX, IDC_EDIT_PLAYER_2_RATING, member_edit_rating_2);
	DDX_Control(pDX, IDC_EDIT_POINTS_NUMBER, member_edit_points_number);
	DDX_Control(pDX, IDC_EDIT_PARTIES_NUMBER, member_edit_parties_number);
	DDX_Control(pDX, IDC_EDIT_ACCURACY_PER_CENT, member_edit_accuracy_percent);
	DDX_Control(pDX, IDC_EDIT_PLAYER_1_WIN_PER_CENT, member_edit_win_1_per_cent);
	DDX_Control(pDX, IDC_EDIT_PLAYER_2_WIN_PER_CENT, member_edit_win_2_per_cent);
	DDX_Control(pDX, IDC_EDIT_DRAW_PER_CENT, member_edit_draw_per_cent);
	DDX_Control(pDX, IDC_EDIT_PLAYER_1_WIN_NUMBER, member_edit_win_1_number);
	DDX_Control(pDX, IDC_EDIT_PLAYER_2_WIN_NUMBER, member_edit_win_2_number);
	DDX_Control(pDX, IDC_EDIT_DRAW_NUMBER, member_edit_draw_number);
	DDX_Control(pDX, IDC_EDIT_PLAYER_1_POINTS_PER_CENT, member_edit_points_1_per_cent);
	DDX_Control(pDX, IDC_EDIT_PLAYER_2_POINTS_PER_CENT, member_edit_points_2_per_cent);
	DDX_Control(pDX, IDC_EDIT_PARTY_RESULT, member_edit_party_result);
	DDX_Control(pDX, IDC_EDIT_FACTOR, member_edit_factor);
	DDX_Control(pDX, IDC_EDIT_PLAYER_1_RATING_NEW, member_edit_rating_1_new);
	DDX_Control(pDX, IDC_EDIT_PLAYER_2_RATING_NEW, member_edit_rating_2_new);
	DDX_Control(pDX, IDC_EDIT_PLAYER_2_RATING_RATING_PERFORMANCE, member_edit_player_2_rating_performance);
	DDX_Control(pDX, IDC_RADIO_FIDE, member_button_expectation_value);
	DDX_Control(pDX, IDC_RADIO_ALTERNATIVE, member_button_expectation_value_1);
	DDX_Control(pDX, IDC_RADIO_RATING_200, member_button_rating);
	DDX_Control(pDX, IDC_RADIO_RATING_1200, member_button_rating_1);
	DDX_Control(pDX, IDC_RADIO_RATING_ENTER, member_button_rating_2);
	DDX_Control(pDX, IDC_CHECK_CALCULATE_INITIAL_RATING_OF_PLAYER_2, member_calculate_initial_rating_2);
	DDX_Control(pDX, IDC_STATIC_INFORMATION, member_static_information);
}

BEGIN_MESSAGE_MAP(CProbabilities_calculationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CProbabilities_calculationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CProbabilities_calculationDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_RADIO_RATING_200, &CProbabilities_calculationDlg::OnBnClickedRadioRating200)
	ON_BN_CLICKED(IDC_RADIO_RATING_1200, &CProbabilities_calculationDlg::OnBnClickedRadioRating1200)
	ON_BN_CLICKED(IDC_RADIO_RATING_ENTER, &CProbabilities_calculationDlg::OnBnClickedRadioRatingEnter)
	ON_BN_CLICKED(IDC_RADIO_FIDE, &CProbabilities_calculationDlg::OnBnClickedRadioFide)
	ON_BN_CLICKED(IDC_RADIO_ALTERNATIVE, &CProbabilities_calculationDlg::OnBnClickedRadioAlternative)
	ON_BN_CLICKED(IDC_CHECK_CALCULATE_INITIAL_RATING_OF_PLAYER_2, &CProbabilities_calculationDlg::OnBnClickedCheckCalculateInitialRatingOfPlayer2)
END_MESSAGE_MAP()


// обработчики сообщений CProbabilities_calculationDlg

BOOL CProbabilities_calculationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	member_expectation_value_type = 0;

	member_button_expectation_value.EnableWindow(TRUE);
	member_button_expectation_value_1.EnableWindow(TRUE);

	member_rating_type = 0;

	member_button_rating.EnableWindow(FALSE);
	member_button_rating_1.EnableWindow(FALSE);
	member_button_rating_2.EnableWindow(FALSE);

	member_edit_rating_enter.EnableWindow(FALSE);
	member_edit_rating_enter.SetWindowTextW(CString(L"300.0"));

	member_static_information.SetWindowTextW(CString(L"1) При рассчёте начального рейтинга:\r\nМножитель равен интервалу достоверности делённому на количество партий.\r\n\r\n2) При рассчёте приращений рейтингов:\r\nМножитель равен интервалу достоверности делённому на количество ходов в партии.\r\n\r\nИнтервалом достоверности называется сила Ладьи в пунктах рейтинга Байеса (1200 пунктов)."));

	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CProbabilities_calculationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CProbabilities_calculationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CProbabilities_calculationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProbabilities_calculationDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CProbabilities_calculationDlg::OnBnClickedButtonCalculate()
{
	UpdateData(TRUE);


	member_edit_win_1_per_cent.SetWindowTextW(CString());
	member_edit_win_2_per_cent.SetWindowTextW(CString());
	member_edit_draw_per_cent.SetWindowTextW(CString());
	member_edit_win_1_number.SetWindowTextW(CString());
	member_edit_win_2_number.SetWindowTextW(CString());
	member_edit_draw_number.SetWindowTextW(CString());
	member_edit_points_1_per_cent.SetWindowTextW(CString());
	member_edit_points_2_per_cent.SetWindowTextW(CString());


	int member_edit_rating_1_text_length = member_edit_rating_1.GetWindowTextLengthW();
	int member_edit_rating_2_text_length = member_edit_rating_2.GetWindowTextLengthW();
	int member_edit_points_number_length = member_edit_points_number.GetWindowTextLengthW();
	int member_edit_parties_number_text_length = member_edit_parties_number.GetWindowTextLengthW();
	int member_edit_accuracy_percent_text_length = member_edit_accuracy_percent.GetWindowTextLengthW();
	int member_edit_party_result_text_length = member_edit_party_result.GetWindowTextLengthW();
	int member_edit_factor_text_length = member_edit_factor.GetWindowTextLengthW();
	int member_edit_rating_enter_length = member_edit_rating_enter.GetWindowTextLengthW();
	BOOL member_edit_rating_enter_is_enabled = member_edit_rating_enter.IsWindowEnabled();
	BOOL member_calculate_initial_rating_2_is_enabled = member_calculate_initial_rating_2.IsWindowEnabled();
	int member_calculate_initial_rating_2_is_checked = member_calculate_initial_rating_2.GetCheck();

	if
		(
			member_edit_rating_1_text_length==0
			||
			(
				member_edit_rating_2_text_length==0
				&&
				(
					member_calculate_initial_rating_2_is_enabled==FALSE
					||
					(
						member_calculate_initial_rating_2_is_enabled==TRUE
						&&
						member_calculate_initial_rating_2_is_checked==0
					)
				)
			)
			||
			(
				(
					member_calculate_initial_rating_2_is_enabled==TRUE
					&&
					member_calculate_initial_rating_2_is_checked>0
				)
				&&
				member_edit_factor_text_length==0
			)
			||
			member_edit_parties_number_text_length==0
			||
			(
				member_edit_accuracy_percent_text_length==0
				&&
				(
					member_calculate_initial_rating_2_is_enabled==FALSE
					||
					(
						member_calculate_initial_rating_2_is_enabled==TRUE
						&&
						member_calculate_initial_rating_2_is_checked==0
					)
				)
				&&
				member_expectation_value_type!=0
			)
			||
			(
				member_edit_rating_enter_length==0
				&&
				member_edit_rating_enter_is_enabled==TRUE
			)
		)
	{
		MessageBoxW(CString(L"Введите все входные параметры."));
		return;
	}

	if
	(
		member_calculate_initial_rating_2_is_enabled==TRUE
		&&
		member_calculate_initial_rating_2_is_checked>0
		&&
		member_edit_points_number_length!=0
		&&
		member_edit_factor_text_length!=0
	)
	{
		double local_rating_a = 0;
		double local_rating_c = 0;
		double local_expectation = 0;

		CString local_rating_1_string;

		member_edit_rating_1.GetWindowTextW(local_rating_1_string);

		local_rating_c = _wtof(local_rating_1_string);


		double local_points_number = 1;

		CString local_points_number_string;

		member_edit_points_number.GetWindowTextW(local_points_number_string);
		local_points_number = _wtof(local_points_number_string);


		double local_parties_number = 12;

		CString local_parties_number_string;

		member_edit_parties_number.GetWindowTextW(local_parties_number_string);
		local_parties_number = _wtof(local_parties_number_string);

		CString local_factor_string;

		member_edit_factor.GetWindowTextW(local_factor_string);

		double local_factor = _wtof(local_factor_string);


		local_expectation = local_points_number/local_parties_number;

		double local_performance = local_rating_c + (800.0* local_expectation - 400.0);

		local_rating_a = local_rating_c + local_factor*(local_points_number-local_parties_number*0.5);

		CString local_rating_a_string;

		local_rating_a_string.Format(L"%.4f",local_rating_a);

		member_edit_rating_2_new.SetWindowTextW(local_rating_a_string);

		CString local_rating_performance_string;

		local_rating_performance_string.Format(L"%.4f",local_performance);

		member_edit_player_2_rating_performance.SetWindowTextW(local_rating_performance_string);


		double local_points_per_cent_2 = local_expectation*100;
		double local_points_per_cent_1 = 100.0 - local_points_per_cent_2;

		CString local_points_per_cent_2_string;

		local_points_per_cent_2_string.Format(L"%.4f",local_points_per_cent_2);

		member_edit_points_2_per_cent.SetWindowTextW(local_points_per_cent_2_string);

		CString local_points_per_cent_1_string;

		local_points_per_cent_1_string.Format(L"%.4f",local_points_per_cent_1);

		member_edit_points_1_per_cent.SetWindowTextW(local_points_per_cent_1_string);

		return;
	}

	double local_rating_1 = 0.0;
	double local_rating_2 = 0.0;

	double local_result_1 = 0.0;
	double local_result_2 = 0.0;
	double local_result_0 = 0.0;

	int local_expectation_value_flag = 0;

	switch(member_expectation_value_type)
	{
	default:
	case 0:
		local_expectation_value_flag = 0;
		break;
	case 1:
		local_expectation_value_flag = 1;
		break;
	}

	int local_rating_flag = 0;

	switch(member_rating_type)
	{
	case 0:
		local_rating_flag = 0;
		break;
	case 1:
		local_rating_flag = 1;
		break;
	default:
	case 2:
		local_rating_flag = 2;
		break;
	}

	CString local_rating_1_string;
	CString local_rating_2_string;

	member_edit_rating_1.GetWindowTextW(local_rating_1_string);
	member_edit_rating_2.GetWindowTextW(local_rating_2_string);

	local_rating_1 = _wtof(local_rating_1_string);
	local_rating_2 = _wtof(local_rating_2_string);

	const double local_100 = 100.0;

	double local_parties_number = 12;

	CString local_parties_number_string;

	member_edit_parties_number.GetWindowTextW(local_parties_number_string);
	local_parties_number = _wtof(local_parties_number_string);
	
	double local_accuracy_per_cent = 1.0;

	CString local_accuracy_per_cent_string;

	member_edit_accuracy_percent.GetWindowTextW(local_accuracy_per_cent_string);
	local_accuracy_per_cent = _wtof(local_accuracy_per_cent_string);



	
	const double local_1200 = 1200.0;
	const double local_200 = 200.0;

	double local_border = local_1200;
	double local_border_1200 = local_1200;

	double local_border_enter = local_200;
	
	CString local_border_enter_string;
	
	member_edit_rating_enter.GetWindowTextW(local_border_enter_string);
	local_border_enter = _wtof(local_border_enter_string);


	if
		(
		local_rating_1<0.0
		||
		local_rating_2<0.0
		||
		local_parties_number<0
		||
		local_accuracy_per_cent<0.0
		||
		local_accuracy_per_cent>100.0
		||
		local_border_enter<0.0
		||
		(
		local_accuracy_per_cent==0.0
		&&
		local_expectation_value_flag!=0
		)
		)
	{
		MessageBoxW(CString(L"Введите все входные параметры правильно."));
		return;
	}


	double local_percent_1 = 0.0;
	double local_percent_2 = 0.0;
	double local_percent_0 = 0.0;


	switch(local_expectation_value_flag)
	{
		default:
		case 0:

			{

			CString local_factor_string;
			member_edit_factor.GetWindowTextW(local_factor_string);
			double local_factor = _wtof(local_factor_string);

	
			double local_q_1 = exp(((local_rating_1 - local_rating_2) / 400.0) * log(10.0));
			double local_q_2 = exp(((local_rating_2 - local_rating_1) / 400.0) * log(10.0));
			double local_q_0 = exp(((1 / (local_rating_1 + local_rating_2))) * log(10.0)) * 2;

			double local_percent_10 = local_q_1/(local_q_1+local_q_2+local_q_0);

			double local_percent_20 = local_q_2/(local_q_1+local_q_2+local_q_0);

			double local_percent_00 = local_q_0/(local_q_1+local_q_2+local_q_0);


			local_percent_0 = 100.0*local_percent_00;
			local_percent_1 = 100.0*local_percent_10;
			local_percent_2 = 100.0*local_percent_20;
			}

			break;


		case 1:

			{
			switch(local_rating_flag)
			{
				case 0:
				local_border = local_200;
				break;
				case 1:
				local_border = local_1200;
				break;
				default:
				case 2:
				local_border = local_border_enter;
				break;
			}

			const double local_delta_1 = local_accuracy_per_cent/local_100;
			const double local_delta_2 = local_accuracy_per_cent/local_100;

			for(double local_counter_1=0;local_counter_1<=2;local_counter_1+=local_delta_1)
			{
				for(double local_counter_2=0;local_counter_2<=2;local_counter_2+=local_delta_2)
				{
					double local_number_1 = local_rating_1+local_counter_1*local_border;
					double local_number_2 = local_rating_2+local_counter_2*local_border;
					if(local_number_1-local_number_2>local_border)
					{
						local_result_1 += 1;
					}
					if(local_number_2-local_number_1>local_border)
					{
						local_result_2 += 1;
					}
					if(
						(local_number_2-local_number_1)<=local_border
						&&
						(local_number_1-local_number_2)<=local_border
						)
					{
						local_result_0 += 1;
					}
				}
			}

			local_percent_1 = local_result_1/(2/local_delta_1+1)/(2/local_delta_2+1)*local_100;
			local_percent_2 = local_result_2/(2/local_delta_1+1)/(2/local_delta_2+1)*local_100;
			local_percent_0 = local_result_0/(2/local_delta_1+1)/(2/local_delta_2+1)*local_100;
			}

			break;
	}

		
	CString local_percent_1_string;
	CString local_percent_2_string;
	CString local_percent_0_string;

	local_percent_1_string.Format(L"%.4f",local_percent_1);
	local_percent_2_string.Format(L"%.4f",local_percent_2);
	local_percent_0_string.Format(L"%.4f",local_percent_0);

	member_edit_win_1_per_cent.SetWindowTextW(local_percent_1_string);
	member_edit_win_2_per_cent.SetWindowTextW(local_percent_2_string);
	member_edit_draw_per_cent.SetWindowTextW(local_percent_0_string);


	CString local_number_1_string;
	CString local_number_2_string;
	CString local_number_0_string;

	local_number_1_string.Format(L"%d",int(local_percent_1*local_parties_number/local_100+0.5));
	local_number_2_string.Format(L"%d",int(local_percent_2*local_parties_number/local_100+0.5));
	local_number_0_string.Format(L"%d",int(local_percent_0*local_parties_number/local_100+0.5));

	member_edit_win_1_number.SetWindowTextW(local_number_1_string);
	member_edit_win_2_number.SetWindowTextW(local_number_2_string);
	member_edit_draw_number.SetWindowTextW(local_number_0_string);


	CString local_points_1_per_cent_string;
	CString local_points_2_per_cent_string;

	local_points_1_per_cent_string.Format(L"%.4f",local_percent_1 + local_percent_0/2.0);
	local_points_2_per_cent_string.Format(L"%.4f",local_percent_2 + local_percent_0/2.0);

	member_edit_points_1_per_cent.SetWindowTextW(local_points_1_per_cent_string);
	member_edit_points_2_per_cent.SetWindowTextW(local_points_2_per_cent_string);

	if
		(
		member_edit_party_result_text_length==0
		||
		member_edit_factor_text_length==0
		)
	{
		MessageBoxW(CString(L"Введите все входные параметры для расчёта нового рейтинга."));
		return;
	}

	CString local_party_result_string;

	member_edit_party_result.GetWindowTextW(local_party_result_string);

	double local_party_result = _wtof(local_party_result_string);

	CString local_factor_string;

	member_edit_factor.GetWindowTextW(local_factor_string);

	double local_factor = _wtof(local_factor_string);

	CString local_rating_1_new_string;
	CString local_rating_2_new_string;

	double bayes_add = local_1200 / local_factor;

	double local_rating_1_new = local_rating_1 + bayes_add + local_factor*(local_party_result-(local_percent_1 + local_percent_0/2.0)/100.0);
	double local_rating_2_new = local_rating_2 - bayes_add + local_factor*((1-local_party_result)-(local_percent_2 + local_percent_0/2.0)/100.0);

	local_rating_1_new_string.Format(L"%.2f",local_rating_1_new);
	local_rating_2_new_string.Format(L"%.2f",local_rating_2_new);

	member_edit_rating_1_new.SetWindowTextW(local_rating_1_new_string);
	member_edit_rating_2_new.SetWindowTextW(local_rating_2_new_string);
}


void CProbabilities_calculationDlg::OnBnClickedRadioRating200()
{
	member_edit_rating_enter.EnableWindow(FALSE);
}


void CProbabilities_calculationDlg::OnBnClickedRadioRating1200()
{
	member_edit_rating_enter.EnableWindow(FALSE);
}


void CProbabilities_calculationDlg::OnBnClickedRadioRatingEnter()
{
	member_edit_rating_enter.EnableWindow(TRUE);
}


void CProbabilities_calculationDlg::OnBnClickedRadioFide()
{
	UpdateData(TRUE);

	member_button_rating.EnableWindow(FALSE);
	member_button_rating_1.EnableWindow(FALSE);
	member_button_rating_2.EnableWindow(FALSE);
	member_calculate_initial_rating_2.EnableWindow(TRUE);

	if
		(
		member_rating_type==2
		)
	{
		member_edit_rating_enter.EnableWindow(FALSE);
	}
}


void CProbabilities_calculationDlg::OnBnClickedRadioAlternative()
{
	UpdateData(TRUE);

	member_button_rating.EnableWindow(TRUE);
	member_button_rating_1.EnableWindow(TRUE);
	member_button_rating_2.EnableWindow(TRUE);
	member_calculate_initial_rating_2.EnableWindow(FALSE);
	
	if
		(
		member_rating_type==2
		)
	{
		member_edit_rating_enter.EnableWindow(TRUE);
	}
}


void CProbabilities_calculationDlg::OnBnClickedCheckCalculateInitialRatingOfPlayer2()
{
	// TODO: добавьте свой код обработчика уведомлений
}
