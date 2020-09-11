#include <IRremote.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
int led_pin1 = 6;
int led_pin2 = 7;
int led_state1 = 0;
int led_state2 = 0;
#define code1 0xFD08F7
#define code2 0xFD8877
 
void setup()
{
  irrecv.enableIRIn();
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("1 : LED1 ON/OFF");
  lcd.setCursor(0,1);
  lcd.print("2 : LED2 ON/OFF");
}
 
void loop() {
if (irrecv.decode(&results)) {
  unsigned int value = results.value;
  switch (value) {
  case code1 :
    lcd.setCursor(0,0);
    if(led_state1 == 1){
    digitalWrite(led_pin1, LOW);
    lcd.print("LED1 is OFF     ");
    led_state1 = 0;
    }
    else{
      digitalWrite(led_pin1, HIGH);
      lcd.print("LED1 is ON      ");
      led_state1 = 1;
    }
    break;
  case code2 :
    lcd.setCursor(0,1);
    if(led_state2 == 1){
    digitalWrite(led_pin2, LOW);
    lcd.print("LED2 is OFF     ");
    led_state2=0;
    }
    else{
      digitalWrite(led_pin2, HIGH);
      lcd.print("LED2 is ON      ");
      led_state2=1;
    }
    break;
    }
    irrecv.resume(); 
}
}