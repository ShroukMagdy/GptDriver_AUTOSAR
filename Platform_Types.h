/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file  		Platform_Types.h
 *      \brief  	Gpt driver
 *      \details  	Implementation of the Gpt driver
 *
 *********************************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

typedef unsigned char 			uint8;				//[0, 255] range														1 byte
typedef signed char 			sint8;				//[-127, +127] range													1 byte

typedef unsigned short int		uint16;			//[0, 65,535] range														2 bytes
typedef signed short int 		sint16;			//[-32,767, +32,767] range												2 bytes

typedef unsigned long int 		uint32;			//[0, 4,294,967,295] range												4 bytes
typedef signed long int 		sint32;			//[-2,147,483,647, +2,147,483,647] range								4 bytes

typedef unsigned long long int 	uint64;			//[0, +18,446,744,073,709,551,615] range								8 bytes
typedef signed long long int 	sint64;			//[-9,223,372,036,854,775,807, +9,223,372,036,854,775,807] range		8 bytes

typedef  float 					f32;			//																		4 bytes
typedef  double 				d64;			//																		8 bytes
typedef  long double 			ld80;			//																		10 bytes

typedef enum {
	E_OK 	  		=  0x00  ,   		// Function Return OK
	E_NOT_OK  		=  0x01  ,   		// Function Return NOT OK
	E_PARAM_NOT_OK  =  0x02  ,   		// Function Return parameter NOT OK
	E_BUSY 	  		=  0x03  ,   		// Function Return busy
	E_PENDING 		=  0x04     		// Function Return pending
}Std_ReturnType;

#define STD_ON       		  		0x01       		// Standard ON
#define STD_OFF		         		0x00	        // Standard OFF

//for any callback function
typedef void (*Ptr_Callbackfn) (void);


#endif  /* PLATFORM_TYPES_H */
