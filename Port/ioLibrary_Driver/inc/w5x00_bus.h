/**
 * Copyright (c) 2023 WIZnet Co.,Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _W5X00_BUS_H_
#define _W5X00_BUS_H_

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
#define W5300_BANK_ADDR ((uint32_t)0x60000000)
#define _W5300_DATA(p) *(volatile unsigned short *)(W5300_BANK_ADDR + (p << 1))

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
static inline void wizchip_select(void);
static inline void wizchip_deselect(void);
static inline uint16_t wizchip_read(uint32_t addr);
static inline void wizchip_write(uint32_t addr, uint16_t tx_data);
void wizchip_initialize(void);
void wizchip_reset(void);
void wizchip_check(void);

#ifdef __cplusplus
}
#endif

#endif /* _W5X00_BUS_H_ */
