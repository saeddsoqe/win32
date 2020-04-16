/* ###*B*###
 * Erika Enterprise, version 3
 * 
 * Copyright (C) 2017 - 2018 Evidence s.r.l.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License, version 2, for more details.
 * 
 * You should have received a copy of the GNU General Public License,
 * version 2, along with this program; if not, see
 * < www.gnu.org/licenses/old-licenses/gpl-2.0.html >.
 * 
 * This program is distributed to you subject to the following
 * clarifications and special exceptions to the GNU General Public
 * License, version 2.
 * 
 * THIRD PARTIES' MATERIALS
 * 
 * Certain materials included in this library are provided by third
 * parties under licenses other than the GNU General Public License. You
 * may only use, copy, link to, modify and redistribute this library
 * following the terms of license indicated below for third parties'
 * materials.
 * 
 * In case you make modified versions of this library which still include
 * said third parties' materials, you are obligated to grant this special
 * exception.
 * 
 * The complete list of Third party materials allowed with ERIKA
 * Enterprise version 3, together with the terms and conditions of each
 * license, is present in the file THIRDPARTY.TXT in the root of the
 * project.
 * ###*E*### */

/** \file   ee_hal.h
 *  \brief  HAL support visible to the application.
 *
 *  This files contains all HAL for a specific Architecture in
 *  Erika Enterprise.
 *
 *  \author Michele Pes
 *  \date   2017
 */

#ifndef OSEE_HAL_H
#define OSEE_HAL_H

/*==============================================================================
                          HAL Types and structures
 =============================================================================*/
#include "ee_cfg.h"
#include "ee_platform_types.h"
#include "ee_utils.h"
#include "ee_compiler.h"

#if (!defined(__GNUC__))
#error Unsupported compiler!
#endif /* !__GNUC__ */

#if (defined(__cplusplus))
extern "C" {
#endif

/*==============================================================================
                            Array Utilities
 =============================================================================*/

/* Fill Pattern Used for Array Monitoring */
#if (!defined(OSEE_FILL_PATTERN))
#define OSEE_FILL_PATTERN 0xA5A5A5A5U
#endif /* !OSEE_FILL_PATTERN */

/* Use Range Designated Initializers */
#define OSEE_FILL_ARRAY(array) \
  = {[0 ... (sizeof(array)/sizeof((array)[0U]) - 1U)] = OSEE_FILL_PATTERN}

/*==============================================================================
                 Utility Macros for debugging and tracing purposes
 =============================================================================*/
#if 0 /* Software Breakpoint support: temporary disabled */
#define OSEE_BREAK_POINT()        __asm__ volatile ("int 3\n")
#define OSEE_GLOBAL_LABEL(label)  __asm__(".globl " #label "\n" #label ":")
#endif /* 0 */

/* Context handling functions for Tasking */
OSEE_STATIC_INLINE OsEE_addr osEE_get_SP(void)
{
  OsEE_addr sp;
  __asm__ volatile("mov %%rsp, %0\n" : "=g"(sp));
  return sp;
}


/*==============================================================================
                            Core IDs Utilities
 =============================================================================*/
/* XXX: Maybe I need a global data structures like {KDB,KCB} for the HAL
        architecture dependent? */

OSEE_STATIC_INLINE OsEE_core_id osEE_get_curr_core_id(void) {
  return 0U;
}

/*==============================================================================
                            Platform setup
 =============================================================================*/
void osEE_x86_64_calibrate_platform_tick_freq(void);

/*==============================================================================
                            Interrupt management
 =============================================================================*/
void OsEE_SetInterruptHandler(uint8_t source_id, Handler_Addr_type InterruptAdr);


/*==============================================================================
                            I/O management
 =============================================================================*/


/*==============================================================================
                                 Timer Support
 =============================================================================*/
#if (defined(OSEE_HAS_SYSTEM_TIMER))
extern void osEE_Win32_system_timer_handler(void);
#endif /* OSEE_HAS_SYSTEM_TIMER */

/*=============================================================================
                                    ISR macros
 ============================================================================*/

/* Macro to declare ISR: always valid */
#define DeclareIsr(f) void f (void)

/* Declare an ISR (category 1) */
#define ISR1(f) void f (void)

/* Define an ISR (category 2). Used only for client code. */
#define ISR2(f) ISR1(f)

/*==============================================================================
 *                               MMIO R/W functions
 =============================================================================*/

OSEE_STATIC_INLINE void OSEE_ALWAYS_INLINE
  osEE_mmio_write8(OsEE_reg addr, uint8_t value)
{
  (*(uint8_t volatile *)addr) = value;
}

OSEE_STATIC_INLINE void OSEE_ALWAYS_INLINE
  osEE_mmio_write16(OsEE_reg addr, uint16_t value)
{
  (*(uint16_t volatile *)addr) = value;
}

OSEE_STATIC_INLINE void OSEE_ALWAYS_INLINE
  osEE_mmio_write32(OsEE_reg addr, uint32_t value)
{
  (*(uint32_t volatile *)addr) = value;
}

OSEE_STATIC_INLINE uint8_t OSEE_ALWAYS_INLINE
  osEE_mmio_read8(OsEE_reg addr)
{
  return (*(uint8_t volatile *)addr);
}

OSEE_STATIC_INLINE uint16_t OSEE_ALWAYS_INLINE
  osEE_mmio_read16(OsEE_reg addr)
{
  return (*(uint16_t volatile *)addr);
}

OSEE_STATIC_INLINE uint32_t OSEE_ALWAYS_INLINE
  osEE_mmio_read32(OsEE_reg addr)
{
  return (*(uint32_t volatile *)addr);
}

#if (defined(__cplusplus))
}
#endif

#endif /* !OSEE_HAL_H */
