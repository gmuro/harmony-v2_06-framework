/*******************************************************************************
  SST25VF020B SPI Flash Driver Local Data Structures

  Company:
    Microchip Technology Inc.

  File Name:
    drv_sst25vf020b_local.h

  Summary:
    SST25VF020B SPI Flash Driver Local Data Structures

  Description:
    Driver Local Data Structures
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute Software
only when embedded on a Microchip microcontroller or digital  signal  controller
that is integrated into your product or third party  product  (pursuant  to  the
sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef _DRV_SST25VF020B_LOCAL_H
#define _DRV_SST25VF020B_LOCAL_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "driver/spi_flash/sst25vf020b/drv_sst25vf020b.h"
#include "driver/spi_flash/sst25vf020b/src/drv_sst25vf020b_variant_mapping.h"
#include "osal/osal.h"
#include "system/debug/sys_debug.h"



// *****************************************************************************
// *****************************************************************************
// Section: Constant Definitions
// *****************************************************************************
// *****************************************************************************

/* op-code definitions for different operations */
/* Write Disable */
#define SST25VF020B_WRDI_OP_CODE            0x04
/* Write Enable */
#define SST25VF020B_WREN_OP_CODE            0x06
/* Write Status Register */
#define SST25VF020B_WRSR_OP_CODE            0x01
/* Erase 4 KByte of Memory Area */
#define SST25VF020B_ERASE_OP_CODE           0x20
/* Byte program */
#define SST25VF020B_WRITE_BYTE_OP_CODE      0x02
/* Read Memory at Normal Speed */
#define SST25VF020B_NORMAL_READ_OP_CODE     0x03
/* Read Memory at High Speed */
#define SST25VF020B_HIGH_SPEED_READ_OP_CODE 0x0B
/* Read Status Register */
#define SST25VF020B_RDSR_OP_CODE            0x05
/* Auto Address Increment Programming */
#define SST25VF020B_AAI_OP_CODE             0xAD

// *****************************************************************************
/* SST Flash Driver Buffer Handle Macros

  Summary:
    SST Flash driver Buffer Handle Macros

  Description:
    Buffer handle related utility macros. SST Flash driver buffer handle is a
    combination of buffer token and the buffer object index. The buffer token
    is a 16 bit number that is incremented for every new write, read or erase
    request and is used along with the buffer object index to generate a new
    buffer handle for every request.

  Remarks:
    None
*/

#define _DRV_SST25VF020B_BUF_TOKEN_MAX         (0xFFFF)
#define _DRV_SST25VF020B_MAKE_HANDLE(token, index) ((token) << 16 | (index))
#define _DRV_SST25VF020B_UPDATE_BUF_TOKEN(token) \
{ \
    (token)++; \
    (token) = ((token) == _DRV_SST25VF020B_BUF_TOKEN_MAX) ? 0: (token); \
}

// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* _DRV_SST25VF020B_ERASE_WRITE_STATES

  Summary
    Lists the different states that erase write operation can have

  Description
    This enumeration lists the different sub states that internal buffer processing
    task routine can have while in the DRV_SST25VF020B_ERASE_WRITE state.

  Remarks:
    None.
*/
typedef enum {
    /* Erase write init state */
    _DRV_SST25VF020B_ERASE_WRITE_INIT,
    
    /* Read substate of the read-modify-write cycle */
    _DRV_SST25VF020B_ERASE_WRITE_READ_COMPLETE,
    
    /* Modify/Erase substate of the read-modify-write cycle */
    _DRV_SST25VF020B_ERASE_WRITE_ERASE_COMPLETE,
    
    /* Write substate of the read-modify-write cycle */
    _DRV_SST25VF020B_ERASE_WRITE_CONT_WRITE,
    
    /* Write Completed substate of the read-modify-write cycle */
    _DRV_SST25VF020B_ERASE_WRITE_WRITE_COMPLETE

} _DRV_SST25VF020B_ERASE_WRITE_STATES;

// *****************************************************************************
/* DRV_SST25VF020B_BUFFER_PROCESS_STATE

  Summary
    Lists the different states that internal buffer processing task routine
    can have.

  Description
    This enumeration lists the different states that internal buffer processing
    task routine can have.

  Remarks:
    None.
*/

