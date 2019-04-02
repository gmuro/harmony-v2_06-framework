/*******************************************************************************
  PTG Peripheral Library Template Implementation

  File Name:
    ptg_PTGBusyStatus_Default.h

  Summary:
    PTG PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PTGBusyStatus
    and its Variant : Default
    For following APIs :
        PLIB_PTG_IsBusy
        PLIB_PTG_ExistsPTGBusyStatus

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

#ifndef _PTG_PTGBUSYSTATUS_DEFAULT_H
#define _PTG_PTGBUSYSTATUS_DEFAULT_H

//******************************************************************************
/* Function :  PTG_IsBusy_Default

  Summary:
    Implements Default variant of PLIB_PTG_IsBusy 

  Description:
    This template implements the Default variant of the PLIB_PTG_IsBusy function.
*/

PLIB_TEMPLATE bool PTG_IsBusy_Default( PTG_MODULE_ID index )
{
	return (bool) PTGCONbits.PTGBUSY;
}


//******************************************************************************
/* Function :  PTG_ExistsPTGBusyStatus_Default

  Summary:
    Implements Default variant of PLIB_PTG_ExistsPTGBusyStatus

  Description:
    This template implements the Default variant of the PLIB_PTG_ExistsPTGBusyStatus function.
*/

#define PLIB_PTG_ExistsPTGBusyStatus PLIB_PTG_ExistsPTGBusyStatus
PLIB_TEMPLATE bool PTG_ExistsPTGBusyStatus_Default( PTG_MODULE_ID index )
{
    return true;
}


#endif /*_PTG_PTGBUSYSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

