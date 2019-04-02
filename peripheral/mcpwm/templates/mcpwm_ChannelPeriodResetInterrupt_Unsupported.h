/*******************************************************************************
  MCPWM Peripheral Library Template Implementation

  File Name:
    mcpwm_ChannelPeriodResetInterrupt_Unsupported.h

  Summary:
    MCPWM PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChannelPeriodResetInterrupt
    and its Variant : Unsupported
    For following APIs :
        PLIB_MCPWM_ChannelPeriodResetInterruptIsPending
		PLIB_MCPWM_ChannelPeriodResetInterruptIsEnabled
        PLIB_MCPWM_ChannelPeriodResetInterruptFlagClear
        PLIB_MCPWM_ChannelPeriodResetInterruptEnable
        PLIB_MCPWM_ChannelPeriodResetInterruptDisable
        PLIB_MCPWM_ExistsChannelPeriodResetInterrupt

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

#ifndef _MCPWM_CHANNELPERIODRESETINTERRUPT_UNSUPPORTED_H
#define _MCPWM_CHANNELPERIODRESETINTERRUPT_UNSUPPORTED_H

//******************************************************************************
/* Function :  MCPWM_ChannelPeriodResetInterruptIsPending_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_MCPWM_ChannelPeriodResetInterruptIsPending 

  Description:
    This template implements the Unsupported variant of the PLIB_MCPWM_ChannelPeriodResetInterruptIsPending function.
*/

PLIB_TEMPLATE bool MCPWM_ChannelPeriodResetInterruptIsPending_Unsupported( MCPWM_MODULE_ID index , MCPWM_CHANNEL_ID channel )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_MCPWM_ChannelPeriodResetInterruptIsPending");

    return false;
}

//******************************************************************************
/* Function :  MCPWM_ChannelPeriodResetInterruptIsEnabled_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_MCPWM_ChannelPeriodResetInterruptIsEnabled 

  Description:
    This template implements the Unsupported variant of the PLIB_MCPWM_ChannelPeriodResetInterruptIsEnabled function.
*/

PLIB_TEMPLATE bool MCPWM_ChannelPeriodResetInterruptIsEnabled_Unsupported( MCPWM_MODULE_ID index , MCPWM_CHANNEL_ID channel )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_MCPWM_ChannelPeriodResetInterruptIsEnabled");

    return false;
}


//******************************************************************************
/* Function :  MCPWM_ChannelPeriodResetInterruptFlagClear_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_MCPWM_ChannelPeriodResetInterruptFlagClear 

  Description:
    This template implements the Unsupported variant of the PLIB_MCPWM_ChannelPeriodResetInterruptFlagClear function.
*/

PLIB_TEMPLATE void MCPWM_ChannelPeriodResetInterruptFlagClear_Unsupported( MCPWM_MODULE_ID index , MCPWM_CHANNEL_ID channel )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_MCPWM_ChannelPeriodResetInterruptFlagClear");
}


//******************************************************************************
/* Function :  MCPWM_ChannelPeriodResetInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_MCPWM_ChannelPeriodResetInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_MCPWM_ChannelPeriodResetInterruptEnable function.
*/

PLIB_TEMPLATE void MCPWM_ChannelPeriodResetInterruptEnable_Unsupported( MCPWM_MODULE_ID index , MCPWM_CHANNEL_ID channel )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_MCPWM_ChannelPeriodResetInterruptEnable");
}


//******************************************************************************
/* Function :  MCPWM_ChannelPeriodResetInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_MCPWM_ChannelPeriodResetInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_MCPWM_ChannelPeriodResetInterruptDisable function.
*/

PLIB_TEMPLATE void MCPWM_ChannelPeriodResetInterruptDisable_Unsupported( MCPWM_MODULE_ID index , MCPWM_CHANNEL_ID channel )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_MCPWM_ChannelPeriodResetInterruptDisable");
}


//******************************************************************************
/* Function :  MCPWM_ExistsChannelPeriodResetInterrupt_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_MCPWM_ExistsChannelPeriodResetInterrupt

  Description:
    This template implements the Unsupported variant of the PLIB_MCPWM_ExistsChannelPeriodResetInterrupt function.
*/

PLIB_TEMPLATE bool MCPWM_ExistsChannelPeriodResetInterrupt_Unsupported( MCPWM_MODULE_ID index )
{
    return false;
}


#endif /*_MCPWM_CHANNELPERIODRESETINTERRUPT_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

