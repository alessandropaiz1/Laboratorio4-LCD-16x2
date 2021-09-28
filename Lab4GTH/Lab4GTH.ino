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
void loop() {
  if (digitalRead(b1) == LOW){
    estadob1 = 1;
  }

  if (digitalRead(b2) == LOW){
    estadob2 = 1;
  }
  if (digitalRead(b1) == HIGH && estadob1 == 1){
    estadob1 = 0;
    contador++;
  }

  if (digitalRead(b2) == HIGH && estadob2 == 1){
    estadob2 = 0;
    contador--;
  }
  voltaje = analogReadMilliVolts(pot1) / 10.0;        // Separar valores del voltaje P1
  int temp = voltaje;
  decenas1 = temp / 100.0;
  temp = temp - decenas1 *100.0;
  unidades1 = temp / 10.0;
  temp = temp - unidades1 *10.0;
  decimal1 = temp;

  voltaje2 = analogReadMilliVolts(pot2) / 10.0;       // Separar valores del voltaje P2
  int temp2 = voltaje2;
  decenas2 = temp2 / 100.0;
  temp2 = temp2 - decenas2 *100.0;
  unidades2 = temp2 / 10.0;
  temp2 = temp2 - unidades2 *10.0;
  decimal2 = temp2;

  int cnt = contador;                                 // Separar valores del contador 
  centenas = contador / 100.0;
  cnt = cnt - centenas * 100.0;
  decenas = cnt / 10.0;
  cnt = cnt - decenas * 10.0;
  unidades = cnt;

  Serial.print(voltaje);                              // Imprimir valores Pot1
  Serial.print("\t");
  Serial.print(decenas1);
  Serial.print("\t");
  Serial.print(unidades1);
  Serial.print("\t");
  Serial.println(decimal1);

  Serial.print("\t");

  Serial.print(voltaje2);                              // Imprimir valores Pot2
  Serial.print("\t");
  Serial.print(decenas2);
  Serial.print("\t");
  Serial.print(unidades2);
  Serial.print("\t");
  Serial.println(decimal2);

  Serial.print("\t");
  
  Serial.print(contador);                              // Imprimir valor del contador 
  LCD.clear();
  LCD.print("Pot1:");
}
