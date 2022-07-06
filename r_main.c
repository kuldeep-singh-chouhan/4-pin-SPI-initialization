/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G13 V2.05.06.02 [08 Nov 2021]
* Device(s)    : R5F100FC
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 23-06-2022
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */

//-----added on 20/06 A0 and RES changed to p146 & p147 respectively----
//-----modified on 21/06 CS1B at p51 respectively-----------------------
#define RESET P14_bit.no6      // lcd res
#define A0 P14_bit.no7         // lcd a0
#define ENABLE P2_bit.no7      // cs1b
//----------------------------------------------------------------------
void hdwinit(void);
void Delay(unsigned int times);
void initLCD(void);
void writeData(unsigned char data, int a0);
//-----modified 21/06 changed to channel 0 from channel 3---------------
void R_CSI00_Start(void);
//------added on 23/06--------------------------------------------------
//unsigned char insSet1[]={0xe2,0x2c,0x2e,0x2f,0x25,0x81,0X1d,0xa2,0xa0,0xc8,0x40,0xaf};
unsigned char insSet2[]={0xa4,0xa6,0xa0,0xc8,0x40,0x25,0x81,0X1b,0xa2,0x2c,0x2e,0x2f,0xaf};
unsigned int i;
unsigned char bit_data;
unsigned char temp;
//----------------------------------------------------------------------
void Delay(unsigned int times)
  {
   while(times)   {
    for(i=125;i>0;i--);
    WDTE = 0xACU;
    times--;
   }
  }

// void writeData(unsigned char data, int a0){
//     CS1B = 1;
//     LCD_A0 = a0;
//     //R_CSI00_Send(&data, 1);
//     //for(i=0;i<8;i++)
// 	//{
        	
// 		//temp=data;
// 		//bit_data &= 0x00;
// 		//bit_data = temp&0x80;
// 		//R_CSI00_Send(&bit_data, 1);
//           	//temp=data<<1;
// 	      	//data=temp; 
//  	//} 
//     R_CSI00_Send(&data, 8);
//     //CS1B = 1;
//    // LCD_A0 = a0^1;
// }

void LCDinit(void){
    //------- added 30/06 ---------------
    Delay(50);
    ENABLE = 1;
    Delay(100);
    ENABLE = 0;     // slave select enabled
    Delay(50);
    RESET = 0;
    Delay(100);
    RESET = 1;    // lcd reset
    Delay(50);
    R_CSI00_Send(&insSet2[0], 8);
    R_CSI00_Send(&insSet2[1], 8);
    R_CSI00_Send(&insSet2[2], 8);
    R_CSI00_Send(&insSet2[3], 8);
    R_CSI00_Send(&insSet2[4], 8);
    R_CSI00_Send(&insSet2[5], 8);
    R_CSI00_Send(&insSet2[6], 8);
    R_CSI00_Send(&insSet2[7], 8);
    R_CSI00_Send(&insSet2[8], 8);
    R_CSI00_Send(&insSet2[9], 8);
    R_CSI00_Send(&insSet2[10], 8);
    R_CSI00_Send(&insSet2[11], 8);
    R_CSI00_Send(&insSet2[12], 8);
    




}
// void initLCD(void){
//     CS1B = 1;
//     LCD_RES = 0;
//     Delay(200);
//     LCD_RES = 1;
//     Delay(500);
//     LCD_A0 = 0;
//     for( i = 0; i < 13; i++ )
//     {
// 	    R_CSI00_Send(&insSet2[i], 8);
// 	    //Delay(500);
//     } 

// }


/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    WDTE = 0xACU;   /* restart watchdog timer */
    hdwinit();
    R_CSI00_Start();
    RESET = 0;
    Delay(100);
    RESET = 1;    // lcd reset
    ENABLE = 1;
    Delay(100);
    ENABLE = 0;     // slave select enabled
    LCDinit();
    
    while (1U)
    {
	    
    //Delay(50);
	R_CSI00_Send(&insSet2[12], 8);
    
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
