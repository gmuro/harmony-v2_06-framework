<#--
/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

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
<#if !(DRV_TOUCH_GENERIC_TASKS?has_content)>
<#assign DRV_TOUCH_GENERIC_TASKS = "TASK_CALL_NO_RTOS">
</#if>
<#if (DRV_TOUCH_GENERIC_TASKS == "PROTO") && (CONFIG_DRV_TOUCH_GENERIC_RTOS == "Standalone")>
<#if CONFIG_3RDPARTY_RTOS_USED == "ThreadX">
void _DRV_TOUCH_GENERIC_Tasks(ULONG thread_input);
<#else>
void _DRV_TOUCH_GENERIC_Tasks(void);
</#if>
</#if>
<#if DRV_TOUCH_GENERIC_TASKS == "CREATE_TASK">
 <#if CONFIG_DRV_TOUCH_GENERIC_RTOS == "Standalone">
 
    /* Create task for gfx state machine*/
<@RTOS_TASK_CREATE RTOS_NAME=CONFIG_3RDPARTY_RTOS_USED TASK_FUNC_NAME="_DRV_TOUCH_GENERIC_Tasks"
TASK_NAME="DRV_TOUCH_GENERIC Tasks" TASK_PRI=CONFIG_DRV_TOUCH_GENERIC_RTOS_TASK_PRIORITY
TASK_STK_SZ=CONFIG_DRV_TOUCH_GENERIC_RTOS_TASK_SIZE/>		
 </#if>
</#if>
<#if (DRV_TOUCH_GENERIC_TASKS == "TASK_CALL_NO_RTOS") || (DRV_TOUCH_GENERIC_TASKS == "TASK_CALL" && CONFIG_DRV_TOUCH_GENERIC_RTOS != "Standalone")>
    DRV_TOUCH_GENERIC_Tasks(sysObj.drvTouchgeneric);
</#if>
<#if DRV_TOUCH_GENERIC_TASKS == "LOCAL_FUNCTION">
 <#if CONFIG_DRV_TOUCH_GENERIC_RTOS == "Standalone">
<#if CONFIG_3RDPARTY_RTOS_USED == "ThreadX">
void _DRV_TOUCH_GENERIC_Tasks(ULONG thread_input)
<#else>
void _DRV_TOUCH_GENERIC_Tasks(void)
</#if>
{
<#if CONFIG_3RDPARTY_RTOS_USED == "uC/OS-III">
    OS_ERR os_err;
	
</#if> 
    while(1)
    {
        DRV_TOUCH_GENERIC_Tasks(sysObj.drvTouchgeneric);
<@RTOS_TASK_DELAY RTOS_NAME=CONFIG_3RDPARTY_RTOS_USED TASK_DELAY=CONFIG_SYS_DEVCON_RTOS_DELAY/>		
    }
}
 </#if>
</#if>

<#--
/*******************************************************************************
 End of File
*/
-->
