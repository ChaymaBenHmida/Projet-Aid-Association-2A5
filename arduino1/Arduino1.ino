#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27,16,2); 
  char data; 

void setup() 
  {
      Serial.begin(9600);
    lcd.init();
lcd.backlight(); 
lcd.print("Bienvenue!!");
  }
    
void loop() {
    if (Serial.available()){     
  
      data=Serial.read();  
      
       if(data=='1') 
        {
      lcd.setCursor(1,0);
      lcd.print("salle ouverte");
      Serial.print("a");
      delay(1500); 
      lcd.clear(); 
        }  

        
       else if(data=='0')
       {
       lcd.setCursor(1,1);
      lcd.print("salle sature");
      Serial.print("b");
      delay(1500); 
      lcd.clear(); 
       }   
      }
  }
 
