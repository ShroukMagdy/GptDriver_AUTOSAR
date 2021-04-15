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




#endif  /* GPT_CFG_H */
