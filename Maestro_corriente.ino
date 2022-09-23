#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int ADC_lectura = 0;
float corriente = 0;
float resistor = 5.3;
float Am;

const int channelPinA = 5;
int PPR = 20;
volatile int ISRCounter = 0;
unsigned int pulsos = 0;
unsigned long Time = 0; 
unsigned int RPM = 0;
void setup() 
{ 
  SerialBT.begin("BluetoothESP32");
  pinMode(channelPinA, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(channelPinA), doEncode, CHANGE);
  Time = millis();
} 
 
void loop() 
{ 
  ADC_lectura = analogRead(36);//leemos el valor del adc
  corriente = (ADC_lectura*5/4095);
  Am = corriente/resistor;
  Serial.write(ADC_lectura); 
  //Serial.print(ADC_lectura);
  delay(1000);  
  
  if(millis() - Time >=1000)
  { pulsos = ISRCounter;
    RPM = 60 * pulsos/PPR;
    SerialBT.print(RPM); 
    //se reestablecen los valores
    ISRCounter = 0;
    pulsos = 0;
    Time = millis();
  }           
} 

void doEncode(){ISRCounter++;}
