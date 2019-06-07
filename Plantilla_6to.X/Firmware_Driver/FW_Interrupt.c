/****************************************************************************************************
 *
 * \file		FW_Interrupt.c
 * \brief		Contiene la funciOn de interrupcion
 * \date		23 de abril de 2019
 * \author		Nicolas Ferragamo nferragamo@est.frba.utn.edu.ar
 * \version     1.0.0
****************************************************************************************************/

/****************************************************************************************************
 *** INCLUDES
****************************************************************************************************/
#include <xc.h>
#include "Tdatos.h"

/****************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
****************************************************************************************************/

/****************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
****************************************************************************************************/

/****************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODUL
****************************************************************************************************/

/****************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
****************************************************************************************************/

/****************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 *   se escriben en CamelCase y estan precedidas por la identificación del 
 *   módulo segida de un _ 
 *   ej: MEM_POOL  Mem_PoolHeap; 
****************************************************************************************************/

/****************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 *   se declaran con static y se escriben en CamelCase y estan precedidas por la 
 *   identificación del módulo segida de un _ y usan _ para separar las palabras
 *   cuando tienen nombres compuestos
 *   ej: static MEM_POOL  Mem_Pool_Heap; 
****************************************************************************************************/

/****************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 * se declaran como staticas y se escriben en CamelCase, estan precedidas por la
 * identificación del módulo seguida de un _. No se decaran en el .h
 * ej static void Clk_DateTimer(paraetros)
****************************************************************************************************/

/****************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
****************************************************************************************************/

/****************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
****************************************************************************************************/
/**
	\fn         __interrupt() myISR
	\brief      Funcion de interrupcion
 	\author     Nicolas Ferragamo
 	\date       23 de abril de 2019
 	\param      [in] void
 	\param      [out] void
	\return     void
*/

void __interrupt() myISR(void)
{
    /*Aquí se ejecuta el código de las interrupciones que hayan sucedido,
     *por defecto el XC8 entra siempre en esta interrupción denominada de
     *Alta prioridad
     */
    
    if(TMR0IF)
    {         //la interrupcion ocurre cada 1 segundo.
        TMR0IF=0;       //se reinicia el timer y su interrupcion.
        //Su codigo por favor!!   
    }
}