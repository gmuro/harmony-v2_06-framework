/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerBaseAddress_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerBaseAddress
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLayerBaseAddress
        PLIB_GLCD_LayerBaseAddressSet
        PLIB_GLCD_LayerBaseAddressGet

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

#ifndef _GLCD_LAYERBASEADDRESS_DEFAULT_H
#define _GLCD_LAYERBASEADDRESS_DEFAULT_H

#include <sys/kmem.h>
//******************************************************************************
/* Function :  GLCD_ExistsLayerBaseAddress_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerBaseAddress

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerBaseAddress function.
*/
#define PLIB_GLCD_ExistsLayerBaseAddress PLIB_GLCD_ExistsLayerBaseAddress
PLIB_TEMPLATE bool GLCD_ExistsLayerBaseAddress_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerBaseAddressSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerBaseAddressSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerBaseAddressSet function.
*/
PLIB_TEMPLATE void GLCD_LayerBaseAddressSet_Default( GLCD_MODULE_ID index , 
                                                     GLCD_LAYER_ID  layerId , 
                                                     uint32_t       baseAddress )
{
	*((SFR_TYPE *)(( (&GLCDL0BADDR) + ( layerId * 8 ) )))  =  ( KVA_TO_PA( (void *) baseAddress) );
}

//******************************************************************************
/* Function :  GLCD_LayerBaseAddressGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerBaseAddressGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerBaseAddressGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerBaseAddressGet_Default( GLCD_MODULE_ID index , 
                                                         GLCD_LAYER_ID  layerId )
{
	return ( *((SFR_TYPE *)(( (&GLCDL0BADDR) + ( layerId * 8 ) ))) );
}

#endif /*_GLCD_LAYERBASEADDRESS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

