/*******************************************************************************
  MCPWM Peripheral Library Template Implementation

  File Name:
    mcpwm_SecondarySpecialEventTrigger_Default.h

  Summary:
    MCPWM PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SecondarySpecialEventTrigger
    and its Variant : Default
    For following APIs :
        PLIB_MCPWM_SecondarySpecialEventTriggerSetup
        PLIB_MCPWM_SecondarySpecialEventTriggerInterruptIsPending
        PLIB_MCPWM_SecondarySpecialEventTriggerInterruptEnable
        PLIB_MCPWM_SecondarySpecialEventTriggerInterruptDisable
        PLIB_MCPWM_ExistsSecondarySpecialEventTrigger

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _MCPWM_SECONDARYSPECIALEVENTTRIGGER_DEFAULT_H
#define _MCPWM_SECONDARYSPECIALEVENTTRIGGER_DEFAULT_H
#include "mcpwm_registers.h"

//******************************************************************************
/* Function :  MCPWM_SecondarySpecialEventTriggerSetup_Default

  Summary:
    Implements Default variant of PLIB_MCPWM_SecondarySpecialEventTriggerSetup 

  Description:
    This template implements the Default variant of the PLIB_MCPWM_SecondarySpecialEventTriggerSetup function.
*/

PLIB_TEMPLATE void MCPWM_SecondarySpecialEventTriggerSetup_Default( MCPWM_MODULE_ID index , uint16_t compare_value , MCPWM_TRIGGER_DIVIDER postscaler_value )
{
    volatile mcpwm_module_registers_t *module_regs = (mcpwm_module_registers_t *)index;
    module_regs->SEVTCMP = compare_value;
	module_regs->STCON.SEVTPS = postscaler_value;
}


//******************************************************************************
/* Function :  MCPWM_SecondarySpecialEventTriggerInterruptIsPending_Default

  Summary:
    Implements Default variant of PLIB_MCPWM_SecondarySpecialEventTriggerInterruptIsPending 

  Description:
    This template implements the Default variant of the PLIB_MCPWM_SecondarySpecialEventTriggerInterruptIsPending function.
*/

PLIB_TEMPLATE bool MCPWM_SecondarySpecialEventTriggerInterruptIsPending_Default( MCPWM_MODULE_ID index )
{
     volatile mcpwm_module_registers_t *module_regs = (mcpwm_module_registers_t *)index;
	if(module_regs->STCON.SSESTAT == 0b1)
		return true;
	else
		return false;
}


//******************************************************************************
/* Function :  MCPWM_SecondarySpecialEventTriggerInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_MCPWM_SecondarySpecialEventTriggerInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_MCPWM_SecondarySpecialEventTriggerInterruptEnable function.
*/

PLIB_TEMPLATE void MCPWM_SecondarySpecialEventTriggerInterruptEnable_Default( MCPWM_MODULE_ID index )
{
      volatile mcpwm_module_registers_t *module_regs = (mcpwm_module_registers_t *)index;
	module_regs->STCONSET = _STCON_SSEIEN_MASK;
}


//******************************************************************************
/* Function :  MCPWM_SecondarySpecialEventTriggerInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_MCPWM_SecondarySpecialEventTriggerInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_MCPWM_SecondarySpecialEventTriggerInterruptDisable function.
*/

PLIB_TEMPLATE void MCPWM_SecondarySpecialEventTriggerInterruptDisable_Default( MCPWM_MODULE_ID index )
{
    volatile mcpwm_module_registers_t *module_regs = (mcpwm_module_registers_t *)index;
	module_regs->STCONCLR = _STCON_SSEIEN_MASK;
}


//******************************************************************************
/* Function :  MCPWM_ExistsSecondarySpecialEventTrigger_Default

  Summary:
    Implements Default variant of PLIB_MCPWM_ExistsSecondarySpecialEventTrigger

  Description:
    This template implements the Default variant of the PLIB_MCPWM_ExistsSecondarySpecialEventTrigger function.
*/

#define PLIB_MCPWM_ExistsSecondarySpecialEventTrigger PLIB_MCPWM_ExistsSecondarySpecialEventTrigger
PLIB_TEMPLATE bool MCPWM_ExistsSecondarySpecialEventTrigger_Default( MCPWM_MODULE_ID index )
{
    return true;
}


#endif /*_MCPWM_SECONDARYSPECIALEVENTTRIGGER_DEFAULT_H*/

/******************************************************************************
 End of File
*/

