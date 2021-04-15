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



/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/



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
void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr){

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
void Gpt_Init(const Gpt_ConfigType* ConfigPtr){

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
void Gpt_DeInit(void){

}

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


