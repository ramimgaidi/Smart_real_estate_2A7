#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
char data; // variable contenant le caractère lu

void setup() {
  Serial.begin(9600);
   lcd.begin(16, 2); // initialisation de l’afficheur
  lcd.init(); //initialisation de l'écran LCD
lcd.cursor_on();
lcd.blink_on();
lcd.backlight();
lcd.setCursor(5,0); // écriture du texte sur la ligne 1 colonne 5 (centré)
lcd.print("Welcome!"); // texte "hello" sur ligne 1 colonne 5
lcd.setCursor(1,1); // écriture du texte sur la ligne 2 colonne 7 (centré)
lcd.print("WaterProof"); // texte "ok" sur ligne 2 colonne 7
lcd.cursor_off();
lcd.blink_off();
 
  pinMode(0, OUTPUT); //règle la borne numérique numéro 0 de la carte Arduino en mode sortie
  pinMode(1, OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie
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
       
       lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Code Correct"); // Afficher le mot ‘traversez vite’ sur l’afficheur LCD
 // delay(1000);
  myservo.write(0);
  delay(1500);
  // waits 15ms for the servo to reach the position
  myservo.write(90);
       Serial.write('1'); //envoyer le nouvel état de la lampe
       }
       if(data=='0') //si le caractère lu est égale à 0

       {
        
       lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Code incorrect");
  //digitalWrite(0, HIGH); //la LED rouge s’éteint
 // digitalWrite(1, LOW); // la LED vert s’éteint
       Serial.write('0'); //envoyer le nouvel état de la lampe
       }

                          }
}
void lcd1() {
  
  
  // effacer le contenu de l’Afficheur LCD
  //digitalWrite(0, LOW); //la LED rouge s’éteint
  //digitalWrite(1, HIGH); //la LED vert s’allume
  
  // tell servo to go to position in variable 'pos'


}
void lcd2() {
 
  
   // Afficher le mot ‘STOP’ sur l’afficheur LCD
  //myservo.write(90);
  
 
}
