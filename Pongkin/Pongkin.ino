#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, 6,
NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

int leftPaddlePosition;
int rightPaddlePosition;
long ballXPos;
long ballYPos;
char ballXVector;
char ballYVector
int leftScore;
int rightScore;

void setup() {
  Serial.begin(9600);
  matrix.begin();
  introScreen();
  resetGame()
}

void loop() {
  matrix.fillScreen(0);
  
  leftPaddle();
  rightPaddle();
  checkCollisions();
  updateBall();
  drawScreen();
  delay(17);
}

void introScreen() {
  matrix.drawPixel(0, 0, matrix.Color(0, 0, 255));
  matrix.show();
}

void resetGame() {
  leftScore = 0;
  rightScore = 0;
  initializeBall();
}

void initializeBall() {
  ballXPos = (long)random(7, 8);
  ballYPos = (long)random(7, 8);
  ballXVector = random(-128, 127);
  ballYVector = random(-128, 127);
}

void leftPaddle() {
  int leftPaddlePosition = (analogRead(A0) / (float)1023) * 13;
}

void rightPaddle() {
  int rightPaddlePosition = (analogRead(A1) / (float)1023) * 13;
}

void checkCollisions() {
  
}

void updateBall() {
  
}

void drawScreen() {
  matrix.drawPixel(0, num1, matrix.Color(0, 0, 255));
  matrix.drawPixel(0, (num1 + 1), matrix.Color(0, 0, 255));
  matrix.drawPixel(0, (num1 + 2), matrix.Color(0, 0, 255));
  
  matrix.drawPixel(15, num2, matrix.Color(0, 0, 255));
  matrix.drawPixel(15, (num2 + 1), matrix.Color(0, 0, 255));
  matrix.drawPixel(15, (num2 + 2), matrix.Color(0, 0, 255));

  matrix.drawPixel(ballXPos, ballYPos, matrix.Color(0, 0, 255));
  
  matrix.show();
}
