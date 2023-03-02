/**
 * Copyright (c) 2023 WIZnet Co.,Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */
#include <stdio.h>
#include <time.h>

#if defined(STM32F207xx)
#include "stm32f2xx_hal.h"
#elif defined(STM32F429xx) || (STM32F439xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F722xx) || (STM32F756xx) || (STM32F767xx)
#include "stm32f7xx_hal.h"
#endif

#include "w5x00_timer.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
uint32_t g_time_base = 0;
uint32_t g_sec = 0;
uint32_t g_msec = 0;

void (*msec_timer_callback_ptr)(void);
void (*sec_timer_callback_ptr)(void);

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
void HAL_SYSTICK_Callback(void)
{
  g_time_base++;

  if ((g_time_base % 1) == 0) // uint : 1 millisecond, repeat every millisecond
  {
    g_msec++;

    wizchip_1msec_timer_callback();
  }

  if ((g_time_base % 1000) == 0) // uint : 1 second, repeat every second
  {
    g_sec++;

    wizchip_1sec_timer_callback();
  }
}

void wizchip_1msec_timer_initialize(void (*callback)(void))
{
  msec_timer_callback_ptr = callback;
}

void wizchip_1msec_timer_callback(void)
{
  if (msec_timer_callback_ptr != NULL)
  {
    msec_timer_callback_ptr();
  }
}

void wizchip_1sec_timer_initialize(void (*callback)(void))
{
  sec_timer_callback_ptr = callback;
}

void wizchip_1sec_timer_callback(void)
{
  if (sec_timer_callback_ptr != NULL)
  {
    sec_timer_callback_ptr();
  }
}

void wizchip_delay_msec(uint32_t msec)
{
  HAL_Delay(msec);
}

void wizchip_delay_sec(uint32_t sec)
{
  HAL_Delay(sec * 1000);
}

uint32_t wizchip_get_msec_tick(void)
{
  return g_msec;
}

uint32_t wizchip_get_sec_tick(void)
{
  return g_sec;
}
