/*******************************************************************************
  EBI Peripheral Library Template Implementation

  File Name:
    ebi_ReadyPin2Config_Unsupported.h

  Summary:
    EBI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ReadyPin2Config
    and its Variant : Unsupported
    For following APIs :
        PLIB_EBI_ReadyPin2ConfigSet
        PLIB_EBI_ExistsReadyPin2Config

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

#ifndef _EBI_READYPIN2CONFIG_UNSUPPORTED_H
#define _EBI_READYPIN2CONFIG_UNSUPPORTED_H

//******************************************************************************
/* Function :  EBI_ReadyPin2ConfigSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_EBI_ReadyPin2ConfigSet 

  Description:
    This template implements the Unsupported variant of the PLIB_EBI_ReadyPin2ConfigSet function.
*/

PLIB_TEMPLATE void EBI_ReadyPin2ConfigSet_Unsupported( EBI_MODULE_ID index , bool ReadyPin2Enable , bool ReadyPin2Invert )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_EBI_ReadyPin2ConfigSet");
}


//******************************************************************************
/* Function :  EBI_ExistsReadyPin2Config_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_EBI_ExistsReadyPin2Config

  Description:
    This template implements the Unsupported variant of the PLIB_EBI_ExistsReadyPin2Config function.
*/

PLIB_TEMPLATE bool EBI_ExistsReadyPin2Config_Unsupported( EBI_MODULE_ID index )
{
    return false;
}


#endif /*_EBI_READYPIN2CONFIG_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

