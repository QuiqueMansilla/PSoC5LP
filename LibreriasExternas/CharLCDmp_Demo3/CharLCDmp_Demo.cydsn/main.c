/* ========================================
 *  CharLCDmp_Demo
 *  February 22, 2013
 *  Mark Hastings
 *
 * This simple demo demostrates the Character 
 * LCD Muli-Port (mp) component.
 *
 * ========================================
*/
#include <device.h>

void main()
{
	uint8 updown;        /* Bargraph up-down flag */
	int8 bargraph = 0;   /* Bargraph position     */
	
    LCD_Start();
	LCD_Position(0,0);
	LCD_PrintString("Multi-Port LCD");
	
    for(;;)
    {
        CyDelay(2);             /* Delay so it doesn't go too fast */

		if(updown != 0)         /* Bargaph goes up */
		{
		    bargraph++;
		    if (bargraph > 65)  /* Go back down once reached 65 */
			{
			   updown = 0;
			   bargraph--;
			}
		}
		else                    /* Bargraph goes Down */
		{
		    bargraph--;
		    if (bargraph <= 0)  /* Change back to up on 0 */
			{
			   updown = 1;
			   bargraph++;
			}
		}
		LCD_Position(1,0);
		LCD_PrintInt8(bargraph);                  /* Show numerical position */
	    LCD_DrawHorizontalBG(1, 3, 13, bargraph); /* Draw bargraph */
    }
}

/* [] END OF FILE */
