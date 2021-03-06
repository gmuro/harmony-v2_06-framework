/*******************************************************************************
  CTMU Peripheral Library Template Implementation

  File Name:
    ctmu_EdgeStatus_Default.h

  Summary:
    CTMU PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EdgeStatus
    and its Variant : Default
    For following APIs :
        PLIB_CTMU_EdgeIsSet
        PLIB_CTMU_EdgeSet
        PLIB_CTMU_ExistsEdgeStatus

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

#ifndef _CTMU_EDGESTATUS_DEFAULT_H
#define _CTMU_EDGESTATUS_DEFAULT_H

#include "ctmu_registers.h"

//******************************************************************************
/* Function :  CTMU_EdgeIsSet_Default

  Summary:
    Implements Default variant of PLIB_CTMU_EdgeIsSet

  Description:
    This template implements the Default variant of the PLIB_CTMU_EdgeIsSet function.
*/

PLIB_TEMPLATE bool CTMU_EdgeIsSet_Default( CTMU_MODULE_ID index , CTMU_EDGE_SELECT edgeNumber )
{
    volatile ctmu_registers_t *ctmu = ((ctmu_registers_t *)(index));	
    if ( edgeNumber == CTMU_EDGE1 )
    {
		return ctmu->CTMUCON.EDG1STAT;
    }
    else
    {
		return ctmu->CTMUCON.EDG2STAT;
    }
}


//******************************************************************************
/* Function :  CTMU_EdgeSet_Default

  Summary:
    Implements Default variant of PLIB_CTMU_EdgeSet

  Description:
    This template implements the Default variant of the PLIB_CTMU_EdgeSet function.
*/

PLIB_TEMPLATE void CTMU_EdgeSet_Default( CTMU_MODULE_ID index , CTMU_EDGE_SELECT edgeNumber )
{
	volatile ctmu_registers_t *ctmu = ((ctmu_registers_t *)(index));
	if ( edgeNumber == CTMU_EDGE1 )
	{
		ctmu->CTMUCONSET = _CTMUCON_EDG1STAT_MASK;
	}
	else
	{
		ctmu->CTMUCONSET = _CTMUCON_EDG2STAT_MASK;
	}
}


//******************************************************************************
/* Function :  CTMU_ExistsEdgeStatus_Default

  Summary:
    Implements Default variant of PLIB_CTMU_ExistsEdgeStatus

  Description:
    This template implements the Default variant of the PLIB_CTMU_ExistsEdgeStatus function.
*/

#define PLIB_CTMU_ExistsEdgeStatus PLIB_CTMU_ExistsEdgeStatus
PLIB_TEMPLATE bool CTMU_ExistsEdgeStatus_Default( CTMU_MODULE_ID index )
{
    return true;
}


#endif /*_CTMU_EDGESTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

