/*******************************************************************************
  Reset System Service Datatype Definitions

  Company:
    Microchip Technology Inc.

  File Name:
    sys_reset_definitions_pic32m.h

  Summary:
    Reset System Service datatype definitions for PIC32M parts.

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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

#ifndef SYS_RESET_DEFINITIONS_PIC32M_H
#define SYS_RESET_DEFINITIONS_PIC32M_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "peripheral/reset/plib_reset.h"

#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif

// *****************************************************************************
/* Macro: _SYS_RESET_NMI_SUPPORT

  Summary:
    This is for the SYS_RESET_NMIDelayCountSet feature existence.

  Description:
    This throws a warning whenever SYS_RESET_NMIDelayCountSet
	is used for the unsupported devices..
*/

#if !defined(PLIB_RESET_ExistsNmiCounter)
    #undef SYS_RESET_PART_SPECIFIC
    #define SYS_RESET_PART_SPECIFIC   __attribute__((unsupported("The microcontroller selected does not implement this feature.")))
#endif
#ifndef _SYS_RESET_PART_SPECIFIC
    #undef SYS_RESET_PART_SPECIFIC
    #define SYS_RESET_PART_SPECIFIC
#endif


#ifdef __cplusplus  // Provide C++ Compatibility
}
#endif

#endif /* SYS_RESET_DEFINITIONS_PIC32M_H */

/*******************************************************************************
 End of File
*/
