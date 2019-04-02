config DRV_I2C_INSTANCES_NUMBER_GT_${INSTANCE+1}
    bool
    depends on USE_DRV_I2C
<#if INSTANCE != 0>
	default n if DRV_I2C_INSTANCES_NUMBER_GT_${INSTANCE} = n     
</#if>	
	default n if DRV_I2C_INSTANCES_NUMBER = ${INSTANCE+1}
	default y
	
config DRV_I2C_INST_IDX${INSTANCE}
    depends on USE_DRV_I2C 
<#if INSTANCE != 0>
	             && DRV_I2C_INSTANCES_NUMBER_GT_${INSTANCE}
</#if>
    bool "I2C Driver Instance ${INSTANCE}"
    default y
    ---help---
    IDH_HTML_DRV_I2C_INSTANCES_NUMBER
    ---endhelp---

ifblock DRV_I2C_INST_IDX${INSTANCE}

menu "RTOS Configuration (Instance ${INSTANCE})"
    depends on USE_DRV_I2C
    depends on USE_3RDPARTY_RTOS
    depends on DRV_I2C_DRIVER_MODE = "DYNAMIC"

config DRV_I2C_RTOS_IDX${INSTANCE}
    string "Run This Driver Instance As"
    depends on DRV_I2C_DRIVER_MODE = "DYNAMIC"
    range 3RDPARTY_RTOS_SYS_TASKS_OPTIONS
    default "Combined with System Tasks"

config DRV_I2C_IDX${INSTANCE}_RTOS_TASK_SIZE
    int "Task Size"
    depends on DRV_I2C_RTOS_IDX${INSTANCE} = "Standalone"
    default 1024

config DRV_I2C_IDX${INSTANCE}_RTOS_TASK_PRIORITY
    int "Task Priority"
    depends on DRV_I2C_RTOS_IDX${INSTANCE} = "Standalone"
    default 1

config DRV_I2C_IDX${INSTANCE}_RTOS_USE_DELAY
    bool "Use Task Delay?"
    depends on DRV_I2C_RTOS_IDX${INSTANCE} = "Standalone"
    default y

config DRV_I2C_IDX${INSTANCE}_RTOS_DELAY
    int "Task Delay"
    depends on DRV_I2C_RTOS_IDX${INSTANCE} = "Standalone"
    depends on DRV_I2C_IDX${INSTANCE}_RTOS_USE_DELAY
    default 1000
endmenu

#	select USE_SYS_TMR_NEEDED
#    select USE_SYS_INT_NEEDED    

config DRV_I2C_BIT_BANG_IDX${INSTANCE}	
    bool "Use Bit Bang I2C Implementation?"
    default y if DRV_I2C_BIT_BANG_NEEDED
    default n
    select DRV_I2C_INTERRUPT_MODE   
	select DRV_I2C_BB_USED
    depends on DRV_I2C_DRIVER_MODE = "DYNAMIC"
    ---help---
    IDH_HTML_I2C_Driver_Library
    ---endhelp---
	
# Currently, the selection of an I2C peripheral defines the IO used.
config DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE}
    string "I2C Module ID"
    depends on USE_DRV_I2C
    range I2C_MODULE_ID
    default "I2C_ID_1"
    ---help---
    IDH_HTML_I2C_MODULE_ID
    ---endhelp---
	
config DRV_SCL_PORT_IDX${INSTANCE}
    string
	depends on USE_DRV_I2C
# For 64 pin parts the pins are decided in drv_i2c.h.ftl  we did this because we couldnt get the Part check to work here
	default "PORT_CHANNEL_A" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
	default "PORT_CHANNEL_A" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"	
	default "PORT_CHANNEL_F" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
	default "PORT_CHANNEL_G" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
	default "PORT_CHANNEL_F" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
	
