//*****************************************************************************
// Universidad del Valle de Guatemala
// BE3015 - Electrónica Digital 2
// Alessandro Paiz - 19572
// Laboratorio #4 - LCD
//*****************************************************************************

//*****************************************************************************
// Librerías
//*****************************************************************************
#include <Arduino.h>
#include <LiquidCrystal.h>

//*****************************************************************************
// Definición de pines
//*****************************************************************************

#define d4 26            // Definir pines del display
#define d5 25            
#define d6 33
#define d7 32
#define en 12
#define rs 13

#define b1 4             // Definir botones
#define b2 0

#define pot1 36          // Definir potenciometros
#define pot2 39

//*****************************************************************************
// Variables Globales
//*****************************************************************************
// Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);
uint8_t decenas1, unidades1, decimal1;     // Unidad, decimal 1 y decimal 2
uint8_t decenas2, unidades2, decimal2;
uint8_t centenas, decenas, unidades;
//*****************************************************************************
// Interrupciones
//*****************************************************************************
//*****************************************************************************
// Configuración
//*****************************************************************************
