



/* pointer to void-void func  //to be moved to platform types
typedef void (*Handler_Addr_type) (void); */

/* interrupt status //replaced by bool
typedef uint8_t OsEE_Win32_InterruptState_type; */

/* interrupt flags typedef  //to be moved to platform types

typedef uint32_t OsEE_Win32_InterruptFlags_type;*/

/*
typedef enum {
  OSEE_FALSE = OSEE_M_FALSE,
  OSEE_TRUE  = OSEE_M_TRUE
} OsEE_bool;
*/

/*==============================================================================
                            Defines
 =============================================================================*/

/* Number of interrupts */ //static
#define OSEE_WIN32_INTERRUPT_NUMBER 32


/*==============================================================================
                           Typedefs
 =============================================================================*/
/* category identifier */ //static 
typedef enum {
	OSEE_ISR_CAT_1,
	OSEE_ISR_CAT_2
} OSEE_ISR_CAT_type;

/* vector structure */ //static
typedef struct {
	Handler_Addr_type 	ISR_Addr;
	OSEE_ISR_CAT_type	ISR_CAT;
}OsEE_Vec_type;

/*==============================================================================
                           external interfaces
 =============================================================================*/
/* interrupt flags */ // to be externed in hal internal
OsEE_Win32_InterruptFlags_type  OsEE_Win32_InterruptFlags = 0x00000000;

/* interrupt state */ // to be externed in hal internal
OsEE_bool OsEE_Win32_InterruptState = OSEE_M_FALSE;

/* ISR indeces   //to be moved to platform types
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
#define	ISR31		((uint8_t)31)*/
 
 
/*==============================================================================
                            internal objects
 =============================================================================*/
/* default handler */ //static
static void OsEE_Win32_DefaultHandler(void)
{
	/* to be replaced by an error code */
	printf("WRONG INTERRUPT IDX!\n");
	while(1);
}

/* vctor look up table */
static OsEE_Vec_type OsEE_Win32_VecLookUpTable[OSEE_WIN32_INTERRUPT_NUMBER] = {
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

/* interrupt source signal is SIGALRM */
/* interrupt sensing */
static void OsEE_Win32_InterruptConttroller(int sig)
{
	uint8_t iterrupt;
	Handler_Addr_type interrupt_adr;
	OSEE_ISR_CAT_type interrupt_cat;
	
	/* chack termination signal */
	
	if (OSEE_M_TRUE == OsEE_Win32_InterruptState)
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
			//osEE_activate_isr2(interrupt_adr);
			kill(gitpid(),SIGUSR1);
		}
	}
}

static void ISR2_SigHandler(int sig)
{
	if(SIGUSR1 == sig)
	{
		printf("ISR cat 2\n");
		osEE_activate_isr2(interrupt_adr);
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
static Handler_Addr_type OsEE_Win32_GetISRAdr(uint8_t source_id)
{
	return OsEE_Win32_VecLookUpTable[source_id].ISR_Addr;
}

/* ISR category getter */
static OSEE_ISR_CAT_type OsEE_Win32_GetISRCat(uint8_t source_id)
{
	return OsEE_Win32_VecLookUpTable[source_id].ISR_CAT;
}


/* ISR table setter */
static void OsEE_Win32_SetISR(uint8_t source_id,OSEE_ISR_CAT_type ISR_cat,Handler_Addr_type InterruptAdr )
{
	/* Assign handler address */
	OsEE_Win32_VecLookUpTable[source_id].ISR_Addr = InterruptAdr;
	
	/* assighn ISR category */
	OsEE_Win32_VecLookUpTable[source_id].ISR_CAT  = ISR_cat;
}

/*==============================================================================
                            APIs
 =============================================================================*/

/* To be used by user */
extern void OsEE_SetInterruptHandler(uint8_t source_id, Handler_Addr_type InterruptAdr)
{
	/* assign ISR category 1 */
	OsEE_Win32_SetISR(source_id, OSEE_ISR_CAT_1,InterruptAdr);
}


FUNC(OsEE_bool, OS_CODE) osEE_cpu_startos(void)
{
	OsEE_bool const continue_startos = osEE_std_cpu_startos();
	/* OSEE_API_DYNAMIC the user initializes the OS pararmeters in run time 
	 * no need for looking for ISR Cat 2 as it will be created by user as well
	 * as the system timer*/ 
	 
	/* create signal */
	signal(SIGALRM, &OsEE_Win32_InterruptConttroller);
	signal(SIGUSR1, &ISR2_SigHandler);
	
#if (!defined(OSEE_API_DYNAMIC))
	/* pointer to kernel descriptor block */
	OsEE_KDB * const ptr_to_KDB      = osEE_get_kernel();
	/* pointer to task disciptor block used inside the KDB */
	OsEE_TDB * ptr_to_TDB;		 
	/* loop iterator */
	uint8_t i;
	
	if (continue_startos == OSEE_TRUE) 
	{	
		/* Initialize ISRs of the kernel  */
		
		/* checking each task in the TDB array execloding the last element "idle task" */
		for (i = 0U; i < (ptr_to_KDB->tdb_array_size - 1U); ++i) 
		{
			/* pointing to the TDB inside the TDB_array */
			ptr_to_TDB = (*ptr_to_KDB->p_tdb_ptr_array)[i];

			/* ISR2 initialization */
			if (ptr_to_TDB->task_type == OSEE_TASK_TYPE_ISR2) 
			{
			OsEE_Win32_SetISR(ptr_to_TDB->hdb.isr2_src, OSEE_ISR_CAT_2, i);
			}
		}
	}
	osEE_Win32_system_timer_init();
 #endif /* !OSEE_API_DYNAMIC */
  return continue_startos;
}

/* OS service for firing interrupts */
extern void OsEE_FireInterrupt(uint8_t source_id)
{
	OsEE_Win32_InterruptFlags |= 1 << source_id;
	kill(getpid(),SIGALRM);
}

#if (defined(OSEE_API_DYNAMIC))
StatusType osEE_hal_set_isr2_source
(
  OsEE_TDB * ptr_to_TDB,
  ISRSource  source_id
)
{
  OsEE_Win32_SetISR((uint8_t)source_id, OSEE_ISR_CAT_2, ptr_to_TDB->tid);
  return E_OK;
}
#endif /* OSEE_API_DYNAMIC */

extern void OsEE_Win32_HandleSuspendedInterrupts(void);
{
	kill(getpid(),SIGALRM);
}
