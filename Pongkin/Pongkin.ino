#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, 6,
NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

int leftPaddlePosition;
int rightPaddlePosition;
float ballXPos;
float ballYPos;
char ballXVector;
char ballYVector;
int leftScore;
int rightScore;
int startingPositions[][4] = { {7, 7}, {7, 8}, {8, 7}, {8, 8} };
float ballSpeed = 0.003;

void setup() {
  Serial.begin(9600);
  matrix.begin();
  randomSeed(analogRead(2));
  introScreen();
  resetGame();
}

void loop() {
  matrix.fillScreen(0);
  
  leftPaddle();
  rightPaddle();
  checkCollisions();
  updateBall();
  drawScreen();
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
  int randomPosition = random(4);
  
  ballXPos = (float)startingPositions[randomPosition][0];
  ballYPos = (float)startingPositions[randomPosition][1];
  
  ballXVector = random(20, 128);
  int ballXMagnitude = random(0, 2);
  if (ballXMagnitude == 1) {
    ballXVector *= -1;
  }
  ballYVector = random(20, 128);
  int ballYMagnitude = random(0, 2);
  if (ballYMagnitude == 1) {
    ballYVector *= -1;
  }
}

void leftPaddle() {
  leftPaddlePosition = (analogRead(A0) / (float)1023) * 13;
}

void rightPaddle() {
  rightPaddlePosition = (analogRead(A1) / (float)1023) * 13;
}

void checkCollisions() {
  //top/bottom
  if ((int)ballYPos <= 0 || (int)ballYPos >= 15) {
    ballYVector *= -1;
  }
  
  //left/right
  if ((int)ballXPos <= 0 || (int)ballXPos >= 15) {
    ballXVector *= -1;
  }

  //left paddle

  //right paddle
}

void updateBall() {
  if (ballXVector != (float)0) {
    ballXPos += (float)ballXVector * (float)ballSpeed;
  }
  
  if (ballYVector != (float)0) {
    ballYPos += (float)ballYVector * (float)ballSpeed;
  }
  
  Serial.println(ballXPos, 10);
  Serial.println(ballYPos, 10);
}

void drawScreen() {
  matrix.drawPixel(0, leftPaddlePosition, matrix.Color(0, 0, 255));
  matrix.drawPixel(0, (leftPaddlePosition + 1), matrix.Color(0, 0, 255));
  matrix.drawPixel(0, (leftPaddlePosition + 2), matrix.Color(0, 0, 255));
  
  matrix.drawPixel(15, rightPaddlePosition, matrix.Color(0, 0, 255));
  matrix.drawPixel(15, (rightPaddlePosition + 1), matrix.Color(0, 0, 255));
  matrix.drawPixel(15, (rightPaddlePosition + 2), matrix.Color(0, 0, 255));

  matrix.drawPixel((int)ballXPos, (int)ballYPos, matrix.Color(0, 0, 255));
  
  matrix.show();
}
