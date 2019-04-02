/*******************************************************************************
  MTCH6301 Touch Driver Configuration Template

  Company:    
    Microchip Technology Inc.

  File Name:   
    drv_mtch6301_config_template.h
  
  Summary:    
    MTCH6301 Touch Driver configuration template.

  Description:
    This header file contains the build-time configuration selections for the
    MTCH6301 Touch Driver.  This is the template file which give all possible
    configurations that can be made. This file should not be included in 
    any project.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2014-2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _DRV_MTCH6301_CONFIG_TEMPLATE_H
#define _DRV_MTCH6301_CONFIG_TEMPLATE_H

//#error "This is a configuration template file.  Do not include it directly."

// *****************************************************************************
// *****************************************************************************
// Section: MTCH6301 Core Functionality Configuration Macros
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* MTCH6301 hardware instance configuration

  Summary:
    Sets up the maximum number of hardware instances that can be supported.

  Description:
    This macro sets up the maximum number of hardware instances that can be 
    supported.

  Remarks:
    None.
*/

#define DRV_MTCH6301_INSTANCES_NUMBER                 1


//**********************************************************************
/* MTCH6301 maximum number of clients

  Summary:
    Selects the maximum number of clients.

  Description:
    This macro selects the maximum number of clients.
    
    This definition selected the maximum number of clients that the MTCH6301
    driver can support at run time.

  Remarks:
    None.                                                              
 */

#define DRV_MTCH6301_CLIENTS_NUMBER                   1


// *****************************************************************************
/* MTCH6301 Static Index Selection

  Summary:
    MTCH6301 static index selection.

  Description:
    This macro specifies the static index selection for the driver object reference.

  Remarks:
    This index is required to make a reference to the driver object.
*/

#define DRV_MTCH6301_INDEX                            DRV_MTCH6301_INDEX_0


// *****************************************************************************
/* MTCH6301 Interrupt And Polled Mode Operation Control

  Summary:
    Controls operation of the driver in the interrupt or polled mode.

  Description:
    This macro controls the operation of the driver in the interrupt
    mode of operation. The possible values of this macro are:
    - true  - Select if interrupt mode of MTCH6301 operation is desired
    - false - Select if polling mode of MTCH6301 operation is desired
    Not defining this option to true or false will result in a build error.

  Remarks:
    None.
*/

#define DRV_MTCH6301_INTERRUPT_MODE                   false


// *****************************************************************************
// *****************************************************************************
// Section: Initialization Overrides
// *****************************************************************************
// *****************************************************************************
/* This section defines the initialization overrides */

// *****************************************************************************
/* MTCH6301 Calibration Inset

  Summary:
    Defines the calibration inset.

  Description:
    This macro defines the calibration inset.

  Remarks:
    None.
*/

#define DRV_MTCH6301_CALIBRATION_INSET                25


//**************************************************************************
/* MTCH6301 Touch Diameter

  Summary:
    Defines the touch diameter.

  Description:
    This macro defines the touch diameter

  Remarks:
    None.
*/

#define DRV_MTCH6301_TOUCH_DIAMETER                   10


//**************************************************************************
/* MTCH6301 Sample Points

  Summary:
    Define the sample points.

  Description:
    MTCH6301 sample points

  Remarks:
    None.
*/

#define DRV_MTCH6301_SAMPLE_POINTS                    4


// *****************************************************************************
/* MTCH6301 Calibration Delay

  Summary:
    Defines the calibration delay.

  Description:
    This macro enables the delay between calibration touch points.

  Remarks:
    None.
*/

#define DRV_MTCH6301_CALIBRATION_DELAY                300

#endif // _DRV_MTCH6301_CONFIG_TEMPLATE_H

/*******************************************************************************
 End of File
*/