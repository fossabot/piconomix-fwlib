/* =============================================================================
     ____    ___    ____    ___    _   _    ___    __  __   ___  __  __ TM
    |  _ \  |_ _|  / ___|  / _ \  | \ | |  / _ \  |  \/  | |_ _| \ \/ /
    | |_) |  | |  | |     | | | | |  \| | | | | | | |\/| |  | |   \  /
    |  __/   | |  | |___  | |_| | | |\  | | |_| | | |  | |  | |   /  \
    |_|     |___|  \____|  \___/  |_| \_|  \___/  |_|  |_| |___| /_/\_\

    Copyright (c) 2020 Pieter Conradie <https://piconomix.com>
 
    License: MIT
    https://github.com/piconomix/piconomix-fwlib/blob/master/LICENSE.md
 
    Title:          px_exti.h : External interrupt driver
    Author(s):      Pieter Conradie
    Creation Date:  2020-04-13

============================================================================= */

/* _____STANDARD INCLUDES____________________________________________________ */

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "px_exti.h"
#include "px_lib_stm32cube.h"

#include "px_dbg.h"
PX_DBG_DECL_NAME("px_exti")

/* _____LOCAL DEFINITIONS____________________________________________________ */

/* _____MACROS_______________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____LOCAL VARIABLES______________________________________________________ */
#if PX_EXTI_CFG_INT0_EN
static px_exti_handler_t px_exti_0_handler;
#endif
#if PX_EXTI_CFG_INT1_EN
static px_exti_handler_t px_exti_1_handler;
#endif
#if PX_EXTI_CFG_INT2_EN
static px_exti_handler_t px_exti_2_handler;
#endif
#if PX_EXTI_CFG_INT3_EN
static px_exti_handler_t px_exti_3_handler;
#endif
#if PX_EXTI_CFG_INT4_EN
static px_exti_handler_t px_exti_4_handler;
#endif
#if PX_EXTI_CFG_INT5_EN
static px_exti_handler_t px_exti_5_handler;
#endif
#if PX_EXTI_CFG_INT6_EN
static px_exti_handler_t px_exti_6_handler;
#endif
#if PX_EXTI_CFG_INT7_EN
static px_exti_handler_t px_exti_7_handler;
#endif
#if PX_EXTI_CFG_INT8_EN
static px_exti_handler_t px_exti_8_handler;
#endif
#if PX_EXTI_CFG_INT9_EN
static px_exti_handler_t px_exti_9_handler;
#endif
#if PX_EXTI_CFG_INT10_EN
static px_exti_handler_t px_exti_10_handler;
#endif
#if PX_EXTI_CFG_INT11_EN
static px_exti_handler_t px_exti_11_handler;
#endif
#if PX_EXTI_CFG_INT12_EN
static px_exti_handler_t px_exti_12_handler;
#endif
#if PX_EXTI_CFG_INT13_EN
static px_exti_handler_t px_exti_13_handler;
#endif
#if PX_EXTI_CFG_INT14_EN
static px_exti_handler_t px_exti_14_handler;
#endif
#if PX_EXTI_CFG_INT15_EN
static px_exti_handler_t px_exti_15_handler;
#endif

/* _____LOCAL FUNCTION DECLARATIONS__________________________________________ */

/* _____LOCAL FUNCTIONS______________________________________________________ */
#if PX_EXTI_CFG_INT0_EN || PX_EXTI_CFG_INT1_EN
void EXTI0_1_IRQHandler(void)
{
#if PX_EXTI_CFG_INT0_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
        if(px_exti_0_handler) (*px_exti_0_handler)();
    }
#endif

#if PX_EXTI_CFG_INT1_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_1))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_1);
        if(px_exti_1_handler) (*px_exti_1_handler)();
    }
#endif

}
#endif

