/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file  		Gpt.c
 *      \brief  	Gpt driver
 *      \details  	Implementation of the Gpt driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt.h"
#include "Gpt_MemMap.h"
#include "SchM_Gpt.h"
#include "Det.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum{
	Gpt_Uninitialized,
	Gpt_Initialized
}Gpt_Initialized_e;


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static Gpt_Initialized_e Gpt_InitValue;
static Gpt_ModeType Internal_Mode;


/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITION
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
void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{

/*only  version , check if pointer is null */
}
/*
 * Function Name: Gpt_Init
 * Description: Initializes the GPT drive
 * Parameters
 *	Inputs       : ConfigPtr Pointer to a selected configuration structure
 *	Input/Outputs:N/A
 *	Outputs      :N/A
 * Return value: :N/A
 * */
static Gpt_ConfigType* LockCfgPtr;
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	LockCfgPtr =ConfigPtr;

}
/*
 * Function Name: Gpt_DeInit
 * Description: DeInitializes the GPT drive
 * Parameters
 *	Inputs       :N/A
 *	Input/Outputs:N/A
 *	Outputs      :N/A
 * Return value: :N/A
 * */
#if GptDeInitApi ==ON
void Gpt_DeInit(void){

}
#endif

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

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
	return 0;
}




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

Gpt_ValueType Gpt_GetTimeReamaining(Gpt_ChannelType Channel)
{
	return 0;
}


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

void Gpt_StartTimer(Gpt_ChannelType channel , Gpt_ValueType Value)
{

}
/*
tenuTimerState Timer0_State;
tenuTimerState Timer1_State;
tenuTimerState Timer2_State;


tenuGPT_err Gpt_StopTimer(Gpt_ChannelType Channel) // violating the return type
{
	tenuGPT_err status;
	switch(Channel) //SWS_Gpt_00013
	{
	case Timer0:
		if(Timer0_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
		_TCCR0.u8RegData &= GPT_u8TCCR_CS_CLEAR_MASK;
		if(_TCCR0.u8RegData & (~GPT_u8TCCR_CS_CLEAR_MASK) == 0x00 )
		{
			Timer0_State = Stopped; //SWS_Gpt_00343
			status= GPT_E_OK;
		}
		break;
	case Timer1:
		if(Timer1_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
		_TCCR1B.u8RegData &= GPT_u8TCCR_CS_CLEAR_MASK;
		if(_TCCR1B.u8RegData & (~GPT_u8TCCR_CS_CLEAR_MASK) == 0x00 )
		{
			Timer1_State = Stopped;
			status= GPT_E_OK;
		}
		break;
	case Timer2:
		if(Timer2_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
		_TCCR2.u8RegData &= GPT_u8TCCR_CS_CLEAR_MASK;
		if(_TCCR2.u8RegData & (~GPT_u8TCCR_CS_CLEAR_MASK) == 0x00 )
		{
			Timer2_State = Stopped;
			status= GPT_E_OK;
		}
		break;
	default:
		status = GPT_E_PARAM_CHANNEL; //SWS_Gpt_00213
		break;
	}
	return status;
}

#if GptEnableDisableNotificationApi == On //SWS_Gpt_00199
/* ***************************************************************************************
 * Public Function:                                                                      *
 * Description: This function is used to enable the notification for the timer         	 *
 *   Input parameters :                                                                  *
 *						                                                                 *
 * Return:                                                                               *
 *         - Not applicable (void)													     *
 * Input/Output parameters:      														 *
 * 		   - Not applicable																 *
 * ***************************************************************************************/
