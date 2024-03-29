/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_InterruptMode_Default.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InterruptMode
    and its Variant : Default
    For following APIs :
        PLIB_PMP_ExistsInterruptMode
        PLIB_PMP_InterruptModeSelect

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PMP_INTERRUPTMODE_DEFAULT_H
#define _PMP_INTERRUPTMODE_DEFAULT_H

//******************************************************************************
/* Function :  PMP_ExistsInterruptMode_Default

  Summary:
    Implements Default variant of PLIB_PMP_ExistsInterruptMode

  Description:
    This template implements the Default variant of the PLIB_PMP_ExistsInterruptMode function.
*/
#define PLIB_PMP_ExistsInterruptMode PLIB_PMP_ExistsInterruptMode
PLIB_TEMPLATE bool PMP_ExistsInterruptMode_Default( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_InterruptModeSelect_Default

  Summary:
    Implements Default variant of PLIB_PMP_InterruptModeSelect 

  Description:
    This template implements the Default variant of the PLIB_PMP_InterruptModeSelect function.
*/
PLIB_TEMPLATE void PMP_InterruptModeSelect_Default( PMP_MODULE_ID index , PMP_INTERRUPT_MODE interruptMode )
{
    PMMODEbits.IRQM = interruptMode;
}

//******************************************************************************
/* Function :  PMP_InterruptModeGet_Default

  Summary:
    Implements Default variant of PLIB_PMP_InterruptModeGet

  Description:
    This template implements the Default variant of the PLIB_PMP_InterruptModeGet function.
*/
PLIB_TEMPLATE PMP_INTERRUPT_MODE PMP_InterruptModeGet_Default( PMP_MODULE_ID index )
{
    return (PMP_INTERRUPT_MODE) (((PMMODE) & (_PMMODE_IRQM_MASK)) >> (_PMMODE_IRQM_POSITION));
}

#endif /*_PMP_INTERRUPTMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

