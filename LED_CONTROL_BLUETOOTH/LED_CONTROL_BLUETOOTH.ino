#include"BluetoothSerial.h"

char receivedChar;

#if !defined(CONFIG_BT_ENABLED) || !defined (CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to an enable it
#endif

BluetoothSerial SerialBT;
const int ledPin = 16;
const char turnON = 'ON';
const char turnOFF = 'OFF';

void setup(){
  SerialBT.begin("ESP32");
  pinMode(ledPin, OUTPUT);
}

void loop(){

  receivedChar = (char)SerialBT.read();

  if(SerialBT.available()){

   if(receivedChar == turnON){
    digitalWrite(ledPin, HIGH);
   } 

   if(receivedChar == turnOFF){
    digitalWrite(ledPin, LOW);
   }

  }

  delay(20);
}