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


/*! GPT Module Id */
#define GPT_MODULE_ID (100U)
/*! GPT Instance Id */
#define GPT_INSTANCE_ID (0U)

typedef enum{
	API_ID_Gpt_SetMode					=	0x09,
	API_ID_Gpt_DisableWakeup			=	0x0a,
	API_ID_Gpt_EnableWakeup				=	0x0b,
	API_ID_Gpt_CheckWakeup				=	0x0c,
	API_ID_Gpt_GetPredefTimerValue		=	0x0d,


}API_ID;
typedef enum
{
	channel_0,
	channel_1

}Gpt_ChannelType;

// Enum for Modes of the GPT driver
typedef enum {
	GPT_MODE_NORMAL =	0x00 ,	 // Normal operation mode of the GPT driver.
	GPT_MODE_SLEEP  =	0x01	 // Sleep mode of the GPT driver (wakeup capable)
}Gpt_ModeType;


// Enum for Type for GPT Predef Timers
typedef enum {
	GPT_PREDEF_TIMER_1US_16BIT 	 =	0x00 ,	// GPT Predef Timer with tick duration 1µs   and range 16bit
	GPT_PREDEF_TIMER_1US_24BIT 	 =	0x01 ,	// GPT Predef Timer with tick duration 1µs   and range 24bit
	GPT_PREDEF_TIMER_1US_32BIT 	 =	0x02 ,  // GPT Predef Timer with tick duration 1µs   and range 32bit
	GPT_PREDEF_TIMER_100US_32BIT  =	0x03	// GPT Predef Timer with tick duration 100µs and range 32bit
}Gpt_PredefTimerType;
/*
typedef enum{
	GptPredefTimer100us32bitEnable_OFF,
	GptPredefTimer100us32bitEnable_ON
}GptPredefTimer100us32bitEnable_e;
GptPredefTimer100us32bitEnable_e GptPredefTimer100us32bitEnable;
*/

/****************************************ROANNE********************************************/
/*
 * notes:
 * add channel id
 * array of struct of channels
 * remove type from elements in struct
 * remove predef
 */
typedef struct
{
	uint8 ChannelType;                      //u8 is defined as uint8 in Platform_Types.h
	Gpt_ModeType ModeType ;              /*GPT_MODE_NORMAL-GPT_MODE_SLEEP*/
	uint8 ValueType ;                      //??ValueTypeThe range of this type is µC dependent (width of the timerregister) and has to be described by the supplier.
	Gpt_PredefTimerType PredefTimerType;/*GPT_PREDEF_TIMER_1US_16BIT
                                          GPT_PREDEF_TIMER_1US_24BIT
                                          GPT_PREDEF_TIMER_1US_32BIT
                                          GPT_PREDEF_TIMER_100US_32BIT */
}Gpt_ConfigType;

typedef struct
{
		//Questions??
}Std_VersionInfoType;
/******************************************************************************************/

/****************************************BANNA********************************************/
/**********************************Channels Range************************/

/***********************************Return Type**************************/
typedef uint32 Gpt_ValueType;


/************************************Errors flag**************************/
typedef enum
{
	GPT_E_UNINIT = 0x0A ,
	GPT_E_PARAM_CHANNEL = 0x14,
	GPT_E_INIT_FAILED=0x0E,
	GPT_E_ALREADY_INITIALIZED=0x0D,
	GPT_E_PARAM_VALUE=0x15,
	GPT_E_PARAM_POINTER=0x16,
	GPT_E_PARAM_PREDEF_TIMER=0x17,
	GPT_E_PARAM_MODE=0x1F
}Gpt_ReturnError_t;
typedef enum
{

/*API service called when timer
channel is still busy (running) Development
*/
	GPT_E_BUSY = 0x0B,
/*
API service called when driver
is in wrong mode Development
*/
	GPT_E_MODE = 0x0C
}Gpt_RuntimeReturnError_t;


/******************************************************************************************/

/****************************************YOUSSEF*******************************************/
typedef enum{
	Stopped,
	Intialized,
	Expired,
	UnIntialized,
	Running
}tenuTimerState;
/******************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Function Name: Gpt_GetVersionInfo
 * Description: DeInitializes the GPT drive
 * Parameters
 *	Inputs       :VersionInfoPtr Pointer to a selected version
 *	Input/Outputs:N/A
 *	Outputs      :N/A
 * Return value: :N/A
 * */
