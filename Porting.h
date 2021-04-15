/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file  		Porting.h
 *      \brief  	Gpt driver
 *      \details  	Implementation of the Gpt driver
 *
 *********************************************************************************************************************/
#ifndef PORTING_H_
#define PORTING_H_

/****************************************ROANNE********************************************/
/*
 * AVR Platforms
 * Channel 0 -->> Timer 0
 * */
#define  GPT_TIMER0_NORMAL_MODE                                  0x00
#define  GPT_TIMER0_CLEAR_TIMER_ON_COMPARE_MATCH_MODE            0x40
#define  GPT_TIMER0_MODE_CLEAR_MASK					             ~(0x48)
#define  GPT_TIMER0_OVERFLOW_INTERRUPT_ENABLE                    0x01
#define  GPT_TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE        0x02
#define  GPT_TIMER0_INTERRUPT_SOURCE_CLEAR_MASK                  ~(0x03)

/******************************************************************************************/



/******************************TIMER MODES********************************/
#define GPT_u8TCCR0_MODE_NORMAL         0x00
#define GPT_u8TCCR0_MODE_PWM_PC         0x04
#define GPT_u8TCCR0_MODE_CTC            0x40
#define GPT_u8TCCR0_MODE_FAST_PWM       0x44
#define GPT_u8TCCR0_MODE_CLEAR_MASK     0xBB


/***********************COMPARE OUTPUT ON MATCH******************************/

/****************************************YOUSSEF*******************************************/

#define GPT_u8TCCR0_COM_NORMAL          0X00

//FAST PWM MODE
#define GPT_u8TCCR0_COM_FAST_PWM_CLEAR_OC0       0X20
#define GPT_u8TCCR0_COM_FAST_PWM_SET_OC0         0X30
#define GPT_u8TCCR0_COM_FAST_PWM_CLEAR_MASK      0XCF

//PHASECORRECT PWM MODE
#define GPT_u8TCCR0_COM_PC_PWM_CLEAR_OC0         0X20
#define GPT_u8TCCR0_COM_PC_PWM_SET_OC0           0X30
#define GPT_u8TCCR0_COM_PC_PWM_CLEAR_MASK        0XCF

//CTC MODE
#define GPT_u8TCCR0_COM_NO_PWM_TOGGLE_OC0       0X10
#define GPT_u8TCCR0_COM_NO_PWM_CLEAR_OC0        0X20
#define GPT_u8TCCR0_COM_NO_PWM_SET_OC0          0X30
#define GPT_u8TCCR0_COM_NO_PWM_CLEAR_MASK       0XCF

/*********************************CLOCK SELET**********************************/

#define GPT_u8TCCR_CS_NO_CLK                                 0X00
#define GPT_u8TCCR_CS_CLK_0                                  0X01
#define GPT_u8TCCR_CS_CLK_8                                  0X02
#define GPT_u8TCCR_CS_CLK_64                                 0X03
#define GPT_u8TCCR_CS_CLK_256                                0X04
#define GPT_u8TCCR_CS_CLK_1024                               0X05
#define GPT_u8TCCR_CS_EXT_T0_FALLING_EDGE                    0X06
#define GPT_u8TCCR_CS_EXT_T0_RISING_EDGE                     0X07
#define GPT_u8TCCR_CS_CLEAR_MASK                             (~0X07)


#define GPT_u8TIMER_OVERFLOW                     0
#define GPT_u8OUTPUT_COMPARE_MATCH               1

/******************************************************************************/

/******************************************************************************************/


#endif /* PORTING_H_ */
