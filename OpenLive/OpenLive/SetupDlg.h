#pragma once
#include "AGButton.h"
#include "AGComboBox.h"
#include "AGSliderCtrl.h"
#include "afxwin.h"
#include "AGEdit.h"
#include "AGConfig.h"
#include "SetupData.h"
// CSetupDlg 对话框

class CSetupDlg : public CDialogEx
{

	DECLARE_DYNAMIC(CSetupDlg)

public:
	CSetupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetupDlg();

    void SetVideoSolution(int nIndex);
    int GetVideoSolution();
	int GetWidth();
	int GetHeight();
	int GetBitrate();
	int GetFPS();
    CString GetVideoSolutionDes();

	int GetEncoderType();
	bool GetCheckIntra();
	void SetWHSwap(BOOL bSwap);
	BOOL IsWHSwap();

// 对话框数据
	enum { IDD = IDD_SETUP_DIALOG };

	typedef struct _AGVIDEO_PARAM
	{
		int nWidth;
		int nHeight;
		int nMinKPB;
		int nMaxKPB;

	} AGNET_RATE_RANGE;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnconfirmSetup();
	afx_msg void OnBnClickedBtncancelSetup();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	DECLARE_MESSAGE_MAP()

protected:
	void InitCtrls();
	void InitData();
	void DrawClient(CDC *lpDC);

private:
	CAGButton       m_btnCancel;
	CAGButton		m_btnConfirm;
	CButton			m_ckSaveSettings;
	CButton			m_ckSwapWH;

	CButton			m_ckFullBand;
	CButton			m_ckStereo;
	CButton			m_ckFullBitrate;

	CAGComboBox		m_cbxVideoProfile;

	CFont			m_ftHead;		// title
	CFont			m_ftDes;		// text in ctrl
	CFont			m_ftBtn;		// button
	CPen            m_penFrame;

    int                 m_nProfileValue[64];
	LPTSTR			    m_szProfileDes[64];
	AGNET_RATE_RANGE	m_agRateRange[13];
	
	int fps[4];

	int m_nWidth;
	int m_nHeight;
	int m_fps;
	int m_bitrate;
	int fps_sel;
	int encoder_type;
	int layout_type;
private:
	CAGConfig		m_agConfig;	
public:
	CComboBox m_cmbEncoder;
	CButton m_chkIntraRequest;
	afx_msg void OnBnClickedButtonSetparam();
	
	CEdit m_edtParam;
	CButton m_btnSetParam;
	CButton m_btnGetParam;
	CButton m_btnReadFile;
	afx_msg void OnBnClickedButtonGetparam();
	afx_msg void OnBnClickedButtonReadfile();
	CAGEdit m_edtWidth;
	CAGEdit m_edtHeight;
	CAGEdit m_edtBitrate;
	CComboBox m_cmbFPS;
	afx_msg void OnBnClickedCkswpwhSetup();
	CComboBox m_cmbLayout;
	CButton m_checkBtn_mode;
};
