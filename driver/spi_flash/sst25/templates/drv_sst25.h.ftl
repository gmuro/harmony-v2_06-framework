<#--
/*******************************************************************************
  SST25 Driver Freemarker Template File

  Company:
    Microchip Technology Inc.

  File Name:
    drv_sst25vf020b.h.ftl

  Summary:
    SST25 Driver Freemarker Template File

  Description:

*******************************************************************************/

/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
-->
<#if CONFIG_USE_DRV_SST25 == true>
<#if CONFIG_DRV_SST25_DRIVER_MODE == "DYNAMIC">
// *****************************************************************************
/* SST25 Driver Configuration Options
*/
#define DRV_SST25_BUFFER_OBJ_NUMBER                       ${CONFIG_DRV_SST25_QUEUE_DEPTH_COMBINED}
#define DRV_SST25_CLIENTS_NUMBER                          ${CONFIG_DRV_SST25_CLIENTS_NUMBER}
#define DRV_SST25_INSTANCES_NUMBER                        ${CONFIG_DRV_SST25_INSTANCES_NUMBER}
<#if CONFIG_USE_DRV_SST25_SYS_FS_REGISTER == true>
#define DRV_SST25_SYS_FS_REGISTER
</#if>

<#-- Instance 0 -->
<#if CONFIG_DRV_SST25_INST_IDX0 == true>
#define DRV_SST25_POWER_STATE_IDX0                        ${CONFIG_DRV_SST25_POWER_STATE_IDX0}
#define DRV_SST25_SPI_DRIVER_INSTANCE_IDX0                ${CONFIG_DRV_SST25_SPI_DRIVER_INSTANCE_IDX0}
#define DRV_SST25_HOLD_PIN_PORT_CHANNEL_IDX0              ${CONFIG_DRV_SST25_HOLD_PIN_PORT_CHANNEL_IDX0}
#define DRV_SST25_HOLD_PIN_PORT_BIT_POS_IDX0              ${CONFIG_DRV_SST25_HOLD_PIN_PORT_BIT_POS_IDX0}
#define DRV_SST25_WRITE_PROTECT_PIN_PORT_CHANNEL_IDX0     ${CONFIG_DRV_SST25_WRITE_PROTECT_PIN_PORT_CHANNEL_IDX0}
#define DRV_SST25_WRITE_PROTECT_PIN_BIT_POS_IDX0          ${CONFIG_DRV_SST25_WRITE_PROTECT_PIN_BIT_POS_IDX0}
#define DRV_SST25_CHIP_SELECT_PORT_CHANNEL_IDX0           ${CONFIG_DRV_SST25_CHIP_SELECT_PORT_CHANNEL_IDX0}
#define DRV_SST25_CHIP_SELECT_PORT_BIT_POS_IDX0           ${CONFIG_DRV_SST25_CHIP_SELECT_PORT_BIT_POS_IDX0}
</#if>

<#-- Instance 1 -->
<#if CONFIG_DRV_SST25_INST_IDX1 == true>
#define DRV_SST25_POWER_STATE_IDX1                        ${CONFIG_DRV_SST25_POWER_STATE_IDX1}
#define DRV_SST25_SPI_DRIVER_INSTANCE_IDX1                ${CONFIG_DRV_SST25_SPI_DRIVER_INSTANCE_IDX1}
#define DRV_SST25_HOLD_PIN_PORT_CHANNEL_IDX1              ${CONFIG_DRV_SST25_HOLD_PIN_PORT_CHANNEL_IDX1}
#define DRV_SST25_HOLD_PIN_PORT_BIT_POS_IDX1              ${CONFIG_DRV_SST25_HOLD_PIN_PORT_BIT_POS_IDX1}
#define DRV_SST25_WRITE_PROTECT_PIN_PORT_CHANNEL_IDX1     ${CONFIG_DRV_SST25_WRITE_PROTECT_PIN_PORT_CHANNEL_IDX1}
#define DRV_SST25_WRITE_PROTECT_PIN_BIT_POS_IDX1          ${CONFIG_DRV_SST25_WRITE_PROTECT_PIN_BIT_POS_IDX1}
#define DRV_SST25_CHIP_SELECT_PORT_CHANNEL_IDX1           ${CONFIG_DRV_SST25_CHIP_SELECT_PORT_CHANNEL_IDX1}
#define DRV_SST25_CHIP_SELECT_PORT_BIT_POS_IDX1           ${CONFIG_DRV_SST25_CHIP_SELECT_PORT_BIT_POS_IDX1}
</#if>

<#-- Instance 2 -->
<#if CONFIG_DRV_SST25_INST_IDX2 == true>
#define DRV_SST25_POWER_STATE_IDX2                        ${CONFIG_DRV_SST25_POWER_STATE_IDX2}
#define DRV_SST25_SPI_DRIVER_INSTANCE_IDX2                ${CONFIG_DRV_SST25_SPI_DRIVER_INSTANCE_IDX2}
#define DRV_SST25_HOLD_PIN_PORT_CHANNEL_IDX2              ${CONFIG_DRV_SST25_HOLD_PIN_PORT_CHANNEL_IDX2}
#define DRV_SST25_HOLD_PIN_PORT_BIT_POS_IDX2              ${CONFIG_DRV_SST25_HOLD_PIN_PORT_BIT_POS_IDX2}
#define DRV_SST25_WRITE_PROTECT_PIN_PORT_CHANNEL_IDX2     ${CONFIG_DRV_SST25_WRITE_PROTECT_PIN_PORT_CHANNEL_IDX2}
#define DRV_SST25_WRITE_PROTECT_PIN_BIT_POS_IDX2          ${CONFIG_DRV_SST25_WRITE_PROTECT_PIN_BIT_POS_IDX2}
#define DRV_SST25_CHIP_SELECT_PORT_CHANNEL_IDX2           ${CONFIG_DRV_SST25_CHIP_SELECT_PORT_CHANNEL_IDX2}
#define DRV_SST25_CHIP_SELECT_PORT_BIT_POS_IDX2           ${CONFIG_DRV_SST25_CHIP_SELECT_PORT_BIT_POS_IDX2}
</#if>

</#if>
</#if>

<#--
/*******************************************************************************
 End of File
*/
-->
