/*******************************************************************************
  POWER Peripheral Library Template Implementation

  File Name:
    power_HLVDLimitSelection_Default.h

  Summary:
    POWER PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : HLVDLimitSelection
    and its Variant : Default
    For following APIs :
        PLIB_POWER_ExistsHLVDLimitSelection
        PLIB_POWER_HLVDLimitSelect

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

#ifndef _POWER_HLVDLIMITSELECTION_DEFAULT_H
#define _POWER_HLVDLIMITSELECTION_DEFAULT_H

//******************************************************************************
/* Function :  POWER_ExistsHLVDLimitSelection_Default

  Summary:
    Implements Default variant of PLIB_POWER_ExistsHLVDLimitSelection

  Description:
    This template implements the Default variant of the PLIB_POWER_ExistsHLVDLimitSelection function.
*/

#define PLIB_POWER_ExistsHLVDLimitSelection PLIB_POWER_ExistsHLVDLimitSelection
PLIB_TEMPLATE bool POWER_ExistsHLVDLimitSelection_Default( POWER_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  POWER_HLVDLimitSelect_Default

  Summary:
    Implements Default variant of PLIB_POWER_HLVDLimitSelect 

  Description:
    This template implements the Default variant of the PLIB_POWER_HLVDLimitSelect function.
*/

PLIB_TEMPLATE void POWER_HLVDLimitSelect_Default( POWER_MODULE_ID index , HLVD_LIMIT limit )
{
    HLVDCONbits.HLVDL = limit;
}


#endif /*_POWER_HLVDLIMITSELECTION_DEFAULT_H*/

/******************************************************************************
 End of File
*/

