/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file  		Gpt.h
 *      \brief  	Gpt driver
 *      \details  	Implementation of the Gpt driver
 *
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "EcuM_Cbk.h"
#include "Gpt_Cfg.h"

typedef enum {

}Gpt_ChannelType;


// Enum for Modes of the GPT driver
typedef enum {
	GPT_MODE_NORMAL =	0x00 ,	 // Normal operation mode of the GPT driver.
	GPT_MODE_SLEEP  =	0x01	 // Sleep mode of the GPT driver (wakeup capable)
}Gpt_ModeType;

// Enum for Type for GPT Predef Timers
typedef enum {
	GPT_PREDEF_TIMER_1US_16BIT 	 =	0x00 ,	// GPT Predef Timer with tick duration 1탎   and range 16bit
	GPT_PREDEF_TIMER_1US_24BIT 	 =	0x01 ,	// GPT Predef Timer with tick duration 1탎   and range 24bit
	GPT_PREDEF_TIMER_1US_32BIT 	 =	0x02 ,  // GPT Predef Timer with tick duration 1탎   and range 32bit
	GPT_PREDEF_TIMER_100US_32BIT  =	0x03	// GPT Predef Timer with tick duration 100탎 and range 32bit
}Gpt_PredefTimerType;

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void Gpt_SetMode(Gpt_ModeType Mode)
 *********************************************************************************************************************/
/*! \brief						Sets the operation mode of the GPT
 *  \details       				set the operation mode of the GPT driver to the given mode parameter.
 *  \Service ID[hex]           	0x09
 *  \param[in]                  Mode : mode of operation (GPT_MODE_NORMAL / GPT_MODE_SLEEP )
 *  \param[in,out]              None
 *  \param[out]                 None
 *  \return                     None
 *  \pre                        GptWakeupFunctionalityApi should be configured to be ON
 *  \context                    Task
 *  \reentrant                  Non Reentrant
 *  \synchronous                Synchronous
 *  \satisfied by               ------
 *********************************************************************************************************************/
void Gpt_SetMode(Gpt_ModeType Mode);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void Gpt_DisableWakeup(Gpt_ChannelType Channel)
 *********************************************************************************************************************/
/*! \brief						Disables the wakeup interrupt of a channel (relevant in sleep mode)
 *  \details       				disable the wakeup interrupt of the referenced channel configured for wakeup.
 *  							The function shall save an attribute like "wakeup disabled" of the channel.
 *  \Service ID[hex]           	0x0a
 *  \param[in]                  Channel : Numeric identifier of the GPT channel
 *  \param[in,out]              None
 *  \param[out]                 None
 *  \return                     None
 *  \pre                        GptWakeupFunctionalityApi should be configured to be ON
 *  \context                    Task
 *  \reentrant                  Reentrant (but not for the same timer channel)
 *  \synchronous                Synchronous
 *  \satisfied by               ------
 *********************************************************************************************************************/
void Gpt_DisableWakeup(Gpt_ChannelType Channel);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void Gpt_EnableWakeup(Gpt_ChannelType Channel)
 *********************************************************************************************************************/
/*! \brief						Enables the wakeup interrupt of a channel (relevant in sleep mode)
 *  \details       				enable the wakeup interrupt of the referenced channel configured for wakeup.
 *  							The function shall save an attribute like "wakeup enabled" of the channel.
 *  \Service ID[hex]           	0x0b
 *  \param[in]                  Channel : Numeric identifier of the GPT channel
 *  \param[in,out]              None
 *  \param[out]                 None
 *  \return                     None
 *  \pre                        GptWakeupFunctionalityApi should be configured to be ON
 *  \context                    Task
 *  \reentrant                  Reentrant (but not for the same timer channel)
 *  \synchronous                Synchronous
 *  \satisfied by               ------
 *********************************************************************************************************************/
void Gpt_EnableWakeup(Gpt_ChannelType Channel);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
 *********************************************************************************************************************/
/*! \brief						Checks if a wakeup capable GPT channel is the source for a wakeup event
 *  \details       				Checks if a wakeup capable GPT channel is the source for a wakeup event
 * 								and calls the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
 *  \Service ID[hex]           	0x0c
 *  \param[in]                  WakeupSource : Information on wakeup source to be checked. The associated GPT channel can be determined from configuration data.
 *  \param[in,out]              None
 *  \param[out]                 None
 *  \return                     None
 *  \pre                        GptWakeupFunctionalityApi should be configured to be ON
 *  \context                    Task
 *  \reentrant                  Reentrant
 *  \synchronous                Synchronous
 *  \satisfied by               ------
 *********************************************************************************************************************/
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Std_ReturnType Gpt_GetPredefTimerValue(EcuM_WakeupSourceType WakeupSource)
 *********************************************************************************************************************/
/*! \brief						Delivers the current value of the desired GPT Predef Timer.
 *  \details       				return the current value of the GPT Predef Timer passed by PredefTimer.
 *  \Service ID[hex]           	0x0d
 *  \param[in]                  PredefTimer  : GPT Predef Timer
 *  \param[in,out]              None
 *  \param[out]                 TimeValuePtr : Pointer to time value destination data in RAM
 *  \return       				E_OK         : request successful
 *  \return        				E_NOT_OK     : request failed
 *  \pre                        GptWakeupFunctionalityApi should be configured to be ON
 *  \context                    Task
 *  \reentrant                  Reentrant
 *  \synchronous                Synchronous
 *  \satisfied by               ------
 *********************************************************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);

#endif  /* GPT_H */
