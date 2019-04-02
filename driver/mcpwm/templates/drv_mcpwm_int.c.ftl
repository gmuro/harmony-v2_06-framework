<#--
/*******************************************************************************
  MCPWM Driver Functions for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_mcpwm_int.c.ftl

  Summary:
    MCPWM driver interrupt handler templates.

  Description:
    The MCPWM device driver provides a simple interface to manage the MCPWM
    modules on Microchip microcontrollers and this module implements the
    interrupts.
    
  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.
    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END
-->

<#if CONFIG_DRV_MCPWM_PRIMARY_SEVT_INTERRUPT_ENABLE == true >
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "ThreadX">
void __ISR(_PWM_PRI_VECTOR, ipl${CONFIG_DRV_MCPWM_PRIMARY_SEVT_INTERRUPT_PRIORITY_NUM}SOFT) _IntHandlerDrvMCPWMPrimarySpecialEvent(void)
<#else>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
void __attribute__( (interrupt(ipl${CONFIG_DRV_MCPWM_PRIMARY_SEVT_INTERRUPT_PRIORITY_NUM}AUTO), vector(_PWM_PRI_VECTOR))) IntHandlerDrvMCPWMPrimarySpecialEvent_ISR( void );
</#if>
void IntHandlerDrvMCPWMPrimarySpecialEvent(void)
</#if>
<#else>
void __ISR(_PWM_PRI_VECTOR, ipl${CONFIG_DRV_MCPWM_PRIMARY_SEVT_INTERRUPT_PRIORITY_NUM}AUTO) _IntHandlerDrvMCPWMPrimarySpecialEvent(void)
</#if>
{
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
    OS_EnterNestableInterrupt();
</#if>
</#if>
	/*Clear Primary Special Event Interrupt Flag*/
    PLIB_INT_SourceFlagClear(INT_ID_0, _PWM_PRI_VECTOR);
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
    OS_LeaveNestableInterrupt();
</#if>
</#if>
}
</#if>

<#if CONFIG_DRV_MCPWM_SECONDARY_SEVT_INTERRUPT_ENABLE == true >
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "ThreadX">
void __ISR(_PWM_SEC_VECTOR, ipl${CONFIG_DRV_MCPWM_SECONDARY_SEVT_INTERRUPT_PRIORITY_NUM}SOFT) _IntHandlerDrvMCPWMSecondarySpecialEvent(void)
<#else>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
void __attribute__( (interrupt(ipl${CONFIG_DRV_MCPWM_SECONDARY_SEVT_INTERRUPT_PRIORITY_NUM}AUTO), vector(_PWM_SEC_VECTOR))) IntHandlerDrvMCPWMSecondarySpecialEvent_ISR( void );
</#if>
void IntHandlerDrvMCPWMSecondarySpecialEvent(void)
</#if>
<#else>
void __ISR(_PWM_SEC_VECTOR, ipl${CONFIG_DRV_MCPWM_SECONDARY_SEVT_INTERRUPT_PRIORITY_NUM}AUTO) _IntHandlerDrvMCPWMSecondarySpecialEvent(void)
</#if>
{
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
    OS_EnterNestableInterrupt();
</#if>
</#if>
	/*Clear Secondary Special Event Interrupt Flag*/
    PLIB_INT_SourceFlagClear(INT_ID_0, _PWM_SEC_VECTOR);
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
    OS_LeaveNestableInterrupt();
</#if>
</#if>
}
</#if>




<#macro DRV_MCPWM_STATIC_FUNCTIONS MCPWM_CHANNEL_INSTANCE MCPWM_CHANNEL_INT_ENABLE MCPWM_CHANNEL_INT_PRIORITY MCPWM_CHANNEL_INT_VECTOR MCPWM_CHANNEL_INT_SOURCE>
<#if MCPWM_CHANNEL_INT_ENABLE == true>
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "ThreadX">
void __ISR(${MCPWM_CHANNEL_INT_VECTOR}, ipl${MCPWM_CHANNEL_INT_PRIORITY}SOFT) _IntHandlerDrvMCPWMChannelInstance${MCPWM_CHANNEL_INSTANCE}(void)
<#else>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
void __attribute__( (interrupt(ipl${MCPWM_CHANNEL_INT_PRIORITY}AUTO), vector(${MCPWM_CHANNEL_INT_VECTOR}))) IntHandlerDrvMCPWMChannelInstance${MCPWM_CHANNEL_INSTANCE}_ISR( void );
</#if>
void IntHandlerDrvMCPWMChannelInstance${MCPWM_CHANNEL_INSTANCE}(void)
</#if>
<#else>
void __ISR(${MCPWM_CHANNEL_INT_VECTOR}, ipl${MCPWM_CHANNEL_INT_PRIORITY}AUTO) _IntHandlerDrvMCPWMChannelInstance${MCPWM_CHANNEL_INSTANCE}(void)
</#if>
{
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
    OS_EnterNestableInterrupt();
</#if>
</#if>
	/*Clear PWM Channel Interrupt Flag*/
    PLIB_INT_SourceFlagClear(INT_ID_0, ${MCPWM_CHANNEL_INT_SOURCE});
<#if CONFIG_USE_3RDPARTY_RTOS>
<#if CONFIG_3RDPARTY_RTOS_USED == "embOS">
    OS_LeaveNestableInterrupt();
</#if>
</#if>
}
</#if>
</#macro>

<#if CONFIG_DRV_MCPWM_INST_IDX0 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX0 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX0
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX0
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX0
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX0/>
</#if>
<#if CONFIG_DRV_MCPWM_INST_IDX1 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX1 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX1
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX1
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX1
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX1/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX2 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX2 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX2
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX2
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX2
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX2/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX3 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX3 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX3
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX3
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX3
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX3/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX4 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX4 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX4
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX4
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX4
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX4/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX5 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX5 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX5
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX5
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX5
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX5/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX6 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX6
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX6 
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX6
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX6
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX6/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX7 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX7 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX7
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX7
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX7
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX7/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX8 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX8 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX8
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX8
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX8
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX8/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX9 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX9 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX9
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX9
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX9
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX9/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX10 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX10 
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX10
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX10
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX10
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX10/>
</#if>

<#if CONFIG_DRV_MCPWM_INST_IDX11 == true>
<@DRV_MCPWM_STATIC_FUNCTIONS 
MCPWM_CHANNEL_INSTANCE=CONFIG_DRV_MCPWM_CHANNEL_ID_IDX11
MCPWM_CHANNEL_INT_ENABLE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_ENABLE_IDX11 
MCPWM_CHANNEL_INT_PRIORITY = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_PRIORITY_NUM_IDX11
MCPWM_CHANNEL_INT_VECTOR = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_VECTOR_IDX11
MCPWM_CHANNEL_INT_SOURCE = CONFIG_DRV_MCPWM_CHANNEL_INTERRUPT_SOURCE_IDX11/>
</#if>




<#--
/*******************************************************************************
 End of File
*/
-->
