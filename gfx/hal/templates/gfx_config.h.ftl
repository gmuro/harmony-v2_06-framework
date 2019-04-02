#ifndef GFX_CONFIG_H
#define GFX_CONFIG_H

#ifndef LIB_EXPORT
#define LIB_EXPORT
#endif

#define GFX_MAX_BUFFER_COUNT    2
#define GFX_DRIVER_COUNT        1
#define GFX_DISPLAY_COUNT       1
<#if CONFIG_USE_GFX_STACK = true>
<#if CONFIG_DRV_GFX_PROCESSOR_TYPE != "None">
#define GFX_PROCESSOR_COUNT     1
</#if>
</#if>

/* configuration flags */
#define GFX_DRAW_PIPELINE_ENABLED     <#if CONFIG_GFX_HAL_DRAW_PIPELINE_ENABLED == true>1<#else>0</#if>
#define GFX_ALPHA_BLENDING_ENABLED    <#if CONFIG_GFX_HAL_ALPHA_BLENDING_ENABLED == true>1<#else>0</#if>
#define GFX_BOUNDS_CLIPPING_ENABLED   <#if CONFIG_GFX_HAL_BOUNDS_CLIPPING_ENABLED == true>1<#else>0</#if>
#define GFX_COLOR_CONVERSION_ENABLED  <#if CONFIG_GFX_HAL_COLOR_CONVERSION_ENABLED == true>1<#else>0</#if>
#define GFX_COLOR_MASKING_ENABLED     <#if CONFIG_GFX_HAL_COLOR_MASKING_ENABLED == true>1<#else>0</#if>
#define GFX_LAYER_CLIPPING_ENABLED    <#if CONFIG_GFX_HAL_LAYER_CLIPPING_ENABLED == true>1<#else>0</#if>
#define GFX_ORIENTATION_ENABLED       <#if CONFIG_GFX_HAL_ORIENTATION_ENABLED == true>1<#else>0</#if>

#define GFX_DRAW_ARC_ENABLED       <#if CONFIG_GFX_DRAW_ARC_ENABLED == true>1<#else>0</#if>
#define GFX_DRAW_ELLIPSE_ENABLED       <#if CONFIG_GFX_DRAW_ELLIPSE_ENABLED == true>1<#else>0</#if>

<#if CONFIG_USE_GFX_UTILITIES_LIB = true>
#define GFX_UTIL_JPEG_DECODER_ENABLED       <#if CONFIG_GFX_UTIL_JPEG_DECODER_ENABLED == true>1<#else>0</#if>
#define GFX_UTIL_PNG_DECODER_ENABLED       <#if CONFIG_GFX_UTIL_PNG_DECODER_ENABLED == true>1<#else>0</#if>
</#if>

#endif /* GFX_CONFIG_H */