#if PX_EXTI_CFG_INT2_EN || PX_EXTI_CFG_INT3_EN
void EXTI2_3_IRQHandler(void)
{
#if PX_EXTI_CFG_INT2_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_2))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_2);
        if(px_exti_2_handler) (*px_exti_2_handler)();
    }
#endif

#if PX_EXTI_CFG_INT3_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
        if(px_exti_3_handler) (*px_exti_3_handler)();
    }
#endif

}
#endif

#if    PX_EXTI_CFG_INT4_EN  || PX_EXTI_CFG_INT5_EN  || PX_EXTI_CFG_INT6_EN  \
    || PX_EXTI_CFG_INT7_EN  || PX_EXTI_CFG_INT8_EN  || PX_EXTI_CFG_INT9_EN  \
    || PX_EXTI_CFG_INT10_EN || PX_EXTI_CFG_INT11_EN || PX_EXTI_CFG_INT12_EN \
    || PX_EXTI_CFG_INT13_EN || PX_EXTI_CFG_INT14_EN || PX_EXTI_CFG_INT15_EN
void EXTI4_15_IRQHandler(void)
{
#if PX_EXTI_CFG_INT4_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_4))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_4);
        if(px_exti_4_handler) (*px_exti_4_handler)();
    }
#endif

#if PX_EXTI_CFG_INT5_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_5))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_5);
        if(px_exti_5_handler) (*px_exti_5_handler)();
    }
#endif

#if PX_EXTI_CFG_INT6_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_6))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_6);
        if(px_exti_6_handler) (*px_exti_6_handler)();
    }
#endif

#if PX_EXTI_CFG_INT7_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_7))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_7);
        if(px_exti_7_handler) (*px_exti_7_handler)();
    }
#endif

#if PX_EXTI_CFG_INT8_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_8))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_8);
        if(px_exti_8_handler) (*px_exti_8_handler)();
    }
#endif

#if PX_EXTI_CFG_INT9_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_9))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_9);
        if(px_exti_9_handler) (*px_exti_9_handler)();
    }
#endif

#if PX_EXTI_CFG_INT10_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_10))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_10);
        if(px_exti_10_handler) (*px_exti_10_handler)();
    }
#endif

#if PX_EXTI_CFG_INT11_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_11))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_11);
        if(px_exti_11_handler) (*px_exti_11_handler)();
    }
#endif

#if PX_EXTI_CFG_INT12_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_12))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_12);
        if(px_exti_12_handler) (*px_exti_12_handler)();
    }
#endif

#if PX_EXTI_CFG_INT13_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_13))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_13);
        if(px_exti_13_handler) (*px_exti_13_handler)();
    }
#endif

#if PX_EXTI_CFG_INT14_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_14))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_14);
        if(px_exti_14_handler) (*px_exti_14_handler)();
    }
#endif

#if PX_EXTI_CFG_INT15_EN
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_15))
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_15);
        if(px_exti_15_handler) (*px_exti_15_handler)();
    }
#endif

}
#endif

/* _____GLOBAL FUNCTIONS_____________________________________________________ */
void px_exti_init(void)
{
}

