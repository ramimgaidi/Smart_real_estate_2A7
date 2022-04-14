#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);

#include <LiquidCrystal.h>


const int rs = 10, en = 9, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i;
 
void setup() 
{

  SPI.begin();     
  mfrc522.PCD_Init();   
  Serial.println("Approximate your card to the reader...");
  Serial.println();

  lcd.begin(16, 2);
  lcd.print("METTRE UN BADGE");
  
 


  
}
void loop() 
{

  lcd.setCursor(6, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
   lcd.setCursor(0, 1);
    lcd.print("12:30");
       lcd.setCursor(9, 1);
    lcd.print("Temp=20");
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "E4 6D 5C 2A") 
  {
    
      lcd.setCursor(0,1);
 lcd.print("nom employé ");

 delay(1000);
  
lcd.setCursor(0,0);
    lcd.clear();
     lcd.print("METTRE UN BADGE");
   
    delay(500);

    }

      if (content.substring(1) == "F9 CD A3 D5") 
  {
      lcd.setCursor(0, 1);
 lcd.print("Monsieur B ");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.clear();
     lcd.print("METTRE UN BADGE");
   
    delay(500);

   
  }
 

}
