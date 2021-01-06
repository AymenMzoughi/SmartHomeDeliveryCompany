//Parameters 
const int btnPin  = A0; 
 
//Variables 
int btnVal  = 0; 

void setup(){ 
//Init Serial USB 
Serial.begin(9600); 
pinMode(3,OUTPUT);
pinMode(2,OUTPUT);
//Init btn 
pinMode(btnPin,INPUT_PULLUP);
digitalWrite(2, HIGH); //Red
digitalWrite(3, LOW); //Green 
} 

void loop() {
  ////Read pushbutton 
  btnVal=analogRead(btnPin); 
  if(btnVal<200){ 
    Serial.println("7");
digitalWrite(2, LOW); //Red
digitalWrite(3, HIGH); //Green 
  }else{ 
    Serial.println("9"); 
digitalWrite(2, HIGH); //Red
digitalWrite(3, LOW); //Green 
  } 
  delay(100);
}
