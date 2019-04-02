/*******************************************************************************
  NVM Device Driver Definition

  Company:
    Microchip Technology Inc.

  File Name:
    drv_nvm_static.c

  Summary:
    NVM Device Driver Static Single Client Implementation

  Description:
    The NVM device driver provides a simple interface to manage the NVM modules
    on Microchip microcontrollers.  This file Implements the core interface
    routines for the NVM driver.
    While building the driver from source, ALWAYS use this file in the build.
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


// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************


#include "driver/nvm/src/drv_nvm_local.h"


// *****************************************************************************
// *****************************************************************************
// Section: File Scope Variables
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Driver Hardware instance objects.

  Summary:
    Defines the hardware instances objects that are available on the part

  Description:
    This data type defines the hardware instance objects that are available on
    the part, so as to capture the hardware state of the instance.

  Remarks:
    Not all modes are available on all micro-controllers.
*/
DRV_NVM_OBJECT                                                _DRV_NVM_OBJ_MAKE_NAME ( gDrvNVMObj ) ;

DRV_NVM_OBJECT                                                *dObj = &(_DRV_NVM_OBJ_MAKE_NAME ( gDrvNVMObj ));

// *****************************************************************************
/* Macro: _DRV_NVM_INDEX_GET(drvIndex)

  Summary:
    Returns the appropriate driver id for the configuration

  Description:
    Either return the statically declared driver id or returns the dynamic index
    passed into the macro. This macro has variations for dynamic or static
    driver

*/
#define _DRV_NVM_INDEX_GET(drvIndex)                          DRV_NVM_CONFIG_INDEX

// *****************************************************************************
/* Driver Client instance objects.

  Summary:
    Defines the client instances objects

  Description:
    This data type defines the client instance objects that are available on
    the part, so as to capture the client state of the instance.
    It uses the configuration of maximum number of clients which can get
    registered per hardware instance.

  Remarks:
    Not all modes are available on all micro-controllers.
 */


// *****************************************************************************
/* Driver Client instance objects.

  Summary:
    Defines the client instances objects

  Description:
    This data type defines the client instance objects that are available on
    the part, so as to capture the client state of the instance.
    It uses the configuration of maximum number of clients which can get
    registered per hardware instance.

  Remarks:
    Not all modes are available on all micro-controllers.
 */

DRV_NVM_CLIENT_OBJECT                                         _DRV_NVM_OBJ_MAKE_NAME(gDrvNVMClientObj);

DRV_NVM_CLIENT_OBJECT    *clientObj                        = &_DRV_NVM_OBJ_MAKE_NAME(gDrvNVMClientObj);

// *****************************************************************************
/* Driver transfer instance objects.

  Summary:
    Defines the transfer instances objects

  Description:
    This data type defines the tranfser instance objects that are available on
    the part, so as to capture the client state of the instance.
    It uses the configuration of maximum number of transfer objects which can get
    registered per build.

  Remarks:
    Not all modes are available on all micro-controllers.
 */
DRV_NVM_XFER_OBJECT                                           gDrvNVMXferQObj[DRV_NVM_XFER_BUFFER_NUMBER];

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Functions
// *****************************************************************************
// *****************************************************************************

/******************************************************************************
  Function:
    static void _DRV_NVM_SetupHardware ( DRV_NVM_INIT   *nvmInit )

  Summary:
    Sets up the hardware from the initialzation structure

  Description:
    This routine sets up the hardware from the initialzation structure.

  Remarks:
    Called
*/

static void _DRV_NVM_SetupHardware
( 
    DRV_NVM_INIT        *nvmInit
)
{
    /* Initialize the Interrupt Source */
    _DRV_NVM_STATIC_INT_SRC( _DRV_NVM_OBJ_MAKE_NAME ( gDrvNVMObj ).FlashControlInterruptSource  = _DRV_NVM_GET_INT_SRC(nvmInit->InterruptSource) );

    //The below operations are only to be enabled if the
    //processor selected is MCU8 series
    //_DRV_NVM_FlashAccessEnable ( _DRV_NVM_PERIPHERAL_ID_GET ( plibId ) ) ;
    //_DRV_NVM_EEPROMAccessEnable ( _DRV_NVM_PERIPHERAL_ID_GET ( plibId ) ) ;
    //_DRV_NVM_FlashWriteOperationSelect ( _DRV_NVM_PERIPHERAL_ID_GET ( plibId ) ) ;
    /*Set up memory access */
    if( PLIB_NVM_ExistsMemoryModificationControl( _DRV_NVM_PERIPHERAL_ID_GET( plibId) ))
    {
        PLIB_NVM_MemoryModifyInhibit( _DRV_NVM_PERIPHERAL_ID_GET( plibId ) );
    }
} /* _DRV_NVM_SetupHardware */


