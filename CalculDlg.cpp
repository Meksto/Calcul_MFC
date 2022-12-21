
// CalculDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Calcul.h"
#include "CalculDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CCalculDlg



CCalculDlg::CCalculDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCUL_DIALOG, pParent)
	, EDIT_TEMP_FIELD(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	value1 = 0.0f;
	value2 = 0.0f;
	znak = '/0';
}

void CCalculDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, EDIT_TEMP_FIELD);
}

BEGIN_MESSAGE_MAP(CCalculDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCalculDlg::OnClicked1)
	ON_BN_CLICKED(IDC_2, &CCalculDlg::OnClicked2)
	ON_BN_CLICKED(IDC_2, &CCalculDlg::OnClicked2)
	ON_BN_CLICKED(IDC_3, &CCalculDlg::OnClicked3)
	ON_BN_CLICKED(IDC_4, &CCalculDlg::OnClicked4)
	ON_BN_CLICKED(IDC_5, &CCalculDlg::OnClicked5)
	ON_BN_CLICKED(IDC_6, &CCalculDlg::OnClicked6)
	ON_BN_CLICKED(IDC_7, &CCalculDlg::OnClicked7)
	ON_BN_CLICKED(IDC_8, &CCalculDlg::OnClicked8)
	ON_BN_CLICKED(IDC_9, &CCalculDlg::OnClicked9)
	ON_BN_CLICKED(IDC_10, &CCalculDlg::OnClicked10)
	ON_BN_CLICKED(IDC_PLUS, &CCalculDlg::OnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CCalculDlg::OnClickedMinus)
	ON_BN_CLICKED(IDC_RESULT, &CCalculDlg::OnClickedResult)
END_MESSAGE_MAP()


// Обработчики сообщений CCalculDlg

BOOL CCalculDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalculDlg::OnPaint()
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
HCURSOR CCalculDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculDlg::OnClicked1()
{
	// TODO: добавьте свой код обработчика уведомлений
	
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("1");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("1");
	}

	UpdateData(FALSE);
}




void CCalculDlg::OnClicked2()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("2");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("2");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked3()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("3");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("3");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked4()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("4");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("4");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked5()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("5");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("5");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked6()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("6");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("6");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked7()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("7");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("7");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked8()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("8");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("8");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked9()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("9");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("9");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClicked10()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (EDIT_TEMP_FIELD != "None")
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("0");

	}
	else
	{
		UpdateData(TRUE);
		EDIT_TEMP_FIELD.Empty();
		EDIT_TEMP_FIELD = EDIT_TEMP_FIELD + _T("0");
	}

	UpdateData(FALSE);
}


void CCalculDlg::OnClickedPlus()
{
	// TODO: добавьте свой код обработчика уведомлений
	value1 = atof(_bstr_t((LPCTSTR)EDIT_TEMP_FIELD));
	znak = '+';
	UpdateData(TRUE);
	EDIT_TEMP_FIELD.Empty();
	UpdateData(FALSE);
}


void CCalculDlg::OnClickedMinus()
{
	// TODO: добавьте свой код обработчика уведомлений
	value1 = atof(_bstr_t((LPCTSTR)EDIT_TEMP_FIELD));
	znak = '-';
	UpdateData(TRUE);
	EDIT_TEMP_FIELD.Empty();
	UpdateData(FALSE);
}


void CCalculDlg::OnClickedResult()
{
	// TODO: добавьте свой код обработчика уведомлений
	switch (znak)
	{
	case '+':
		UpdateData(TRUE);
		value2 = atof(_bstr_t((LPCTSTR)EDIT_TEMP_FIELD));
		value1 += value2;
		EDIT_TEMP_FIELD.Format(_T("%.3f"), value1);
		UpdateData(FALSE);
		EDIT_TEMP_FIELD = "None";
		break;
	case '-':
		UpdateData(TRUE);
		value2 = atof(_bstr_t((LPCTSTR)EDIT_TEMP_FIELD));
		value1 -= value2;
		EDIT_TEMP_FIELD.Format(_T("%.3f"), value1);
		UpdateData(FALSE);
		EDIT_TEMP_FIELD = "None";
		break;
	default:
		break;
	}
}
