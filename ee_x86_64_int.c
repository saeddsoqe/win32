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

#define OSEE_WIN32_INTERRUPTS_NO	32
/* interrupt inital flag */
typedef uint32_t OsEE_IntFlag_Type;
OsEE_IntFlag_Type OsEE_Win32_IntFlags;

/* interrupt interrupt flags buffer */
OsEE_IntFlag_Type OsEE_Win32_IntFlagsBuffer;

/* interrupt status */
typedef unsigned char OsEE_IntState_Type;
OsEE_IntState_Type OsEE_Win32_IntState;

/* interrupt mask type */
OsEE_IntFlag_Type OsEE_Win32_IntMask;

/* interrupt index type */
typedef unsigned char OsEE_Win32_IntIndex_Type;

typedef enum
{
	WIN_32_FLSE,
	WIN_32_TRUE
}OsEE_Win32_Bool;


typedef struct {
  uintptr_t isr_hnd;
  uint8_t   category;
} OsEE_x86_64_lookup_table;

static OsEE_x86_64_lookup_table osEE_isr_task_lookup_table[NUM_IDT_DESC];


void OsEE_Win32_InterruptHandler(int sig)
{
	OsEE_Win32_IntIndex_Type interrupt;
	/* check incomming signal to terminate */
   if (SIGTERM == sig)
   {
      /* Terminate Child process */
     
      /* wait for the second thread to finish */
      pthread_join(osEE_x86_64_system_timer_thread, NULL);
      /* kill Main process */
      
   }
	
	/* check if there is wainting interrupt flags */
	while( Win32_ISRIsWaiting() )
   	{
	  /* get first waiting flag */
      interrupt = Win32_GetFirstISR();

      /* only 0 .. 31 interrupts are allowed */
      if (OSEE_WIN32_INTERRUPTS_NO > interrupt)
      {
		  /* handle if not masked & interrupt enable */
         if ((OsEE_Win32_IntState) && ((OsEE_Win32_IntMask & (1 << interrupt ))  == 0 ))
         {
            //InterruptTable[interrupt]();
         }
         else /* buffer the flag otherwise */
         {
            OsEE_Win32_IntFlagsBuffer |= 1 << interrupt;
         }
      }
}

/* check for wainting nterrupts */
 static OsEE_Win32_Bool Win32_ISRIsWaiting(void)
 {
	 if(0 != OsEE_Win32_IntFlags)
	 {
		 return WIN_32_TRUE;
	 }
	 else
	 {
		 return WIN_32_FALSE;
	 }
 }

/* get the first waiting interrupt */
static OsEE_Win32_IntIndex_Type Win32_GetFirstISR(void)
{
   	OsEE_Win32_IntIndex_Type ret = 255;
   	OsEE_Win32_IntIndex_Type interrupt;
   	uint8_t found = 0;
	uint8_t mask = 0;

   	for(interrupt = 0; (0 == found) && (OSEE_WIN32_INTERRUPTS_NO > interrupt); interrupt++)
   	{
	   mask = 1 << interrupt;
      if (OsEE_Win32_IntFlags & mask)
      {
         found = 1;
         ret = interrupt;

         /* reset interrupt flag */
         OsEE_Win32_IntFlags &= ~mask;
      }
   }

   return ret;
}
	
/* schedule buffered interrupts */
extern void Win32_ScheduleBuffered_interrupt(void)
{
   int iterator = 0;
   uint32 ReadyInterrupt;

   if (OsEE_Win32_IntState) 
   {
      ReadyInterrupt = ( OsEE_Win32_IntFlagsBuffer & ( (OsEE_IntFlag_Type) ~OsEE_Win32_IntMask ) );
      while(ReadyInterrupt != 0)
      {
         if (ReadyInterrupt & 1)
         {
            OsEE_Win32_IntFlagsBuffer &= ~(1<<iterator);

            //InterruptTable[iterator](); /* to be renamed */
         }

         ReadyInterrupt >>= 1;
         iterator++;
      }
   }
}	
	
/* start OS arch component */
	FUNC(OsEE_bool, OS_CODE) osEE_cpu_startos(void)
{
  OsEE_bool const continue_startos = osEE_std_cpu_startos();

#if (!defined(OSEE_API_DYNAMIC))
  if (continue_startos == OSEE_TRUE) {
/* Initialize ISRs of this core */
	  signal(SIGALRM,OsEE_Win32_InterruptHandler);
	  signal(SIGTERM,OsEE_Win32_InterruptHandler);
	  signal(SIGUSR1,OsEE_Win32_InterruptHandler);
	  /* to be implemented agter mplementing the vector table */
      }
    }
#if (defined(OSEE_HAS_SYSTEM_TIMER))
    osEE_Win32_system_timer_init();
#endif /* OSEE_HAS_SYSTEM_TIMER */
  }
#endif /* !OSEE_API_DYNAMIC */
  return continue_startos;
}