// *****************************************************************************
// *****************************************************************************
// Section: Driver Interface Function Definitions
// *****************************************************************************
// *****************************************************************************

/******************************************************************************
  Function:
    SYS_MODULE_OBJ DRV_NVM_Initialize( const SYS_MODULE_INDEX index,
                                       const SYS_MODULE_INIT * const init )

  Summary:
    Initializes hardware and data for the given instance of the NVM module

  Description:
    This routine initializes hardware for the instance of the NVM module,
    using the hardware initialization given data.  It also initializes all
    necessary internal data.

  Parameters:
    index           - Identifies the driver instance to be initialized

    init            - Pointer to the data structure containing all data
                      necessary to initialize the hardware. This pointer may
                      be null if no data is required and static initialization
                      values are to be used.

  Returns:
    If successful, returns a valid handle to a driver instance object.
    Otherwise, it returns SYS_MODULE_OBJ_INVALID.
*/

void _DRV_NVM_MAKE_NAME (Initialize)
(
    const SYS_MODULE_INIT   *const init
)
{
    DRV_NVM_INIT    *nvmInit    = NULL;

    /* Validate the driver index */
    if ( _DRV_NVM_INDEX_GET(DRV_NVM_CONFIG_INDEX) >= DRV_NVM_INDEX_COUNT )
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Assign to the local pointer the init data passed */
    nvmInit = ( DRV_NVM_INIT * )init;

    _DRV_NVM_OBJ_ALLOCATE(DRV_NVM_CONFIG_INDEX, dObj);

    /* Check that the object is valid */
    SYS_ASSERT( DRV_NVM_CONFIG_INDEX < DRV_NVM_INSTANCES_NUMBER, "Hardware Object is invalid" );

    /* Set the operation flag to be in use */
    _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX,inUse) = true;
    
        /* Update the NVM Module Index */
    _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX,moduleId) = _DRV_NVM_PERIPHERAL_ID_GET( nvmInit->nvmID );

    /* Setup the Hardware */
    _DRV_NVM_SetupHardware( NVMInit ) ;

    /* Interrupt flag cleared on the safer side */
    _DRV_NVM_InterruptSourceClear( _DRV_NVM_GET_INT_SRC( _DRV_NVM_OBJ(DRV_NVM_INDEX, interruptSource) ) );

    /* Enable the interrupt source in case of interrupt mode */
    _DRV_NVM_InterruptSourceEnable( _DRV_NVM_GET_INT_SRC( _DRV_NVM_OBJ(DRV_NVM_INDEX, interruptSource) ) );

    /* Set the current driver state */
    _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX, status) = SYS_STATUS_READY;

} /* DRV_NVM_Initialize */


/******************************************************************************
  Function:
    void DRV_NVM_Reinitialize( SYS_MODULE_OBJ object,
                               const SYS_MODULE_INIT* const init )

  Summary:
    Reinitializes and refreshes the hardware for the instance of the NVM
    module

  Description:
    This routine reinitializes and refreshes the hardware for the instance
    of the NVM module using the hardware initialization given data.
    It does not clear or reinitialize internal data structures

  Parameters:
    object          - Identifies the Driver Object returned by the Initialize
                      interface
    init            - Pointer to the data structure containing any data
                      necessary to initialize the hardware.

  Returns:
    None
*/