config DRV_SCL_PIN_POSITION_IDX${INSTANCE}
    string
	depends on USE_DRV_I2C    
	default "PORTS_BIT_POS_14" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
	default "PORTS_BIT_POS_2" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"	
	default "PORTS_BIT_POS_8" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
	default "PORTS_BIT_POS_8" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
	default "PORTS_BIT_POS_5" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
	
config DRV_SDA_PORT_IDX${INSTANCE}
    string
	depends on USE_DRV_I2C    
	default "PORT_CHANNEL_A" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
	default "PORT_CHANNEL_A" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"	
	default "PORT_CHANNEL_F" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
	default "PORT_CHANNEL_G" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
	default "PORT_CHANNEL_F" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
	
config DRV_SDA_PIN_POSITION_IDX${INSTANCE}
    string
	depends on USE_DRV_I2C    
	default "PORTS_BIT_POS_15" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
	default "PORTS_BIT_POS_3" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"	
	default "PORTS_BIT_POS_2" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
	default "PORTS_BIT_POS_7" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
	default "PORTS_BIT_POS_4" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
	
config DRV_I2C_OPERATION_MODE_IDX${INSTANCE}
    string "Operation Mode"
	depends on USE_DRV_I2C
	depends on DRV_I2C_DRIVER_MODE = "DYNAMIC"
    range DRV_I2C_OP_MODE
    default "DRV_I2C_MODE_MASTER"
    ---help---
    IDH_HTML_PLIB_I2C_Initializing_the_I2C
    ---endhelp---

config DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE}
    string "Operation Mode"
	depends on USE_DRV_I2C
	depends on (DRV_I2C_STATIC_DRIVER_MODE = "BYTE_MODEL_STATIC" || DRV_I2C_STATIC_DRIVER_MODE = "BUFFER_MODEL_STATIC" || DRV_I2C_STATIC_DRIVER_MODE = "STATIC" )
    range DRV_I2C_OP_MODE	
    default "DRV_I2C_MODE_MASTER"
    ---help---
    IDH_HTML_PLIB_I2C_Initializing_the_I2C
    ---endhelp---

	
ifblock (DRV_I2C_BIT_BANG_IDX${INSTANCE})
	
config DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE}
    string "Bit Bang Timer Source"
    depends on USE_DRV_I2C
    range TMR_MODULE_ID
    default "TMR_ID_1" if TMR_NUMBER_OF_MODULES = 1
    default "TMR_ID_2" if TMR_NUMBER_OF_MODULES = 2
    default "TMR_ID_3" if TMR_NUMBER_OF_MODULES = 3
    default "TMR_ID_4" if TMR_NUMBER_OF_MODULES = 4
    default "TMR_ID_5" if TMR_NUMBER_OF_MODULES = 5
    default "TMR_ID_6" if TMR_NUMBER_OF_MODULES = 6
    default "TMR_ID_7" if TMR_NUMBER_OF_MODULES = 7
    default "TMR_ID_8" if TMR_NUMBER_OF_MODULES = 8
    default "TMR_ID_9" if TMR_NUMBER_OF_MODULES = 9
    default "TMR_ID_10" if TMR_NUMBER_OF_MODULES = 10
    default "TMR_ID_11" if TMR_NUMBER_OF_MODULES = 11
    default "TMR_ID_12" if TMR_NUMBER_OF_MODULES = 12

    ---help---
    IDH_HTML_PLIB_I2C_Initializing_the_I2C
    ---endhelp---

	#TODO  The selection of slave IO and the enabling of Change Notification has to go in here.

	
	
config DRV_I2C_BIT_BANG_BAUD_RATE_IDX${INSTANCE}
    int "I2C CLOCK FREQUENCY (Hz)"
    depends on USE_DRV_I2C
	depends on DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default 50000
    ---help---
    IDH_HTML_PLIB_I2C_BaudRateSet_I2C_MODULE_ID_uint32_t_I2C_BAUD_RATE
    ---endhelp---
	