void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);
/*
 * Function Name: Gpt_Init
 * Description: Initializes the GPT drive
 * Parameters
 *	Inputs       : ConfigPtr Pointer to a selected configuration structure
 *	Input/Outputs:N/A
 *	Outputs      :N/A
 * Return value: :N/A
 * */
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
/*
 * Function Name: Gpt_DeInit
 * Description: DeInitializes the GPT drive
 * Parameters
 *	Inputs       :N/A
 *	Input/Outputs:N/A
 *	Outputs      :N/A
 * Return value: :N/A
 * */
void Gpt_DeInit(void);


/*[SWS_00010] ==> Approved*/
/*if the mode is one shoot we should return the value in ticks */

/*[SWS_00361] ==> ???????*/
/*if the mode is continuous mode we should return the time in ticks from last recurrence*/

/*[SWS_00296] ==> Approved (Not sure to implement due to HW constrains )*/
/*if the function is called before the initialization function so  the function should return '0'*/

 /* [SWS_00297] ==> Approved (Not sure to implement due to HW constrains )
 *if the function is called when the timer is stopped , this function will return the stopped value*/

/*[SWS_00299] == > Approved
 *In One shot mode if the timer reached the target time the function should return the target time*/

/*[SWS_00113] == > Approved (under discussion)
 * the function should be fully re-enrant */

/*[SWS_00195] == > Approved
 * the function is a pre-compilation configuration
 */
/*[SWS_00222] == > Approved
 *if the driver not inialized , this function should raise a flag (development error detection)
 */

/*[SWS_00210] == > Approved
 *if the channel is invalid , a GPT_E_PARAMETER flag should be raised
 */

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);




/*[SWS_00083] == > Approved
 *the function retunr the time remaining untill the target time
 */

/*[SWS_00301] ==> Approved (Not sure to implement due to HW constrains )*/
/*if the function is called before the initialization function so  the function should return '0'*/

 /* [SWS_00303] ==> Approved (Not sure to implement due to HW constrains )
 *if the function is called when the timer is stopped , this function will return the stopped value*/

/*[SWS_00305] == > Approved
*In One shot mode if the timer reached the target time the function should return the target time*/

/*[SWS_00114] == > Approved (under discussion)
* the function should be fully re-enrant */

/*[SWS_00196] == > Approved ????????
* the function is a pre-compilation configuration
*/
/*[SWS_00223] == > Approved
*if the driver not inialized , this function should raise a flag (development error detection)
*/

/*[SWS_00211] == > Approved
*if the channel is invalid , a GPT_E_PARAMETER flag should be raised
*/

Gpt_ValueType Gpt_GetTimeReamaining(Gpt_ChannelType Channel);


/*[SWS_00274] == > Approved
*The function shall start the timer of the required channel with the required time ticks
*/

/*[SWS_00275] == > Approved (under discussion) ??????
*When reach the required target an interrupt should be triggered so we have to enable the interrupt here
*/

/*[SWS_00115] == > Approved (under discussion) ??????
*the function shall be re-entrant
*/

/*[SWS_00364] == > Approved
*the state of the channel should be "running" if the fucntion is called for specific channel
*/

/*[SWS_00212] == > Approved
*if the channel is invalid , a GPT_E_PARAMETER flag should be raised
*/

/*[SWS_00218] == > Approved
*if the channel is invalid , a GPT_E_PARAM_VALUE flag should be raised
*/

/*[SWS_00224] == > Approved
*if the channel is invalid , a GPT_E_PARAM_VALUE flag should be raised
*/

/*[SWS_00084] == > Approved
*if this func is called specific channel which in running state, a GPT_E_BUSY flag should be raised
*/

void Gpt_StartTimer(Gpt_ChannelType channel , Gpt_ValueType Value);




