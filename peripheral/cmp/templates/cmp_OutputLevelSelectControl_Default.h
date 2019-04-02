/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_OutputLevelSelectControl_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OutputLevelSelectControl
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsOutputLevelControl
        PLIB_CMP_OutputLogicHigh
        PLIB_CMP_OutputLogicLow

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

#ifndef _CMP_OUTPUTLEVELSELECTCONTROL_DEFAULT_H
#define _CMP_OUTPUTLEVELSELECTCONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _CMP_CMP_OUTPUT_LEVEL_CONTROL_VREG(index)

  MASKs:
    _CMP_CMP_OUTPUT_LEVEL_CONTROL_MASK(index)

  POSs:
    _CMP_CMP_OUTPUT_LEVEL_CONTROL_POS(index)

  LENs:
    _CMP_CMP_OUTPUT_LEVEL_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  CMP_ExistsOutputLevelControl_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsOutputLevelControl

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsOutputLevelControl function.
*/

#define PLIB_CMP_ExistsOutputLevelControl PLIB_CMP_ExistsOutputLevelControl
PLIB_TEMPLATE bool CMP_ExistsOutputLevelControl_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_OutputLogicHigh_Default

  Summary:
    Implements Default variant of PLIB_CMP_OutputLogicHigh

  Description:
    This template implements the Default variant of the PLIB_CMP_OutputLogicHigh function.
*/

PLIB_TEMPLATE void CMP_OutputLogicHigh_Default( CMP_MODULE_ID index )
{
    _SFR_BIT_SET( _CMP_CMP_OUTPUT_LEVEL_CONTROL_VREG(index),
    	_CMP_CMP_OUTPUT_LEVEL_CONTROL_POS(index) );
}


//******************************************************************************
/* Function :  CMP_OutputLogicLow_Default

  Summary:
    Implements Default variant of PLIB_CMP_OutputLogicLow

  Description:
    This template implements the Default variant of the PLIB_CMP_OutputLogicLow function.
*/

PLIB_TEMPLATE void CMP_OutputLogicLow_Default( CMP_MODULE_ID index )
{
    _SFR_BIT_CLEAR( _CMP_CMP_OUTPUT_LEVEL_CONTROL_VREG(index),
    	_CMP_CMP_OUTPUT_LEVEL_CONTROL_POS(index));
}


#endif /*_CMP_OUTPUTLEVELSELECTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