config DRV_I2C_BIT_BANG_INT_SRC_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on DRV_I2C_BIT_BANG_IDX${INSTANCE}
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER")
    default "INT_SOURCE_TIMER_1" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_1"
    default "INT_SOURCE_TIMER_2" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_2"
    default "INT_SOURCE_TIMER_3" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_3"
    default "INT_SOURCE_TIMER_4" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_4"
    default "INT_SOURCE_TIMER_5" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_5"
    default "INT_SOURCE_TIMER_6" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_6"
    default "INT_SOURCE_TIMER_7" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_7"
    default "INT_SOURCE_TIMER_8" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_8"
    default "INT_SOURCE_TIMER_9" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_9"


config DRV_I2C_BIT_BANG_INT_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
    default "INT_VECTOR_T1" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_1"
    default "INT_VECTOR_T2" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_2"
    default "INT_VECTOR_T3" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_3"
    default "INT_VECTOR_T4" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_4"
    default "INT_VECTOR_T5" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_5"
    default "INT_VECTOR_T6" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_6"
    default "INT_VECTOR_T7" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_7"
    default "INT_VECTOR_T8" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_8"
    default "INT_VECTOR_T9" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_9"

config DRV_I2C_BIT_BANG_ISR_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
    default "_TIMER_1_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_1"
    default "_TIMER_2_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_2"
    default "_TIMER_3_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_3"
    default "_TIMER_4_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_4"
    default "_TIMER_5_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_5"
    default "_TIMER_6_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_6"
    default "_TIMER_7_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_7"
    default "_TIMER_8_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_8"
    default "_TIMER_9_VECTOR" if DRV_I2C_BIT_BANG_TMR_MODULE_IDX${INSTANCE} = "TMR_ID_9"

config DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE}
    string "I2C Interrupt Priority"
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
    range INT_PRIORITY_LEVEL
    default "INT_PRIORITY_LEVEL3"
    ---help---
    IDH_HTML_INT_PRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_BIT_BANG_INT_SUB_PRIORITY_IDX${INSTANCE}
    string "I2C Interrupt Sub-priority"
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
    range INT_SUBPRIORITY_LEVEL
    default "INT_SUBPRIORITY_LEVEL0"
    ---help---
    IDH_HTML_INT_SUBPRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_BIT_BANG_INT_PRIO_NUM_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
    default "0" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_DISABLE_INTERRUPT"
    default "1" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL1"
    default "2" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL2"
    default "3" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL3"
    default "4" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL4"
    default "5" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL5"
    default "6" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL6"
    default "7" if DRV_I2C_BIT_BANG_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL7"
endif


	
	
ifblock !DRV_I2C_BIT_BANG_IDX${INSTANCE}

config DRV_I2C_MASTER_INT_SRC_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER") || (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER")
    default "INT_SOURCE_I2C_1_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_SOURCE_I2C_2_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_SOURCE_I2C_3_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_SOURCE_I2C_4_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_SOURCE_I2C_5_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"

config DRV_I2C_SLAVE_INT_SRC_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE") || (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE")
    default "INT_SOURCE_I2C_1_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_SOURCE_I2C_2_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_SOURCE_I2C_3_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_SOURCE_I2C_4_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_SOURCE_I2C_5_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"


	
	
# PIC32MX

config DRV_I2C_ERR_MX_INT_SRC_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default "INT_SOURCE_I2C_1_ERROR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_SOURCE_I2C_2_ERROR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_SOURCE_I2C_3_ERROR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_SOURCE_I2C_4_ERROR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_SOURCE_I2C_5_ERROR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
	
config DRV_I2C_INT_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default "INT_VECTOR_I2C1" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_VECTOR_I2C2" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_VECTOR_I2C3" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_VECTOR_I2C4" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_VECTOR_I2C5" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"

config DRV_I2C_ISR_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE && PIC32MX
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default "_I2C_1_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "_I2C_2_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "_I2C_3_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "_I2C_4_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "_I2C_5_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"