/*
tenuGPT_err Gpt_EnableNotification(Gpt_ChannelType Channel)
{
	tenuGPT_err status;
	switch(Channel) //SWS_Gpt_00013
	{
	case Timer0:
		if(Timer0_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
#if GPT_0_OVERFLOW_IR == ENABLED
		_TIMSK.Bits.u8Bit_0 = 1; //SWS_Gpt_00117
#endif
#if GPT_0_OUTPUT_COMPARE_IR == ENABLED
		_TIMSK.Bits.u8Bit_1 = 1;
#endif

#if (GPT_0_OVERFLOW_IR == DISABLED) && (GPT_0_OUTPUT_COMPARE_IR == DISABLED) //SWS_Gpt_00377
		status = GPT_E_PARAM_CHANNEL;
#endif
		break;
	case Timer1:
		if(Timer1_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
#if GPT_1_OVERFLOW_IR == ENABLED
		_TIMSK.Bits.u8Bit_2 = 1;
#endif
#if GPT_1_OUTPUT_COMPAREA_IR == ENABLED
		_TIMSK.Bits.u8Bit_4 = 1;
#endif
#if GPT_1_OUTPUT_COMPAREB_IR == ENABLED
		_TIMSK.Bits.u8Bit_3 = 1;
#endif
#if GPT_1_INPUT_CAPTURE_IR == ENABLED
		_TIMSK.Bits.u8Bit_3 = 1;
#endif

#if (GPT_1_OVERFLOW_IR == DISABLED) && (GPT_1_OUTPUT_COMPAREA_IR == DISABLED) && (GPT_1_OUTPUT_COMPAREB_IR == DISABLED) && (GPT_1_INPUT_CAPTURE_IR == DISABLED) //SWS_Gpt_00377
		status = GPT_E_PARAM_CHANNEL;
#endif
		break;
	case Timer2:
		if(Timer2_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
#if GPT_2_OVERFLOW_IR == ENABLED
		_TIMSK.Bits.u8Bit_7 = 1;
#endif
#if GPT_2_OUTPUT_COMPARE_IR == ENABLED
		_TIMSK.Bits.u8Bit_6 = 1;
#endif

#if (GPT_2_OVERFLOW_IR == DISABLED) && (GPT_2_OUTPUT_COMPARE_IR == DISABLED)//SWS_Gpt_00377
		status = GPT_E_PARAM_CHANNEL;
#endif
		break;
	default:
		status = GPT_E_PARAM_CHANNEL; //SWS_Gpt_00213
		break;
	}
}

/*
tenuGPT_err Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	tenuGPT_err status;
	switch(Channel) //SWS_Gpt_00013
	{
	case Timer0:
		if(Timer0_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
#if GPT_0_OVERFLOW_IR == ENABLED
		_TIMSK.Bits.u8Bit_0 = 0; //SWS_Gpt_00117
#endif
#if GPT_0_OUTPUT_COMPARE_IR == ENABLED
		_TIMSK.Bits.u8Bit_1 = 0;
#endif

#if (GPT_0_OVERFLOW_IR == DISABLED) && (GPT_0_OUTPUT_COMPARE_IR == DISABLED) //SWS_Gpt_00377
		status = GPT_E_PARAM_CHANNEL;
#endif
		break;
	case Timer1:
		if(Timer1_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
#if GPT_1_OVERFLOW_IR == ENABLED
		_TIMSK.Bits.u8Bit_2 = 0;
#endif
#if GPT_1_OUTPUT_COMPAREA_IR == ENABLED
		_TIMSK.Bits.u8Bit_4 = 0;
#endif
#if GPT_1_OUTPUT_COMPAREB_IR == ENABLED
		_TIMSK.Bits.u8Bit_3 = 0;
#endif
#if GPT_1_INPUT_CAPTURE_IR == ENABLED
		_TIMSK.Bits.u8Bit_3 = 0;
#endif

#if (GPT_1_OVERFLOW_IR == DISABLED) && (GPT_1_OUTPUT_COMPAREA_IR == DISABLED) && (GPT_1_OUTPUT_COMPAREB_IR == DISABLED) && (GPT_1_INPUT_CAPTURE_IR == DISABLED) //SWS_Gpt_00377
		status = GPT_E_PARAM_CHANNEL;
#endif
		break;
	case Timer2:
		if(Timer2_State == UnIntialized)//SWS_Gpt_00225
		{
			status = GPT_E_UNINIT;
		}
#if GPT_2_OVERFLOW_IR == ENABLED
		_TIMSK.Bits.u8Bit_7 = 0;
#endif
#if GPT_2_OUTPUT_COMPARE_IR == ENABLED
		_TIMSK.Bits.u8Bit_6 = 0;
#endif

#if (GPT_2_OVERFLOW_IR == DISABLED) && (GPT_2_OUTPUT_COMPARE_IR == DISABLED)//SWS_Gpt_00377
		status = GPT_E_PARAM_CHANNEL;
#endif
		break;
	default:
		status = GPT_E_PARAM_CHANNEL; //SWS_Gpt_00213
		break;
	}
}
#endif
 */

