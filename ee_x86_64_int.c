//we will handle our interrupt handling here

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

/** \file  ee_x86_64_int.c
 *  \brief  Interrupt configuration.
 *
 *  This files contains the interrupt configuration implementation for
 *  a specific Architecture in Erika Enterprise.
 *
 *  \author  Michele Pes
 *  \date    2017
 */

#include "ee_internal.h"
#include "ee_platform_config.h"
#include <stdio.h>

/* pointer to void-void func */
typedef void (*Handler_Addr_type) (void);

/* interrupt status */
typedef uint8_t OsEE_Win32_InterruptState_type;

OsEE_Win32_InterruptState_type OsEE_Win32_InterruptState = 0;
 
/* category identifier */

typedef enum {
	OSEE_ISR_CAT_1,
	OSEE_ISR_CAT_2
} OSEE_ISR_CAT_type;

/* vector structure */

typedef struct {
	Handler_Addr_type 	ISR_Addr;
	OSEE_ISR_CAT_type	ISR_CAT;
}OsEE_Vec_type;

/* Number of interrupts */
#define OSEE_WIN32_INTERRUPT_NUMBER 32

/* default handler */
void OsEE_Win32_DefaultHandler(void)
{
	/* to be replaced by an error code */
	printf("WRONG INTERRUPT IDX!\n");
	while(1);
}

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


/* vctor look up table */
OsEE_Vec_type OsEE_Win32_VecLookUpTable[OSEE_WIN32_INTERRUPT_NUMBER] = {
	{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	},
		{
		OsEE_Win32_DefaultHandler,
		OSEE_ISR_CAT_1
	}
}

/* interrupt flags typedef */

typedef uint32_t OsEE_Win32_InterruptFlags_type;

/* interrupt flags */
OsEE_Win32_InterruptFlags_type  OsEE_Win32_InterruptFlags = 0x00000000;


/* interrupt source signal is SIGALRM */

/* interrupt sensing */
static void OsEE_Win32_InterruptConttroller(int sig)
{
	uint8_t iterrupt;
	Handler_Addr_type interrupt_adr;
	OSEE_ISR_CAT_type interrupt_cat;
	
	/* chack termination signal */
	
	if (OsEE_Win32_InterruptState)
	{
	
		while (OsEE_Win32_InterruptFlags != 0)
		{
		/* identify */
		/* check fired interrupt flag */
			interrupt = OsEE_Win32_GetFiredInterrupt();
		}

		/* get interrupt handler */
		interrupt_adr = OsEE_Win32_GetISRAdr(interrupt);

		/* identify interrypt type */
		interrupt_cat = OsEE_Win32_GetISRCat(interrupt);
	
		/* service */
		if (OSEE_ISR_CAT_2 != interrupt_cat)
		{
			interrupt_adr();
		}
		else
		{
			osEE_activate_isr2(interrupt_adr);
		}
	}

}

static uint8_t OsEE_Win32_GetFiredInterrupt(void)
{
	uint8_t loopi;
	
	for(loopi = 0, loopi < OSEE_WIN32_INTERRUPT_NUMBER, loopi++)
	{
		if (1 == ((OsEE_Win32_InterruptFlags & (1 << loopi)) >> loopi))
		{
			/* reset interrupt flag */
			OsEE_Win32_InterruptFlags &= ~(1 << loopi);
			return loopi;
		}
		else
		{
			/* do nothing here */
		}
	}
	return OSEE_WIN32_INTERRUPT_NUMBER;
	
}
/* ISR address getter */
static Handler_Addr_type OsEE_Win32_GetISRAdr(uint8_t InterruptNo)
{
	return OsEE_Win32_VecLookUpTable[InterruptNo].ISR_Addr;
}

/* ISR category getter */
static OSEE_ISR_CAT_type OsEE_Win32_GetISRCat(uint8_t InterruptNo)
{
	return OsEE_Win32_VecLookUpTable[InterruptNo].ISR_CAT;
}

/* OS service for firing interrupts */
void OsEE_FireInterrupt(uint8_t InterruptNo)
{
	OsEE_Win32_InterruptFlags |= 1 << InterruptNo;
	kill(getpid(),SIGALRM);
}

/* ISR table setter */
static void OsEE_Win32_SetISR(uint8_t InterruptNo,OSEE_ISR_CAT_type ISR_cat,Handler_Addr_type InterruptAdr )
{
	/* Assign handler address */
	OsEE_Win32_VecLookUpTable[InterruptNo].ISR_Addr = InterruptAdr;
	
	/* assighn ISR category */
	OsEE_Win32_VecLookUpTable[InterruptNo].ISR_CAT  = ISR_cat;
}

/* To be used by user */
void OsEE_SetInterruptHandler(uint8_t InterruptNo, Handler_Addr_type InterruptAdr)
{
	/* assign ISR category 1 */
	OsEE_Win32_SetISR(InterruptNo, OSEE_ISR_CAT_1,InterruptAdr);
}


FUNC(OsEE_bool, OS_CODE) osEE_cpu_startos(void)
{
	OsEE_bool const continue_startos = osEE_std_cpu_startos();
	OsEE_KDB * const ptr_to_KDB      = osEE_get_kernel();
	OsEE_TDB * ptr_to_TDB;		 

	/* Initialize ISRs of the kernel  */

	for (i = 0U; i < (ptr_to_KDB->tdb_array_size - 1U); ++i) 
	{
	  /* ISR2 initialization */
	  ptr_to_TDB = (*ptr_to_KDB->p_tdb_ptr_array)[i];

	  if (ptr_to_TDB->task_type == OSEE_TASK_TYPE_ISR2) 
	  {
		OsEE_Win32_SetISR(ptr_to_TDB->hdb.isr2_src, INT_CAT_ISR2, ptr_to_TDB->task_func);
	  }
	}

	osEE_Win32_system_timer_init();
  
  return continue_startos;
}
