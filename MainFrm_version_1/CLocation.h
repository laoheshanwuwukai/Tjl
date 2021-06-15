#pragma once


// CLocation 对话框

class CLocation : public CDialog
{
	DECLARE_DYNAMIC(CLocation)

public:
	CLocation(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLocation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOCATION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()



private:
	POINT Old;
	CRect m_Location;

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void ReSize(void);
};