#if GptWakeupFunctionalityApi == GptWakeupFunctionalityApi_ON
/*
	[SWS_Gpt_00255] ⌈ The function Gpt_SetMode is only available if the configuration
	parameter GptReportWakeupSource is enabled.  ( )
 */
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
void Gpt_SetMode(Gpt_ModeType Mode){
	int localCounter;
	uint8 LocalState=E_OK;

#if GptDevErrorDetect == GptDevErrorDetect_ON

	/*
	[SWS_Gpt_00228] ⌈ If development error detection is enabled for GPT module:
	If the driver is not initialized, the function Gpt_SetMode shall raise the error
	GPT_E_UNINIT. ⌋ (SRS_BSW_00406)
	 */
	if(Gpt_Uninitialized==Gpt_InitValue){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_SetMode,GPT_E_UNINIT);
		LocalState=E_NOT_OK;
	}
	/*
	[SWS_Gpt_00231] ⌈ If development error detection is enabled for GPT module:
	The function Gpt_SetMode shall raise the error GPT_E_PARAM_MODE if the
	parameter Mode is invalid. ⌋ ( )
	 */
	if(Mode>GPT_MODE_SLEEP){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_SetMode,GPT_E_PARAM_MODE);
		LocalState=E_NOT_OK;
	}


#endif
	if(LocalState == E_OK){
		/*
	[SWS_Gpt_00151] ⌈ The function Gpt_SetMode shall set the operation mode of the
	GPT driver to the given mode parameter.  (SRS_SPAL_12169, SRS_Gpt_13603)
		 */
		Internal_Mode=Mode;

		/*
	[SWS_Gpt_00152] ⌈ If the parameter Mode has the value GPT_MODE_NORMAL:
	The function Gpt_SetMode shall enable the interrupt notification for all channels
	which are configured for notification and the notification is enabled (stored attribute)
	via the function Gpt_EnableNotification prior. All other interrupt notifications
	shall be disabled. ⌋ (SRS_Gpt_13603)
		 */
		/*
	[SWS_Gpt_00165] ⌈ If the parameter Mode has the value GPT_MODE_NORMAL, the
	function Gpt_SetMode shall not restart automatically the timer channels which have
	been stopped by entering the sleep mode. ⌋ ( )
		 */
		/*
	 if(Mode == GPT_MODE_NORMAL){
	 for(localCounter=0;localCounter<ChannelsSize;localCounter++){
	 if(Channel[localCounter].NotificationEnabled == NotificationEnabled_ON){
	 //enable the interrupt notification
	  Timer_EnableNotification(ChannelID);
	 }
		 */

		/*
	[SWS_Gpt_00392] ⌈ If the parameter Mode has the value GPT_MODE_NORMAL:
	If the driver is in “sleep mode”, the function Gpt_SetMode shall restart all enabled
	GPT Predef Timers at value “0”. ⌋ (SRS_Gpt_13607)
		 */
		/*
	 if(ChannelCfg[localCounter].GptPredefTimer100us32bitEnable == GptPredefTimer100us32bitEnable_ON){
	 //restart all enabled 	GPT Predef Timers at value “0”
	  Timer_Start(ChannelID);
	 }
	 }

	 }
		 */

		/*
	[SWS_Gpt_00153] ⌈ If the parameter Mode has the value GPT_MODE_SLEEP:
	The function Gpt_SetMode shall enable the wakeup interrupts for all channels which
	are configured for wakeup and the wakeup is enabled (stored attribute) via the
	function Gpt_EnableWakeup prior. All other wakeup interrupts shall be disabled. ⌋
	(SRS_Gpt_13603)
		 */
		/*
	[SWS_Gpt_00341] ⌈ If the parameter has the value GPT_MODE_SLEEP the function
	Gpt_SetMode shall not start a wakeup timer automatically. First, the user shall call
	Gpt_StartTimer to start a wakeup timer, after this the user shall call
	Gpt_SetMode with parameter GPT_MODE_SLEEP. ⌋ ( )
		 */
		/*
		else if(Mode == GPT_MODE_SLEEP){
		 for(localCounter=0;localCounter<ChannelsSize;localCounter++){
		 if(Channel[localCounter].Gpt_EnableWakeup == Gpt_EnableWakeup_ON){
		 //enable the wakeup interrupt notification
		  Timer_WakeupEnableNotification(ChannelID);
		 }
		 */
		/*
	[SWS_Gpt_00164] ⌈ If the function Gpt_SetMode is called with parameter Mode
	has the value GPT_MODE_SLEEP: All timer channels in state "running" which are not
	configured for wakeup or not enabled for wakeup interruption (stored attribute) via
	Gpt_EnableWakeup shall be stopped and their state shall be changed to "stopped".
	⌋ ( )
		 */

		/*
	[SWS_Gpt_00393] ⌈ If the parameter Mode has the value GPT_MODE_SLEEP:
	The function Gpt_SetMode shall stop all enabled GPT Predef Timers. ⌋
	(SRS_Gpt_13607)
		 */
		/*
		 else if(ChannelCfg[localCounter].Gpt_EnableWakeup == Gpt_EnableWakeup_OFF){
		 if(Channel[localCounter].State == Running){
		 // shall be stopped and their state shall be changed to "stopped"
		  Timer_Stop(ChannelID);
		  Channel[localCounter].State= Stopped;
		  }
		 }
		 }

		 }
		 */
	}
}
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
void Gpt_DisableWakeup(Gpt_ChannelType Channel){
	uint8 LocalState=E_OK;
#if GptDevErrorDetect == GptDevErrorDetect_ON

	/*
	[SWS_Gpt_00229] ⌈ If development error detection is enabled for GPT module:
	If the driver is not initialized, the function Gpt_DisableWakeup shall raise the error
	GPT_E_UNINIT. ⌋ (SRS_BSW_00406)
	 */
	if(Gpt_Uninitialized==Gpt_InitValue){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_DisableWakeup,GPT_E_UNINIT);
		LocalState=E_NOT_OK;
	}
	/*
	[SWS_Gpt_00215] ⌈ If development error detection is enabled for GPT module:
	If the parameter Channel is invalid (not within the range specified by configuration)
	or channel wakeup is not enabled by configuration (GptEnableWakeup), the function
	Gpt_DisableWakeup shall raise the error GPT_E_PARAM_CHANNEL. ⌋ ( )
	 */
	/*
	if((Channel>channel_1)||(Channel_cfg[Channel].GptEnableWakeup==Gpt_EnableWakeup_OFF)){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_DisableWakeup,GPT_E_PARAM_CHANNEL);
		LocalState=E_NOT_OK;

	}

	 */
