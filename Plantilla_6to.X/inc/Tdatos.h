/**********************************************************************************************************
*                                              TDatos
*						Incluye los tipos de datos estandares para
 *                      microcontroladores
*
*						<Copyright>
*
*						<Copyright or distribution terms>
*
*
*********************************************************************************************************/

/*********************************************************************************************************
*                                               Tipos de datos
*
* Filename	: Tdatos
* Version	: TDatos					
* Programmer(s) : NEF
**********************************************************************************************************
*  Note(s):
*
*
*
*********************************************************************************************************/

/*********************************************************************************************************
 *
 * \file		Tdatos
 * \brief		Continene los tipos de datos estandares para los ucontroladores
 * \date		6 de junio de 2019
 * \author		Nicolas Ferragamo nferragamo@est.frba.utn.edu.ar
 * \version     1.0.0
*********************************************************************************************************/

/*********************************************************************************************************
 *** MODULO
*********************************************************************************************************/

#ifndef Tdato_H
#define	Tdato_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

/*********************************************************************************************************
 *** INCLUDES GLOBALES
*********************************************************************************************************/

/*********************************************************************************************************
 *** DEFINES GLOBALES
 *   Se escriben en mayusculas y estan precedidas por la identificación del
 *   módulo segidas de un '_' . Si el nombre esta compuesto por mas de una
 *   palabra, las mismas deben separarce con un '_'.
 *   ej: #define  DEF_OCTETE_NMR_BITS.
*********************************************************************************************************/
#define		__R		volatile const
#define 	__w		volatile
#define 	__RW	volatile

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
typedef		unsigned long int		uint32_t; //!< Tipo de dato entero sin signo de 32 bits
typedef		unsigned short int 	    uint16_t; //!< Tipo de dato entero sin signo de 16 bits
/*typedef		unsigned long short int uint24_t; //!< Tipo de dato entero sin signo de 24 bits */
typedef		unsigned char			uint8_t;  //!< Tipo de dato entero sin signo de 8 bits
typedef		long int				int32_t;  //!< Tipo de dato entero con signo de 32 bits
/*typedef     long short int          int24_t;  //!< Tipo de dato entero con signo de 24 bits */
typedef		short int				int16_t;  //!< Tipo de dato entero con signo de 16 bits
typedef		char					int8_t;   //!< Tipo de dato entero con signo de 8 bits
typedef		float					float_t;  //!< Tipo de dato flotante de 32 bits
typedef		double					double_t; //!< Tipo de dato flotante de 64 bits

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

#endif /* Tdato_H */