config DRV_I2C_INT_PRIORITY_IDX${INSTANCE}
    string "I2C Interrupt Priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && PIC32MX
    range INT_PRIORITY_LEVEL
    default "INT_PRIORITY_LEVEL1"
    ---help---
    IDH_HTML_INT_PRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_INT_SUB_PRIORITY_IDX${INSTANCE}
    string "I2C Interrupt Sub-priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && PIC32MX
    range INT_SUBPRIORITY_LEVEL
    default "INT_SUBPRIORITY_LEVEL0"
    ---help---
    IDH_HTML_INT_SUBPRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_INT_PRIO_NUM_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE && PIC32MX
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default "0" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_DISABLE_INTERRUPT"
    default "1" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL1"
    default "2" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL2"
    default "3" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL3"
    default "4" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL4"
    default "5" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL5"
    default "6" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL6"
    default "7" if DRV_I2C_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL7"

# PIC32MZ
# Master
config DRV_I2C_MASTER_INT_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE
    default "INT_VECTOR_I2C1_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_VECTOR_I2C2_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_VECTOR_I2C3_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_VECTOR_I2C4_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_VECTOR_I2C5_MASTER" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"

config DRV_I2C_MASTER_ISR_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK)
    default "_I2C1_MASTER_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "_I2C2_MASTER_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "_I2C3_MASTER_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "_I2C4_MASTER_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "_I2C5_MASTER_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"


config DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE}
    string "Master Interrupt Priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER") || (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER")
    range INT_PRIORITY_LEVEL
    default "INT_PRIORITY_LEVEL1"
    ---help---
    IDH_HTML_INT_PRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_MASTER_INT_SUB_PRIORITY_IDX${INSTANCE}
    string "Master Interrupt Sub-priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER") || (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER")
    range INT_SUBPRIORITY_LEVEL
    default "INT_SUBPRIORITY_LEVEL0"

config DRV_I2C_MASTER_INT_PRIO_NUM_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
    default "0" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_DISABLE_INTERRUPT"
    default "1" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL1"
    default "2" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL2"
    default "3" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL3"
    default "4" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL4"
    default "5" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL5"
    default "6" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL6"
    default "7" if DRV_I2C_MASTER_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL7"

# Slave
config DRV_I2C_SLAVE_INT_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE
    default "INT_VECTOR_I2C1_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_VECTOR_I2C2_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_VECTOR_I2C3_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_VECTOR_I2C4_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_VECTOR_I2C5_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
    default "INT_VECTOR_I2C6_SLAVE" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_6"

config DRV_I2C_SLAVE_ISR_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
    default "_I2C1_SLAVE_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "_I2C2_SLAVE_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "_I2C3_SLAVE_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "_I2C4_SLAVE_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "_I2C5_SLAVE_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
    default "_I2C6_SLAVE_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_6"

config DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE}
    string "Slave Interrupt Priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE") || (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE")
    range INT_PRIORITY_LEVEL
    default "INT_PRIORITY_LEVEL1"
    ---help---
    IDH_HTML_INT_PRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_SLAVE_INT_SUB_PRIORITY_IDX${INSTANCE}
    string "Slave Interrupt Sub-priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
	depends on (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE") || (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE")
    range INT_SUBPRIORITY_LEVEL
    default "INT_SUBPRIORITY_LEVEL0"
    ---help---
    IDH_HTML_INT_SUBPRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_SLAVE_INT_PRIO_NUM_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
    default "0" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_DISABLE_INTERRUPT"
    default "1" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL1"
    default "2" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL2"
    default "3" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL3"
    default "4" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL4"
    default "5" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL5"
    default "6" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL6"
    default "7" if DRV_I2C_SLAVE_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL7"

#Error
config DRV_I2C_ERR_MZ_INT_SRC_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default "INT_SOURCE_I2C_1_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_SOURCE_I2C_2_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_SOURCE_I2C_3_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_SOURCE_I2C_4_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_SOURCE_I2C_5_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
	
config DRV_I2C_ERR_INT_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
    depends on DRV_I2C_INTERRUPT_MODE
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default "INT_VECTOR_I2C1_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "INT_VECTOR_I2C2_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "INT_VECTOR_I2C3_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "INT_VECTOR_I2C4_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "INT_VECTOR_I2C5_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
    default "INT_VECTOR_I2C6_BUS" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_6"

config DRV_I2C_ERR_ISR_VECTOR_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
    default "_I2C1_BUS_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1"
    default "_I2C2_BUS_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"
    default "_I2C3_BUS_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3"
    default "_I2C4_BUS_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"
    default "_I2C5_BUS_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_5"
    default "_I2C6_BUS_VECTOR" if DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_6"

config DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE}
    string "Error Interrupt Priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK  || PIC32MK )
    range INT_PRIORITY_LEVEL
    default "INT_PRIORITY_LEVEL1"
    ---help---
    IDH_HTML_INT_PRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_ERR_INT_SUB_PRIORITY_IDX${INSTANCE}
    string "Error Interrupt Sub-priority"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
    range INT_SUBPRIORITY_LEVEL
    default "INT_SUBPRIORITY_LEVEL0"
    ---help---
    IDH_HTML_INT_SUBPRIORITY_LEVEL
    ---endhelp---

