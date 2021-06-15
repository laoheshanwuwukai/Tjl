// CAmend.cpp: 实现文件
//

#include "pch.h"
#include "MainFrm.h"
#include "CAmend.h"
#include "afxdialogex.h"


// CAmend 对话框

IMPLEMENT_DYNAMIC(CAmend, CDialogEx)

CAmend::CAmend(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Amend_DIALOG, pParent)
{

}

CAmend::~CAmend()
{
}

void CAmend::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAmend, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CAmend 消息处理程序

BOOL CAmend::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetClientRect(&m_Amend);
	Old.x = m_Amend.right - m_Amend.left;
	Old.y = m_Amend.bottom - m_Amend.top;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CAmend::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	Resize();
	// TODO: 在此处添加消息处理程序代码
}


void CAmend::Resize(void)
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