#endif
	if(LocalState == E_OK ){

		/*
	[SWS_Gpt_00159] ⌈ The function Gpt_DisableWakeup shall disable the wakeup
	interrupt of the referenced channel configured for wakeup. The function shall save an
	attribute like "wakeup disabled" of the channel.
	Comment: This attribute affects the wakeup interrupt always when the driver is in
	"sleep mode". In "normal mode" the attribute has no influence. ⌋ (SRS_Gpt_13602)
		 */
		/*
	 Timer_DisableWakeup(Channel);
	 Channel[Channel].WakeupEnabled=WakeupEnabled_OFF;
		 */

	}


}

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
 *  \satisfied by               SWS_Gpt_00230
 *  \satisfied by               SWS_Gpt_00216
 *  \satisfied by               SWS_Gpt_00160
 *  \satisfied by               SWS_Gpt_00158
 *  \satisfied by               SWS_Gpt_00156
 *  \satisfied by               SWS_Gpt_00203
 *********************************************************************************************************************/
void Gpt_EnableWakeup(Gpt_ChannelType Channel){
	uint8 LocalState=E_OK;
#if GptDevErrorDetect == GptDevErrorDetect_ON

	/*
	[SWS_Gpt_00230] ⌈ If development error detection is enabled for GPT module:
	If the driver is not initialized, the function Gpt_EnableWakeup shall raise the error
	GPT_E_UNINIT. ⌋ (SRS_BSW_00406)
	 */
	if(Gpt_Uninitialized==Gpt_InitValue){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_EnableWakeup,GPT_E_UNINIT);
		LocalState=E_NOT_OK;
	}
	/*
	[SWS_Gpt_00216] ⌈ If development error detection is enabled for GPT module:
	If the parameter Channel is invalid (not within the range specified by configuration)
	or channel wakeup is not enabled by configuration (GptEnableWakeup), the function
	Gpt_EnableWakeup shall raise the error GPT_E_PARAM_CHANNEL. ⌋ ( )
	 */

	/*
	if((Channel>channel_1)||(Channel_cfg[Channel].GptEnableWakeup==Gpt_EnableWakeup_OFF)){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_EnableWakeup,GPT_E_PARAM_CHANNEL);
		LocalState=E_NOT_OK;

	}

	 */
