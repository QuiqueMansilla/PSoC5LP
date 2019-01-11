/*******************************************************************************
* File Name: isrtiempo.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isrtiempo_H)
#define CY_ISR_isrtiempo_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrtiempo_Start(void);
void isrtiempo_StartEx(cyisraddress address);
void isrtiempo_Stop(void);

CY_ISR_PROTO(isrtiempo_Interrupt);

void isrtiempo_SetVector(cyisraddress address);
cyisraddress isrtiempo_GetVector(void);

void isrtiempo_SetPriority(uint8 priority);
uint8 isrtiempo_GetPriority(void);

void isrtiempo_Enable(void);
uint8 isrtiempo_GetState(void);
void isrtiempo_Disable(void);

void isrtiempo_SetPending(void);
void isrtiempo_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrtiempo ISR. */
#define isrtiempo_INTC_VECTOR            ((reg32 *) isrtiempo__INTC_VECT)

/* Address of the isrtiempo ISR priority. */
#define isrtiempo_INTC_PRIOR             ((reg8 *) isrtiempo__INTC_PRIOR_REG)

/* Priority of the isrtiempo interrupt. */
#define isrtiempo_INTC_PRIOR_NUMBER      isrtiempo__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrtiempo interrupt. */
#define isrtiempo_INTC_SET_EN            ((reg32 *) isrtiempo__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrtiempo interrupt. */
#define isrtiempo_INTC_CLR_EN            ((reg32 *) isrtiempo__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrtiempo interrupt state to pending. */
#define isrtiempo_INTC_SET_PD            ((reg32 *) isrtiempo__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrtiempo interrupt. */
#define isrtiempo_INTC_CLR_PD            ((reg32 *) isrtiempo__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrtiempo_H */


/* [] END OF FILE */