config DRV_I2C_ERR_INT_PRIO_NUM_IDX${INSTANCE}
    string
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    depends on DRV_I2C_INTERRUPT_MODE && ( PIC32MZ || PIC32WK || PIC32MK )
    default "0" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_DISABLE_INTERRUPT"
    default "1" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL1"
    default "2" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL2"
    default "3" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL3"
    default "4" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL4"
    default "5" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL5"
    default "6" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL6"
    default "7" if DRV_I2C_ERR_INT_PRIORITY_IDX${INSTANCE} = "INT_PRIORITY_LEVEL7"
endif
	
ifblock (DRV_I2C_STATIC_DRIVER_MODE = "STATIC" || DRV_I2C_STATIC_DRIVER_MODE = "BYTE_MODEL_STATIC" || DRV_I2C_STATIC_DRIVER_MODE = "BUFFER_MODEL_STATIC") && (!DRV_I2C_BIT_BANG_IDX${INSTANCE})
	
config DRV_I2C_STATIC_SMBus_SPECIFICATION_IDX${INSTANCE}
    bool
	depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
	default n
    ---help---
    IDH_HTML_PLIB_I2C_SMBDisable_I2C_MODULE_ID
    ---endhelp---
	
ifblock (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER") && (!DRV_I2C_BIT_BANG_IDX${INSTANCE})

config DRV_I2C_STATIC_BRG_CLOCK_IDX${INSTANCE}
    int "Baud Rate Generator Clock"
    depends on USE_DRV_I2C
	depends on DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER"
    default SYS_CLK_PBCLK_FREQ if PIC32MX
    default SYS_CLK_PBCLK1_FREQ  if PIC32MZ
	default SYS_CLK_PBCLK1_FREQ  if ( PIC32MK && (DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1" || DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2" ))
	default SYS_CLK_PBCLK2_FREQ  if ( PIC32MK && (DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3" || DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4" ))
    default SYS_CLK_PBCLK2_FREQ  if ( PIC32WK && DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1")
    default SYS_CLK_PBCLK3_FREQ  if ( PIC32WK && DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2")
	persistent
    ---help---
    IDH_HTML_CLK_SOURCES_SYSTEM
    ---endhelp---
	
config DRV_I2C_STATIC_BAUD_RATE_IDX${INSTANCE}
    int "I2C CLOCK FREQUENCY (Hz)"
    depends on USE_DRV_I2C
    default 50000
    ---help---
    IDH_HTML_PLIB_I2C_BaudRateSet_I2C_MODULE_ID_uint32_t_I2C_BAUD_RATE
    ---endhelp---

config DRV_I2C_STATIC_SLEW_RATE_CONTROL_IDX${INSTANCE}
    bool "Slew Rate Control"
	depends on USE_DRV_I2C
	depends on DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER"
	default n
    ---help---
    IDH_HTML_PLIB_I2C_HighFrequencyEnable_I2C_MODULE_ID
    ---endhelp---
	
endif

ifblock (DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE") && (!DRV_I2C_BIT_BANG_IDX${INSTANCE})

config DRV_I2C_STATIC_ADDRESS_WIDTH_IDX${INSTANCE}
    string "Slave Address Width"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
    range DRV_I2C_ADDRESS_WIDTH
	default "DRV_I2C_7BIT_SLAVE"
    ---help---
    IDH_HTML_PLIB_I2C_SlaveAddress10BitWasDetected_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_STATIC_STRICT_ADDRESS_RULE_IDX${INSTANCE}
    bool "Strict Address rule"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default y
    ---help---
    IDH_HTML_PLIB_I2C_ReservedAddressProtectEnable_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_STATIC_GENERAL_CALL_ADDRESS_IDX${INSTANCE}
    bool "General Call Address"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default n
    ---help---
    IDH_HTML_PLIB_I2C_GeneralCallDisable_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_STATIC_CLOCK_STRETCH_IDX${INSTANCE}
    bool "Clock Stretch Enable"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default y
    ---help---
    IDH_HTML_PLIB_I2C_SlaveClockStretchingEnable_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_STATIC_SLAVE_ADDRESS_MASK_IDX${INSTANCE}
    hex "Slave Address Mask (hexadecimal)"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default 0x00
    ---help---
    IDH_HTML_PLIB_I2C_SlaveMask7BitSet_I2C_MODULE_ID_uint8_t
    ---endhelp---

config DRV_I2C_STATIC_SLAVE_ADDRESS_VALUE_IDX${INSTANCE}
    hex "Slave Address Value (hexadecimal)"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default 0x00
    ---help---
    IDH_HTML_PLIB_I2C_SlaveAddress7BitSet_I2C_MODULE_ID_uint8_t
    ---endhelp---
    
config DRV_I2C_STATIC_SLAVE_CALLBACK_FUNCTION_IDX${INSTANCE}
    string "Callback function name"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_STATIC_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default "APP_I2C_SlaveTransfer_Callback"

	
endif

config DRV_I2C_STATIC_POWER_STATE_IDX${INSTANCE}
    string "Power State"
    depends on USE_DRV_I2C
    range SYS_MODULE_POWER_STATE
    default "SYS_MODULE_POWER_RUN_FULL"
    ---help---
    IDH_HTML_SYS_MODULE_INIT
    ---endhelp---

endif

ifblock DRV_I2C_DRIVER_MODE = "DYNAMIC" && (!DRV_I2C_BIT_BANG_IDX${INSTANCE})

config DRV_I2C_STOP_IN_IDLE_IDX${INSTANCE}
    bool 
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    default n
    ---help---
    IDH_HTML_DRV_I2C_STOP_IDLE_FLAGS
    ---endhelp---

config DRV_I2C_SMBus_SPECIFICATION_IDX${INSTANCE}
    bool 
	depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
	default n
    ---help---
    IDH_HTML_PLIB_I2C_SMBDisable_I2C_MODULE_ID
    ---endhelp---

	
ifblock (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER") && (!DRV_I2C_BIT_BANG_IDX${INSTANCE})

config DRV_I2C_BRG_CLOCK_IDX${INSTANCE}
    int "Baud Rate Generator Clock"
    depends on USE_DRV_I2C
	depends on DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER"
    default SYS_CLK_PBCLK_FREQ if PIC32MX
    default SYS_CLK_PBCLK1_FREQ  if PIC32MZ
    default SYS_CLK_PBCLK1_FREQ  if ( PIC32MK && (DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1" || DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2"))
    default SYS_CLK_PBCLK2_FREQ  if ( PIC32MK && (DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_3" || DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_4"))	
    default SYS_CLK_PBCLK2_FREQ  if ( PIC32WK && DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_1")
    default SYS_CLK_PBCLK3_FREQ  if ( PIC32WK && DRV_I2C_PERIPHERAL_ID_IDX${INSTANCE} = "I2C_ID_2")
	persistent
    ---help---
    IDH_HTML_CLK_SOURCES_SYSTEM
    ---endhelp---
	
config DRV_I2C_BAUD_RATE_IDX${INSTANCE}
    int "I2C CLOCK FREQUENCY (Hz)"
    depends on USE_DRV_I2C
    default 50000
    ---help---
    IDH_HTML_PLIB_I2C_BaudRateSet_I2C_MODULE_ID_uint32_t_I2C_BAUD_RATE
    ---endhelp---

config DRV_I2C_SLEW_RATE_CONTROL_IDX${INSTANCE}
    bool "Slew Rate Control"
	depends on USE_DRV_I2C
	depends on DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_MASTER"
	default n
    ---help---
    IDH_HTML_PLIB_I2C_HighFrequencyEnable_I2C_MODULE_ID
    ---endhelp---
	
endif

ifblock (DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE") && (!DRV_I2C_BIT_BANG_IDX${INSTANCE})

config DRV_I2C_ADDRESS_WIDTH_IDX${INSTANCE}
    string "Slave Address Width"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
    range DRV_I2C_ADDRESS_WIDTH
	default "DRV_I2C_7BIT_SLAVE"
    ---help---
    IDH_HTML_PLIB_I2C_SlaveAddress10BitWasDetected_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_STRICT_ADDRESS_RULE_IDX${INSTANCE}
    bool "Strict Address rule"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default y
    ---help---
    IDH_HTML_PLIB_I2C_ReservedAddressProtectEnable_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_GENERAL_CALL_ADDRESS_IDX${INSTANCE}
    bool "General Call Address"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default n
    ---help---
    IDH_HTML_PLIB_I2C_GeneralCallDisable_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_CLOCK_STRETCH_IDX${INSTANCE}
    bool "Clock Stretch Enable"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default y
    ---help---
    IDH_HTML_PLIB_I2C_SlaveClockStretchingEnable_I2C_MODULE_ID
    ---endhelp---
	
config DRV_I2C_SLAVE_ADDRESS_MASK_IDX${INSTANCE}
    hex "Slave Address Mask"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default 0x00
    ---help---
    IDH_HTML_PLIB_I2C_SlaveMask7BitSet_I2C_MODULE_ID_uint8_t
    ---endhelp---

config DRV_I2C_SLAVE_ADDRESS_VALUE_IDX${INSTANCE}
    hex "Slave Address Value"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default 0x00
    ---help---
    IDH_HTML_PLIB_I2C_SlaveAddress7BitSet_I2C_MODULE_ID_uint8_t
    ---endhelp---
    
config DRV_I2C_SLAVE_CALLBACK_FUNCTION_IDX${INSTANCE}
    string "Callback function name"
	depends on USE_DRV_I2C
	depends on  DRV_I2C_OPERATION_MODE_IDX${INSTANCE} = "DRV_I2C_MODE_SLAVE"
	default "APP_I2C_SlaveTransfer_Callback"
	
endif

config DRV_I2C_POWER_STATE_IDX${INSTANCE}
    string "Power State"
    depends on USE_DRV_I2C
	depends on !DRV_I2C_BIT_BANG_IDX${INSTANCE}
    range SYS_MODULE_POWER_STATE
    default "SYS_MODULE_POWER_RUN_FULL"
    ---help---
    IDH_HTML_SYS_MODULE_INIT
    ---endhelp---

endif
endif




	
