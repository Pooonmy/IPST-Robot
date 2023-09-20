#include <IROVER.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define IR_R 34
#define IR_L 35
#define TRE 1500
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int i = 0, j = 0, t = 0;

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
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("R : ");
    display.println(valR);
    display.print("L : ");
    display.println(valL);
    display.display();
    if ((valR < TRE) && (valL < TRE)) {
      if (i == 0) {
        display.setCursor(0, 50);
        display.print("Turn Left");
        display.display();
        fd(40);
        delay(300);
        sl(40);
        delay(500);
        ao();
        delay(500);
        i++;
      } else if (i == 1) {
        display.setCursor(0, 50);
        display.print("Turn Right");
        display.display();
        fd(40);
        delay(300);
        sr(40);
        delay(500);
        ao();
        delay(500);
        i++;
      } else if (i == 2) {
        display.setCursor(0, 50);
        display.print("Turn Right");
        display.display();
        sr(40);
        delay(300);
        fd(40);
        delay(300);
        ao();
        delay(500);
        i++;
      } else if (i == 3) {
        display.setCursor(0, 50);
        display.print("Turn Left");
        display.display();
        fd(40);
        delay(260);
        sl(40);
        delay(500);
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
    if ((valR > TRE) && (valL > TRE)) {
      fd(40);
    }
    if ((valR < TRE) && (valL > TRE)) {
      sr(70);
    }
    if ((valR > TRE) && (valL < TRE)) {
      sl(40);
    }
  }
}