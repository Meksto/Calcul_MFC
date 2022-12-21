
// CalculDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCalculDlg
class CCalculDlg : public CDialogEx
{
// Создание
public:
	CCalculDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCUL_DIALOG };
#endif

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


	float value1;
	float value2;

	char znak;
public:
	afx_msg void OnClicked1();
	// Временная корзиночка для переменной
	CString EDIT_TEMP_FIELD;
	afx_msg void OnClicked2();
	afx_msg void OnClicked3();
	afx_msg void OnClicked4();
	afx_msg void OnClicked5();
	afx_msg void OnClicked6();
	afx_msg void OnClicked7();
	afx_msg void OnClicked8();
	afx_msg void OnClicked9();
	afx_msg void OnClicked10();
	afx_msg void OnClickedPlus();
	afx_msg void OnClickedMinus();
	afx_msg void OnClickedResult();
};