void _DRV_NVM_MAKE_NAME(Reinitialize)
( 
    const SYS_MODULE_INIT * const init
)
{

    DRV_NVM_OBJ dObj = (DRV_NVM_OBJ) object ;
    DRV_NVM_INIT * nvmInit = NULL;

    /* Valid init structure is present */
    nvmInit = ( DRV_NVM_INIT * ) init;

    /* Stop the memory modification NVM Module */
    if( PLIB_NVM_ExistsMemoryModificationControl( _DRV_NVM_PERIPHERAL_ID_GET( _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX , nvmId ) ) ) )
    {
        PLIB_NVM_MemoryModifyDisable( _DRV_NVM_PERIPHERAL_ID_GET( _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX , nvmId ) ) );
    }

    /* Set the curent driver state */
    _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX ,status) = SYS_STATUS_UNINITIALIZED ;

    /* Setup the Hardware */
    _DRV_NVM_SetupHardware( NVMInit ) ;

    /* Re Start the memory mofidication NVM Module */
    if( PLIB_NVM_ExistsMemoryModificationControl( _DRV_NVM_PERIPHERAL_ID_GET( _DRV_NVM_OBJ( DRV_NVM_INDEX , nvmId ) ) ) )
    {
        PLIB_NVM_MemoryModifyEnable( _DRV_NVM_PERIPHERAL_ID_GET( _DRV_NVM_OBJ( DRV_NVM_INDEX , nvmId ) ) );
    }

    /* Set the curent driver state */
    _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX ,status) = SYS_STATUS_READY;

} /* DRV_NVM_Reinitialize */


/******************************************************************************
  Function:
    void DRV_NVM_Deinitialize( SYS_MODULE_OBJ object )

  Summary:
    Deinitializes the specific module instance of the NVM module

  Description:
    Deinitializes the specific module instancedisabling its operation (and any
    hardware for driver modules).  Resets all the internal data structures and
    fields for the specified instance to the default settings.

  Parameters:
    object          - Identifies the Driver Object returned by the Initialize
                      interface

  Returns:
    None
*/

void _DRV_NVM_MAKE_NAME (Deinitialize)( void )
{
    DRV_NVM_OBJ dObj = (DRV_NVM_OBJ) object ;
    /* Interrupt De-Registration */
    _DRV_NVM_InterruptSourceDisable( _DRV_NVM_GET_INT_SRC( _DRV_NVM_OBJ(DRV_NVM_INDEX, interruptSource) ) );

    /* Set the Device Status */
    _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX ,status) = SYS_STATUS_UNINITIALIZED;

    /* Remove the driver usage */
    _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX ,inUse) = false;

} /* DRV_NVM_Deinitialize */


/******************************************************************************
  Function:
    SYS_STATUS DRV_NVM_Status( SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the hardware instance of the NVM module

  Description:
    This routine Provides the current status of the hardware instance of the
    NVM module.

  Parameters:
    object          - Identifies the Driver Object returned by the Initialize
                      interface

  Returns:
    SYS_STATUS_READY    Indicates that any previous module operation for the
                        specified module has completed

    SYS_STATUS_BUSY     Indicates that a previous module operation for the
                        specified module has not yet completed

    SYS_STATUS_ERROR    Indicates that the specified module is in an error state
*/

SYS_STATUS _DRV_NVM_MAKE_NAME (Status)( void  )
{
    DRV_NVM_OBJ dObj = (DRV_NVM_OBJ) object ;
    /* Return the status associated with the driver handle */
    return( _DRV_NVM_OBJ( DRV_NVM_CONFIG_INDEX ,status );

} /* DRV_NVM_Status */


/******************************************************************************
  Function:
    DRV_HANDLE DRV_NVM_Open( const SYS_MODULE_INDEX index,
                             const DRV_IO_INTENT intent )

  Summary:
    Opens the specific module instance and returns a handle

  Description:
    This routine opens a driver for use by any client module and provides a
    handle that must be provided to any of the other driver operations to
    identify the caller and the instance of the driver/hardware module.

  Parameters:
    index           - Identifier for the instance to be initialized
    ioIntent        - Possible values from the enumeration DRV_IO_INTENT

  Returns:
    If successful, the routine returns a valid open-instance handle (a number
    identifying both the caller and the module instance)
    If an error occurs, the return value is DRV_HANDLE_INVALID
*/

void _DRV_NVM_MAKE_NAME (Open)
(
        const DRV_IO_INTENT ioIntent
)
{
    /* Multi client variables are removed from single client builds. */
    DRV_NVM_CLIENT_OBJ hClientObj = (DRV_NVM_CLIENT_OBJ) 0;
    DRV_NVM_OBJ hObj = 0;


    /* Setup client operations */

    /* To Do: OSAL - Lock Mutex */

    /* Set the flag as in use */
    _DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,inUse )         = true;
    _DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,driverObject)   = _DRV_NVM_INDEX_GET( DRV_NVM_CONFIG_INDEX );


    /* To Do: OSAL - Unlock Mutex */

    /* Update the Client Status */
    _DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,status) = DRV_NVM_CLIENT_STATUS_READY;

} /* DRV_NVM_Open */


