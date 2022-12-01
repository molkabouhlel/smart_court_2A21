#include <Keypad.h>
#include <Servo.h>
Servo monServomoteur;
#include <LiquidCrystal_I2C.h> // pour télécharger la librairie: croquis - include library - manage libraries - LiquidCrystal_I2C.h de Frank de Brabander
LiquidCrystal_I2C lcd(0x27,16,2);
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte rowPins[ROWS] =  {5,4,3,2}; //Lignes
byte colPins[COLS] = {8,7,6,10}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int redled = 11;
int greenled=1;
int ir=9;
String ch="";
String C="WRONG\n";
void setup()
{
    Serial.begin(9600);
    monServomoteur.attach(13);//moteur pin 13
    monServomoteur.write(50);
    lcd.begin(16, 2);
    lcd.init(); //initialisation de l'écran LCD
    lcd.backlight();
    lcd.setCursor (0,0);
    lcd.print("    PROJET  ");
    lcd.setCursor (0,1);
    lcd.print(" SMART PARKING");
    delay (5000);
    lcd.clear();
    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);
    lcd.setCursor (0,0);
    delay (200);
}
void loop()
{
    keypadfunction();

}
void keypadfunction()
{
    monServomoteur.write(50);
    delay(100);
    lcd.clear();
    lcd.println("ENTER PASSWORD!");
    //lcd.setCursor(0,1);
    char key = keypad.getKey();
    if(key)
    Serial.print(key);
   
   
    if(Serial.available())
    {
        lcd.clear();
        lcd.init(); //initialisation de l'écran LCD
         lcd.backlight();
        lcd.setCursor (0,0);
        lcd.println(" WELCOME :");
        lcd.setCursor (0,1);
        ch=Serial.readString();
        lcd.println(ch);//base
        delay(500);
        if(!ch.equals(C))//vrai
        {
            monServomoteur.write(150);
            delay(3000);
            digitalWrite(greenled, LOW);
            delay(1000);
            digitalWrite(redled, HIGH);
            delay(1000);
        }
        lcd.clear();
    }
}
