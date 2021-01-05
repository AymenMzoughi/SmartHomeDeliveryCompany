const int bouton =2;  // la broche 4 devient bouton
const int led = 12;    // la broche 12 devient led
int val=0;
void setup()
{
    pinMode(bouton,INPUT_PULLUP); // Initialise la broche 4 comme entrée
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    // Initialise la broche 12 comme sortie
    Serial.begin(9600);     // Ouvre le port série à 9600 bauds
}

void loop()
{
    // Si bouton poussoir appuyé...
    if (digitalRead(bouton) == 1) // teste si le bouton a une valeur de 1
        // ...on allume la LED
    {
        digitalWrite(led,HIGH);
        
        
    }
    // Sinon...
    else
        // teste si le bouton a une valeur de 0
        // ...on éteint la LED
    {
        digitalWrite(led,LOW);
        Serial.println("6");
           
        
    }

}