/******************************************************************************
  Function:
    void DRV_NVM_Close( DRV_Handle handle )

  Summary:
    Closes an opened-instance of a driver

  Description:
    This routine closes an opened-instance of a driver, invalidating the given
    handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None
*/

void _DRV_NVM_MAKE_NAME (Close) ( void )
{

    /* To Do: OSAL - lock Mutex */

    /* Free the Client Instance */
    _DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,inUse) = false ;

    /* To Do: OSAL - unlock Mutex */

    /* Update the Client Status */
    _DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,status) = DRV_NVM_STATUS_INVALID;
    
} /* DRV_NVM_Close */


/******************************************************************************
  Function:
    DRV_NVM_CLIENT_STATUS DRV_NVM_ClientStatus(DRV_HANDLE handle)

  Summary:
    Gets the status of the module instance associated with the handle

  Description:
    This routine gets the status of the module instance associated with the
    handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    DRV_NVM_CLIENT_STATUS value describing the current status of the driver
*/

DRV_NVM_CLIENT_STATUS _DRV_NVM_MAKE_NAME (ClientStatus)( void )
{
    /* Return the client status associated with the handle passed */
    return( _DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,status ));

} /* DRV_NVM_ClientStatus */



int _DRV_NVM_MAKE_NAME ( Read )
(
    /* Function Parameters: (Dynamic arguments are removed from static builds.) */
    uint8_t *targetBuffer,
    uint8_t *srcAddress,
    const unsigned int numbytes
)
{
    int32_t                             numBytesRead = 0 ;
    /* Multi client variables are removed from single client builds. */
    DRV_NVM_CLIENT_OBJ  hClientObj;
    unsigned int        count = 0;

    while(count++<numbytes)
    {
        *targetBuffer = PLIB_NVM_FlashRead(_DRV_NVM_CLIENT_OBJ( DRV_NVM_CONFIG_INDEX ,driverObject),   srcAddress++);
        targetBuffer++;
    }

    return count ;

} /* DRV_NVM_Read */

/******************************************************************************
  Function:
        DRV_NVM_BUFFER_HANDLE* DRV_NVM_BufferAdd( const DRV_HANDLE handle,
            DRV_NVM_IO_BUFFER_OBJECT *bufferObject) ;
 */

