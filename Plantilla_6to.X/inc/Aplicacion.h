/**********************************************************************************************************
*                                               Aplicacion
*                               Codigo de la aplicacion a desarrollar
*
*						<Copyright>
*
*						<Copyright or distribution terms>
*
*
*********************************************************************************************************/

/*********************************************************************************************************
*                                               <File description>
*
* Filename	: Aplicacion.h
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
 * \file		Aplicacion.h
 * \brief		Escriba la función de su aplicación de forma breve
 * \details     Escriba la función de su aplicación de forma extensa
 * \date		13 de junio del 2019
 * \author		Nicolas Ferragamo nferragamo@est.frba.utn.edu.ar
 * \version     1.0.0
*********************************************************************************************************/

/*********************************************************************************************************
 *** MODULO
*********************************************************************************************************/

#ifndef APLICACION_H
#define APLICACION_H

/*********************************************************************************************************
 *** INCLUDES GLOBALES
*********************************************************************************************************/

#include <xc.h>
#include "Confbits.h"
#include "Tdatos.h"
#include "BaseBoard.h"
#include "FW_InitKit.h"
#include "FW_InitTimer.h" 
#include "PR_LCD.h"
#include "FW_LCD.h"
#include "FW_Teclado.h"
#include "PR_Teclado.h"

/*********************************************************************************************************
 *** DEFINES GLOBALES
 *   Se escriben en mayusculas y estar precedidas por la identificación del
 *   módulo segidas de un '_' . Si el nombre esta compuesto por mas de una
 *   palabra, las mismas deben separarce con un '_'.
 *   ej: #define  DEF_OCTETE_NMR_BITS.
*********************************************************************************************************/

/*********************************************************************************************************
 *** MACROS GLOBALES
 *   Se escriben en mayusculas y estar precedidas por la identificación del
 *   módulo segidas de un '_' . Si el nombre esta compuesto por mas de una
 *   palabra, las mismas deben separarce con un '_'.
 *   ej: #define  MAYOR(A,B)     (A > B) ? A : B;
*********************************************************************************************************/

/*********************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 *   se escriben en MAYUSCULA 
 *   ej: typedef  unsigned char  CPU_CHAR;  8 bits caracter
*********************************************************************************************************/

/*********************************************************************************************************
 *** VARIABLES GLOBALES
 *   se escriben en CamelCase y estan precedidas por la identificación del 
 *   módulo segida de un _ 
 *   ej:  extern MEM_POOL  MemPoolHeap; 
*********************************************************************************************************/

/*********************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 *  se escriben en CamelCase, estan precedidas por la identificación del módulo 
 *  seguida de un _. No se decaran en el .h
 *  ej  void Clk_DateTimer(paraetros)
**********************************************************************************************************/

/**
	\brief 		Funcion principal
 	\author 	Nicolas Ferragamo nferragamo@est.frba.utn.edu.ar
 	\date 		13 de junio del 2019
*/

void Aplicacion (void);

#endif /* APLICACION_H */