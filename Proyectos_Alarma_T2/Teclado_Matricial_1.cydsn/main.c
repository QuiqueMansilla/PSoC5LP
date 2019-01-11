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
    
    if((data_D_MSB == 0)&&(data_C == 0)&&(data_B == 0)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[0][3]; //En la matriz primero se coloca valor de Fila y luego valor de Columna
                              //en este caso corresponde a la tecla '*' asterisco
    }
    if((data_D_MSB == 0)&&(data_C == 0)&&(data_B == 0)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[1][3]; //en este caso corresponde a la tecla '0' cero
    }
    if((data_D_MSB == 0)&&(data_C == 0)&&(data_B == 1)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[0][1]; //en este caso corresponde a la tecla '4' 
    }
    if((data_D_MSB == 0)&&(data_C == 0)&&(data_B == 1)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[1][1]; //en este caso corresponde a la tecla '5' 
    }
    if((data_D_MSB == 0)&&(data_C == 1)&&(data_B == 0)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[2][3]; //en este caso corresponde a la tecla '#' numeral
    }
    if((data_D_MSB == 0)&&(data_C == 1)&&(data_B == 0)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[3][3]; //en este caso corresponde a la tecla 'D' 
    }
    if((data_D_MSB == 0)&&(data_C == 1)&&(data_B == 1)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[2][1]; //en este caso corresponde a la tecla '6' 
    }
    if((data_D_MSB == 0)&&(data_C == 1)&&(data_B == 1)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[3][1]; //en este caso corresponde a la tecla 'B' 
    }
    if((data_D_MSB == 1)&&(data_C == 0)&&(data_B == 0)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[0][2]; //en este caso corresponde a la tecla '7' 
    }
    if((data_D_MSB == 1)&&(data_C == 0)&&(data_B == 0)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[1][2]; //en este caso corresponde a la tecla '8' 
    }
    if((data_D_MSB == 1)&&(data_C == 0)&&(data_B == 1)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[0][0]; //en este caso corresponde a la tecla '1' 
    }
    if((data_D_MSB == 1)&&(data_C == 0)&&(data_B == 1)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[1][0]; //en este caso corresponde a la tecla '2' 
    }
    if((data_D_MSB == 1)&&(data_C == 1)&&(data_B == 0)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[2][2]; //en este caso corresponde a la tecla '9' 
    }
    if((data_D_MSB == 1)&&(data_C == 1)&&(data_B == 0)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[3][2]; //en este caso corresponde a la tecla 'C' 
    }
    if((data_D_MSB == 1)&&(data_C == 1)&&(data_B == 1)&&(data_A_LSB == 0))
    {
        i=Keypad_1_Key[2][0]; //en este caso corresponde a la tecla '3' 
    }
    if((data_D_MSB == 1)&&(data_C == 1)&&(data_B == 1)&&(data_A_LSB == 1))
    {
        i=Keypad_1_Key[3][0]; //en este caso corresponde a la tecla 'A' 
    }
    
    
}

CY_ISR(Temporizador)
{
    numeroint--;
    
}

CY_ISR(LeerTeclaInt)    //Creo el metodo de interrupcion que llamará a la función LeerTecla()definida anteriormente (arriba)
{
    LeerTecla();
    
    if((i != 'A')&&(i != 'B')&&(i != 'C')&&(i != 'D')&&(i != '*')&&(i != '#'))
    {
        if(cuenta<=3)
        {
            numero[cuenta] = i;
            cuenta++;
        }else
        {
            cuenta = 0;
        }
    }
    
    if(i == 'B') // Uso la tecla 'B' para borrar
    {
        numero[0] = ' ';
        numero[1] = ' ';
        numero[2] = ' ';
        numero[3] = ' ';
        cuenta = 0;
    }
    
    if(i == 'A')
    {
        numeroint = atoi(numero);
        
        Timer_Start();
        LCD_ClearDisplay();
        
    }
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    timer_clock_Start();
    LCD_Start();
    
    Pulisr_StartEx(LeerTeclaInt); //Inicializo la interrupcion externa para leer una tecla
    isrtiempo_StartEx(Temporizador);
    
    
    for(;;)
    {
        /* Place your application code here. */
        if(i != 'A')
        {
            LCD_Position(0,0);
            LCD_PrintString("Ingrese Numero");
            LCD_Position(1,0);
            LCD_PrintString(numero);
        }
        if(i == 'A')
        {
            LCD_Position(0,0);
            LCD_PrintString("  Temporizador ");
            LCD_Position(1,5);
            LCD_PrintNumber(numeroint);
        }
    }
}

/* [] END OF FILE */
