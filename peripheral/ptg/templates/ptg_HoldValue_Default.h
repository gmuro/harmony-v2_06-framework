/*******************************************************************************
  PTG Peripheral Library Template Implementation

  File Name:
    ptg_HoldValue_Default.h

  Summary:
    PTG PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : HoldValue
    and its Variant : Default
    For following APIs :
        PLIB_PTG_HoldValueSet
        PLIB_PTG_HoldValueGet
        PLIB_PTG_ExistsHoldValue

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

#ifndef _PTG_HOLDVALUE_DEFAULT_H
#define _PTG_HOLDVALUE_DEFAULT_H

//******************************************************************************
/* Function :  PTG_HoldValueSet_Default

  Summary:
    Implements Default variant of PLIB_PTG_HoldValueSet 

  Description:
    This template implements the Default variant of the PLIB_PTG_HoldValueSet function.
*/

PLIB_TEMPLATE void PTG_HoldValueSet_Default( PTG_MODULE_ID index , uint16_t holdValue )
{
	PTGHOLD = (holdValue & 0xFFFF);
}


//******************************************************************************
/* Function :  PTG_HoldValueGet_Default

  Summary:
    Implements Default variant of PLIB_PTG_HoldValueGet 

  Description:
    This template implements the Default variant of the PLIB_PTG_HoldValueGet function.
*/

PLIB_TEMPLATE uint16_t PTG_HoldValueGet_Default( PTG_MODULE_ID index )
{
	return (PTGHOLD & 0xFFFF);
}


//******************************************************************************
/* Function :  PTG_ExistsHoldValue_Default

  Summary:
    Implements Default variant of PLIB_PTG_ExistsHoldValue

  Description:
    This template implements the Default variant of the PLIB_PTG_ExistsHoldValue function.
*/

#define PLIB_PTG_ExistsHoldValue PLIB_PTG_ExistsHoldValue
PLIB_TEMPLATE bool PTG_ExistsHoldValue_Default( PTG_MODULE_ID index )
{
    return true;
}


#endif /*_PTG_HOLDVALUE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