#endif
	if(LocalState == E_OK ){
		/*
	[SWS_Gpt_00160] ⌈ The function Gpt_EnableWakeup shall enable the wakeup
	interrupt of the referenced channel configured for wakeup. The function shall save an
	attribute like "wakeup enabled" of the channel. ⌋ (SRS_Gpt_13602)
	Comment: This attribute affects the wakeup interrupt always when the driver is in
	"sleep mode". In "normal mode" the attribute has no influence.
		 */


		/*
		 Timer_EnableWakeup(Channel);
		 Channel[Channel].WakeupEnabled=WakeupEnabled_ON;
		 */

	}
}

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
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource){
	uint8 LocalState=E_OK;
#if GptDevErrorDetect == GptDevErrorDetect_ON

	/*
	[SWS_Gpt_00325] ⌈ If development error detection is enabled for GPT module:
	If the driver is not initialized, the function Gpt_CheckWakeup shall raise the error
	GPT_E_UNINIT. ⌋ (SRS_BSW_00406)
	 */
	if(Gpt_Uninitialized==Gpt_InitValue){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_CheckWakeup,GPT_E_UNINIT);
		LocalState=E_NOT_OK;
	}
#endif
	/*
	[SWS_Gpt_00321] ⌈ The function Gpt_CheckWakeup shall check if a wakeup
	capable GPT channel is the source for a wakeup event and call
	EcuM_SetWakeupEvent to indicate a valid timer wakeup event to the ECU State
	Manager [8]. ⌋ ( )
	 */
#ifdef GptWakeupSourceRef
	EcuM_SetWakeupEvent(GptWakeupSourceRef);
#endif

}

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
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr){
	uint8 LocalState=E_OK;
	Std_ReturnType LocalReturn=E_NOT_OK;
#if GptDevErrorDetect == GptDevErrorDetect_ON
	/*
	[SWS_Gpt_00398] ⌈ If development error detection is enabled for GPT module: If
	the driver is not initialized, the function Gpt_GetPredefTimerValue shall raise
	the error GPT_E_UNINIT. ⌋ (SRS_BSW_00406)
	 */
	if(Gpt_Uninitialized==Gpt_InitValue){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_GetPredefTimerValue,GPT_E_UNINIT);
		LocalState=E_NOT_OK;
	}
	/*
	[SWS_Gpt_00400] ⌈ If development error detection is enabled for GPT module: If
	the GPT Predef Timer passed by the parameter PredefTimer is not enabled, the
	function Gpt_GetPredefTimerValue shall raise the development error
	GPT_E_PARAM_PREDEF_TIMER. ⌋ ( )
	 */
	/*
	if( (GptDriverConfiguration.GptPredefTimer1usEnablingGrade != PredefTimer )
			&&(GptDriverConfiguration.GptPredefTimer100us32bitEnable != PredefTimer)){

			Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_GetPredefTimerValue,GPT_E_PARAM_PREDEF_TIMER);
			LocalState=E_NOT_OK;
	}

	 */
	/*
	[SWS_Gpt_00399] ⌈ If development error detection is enabled for GPT module: If
	the parameter PredefTimer is invalid, the function
	Gpt_GetPredefTimerValue shall raise the development error
	GPT_E_PARAM_PREDEF_TIMER. ⌋ (SRS_BSW_00323)
	 */
	if( PredefTimer > GPT_PREDEF_TIMER_100US_32BIT){

		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_GetPredefTimerValue,GPT_E_PARAM_PREDEF_TIMER);
		LocalState=E_NOT_OK;
	}
	/*
	[SWS_Gpt_00403] ⌈ If development error detection is enabled for GPT module: If
	the parameter TimeValuePtr is a null pointer, the function
	Gpt_GetPredefTimerValue shall raise the error GPT_E_PARAM_POINTER.⌋
	(SRS_BSW_00369, SRS_BSW_00323)
	 */
	if(TimeValuePtr == 0){
		Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_GetPredefTimerValue,GPT_E_PARAM_POINTER);
		LocalState=E_NOT_OK;

	}


