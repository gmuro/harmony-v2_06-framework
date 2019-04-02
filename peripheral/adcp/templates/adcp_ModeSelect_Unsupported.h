/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_ModeSelect_Unsupported.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ModeSelect
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCP_SHModeSelect
        PLIB_ADCP_ExistsModeSelect

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

#ifndef _ADCP_MODESELECT_UNSUPPORTED_H
#define _ADCP_MODESELECT_UNSUPPORTED_H

//******************************************************************************
/* Function :  ADCP_SHModeSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_SHModeSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_SHModeSelect function.
*/

PLIB_TEMPLATE void ADCP_SHModeSelect_Unsupported( ADCP_MODULE_ID index , ADCP_DSH_ID id , ADCP_SH_MODE mode )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_SHModeSelect");
}


//******************************************************************************
/* Function :  ADCP_ExistsModeSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_ExistsModeSelect

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_ExistsModeSelect function.
*/

PLIB_TEMPLATE bool ADCP_ExistsModeSelect_Unsupported( ADCP_MODULE_ID index )
{
    return false;
}


#endif /*_ADCP_MODESELECT_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

