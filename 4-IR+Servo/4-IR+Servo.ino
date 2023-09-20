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
  servo(10, 180);
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
        turnLeft();
        i++;
      } else if (i == 1) {
        ao();
        turnServo();
        turnAround();
        i++;
      } else if (i == 2) {
        turnLeft();
        i++;
      } else if (i == 3) {
        ao();
        turnServo();
        turnAround();
        i++;
      } else if (i == 4) {
        turnLeft();
        i++;
      } else if (i == 5) {
        ao();
        turnServo();
        turnAround();
        i++;
      } else if (i == 6) {
        turnLeft();
        i++;
      } else if (i == 7) {
        ao();
        j++;
      }
    } else if ((valR > TRE) && (valL > TRE)) {
      fd(40);
    } else if ((valR < TRE) && (valL > TRE)) {
      sr(50);
    } else if ((valR > TRE) && (valL < TRE)) {
      sl(50);
    }
  }
}
void turnRight() {
  display.setCursor(0, 50);
  display.print("Turn Right");
  display.display();
  fd(40);
  delay(300);
  sr(40);
  delay(450);
}

void turnLeft() {
  display.setCursor(0, 50);
  display.print("Turn Left");
  display.display();
  fd(40);
  delay(260);
  sl(40);
  delay(430);
}

void turnAround() {
  display.setCursor(0, 50);
  display.print("Turn Around");
  display.display();
  sr(40);
  delay(950);
}

void turnServo() {  
  display.setCursor(0, 50);
  display.print("Get Rekt");
  display.display();
  servo(10, 0);
  delay(500);
  servo(10, 180);
}