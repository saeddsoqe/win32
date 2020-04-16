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

/** \file   ee_platform_types.h
 *  \brief  Platform Types.
 *
 *  This files contains all types and symbols for a specific Architecture in
 *  Erika Enterprise.
 *
 *  \note COULD BE raplaced by AUTOSAR Type definition paradigm or being the
 *        implementation.
 *  \note TO BE DOCUMENTED!!!
 *
 *  \author Michele Pes
 *  \date   2017
 */

#if (!defined(OSEE_PLATFORM_TYPES_H))
#define OSEE_PLATFORM_TYPES_H

#include "ee_cfg.h"
#include "ee_arch_override.h"
#include "ee_utils.h"
#include "ee_compiler.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#if (defined(__cplusplus))
extern "C" {
#endif

#if (!defined(OSEE_BOOL_TYPE))
typedef enum {
  OSEE_FALSE = OSEE_M_FALSE,
  OSEE_TRUE  = OSEE_M_TRUE
} OsEE_bool;
#define OSEE_BOOL_TYPE OsEE_bool
#endif /* !OSEE_BOOL_TYPE */

/* Define HAL types */ // to be modified
typedef void *                OsEE_addr;
typedef int32_t               OsEE_sreg;
typedef uint32_t              OsEE_reg;
typedef uint32_t              OsEE_stack;

typedef uint8_t               OsEE_core_id;
#define OSEE_CORE_ID_TYPE     OsEE_core_id

typedef uint8_t               OsEE_isr_src_id;
#define OSEE_ISR_SOURCE_TYPE  OsEE_isr_src_id

typedef void (* OsEE_void_cb) ( void );

typedef unsigned long           OsEE_vaddr;
/************************ win32 added *************************/
/* pointer to void-void func */
typedef void (*Handler_Addr_type) (void);

/* interrupt flags type */
typedef uint32_t OsEE_Win32_InterruptFlags_type;

/* ISR indeces */ 
#define	ISR00		((uint8_t)0)
#define	ISR01		((uint8_t)1)
#define	ISR02		((uint8_t)2)
#define	ISR03		((uint8_t)3)
#define	ISR04		((uint8_t)4)
#define	ISR05		((uint8_t)5)
#define	ISR06		((uint8_t)6)
#define	ISR07		((uint8_t)7)
#define	ISR08		((uint8_t)8)
#define	ISR09		((uint8_t)9)
#define	ISR10		((uint8_t)10)
#define	ISR11		((uint8_t)11)
#define	ISR12		((uint8_t)12)
#define	ISR13		((uint8_t)13)
#define	ISR14		((uint8_t)14)
#define	ISR15		((uint8_t)15)
#define	ISR16		((uint8_t)16)
#define	ISR17		((uint8_t)17)
#define	ISR18		((uint8_t)18)
#define	ISR19		((uint8_t)19)
#define	ISR20		((uint8_t)20)
#define	ISR21		((uint8_t)21)
#define	ISR22		((uint8_t)22)
#define	ISR23		((uint8_t)23)
#define	ISR24		((uint8_t)24)
#define	ISR25		((uint8_t)25)
#define	ISR26		((uint8_t)26)
#define	ISR27		((uint8_t)27)
#define	ISR28		((uint8_t)28)
#define	ISR29		((uint8_t)29)
#define	ISR30		((uint8_t)30)
#define	ISR31		((uint8_t)31)


//typedef uint8_t               OsEE_isr_prio;
//#define OSEE_ISR_PRIO_TYPE    OsEE_isr_prio

/* Override default implementation for some Kernel Types */
//typedef size_t                OsEE_mem_size;
//#define OSEE_MEM_SIZE_TYPE    OsEE_mem_size

#if (defined(__cplusplus))
}
#endif

#endif /* !OSEE_PLATFORM_TYPES_H */
