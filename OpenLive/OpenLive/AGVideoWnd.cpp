// AGVideoWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "OpenLive.h"
#include "AGVideoWnd.h"

IMPLEMENT_DYNAMIC(CAGInfoWnd, CWnd)

CAGInfoWnd::CAGInfoWnd()
: m_bShowTip(TRUE)
, m_bSpeakingTip(FALSE)
, m_nWidth(0)
, m_nHeight(0)
, m_nWinWidth(0)
, m_nWinHeight(0)
, m_nFps(0)
, m_nBitrate(0)
, m_nVolume(0)
, m_nUID(0)
{
	m_brBack.CreateSolidBrush(RGB(0x00, 0xA0, 0xE9));
	m_penRed.CreatePen(PS_SOLID, 8, RGB(255, 0, 0));
	m_penNormal.CreatePen(PS_SOLID, 8, RGB(0x00, 0xA0, 0xE9));

	m_fontTip.CreateFont(14, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
}

CAGInfoWnd::~CAGInfoWnd()
{
	m_brBack.DeleteObject();
	m_penRed.DeleteObject();
	m_penNormal.DeleteObject();

	m_fontTip.DeleteObject();
}


BEGIN_MESSAGE_MAP(CAGInfoWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CAGInfoWnd::ShowSpeakingTip(BOOL bShow, int nVolume)
{
	m_bSpeakingTip = bShow;
	m_nVolume = nVolume;

	Invalidate(FALSE);
}

void CAGInfoWnd::ShowTips(BOOL bShow)
{
	m_bShowTip = bShow;

	if (bShow)
		ShowWindow(SW_SHOW);
	else
		ShowWindow(SW_HIDE);

	Invalidate(FALSE);
}

void CAGInfoWnd::SetWindowInfo(int nWinWidth, int nWinHeight)
{
	m_nWinWidth = nWinWidth;
	m_nWinHeight = nWinHeight;

	if (m_bShowTip) {
		Invalidate(TRUE);
		UpdateWindow();
	}
}

void CAGInfoWnd::SetVideoResolution(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	if (m_bShowTip) {
		Invalidate(TRUE);
		UpdateWindow();
	}
}

void CAGInfoWnd::SetUID(UINT nUID)
{
	m_nUID = nUID;

	if (m_bShowTip) {
		Invalidate(TRUE);
		UpdateWindow();
	}
}
void CAGInfoWnd::SetFrameRateInfo(int nFPS)
{
	m_nFps = nFPS;

	if (m_bShowTip) {
		Invalidate(TRUE);
		UpdateWindow();
	}
}

void CAGInfoWnd::SetBitrateInfo(int nBitrate)
{
	m_nBitrate = nBitrate;

	if (m_bShowTip) {
		Invalidate(TRUE);
		UpdateWindow();
	}
}

void CAGInfoWnd::OnPaint()
{
	CPaintDC dc(this);
	CRect	rcClient;
	CString strTip;
	int		nHeight = 0;

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0xFF, 0xFF, 0xFF));

	CFont *lpDefFont = dc.SelectObject(&m_fontTip);

	if (m_bShowTip) {
		// 640x480/1024*768,15fps,400k
		GetClientRect(&rcClient);
		rcClient.top += 4;
		strTip.Format(_T("%dx%d(%dx%d)-%lu, %dfps, %dK"), m_nWidth, m_nHeight, m_nWinWidth, m_nWinHeight, m_nUID, m_nFps, m_nBitrate);
		dc.DrawText(strTip, &rcClient, DT_VCENTER | DT_CENTER);

		dc.MoveTo(0, rcClient.bottom);
		if (m_bSpeakingTip) {
			nHeight = m_nVolume*rcClient.Height() / 255;
			dc.SelectObject(m_penRed);
			dc.LineTo(0, rcClient.bottom - nHeight);
		}
		else {
			dc.SelectObject(m_penNormal);
			dc.LineTo(0, rcClient.top);
		}
	}
}

BOOL CAGInfoWnd::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CRect rcClient;

	if (pDC != NULL) {
		GetClientRect(&rcClient);
		pDC->FillRect(&rcClient, &m_brBack);
	}

	return TRUE;
}

// CAGVideoWnd

IMPLEMENT_DYNAMIC(CAGVideoWnd, CWnd)

CAGVideoWnd::CAGVideoWnd()
: m_nUID(0)
, m_crBackColor(RGB(0x58, 0x58, 0x58))
, m_bShowVideoInfo(FALSE)
, m_bBigShow(FALSE)
, m_bBackground(FALSE)
{

}

CAGVideoWnd::~CAGVideoWnd()
{
	m_imgBackGround.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CAGVideoWnd, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CAGVideoWnd 消息处理程序
BOOL CAGVideoWnd::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CRect		rcClient;
	CPoint		ptDraw;
	IMAGEINFO	imgInfo;

	GetClientRect(&rcClient);

	pDC->FillSolidRect(&rcClient, m_crBackColor);
	if (!m_imgBackGround.GetImageInfo(0, &imgInfo))
		return TRUE;

	ptDraw.SetPoint((rcClient.Width() - imgInfo.rcImage.right) / 2, (rcClient.Height() - imgInfo.rcImage.bottom) / 2);
	if (ptDraw.x < 0)
		ptDraw.x = 0;
	if (ptDraw.y <= 0)
		ptDraw.y = 0;

	m_imgBackGround.Draw(pDC, 0, ptDraw, ILD_NORMAL);
	return TRUE;
}

