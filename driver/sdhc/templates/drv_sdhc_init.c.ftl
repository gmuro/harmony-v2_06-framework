<#--
/*******************************************************************************
  SD Host Controller Driver Initialization File

  File Name:
    drv_sdhc_init.c.ftl

  Summary:
    This file contains source code necessary to initialize the SDHC driver.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, configuration bits, and allocates
    any necessary global system resources, such as the systemObjects structure
    that contains the object handles to all the MPLAB Harmony module objects in
    the system.
 *******************************************************************************/

/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

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
 -->
<#if CONFIG_USE_DRV_SDHC == true>
    sysObj.drvSDHC = DRV_SDHC_Initialize(DRV_SDHC_INDEX_0,(SYS_MODULE_INIT *)&drvSDHCInit);

    SYS_INT_VectorPrioritySet(${CONFIG_DRV_SDHC_INTERRUPT_VECTOR}, ${CONFIG_DRV_SDHC_INT_PRIORITY});
    SYS_INT_VectorSubprioritySet(${CONFIG_DRV_SDHC_INTERRUPT_VECTOR}, ${CONFIG_DRV_SDHC_INT_SUB_PRIORITY});
    SYS_INT_SourceEnable(${CONFIG_DRV_SDHC_INTERRUPT_SOURCE});

<#elseif CONFIG_USE_DRV_SDHC == false && CONFIG_HAVE_SDHC == true>
    /* Disable SDHC module */
	PLIB_POWER_PeripheralModuleDisable(POWER_ID_0, POWER_MODULE_SDHC);
</#if>
<#--
/*******************************************************************************
 End of File
*/
-->
