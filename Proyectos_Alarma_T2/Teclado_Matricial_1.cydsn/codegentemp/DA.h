/*******************************************************************************
* File Name: DA.h  
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

#if !defined(CY_PINS_DA_H) /* Pins DA_H */
#define CY_PINS_DA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DA__PORT == 15 && ((DA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DA_Write(uint8 value);
void    DA_SetDriveMode(uint8 mode);
uint8   DA_ReadDataReg(void);
uint8   DA_Read(void);
void    DA_SetInterruptMode(uint16 position, uint16 mode);
uint8   DA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DA_SetDriveMode() function.
     *  @{
     */
        #define DA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DA_DM_RES_UP          PIN_DM_RES_UP
        #define DA_DM_RES_DWN         PIN_DM_RES_DWN
        #define DA_DM_OD_LO           PIN_DM_OD_LO
        #define DA_DM_OD_HI           PIN_DM_OD_HI
        #define DA_DM_STRONG          PIN_DM_STRONG
        #define DA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DA_MASK               DA__MASK
#define DA_SHIFT              DA__SHIFT
#define DA_WIDTH              1u

/* Interrupt constants */
#if defined(DA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DA_SetInterruptMode() function.
     *  @{
     */
        #define DA_INTR_NONE      (uint16)(0x0000u)
        #define DA_INTR_RISING    (uint16)(0x0001u)
        #define DA_INTR_FALLING   (uint16)(0x0002u)
        #define DA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DA_INTR_MASK      (0x01u) 
#endif /* (DA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DA_PS                     (* (reg8 *) DA__PS)
/* Data Register */
#define DA_DR                     (* (reg8 *) DA__DR)
/* Port Number */
#define DA_PRT_NUM                (* (reg8 *) DA__PRT) 
/* Connect to Analog Globals */                                                  
#define DA_AG                     (* (reg8 *) DA__AG)                       
/* Analog MUX bux enable */
#define DA_AMUX                   (* (reg8 *) DA__AMUX) 
/* Bidirectional Enable */                                                        
#define DA_BIE                    (* (reg8 *) DA__BIE)
/* Bit-mask for Aliased Register Access */
#define DA_BIT_MASK               (* (reg8 *) DA__BIT_MASK)
/* Bypass Enable */
#define DA_BYP                    (* (reg8 *) DA__BYP)
/* Port wide control signals */                                                   
#define DA_CTL                    (* (reg8 *) DA__CTL)
/* Drive Modes */
#define DA_DM0                    (* (reg8 *) DA__DM0) 
#define DA_DM1                    (* (reg8 *) DA__DM1)
#define DA_DM2                    (* (reg8 *) DA__DM2) 
/* Input Buffer Disable Override */
#define DA_INP_DIS                (* (reg8 *) DA__INP_DIS)
/* LCD Common or Segment Drive */
#define DA_LCD_COM_SEG            (* (reg8 *) DA__LCD_COM_SEG)
/* Enable Segment LCD */
#define DA_LCD_EN                 (* (reg8 *) DA__LCD_EN)
/* Slew Rate Control */
#define DA_SLW                    (* (reg8 *) DA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DA_PRTDSI__CAPS_SEL       (* (reg8 *) DA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DA_PRTDSI__OE_SEL0        (* (reg8 *) DA__PRTDSI__OE_SEL0) 
#define DA_PRTDSI__OE_SEL1        (* (reg8 *) DA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DA_PRTDSI__OUT_SEL0       (* (reg8 *) DA__PRTDSI__OUT_SEL0) 
#define DA_PRTDSI__OUT_SEL1       (* (reg8 *) DA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DA_PRTDSI__SYNC_OUT       (* (reg8 *) DA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DA__SIO_CFG)
    #define DA_SIO_HYST_EN        (* (reg8 *) DA__SIO_HYST_EN)
    #define DA_SIO_REG_HIFREQ     (* (reg8 *) DA__SIO_REG_HIFREQ)
    #define DA_SIO_CFG            (* (reg8 *) DA__SIO_CFG)
    #define DA_SIO_DIFF           (* (reg8 *) DA__SIO_DIFF)
#endif /* (DA__SIO_CFG) */

/* Interrupt Registers */
#if defined(DA__INTSTAT)
    #define DA_INTSTAT            (* (reg8 *) DA__INTSTAT)
    #define DA_SNAP               (* (reg8 *) DA__SNAP)
    
	#define DA_0_INTTYPE_REG 		(* (reg8 *) DA__0__INTTYPE)
#endif /* (DA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DA_H */


/* [] END OF FILE */
