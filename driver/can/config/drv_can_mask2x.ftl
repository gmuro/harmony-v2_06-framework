config DRV_CAN_MASK2_NUMBER_GT_${INSTANCE+1}
    bool
    depends on USE_DRV_CAN
<#if INSTANCE != 0>
	default n if DRV_CAN_MASK2_NUMBER_GT_${INSTANCE} = n     
</#if>	
	default n if DRV_CAN_MASKS_NUMBER2 = ${INSTANCE+1}
	default y
	
config DRV_CAN_MASK2_IDX${INSTANCE}
    depends on USE_DRV_CAN 
<#if INSTANCE != 0>
	             && DRV_CAN_MASK2_NUMBER_GT_${INSTANCE}
</#if>
    bool "CAN Driver 2 Mask ${INSTANCE}"
    default y

ifblock DRV_CAN_MASK2_IDX${INSTANCE}

config DRV_CAN_MASKIDENTIFIER2_IDX${INSTANCE}
	depends on USE_DRV_CAN
        string "CAN MASK Identifier Mode"
        range CAN_ID_TYPE
	default "CAN_SID"
        ---help---
        IDH_HTML_CAN_ID_TYPE
        ---endhelp---

config DRV_CAN_MASKTYPE2_IDX${INSTANCE}
	depends on USE_DRV_CAN
        string "CAN MASK Type"
        range CAN_FILTER_MASK_TYPE
	default "CAN_FILTER_MASK_IDE_TYPE"
        ---help---
        IDH_HTML_CAN_FILTER_MASK_TYPE
        ---endhelp---

config DRV_CAN_MASKACCEPTANCE2_IDX${INSTANCE}
	depends on USE_DRV_CAN
        string "CAN MASK Acceptance Filter"
	default "0x0"
	
endif
