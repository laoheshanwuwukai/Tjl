#pragma once


// CAmend 对话框

class CAmend : public CDialogEx
{
	DECLARE_DYNAMIC(CAmend)

public:
	CAmend(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAmend();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Amend_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	POINT Old;
	CRect m_Amend;


public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void Resize(void);



};
