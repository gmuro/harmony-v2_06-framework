/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalComparator_pic32mk.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalComparator
    and its Variant : pic32mk
    For following APIs :
        PLIB_ADCHS_DigitalComparatorAnalogInputSelect
        PLIB_ADCHS_DigitalComparatorAnalogInputGet
        PLIB_ADCHS_DigitalComparatorEnable
        PLIB_ADCHS_DigitalComparatorDisable
        PLIB_ADCHS_DigitalComparatorInterruptEnable
        PLIB_ADCHS_DigitalComparatorInterruptDisable
        PLIB_ADCHS_DigitalComparatorSetup
        PLIB_ADCHS_DigitalComparatorEventHasOccurred
        PLIB_ADCHS_DigitalComparatorLimitSet
        PLIB_ADCHS_ExistsDigitalComparator

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

#ifndef _ADCHS_DIGITALCOMPARATOR_PIC32MK_H
#define _ADCHS_DIGITALCOMPARATOR_PIC32MK_H



//******************************************************************************
/* Function :  ADCHS_DigitalComparatorAnalogInputSelect_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorAnalogInputSelect 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorAnalogInputSelect function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorAnalogInputSelect_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->adccmpx[digComparator].ADCCMPEN.set = BIT(analogInput);   
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorAnalogInputGet_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorAnalogInputGet 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorAnalogInputGet function.
    Operation is atomic.
*/

PLIB_TEMPLATE ADCHS_AN_INPUT_ID ADCHS_DigitalComparatorAnalogInputGet_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

     return regs->ADCCMPCONx[digComparator].bits.AINID;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorEnable_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorEnable 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorEnable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorEnable_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCMPCONx[digComparator].bits.ENDCMP = 1;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorDisable_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorDisable 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorDisable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorDisable_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCMPCONx[digComparator].bits.ENDCMP = 0;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorInterruptEnable_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorInterruptEnable 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorInterruptEnable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorInterruptEnable_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCMPCONx[digComparator].bits.DCMPGIEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorInterruptDisable_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorInterruptDisable 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorInterruptDisable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorInterruptDisable_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCMPCONx[digComparator].bits.DCMPGIEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorSetup_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorSetup 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorSetup function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorSetup_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id , bool intEnable , bool inBetweenOrEqual , bool greaterEqualHi , bool lessThanHi , bool greaterEqualLo , bool lessThanLo , ADCHS_AN_INPUT_ID analogInput , int16_t  hiLimit , int16_t  loLimit )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCMPCONx[id].bits.IELOLO = lessThanLo;
    regs->ADCCMPCONx[id].bits.IELOHI = greaterEqualLo;
    regs->ADCCMPCONx[id].bits.IEHILO = lessThanHi;
    regs->ADCCMPCONx[id].bits.IEHIHI = greaterEqualHi;
    regs->ADCCMPCONx[id].bits.IEBTWN = inBetweenOrEqual;
    regs->ADCCMPCONx[id].bits.DCMPGIEN = intEnable;

    regs->adccmpx[id].ADCCMPEN.set = BIT(analogInput);
    regs->adccmpx[id].ADCCMP.bits = ((uint32_t)(hiLimit << 16) | loLimit);
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorEventHasOccurred_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorEventHasOccurred 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorEventHasOccurred function.
    Operation is not atomic.
*/

PLIB_TEMPLATE bool ADCHS_DigitalComparatorEventHasOccurred_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)regs->ADCCMPCONx[id].bits.DCMPED;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorLimitSet_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_DigitalComparatorLimitSet 

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_DigitalComparatorLimitSet function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorLimitSet_pic32mk( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id , int16_t  hiLimit , int16_t  loLimit )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->adccmpx[id].ADCCMP.bits = ((uint32_t)(hiLimit << 16) | loLimit);
}


//******************************************************************************
/* Function :  ADCHS_ExistsDigitalComparator_pic32mk

  Summary:
    Implements pic32mk variant of PLIB_ADCHS_ExistsDigitalComparator

  Description:
    This template implements the pic32mk variant of the PLIB_ADCHS_ExistsDigitalComparator function.
*/

#define PLIB_ADCHS_ExistsDigitalComparator PLIB_ADCHS_ExistsDigitalComparator
PLIB_TEMPLATE bool ADCHS_ExistsDigitalComparator_pic32mk( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DIGITALCOMPARATOR_PIC32MK_H*/

/******************************************************************************
 End of File
*/

