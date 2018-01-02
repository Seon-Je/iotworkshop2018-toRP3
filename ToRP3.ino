#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int Val = 0;  
char buf[2];  
int TempPin = A0; 

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{   
  Serial.begin(9600);    
  
  lcd.init();                      // initialize the lcd    
  lcd.backlight();  // <--> noBacklight(); 

  lcd.setCursor(0,0);    
  lcd.print("2018-1st");      
  
  lcd.setCursor(3,1);   
  lcd.print("IoT Workshop");    
  
  delay(5000); 
  
  lcd.clear();    
  lcd.setCursor(0,0);    
  lcd.print("*IoT Workshop*");    
  lcd.setCursor(0,1);    
  lcd.print("Temp : "); 
  lcd.setCursor(10,1);    
  lcd.print("degrees"); 
} 

void loop() 
{   
  Val = analogRead(TempPin);   
  Val = Val * 1000/10 * 5/1024; 

  Serial.print("Temp : ");  
  Serial.println(Val);  

  lcd.setCursor(7,1);    
  lcd.print(itoa(Val,buf,10)); 

  delay(500); 
} 