DRV_HANDLE  _DRV_NVM_MAKE_NAME (BufferAdd)
(
    DRV_NVM_IO_BUFFER   *bufferObject
)
{
    DRV_NVM_CLIENT_OBJ                  clientObj    = (DRV_NVM_CLIENT_OBJ) 0 ;
    DRV_NVM_OBJ                         dObj                = (DRV_NVM_OBJ) 0 ;
    DRV_NVM_BUFFER_OBJ                  bufferObj    = (DRV_NVM_BUFFER_OBJ)0;
    DRV_IO_BUFFER_TYPES                 ioType ;
    DRV_NVM_BUFFER_OBJECT               *nvm_bufferObject = NULL ;
 
    //moduleId = _DRV_NVM_HW_INSTANCE(moduleIndex).moduleId;

    if (( bufferObject->flags & DRV_NVM_BUFFER_FLAG_WRITE ))
    {
        ioType = DRV_IO_BUFFER_TYPE_WRITE ;
    }
    else
    {
        if (( bufferObject->flags & DRV_NVM_BUFFER_FLAG_READ ))
        {
            ioType = DRV_IO_BUFFER_TYPE_READ ;
        }
        else
        {
            ioType = DRV_IO_BUFFER_TYPE_ERASE;
        }

    }

    for (i = 0 ; i < DRV_NVM_NUMBER_OF_BUFFER_OBJECTS ; i++)
    {
        if (gDrvNVMBufferObj[i].inUse != true )
        {
            nvm_bufferObject = &gDrvNVMBufferObj[i] ;

            gDrvNVMBufferObj[i].inUse = true;
            //Update the type
            nvm_bufferObject->bufferFlags = ioType;
            //Update Target Address
            nvm_bufferObject->SrcAddress                = bufferObject->address;

            nvm_bufferObject->bufferObject->buffer      = bufferObject->buffer;

            nvm_bufferObject->bufferObject->size        = bufferObject->bufferSize;

            nvm_bufferObject->bufferObject->bufferType  = ioType;

            if(nvm_bufferObject->SrcAddress % 512 == 0)
            {
                nvm_bufferObject->isRowAligned == 1;
                nvm_bufferObject->NoOfRows = nvm_bufferObject->SrcAddress/512;
            }
            if(nvm_bufferObject->SrcAddress % 4096 == 0)
            {
                nvm_bufferObject->isPageAligned == 1;
                nvm_bufferObject->NoofPages = nvm_bufferObject->SrcAddress/4096;
            }

            //Add Logic for row and Page aligned here
            break ;
        }
    }

    /* Add the transaction buffer to the hardware Q*/
    if (bufferObj != -1)
    {
         //_DRV_NVM_AddWriteBufferObject(moduleIndex, bufferObjectIndex);
        bufferObj = i;

        if(ioType == DRV_IO_BUFFER_TYPE_WRITE)
        {
            QUEUE_Push(&_DRV_NVM_OBJ((DRV_NVM_CONFIG_INDEX , writeQ), (void *)nvm_bufferObject);
        }
        else
        {
            if(ioType == DRV_IO_BUFFER_TYPE_ERASE)
            {
                QUEUE_Push(&_DRV_NVM_OBJ((DRV_NVM_CONFIG_INDEX , eraseQ), (void *)nvm_bufferObject);
            }
        }

        _DRV_NVM_InterruptSourceEnable(_DRV_NVM_GET_INT_SRC(_DRV_NVM_OBJ((DRV_NVM_CONFIG_INDEX , InterruptSource)));

        // OSAL --> Unlock the instance mutex

        _DRV_NVM_BUFFER_OBJ(bufferObj, status) = DRV_NVM_BUFFER_QUEUED ;

    }
    /* Return the handle to the transaction buffer */
    return (DRV_NVM_BUFFER_HANDLE)bufferObj ;
}

/******************************************************************************
  Function:
    uint8_t DRV_NVM_Write( const DRV_HANDLE handle,  uint8_t *buffer,  const uint32_t numbytes);
 */

unsigned int _DRV_NVM_MAKE_NAME (WriteBlock)
(
    /* Function Parameters: (Multi client arguments are removed from single client builds.) */
    uint8_t             *buffer,
    const uint32_t      *NVMAddr,
    const uint32_t      numbytes
)
{
    DRV_NVM_BUFFER_OBJ            bufferHandle = -1 ;
    DRV_NVM_IO_BUFFER              bufferObject ;

    bufferObject.buffer         = (uint8_t *) buffer ;
    bufferObject.bufferSize     = numbytes ;
    bufferObject.flags          = DRV_NVM_BUFFER_FLAG_WRITE ;
    bufferObject.address        = NVMAddr;

    bufferHandle = DRV_NVM_BufferAdd(handle, &bufferObject) ;

    SYS_ASSERT ( ( bufferHandle != (DRV_NVM_BUFFER_HANDLE) NULL ) , "Unable to queue buffers for writing" ) ;

    return numbytes ;
}

/******************************************************************************
  Function:
    uint8_t DRV_NVM_Write( const DRV_HANDLE handle,  uint8_t *buffer,  const uint32_t numbytes);
 */

unsigned int _DRV_NVM_MAKE_NAME (EraseBlock)
(
    /* Function Parameters: (Multi client arguments are removed from single client builds.) */
    const uint32_t*     NVMAddr,
    const uint32_t      numbytes
)
{
    DRV_NVM_BUFFER_OBJ                bufferHandle = -1 ;
    DRV_NVM_IO_BUFFER                 bufferObject ;

    bufferObject.buffer         = (uint8_t *) NULL ;
    bufferObject.bufferSize     = numbytes ;
    bufferObject.flags          = DRV_NVM_BUFFER_FLAG_ERASE ;
    bufferObject.address        = NVMAddr;

    bufferHandle = DRV_NVM_BufferAdd(handle, &bufferObject) ;

    SYS_ASSERT ( ( bufferHandle != (DRV_NVM_BUFFER_HANDLE) NULL ) , "Unable to queue buffers for writing" ) ;

    return numbytes ;
}


/*******************************************************************************
  Function:
    void DRV_NVM_Tasks_Write ( SYS_MODULE_OBJ object )

  Summary:

  Description:

  Precondition:
    The DRV_NVM_Initialize routine must have been called for the specified
    NVM driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_NVM_Initialize)

  Returns:
    None.
*/

void  _DRV_NVM_MAKE_NAME (Tasks_Write)
(
    /* Function Parameter: (Dynamic arguments are removed from static builds.) */
)
{
    DRV_NVM_OBJ dObj                            = (DRV_NVM_OBJ) object ;
    DRV_NVM_BUFFER_OBJ bufferObj                = (DRV_NVM_BUFFER_OBJ)0;
    DRV_NVM_BUFFER_OBJECT                       *NVMbufferObject;
    uint8_t                             byte ;
    uint32_t                            *address;

    /* Check for the valid driver object passed */
    SYS_ASSERT( _DRV_NVM_ObjectIsValid( (DRV_NVM_CONFIG_INDEX  ) , "Driver Object is invalid" ) ;

    while (!PLIB_NVM_FlashWriteCycleHasCompleted(_DRV_NVM_OBJ((DRV_NVM_CONFIG_INDEX  , moduleId)))
    {
        /* Check if there is a write buffer associated with the
           instance*/
        if(_DRV_NVM_CheckCurrentBuffer(_DRV_NVM_OBJ((DRV_NVM_CONFIG_INDEX , currentWriteBuffer)))
        {
            _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer) = _DRV_NVM_GetNextBufferObject(&(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , writeQ)));
        }

        /* Check if the valid buffer is available. */
        if (_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer)!= NULL)
        {
            //bufferObject = (BUFFER_OBJECT*)_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer)->bufferObject;

            NVMbufferObject->bufferObject    = (BUFFER_OBJECT *)&((gDrvNVMObj[DRV_NVM_CONFIG_INDEX ].currentWriteBuffer)->bufferObject) ;

            //if not aligned then Byte by Byte transfer
            //else page/row transfer
            byte            = BUFFER_ReadByte ( bufferObject ) ;
            address         = NVMbufferObject->SrcAddress;

            asm("di");
            PLIB_NVM_MemoryModifyInhibit(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));

            if(NVMbufferObject->isRowAligned)
            {
                PLIB_NVM_FlashAddressToModify(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , address );
                PLIB_NVM_DataBlockSourceAddress ( _DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , NVMbufferObject->bufferObject->buffer ) ;

                PLIB_NVM_MemoryModifyEnable(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));
                PLIB_NVM_MemoryOperationSelect(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ), ROW_PROGRAM_OPERATION );
                NVMbufferObject->NoOfRows--;
            }
            else
            {
                //byte = _DRV_NVM_WRITE_BUFFER(bufferObjectIndex).buffer[_DRV_NVM_WRITE_BUFFER(bufferObjectIndex).readIndex++];
                //_DRV_NVM_WRITE_BUFFER(bufferObjectIndex).count--;
                //Disable Global interrupts

                PLIB_NVM_FlashAddressToModify(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , address++ );
                PLIB_NVM_FlashProvideData ( _DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , byte ) ;

                PLIB_NVM_MemoryModifyEnable(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));
                PLIB_NVM_MemoryOperationSelect(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ), WORD_PROGRAM_OPERATION );
            }

            while(!PLIB_NVM_FlashWriteCycleHasCompleted(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId)));

            PLIB_NVM_MemoryModifyInhibit(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));
            

            asm("ei");
            if ((BUFFER_IsBufferEmpty ( bufferObject )) && !((NVMbufferObject->isPageAligned || NVMbufferObject->isRowAligned)&&NVMbufferObject->NoOfRows))
            {
                /* OSAL --> Lock the instance mutex */
                QUEUE_Pop(&(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , writeQ)));
                /* OSAL --> Unlock the instance mutex */
                _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer)->status =  DRV_NVM_BUFFER_COMPLETED ;

                _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer)->operationalFlags = 0;

                _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer) = NULL;
            }
        }

        // Check if the transmission is complete
        if(QUEUE_IsEmpty(&(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , writeQ))) && ((_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer) == NULL )))
        {
            _DRV_NVM_InterruptSourceDisable(_DRV_NVM_GET_INT_SRC(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , txInterruptSource)));
            break;
        }
    }
}

