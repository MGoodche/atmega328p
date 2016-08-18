#include <SoftwareSerial.h>
#include <Timer.h>
// Relacion Pines arduino - terminales led
int rojo = 9;
int verde = 8;
int azul = 7;
int rec;
int wait = 1000;
int count = 0;

SoftwareSerial BT(10,11);
Timer t; 
//Configuramos Pines como salidas, establecemos el baudRate a 9600
void setup()
{
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
   Serial.begin(9600);
   BT.begin(9600);
   digitalWrite(9,LOW);
   digitalWrite(8,LOW);
   digitalWrite(7,LOW);   
}

/*
  Ciclo Principal
  mientras serial este conectado espera y lee datos de entrada, los analiza y envia distintos parametros al metodo
  setColor que manda a cada pin correspondiente a cada color su respectivo valor.
*/
void loop()
{
   t.update();
   rec = BT.read();
       switch(rec)
       {
         case '0':
         {
           setColor(255, 0, 0);
           Serial.println("Passion Mood");
           break;
         }
         case '1':
         {
           setColor(0,0,0); 
           Serial.println("Negative Mood");
           break;
         }
         case '2':
         {
          {
            t.every(500, enviarnavidad); //Para conseguir el efecto de luces de navidad se crea una función que mande los valores cada medio segundo
      
          }
          break;
         }

     case '3':
         {
           setColor(255, 255, 0);
           Serial.println("Energy Mood");
           break;
         }
         case '4':
         {
           setColor(0,255, 255); 
           Serial.println("Tranquility Mood");
           break;
         }
         case '5':
         {
           setColor(255,0,255); 
           Serial.println("Happy Mood");
           break;
         }
     case '6':
         {
           setColor(255,155,200); 
           Serial.println("Positive Mood");
           break;
         }
     case '7':
         {
           setColor(0,0,170); 
           Serial.println("Dramatic Mood");
           break;
         }
              case '8':
         {
            digitalWrite(9,LOW);
   digitalWrite(8,LOW);
   digitalWrite(7,LOW);
           break;
         }
       }       
 
}

void setColor(int red, int green, int blue)
{
  analogWrite(rojo, red);
  analogWrite(verde, green);
  analogWrite(azul, blue);  
}

void enviarnavidad()
{
           setColor(0,0,255); 
           Serial.println("Christmas Mood");
           delay(wait);
           setColor(0,255,0); 
           delay(wait);
           setColor(255,0,0);
           delay(wait);
             setColor(255, 255, 0);
           delay(wait);
            setColor(255,0,255); 
           delay(wait);
           setColor(0,255, 255); 
           delay(wait);
  
}
