/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_harmony.h

  Summary:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version ${CONFIG_MPLAB_HARMONY_VERSION_STRING}
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END

#ifndef _LIBARIA_HARMONY_H
#define _LIBARIA_HARMONY_H

#include "system_config.h"
#include "system_definitions.h"

#include "gfx/libaria/libaria.h"

<#if CONFIG_USE_3RDPARTY_RTOS == true>
#include "gfx/libaria/libaria_rtos.h"
#include "gfx/libaria/inc/libaria_context_rtos.h"
#include "gfx/libaria/inc/libaria_input_rtos.h"
</#if>

<#if CONFIG_MHGC_ENABLE?? && CONFIG_MHGC_ENABLE == true>
#include "gfx/libaria/libaria_init.h"

<#if CONFIG_LIBARIA_HAS_EVENTS??>
#include "gfx/libaria/libaria_events.h"
<#if CONFIG_USE_3RDPARTY_RTOS == true>
#include "gfx/libaria/inc/libaria_events_rtos.h"
</#if></#if>

<#if CONFIG_LIBARIA_HAS_MACROS??>
#include "gfx/libaria/libaria_macros.h"
</#if>
</#if>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

typedef enum
{
    LIBARIA_STATE_INIT = 0,
    LIBARIA_STATE_RUNNING,
	LIBARIA_STATE_ERROR
} LIBARIA_STATES;

// *****************************************************************************
/* MPLAB Harmony Graphics Composer Objects

  Summary:
    Structure holding the graphics object handles

  Description:
    This structure contains the object handles for all graphics objects 
    generated by the Harmony Graphics Composer

  Remarks:
*/

typedef struct libaria_objects_t
{
	laContext* context;
} libaria_objects;

extern libaria_objects libariaObj;

/******************************************************************************
  Function:
    void LibAria_Initialize(void)

  Summary:
    This function initializes the LibAria state machine.  
 */
int32_t LibAria_Initialize(void);


/******************************************************************************
  Function:
    void LibAria_Tasks(void);

  Summary:
    This function is called in SYS_Tasks.  
*/
void LibAria_Tasks(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_HARMONY_H
/*******************************************************************************
 End of File
*/
