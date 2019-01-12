/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdlib.h"

int data_D_MSB,data_C,data_B,data_A_LSB,cuenta=0,numeroint=0;
char i='\0';
char numero[3]=" ";
char8 Keypad_1_Key[4][4] = {
                        {'1','2','3','A'}, //Row1
                        {'4','5','6','B'}, //Row2
                        {'7','8','9','C'}, //Row3
                        {'*','0','#','D'}  //Row4
                    };

void LeerTecla(){
    
    data_D_MSB=Data_D_MSB_Read();
    data_C=Data_C_Read();
    data_B=Data_B_Read();
    data_A_LSB=Data_A_LSB_Read();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
