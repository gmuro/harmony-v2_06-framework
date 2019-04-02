/*******************************************************************************
  File Name:
    nmdrv.c

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

#include "driver/wifi/winc1500/wireless_driver_extension/common/include/nm_common.h"
#include "driver/wifi/winc1500/wireless_driver_extension/common/include/nm_debug.h"
#include "driver/wifi/winc1500/wireless_driver_extension/driver/include/m2m_types.h"
#include "driver/wifi/winc1500/wireless_driver_extension/driver/source/nmasic.h"
#include "driver/wifi/winc1500/wireless_driver_extension/driver/source/nmbus.h"
#include "driver/wifi/winc1500/wireless_driver_extension/driver/source/nmdrv.h"
#include "driver/wifi/winc1500/wireless_driver_extension/driver/source/nmspi.h"
#include "driver/wifi/winc1500/wireless_driver_extension/spi_flash/include/spi_flash.h"

/**
*	@fn		nm_get_firmware_info(tstrM2mRev* M2mRev)
*	@brief	Get Firmware version info
*	@param [out]	M2mRev
*			    pointer holds address of structure "tstrM2mRev" that contains the firmware version parameters
*	@version	1.0
*/
sint8 nm_get_firmware_info(tstrM2mRev* M2mRev)
{
	uint16  curr_drv_ver, min_req_drv_ver,curr_firm_ver;
	uint32	reg = 0;
	sint8	ret = M2M_SUCCESS;

	ret = nm_read_reg_with_ret(NMI_REV_REG, &reg);
	//In case the Firmware running is ATE fw
	if(M2M_ATE_FW_IS_UP_VALUE == reg)
	{
		//Read FW info again from the register specified for ATE
		ret = nm_read_reg_with_ret(NMI_REV_REG_ATE, &reg);
	}
	M2mRev->u8DriverMajor	= M2M_GET_DRV_MAJOR(reg);
	M2mRev->u8DriverMinor   = M2M_GET_DRV_MINOR(reg);
	M2mRev->u8DriverPatch	= M2M_GET_DRV_PATCH(reg);
	M2mRev->u8FirmwareMajor	= M2M_GET_FW_MAJOR(reg);
	M2mRev->u8FirmwareMinor = M2M_GET_FW_MINOR(reg);
	M2mRev->u8FirmwarePatch = M2M_GET_FW_PATCH(reg);
	M2mRev->u32Chipid	= nmi_get_chipid();
	M2mRev->u16FirmwareSvnNum = 0;
	
	curr_firm_ver   = M2M_MAKE_VERSION(M2mRev->u8FirmwareMajor, M2mRev->u8FirmwareMinor, M2mRev->u8FirmwarePatch);
	curr_drv_ver    = M2M_MAKE_VERSION(M2M_RELEASE_VERSION_MAJOR_NO, M2M_RELEASE_VERSION_MINOR_NO, M2M_RELEASE_VERSION_PATCH_NO);
	min_req_drv_ver = M2M_MAKE_VERSION(M2mRev->u8DriverMajor, M2mRev->u8DriverMinor, M2mRev->u8DriverPatch);
	if(curr_drv_ver <  min_req_drv_ver) {
		/*The current driver version should be larger or equal 
		than the min driver that the current firmware support  */
		ret = M2M_ERR_FW_VER_MISMATCH;
	}
	if(curr_drv_ver >  curr_firm_ver) {
		/*The current driver should be equal or less than the firmware version*/
		ret = M2M_ERR_FW_VER_MISMATCH;
	}
	return ret;
}

/**
 *	@fn		nm_get_firmware_info(tstrM2mRev *M2mRev)
 *	@brief	Get Firmware version info
 *	@param [out]	M2mRev
 *				pointer holds address of structure "tstrM2mRev" that contains the firmware version parameters
 *	@version	1.0
 */
