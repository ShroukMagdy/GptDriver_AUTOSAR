/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file  		Gpt_Cfg.h
 *      \brief  	Gpt driver
 *      \details  	Implementation of the Gpt driver
 *
 *********************************************************************************************************************/
#ifndef GPT_CFG_H
#define GPT_CFG_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/


/****************************************YOUSSEF*******************************************/

#define GptEnableDisableNotificationApi   On


#if GptEnableDisableNotificationApi == On

#define GPT_0_OVERFLOW_IR  ENABLED
#define GPT_0_OUTPUT_COMPARE_IR DISABLED

#define GPT_1_OVERFLOW_IR  ENABLED
#define GPT_1_OUTPUT_COMPAREA_IR DISABLED
#define GPT_1_OUTPUT_COMPAREB_IR DISABLED
#define GPT_1_INPUT_CAPTURE_IR DISABLED


#define GPT_2_OVERFLOW_IR  ENABLED
#define GPT_2_OUTPUT_COMPARE_IR DISABLED

#endif

/******************************************************************************************/
/*
Switches the development error detection and notification on or off.
 true: detection and notification is enabled.
 false: detection and notification is disabled
*/
typedef enum{
	GptDevErrorDetect_ON,
	GptDevErrorDetect_OFF
}GptDevErrorDetect_e;
//Enables/disables the GPT Predef Timer 100µs32bit.
typedef enum{
	GptPredefTimer100us32bitEnable_ON,
	GptPredefTimer100us32bitEnable_OFF
}GptPredefTimer100us32bitEnable_e;
//Specifies the grade of enabling the GPT Predef Timers with 1µs tick duration.
typedef enum{
	GPT_PREDEF_TIMER_1US_16BIT_ENABLED, 		//16bit timer enabled
	GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED, 		//16 and 24bit timers enabled
	GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED, 	//16, 24 and 32bit timers enabled
	GPT_PREDEF_TIMER_1US_DISABLED 				//disabled
}GptPredefTimer1usEnablingGrade_e;
//Enables/Disables wakeup source reporting
typedef enum{
	GptReportWakeupSource_ON,
	GptReportWakeupSource_OFF
}GptReportWakeupSource_e;

/*
 * parent container :GptDriverConfiguration
 * Description This container contains the module-wide configuration (parameters) of the GPT Driver

	GptDevErrorDetect_e GptDevErrorDetect;
	GptPredefTimer100us32bitEnable_e GptPredefTimer100us32bitEnable;
	GptPredefTimer1usEnablingGrade_e GptPredefTimer1usEnablingGrade;
	GptReportWakeupSource_e GptReportWakeupSource;
	*/

#define GptDevErrorDetect 		GptDevErrorDetect_ON
#define GptReportWakeupSource 	GptReportWakeupSource_ON
/*
 * Adds / removes the services Gpt_SetMode(), Gpt_EnableWakeup()
Gpt_DisableWakeup() and Gpt_CheckWakeup() from the code.
 *
 */
typedef enum{
	GptWakeupFunctionalityApi_ON,
	GptWakeupFunctionalityApi_OFF
}GptWakeupFunctionalityApi_e;

#define GptWakeupFunctionalityApi GptWakeupFunctionalityApi_ON

/***return to ECU as it should be according to bitfield, this value is not mandatory*/
#define GPT_CHANNEL0				0x20
#define GptWakeupSourceRef		GPT_CHANNEL0

#endif  /* GPT_CFG_H */
