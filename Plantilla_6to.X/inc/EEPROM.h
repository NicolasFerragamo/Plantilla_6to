/**********************************************************************************************************
*                                               EEPROM
                    *						M�dulo para trabajar con memoria EEPROM
*
*						<Copyright>
*
*						<Copyright or distribution terms>
*
*
*********************************************************************************************************/

/*********************************************************************************************************
*                                               EEPROM.h
*
* Filename	: EEPROM.h
* Version	: 1.0.0					
* Programmer(s) : NEF
**********************************************************************************************************
*  Note(s):
*
*
*
*********************************************************************************************************/

/*********************************************************************************************************
 *
 * \file		EEPROM.h
 * \brief		M�dulo para trabajar con memoria EEPROM
 * \date		1 de octubre de 2019
 * \author		Nicolas Ferragamo nferragamo@est.frba.utn.edu.ar
 * \version     1.0.0
*********************************************************************************************************/

/*********************************************************************************************************
 *** MODULO
*********************************************************************************************************/

#ifndef __EEPROM_H
#define __EEPROM_H

/*********************************************************************************************************
 *** INCLUDES GLOBALES
*********************************************************************************************************/
#include "Tdatos.h"
#include "BaseBoard.h"
/*********************************************************************************************************
 *** DEFINES GLOBALES
*********************************************************************************************************/

/*********************************************************************************************************
 *** MACROS GLOBALES
*********************************************************************************************************/

/*********************************************************************************************************
 *** TIPO DE DATOS GLOBALES
*********************************************************************************************************/

/*********************************************************************************************************
 *** VARIABLES GLOBALES 
*********************************************************************************************************/

/*********************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
**********************************************************************************************************/


/**
	\fn  		void EEPROM_Write(uint8_t addr,uint8_t n);
	\brief 		Se encarga de escribir un dato en la memoria EEPROM
 	\author 	
 	\date 		
 	\param [in]     addr
    \param [in]     n
 	\param [out] 	void
*/
void EEPROM_Write (uint8_t addr,uint8_t n);


/**
	\fn  		void EEPROM_Read(uint8_t addr,uint8_t n);
	\brief 		Se encarga de escribir un dato en la memoria EEPROM
 	\author 	
 	\date 		
 	\param [in]     addr
 	\param [out] 	EEDATA
*/
uint8_t EEPROM_Read (uint8_t addr);


#endif /* __EEPROM_H */