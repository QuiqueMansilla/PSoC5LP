/*******************************************************************************
* File Name: Pulisr.h
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
#if !defined(CY_ISR_Pulisr_H)
#define CY_ISR_Pulisr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Pulisr_Start(void);
void Pulisr_StartEx(cyisraddress address);
void Pulisr_Stop(void);

CY_ISR_PROTO(Pulisr_Interrupt);

void Pulisr_SetVector(cyisraddress address);
cyisraddress Pulisr_GetVector(void);

void Pulisr_SetPriority(uint8 priority);
uint8 Pulisr_GetPriority(void);

void Pulisr_Enable(void);
uint8 Pulisr_GetState(void);
void Pulisr_Disable(void);

void Pulisr_SetPending(void);
void Pulisr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Pulisr ISR. */
#define Pulisr_INTC_VECTOR            ((reg32 *) Pulisr__INTC_VECT)

/* Address of the Pulisr ISR priority. */
#define Pulisr_INTC_PRIOR             ((reg8 *) Pulisr__INTC_PRIOR_REG)

/* Priority of the Pulisr interrupt. */
#define Pulisr_INTC_PRIOR_NUMBER      Pulisr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Pulisr interrupt. */
#define Pulisr_INTC_SET_EN            ((reg32 *) Pulisr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Pulisr interrupt. */
#define Pulisr_INTC_CLR_EN            ((reg32 *) Pulisr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Pulisr interrupt state to pending. */
#define Pulisr_INTC_SET_PD            ((reg32 *) Pulisr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Pulisr interrupt. */
#define Pulisr_INTC_CLR_PD            ((reg32 *) Pulisr__INTC_CLR_PD_REG)


#endif /* CY_ISR_Pulisr_H */


/* [] END OF FILE */
