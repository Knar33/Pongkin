#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, 6,
NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  matrix.begin();
  matrix.drawPixel(0, 0, matrix.Color(0, 0, 255));
  matrix.show();
}

void loop() {
  matrix.fillScreen(0);
  int num1 = (analogRead(A0) / (float)1023) * 13;
  Serial.println(num1);
  matrix.drawPixel(0, num1, matrix.Color(0, 0, 255));
  matrix.drawPixel(0, (num1 + 1), matrix.Color(0, 0, 255));
  matrix.drawPixel(0, (num1 + 2), matrix.Color(0, 0, 255));
  
  int num2 = (analogRead(A1) / (float)1023) * 13;
  Serial.println(num1);
  matrix.drawPixel(15, num2, matrix.Color(0, 0, 255));
  matrix.drawPixel(15, (num2 + 1), matrix.Color(0, 0, 255));
  matrix.drawPixel(15, (num2 + 2), matrix.Color(0, 0, 255));
  
  matrix.show();
  
  Serial.println("======================================");
  
  delay(17);
}
