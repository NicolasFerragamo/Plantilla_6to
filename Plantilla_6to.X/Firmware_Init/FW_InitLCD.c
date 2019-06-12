/*********************************************************************************************************
*                                               LCD
*                               Inicialización del LCD
*
*                                   <Copyright>
*
*                               <Copyright or distribution terms>
*
*
*********************************************************************************************************/

/*********************************************************************************************************
*                                               <File description>
*
* Filename	: FW_InitLCD
* Version	: 1.0.0					
* Programmer(s) : NEF
**********************************************************************************************************
*  Note(s): Esta librería solo puede utilizar las cuatro líneas menos significativas de 
*   un puerto en caso de querer utilizar otras líneas se debe de reprogramar.
*   Es necesarío este habilitada la interrupción de timer en la cual se debe de 
*   llamar a la función LCD_tic() la misma establece las demoras que de otra
*   manera habría que implementarlas como una función aparte. No olvide declarar 
*   la variable extern uint8_t LCD_Tout en el archivo FW__Interrupt.c
*
*
*
*********************************************************************************************************/

/*********************************************************************************************************
 *
 * \file		FW_InitLCD
 * \brief		Archivo con la función de inicalizacion del Display LCD
 * \date		11 de junio del 2019
 * \author		Nicolas Ferragamo nferragamo@est.frba.utn.edu.ar
 * \version     1.0.0
*********************************************************************************************************/

/*********************************************************************************************************
 *** INCLUDES
*********************************************************************************************************/

#include "LCD.h"

/*********************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
*********************************************************************************************************/

#define     ENTRADA     0xF0            //!< Esto es para invertir el bus de datos y poder
#define     SALIDA      0x0F            //!<leer cuando necesito ver si está busy..
#define     BUSY        PORTDbits.RD7	//!< Con estos defines me abstraigo del hardware
#define     BUS_DIR     TRISD

#define     TRUE        0x1
#define     FALSE       0x0

/*********************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
*********************************************************************************************************/
uint8_t LCD_Tout = 0;

/*********************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO

*********************************************************************************************************/
static void LCD_Read_Busy (void);		
static void LCD_Write_CMD (uint8_t comando);	
static void LCD_Write (uint8_t dato);
/*********************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
*********************************************************************************************************/
/**
 *	\fn         static void LCD_Read_Busy(void)
 *	\brief      Se encarga de leer el bit busy
 *  \details    La función se asegura que el LCD haya terminado la operación ctual
 *	\author     Esteban Lemos
 *	\date 
*/
static void LCD_Read_Busy (void)
{
    uint8_t aux;

	BUS_DIR | = ENTRADA;	// Pone el bus como entrada (hay que leer) D7 a D4
	RS        = FALSE;      // Pone las señales para indicar que va a leer
	RW        = TRUE;
	do{                     // Hace
		E     = TRUE;       // E=1
		aux   = BUSY;       // Lee bit de busy
		E     = FALSE;      // E=0
		E     = TRUE;       // E=1
		(void)BUSY;         // Lectura dummy para completar el byte
		E     = FALSE;      // E=0, completo byte
	}while (aux);           // Mientras busy = 1, cuando busy = 0 (LCD terminó), sale de este do-while
	RW        = FALSE;		// Normaliza las señales
	BUS_DIR & = SALIDA;     // Hace el bus salida para seguir escribiendo al LCD
}


/**
 *	\fn         static void LCD_Write_CMD(uint8_t comando)
 *	\brief      Se encarga de escribir un comando en el LCD
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  Recive el comando a enviar al LCD
*/
static void LCD_Write_CMD (uint8_t comando)
{
    RS = FALSE;
	RW = FALSE;
	LCD_Write (comando);	// Envía efectivamente el comando
}

/**
 *	\fn         static void LCD_Write(unsigned char dato)
 *	\brief      Se encarga de escribir un dato en bus de a un nibble por vez
 *  \details    Se encarga de escribir un dato en bus de a un nibble por vez
 *              para poder trabajar en 4 bits.
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  Recive el dato a enviar al LCD
*/
static void LCD_Write (uint8_t dato)
{
    DISPLAY & = 0x0F;
    E         = TRUE;
    DISPLAY | = (dato & 0xF0);		// Pone el nibble alto en el bus
    E         = FALSE;
    DISPLAY & = 0x0F;
    E         = TRUE;
    DISPLAY | = (dato << 4);		// Pone el nibble alto en el bus
    E         = FALSE;
}

/*********************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
*********************************************************************************************************/


/**
 *	\fn         void LCD_Init(void)
 *	\brief      Inicializa el LCD para el shield 2
 *  \details    Inicializa los puertos del entrenador necesarios para usar
 *              el display LCD e inicializa el LCD propiamente dicho.
 *	\author     Esteban Lemos
 *	\date 
*/
void LCD_Init(void)
{
    BUS_DIR     & = SALIDA;	// Hace el bus salida para escribir en el LCD
    RS_BUS_DIR    = 0;
    RW_BUS_DIR    = 0;
    E_BUS_DIR     = 0;
        

	LCD_Tout = 30;          // Espera 30 interrup de timer
	while (LCD_Tout);

	LCD_Write_CMD (0x02);        // trabajar en 4bits 0010****
	LCD_Tout = 1;		// Al menos 50uS 
	while (LCD_Tout);	// Espera acá hasta que LCD_tout se hace 0

	LCD_Write_CMD (0x28);	// 4 bits 2 lineas caracter 5*8
	LCD_Tout = 1;
	while (LCD_Tout);

	LCD_Write_CMD (0x0C);        //disp ON Cursor OFF Blink OFF
	LCD_Tout = 1;
	while (LCD_Tout);

	LCD_Write_CMD (0x01);        // borra el display
	LCD_Tout = 1;
	while (LCD_Tout);

	LCD_Write_CMD (0x06);        //Incrementar la pos auto SCROLL OFF
	LCD_Tout = 1;
	while (LCD_Tout);

	LCD_Read_Busy ();												// Esta rutina lee el bit de busy a ver si el LCD se liberó..
}