#endif
	/*
	[SWS_Gpt_00401] ⌈ If the driver is in "sleep mode", the function
	Gpt_GetPredefTimerValue shall raise the runtime error GPT_E_MODE.⌋ ( )
	 */

	if(Internal_Mode == GPT_MODE_SLEEP){
		Det_ReportRuntimeError(GPT_MODULE_ID,GPT_INSTANCE_ID,API_ID_Gpt_GetPredefTimerValue,GPT_E_MODE);
		LocalState=E_NOT_OK;
	}
	/*
	[SWS_Gpt_00402] ⌈ If the GPT driver is not initialized, in “sleep mode” or the GPT
	Predef Timer is not enabled, the function Gpt_GetPredefTimerValue shall
	return E_NOT_OK. ⌋ (SRS_BSW_00406)
	Note:
	This is to inform user software if the hardware timer is not running, independent of
	development error detection is enabled for GPT module enabled/disabled for the
	GPT module. The function Gpt_GetPredefTimerValue is used by the Time
	Service module which is part of the Services Layer. The user of the Time Service
	module shall have a chance to cope with missed timer support.
	 */

	if(Internal_Mode == GPT_MODE_SLEEP){
		LocalState=E_NOT_OK;
	}

	if(LocalState == E_OK){
		/*
	[SWS_Gpt_00395] ⌈ The function Gpt_GetPredefTimerValue shall return the
	current value of the GPT Predef Timer passed by PredefTimer. ⌋
	(SRS_Gpt_13608)
		 */
		/*
	[SWS_Gpt_00396] ⌈ If the timer value of the function Gpt_GetPredefTimerValue
	is less than 32 bit (16bit or 24bit timer), the upper bits shall be filled with zero. ⌋ ( )
		 */
		/*
	 Timer_GetCurrentValue(TimeValuePtr);
		 */



		LocalReturn=E_OK;
	}
	return LocalReturn;
}
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void Gpt_Notification_channel_0(void)
 *********************************************************************************************************************/
/*! \details       				The notification prototype Gpt_Notification_<channel> is for the notification
								callback function and shall be implemented by the user.
								The GPT module’s environment shall declare a separate notification for each channel
								to avoid parameters in notification services and to improve run time efficiency.
 *  \param[in]                  None
 *  \param[in,out]              None
 *  \param[out]                 None
 *  \return       				None
 *  \pre                        None
 *  \context                    Task
 *  \reentrant                  Reentrant
 *  \synchronous                Synchronous
 *  \satisfied by               SWS_Gpt_00086
 *  \satisfied by               SWS_Gpt_00209
 *  \satisfied by               SWS_Gpt_00093
 *  \satisfied by               SWS_Gpt_00233
 *  \satisfied by               SWS_Gpt_00206
 *  \violated by                SWS_Gpt_00362
 *********************************************************************************************************************/
void Gpt_Notification_channel_0(void){
	/*
	[SWS_Gpt_00093] ⌈ When disabled, the GPT Driver will send no notification. ⌋ ( )
	*/
	/*
	 if(Channels_cfg[channel0].Gpt_NotificationEnable==Enabled){
	 */
	/*
	[SWS_Gpt_00086] ⌈ The callback notifications Gpt_Notification_<channel>
	shall be configurable as pointers to user defined functions within the configuration
	structure. ⌋ ( )
	*/
	/*
	[SWS_Gpt_00209] ⌈ Each channel shall provide its own notification if configured. ⌋
	(SRS_BSW_00375, SRS_SPAL_12069)
	*/
	/*
	[SWS_Gpt_00233] ⌈ The GPT Driver shall invoke a notification whenever the
	defined target time of the channel is reached. ⌋ (SRS_SPAL_12067,
	SRS_Gpt_12120)
	*/
	/*
	[SWS_Gpt_00206] ⌈ The ISR´s, providing the timer events, shall be responsible for
	resetting the interrupt flags (if needed by hardware) and calling the according
	notification function. ⌋ (SRS_SPAL_12129)
	*/
	/*
	 Channels_cfg[channel0].Gpt_Notification();
	 */
	//}
	/*
	[SWS_Gpt_00362] ⌈ For all available channels, callback functions have to be
	declared by the configuration tool. ⌋ ( )
	*/
}

