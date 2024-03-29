/*******************************************************************************
  SB Peripheral Library Template Implementation

  File Name:
    sb_PGVErrStatus_PIC32_DA.h

  Summary:
    SB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PGVErrStatus
    and its Variant : PIC32_DA
    For following APIs :
        PLIB_SB_ExistsPGVErrStatus
        PLIB_SB_PGVErrorStatus

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

#ifndef _SB_PGVERRSTATUS_PIC32_DA_H
#define _SB_PGVERRSTATUS_PIC32_DA_H

//******************************************************************************
/* Function :  SB_ExistsPGVErrStatus_PIC32_DA

  Summary:
    Implements PIC32_DA variant of PLIB_SB_ExistsPGVErrStatus

  Description:
    This template implements the PIC32_DA variant of the PLIB_SB_ExistsPGVErrStatus function.
*/
#define PLIB_SB_ExistsPGVErrStatus PLIB_SB_ExistsPGVErrStatus
PLIB_TEMPLATE bool SB_ExistsPGVErrStatus_PIC32_DA( SB_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  SB_PGVErrorStatus_PIC32_DA

  Summary:
    Implements PIC32_DA variant of PLIB_SB_PGVErrorStatus 

  Description:
    This template implements the PIC32_DA variant of the PLIB_SB_PGVErrorStatus function.
    This operation is atomic.
*/
PLIB_TEMPLATE bool SB_PGVErrorStatus_PIC32_DA( SB_MODULE_ID index , PLIB_SB_TGT_ID target )
{
    volatile uint32_t *SBFLAGx = (volatile uint32_t *)(&SBFLAG0 + (0x10000u * target / 32u) / 4u);

    return (bool)((*SBFLAGx >> (target % 32u)) & 0x1u);
}

#endif /*_SB_PGVERRSTATUS_PIC32_DA_H*/

/******************************************************************************
 End of File
*/
