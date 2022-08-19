const int sensorPin1 = 36;
const int sensorPin2 = 39;
const int sensorPin3 = 34;
int pot=0;
int ult=0;
int hig=0;
String cad1;
String cad2;
String cad3;
String resultado;
String term= ":";
void setup()
{
   Serial.begin(9600);
   pinMode(13,OUTPUT);
}

void loop() 
{
  char sel=Serial.read();
  int cona=1;
 
    if (sel=='a'){
      do{
    pot=analogRead(sensorPin1);
    cona++;
    digitalWrite(13,HIGH);
    Serial.println(pot);
      delay(10); 
      }while(cona !=1000);
    }
      if (sel=='b'){
      do{
    ult=analogRead(sensorPin2);
    cona++;
    digitalWrite(13,LOW);
    Serial.println(ult);
      delay(10); 
      }while(cona !=1000);
  }
  if (sel=='c'){
      do{
    hig=analogRead(sensorPin3);
    cona++;
    digitalWrite(13,HIGH);
    Serial.println(hig);
      delay(10); 
      }while(cona !=1000);
  }
  if (sel=='d'){
      do{
    digitalWrite(13,HIGH);
    pot=analogRead(sensorPin1);
    ult=analogRead(sensorPin2);
    hig=analogRead(sensorPin3);
    cad1=(String)pot;
    cad2=(String)ult;
    cad3=(String)hig;
    cona++;
    resultado= cad1+term+cad2+term+cad3;
    Serial.println(resultado);
     delay(10); 
   
      }while(cona !=1000);
  }
  delay(1000);
 }