/****************************************************************************************
[SWS_Gpt_00285]
----------------------------------------------------------------------------------------
* 		Service Name    	|Gpt_StopTimer                                             |
* ==========================|==========================================================|
*          Syntax           |  void Gpt_StopTimer(                                     |
*                           |      Gpt_ChannelType Channel                             |
*                           |  )                                                       |
* --------------------------|----------------------------------------------------------|
* 	    Service ID[hex]     |0x06                                                      |
* --------------------------|----------------------------------------------------------|
* 		  Sync/Async		|Synchronous                                               |
* --------------------------|----------------------------------------------------------|
*         Reentrancy        |Reentrant (but not for the same timer channel)            |
* --------------------------|----------------------------------------------------------|
* 	    Parameters (in)     |Channel     | Numeric identifier of the GPT channel.      |
* --------------------------|----------------------------------------------------------|
* 	   Parameters (inout)	|None                                                      |
* --------------------------|----------------------------------------------------------|
*        Return value       |None                                                      |
* --------------------------|----------------------------------------------------------|
*        Description        |Stops a timer channel                                     |
* -------------------------------------------------------------------------------------|

[SWS_Gpt_00013]==> Approved
  The function Gpt_StopTimer shall stop the selected timer channel.

[SWS_Gpt_00343] ==> Approved
 The state of the selected timer channel shall be changed to "stopped" if Gpt_StopTimer is called.

[SWS_Gpt_00099] ==> Approved
 If development error detection is enabled for GPT module:
If the function Gpt_StopTimer is called on a channel in state "initialized", "stopped"
or "expired", the function shall not raise a development error.

[SWS_Gpt_00344] ==> Approved
 If the function Gpt_StopTimer is called on a channel in state
"initialized", "stopped" or "expired", the function shall leave without any action (no
change of the channel state).

[SWS_Gpt_00116] ==> Approved ??
 The function Gpt_StopTimer shall be reentrant, if the timer
channels used in concurrent calls are different.

[SWS_Gpt_00213] ==> Approved
 If development error detection is enabled for GPT module:
If the parameter Channel is invalid (not within the range specified by configuration),
the function Gpt_StopTimer shall raise the error GPT_E_PARAM_CHANNEL.

[SWS_Gpt_00225] ==> Approved
 If development error detection is enabled for GPT module:
If the driver is not initialized, the function Gpt_StopTimer shall raise the error
GPT_E_UNINIT.

****************************************************************************************/
//tenuGPT_err Gpt_StopTimer(Gpt_ChannelType Channel);

/****************************************************************************************
[SWS_Gpt_00286]
----------------------------------------------------------------------------------------
* 		Service Name    	| Gpt_EnableNotification                                   |
* ==========================|==========================================================|
*          Syntax           |  void Gpt_EnableNotification(                            |
*                           |      Gpt_ChannelType Channel                             |
*                           |  )                                                       |
* --------------------------|----------------------------------------------------------|
* 	    Service ID[hex]     |0x07                                                      |
* --------------------------|----------------------------------------------------------|
* 		  Sync/Async		|Synchronous                                               |
* --------------------------|----------------------------------------------------------|
*         Reentrancy        |Reentrant (but not for the same timer channel)            |
* --------------------------|----------------------------------------------------------|
* 	    Parameters (in)     |Channel     | Numeric identifier of the GPT channel.      |
* --------------------------|----------------------------------------------------------|
* 	   Parameters (inout)	|None                                                      |
* --------------------------|----------------------------------------------------------|
*        Return value       |None                                                      |
* --------------------------|----------------------------------------------------------|
*        Description        |Enables the interrupt notification for a channel          |
*                           |(relevant in normal mode).                                |
* -------------------------------------------------------------------------------------|

[SWS_Gpt_00014] ==> Approved
 The function Gpt_EnableNotification shall enable the
interrupt notification of the referenced channel configured for notification.
 The function shall save an attribute like "notification enabled" of
the channel.

Comment: This attribute affects the interrupt notification always when the driver is in
"normal mode". In "sleep mode" the attribute has no influence.

[SWS_Gpt_00117] ==> Approved ??
 The function Gpt_EnableNotification shall be reentrant, if
the timer channels used in concurrent calls are different.

[SWS_Gpt_00199] ==> Approved
 The function Gpt_EnableNotification shall be pre-compile
time configurable On/Off by the configuration parameter: GptEnableDisableNotificationApi.

[SWS_Gpt_00226] ==> Approved
 If development error detection is enabled for GPT module:
If the driver is not initialized, the function Gpt_EnableNotification shall raise the
error GPT_E_UNINIT.

[SWS_Gpt_00214] ==> Approved
 If development error detection is enabled for GPT module:
If the parameter Channel is invalid (not within the range specified by
configuration), the function Gpt_EnableNotification shall raise the error
GPT_E_PARAM_CHANNEL.

[SWS_Gpt_00377] ==> Approved
 If development error detection is enabled for GPT module:
If no valid notification function is configured (GptNotification), the function
Gpt_EnableNotification shall raise the error GPT_E_PARAM_CHANNEL.

****************************************************************************************/

//tenuGPT_err Gpt_EnableNotification(Gpt_ChannelType Channel);


