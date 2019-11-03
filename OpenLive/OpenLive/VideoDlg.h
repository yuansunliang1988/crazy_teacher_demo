#pragma once
#include "AGButton.h"
#include "AGVideoWnd.h"
#include "DeviceDlg.h"
#include "ChatDlg.h"
#include "SEIDlg.h"
#include "AGScreenCaptureDlg.h"
#include "SetupData.h"
#include "SetupDlg.h"
// CVideoDlg 对话框
#define MAX_VIDEOS 9
class CVideoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVideoDlg)

public:
	CVideoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVideoDlg();

// 对话框数据
	enum { IDD = IDD_VIDEO_DIALOG };

	HWND GetRemoteVideoWnd(int nIndex);
	HWND GetLocalVideoWnd() { return m_wndLocal.GetSafeHwnd(); };

	void RebindVideoWnd();

	void ShowControlButton(BOOL bShow = TRUE);
	void SetSetupDlg(CSetupDlg* pDlg);
	int count = 1;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg LRESULT OnShowModeChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowBig(WPARAM wParam, LPARAM lParam);

	afx_msg void OnBnClickedBtnmin();
	afx_msg void OnBnClickedBtnclose();
	afx_msg void OnBnClickedBtnrest();

	afx_msg void OnBnClickedBtnmessage();
	afx_msg void OnBnClickedBtnmode();
	afx_msg void OnBnClickedBtnShowLocal();
	afx_msg void OnBnClickedBtnaudio();
	afx_msg void OnBnClickedBtntip();
	afx_msg void OnBnClickedBtnScreenCapture();
	afx_msg void OnBnClickedBtnMore();

	afx_msg void OnBnClickedBtnfullscr();
	afx_msg void OnCbnSelchangeCmbRole();

	afx_msg void OnBnClickedScreenshare();
	afx_msg void OnBnClickedWindowshare();

	afx_msg void OnBnClickedBtnsetup();
	afx_msg void OnBnClickedBtSEIPush();

	// 用于处理引擎的回调消息
	afx_msg LRESULT OnEIDJoinChannelSuccess(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDReJoinChannelSuccess(WPARAM wParam, LPARAM lParam);
	
	afx_msg LRESULT OnEIDFirstLocalFrame(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDFirstRemoteFrameDecoded(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDUserJoined(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDUserOffline(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDConnectionLost(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDVideoDeviceChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRemoteVideoStat(WPARAM wParam, LPARAM lParam);

	afx_msg LRESULT OnStartRecordingService(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStopRecordingService(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnApiCallExecuted(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

protected:
	BOOL NeedShowSizeBox(CPoint point);
	void EnableSize(BOOL bEnable);
	void CreateScreenShareMenu();
	void CreateMoreMenu();

	void DrawHead(CDC *pDC);

	void InitCtrls();

	void ShowVideo1();
	void ShowVideo2();
	void ShowVideo3();
	void ShowVideo4();
	void ShowVideo5();
	void ShowVideo6();
	void ShowVideo7();
	void ShowMulti();

	void ShowButtonsNormal();

	void AdjustButtonsNormal(int cx, int cy);

	void AdjustSizeVideo1(int cx, int cy);
	void AdjustSizeVideo2(int cx, int cy);
	void AdjustSizeVideo3(int cx, int cy);
	void AdjustSizeVideo4(int cx, int cy);
	void AdjustSizeVideo5(int cx, int cy);
	void AdjustSizeVideo6(int cx, int cy);
	void AdjustSizeVideo7(int cx, int cy);
	void AdjustSizeVideoMulti(int cx, int cy);

	void HideAllVideos();
	void ShowVideosWnd();
private:
	CSetupDlg* m_pDlgSetup;
	CBrush			m_brHead;
	CFont			m_ftDes;

	CAGButton		m_btnMin;
	CAGButton		m_btnRst;
	CAGButton		m_btnClose;
	
//	CAGButton		m_btnSetup;
	CAGButton		m_btnShowLocal;

	CAGButton		m_btnMode;
	CAGButton		m_btnAudio;
	CAGButton		m_btnEndCall;
	CComboBox		m_cbxRole;
	CAGButton		m_btnShow;
	CAGButton		m_btnTip;
	CAGButton		m_btnScrCap;

	CAGButton       m_btnMore;

	BOOL			m_bLastStat;
	UINT			m_nScreenMode;
	UINT            m_nLayout;
	UINT			m_nBigShowedUID;
	
	CAGVideoWnd		m_wndLocal;
	CAGVideoWnd		m_wndVideo[MAX_VIDEOS];
	CAGVideoWnd*	m_wndShowVideos[MAX_VIDEOS];
	CAGVideoWnd		*m_lpBigShowed;

	CDeviceDlg		m_dlgDevice;
	CChatDlg        m_dlgChat;
	CSEIDlg			m_dlgSEI;
	//CSetupDlg       m_dlgSetup;
	CRect			m_rcVideoArea;
	CRect			m_rcChildVideoArea;

	CBitmap         m_bitMenuDevice;
	CBitmap			m_bitMenuSEI;
	
	CAGScreenCaptureDlg	m_dlgScreenCapture;
	int showCount = 0;
private:	// data	

	typedef struct _AGVIDEO_WNDINFO
	{
		UINT	nUID;
		int		nIndex;

		UINT	nWidth;
		UINT	nHeight;
		int		nBitrate;
		int		nFramerate;
		int		nCodec;

	} AGVIDEO_WNDINFO, *PAGVIDEO_WNDINFO, *LPAGVIDEO_WNDINFO;

	CList<AGVIDEO_WNDINFO>	m_listWndInfo;

	BOOL			m_bRecording;
	BOOL			m_bFullScreen;
	int				m_nTimeCounter;

	BOOL  bShowLocalVideo = TRUE;

	BOOL oldShowLocalVideo = TRUE;
};