typedef enum{

    /* Beginning of Buffer Process */
    DRV_SST25VF020B_BUFFER_PROCESS_INIT,

    /* Send write enable command */
    DRV_SST25VF020B_SEND_WREN_CMD,

    /* Check if write has been enabled */
    DRV_SST25VF020B_WREN_EXECUTION_STATUS_CHECK,

    /* Send Write command along with write address and data pointer */
    DRV_SST25VF020B_SEND_WRITE_CMD_ADDRESS_AND_DATA,

    /* Send erase command and address */
    DRV_SST25VF020B_SEND_ERASE_CMD_AND_ADDRESS,

    /* Send read command and address */
    DRV_SST25VF020B_SEND_READ_CMD_AND_ADDRESS,

    /* Start the read operation */
    DRV_SST25VF020B_START_READING,

    /* Wait for Write/Erase buffer completion */
    DRV_SST25VF020B_WAIT_FOR_WRITE_OR_ERASE_BUFFER_COMPLETE,

    /* Send command to read the status register */
    DRV_SST25VF020B_SEND_COMMAND_FOR_BUSY_STATUS,

    /* Read the status of Busy Bit */
    DRV_SST25VF020B_READ_BUSY_STATUS,

    /* Wait until BUSY bit is clear */
    DRV_SST25VF020B_WAIT_FOR_BUSY_CLEAR,

    /* Read operation is completed */
    DRV_SST25VF020B_READ_COMPLETED,

    /* Erase write main state */
    DRV_SST25VF020B_ERASE_WRITE,

}DRV_SST25VF020B_BUFFER_PROCESS_STATE;

// *****************************************************************************
/* SST25VF020B Driver task states

  Summary
    Lists the different states that SST25VF020B task routine can have.

  Description
    This enumeration lists the different states that SST25VF020B task routine
    can have.

  Remarks:
    None.
*/

typedef enum
{
    /* Open SPI driver */
    DRV_SST25VF020B_TASK_OPEN_SPI_DRIVER,

    /* This state is to send the WREN command to be able to modify
       SST Status register */
    DRV_SST25VF020B_SEND_WREN_CMD_WRSR,

    /* Check if write has been enabled */
    DRV_SST25VF020B_WREN_EXECUTION_STATUS_CHECK_WRSR,

    /* Send write status register command and status register value */
    DRV_SST25VF020B_SEND_WRSR_CMD_AND_VALUE,

    /* Check if Status register is written */
    DRV_SST25VF020B_WRSR_EXECUTION_STATUS_CHECK,

    /* Process Queue */
    DRV_SST25VF020B_TASK_PROCESS_QUEUE

} DRV_SST25VF020B_DATA_OBJECT_STATE;

// *****************************************************************************
/* SST25VF020B Driver Operations

  Summary
    Lists the different operations that SST25VF020B driver can do.

  Description
    This enumeration lists the different operations that SST25VF020B driver can
    do.

  Remarks:
    None.
*/

typedef enum
{
    /* Block Read */
    DRV_SST25VF020B_BLOCK_READ,

    /* Block Write */
    DRV_SST25VF020B_BLOCK_WRITE,

    /* Block Erase */
    DRV_SST25VF020B_BLOCK_ERASE,

    /* Erase Write */
    DRV_SST25VF020B_BLOCK_ERASE_WRITE

} DRV_SST25VF020B_BLOCK_OPERATION;

// *****************************************************************************
/* SST25VF020B SPI Flash Driver Buffer Object

  Summary:
    Object used to keep track of a client's buffer.

  Description:
    This object is used to keep track of a client's buffer in the driver's 
    queue.

  Remarks:
    None.
*/

typedef struct _DRV_SST25VF020B_BUFFER_OBJ
{
    /* This flag tracks whether this object is in use */
    bool inUse;

    /* Pointer to the application read or write buffer */
    uint8_t * buffer;

    /* address of flash from where to read or to write or erase from */
    uint32_t address;
    
    /* Tracks how much data has been transferred */
    uint32_t nCurrentBlocks;

    /* Number of blocks to be transferred */
    uint32_t size;

    /* block operation which has been requested */
    DRV_SST25VF020B_BLOCK_OPERATION operation;
            
    /* Client that owns this buffer */
    void * hClient;
    
    /* Status of the Buffer */
    DRV_SST25VF020B_COMMAND_STATUS commandStatus;

    /* Current command handle of this buffer object */
    DRV_SST25VF020B_BLOCK_COMMAND_HANDLE commandHandle;

    /* Next buffer pointer */
    struct _DRV_SST25VF020B_BUFFER_OBJ * next;

    /* Previous buffer pointer */
    struct _DRV_SST25VF020B_BUFFER_OBJ * previous;

} DRV_SST25VF020B_BUFFER_OBJ;

// *****************************************************************************
/* SST25VF020B Driver Global Instances Object

  Summary:
    Object used to keep track of data that is common to all instances of the
    SST25VF020B driver.

  Description:
    This object is used to keep track of any data that is common to all
    instances of the SST25VF020B driver.

  Remarks:
    None.
*/