/****************************************************************************************
[SWS_Gpt_00286]
----------------------------------------------------------------------------------------
* 		Service Name    	| Gpt_DisableNotification                                  |
* ==========================|==========================================================|
*          Syntax           |  void Gpt_DisableNotification(                           |
*                           |      Gpt_ChannelType Channel                             |
*                           |  )                                                       |
* --------------------------|----------------------------------------------------------|
* 	    Service ID[hex]     |0x08                                                      |
* --------------------------|----------------------------------------------------------|
* 		  Sync/Async		|Synchronous                                               |
* --------------------------|----------------------------------------------------------|
*         Reentrancy        |Reentrant (but not for the same timer channel)            |
* --------------------------|----------------------------------------------------------|
* 	    Parameters (in)     |Channel     | Numeric identifier of the GPT channel.      |
* --------------------------|----------------------------------------------------------|
* 	   Parameters (inout)	|None                                                      |
* --------------------------|----------------------------------------------------------|
*        Return value       |None                                                      |
* --------------------------|----------------------------------------------------------|
*        Description        |Disables the interrupt notification for a channel         |
*                           |(relevant in normal mode).                                |
* -------------------------------------------------------------------------------------|

[SWS_Gpt_00015] ==> Approved
 The function Gpt_EnableNotification shall enable the
interrupt notification of the referenced channel configured for notification.
 The function shall save an attribute like "notification enabled" of
the channel.

Comment: This attribute affects the interrupt notification always when the driver is in
"normal mode". In "sleep mode" the attribute has no influence.

[SWS_Gpt_00118] ==> Approved ??
 The function Gpt_EnableNotification shall be reentrant, if
the timer channels used in concurrent calls are different.

[SWS_Gpt_00200] ==> Approved
 The function Gpt_EnableNotification shall be pre-compile
time configurable On/Off by the configuration parameter: GptEnableDisableNotificationApi.

[SWS_Gpt_00227] ==> Approved
 If development error detection is enabled for GPT module:
If the driver is not initialized, the function Gpt_EnableNotification shall raise the
error GPT_E_UNINIT.

[SWS_Gpt_00217] ==> Approved
 If development error detection is enabled for GPT module:
If the parameter Channel is invalid (not within the range specified by
configuration), the function Gpt_EnableNotification shall raise the error
GPT_E_PARAM_CHANNEL.

[SWS_Gpt_00379] ==> Approved
 If development error detection is enabled for GPT module:
If no valid notification function is configured (GptNotification), the function
Gpt_EnableNotification shall raise the error GPT_E_PARAM_CHANNEL.

****************************************************************************************/

//tenuGPT_err Gpt_DisableNotification(Gpt_ChannelType Channel);

#if GptWakeupFunctionalityApi == GptWakeupFunctionalityApi_ON
#if GptReportWakeupSource == GptReportWakeupSource_ON

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
 *  \pre                        None
 *  \context                    Task
 *  \reentrant                  Non Reentrant
 *  \synchronous                Synchronous
 *  \satisfied by               SWS_Gpt_00151
 *  \satisfied by               SWS_Gpt_00255
 *  \satisfied by               SWS_Gpt_00152
 *  \satisfied by               SWS_Gpt_00153
 *  \satisfied by               SWS_Gpt_00164
 *  \satisfied by               SWS_Gpt_00165
 *  \satisfied by               SWS_Gpt_00341
 *  \satisfied by               SWS_Gpt_00228
 *  \satisfied by               SWS_Gpt_00231
 *  \satisfied by				SWS_Gpt_00201
 *  \satisfied by				SWS_Gpt_00392
 *  \satisfied by				SWS_Gpt_00393
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
 *  \satisfied by               SWS_Gpt_00229
 *  \satisfied by               SWS_Gpt_00215
 *  \satisfied by               SWS_Gpt_00159
 *  \satisfied by               SWS_Gpt_00157
 *  \satisfied by               SWS_Gpt_00155
 *  \satisfied by               SWS_Gpt_00202
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
 *  \satisfied by               SWS_Gpt_00321
 *  \satisfied by               SWS_Gpt_00322
 *  \satisfied by               SWS_Gpt_00323
 *  \satisfied by               SWS_Gpt_00324
 *  \satisfied by               SWS_Gpt_00325
 *********************************************************************************************************************/
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

#endif
#endif
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
 *  \satisfied by               SWS_Gpt_00395
 *  \satisfied by               SWS_Gpt_00396
 *  \satisfied by               SWS_Gpt_00397
 *  \satisfied by               SWS_Gpt_00398
 *  \satisfied by               SWS_Gpt_00399
 *  \satisfied by               SWS_Gpt_00400
 *  \satisfied by               SWS_Gpt_00401
 *  \satisfied by               SWS_Gpt_00402
 *  \satisfied by               SWS_Gpt_00403
 *********************************************************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);

#endif  /* GPT_H */
