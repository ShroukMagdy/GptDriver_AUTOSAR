/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file  		EcuM_Cbk.h
 *      \brief  	Gpt driver
 *      \details  	Implementation of the Gpt driver
 *
 *********************************************************************************************************************/
#ifndef ECUM_CBK_H
#define ECUM_CBK_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_CHANNEL0				0x20

/*
 EcuM_WakeupSourceType defines a bitfield with 5 pre-defined positions (see 
Range). The bitfield provides one bit for each wakeup source.
In WAKEUP, all bits cleared indicates that no wakeup source is known.
In STARTUP, all bits cleared indicates that no reason for restart or reset is known. 
In this case, ECUM_WKSOURCE_RESET shall be assumed.
*/
/*****************1st implemenetaion************/
typedef enum{
// ECUM_WKSOURCE_POWER --Power cycle (bit 0)
ECUM_WKSOURCE_POWER=0x01,
//ECUM_WKSOURCE_RESET -- Hardware reset (bit 1).
/*
If the Mcu driver cannot distinguish 
between a power cycle and a reset 
reason, then this shall be the default 
wakeup source.
*/
ECUM_WKSOURCE_RESET=0x02,
//ECUM_WKSOURCE_INTERNAL_RESET -- Internal reset of µC (bit 2)
/*
The internal reset typically only resets the 
µC core but not peripherals or memory 
controllers. The exact behavior is 
hardware specific.
This source may also indicate an 
unhandled exception.
*/
ECUM_WKSOURCE_INTERNAL_RESET=0x04,
//ECUM_WKSOURCE_INTERNAL_WDG -- Reset by internal watchdog (bit 3)
ECUM_WKSOURCE_INTERNAL_WDG=0x08,
//ECUM_WKSOURCE_EXTERNAL_WDG -- Reset by external watchdog (bit 4), if detection supported by hardware
ECUM_WKSOURCE_EXTERNAL_WDG=0x10,

//added for GPT
ECUM_WKSOURCE_GPT_CHANNEL0=GPT_CHANNEL0

}EcuM_WakeupSourceType;
/***********************************************/
/*****************2nd implemenetaion************/
/*
typedef uint32 EcuM_WakeupSourceType;
EcuM_WakeupSourceType ECUM_WKSOURCE_POWER=0x01;
EcuM_WakeupSourceType ECUM_WKSOURCE_RESET=0x02;
EcuM_WakeupSourceType ECUM_WKSOURCE_INTERNAL_RESET=0x04;
EcuM_WakeupSourceType ECUM_WKSOURCE_INTERNAL_WDG=0x08;
EcuM_WakeupSourceType ECUM_WKSOURCE_EXTERNAL_WDG=0x10;
*/
/***********************************************/
 
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);






#endif  /* ECUM_CBK_H */
