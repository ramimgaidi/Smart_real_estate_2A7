#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
char data; // variable contenant le caractère lu

void setup() {
Serial.begin(9600);  
lcd.begin(16,2); // initialisation de l’afficheur
pinMode(0,OUTPUT); //règle la borne numérique numéro 0 de la carte Arduino en mode sortie
pinMode(1,OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);

}

void loop() {
  
  if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
     lcd1();
     }
     else if(data=='0') //si le caractère lu est égale à 0

     {
     lcd2();

     }   

                        }
}
bool lcd1(){
lcd.init();
lcd.backlight();
lcd.clear(); // effacer le contenu de l’Afficheur LCD
digitalWrite(0,LOW); //la LED rouge s’éteint
digitalWrite(1,HIGH); //la LED vert s’allume
lcd.setCursor(0, 0);
lcd.print("Code Correct"); // Afficher le mot ‘traversez vite’ sur l’afficheur LCD
delay(3000); 
      myservo.write(0);
      delay(1000);   
// waits 15ms for the servo to reach the position 
myservo.write(90);
// tell servo to go to position in variable 'pos'
    delay(1000); 
return true;
}
bool lcd2(){
lcd.clear();
digitalWrite(0,HIGH); //la LED rouge s’éteint
digitalWrite(1,LOW); // la LED vert s’éteint
lcd.print("Code Incorrect"); // Afficher le mot ‘STOP’ sur l’afficheur LCD
delay(3000);
return true;
}
