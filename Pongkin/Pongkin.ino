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
int startingBallSpeed = 30;
int ballSpeedUpRate = 5;
int ballDeflectionSpeedUpRate = 5;
uint16_t pixelColor = matrix.Color(0, 0, 255);

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
  matrix.drawPixel(0, 0, pixelColor);
  matrix.show();
}

void resetGame() {
  leftScore = 0;
  rightScore = 0;
  initializeBall();
}

void initializeBall() {
  //This was done because generating 2 random numbers back to back gave the same random number every time.
  int randomPosition = random(4);
  ballXPos = (float)startingPositions[randomPosition][0];
  ballYPos = (float)startingPositions[randomPosition][1];
  
  ballXVector = startingBallSpeed;
  int ballXMagnitude = random(0, 2);
  if (ballXMagnitude == 1) {
    ballXVector *= -1;
  }
  ballYVector = random(20, 128);
  int ballYMagnitude = random(0, 2);
  if (ballYMagnitude == 1) {
    ballYVector *= -1;
  }

  matrix.drawPixel((int)ballXPos, (int)ballYPos, pixelColor);
  delay(200);
  matrix.show();

  matrix.drawPixel((int)ballXPos, (int)ballYPos, 0);
  delay(200);
  matrix.show();

  matrix.drawPixel((int)ballXPos, (int)ballYPos, pixelColor);
  delay(200);
  matrix.show();

  matrix.drawPixel((int)ballXPos, (int)ballYPos, 0);
  delay(200);
  matrix.show();

  matrix.drawPixel((int)ballXPos, (int)ballYPos, pixelColor);
  delay(200);
  matrix.show();
}

void leftPaddle() {
  leftPaddlePosition = (analogRead(A0) / (float)1023) * 13;
}

void rightPaddle() {
  rightPaddlePosition = (analogRead(A1) / (float)1023) * 13;
}

void checkCollisions() {
  //top/bottom walls
  if ((int)ballYPos <= 0 || (int)ballYPos >= 15) {
    ballYVector *= -1;
  }
  
  //left/right walls
  if ((int)ballXPos <= 0 || (int)ballXPos >= 15) {
    resetGame();
  }

  //left paddle
  if ((int)ballXPos == 1) {
    if ((int)ballYPos == leftPaddlePosition) {
      ballXVector *= -1;
      if (ballYVector <= (127 - ballDeflectionSpeedUpRate)) {
        ballYVector += ballDeflectionSpeedUpRate;
      }
      else {
        ballYVector = 127;
      }
      speedUpBall();
    }
    if ((int)ballYPos == (leftPaddlePosition + 1)) {
      ballXVector *= -1;
      speedUpBall();
    }
    if ((int)ballYPos == (leftPaddlePosition + 2)) {
      ballXVector *= -1;
      if (ballYVector >= (-128 + ballDeflectionSpeedUpRate)) {
        ballYVector -= ballDeflectionSpeedUpRate;
      }
      else {
        ballYVector = -128;
      }
      speedUpBall();
    }
  }
  
  //right paddle
  if ((int)ballXPos == 14) {
    if ((int)ballYPos == rightPaddlePosition) {
      ballXVector *= -1;
      if (ballYVector <= (127 - ballDeflectionSpeedUpRate)) {
        ballYVector += ballDeflectionSpeedUpRate;
      }
      else {
        ballYVector = 127;
      }
      speedUpBall();
    }
    if ((int)ballYPos == (rightPaddlePosition + 1)) {
      ballXVector *= -1;
      speedUpBall();
    }
    if ((int)ballYPos == (rightPaddlePosition + 2)) {
      ballXVector *= -1;
      if (ballYVector >= (-128 + ballDeflectionSpeedUpRate)) {
        ballYVector -= ballDeflectionSpeedUpRate;
      }
      else {
        ballYVector = -128;
      }
      speedUpBall();
    }
  }
}

void updateBall() {
  if (ballXVector != (float)0) {
    ballXPos += (float)ballXVector * (float)ballSpeed;
  }
  
  if (ballYVector != (float)0) {
    ballYPos += (float)ballYVector * (float)ballSpeed;
  }
}

void speedUpBall() {
  if (ballXVector < 0 && ballXVector >= (-128 + ballSpeedUpRate)) {
    ballXVector -= ballSpeedUpRate;
  }
  else if (ballXVector <= (127 - ballSpeedUpRate)) {
    ballXVector += ballSpeedUpRate;
  }
}

void drawScreen() {
  matrix.drawPixel(0, leftPaddlePosition, pixelColor);
  matrix.drawPixel(0, (leftPaddlePosition + 1), pixelColor);
  matrix.drawPixel(0, (leftPaddlePosition + 2), pixelColor);
  
  matrix.drawPixel(15, rightPaddlePosition, pixelColor);
  matrix.drawPixel(15, (rightPaddlePosition + 1), pixelColor);
  matrix.drawPixel(15, (rightPaddlePosition + 2), pixelColor);

  matrix.drawPixel((int)ballXPos, (int)ballYPos, pixelColor);
  
  matrix.show();
}
