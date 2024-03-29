<#--
/*******************************************************************************
  AK4642 Driver Freemarker Template File

  Company:
    Microchip Technology Inc.

  File Name:
    drv_ak4642.ftl

  Summary:
    AK4642 Driver Freemarker Template File

  Description:

*******************************************************************************/

/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

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
-->

/*** Codec Driver Configuration ***/

<#if CONFIG_USE_DRV_CODEC_AK4642 ==  true>
#define DRV_AK4642_CLIENTS_NUMBER                           ${CONFIG_DRV_AK4642_CLIENTS_NUMBER}
#define DRV_AK4642_INSTANCES_NUMBER                         1
<#if CONFIG_SYS_CLK_REFCLK_ENABLE?has_content><#if CONFIG_SYS_CLK_REFCLK_ENABLE == true>
#define DRV_AK4642_INPUT_REFCLOCK    	                	${CONFIG_SYS_CLK_REFCLK_ROSEL}
</#if></#if>
<#if CONFIG_SYS_CLK_REFCLK0_ENABLE?has_content><#if CONFIG_SYS_CLK_REFCLK0_ENABLE == true>
#define DRV_AK4642_INPUT_REFCLOCK    	                	${CONFIG_SYS_CLK_REFCLK_ROSEL0}
</#if></#if>
<#if CONFIG_SYS_CLK_REFCLK1_ENABLE?has_content><#if CONFIG_SYS_CLK_REFCLK1_ENABLE == true>
#define DRV_AK4642_INPUT_REFCLOCK    	                	${CONFIG_SYS_CLK_REFCLK_ROSEL1}
</#if></#if>
<#if CONFIG_SYS_CLK_REFCLK2_ENABLE?has_content><#if CONFIG_SYS_CLK_REFCLK2_ENABLE == true>
#define DRV_AK4642_INPUT_REFCLOCK    	                	${CONFIG_SYS_CLK_REFCLK_ROSEL2}
</#if></#if>
<#if CONFIG_SYS_CLK_REFCLK3_ENABLE?has_content><#if CONFIG_SYS_CLK_REFCLK3_ENABLE == true>
#define DRV_AK4642_INPUT_REFCLOCK    	                	${CONFIG_SYS_CLK_REFCLK_ROSEL3}
</#if></#if>
#define DRV_AK4642_AUDIO_SAMPLING_RATE                      ${CONFIG_DRV_I2S_BAUD_RATE}
#define DRV_AK4642_MCLK_SAMPLE_FREQ_MULTPLIER               (SYS_CLK_BUS_REFERENCE_1/DRV_AK4642_AUDIO_SAMPLING_RATE)
#define DRV_AK4642_BCLK_BIT_CLK_DIVISOR                     ${CONFIG_DRV_AK4642_BCLK_BIT_CLK_DIVISOR}

