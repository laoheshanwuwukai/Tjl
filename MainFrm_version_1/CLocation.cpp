// CLocation.cpp: 实现文件
//

#include "pch.h"
#include "MainFrm.h"
#include "CLocation.h"
#include "afxdialogex.h"


// CLocation 对话框

IMPLEMENT_DYNAMIC(CLocation, CDialog)

CLocation::CLocation(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LOCATION_DIALOG, pParent)
{

}

CLocation::~CLocation()
{
}

void CLocation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLocation, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CLocation 消息处理程序

BOOL CLocation::OnInitDialog()
{
	CDialog::OnInitDialog();

	GetClientRect(&m_Location);
	Old.x = m_Location.right - m_Location.left;
	Old.y = m_Location.bottom - m_Location.top;


	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CLocation::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	ReSize();
	// TODO: 在此处添加消息处理程序代码
}

void CLocation::ReSize(void)
{
	float fsp[2];
	POINT NewP;		//获取现在对话框的大小
	CRect new_rect;
	GetClientRect(&new_rect);
	NewP.x = new_rect.right - new_rect.left;
	NewP.y = new_rect.bottom - new_rect.top;

	fsp[0] = (float)NewP.x / Old.x;
	fsp[1] = (float)NewP.y / Old.y;

	CRect m_Rect;
	int woc;
	CPoint OldTLPoint, TLPoint;//左上角
	CPoint OldBRPoint, BRPoint;//右下角

	HWND hWndChild = ::GetWindow(m_hWnd, GW_CHILD);	//列出所有控件
	while (hWndChild)
	{
		woc = ::GetDlgCtrlID(hWndChild);	//取得ID
		GetDlgItem(woc)->GetWindowRect(m_Rect);
		ScreenToClient(m_Rect);

		OldTLPoint = m_Rect.TopLeft();
		TLPoint.x = (long)(OldTLPoint.x * fsp[0]);
		TLPoint.y = (long)(OldTLPoint.y * fsp[1]);

		OldBRPoint = m_Rect.BottomRight();
		BRPoint.x = (long)(OldBRPoint.x * fsp[0]);
		BRPoint.y = (long)(OldBRPoint.y * fsp[1]);

		m_Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(m_Rect, TRUE);
		hWndChild = ::GetWindow(hWndChild, GW_HWNDNEXT);
	}
	Old = NewP;
}
