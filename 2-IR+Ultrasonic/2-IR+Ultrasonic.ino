#include <IROVER.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define ULTRA 32
#define IR_R 34
#define IR_L 35
#define TRE 3000
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int i = 0, j = 0, k = 0;

void setup() {
  init(0x48);
  waitSW_1();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  while (j == 0) {
    int valR = analogRead(IR_R);
    int valL = analogRead(IR_L);
    int dis = (analogRead(ULTRA)) * 3;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("R : ");
    display.println(valR);
    display.print("L : ");
    display.println(valL);
    display.print(String(dis) + " MM");
    display.display();
    if ((valR < TRE) && (valL < TRE)) {
      if (i == 0) {
        display.setCursor(0, 50);
        display.print("Turn Left");
        display.display();
        fd(35);
        delay(300);
        sl(40);
        delay(440);
        i++;
      } else if (i == 1) {
        display.setCursor(0, 50);
        display.print("Turn Right");
        display.display();
        fd(40);
        delay(300);
        sr(40);
        delay(450);
        i++;
      } else if (i == 2) {
        display.setCursor(0, 50);
        display.print("Turn Right");
        display.display();
        fd(40);
        delay(300);
        sr(40);
        delay(450);
        i++;
      } else if (i == 3) {
        display.setCursor(0, 50);
        display.print("Turn Left");
        display.display();
        fd(40);
        delay(260);
        sl(40);
        delay(430);
        ao();
        delay(500);
        i++;
      } else if (i == 4) {
        display.setCursor(0, 50);
        display.print("Stop");
        display.display();
        fd(40);
        delay(500);
        ao();
        j++;
      }
    }
    else if ((valR > TRE) && (valL > TRE)) {
      fd(40);
    }
    else if ((valR < TRE) && (valL > TRE)) {
      sr(50);
    }
    else if ((valR > TRE) && (valL < TRE)) {
      sl(50);
    }
    if (dis <= 700) {
      if (k == 0) {
        sr(40);
        delay(400);
        fd(40);
        delay(580);
        sl(40);
        delay(400);
        fd(40);
        delay(800);
        sl(40);
        delay(400);
        fd(40);
        delay(650);
        sr(40);
        delay(400);
        k++;
      } else if (k == 1) {
        sr(40);
        delay(400);
        fd(40);
        delay(500);
        sl(40);
        delay(430);
        fd(40);
        delay(850);
        sl(40);
        delay(400);
        fd(40);
        delay(430);
        sr(40);
        delay(400);
        k++;
      } else if (k == 2) {
        sr(40);
        delay(500);
        fd(40);
        delay(670);
        sl(40);
        delay(300);
        fd(40);
        delay(800);
        sl(40);
        delay(400);
        fd(40);
        delay(500);
        sr(40);
        delay(400);
      }
    }
  }
}