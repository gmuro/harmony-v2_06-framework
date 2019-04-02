/*******************************************************************************
  BMX Peripheral Library Template Implementation

  File Name:
    bmx_BusExceptionData_Unsupported.h

  Summary:
    BMX PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BusExceptionData
    and its Variant : Unsupported
    For following APIs :
        PLIB_BMX_ExistsBusExceptionData
        PLIB_BMX_BusExceptionDataEnable
        PLIB_BMX_BusExceptionDataDisable

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

#ifndef _BMX_BUSEXCEPTIONDATA_UNSUPPORTED_H
#define _BMX_BUSEXCEPTIONDATA_UNSUPPORTED_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    None.

  MASKs: 
    None.

  POSs: 
    None.

  LENs: 
    None.

*/


//******************************************************************************
/* Function :  BMX_ExistsBusExceptionData_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_BMX_ExistsBusExceptionData

  Description:
    This template implements the Unsupported variant of the PLIB_BMX_ExistsBusExceptionData function.
*/

PLIB_TEMPLATE bool BMX_ExistsBusExceptionData_Unsupported( BMX_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  BMX_BusExceptionDataEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_BMX_BusExceptionDataEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_BMX_BusExceptionDataEnable function.
*/

PLIB_TEMPLATE void BMX_BusExceptionDataEnable_Unsupported( BMX_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_BMX_BusExceptionDataEnable");
}


//******************************************************************************
/* Function :  BMX_BusExceptionDataDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_BMX_BusExceptionDataDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_BMX_BusExceptionDataDisable function.
*/

PLIB_TEMPLATE void BMX_BusExceptionDataDisable_Unsupported( BMX_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_BMX_BusExceptionDataDisable");
}


#endif /*_BMX_BUSEXCEPTIONDATA_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

