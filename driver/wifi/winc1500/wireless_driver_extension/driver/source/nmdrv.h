/*******************************************************************************
  This module contains WINC1500 M2M driver APIs implementation.
  
  File Name:
    nmdrv.h

  Summary:
    This module contains WINC1500 M2M driver APIs implementation.

  Description:
    This module contains WINC1500 M2M driver APIs implementation.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc. All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/

#ifndef _NMDRV_H_
#define _NMDRV_H_

#include "driver/wifi/winc1500/wireless_driver_extension/common/include/nm_common.h"

/**
*  @struct		tstrM2mRev
*  @brief		Structure holding firmware version parameters and build date/time
*/
typedef struct {
	uint32 u32Chipid; /* HW revision which will be basically the chip ID */
	uint8 u8FirmwareMajor; /* Version Major Number which represents the official release base */
	uint8 u8FirmwareMinor; /* Version Minor Number which represents the engineering release base */
	uint8 u8FirmwarePatch;	/* Version pathc Number which represents the pathces release base */
	uint8 u8DriverMajor; /* Version Major Number which represents the official release base */
	uint8 u8DriverMinor; /* Version Minor Number which represents the engineering release base */
	uint8 u8DriverPatch; /* Version Patch Number which represents the pathces release base */
	uint8 BuildDate[sizeof(__DATE__)];
	uint8 BuildTime[sizeof(__TIME__)];
	uint8 _PAD8_;
	uint16 u16FirmwareSvnNum;
	uint16 _PAD16_[2];
} tstrM2mRev;

/**
*  @struct		tstrM2mBinaryHeader
*  @brief		Structure holding compatibility version info for firmware binaries
*/
typedef struct {
	tstrM2mRev binVerInfo;
    uint32	   flashOffset;
	uint32     payloadSize;
} tstrM2mBinaryHeader;

#ifdef __cplusplus
     extern "C" {
 #endif
/**
*	@fn		nm_get_firmware_info(tstrM2mRev* M2mRev)
*	@brief	Get Firmware version info
*	@param [out]	M2mRev
*			    pointer holds address of structure "tstrM2mRev" that contains the firmware version parameters
*	@version	1.0
*/
sint8 nm_get_firmware_info(tstrM2mRev* M2mRev);
/**
*	@fn		nm_get_firmware_full_info(tstrM2mRev* pstrRev)
*	@brief	Get Firmware version info
*	@param [out]	M2mRev
*			    pointer holds address of structure "tstrM2mRev" that contains the firmware version parameters
*	@version	1.0
*/
sint8 nm_get_firmware_full_info(tstrM2mRev* pstrRev);
/**
*	@fn		nm_get_ota_firmware_info(tstrM2mRev* pstrRev)
*	@brief	Get Firmware version info
*	@param [out]	M2mRev
*			    pointer holds address of structure "tstrM2mRev" that contains the firmware version parameters
			
*	@version	1.0
*/
sint8 nm_get_ota_firmware_info(tstrM2mRev* pstrRev);
/*
*	@fn		nm_drv_init
*	@brief	Initialize NMC1000 driver
*	@return	ZERO in case of success and Negative error code in case of failure
*/
sint8 nm_drv_init_download_mode(void);

/*
*	@fn		nm_drv_init
*	@brief	Initialize NMC1000 driver
*	@return	M2M_SUCCESS in case of success and Negative error code in case of failure
*   @param [in]	arg
*				Generic argument TBD
*	@return	ZERO in case of success and Negative error code in case of failure

*/
sint8 nm_drv_init(void * arg);

/**
*	@fn		nm_drv_deinit
*	@brief	Deinitialize NMC1000 driver
*	@author	M. Abdelmawla
*   @param [in]	arg
*				Generic argument TBD
*	@return	ZERO in case of success and Negative error code in case of failure
*/
sint8 nm_drv_deinit(void * arg);

#ifdef __cplusplus
	 }
 #endif

#endif	/*_NMDRV_H_*/


