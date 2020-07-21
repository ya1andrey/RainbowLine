#include "Adafruit_NeoPixel.h"
#define NL 31
#define PIN 13
const int micPin=A0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NL,PIN, NEO_GRB+NEO_KHZ800);
void setup(){
  strip.begin();
  strip.setBrightness(50);
  Serial.begin(9600);
  }

void loop(){
  
  int mv=analogRead(micPin);
  Serial.println(mv);
  
 rainbow(1);
 
}

void rainbow(int wait){
 // int i,j;
  for(int j=0;j<256;j++)
  {
    for(int i=0; i<NL;i++)
    {
      strip.setPixelColor(i,Wheel(i*256/strip.numPixels()+j));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos){
  if(WheelPos<50){ //красный-оранжевый(стоит удлинить)
    return strip.Color(255,WheelPos*1.5,0);
  }
 
  else if(WheelPos<120){//желтый-зеленый
    WheelPos+=15;
    return strip.Color(255-WheelPos*1.6,150,0);
  }
  else if(WheelPos<160){//зеленый-голубой
  WheelPos+=7;
    return strip.Color(0,255,WheelPos*2);
  }
  else if(WheelPos<190){//голубой-синий
  WheelPos+=6;
    return strip.Color(0,255-WheelPos*1.5,255);
  }
  else{
    WheelPos+=20;
    return strip.Color(120+WheelPos*2, 0,255);
  }
}