<#-- Instance 0 -->
<#if CONFIG_DRV_CODEC_AK4642_INST_IDX0 == true>
#define DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0             ${CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0}
#define DRV_AK4642_I2C_DRIVER_MODULE_INDEX_IDX0             ${CONFIG_DRV_AK4642_I2C_DRIVER_MODULE_INDEX_IDX0}
#define DRV_AK4642_VOLUME                                   ${CONFIG_DRV_AK4642_VOLUME}	
#define DRV_AK4642_VOLUME_MIN                               0x0                                           
#define DRV_AK4642_VOLUME_MAX                               0xFF
<#if CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0 == "DRV_I2S_INDEX_0">
<#if CONFIG_SPI_AUDIO_COMM_WIDTH_IDX0 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_32CHANNEL"  || CONFIG_SPI_AUDIO_COMM_WIDTH_IDX0 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_16CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX0 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX0 == "DRV_I2S_AUDIO_LFET_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITMSB_SDTI
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX0 == "DRV_I2S_AUDIO_RIGHT_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITLSB_SDTI
</#if>
<#elseif CONFIG_SPI_AUDIO_COMM_WIDTH_IDX0 == "SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX0 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#else>
#error "The AK4642 CODEC driver does not supports the selected combination of "Audio Communication Width" and "Audio Protocol Mode" in i2s driver configuration"  
</#if>
</#if>
<#if CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0 == "DRV_I2S_INDEX_1">
<#if CONFIG_SPI_AUDIO_COMM_WIDTH_IDX1 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_32CHANNEL"  || CONFIG_SPI_AUDIO_COMM_WIDTH_IDX1 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_16CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX1 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX1 == "DRV_I2S_AUDIO_LFET_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITMSB_SDTI
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX1 == "DRV_I2S_AUDIO_RIGHT_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITLSB_SDTI
</#if>
<#elseif CONFIG_SPI_AUDIO_COMM_WIDTH_IDX1 == "SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX1 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#else>
#error "The AK4642 CODEC driver does not supports the selected combination of "Audio Communication Width" and "Audio Protocol Mode" in i2s driver configuration"  
</#if>
</#if>
<#if CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0 == "DRV_I2S_INDEX_2">
<#if CONFIG_SPI_AUDIO_COMM_WIDTH_IDX2 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_32CHANNEL"  || CONFIG_SPI_AUDIO_COMM_WIDTH_IDX2 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_16CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX2 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX2 == "DRV_I2S_AUDIO_LFET_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITMSB_SDTI
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX2 == "DRV_I2S_AUDIO_RIGHT_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITLSB_SDTI
</#if>
<#elseif CONFIG_SPI_AUDIO_COMM_WIDTH_IDX2 == "SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX2 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#else>
#error "The AK4642 CODEC driver does not supports the selected combination of "Audio Communication Width" and "Audio Protocol Mode" in i2s driver configuration"  
</#if>
</#if>
<#if CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0 == "DRV_I2S_INDEX_3">
<#if CONFIG_SPI_AUDIO_COMM_WIDTH_IDX3 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_32CHANNEL"  || CONFIG_SPI_AUDIO_COMM_WIDTH_IDX3 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_16CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX3 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX3 == "DRV_I2S_AUDIO_LFET_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITMSB_SDTI
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX3 == "DRV_I2S_AUDIO_RIGHT_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITLSB_SDTI
</#if>
<#elseif CONFIG_SPI_AUDIO_COMM_WIDTH_IDX3 == "SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX3 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#else>
#error "The AK4642 CODEC driver does not supports the selected combination of "Audio Communication Width" and "Audio Protocol Mode" in i2s driver configuration"  
</#if>
</#if>
<#if CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0 == "DRV_I2S_INDEX_4">
<#if CONFIG_SPI_AUDIO_COMM_WIDTH_IDX4 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_32CHANNEL"  || CONFIG_SPI_AUDIO_COMM_WIDTH_IDX4 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_16CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX4 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX4 == "DRV_I2S_AUDIO_LFET_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITMSB_SDTI
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX4 == "DRV_I2S_AUDIO_RIGHT_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITLSB_SDTI
</#if>
<#elseif CONFIG_SPI_AUDIO_COMM_WIDTH_IDX4 == "SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX4 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#else>
#error "The AK4642 CODEC driver does not supports the selected combination of "Audio Communication Width" and "Audio Protocol Mode" in i2s driver configuration"  
</#if>
</#if>
<#if CONFIG_DRV_AK4642_I2S_DRIVER_MODULE_INDEX_IDX0 == "DRV_I2S_INDEX_5">
<#if CONFIG_SPI_AUDIO_COMM_WIDTH_IDX5 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_32CHANNEL"  || CONFIG_SPI_AUDIO_COMM_WIDTH_IDX5 == "SPI_AUDIO_COMMUNICATION_16DATA_16FIFO_16CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX5 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX5 == "DRV_I2S_AUDIO_LFET_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITMSB_SDTI
</#if>
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX5 == "DRV_I2S_AUDIO_RIGHT_JUSTIFIED">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_16BITMSB_SDTO_16BITLSB_SDTI
</#if>
<#elseif CONFIG_SPI_AUDIO_COMM_WIDTH_IDX5 == "SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL">
<#if CONFIG_DRV_I2S_AUDIO_PROTOCOL_MODE_IDX5 == "DRV_I2S_AUDIO_I2S">
#define DRV_AK4642_AUDIO_DATA_FORMAT_MACRO                  DRV_AK4642_AUDIO_DATA_FORMAT_I2S
</#if>
<#else>
#error "The AK4642 CODEC driver does not supports the selected combination of "Audio Communication Width" and "Audio Protocol Mode" in i2s driver configuration"  
</#if>
</#if>
</#if> 
</#if> 
/* CODEC Driver Abstraction definition */

