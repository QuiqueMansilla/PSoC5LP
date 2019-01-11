/*******************************************************************************
* File Name: Data_A_LSB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Data_A_LSB_H) /* Pins Data_A_LSB_H */
#define CY_PINS_Data_A_LSB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Data_A_LSB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Data_A_LSB__PORT == 15 && ((Data_A_LSB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Data_A_LSB_Write(uint8 value);
void    Data_A_LSB_SetDriveMode(uint8 mode);
uint8   Data_A_LSB_ReadDataReg(void);
uint8   Data_A_LSB_Read(void);
void    Data_A_LSB_SetInterruptMode(uint16 position, uint16 mode);
uint8   Data_A_LSB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Data_A_LSB_SetDriveMode() function.
     *  @{
     */
        #define Data_A_LSB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Data_A_LSB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Data_A_LSB_DM_RES_UP          PIN_DM_RES_UP
        #define Data_A_LSB_DM_RES_DWN         PIN_DM_RES_DWN
        #define Data_A_LSB_DM_OD_LO           PIN_DM_OD_LO
        #define Data_A_LSB_DM_OD_HI           PIN_DM_OD_HI
        #define Data_A_LSB_DM_STRONG          PIN_DM_STRONG
        #define Data_A_LSB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Data_A_LSB_MASK               Data_A_LSB__MASK
#define Data_A_LSB_SHIFT              Data_A_LSB__SHIFT
#define Data_A_LSB_WIDTH              1u

/* Interrupt constants */
#if defined(Data_A_LSB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Data_A_LSB_SetInterruptMode() function.
     *  @{
     */
        #define Data_A_LSB_INTR_NONE      (uint16)(0x0000u)
        #define Data_A_LSB_INTR_RISING    (uint16)(0x0001u)
        #define Data_A_LSB_INTR_FALLING   (uint16)(0x0002u)
        #define Data_A_LSB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Data_A_LSB_INTR_MASK      (0x01u) 
#endif /* (Data_A_LSB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Data_A_LSB_PS                     (* (reg8 *) Data_A_LSB__PS)
/* Data Register */
#define Data_A_LSB_DR                     (* (reg8 *) Data_A_LSB__DR)
/* Port Number */
#define Data_A_LSB_PRT_NUM                (* (reg8 *) Data_A_LSB__PRT) 
/* Connect to Analog Globals */                                                  
#define Data_A_LSB_AG                     (* (reg8 *) Data_A_LSB__AG)                       
/* Analog MUX bux enable */
#define Data_A_LSB_AMUX                   (* (reg8 *) Data_A_LSB__AMUX) 
/* Bidirectional Enable */                                                        
#define Data_A_LSB_BIE                    (* (reg8 *) Data_A_LSB__BIE)
/* Bit-mask for Aliased Register Access */
#define Data_A_LSB_BIT_MASK               (* (reg8 *) Data_A_LSB__BIT_MASK)
/* Bypass Enable */
#define Data_A_LSB_BYP                    (* (reg8 *) Data_A_LSB__BYP)
/* Port wide control signals */                                                   
#define Data_A_LSB_CTL                    (* (reg8 *) Data_A_LSB__CTL)
/* Drive Modes */
#define Data_A_LSB_DM0                    (* (reg8 *) Data_A_LSB__DM0) 
#define Data_A_LSB_DM1                    (* (reg8 *) Data_A_LSB__DM1)
#define Data_A_LSB_DM2                    (* (reg8 *) Data_A_LSB__DM2) 
/* Input Buffer Disable Override */
#define Data_A_LSB_INP_DIS                (* (reg8 *) Data_A_LSB__INP_DIS)
/* LCD Common or Segment Drive */
#define Data_A_LSB_LCD_COM_SEG            (* (reg8 *) Data_A_LSB__LCD_COM_SEG)
/* Enable Segment LCD */
#define Data_A_LSB_LCD_EN                 (* (reg8 *) Data_A_LSB__LCD_EN)
/* Slew Rate Control */
#define Data_A_LSB_SLW                    (* (reg8 *) Data_A_LSB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Data_A_LSB_PRTDSI__CAPS_SEL       (* (reg8 *) Data_A_LSB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Data_A_LSB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Data_A_LSB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Data_A_LSB_PRTDSI__OE_SEL0        (* (reg8 *) Data_A_LSB__PRTDSI__OE_SEL0) 
#define Data_A_LSB_PRTDSI__OE_SEL1        (* (reg8 *) Data_A_LSB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Data_A_LSB_PRTDSI__OUT_SEL0       (* (reg8 *) Data_A_LSB__PRTDSI__OUT_SEL0) 
#define Data_A_LSB_PRTDSI__OUT_SEL1       (* (reg8 *) Data_A_LSB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Data_A_LSB_PRTDSI__SYNC_OUT       (* (reg8 *) Data_A_LSB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Data_A_LSB__SIO_CFG)
    #define Data_A_LSB_SIO_HYST_EN        (* (reg8 *) Data_A_LSB__SIO_HYST_EN)
    #define Data_A_LSB_SIO_REG_HIFREQ     (* (reg8 *) Data_A_LSB__SIO_REG_HIFREQ)
    #define Data_A_LSB_SIO_CFG            (* (reg8 *) Data_A_LSB__SIO_CFG)
    #define Data_A_LSB_SIO_DIFF           (* (reg8 *) Data_A_LSB__SIO_DIFF)
#endif /* (Data_A_LSB__SIO_CFG) */

/* Interrupt Registers */
#if defined(Data_A_LSB__INTSTAT)
    #define Data_A_LSB_INTSTAT            (* (reg8 *) Data_A_LSB__INTSTAT)
    #define Data_A_LSB_SNAP               (* (reg8 *) Data_A_LSB__SNAP)
    
	#define Data_A_LSB_0_INTTYPE_REG 		(* (reg8 *) Data_A_LSB__0__INTTYPE)
#endif /* (Data_A_LSB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Data_A_LSB_H */


/* [] END OF FILE */
