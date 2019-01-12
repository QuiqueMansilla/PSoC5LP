/* ========================================
 *
 * Autor Quique Mansilla
 * All Rights Reserved
 * Primer uso de un daiplay LCD de 2x16 Winstar A
 * 
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Char_Start();
    LCD_Char_ClearDisplay();
    
    

    for(;;)
    {
        /* Place your application code here. */
    LCD_Char_Position(0,0);
    LCD_Char_PrintString("La rubita Pamela");
    LCD_Char_Position(1,0);
    LCD_Char_PrintString(" que personaje  ");
    }
}

/* [] END OF FILE */
