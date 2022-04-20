#include "BlynkGO_Mega.h"

GTimerDuino mega_timer;
uint32_t counter;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);  // MEGA Serial2 : RX 17 TX 16

  // ตั้งเวลาทุกๆ 1000ms ส่งค่า MEGA --> ESP32 ทาง Serial2
  mega_timer.setInterval(1000,[](){
    String msg_mega = String("Mega : ") + String(counter++);
    Serial2.println(msg_mega);
  });
}

void loop() {
  mega_timer.run();
  // รับค่าจาก ESP32 --> MEGA ทาง Serial2
  if(Serial2.available()){
    String msg32 = Serial2.readStringUntil('\n'); msg.trim();
    Serial.println(msg32);
  }
}

