//All Credit Technic 1510
//
//
//
//
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   
LiquidCrystal lcd(6 , 7, 5, 4, 3, 2);
char data;
 
void setup() 
{
  
  SPI.begin();     
  mfrc522.PCD_Init();   
  lcd.begin(16, 2);
  lcd.print("Scan RFID Card");
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

}
void loop() 
{

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    lcd.setCursor(0, 1);
     lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     lcd.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
lcd.clear();
lcd.begin(16, 2);
 lcd.print("Acces:");
 content.toUpperCase();
  if (content.substring(1) == "C3 9E B0 40") //Plz change to your cards UID
  
  {Serial.write('1');
     if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();}  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1')//si le car
   lcd.setCursor(0,1);
    lcd.print("Accepted");
     delay(3000);
   lcd.clear();
    setup();
  }
 
 else   {
  {Serial.write('0');
     if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  }
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='0') //si le caractère lu est égale à 1
  lcd.setCursor(0, 1);
    lcd.print("denied");
    delay(3000);
    lcd.clear();
      setup();
      }
} 

 }
