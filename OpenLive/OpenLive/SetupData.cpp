#include "stdafx.h"
#include "SetupData.h"

CSetupData* CSetupData::GetSetupData()
{
	static CSetupData setupData;
	return &setupData;
}

CSetupData::CSetupData()
{

}

CSetupData::~CSetupData()
{

}

void CSetupData::SetupVideoResolution(int w, int h, int fps, int bit)
{
	width = w;
	height = h;
	framerate = fps; 
	bitrate = bit;
}