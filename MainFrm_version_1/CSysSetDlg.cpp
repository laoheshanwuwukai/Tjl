// CSysSetDlg.cpp: 实现文件
//

#include "pch.h"
#include "MainFrm.h"
#include "CSysSetDlg.h"
#include "afxdialogex.h"


// CSysSetDlg 对话框

IMPLEMENT_DYNAMIC(CSysSetDlg, CDialog)

CSysSetDlg::CSysSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SYSSET_DIALOG, pParent)
{

}

CSysSetDlg::~CSysSetDlg()
{
}

void CSysSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSysSetDlg, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSysSetDlg 消息处理程序

BOOL CSysSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetClientRect(&m_Syssetrect);
	Old.x = m_Syssetrect.right - m_Syssetrect.left;
	Old.y = m_Syssetrect.bottom - m_Syssetrect.top;






	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CSysSetDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (nType != SIZE_MINIMIZED)	//判断窗口是不是最小化了，因为窗口最小化之后，窗口的长和宽会变为0，这样造成除以0的错误
	{
		Resize();
	}
	// TODO: 在此处添加消息处理程序代码
}

void CSysSetDlg::Resize(void)
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