void px_exti_enable(px_exti_port_t    exti_port,
                    px_exti_line_t    exti_line,
                    px_exti_type_t    exti_type,
                    px_exti_handler_t exti_handler)
{
    switch(exti_line)
    {
#if PX_EXTI_CFG_INT0_EN
    case PX_EXTI_LINE_0:
        px_exti_0_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE0);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_0);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_0);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_0);
        }
        NVIC_EnableIRQ(EXTI0_1_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT1_EN
    case PX_EXTI_LINE_1:
        px_exti_1_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE1);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_1);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_1);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_1);
        }
        NVIC_EnableIRQ(EXTI0_1_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT2_EN
    case PX_EXTI_LINE_2:
        px_exti_2_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE2);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_2);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_2);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_2);
        }
        NVIC_EnableIRQ(EXTI2_3_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT3_EN
    case PX_EXTI_LINE_3:
        px_exti_3_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE3);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_3);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_3);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_3);
        }
        NVIC_EnableIRQ(EXTI2_3_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT4_EN
    case PX_EXTI_LINE_4:
        px_exti_4_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE4);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_4);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_4);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_4);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT5_EN
    case PX_EXTI_LINE_5:
        px_exti_5_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE5);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_5);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_5);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_5);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT6_EN
    case PX_EXTI_LINE_6:
        px_exti_6_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE6);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_6);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_6);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_6);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT7_EN
    case PX_EXTI_LINE_7:
        px_exti_7_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE7);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_7);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_7);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_7);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT8_EN
    case PX_EXTI_LINE_8:
        px_exti_8_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE8);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_8);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_8);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_8);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT9_EN
    case PX_EXTI_LINE_9:
        px_exti_9_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE9);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_9);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_9);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_9);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT10_EN
    case PX_EXTI_LINE_10:
        px_exti_10_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE10);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_10);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_10);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_10);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT11_EN
    case PX_EXTI_LINE_11:
        px_exti_11_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE11);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_11);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_11);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_11);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT12_EN
    case PX_EXTI_LINE_12:
        px_exti_12_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE12);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_12);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_12);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_12);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT13_EN
    case PX_EXTI_LINE_13:
        px_exti_13_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE13);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_13);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_13);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_13);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT14_EN
    case PX_EXTI_LINE_14:
        px_exti_14_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE14);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_14);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_14);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_14);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

#if PX_EXTI_CFG_INT15_EN
    case PX_EXTI_LINE_15:
        px_exti_15_handler = exti_handler;
        LL_SYSCFG_SetEXTISource(exti_port, LL_SYSCFG_EXTI_LINE15);
        LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_15);
        if(exti_type == PX_EXTI_TYPE_FALLING_EDGE)
        {
            LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_15);
        }
        else if(exti_type == PX_EXTI_TYPE_RISING_EDGE)
        {
            LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_15);
        }
        NVIC_EnableIRQ(EXTI4_15_IRQn);
        break;
#endif

    default:
        PX_DBG_ERR("Invalid EXTI line specified");
    }
}

void px_exti_disable(px_exti_line_t exti_line)
{
    switch(exti_line)
    {
#if PX_EXTI_CFG_INT0_EN
    case PX_EXTI_LINE_0:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_0);
        px_exti_0_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT1_EN
    case PX_EXTI_LINE_1:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_1);
        px_exti_1_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT2_EN
    case PX_EXTI_LINE_2:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_2);
        px_exti_2_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT3_EN
    case PX_EXTI_LINE_3:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_3);
        px_exti_3_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT4_EN
    case PX_EXTI_LINE_4:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_4);
        px_exti_4_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT5_EN
    case PX_EXTI_LINE_5:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_5);
        px_exti_5_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT6_EN
    case PX_EXTI_LINE_6:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_6);
        px_exti_6_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT7_EN
    case PX_EXTI_LINE_7:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_7);
        px_exti_7_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT8_EN
    case PX_EXTI_LINE_8:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_8);
        px_exti_8_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT9_EN
    case PX_EXTI_LINE_9:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_9);
        px_exti_9_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT10_EN
    case PX_EXTI_LINE_10:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_10);
        px_exti_10_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT11_EN
    case PX_EXTI_LINE_11:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_11);
        px_exti_11_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT12_EN
    case PX_EXTI_LINE_12:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_12);
        px_exti_12_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT13_EN
    case PX_EXTI_LINE_13:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_13);
        px_exti_13_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT14_EN
    case PX_EXTI_LINE_14:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_14);
        px_exti_14_handler = NULL;
        break;
#endif

#if PX_EXTI_CFG_INT15_EN
    case PX_EXTI_LINE_15:
        LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_15);
        px_exti_15_handler = NULL;
        break;
#endif

    default:
        PX_DBG_ERR("Invalid EXTI line specified");
    }
}