/*******************************************************************************
  Function:
    void DRV_NVM_Tasks_Erase ( SYS_MODULE_OBJ object )

  Summary:

  Description:

  Precondition:
    The DRV_NVM_Initialize routine must have been called for the specified
    NVM driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_NVM_Initialize)

  Returns:
    None.
*/

void  _DRV_NVM_MAKE_NAME (Tasks_Erase)
(
    /* Function Parameter: (Dynamic arguments are removed from static builds.) */
    SYS_MODULE_OBJ object
)
{
    DRV_NVM_OBJ dObj                            = (DRV_NVM_OBJ) object ;
    DRV_NVM_BUFFER_OBJ bufferObj                = (DRV_NVM_BUFFER_OBJ)0;
    DRV_NVM_BUFFER_OBJECT                       *NVMbufferObject;
    uint8_t                             byte ;
    uint32_t                            *address;

    /* Check for the valid driver object passed */
    SYS_ASSERT( _DRV_NVM_ObjectIsValid( DRV_NVM_CONFIG_INDEX  ) , "Driver Object is invalid" ) ;

    while (!PLIB_NVM_FlashWriteCycleHasCompleted(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId)))
    {
        /* Check if there is a write buffer associated with the
           instance*/
        if(_DRV_NVM_CheckCurrentBuffer(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer)))
        {
            _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer) = _DRV_NVM_GetNextBufferObject(&(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , writeQ)));
        }

        /* Check if the valid buffer is available. */
        if (_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer)!= NULL)
        {
            //bufferObject = (BUFFER_OBJECT*)_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentWriteBuffer)->bufferObject;

            NVMbufferObject->bufferObject    = (BUFFER_OBJECT *)&((_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer))->bufferObject) ;

            //if not aligned then Byte by Byte transfer
            //else page/row transfer
            byte            = BUFFER_ReadByte ( bufferObject ) ;
            address         = NVMbufferObject->SrcAddress;

            //byte = _DRV_NVM_WRITE_BUFFER(bufferObjectIndex).buffer[_DRV_NVM_WRITE_BUFFER(bufferObjectIndex).readIndex++];
            //_DRV_NVM_WRITE_BUFFER(bufferObjectIndex).count--;
            //Disable Global interrupts
            asm("di");
            PLIB_NVM_MemoryModifyInhibit(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));

            if(NVMbufferObject->isPageAligned)
            {
                PLIB_NVM_FlashAddressToModify(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , address );
                PLIB_NVM_DataBlockSourceAddress ( _DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , NVMbufferObject->bufferObject->buffer ) ;

                PLIB_NVM_MemoryModifyEnable(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));
                PLIB_NVM_MemoryOperationSelect(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ), PAGE_ERASE_OPERATION );
                NVMbufferObject->NoofPages--;
            }
            else
            {
                //byte = _DRV_NVM_WRITE_BUFFER(bufferObjectIndex).buffer[_DRV_NVM_WRITE_BUFFER(bufferObjectIndex).readIndex++];
                //_DRV_NVM_WRITE_BUFFER(bufferObjectIndex).count--;
                //Disable Global interrupts

                PLIB_NVM_FlashAddressToModify(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , address++ );
                PLIB_NVM_FlashProvideData ( _DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ) , byte ) ;

                PLIB_NVM_MemoryModifyEnable(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));
                PLIB_NVM_MemoryOperationSelect(_DRV_NVM_PERIPHERAL_ID_GET ( _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId) ), WORD_PROGRAM_OPERATION );
            }

            while(!PLIB_NVM_FlashWriteCycleHasCompleted(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId)));

            PLIB_NVM_MemoryModifyInhibit(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX  , moduleId));


            asm("ei");
            if ((BUFFER_IsBufferEmpty ( bufferObject )) && !((NVMbufferObject->isPageAligned || NVMbufferObject->isRowAligned)&&NVMbufferObject->NoOfRows))
            {
                /* OSAL --> Lock the instance mutex */
                QUEUE_Pop(&(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , writeQ)));
                /* OSAL --> Unlock the instance mutex */
                _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer)->status =  DRV_NVM_BUFFER_COMPLETED ;

                _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer)->operationalFlags = 0;

                _DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer) = NULL;
            }
        }

        // Check if the transmission is complete
        if(QUEUE_IsEmpty(&(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , eraseQ))) && ((_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , currentEraseBuffer) == NULL )))
        {
            _DRV_NVM_InterruptSourceDisable(_DRV_NVM_GET_INT_SRC(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , txInterruptSource)));
            break;
        }
    }
}


