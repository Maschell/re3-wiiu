#include "common.h"

#include "Draw.h"
#include "Frontend.h"
#include "Camera.h"
#include "CutsceneMgr.h"

#ifdef ASPECT_RATIO_SCALE
float CDraw::ms_fAspectRatio = DEFAULT_ASPECT_RATIO;
float CDraw::ms_fScaledFOV = 45.0f;
#endif

float CDraw::ms_fNearClipZ;
float CDraw::ms_fFarClipZ;
float CDraw::ms_fFOV = 45.0f;
float CDraw::ms_fLODDistance;

uint8 CDraw::FadeValue;
uint8 CDraw::FadeRed;
uint8 CDraw::FadeGreen;
uint8 CDraw::FadeBlue;

float
CDraw::FindAspectRatio(void)
{
#ifndef ASPECT_RATIO_SCALE
	if(FrontEndMenuManager.m_PrefsUseWideScreen)	
		return 16.0f/9.0f;
	else
		return 4.0f/3.0f;
#else
	switch (FrontEndMenuManager.m_PrefsUseWideScreen) {
	case AR_AUTO:
		return SCREEN_WIDTH / SCREEN_HEIGHT;
	default:
	case AR_4_3:
		return 4.0f / 3.0f;
	case AR_16_9:
		return 16.0f / 9.0f;
	};
#endif
}

#ifdef ASPECT_RATIO_SCALE
// convert a 4:3 hFOV to vFOV,
// then convert that vFOV to hFOV for our aspect ratio,
// i.e. HOR+
float
CDraw::ConvertFOV(float hfov)
{
	// => tan(hFOV/2) = tan(vFOV/2)*aspectRatio
	// => tan(vFOV/2) = tan(hFOV/2)/aspectRatio
	float ar1 = DEFAULT_ASPECT_RATIO;
	float ar2 = GetAspectRatio();
	hfov = DEGTORAD(hfov);
	float vfov = Atan(tan(hfov/2) / ar1) *2;
	hfov = Atan(tan(vfov/2) * ar2) *2;
	return RADTODEG(hfov);
}
#endif

void
CDraw::SetFOV(float fov)
{
#ifdef ASPECT_RATIO_SCALE
	if (!CCutsceneMgr::IsRunning())
		ms_fScaledFOV = ConvertFOV(fov);
	else
		ms_fScaledFOV = fov;
#endif
	ms_fFOV = fov;
}

#ifdef ASPECT_RATIO_SCALE
float
ScaleAndCenterX(float x)
{
	if (SCREEN_WIDTH == DEFAULT_SCREEN_WIDTH)
		return x;
	else
		return (SCREEN_WIDTH - SCREEN_SCALE_X(DEFAULT_SCREEN_WIDTH)) / 2 + SCREEN_SCALE_X(x);
}
#endif