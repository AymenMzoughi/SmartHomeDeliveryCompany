//Parameters 
const int btnPin  = A0; 
 
//Variables 
int btnVal  = 0; 

void setup(){ 
//Init Serial USB 
Serial.begin(9600); 
//Init btn 
pinMode(btnPin,INPUT_PULLUP); 
} 

void loop() {
  ////Read pushbutton 
  btnVal=analogRead(btnPin); 
  if(btnVal<200){ 
    Serial.println("7"); 
  }else{ 
    Serial.println("9"); 
  } 
  delay(100);
}
