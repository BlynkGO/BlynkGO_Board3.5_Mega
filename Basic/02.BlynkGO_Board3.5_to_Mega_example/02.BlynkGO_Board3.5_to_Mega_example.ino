#include <BlynkGOv2.h>

GLabel    label;
GTimer    esp32_timer;
uint32_t  counter;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial2.begin(9600, SERIAL_8N1, 22,25, false);

  BlynkGO.begin();

  label.font(prasanmit_40,TFT_WHITE);

  // ตั้งเวลาทุกๆ 2000ms ส่งค่า ESP32 --> MEGA ทาง Serial2
  esp32_timer.setInterval(2000,[](){
    String msg32 = String("ESP32: ") + String(counter++);
    Serial2.println(msg32);
  });
}

void loop() {
  BlynkGO.update();
  // รับค่าจาก MEGA --> ESP32 ทาง Serial2 แล้วแสดงออกจอ ด้วยวิตเจ็ต GLabel
  if(Serial2.available()){
    String msg_mega = Serial2.readStringUntil('\n'); message.trim();
    label = msg_mega;
  }
}


