#pragma once
#include "Automobile.h"
#include "PlayerPed.h"

enum eWastedBustedState
{
	WBSTATE_PLAYING,
	WBSTATE_WASTED,
	WBSTATE_BUSTED,
	WBSTATE_FAILED_CRITICAL_MISSION,
};

struct CCivilianPed
{

};

class CPlayerInfo
{
public:
	CPlayerPed *m_pPed;
	CVehicle *m_pRemoteVehicle;
	CColModel m_ColModel;
	CVehicle *m_pVehicleEx;
	char m_aszPlayerName[70];
private:
	int8 _pad0[2];
public:
	int32 m_nMoney;
	int32 m_nVisibleMoney;
	int32 m_nCollectedPackages;
	int32 m_nTotalPackages;
	int32 field_188;
	int32 m_nSwitchTaxiTime;
	bool m_bSwitchTaxi;
	int8 field_197;
	int8 field_198;
	int8 field_199;
	int32 m_nNextSexFrequencyUpdateTime;
	int32 m_nNextSexMoneyUpdateTime;
	int32 m_nSexFrequency;
	CCivilianPed *m_pHooker;
	int8 m_bWBState; // eWastedBustedState
	int8 field_217;
	int8 field_218;
	int8 field_219;
	int32 m_nWBTime;
	bool m_bInRemoteMode;
	int8 field_225;
	int8 field_226;
	int8 field_227;
	int32 m_nTimeLostRemoteCar;
	int32 m_nTimeLastHealthLoss;
	int32 m_nTimeLastArmourLoss;
	int32 field_240;
	int32 m_nUpsideDownCounter;
	int32 field_248;
	int16 m_nTrafficMultiplier;
	int8 field_254;
	int8 field_255;
	float m_fRoadDensity;
	int32 m_nPreviousTimeRewardedForExplosion;
	int32 m_nExplosionsSinceLastReward;
	int32 field_268;
	int32 field_272;
	bool m_bInfiniteSprint;
	bool m_bFastReload;
	bool m_bGetOutOfJailFree;
	bool m_bGetOutOfHospitalFree;
	uint8 m_aSkinName[32];
	RwTexture *m_pSkinTexture;
};

static_assert(sizeof(CPlayerInfo) == 0x13C, "CPlayerPed: error");