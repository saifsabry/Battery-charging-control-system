#include <Wire.h>
#include <LiquidCrystal.h>
#define bt_start  A0
#define RELAY2 7 
#define relay 8
int program;
int A=2;
int LED = 2;
unsigned long myTime;
int sec =0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int selectButton = 0;
int menu = 1;




void setup() 
{
  lcd.begin(16,2);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  updateMenu();
}


void loop() 
{
  if (!digitalRead(selectButton)){
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
}

void updateMenu() {
  
  switch (menu) {
    case 0:
      menu = 1;
      break;
      
    case 1:
      lcd.clear();
      lcd.print(" Charging  Prog ");
      lcd.setCursor(5, 1);
      lcd.print(">Start");
      break;

  }
}


void executeAction() {
  switch (menu) {
    
    case 1:
      timer_min();  
      action1();
      break;
}
}



void timer_min(){
lcd.clear();
int sec =0;
int time_m = 0;
int time_h = 0;




while(sec<51 &&  time_m==0 && time_h==0){
  sec = sec+1;
delay(1000);



if(sec>59)
{
time_m = time_m+1;
sec=0;
}



if(time_m>59)
{
time_h = time_h+1;
time_m=0;
}



// one hour charging
if(sec==1 &&  time_m==0  && time_h==0)
{

lcd.setCursor(0,0);
lcd.print(" Charging 1 hr ");
digitalWrite(RELAY2, LOW);
digitalWrite(relay, HIGH);  

}



  
// 5 min short circuit

if(sec==10 &&  time_m==0  && time_h==0)
{
lcd.setCursor(0,0);
lcd.print("  Short stage  ");
digitalWrite(RELAY2, HIGH);
digitalWrite(relay, LOW);


  }

// 12 hours short circuit 
if(sec==20&&  time_m==0  && time_h==0)
{
lcd.setCursor(0,0);
lcd.print(" Charging 2 hr     ");

digitalWrite(RELAY2, LOW);
digitalWrite(relay, HIGH);  
  

  }
  if(sec==30 &&  time_m==0  && time_h==0)
{
lcd.setCursor(0,0);
lcd.print("  Short stage 2 ");
digitalWrite(RELAY2, HIGH);
digitalWrite(relay, LOW);


  }



if(sec==40 &&  time_m==0  && time_h==0)
{
lcd.setCursor(0,0);
lcd.print(" Charging 12 hr ");
digitalWrite(RELAY2, LOW);
digitalWrite(relay, HIGH);


  }
if(sec== 50 &&  time_m==0 && time_h==0)
{
delay(1000);
digitalWrite(relay, LOW);
digitalWrite(RELAY2, LOW);
digitalWrite(LED, HIGH);


  }



lcd.setCursor(4,1);
if(time_h<=9){lcd.print("0");}
lcd.print(time_h);
lcd.print(":");
if(time_m<=9){lcd.print("0");}
lcd.print(time_m);
lcd.print(":");
if(sec<=9){lcd.print("0");}
lcd.print(sec);
lcd.print("   ");

}}
void action1() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Done charging");
  lcd.setCursor(0,1);
  lcd.print(">Home");
  delay(1500);
}
