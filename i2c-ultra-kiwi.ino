

#include <Wire.h> // Wire Bibliothek einbinden
#include <LiquidCrystal_I2C.h> // Vorher hinzugefügte LiquidCrystal_I2C Bibliothek einbinden
LiquidCrystal_I2C lcd(0x3F, 16, 2); //Hier wird festgelegt um was für einen Display es sich handelt. In diesem Fall eines mit 16 Zeichen in 2 Zeilen und der HEX-Adresse 0x27. Für ein vierzeiliges I2C-LCD verwendet man den Code "LiquidCrystal_I2C lcd(0x27, 20, 4)" 
int _trigger_U = 7;
int _echo_U = 6;
double _signalToDistance = 0.03432/2;
double _getUltrasonicDistance()
{
    digitalWrite(_trigger_U, LOW);
    delay(5);
    digitalWrite(_trigger_U, HIGH);
    delay(10);
    digitalWrite(_trigger_U, LOW);
    return pulseIn(_echo_U, HIGH)*_signalToDistance;
}


void setup() 
{
    Serial.begin(9600); 
    pinMode(_trigger_U, OUTPUT);
    pinMode(_echo_U, INPUT);
    lcd.init(); //Im Setup wird der LCD gestartet 
    lcd.backlight(); //Hintergrundbeleuchtung einschalten (lcd.noBacklight(); schaltet die Beleuchtung aus). 
}

void loop() 
{ 
lcd.setCursor(0, 0);//Hier wird die Position des ersten Zeichens festgelegt. In diesem Fall bedeutet (0,0) das erste Zeichen in der ersten Zeile. 
lcd.print(_getUltrasonicDistance()); 
lcd.setCursor(0, 1);// In diesem Fall bedeutet (0,1) das erste Zeichen in der zweiten Zeile. 
lcd.print("kreidezeit.kiwi"); 
delay(500);
} 