void CAGVideoWnd::SetUID(UINT nUID)
{
	m_nUID = nUID;

	if (m_nUID == 0)
		m_wndInfo.ShowWindow(SW_HIDE);
	else
		m_wndInfo.ShowWindow(SW_SHOW);

	m_wndInfo.SetUID(nUID);
}

UINT CAGVideoWnd::GetUID()
{
	return m_nUID;
}

BOOL CAGVideoWnd::IsWndFree()
{
	return m_nUID == 0 ? TRUE : FALSE;
}

BOOL CAGVideoWnd::SetBackImage(UINT nID, UINT nWidth, UINT nHeight, COLORREF crMask)
{
	CBitmap bmBackImage;

	if (!bmBackImage.LoadBitmap(nID))
		return FALSE;

	m_imgBackGround.DeleteImageList();

	m_imgBackGround.Create(nWidth, nHeight, ILC_COLOR24 | ILC_MASK, 1, 1);
	m_imgBackGround.Add(&bmBackImage, crMask);
	bmBackImage.DeleteObject();

	Invalidate(TRUE);

	return TRUE;
}

void CAGVideoWnd::ShowBackground(BOOL bBackground)
{
	m_bBackground = bBackground;

	Invalidate(TRUE);
}

void CAGVideoWnd::SetFaceColor(COLORREF crBackColor)
{
	m_crBackColor = crBackColor;

	Invalidate(TRUE);
}

void CAGVideoWnd::SetVideoResolution(UINT nWidth, UINT nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	CRect rcWinRect;

	GetWindowRect(&rcWinRect);
	m_wndInfo.SetVideoResolution(nWidth, nHeight);
	m_wndInfo.SetWindowInfo(rcWinRect.Width(), rcWinRect.Height());
}

void CAGVideoWnd::GetVideoResolution(UINT *nWidth, UINT *nHeight)
{
	*nWidth = m_nWidth;
	*nHeight = m_nHeight;
}

void CAGVideoWnd::SetBitrateInfo(int nReceivedBitrate)
{
	m_nBitRate = nReceivedBitrate;
	m_wndInfo.SetBitrateInfo(nReceivedBitrate);
}

void CAGVideoWnd::SetFrameRateInfo(int nReceiveFrameRate)
{
	m_nFrameRate = nReceiveFrameRate;
	m_wndInfo.SetFrameRateInfo(nReceiveFrameRate);
}

void CAGVideoWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	::SendMessage(GetParent()->GetSafeHwnd(), WM_SHOWBIG, (WPARAM)this, (LPARAM)m_nUID);

	CWnd::OnLButtonDown(nFlags, point);
}


void CAGVideoWnd::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	::SendMessage(GetParent()->GetSafeHwnd(), WM_SHOWMODECHANGED, (WPARAM)this, (LPARAM)m_nUID);

	CWnd::OnRButtonDown(nFlags, point);
}


int CAGVideoWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_wndInfo.Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, CRect(0, 0, WND_INFO_WIDTH, 28), this, IDC_STATIC);

	return 0;
}


void CAGVideoWnd::ShowVideoInfo(BOOL bShow)
{
	m_bShowVideoInfo = bShow;

	m_wndInfo.ShowTips(bShow);

	Invalidate(TRUE);
}

void CAGVideoWnd::SetBigShowFlag(BOOL bBigShow)
{
	CRect	rcClient;

	m_bBigShow = bBigShow;
	GetClientRect(&rcClient);

	int x = (rcClient.Width() - WND_INFO_WIDTH) / 2;
	int y = rcClient.Height() - 24;

	if (m_wndInfo.GetSafeHwnd() != NULL) {
		if (m_bBigShow)
			y -= 4;

		m_wndInfo.MoveWindow(x, y, WND_INFO_WIDTH, 24);
	}
};


void CAGVideoWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	int x = (cx - WND_INFO_WIDTH) / 2;
	int y = cy - 24;
	// TODO:  在此处添加消息处理程序代码
	if (m_wndInfo.GetSafeHwnd() != NULL) {
		if (m_bBigShow)
			y -= 4;

		m_wndInfo.MoveWindow(x, y, WND_INFO_WIDTH, 24);
	}
}


void CAGVideoWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	::SendMessage(GetParent()->GetSafeHwnd(), WM_SHOWMODECHANGED, (WPARAM)this, (LPARAM)m_nUID);

	CWnd::OnLButtonDblClk(nFlags, point);
}


void CAGVideoWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()

	if (m_bBackground) {
		CRect		rcClient;
		CPoint		ptDraw;
		IMAGEINFO	imgInfo;

		GetClientRect(&rcClient);

		dc.FillSolidRect(&rcClient, m_crBackColor);
		if (!m_imgBackGround.GetImageInfo(0, &imgInfo))
			return;

		ptDraw.SetPoint((rcClient.Width() - imgInfo.rcImage.right) / 2, (rcClient.Height() - imgInfo.rcImage.bottom) / 2);
		if (ptDraw.x < 0)
			ptDraw.x = 0;
		if (ptDraw.y <= 0)
			ptDraw.y = 0;

		m_imgBackGround.Draw(&dc, 0, ptDraw, ILD_NORMAL);
	}
	else
		return CWnd::OnPaint();
}

void CAGVideoWnd::ShowSpeakingTip(BOOL bShow, int nVolume)
{
	m_wndInfo.ShowSpeakingTip(bShow, nVolume);
}