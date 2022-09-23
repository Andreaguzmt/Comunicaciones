#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)
int ADC;
float I;
float R = 5.3;
float A;
float C=0;
void setup() 
{ 
  Serial.begin(9600); 
  lcd.init();;//inicializar la pantalla lcd
  lcd.backlight();//Encender la luz de fondo
  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print("  Laboratorio 2 ");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);//poner el cursor en las coordenadas (x,y)
  lcd.print("RS-485 Mast-Eslv");//muestra en la pantalla max 20 caracteres
  delay (5000);
} 
 
void loop() 
{ 
  if (Serial.available()) {
    ADC = Serial.read();//Leemos el dato recibido 
    I = (ADC*5/255);
    A = (I/R);
    if (A >0.56)
    {C = A;}
    
  }
  lcd.clear();
  lcd.print("Corriente = ");
  lcd.setCursor(0,1);
  lcd.println(C);  
  Serial.print(C);                                        
  lcd.setCursor(4,1);  
  lcd.print("A.");
  delay(1000);//Esperamos 1 segundo antes de repetir el loop
} 