sint8 nm_get_firmware_full_info(tstrM2mRev *pstrRev)
{
	uint16  curr_drv_ver, min_req_drv_ver, curr_firm_ver;
	uint32	reg = 0;
	sint8	ret = M2M_SUCCESS;
	tstrGpRegs strgp = {0};

	if (pstrRev != NULL)
	{
		m2m_memset((uint8 *)pstrRev, 0, sizeof(tstrM2mRev));
		ret = nm_read_reg_with_ret(rNMI_GP_REG_2, &reg);
		if(ret == M2M_SUCCESS)
		{
			if(reg != 0)
			{
				ret = nm_read_block(reg|0x30000, (uint8 *)&strgp, sizeof(tstrGpRegs));
				if(ret == M2M_SUCCESS)
				{
					reg = strgp.u32Firmware_Ota_rev;
					reg &= 0x0000ffff;
					if(reg != 0)
					{
						ret = nm_read_block(reg|0x30000, (uint8 *)pstrRev, sizeof(tstrM2mRev));
						if(ret == M2M_SUCCESS)
						{
							curr_firm_ver   = M2M_MAKE_VERSION(pstrRev->u8FirmwareMajor, pstrRev->u8FirmwareMinor, pstrRev->u8FirmwarePatch);
							curr_drv_ver    = M2M_MAKE_VERSION(M2M_RELEASE_VERSION_MAJOR_NO, M2M_RELEASE_VERSION_MINOR_NO, M2M_RELEASE_VERSION_PATCH_NO);
							min_req_drv_ver = M2M_MAKE_VERSION(pstrRev->u8DriverMajor, pstrRev->u8DriverMinor, pstrRev->u8DriverPatch);
							if((curr_firm_ver == 0)||(min_req_drv_ver == 0)||(min_req_drv_ver == 0)){
								ret = M2M_ERR_FAIL;
								goto EXIT;
							}
							if(curr_drv_ver < min_req_drv_ver) {
								/*The current driver version should be larger or equal 
								than the min driver that the current firmware support*/
								ret = M2M_ERR_FW_VER_MISMATCH;
								goto EXIT;
							}
							if(curr_drv_ver > curr_firm_ver) {
								/*The current driver should be equal or less than the firmware version*/
								ret = M2M_ERR_FW_VER_MISMATCH;
								goto EXIT;
							}
						}
					}else {
						ret = M2M_ERR_FAIL;
					}
				}
			}else{
				ret = M2M_ERR_FAIL;
			}
		}
	}
EXIT:
	return ret;
}

/**
 *	@fn		nm_get_ota_firmware_info(tstrM2mRev *pstrRev)
 *	@brief	Get Firmware version info
 *	@param [out]	M2mRev
 *				pointer holds address of structure "tstrM2mRev" that contains the firmware version parameters
 *	@version	1.0
 */
sint8 nm_get_ota_firmware_info(tstrM2mRev *pstrRev)
{
	uint16  curr_drv_ver, min_req_drv_ver, curr_firm_ver;
	uint32	reg = 0;
	sint8	ret;
	tstrGpRegs strgp = {0};

	if (pstrRev != NULL)
	{
		m2m_memset((uint8 *)pstrRev, 0, sizeof(tstrM2mRev));
		ret = nm_read_reg_with_ret(rNMI_GP_REG_2, &reg);
		if(ret == M2M_SUCCESS)
		{
			if(reg != 0)
			{
				ret = nm_read_block(reg|0x30000, (uint8 *)&strgp, sizeof(tstrGpRegs));
				if(ret == M2M_SUCCESS)
				{
					reg = strgp.u32Firmware_Ota_rev;
					reg >>= 16;
					if(reg != 0)
					{
						ret = nm_read_block(reg|0x30000, (uint8 *)pstrRev, sizeof(tstrM2mRev));
						if(ret == M2M_SUCCESS)
						{
							curr_firm_ver   = M2M_MAKE_VERSION(pstrRev->u8FirmwareMajor, pstrRev->u8FirmwareMinor, pstrRev->u8FirmwarePatch);
							curr_drv_ver    = M2M_MAKE_VERSION(M2M_RELEASE_VERSION_MAJOR_NO, M2M_RELEASE_VERSION_MINOR_NO, M2M_RELEASE_VERSION_PATCH_NO);
							min_req_drv_ver = M2M_MAKE_VERSION(pstrRev->u8DriverMajor, pstrRev->u8DriverMinor, pstrRev->u8DriverPatch);
							if((curr_firm_ver == 0)||(min_req_drv_ver == 0)||(min_req_drv_ver == 0)){
								ret = M2M_ERR_FAIL;
								goto EXIT;
							}
							if(curr_drv_ver < min_req_drv_ver) {
								/*The current driver version should be larger or equal 
								than the min driver that the current firmware support*/
								ret = M2M_ERR_FW_VER_MISMATCH;
							}
							if(curr_drv_ver > curr_firm_ver) {
								/*The current driver should be equal or less than the firmware version*/
								ret = M2M_ERR_FW_VER_MISMATCH;
							}
						}
					}else{
						ret = M2M_ERR_INVALID;
					}
				}
			}else{
				ret = M2M_ERR_FAIL;
			}
		}
	} else {
		ret = M2M_ERR_INVALID_ARG;
	}
EXIT:
	return ret;
}