// *****************************************************************************
/*
  Function:
    DRV_NVM_BUFFER_STATUS DRV_NVM_BufferStatus(  const DRV_HANDLE handle,
        const DRV_NVM_BUFFER_HANDLE *bufferHandle);
 */

DRV_NVM_BUFFER_STATUS  _DRV_NVM_MAKE_NAME (BufferTransferStatus)
(
    DRV_HANDLE handle ,
    const DRV_NVM_BUFFER_HANDLE bufferHandle
)
{
    DRV_NVM_BUFFER_OBJ bufferObj = (DRV_NVM_BUFFER_OBJ)0;

    bufferObj = (uint8_t) bufferHandle ;

    return _DRV_NVM_BUFFER_OBJ(bufferObj, status) ;
}

// *****************************************************************************


//******************************************************************************
/* Function:
    unsigned int DRV_NVM_VersionGet( const SYS_MODULE_INDEX drvIndex )

  Summary:
    Gets NVM driver version in numerical format.

  Description:
    This routine gets the NVM driver version. The version is encoded as
    major * 10000 + minor * 100 + patch. The stringized version can be obtained
    using DRV_NVM_VersionStrGet()

  Parameters:
    None.

  Returns:
    Current driver version in numerical format.
*/

unsigned int DRV_NVM_VersionGet()
{
    return( ( _DRV_NVM_VERSION_MAJOR * 10000 ) +
            ( _DRV_NVM_VERSION_MINOR * 100 ) +
            ( _DRV_NVM_VERSION_PATCH ) );

} /* DRV_NVM_VersionGet */


