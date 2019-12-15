 /**
   CLC2 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     clc2.c
 
   @Summary
     This is the generated driver implementation file for the CLC2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CLC2.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
         Device            :  PIC16F18345
         Driver Version    :  2.01
     The generated drivers are tested against the following:
         Compiler          :  XC8 1.45 or later
         MPLAB             :  MPLAB X 4.15
 */ 

 /*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
 
 /**
   Section: Included Files
 */

#include <xc.h>
#include "clc2.h"
#include "mcc.h"
/**
  Section: CLC2 APIs
*/

void CLC2_Initialize(void)
{
    // Set the CLC2 to the options selected in the User Interface

    // LC2G1POL not_inverted; LC2G2POL not_inverted; LC2G3POL inverted; LC2G4POL not_inverted; LC2POL not_inverted; 
    CLC2POL = 0x04;
    // LC2D1S CLCIN1 (CLCIN1PPS); 
    CLC2SEL0 = 0x01;
    // LC2D2S CLCIN0 (CLCIN0PPS); 
    CLC2SEL1 = 0x00;
    // LC2D3S CLCIN0 (CLCIN0PPS); 
    CLC2SEL2 = 0x00;
    // LC2D4S CLCIN0 (CLCIN0PPS); 
    CLC2SEL3 = 0x00;
    // LC2G1D3N disabled; LC2G1D2N disabled; LC2G1D4N disabled; LC2G1D1T enabled; LC2G1D3T disabled; LC2G1D2T disabled; LC2G1D4T disabled; LC2G1D1N disabled; 
    CLC2GLS0 = 0x02;
    // LC2G2D2N disabled; LC2G2D1N disabled; LC2G2D4N disabled; LC2G2D3N disabled; LC2G2D2T enabled; LC2G2D1T disabled; LC2G2D4T enabled; LC2G2D3T enabled; 
    CLC2GLS1 = 0xA8;
    // LC2G3D1N disabled; LC2G3D2N disabled; LC2G3D3N disabled; LC2G3D4N disabled; LC2G3D1T disabled; LC2G3D2T enabled; LC2G3D3T enabled; LC2G3D4T enabled; 
    CLC2GLS2 = 0xA8;
    // LC2G4D1N disabled; LC2G4D2N disabled; LC2G4D3N disabled; LC2G4D4N disabled; LC2G4D1T disabled; LC2G4D2T enabled; LC2G4D3T enabled; LC2G4D4T enabled; 
    CLC2GLS3 = 0xA8;
    // LC2EN enabled; INTN disabled; INTP enabled; MODE 2-input D flip-flop with R; 
    CLC2CON = 0x95;

    // Clear the CLC interrupt flag
    PIR3bits.CLC2IF = 0;
    // Enabling CLC2 interrupt.
    PIE3bits.CLC2IE = 1;
}

void CLC2_ISR(void)
{
    CLC_2_Interrupt();
    // Clear the CLC interrupt flag
    PIR3bits.CLC2IF = 0;
}

bool CLC2_OutputStatusGet(void)
{
    return(CLC2CONbits.LC2OUT);
}
/**
 End of File
*/