#define DRV_CODEC_INDEX_0                                   DRV_AK4642_INDEX_0
#define sysObjdrvCodec0                                     sysObj.drvak4642Codec0
#define DRV_CODEC_CHANNEL                                   DRV_AK4642_CHANNEL
#define DRV_CODEC_CHANNEL_LEFT                              DRV_AK4642_CHANNEL_LEFT
#define DRV_CODEC_CHANNEL_RIGHT                             DRV_AK4642_CHANNEL_RIGHT
#define DRV_CODEC_CHANNEL_LEFT_RIGHT                        DRV_AK4642_CHANNEL_LEFT_RIGHT
#define DRV_CODEC_BUFFER_HANDLE                             DRV_AK4642_BUFFER_HANDLE
#define DRV_CODEC_BUFFER_HANDLE_INVALID                     DRV_AK4642_BUFFER_HANDLE_INVALID
#define DRV_CODEC_BUFFER_EVENT_HANDLER                      DRV_AK4642_BUFFER_EVENT_HANDLER
#define DRV_CODEC_BUFFER_EVENT                              DRV_AK4642_BUFFER_EVENT
#define DRV_CODEC_BUFFER_EVENT_COMPLETE                     DRV_AK4642_BUFFER_EVENT_COMPLETE
#define DRV_CODEC_BUFFER_EVENT_ERROR                        DRV_AK4642_BUFFER_EVENT_ERROR
#define DRV_CODEC_BUFFER_EVENT_ABORT                        DRV_AK4642_BUFFER_EVENT_ABORT
#define DRV_CODEC_COMMAND_EVENT_HANDLER                     DRV_AK4642_COMMAND_EVENT_HANDLER
#define DRV_CODEC_VOLUME_MIN                                DRV_AK4642_VOLUME_MIN
#define DRV_CODEC_VOLUME_MAX                                DRV_AK4642_VOLUME_MAX
//#define DRV_CODEC_MICROPHONE_TYPE                         DRV_AK4642_INT_EXT_MIC
#define DRV_CODEC_MICROPHONE_SELECT                         DRV_AK4642_MIC
#define DRV_CODEC_MICROPHONE_SELECT_1                       MIC1
#define DRV_CODEC_MICROPHONE_SELECT_2                       MIC2
#define DRV_CODEC_MICROPHONE_TYPE_INTERNAL                  INT_MIC
#define DRV_CODEC_MICROPHONE_TYPE_EXTERNAL                  EXT_MIC
#define DRV_CODEC_MICROPHONE_SOUND                          DRV_AK4642_MONO_STEREO_MIC
#define DRV_CODEC_MICROPHONE_SOUND_NONE                     ALL_ZEROS
#define DRV_CODEC_MICROPHONE_SOUND_MONO_RIGHT               MONO_RIGHT_CHANNEL
#define DRV_CODEC_MICROPHONE_SOUND_MONO_LEFT                MONO_LEFT_CHANNEL
#define DRV_CODEC_MICROPHONE_SOUND_STEREO                   STEREO

#define DRV_CODEC_Initialize                                DRV_AK4642_Initialize
#define DRV_CODEC_Deinitialize                              DRV_AK4642_Deinitialize
#define DRV_CODEC_Status                                    DRV_AK4642_Status
#define DRV_CODEC_Tasks                                     DRV_AK4642_Tasks
#define DRV_CODEC_Open                                      DRV_AK4642_Open
#define DRV_CODEC_Close                                     DRV_AK4642_Close
#define DRV_CODEC_BufferEventHandlerSet                     DRV_AK4642_BufferEventHandlerSet
#define DRV_CODEC_BufferAddWrite                            DRV_AK4642_BufferAddWrite
#define DRV_CODEC_BufferAddRead                             DRV_AK4642_BufferAddRead
#define DRV_CODEC_BufferAddWriteRead                        DRV_AK4642_BufferAddWriteRead
#define DRV_CODEC_SamplingRateSet                           DRV_AK4642_SamplingRateSet
#define DRV_CODEC_SamplingRateGet                           DRV_AK4642_SamplingRateGet
#define DRV_CODEC_VolumeSet                                 DRV_AK4642_VolumeSet
#define DRV_CODEC_VolumeGet                                 DRV_AK4642_VolumeGet
#define DRV_CODEC_MuteOn                                    DRV_AK4642_MuteOn
#define DRV_CODEC_MuteOff                                   DRV_AK4642_MuteOff

#define DRV_CODEC_MicrophoneTypeSet                         DRV_AK4642_IntExtMicSet
#define DRV_CODEC_MicSet                                    DRV_AK4642_MicSet
#define DRV_CODEC_BufferQueueFlush                          DRV_AK4642_BufferQueueFlush

#define DRV_CODEC_MicrophoneSoundSet                        DRV_AK4642_MonoStereoMicSet
#define DRV_CODEC_SetAudioCommunicationMode                 DRV_AK4642_SetAudioCommunicationMode
#define DRV_CODEC_CommandEventHandlerSet                    DRV_AK4642_CommandEventHandlerSet


<#--
/*******************************************************************************
 End of File
*/
-->