// *****************************************************************************
/* Function:
    char * DRV_NVM_VersionStrGet( const SYS_MODULE_INDEX drvIndex )

  Summary:
    Gets NVM driver version in string format.

  Description:
    This routine gets the NVM driver version. The version is returned as
    major.minor.path[type], where type is optional. The numertical version can
    be obtained using DRV_NVM_VersionGet()

  Parameters:
    None.

  Returns:
    Current NVM driver version in the string format.

  Remarks:
    None.
*/

char * DRV_NVM_VersionStrGet()
{
    return _DRV_NVM_VERSION_STR;

} /* DRV_NVM_VersionStrGet */

void DRV_NVM_InitializeQueues(DRV_NVM_OBJ DRV_NVM_CONFIG_INDEX )
{
    QUEUE_Initialize ( &(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , eraseQ)) , DRV_NVM_NUMBER_OF_BUFFER_OBJECTS , sDrvNVMQueueElementObj ) ;

    QUEUE_Initialize ( &(_DRV_NVM_OBJ(DRV_NVM_CONFIG_INDEX , writeQ)) , DRV_NVM_NUMBER_OF_BUFFER_OBJECTS , sDrvNVMQueueElementObj ) ;
}

// *****************************************************************************
/* static DRV_NVM_BUFFER_OBJECT* _DRV_NVM_GetNextBufferObject ( QUEUE_OBJECT *queue )

   Summary:
    Returns the next available buffer object from the queue

   Description:
    Returns the next available buffer object (whose handle is open) from the queue

   Remarks:
    None
 */

DRV_NVM_BUFFER_OBJECT* _DRV_NVM_GetNextBufferObject ( QUEUE_OBJECT *queue )
{
    QUEUE_ELEMENT_OBJECT    *q_Element      = NULL ;
    DRV_NVM_BUFFER_OBJECT   *bufferObject   = NULL ;

    q_Element = QUEUE_Front ( queue ) ;

    if (q_Element != (QUEUE_ELEMENT_OBJECT *) NULL)
    {
        bufferObject = (DRV_NVM_BUFFER_OBJECT *) q_Element->data ;
    }

    SYS_ASSERT ( ( bufferObject != (DRV_NVM_BUFFER_OBJECT *) NULL ) , " Invalid  buffer Object " ) ;
    if (bufferObject != (DRV_NVM_BUFFER_OBJECT *) NULL)
    {
        bufferObject->status = DRV_NVM_BUFFER_IN_PROGRESS ;
    }

    return bufferObject ;
}



/*******************************************************************************
End of File
*/

