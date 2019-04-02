/*******************************************************************************
  OC Peripheral Library Template Implementation

  File Name:
    oc_FaultInput_Default.h

  Summary:
    OC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FaultInput
    and its Variant : Default
    For following APIs :
        PLIB_OC_FaultInputSelect
        PLIB_OC_ExistsFaultInput

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

#ifndef _OC_FAULTINPUT_DEFAULT_H
#define _OC_FAULTINPUT_DEFAULT_H

#include "oc_Registers.h"

//******************************************************************************
/* Function :  OC_FaultInputSelect_Default

  Summary:
    Implements Default variant of PLIB_OC_FaultInputSelect 

  Description:
    This template implements the Default variant of the PLIB_OC_FaultInputSelect function.
*/

PLIB_TEMPLATE void OC_FaultInputSelect_Default( OC_MODULE_ID index , OC_FAULTS flt )
{
    volatile oc_register_t *regs = (volatile oc_register_t *)index;

    regs->OCxCON.OCM = flt;
}


//******************************************************************************
/* Function :  OC_ExistsFaultInput_Default

  Summary:
    Implements Default variant of PLIB_OC_ExistsFaultInput

  Description:
    This template implements the Default variant of the PLIB_OC_ExistsFaultInput function.
*/

#define PLIB_OC_ExistsFaultInput PLIB_OC_ExistsFaultInput
PLIB_TEMPLATE bool OC_ExistsFaultInput_Default( OC_MODULE_ID index )
{
    return true;
}


#endif /*_OC_FAULTINPUT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

