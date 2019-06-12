/*********************************************************************************************************
*                                               LCD
*                               Manejo del display LCD
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
* Filename	: PR_LCD
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
 * \file		PR_LCD
 * \brief		Archivo con la función para el manejo del Display LCD
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
extern uint8_t LCD_Tout;

/*********************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO

*********************************************************************************************************/
static void LCD_Read_Busy (void);		
static void LCD_Write_CMD (uint8_t comando);	
static void LCD_Write (uint8_t dato);
static void LCD_Write_Data (uint8_t dato);	// Pone señales para escribir dato

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

/**
 *	\fn         static void LCD_Write_Data (uint8_t dato)
 *	\brief      Configura las señales necesarias para escribir el dato
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  Recive el dato a enviar al LCD
*/
static void LCD_Write_Data (uint8_t dato)
{
    RS = TRUE;
	RW = FALSE;
	LCD_Write(dato);	// Envía efectivamente el dato
}

/*********************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
*********************************************************************************************************/

/**
 *	\fn         void LCD_Char2LCD(uint8_t caracter)
 *	\brief      Envia un carater al LCD
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  caracter 
*/
void LCD_Char2LCD (uint8_t caracter)
{
    LCD_Write_Data (caracter);
	LCD_Read_Busy();
}


/**
 *	\fn         void LCD_Msg2LCD(const uint8_t* msg)
 *	\brief      Envia un string al LCD
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  msg
*/
void LCD_Msg2LCD (const uint8_t* msg)
{
    while (*msg != 0)
    {
		LCD_Write_Data(*msg);
		LCD_Read_Busy();
		msg++;
	}
}
   
/**
 *	\fn         void LCD_Clear(void)
 *	\brief      Borra el LCD
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  mensaje a enviar al LCD
*/
void LCD_Clear (void)
{
    LCD_Write_CMD (0x01);
	LCD_Read_Busy();
}
   
/**
 *	\fn         void LCD_RetHome(void)
 *	\brief      Regresa el curor al inicio
 *	\author     Esteban Lemos
 *	\date 
*/
void LCD_RetHome (void)
{
    LCD_Write_CMD (0x02);
	LCD_Read_Busy();
}
   
/**
 *	\fn         void LCD_SetCursor(uint8_t)
 *	\brief      Ubica el cursor en una posición determinada
 *	\author     Esteban Lemos
 *	\date 
 *  \param      [in]  posición del cursor
*/
void LCD_SetCursor (uint8_t pos)
{
    pos |= 0x80;
    LCD_Write_CMD (pos);
	LCD_Read_Busy();
}

   
/**
 *	\fn         void LCD_TicLCD(void)
 *	\brief      Rutina necesaria para el fncionamiento del módulo
 *  \details    Esta rutina se debe llama desde la interrupción de timer cada 1mS
 *	\author     Esteban Lemos
 *	\date 
*/
void LCD_TicLCD (void)
{
     if (LCD_Tout) LCD_Tout--;
}

   
/**
 *	\fn         void LCD_Desp2Izq(void)
 *	\brief      Desplaza al LCD a la izq
 *	\author     Esteban Lemos
 *	\date 
*/
void LCD_Desp2Izq (void)
{
    LCD_Write_CMD (24);
	LCD_Read_Busy();
}