/*
 *	@fn		nm_drv_init_download_mode
 *	@brief	Initialize NMC1000 driver
 *	@return	M2M_SUCCESS in case of success and Negative error code in case of failure
 *	@param [in]	arg
 *				Generic argument
 *	@author	Viswanathan Murugesan
 *	@date	10 Oct 2014
 *	@version	1.0
 */
sint8 nm_drv_init_download_mode()
{
	sint8 ret = M2M_SUCCESS;

	ret = nm_bus_iface_init(NULL);
	if (M2M_SUCCESS != ret) {
		M2M_ERR("[nmi start]: fail init bus\n");
		goto ERR1;
	}

	nm_spi_lock_init();

	/**
		TODO:reset the chip and halt the cpu in case of no wait efuse is set (add the no wait effuse check)
	*/
	if(!ISNMC3000(GET_CHIPID()))
	{
		/*Execuate that function only for 1500A/B, no room in 3000, but it may be needed in 3400 no wait*/
		chip_reset_and_cpu_halt();
	}

	/* Must do this after global reset to set SPI data packet size. */
	nm_spi_init();

	M2M_INFO("Chip ID %lx\n", nmi_get_chipid());

	/*disable all interrupt in ROM (to disable uart) in 2b0 chip*/
	nm_write_reg(0x20300, 0);

ERR1:
	return ret;
}

/*
*	@fn		nm_drv_init
*	@brief	Initialize NMC1000 driver
*	@return	M2M_SUCCESS in case of success and Negative error code in case of failure
*   @param [in]	arg
*				Generic argument
*	@author	M. Abdelmawla
*	@date	15 July 2012
*	@version	1.0
*/
sint8 nm_drv_init(void *arg)
{
	sint8 ret = M2M_SUCCESS;
	uint8 u8Mode;

	if (NULL != arg) {
		u8Mode = *((uint8 *)arg);
		if ((u8Mode < M2M_WIFI_MODE_NORMAL)||(u8Mode >= M2M_WIFI_MODE_MAX)) {
			u8Mode = M2M_WIFI_MODE_NORMAL;
		}
	} else {
		u8Mode = M2M_WIFI_MODE_NORMAL;
	}

	ret = nm_bus_iface_init(NULL);
	if (M2M_SUCCESS != ret) {
		M2M_ERR("[nmi start]: fail init bus\n");
		goto ERR1;
	}

#ifdef BUS_ONLY
	return;
#endif

#ifdef NO_HW_CHIP_EN
	ret = chip_wake();
	if (M2M_SUCCESS != ret) {
		M2M_ERR("[nmi start]: fail chip_wakeup\n");
		goto ERR2;
	}

	/**
	Go...
	**/
	ret = chip_reset();
	if (M2M_SUCCESS != ret) {
		goto ERR2;
	}
#endif

	/* Must do this after global reset to set SPI data packet size. */
    nm_spi_lock_init();
	nm_spi_init();

	M2M_INFO("Chip ID %lx\n", nmi_get_chipid());

	ret = wait_for_bootrom(u8Mode);
	if (M2M_SUCCESS != ret) {
		goto ERR2;
	}

	ret = wait_for_firmware_start(u8Mode);
	if (M2M_SUCCESS != ret) {
		goto ERR2;
	}

	if ((M2M_WIFI_MODE_ATE_HIGH == u8Mode)||(M2M_WIFI_MODE_ATE_LOW == u8Mode)) {
		goto ERR1;
	} else {
		/*continue running*/
	}

	ret = enable_interrupts();
	if (M2M_SUCCESS != ret) {
		M2M_ERR("failed to enable interrupts..\n");
		goto ERR2;
	}
	return ret;

ERR2:
	nm_bus_iface_deinit();
ERR1:
	return ret;
}

/*
*	@fn		nm_drv_deinit
*	@brief	Deinitialize NMC1000 driver
*	@author	M. Abdelmawla
*	@date	17 July 2012
*	@version	1.0
*/
sint8 nm_drv_deinit(void * arg)
{
	sint8 ret;

	ret = chip_deinit();
	if (M2M_SUCCESS != ret) {
		M2M_ERR("[nmi stop]: chip_deinit fail\n");
		goto ERR1;
	}
	
	/* Disable SPI flash to save power when the chip is off */
	ret = spi_flash_enable(0);
	if (M2M_SUCCESS != ret) {
		M2M_ERR("[nmi stop]: SPI flash disable fail\n");
		goto ERR1;
	}

	ret = nm_bus_iface_deinit();
	if (M2M_SUCCESS != ret) {
		M2M_ERR("[nmi stop]: fail init bus\n");
		goto ERR1;
	}
	/* Must do this after global reset to set SPI data packet size. */
	nm_spi_deinit();

ERR1:
	return ret;
}

//DOM-IGNORE-END
