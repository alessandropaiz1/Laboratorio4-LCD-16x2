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

int contador = 0;             // Crear variable para el contador 
int adcRaw;
float voltaje;                // Variable para voltaje potenciometro 1
float voltaje2;               // Variable para voltaje potenciometro 2
byte estadob1 = 0;
byte estadob2 = 0;

//*****************************************************************************
// Interrupciones
//*****************************************************************************
void IRAM_ATTR ISRbsuma(){     // Interrupción para bot on de incrementar contador
  if (contador > 255){
    contador = 0;
  }
}

void IRAM_ATTR ISRbresta(){     // Interrupción para boton de decrementar contador
  if (contador < 0){
    contador = 0 ;
  }
}

//*****************************************************************************
// Configuración
//*****************************************************************************
void setup() {
  Serial.begin(115200);                    // Configuración serial 
 
  LCD.begin(16, 2);                        // Configurar LCD 16*2

  pinMode(b1, INPUT_PULLUP);                
  pinMode(b2, INPUT_PULLUP);

  attachInterrupt(b1, ISRbsuma, HIGH);      // Configurar interrupción del botón incrementar 
  attachInterrupt(b2, ISRbresta, HIGH);     // Configurar interrupción botón decrementar 
}
}
