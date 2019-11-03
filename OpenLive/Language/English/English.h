// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ENGLISH_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ENGLISH_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ENGLISH_EXPORTS
#define ENGLISH_API __declspec(dllexport)
#else
#define ENGLISH_API __declspec(dllimport)
#endif


extern ENGLISH_API LPCTSTR IDS_TITLE;
extern ENGLISH_API LPCTSTR IDS_LOGO_DESC;
extern ENGLISH_API LPCTSTR IDS_LOGO_AGORAWEB;

extern ENGLISH_API LPCTSTR IDS_PRE_TITLE;
extern ENGLISH_API LPCTSTR IDS_PRE_OPTDSC1;
extern ENGLISH_API LPCTSTR IDS_PRE_OPTDSC2;
extern ENGLISH_API LPCTSTR IDS_PRE_WEBDSC1;
extern ENGLISH_API LPCTSTR IDS_PRE_WEBDSC2;

extern ENGLISH_API LPCTSTR IDS_PRE_BTNOPT;
extern ENGLISH_API LPCTSTR IDS_PRE_BTNWEB;

extern ENGLISH_API LPCTSTR IDS_CHN_TITLE1;
extern ENGLISH_API LPCTSTR IDS_CHN_TITLE2;
extern ENGLISH_API LPCTSTR IDS_CHN_DSC1;
extern ENGLISH_API LPCTSTR IDS_CHN_DSC2;
extern ENGLISH_API LPCTSTR IDS_CHN_DSC3;
extern ENGLISH_API LPCTSTR IDS_CHN_DSC4;
extern ENGLISH_API LPCTSTR IDS_CHN_ROOMKEY;

extern ENGLISH_API LPCTSTR IDS_CHN_BTBACK;
extern ENGLISH_API LPCTSTR IDS_CHN_BTTEST;
extern ENGLISH_API LPCTSTR IDS_CHN_BTJOIN;

extern ENGLISH_API LPCTSTR IDS_CHN_ROLETITLE;
extern ENGLISH_API LPCTSTR IDS_CHN_ROLE0;
extern ENGLISH_API LPCTSTR IDS_CHN_ROLE1;
extern ENGLISH_API LPCTSTR IDS_CHN_ROLE2;
extern ENGLISH_API LPCTSTR IDS_CHN_ROLE3;

extern ENGLISH_API LPCTSTR IDS_CHN_CASTER;
extern ENGLISH_API LPCTSTR IDS_CHN_AUDIENCE;

extern ENGLISH_API LPCTSTR IDS_CHN_CHANNELNAME;
extern ENGLISH_API LPCTSTR IDS_CHN_ROOMPASSWORD;

extern ENGLISH_API LPCTSTR IDS_CHN_CHTIP1;
extern ENGLISH_API LPCTSTR IDS_CHN_CHTIP2;

extern ENGLISH_API LPCTSTR IDS_CHN_KEYTIP1;
extern ENGLISH_API LPCTSTR IDS_CHN_KEYTIP2;

extern ENGLISH_API LPCTSTR IDS_SET_RESOLUTION;
extern ENGLISH_API LPCTSTR IDS_SET_MFR;
extern ENGLISH_API LPCTSTR IDS_SET_MR;
extern ENGLISH_API LPCTSTR IDS_SET_BTCONFIRM;

extern ENGLISH_API LPCTSTR IDS_SET_FULLBAND;
extern ENGLISH_API LPCTSTR IDS_SET_STEREO;
extern ENGLISH_API LPCTSTR IDS_SET_FULLBITRATE;

extern ENGLISH_API LPCTSTR IDS_ENCODE_SOFTWARE;
extern ENGLISH_API LPCTSTR IDS_ENCODE_INTEL;
extern ENGLISH_API LPCTSTR IDS_ENCODE_NVIDIA;


extern ENGLISH_API LPCTSTR IDS_SET_CODEC;
extern ENGLISH_API LPCTSTR IDS_SET_SWAPWH;
extern ENGLISH_API LPCTSTR IDS_SET_SAVESETTING;

extern ENGLISH_API LPCTSTR IDS_DEVICE_AUDIOIN;
extern ENGLISH_API LPCTSTR IDS_DEVICE_AUDIOOUT;
extern ENGLISH_API LPCTSTR IDS_DEVICE_CAMERA;
extern ENGLISH_API LPCTSTR IDS_DEVICE_VOLUME;
extern ENGLISH_API LPCTSTR IDS_DEVICE_BTNTEST;
extern ENGLISH_API LPCTSTR IDS_DEVICE_BTNTESTOFF;
extern ENGLISH_API LPCTSTR IDS_DEVICE_CANCEL;
extern ENGLISH_API LPCTSTR IDS_DEVICE_CONFIRM;
extern ENGLISH_API LPCTSTR IDS_DEVICE_APPLY;

extern ENGLISH_API LPCTSTR IDS_VIDEO_SCRSHARE;
extern ENGLISH_API LPCTSTR IDS_VIDEO_WNDSHARE;

extern ENGLISH_API LPCTSTR IDS_VIDEO_WBHOST;
extern ENGLISH_API LPCTSTR IDS_VIDEO_WBGUEST;

extern ENGLISH_API LPCTSTR IDS_VIDEO_MOREDEVICE;
extern ENGLISH_API LPCTSTR IDS_VIDEO_MORESEI;

extern ENGLISH_API LPCTSTR IDS_SEI_CAVWIDTH;
extern ENGLISH_API LPCTSTR IDS_SEI_CAVHEIGHT;
extern ENGLISH_API LPCTSTR IDS_SEI_INDEX;
extern ENGLISH_API LPCTSTR IDS_SEI_XPOS;
extern ENGLISH_API LPCTSTR IDS_SEI_YPOS;
extern ENGLISH_API LPCTSTR IDS_SEI_WIDTH;
extern ENGLISH_API LPCTSTR IDS_SEI_HEIGHT;