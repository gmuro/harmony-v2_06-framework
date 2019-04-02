/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogInputCheck_pic32wk.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogInputCheck
    and its Variant : pic32wk
    For following APIs :
        PLIB_ADCHS_AnalogInputIsAvailable
        PLIB_ADCHS_ExistsAnalogInputCheck

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

#ifndef _ADCHS_ANALOGINPUTCHECK_PIC32WK_H
#define _ADCHS_ANALOGINPUTCHECK_PIC32WK_H



//******************************************************************************
/* Function :  ADCHS_AnalogInputIsAvailable_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_AnalogInputIsAvailable 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_AnalogInputIsAvailable function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputIsAvailable_pic32wk( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)(regs->ADCSYSCFGx[analogInput / 32] & BIT(analogInput % 32));
}


//******************************************************************************
/* Function :  ADCHS_ExistsAnalogInputCheck_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ExistsAnalogInputCheck

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ExistsAnalogInputCheck function.
*/

#define PLIB_ADCHS_ExistsAnalogInputCheck PLIB_ADCHS_ExistsAnalogInputCheck
PLIB_TEMPLATE bool ADCHS_ExistsAnalogInputCheck_pic32wk( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_ANALOGINPUTCHECK_PIC32WK_H*/

/******************************************************************************
 End of File
*/

