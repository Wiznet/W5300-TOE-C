/**
 * Copyright (c) 2023 WIZnet Co.,Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _W5X00_TIMER_H_
#define _W5X00_TIMER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */

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

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
void wizchip_1msec_timer_initialize(void (*callback)(void));
void wizchip_1msec_timer_callback(void);
void wizchip_1sec_timer_initialize(void (*callback)(void));
void wizchip_1sec_timer_callback(void);
void wizchip_delay_msec(uint32_t msec);
void wizchip_delay_sec(uint32_t sec);
uint32_t wizchip_get_msec_tick(void);
uint32_t wizchip_get_sec_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* _W5X00_TIMER_H_ */
