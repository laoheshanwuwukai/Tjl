#pragma once


// CCalibration 对话框

class CCalibration : public CDialog
{
	DECLARE_DYNAMIC(CCalibration)

public:
	CCalibration(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCalibration();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALIBRATION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	POINT Old;
	CRect m_Calibrationrect;


public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void ReSize(void);
};