typedef struct
{
    /* Set to true if all members of this structure
       have been initialized once */
    bool membersAreInitialized;

    /* Mutex to protect client object pool */
    OSAL_MUTEX_DECLARE(mutexClientObjects);

    /* Mutex to protect buffer queue object pool */
    OSAL_MUTEX_DECLARE(mutexBufferQueueObjects);

} DRV_SST25VF020B_COMMON_DATA_OBJ;

// *****************************************************************************
/* SST25VF020B SPI Flash Driver Instance Object

  Summary:
    Object used to keep any data required for an instance of the SST25VF020B SPI
    Flash driver.

  Description:
    This object is used to keep track of any data that must be maintained to 
    manage a single instance of the SPI Flash driver.

  Remarks:
    None.
*/

typedef struct
{
    /*  The module index of associated SPI driver */
    SYS_MODULE_INDEX    spiDriverModuleIndex;
    
    /* SPI Driver Handle */
    DRV_HANDLE spiDriverOpenHandle;

    /* The status of the driver */
    SYS_STATUS status;

    /* Flag to indicate this obejct is in use  */
    bool inUse;

    /* Flag to indicate that driver has been opened exclusively. */
    bool isExclusive;

    /* Keeps track of the number of clients that have opened this driver */
    uint32_t nClients;

    /* The buffer Queue Tail pointer*/
    /* elements are removed from the queue from the position pointed by
     * queueTail */
    DRV_SST25VF020B_BUFFER_OBJ  *queueTail;

    /* It is maximum number of requests that driver will queue */
    uint32_t queueSize;
    
    /* Current queue occupancy, it should never be more than queueSize */
    uint32_t queueOccupancy;

    /* Chip select pin port channel */
    PORTS_CHANNEL                       chipSelectPortChannel;

    /* Chip Select Bit pin position */
    PORTS_BIT_POS                       chipSelectBitPosition;

    /* State of the task */
    DRV_SST25VF020B_DATA_OBJECT_STATE    	state;

    /* State of the buffer object transfer */
    DRV_SST25VF020B_BUFFER_PROCESS_STATE    		bufferProcessState;

    /* temprary SPI Buffer Handle */
    DRV_HANDLE        spiBufferHandle;

    /* array to keep commands, addresses and data */
    uint8_t         commandAddressData[6];

    /* Check if an erase write operation is in progress. */
    bool            isEraseWrite;

    /* Erase write sub states */
    _DRV_SST25VF020B_ERASE_WRITE_STATES eraseWriteState;

    /* Write block address of the erase write operation. */
    uint32_t writeAddress;

    /* Number of pending write blocks in the erase write operation. */
    uint32_t numPendingWriteBlocks;

    /* Erase block address */
    uint32_t eraseBlockAddress;

    /* Number of bytes to be programmed in the current erase block */
    uint32_t numBytesInThisBlock;

    /* SST device geometry */
    SYS_FS_MEDIA_GEOMETRY		sstDeviceGeometry;

    /* Read, Write and Erase region details */
    SYS_FS_MEDIA_REGION_GEOMETRY        memoryRegions[3];

    /* Hardware instance mutex */
    OSAL_MUTEX_DECLARE(mutexDriverInstance);

} DRV_SST25VF020B_OBJ;

// *****************************************************************************
/* SST25VF020B SPI Flash Driver Client Object

  Summary:
    Object used to track a single client.

  Description:
    This object is used to keep the data necesssary to keep track of a single 
    client.

  Remarks:
    None.
*/

typedef struct
{
    /* The hardware instance object associated with the client */
    DRV_SST25VF020B_OBJ * hDriver;

    /* The IO intent with which the client was opened */
    DRV_IO_INTENT   ioIntent;

    /* This flags indicates if the object is in use or is available */
    bool inUse;

    /* Event handler for this function */
    DRV_SST25VF020B_EVENT_HANDLER eventHandler;

    /* Client Status */
    DRV_SST25VF020B_CLIENT_STATUS clientStatus;

    /* Application Context associated with this client */
    uintptr_t context;

} DRV_SST25VF020B_CLIENT_OBJ;

/* This is the array of SST25VF020B SPI Flash Driver Buffer objects. */
extern DRV_SST25VF020B_BUFFER_OBJ gDrvSST25VF020BBufferObj[DRV_SST25VF020B_QUEUE_DEPTH_COMBINED];

extern uint16_t gDrvSST25VF020BBufferToken;

extern DRV_SST25VF020B_CLIENT_OBJ * _DRV_SST25VF020B_DriverHandleValidate(DRV_HANDLE handle);

#endif //#ifndef _DRV_SST25VF020B_LOCAL_H

/*******************************************************************************
 End of File
*/

