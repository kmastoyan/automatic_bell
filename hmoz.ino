#include <Wire.h>
#include "RTClib.h"
#define relay_pin 4    // пин реле
RTC_DS3231 rtc;
byte zangi_zhamanak=11;

byte sec, minute = 0, hour = 0, dow, os;

void setup() {
 Serial.begin(9600);
 pinMode(relay_pin, OUTPUT);          // пин реле как выход
 rtc.begin();
 //   Wire.begin();
  //  if (rtc.lostPower()){     
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//}
   DateTime now = rtc.now();
   dow=now.dayOfTheWeek();
   hour=now.hour();
   minute=now.minute();
   sec=now.second();
}



void loop() {
digitalWrite(relay_pin, 1);
delay(999);
  //if (hour < 10)
    //{
     // Serial.print("0");
      Serial.print(hour);    
    //}
    //else
   // {
      //Serial.print(hour);
    //}
    Serial.print(":");
    //if (minute < 10)
   // {
     // Serial.print("0");
      Serial.print(minute);
    //}
   // else
 //   {
 //     Serial.print(minute);
  //  }
  Serial.print(":");
  //  if (sec < 10)
  //  {
  //    Serial.print("0");
      Serial.print(sec);
 //   }
//    else
 //   {
 //     Serial.print(sec);
  //  }
//    Serial.print(" ");
    sec++;
    if (sec > 59)
    {
      minute++;
      sec = 0;
    }

    if (minute > 59)
    {
      hour++;
      minute = 0;
    }
    if (hour > 23)
    {
      hour = 0;
    }
  Serial.println();

  if(hour==8 && minute==30 && sec==0){delay(50000);Reset();}
  if(dow==0 || dow==3 || dow==4 || dow==5 || dow==6)
  {    
    if(hour==9 && minute==0&& sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;} }
    if(hour==10 && minute==10 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;}}
    if(hour==10 && minute==20 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;}}
    if(hour==11 && minute==30 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;}}
    if(hour==11 && minute==50 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;}}
    if(hour==13 && minute==0 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;}}
    if(hour==13 && minute==10 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;}}
    if(hour==14 && minute==20 && sec==0){ while(sec<zangi_zhamanak){digitalWrite(relay_pin, 0);delay(1000);sec++;} }
  }

}


inline void Reset() {asm("JMP 0");}
