
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <TFT.h>  
#include <SPI.h>

Adafruit_INA219 ina219;
#define cs   10
#define dc   9
#define rst  8

  float voltage_V = 0,shuntVoltage_mV,busVoltage_V;
  float current_mA = 0;
  //float ancien_courant =0;
  //float courant=0;
  float puissance = 0;
  float energie=0;
  float energie_totale=0;
  float energie_wh=0;
  float duree=0;
  long time_s=0;
  long temps_nouveau=0;
  long temps_ancien=0;
  long temps=0;

 TFT TFTscreen = TFT(cs, dc, rst);

void setup(void) 
{
  Serial.begin(9600);
  uint32_t currentFrequency;
  ina219.begin();
  TFTscreen.begin();
  TFTscreen.background(200, 0, 0);
  TFTscreen.setTextSize(1);
  TFTscreen.text("Measuring voltage and current with INA219", 10, 100);
  
 
}


void loop(void) 
{
  
  temps_ancien = millis()/1000;
  getData();
  delay(2000);

  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text("----------------------------------------------------------------------------", 0, 0);
  TFTscreen.text("temps :        ", 10, 10); TFTscreen.text(temps_ancien, 30, 10); TFTscreen.text(" secondes", 40, 10);
  TFTscreen.text("Tension:  ", 10, 20); TFTscreen.text(voltage_V, 30, 20); TFTscreen.text(" V", 30, 20);
  TFTscreen.text("Courant:       ", 10, 30); TFTscreen.text(current_mA, 30, 30); TFTscreen.text(" mA", 40, 30);
  TFTscreen.text("Puissance:         ", 10, 40); TFTscreen.text(puissance, 30, 40); TFTscreen.text(" W", 40, 40);  
  TFTscreen.text("duree:         ", 10, 50); TFTscreen.text(duree, 30, 50);  
  if (energie_totale >3600){
  energie_wh= energie_totale/3600;
  TFTscreen.text("Energie totale:        ", 10, 60); TFTscreen.text(energie_wh, 30, 60); TFTscreen.text(" Wh", 40, 60);
 }
  else {
    TFTscreen.text("Energie totale:        ", 10, 60); TFTscreen.text(energie_totale, 30, 60); TFTscreen.text(" Ws", 40, 60);
  }
  TFTscreen.text("----------------------------------------------------------------------------", 0, 100);
  
}

void getData(){

 temps_nouveau = millis()/1000; 
  
 busVoltage_V = ina219.getBusVoltage_V();
 delay(100);
 shuntVoltage_mV = ina219.getShuntVoltage_mV();
 delay(100);
 voltage_V = busVoltage_V + (shuntVoltage_mV / 1000);
 delay(100);
 current_mA = ina219.getCurrent_mA();
 delay(100);
 
 //temps_nouveau = millis();
 duree = (temps_nouveau-temps_ancien);
 temps_ancien=temps_nouveau;
 puissance = voltage_V*current_mA/1000;
 energie=puissance*duree;
 energie_totale =energie_totale+energie;
 
   
  
 
}
