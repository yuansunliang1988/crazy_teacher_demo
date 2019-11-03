#pragma once
#include <unordered_map>

enum {
	CLASS_TEACHER_MODE = 0,
	CLASS_INTERACTIVE_MODE
};

enum {
	LAYOUT_AVERAGE = 0,
	LAYOUT_TEACHER_BIG
};

enum {
	SCREEN_VIDEO1 = 0,	// 单屏
	SCREEN_VIDEO2,	    // 1左一右
	SCREEN_VIDEO3,		// 上2下1分屏
	SCREEN_VIDEO4,		// 4分屏
	SCREEN_VIDEO5,		// 4分屏
	SCREEN_VIDEO6,
	SCREEN_VIDEO7,
	SCREEN_VIDEO8,      // 9宫格
	SCREEN_VIDEOMULTI,	// 1大4小
};

enum{
	ENCODER_SOFTWARE = 0,
	ENCODER_NVIDIA,
	ENCODER_INTEL
};

class CSetupData
{
public:
	CSetupData();
	~CSetupData();

	static CSetupData* GetSetupData();

	void SetupVideoResolution(int w, int h, int fps, int bit);
public:
	int framerate = 15;
	int bitrate = 500;
	int width = 640;
	int height = 360;

	int layout = LAYOUT_AVERAGE;
	int encoder_type = ENCODER_SOFTWARE;
	bool intra_request = false;
	bool fluency_precedence = false;
};

#define AgoraGetSetupData()  CSetupData::GetSetupData()