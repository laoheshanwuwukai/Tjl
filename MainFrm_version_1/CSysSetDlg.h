#pragma once


// CSysSetDlg 对话框

class CSysSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CSysSetDlg)

public:
	CSysSetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSysSetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYSSET_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	POINT Old;
	CRect m_Syssetrect;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void Resize(void);
	
};
