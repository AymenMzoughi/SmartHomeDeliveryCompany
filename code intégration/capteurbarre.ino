#include<Servo.h>
Servo myservo;
const int trigPin=3;
const int echoPin=5; 
long tmeduration;
int distance;
bool test1=false;
const int bouton = 4;   // la broche 4 devient bouton
    // la broche 12 devient led
int etatbouton;


void setup() {

  myservo.attach(9);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(bouton, INPUT); // Initialise le bouton comme entrée
   // Initialise la led comme sortie
    etatbouton = LOW; 
  Serial.begin(9600);
  
  

}

void loop() {


   etatbouton = digitalRead(bouton); // On mémorise l'état du bouton
    if(etatbouton == LOW) // teste si le bouton a un niveau logique BAS
    {
          Serial.print("low");
    }
    else // teste si le bouton a un niveau logique différent de BAS (donc HAUT)
    {
       Serial.print("high");   // le bouton est appuyé, la LED est allumée
    }
 /* digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
  
tmeduration=pulseIn(echoPin,HIGH);
distance=(0.034*tmeduration)/2;

if(distance<=20){
  myservo.write(90); 
  test1=true;
  
 
  }
  else{
    if(test1==true)
    { 
      Serial.write('1');
      test1=false;
    }
    myservo.write(0);
   }
    delay(10);*/
  

}
