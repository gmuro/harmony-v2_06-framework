/*******************************************************************************
* Contains proprietary and confidential information of SEARAN LLC.
* May not be used or disclosed to any other party except in accordance
* with a license from SEARAN LLC.
* Copyright (c) 2011-2015 SEARAN LLC. All Rights Reserved.
*******************************************************************************/

/******************************************************************************
* DO NOT MODIFY THIS FILE!
* This file was machine generated by the make_patch_script.pl script
*******************************************************************************/

#include "cdbt/bt/bt_std.h"
#include "cdbt/bt/bt_private.h"
#include "cdbt/extra/ti/ti.h"


// Set Power tables (note the special notation, 7.1)
static const bt_byte packet01[] = {0x01,0x82,0xfd,0x13,0x00,0x9c,0x14,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0xd8,0xe2,
                                   0xec,0xf6,0x00,0x0a,0x14,0xff,0x00,0x00};
static const bt_byte packet02[] = {0x01,0x82,0xfd,0x13,0x01,0x9c,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0xd8,0xe2,
                                   0xec,0xf6,0x00,0x0a,0x14,0xff,0x00,0x00};
static const bt_byte packet03[] = {0x01,0x82,0xfd,0x13,0x02,0x9c,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0xd8,0xe2,
                                   0xec,0xf6,0x00,0x0a,0x14,0xff,0x00,0x00};
//Update max power (for devices which don't support power control)
static const bt_byte packet04[] = {0x01,0x87,0xfd,0x03,0x0d,0x0d,0x0d};
// Set Class 1.5 mode when "0" = VBAT, "1" = DC2DC/SMPS mode
// When at VBAT, the command below updates the Trim value to 7. at DC2DC the temperature calibration 
// Updates the Trim value according to the temperature of the device.
// For SMPS/DC2DC with trim 7 (default value) use the command below:
static const bt_byte packet05[] = {0x01,0x6e,0xfd,0x02,0x01,0x07};
// calibration info
static const bt_byte packet06[] = {0x01,0x76,0xfd,0x2e,0x01,0x21,0x54,0x00,0x00,0x61,0x57,0x00,0x00,0x14,0x05,0x0a,
                                   0x05,0x00,0x07,0x06,0x0a,0x04,0x05,0x08,0x09,0x0b,0x0c,0x0d,0x0e,0x10,0x10,0x10,
                                   0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
                                   0x10,0x00};
//run calibration first time (Init)
static const bt_byte packet07[] = {0x01,0x80,0xfd,0x06,0x00,0x01,0x00,0x00,0x00,0x01};
//Enable periodic calibrations (DC+KDCO+TPC+LPS+WB_RSSI+Temperature+IFA pole)
static const bt_byte packet08[] = {0x01,0x80,0xfd,0x06,0x3c,0xf0,0x5f,0x00,0x00,0x00};

static const bt_byte* const packets[] = {packet01,packet02,packet03,packet04,packet05,packet06,packet07,packet08};

#define PACKET_COUNT (sizeof(packets) / sizeof(packets[0]))

static const btx_ti_script_t script =
{
	packets,
	PACKET_COUNT,
	0, 0         // compatible FW version N/A
};

const btx_ti_script_t* btx_ti_get_script__WL127xL_BT_Service_Pack_2_4_DC2DC_AddOn(void)
{
	return &script;
}

//-------------------------------------------------------------------
// END OF GENERATED FILE
//-------------------------------------------------------------------
