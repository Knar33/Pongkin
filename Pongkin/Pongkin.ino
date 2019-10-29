#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define paddle1Pin A0
#define paddle2Pin A1
#define ledPin 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, ledPin, 
NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

static const uint16_t knarLogo[256] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x1821, 0x3042, 0x3042, 0x3042, 0x3042, 0x2841, 0x0000, 0x0000, 0x2842, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x3042, 0x2041, 
    0x7843, 0xe825, 0xe825, 0xe825, 0xe825, 0xb865, 0x0000, 0x7884, 0xe845, 0xe825, 0xe825, 0xe825, 0xe825, 0xe825, 0xd865, 0x2841, 
    0x7843, 0xf025, 0xf025, 0xf025, 0xf025, 0xb865, 0x7884, 0xe845, 0xf025, 0xf025, 0xf025, 0xf025, 0xf025, 0xd865, 0x2841, 0x0000, 
    0x7843, 0xe825, 0xe825, 0xe825, 0xe825, 0xe846, 0xe825, 0xe9ca, 0xea0b, 0xe825, 0xe825, 0xf025, 0xd865, 0x2841, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xe825, 0xe825, 0xe825, 0xf025, 0xe866, 0xee5a, 0xe8a7, 0xe825, 0xf025, 0xd865, 0x2841, 0x0000, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xe825, 0xe825, 0xe825, 0xea6d, 0xe390, 0xedb7, 0xe845, 0xf025, 0xd865, 0x2841, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xe825, 0xf025, 0xe845, 0xe453, 0xe4b4, 0xf5d8, 0xe825, 0xe066, 0x2841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xf025, 0xe98a, 0xe3d1, 0xe473, 0xf71c, 0xeace, 0xe825, 0xe845, 0x6863, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xe866, 0xedf8, 0xe494, 0xf71c, 0xe2ae, 0xe825, 0xe825, 0xe825, 0xe845, 0x6063, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xe845, 0xee9a, 0xee39, 0xe26d, 0xe845, 0xe825, 0xe825, 0xe825, 0xe825, 0xe845, 0x6863, 0x0000, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xe845, 0xedb7, 0xe928, 0xd066, 0xd865, 0xe825, 0xe825, 0xe825, 0xe825, 0xe825, 0xe845, 0x6864, 0x0000, 0x0000, 
    0x7843, 0xe825, 0xf025, 0xe949, 0xf025, 0xb845, 0x3042, 0xe045, 0xe825, 0xe825, 0xe825, 0xe825, 0xe825, 0xe845, 0x6863, 0x0000, 
    0x6863, 0xd886, 0xd886, 0xd886, 0xd886, 0xa885, 0x0000, 0x3842, 0xd086, 0xd886, 0xd886, 0xd886, 0xd886, 0xd886, 0xd8a6, 0x48a3, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

static const uint16_t matrexLogo[256] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2922, 0x9385, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6a84, 0xd4e4, 0xfde4, 0xa426, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1083, 0x39aa, 0x5ab0, 0x62f3, 0x0840, 0xe565, 0xfde4, 0xfde4, 0x5a65, 
    0x0000, 0x0000, 0x0000, 0x0021, 0x2947, 0x39eb, 0x0000, 0x6b54, 0x7b96, 0x7b96, 0x5271, 0x4a06, 0xfde4, 0xfde4, 0xfdc4, 0x1081, 
    0x0000, 0x0000, 0x52af, 0x7396, 0x7b96, 0x5271, 0x2946, 0x7b96, 0x7b96, 0x7b96, 0x39ae, 0x9bc8, 0xfde4, 0xfde4, 0xc4a6, 0x0000, 
    0x0000, 0x10a3, 0x7b96, 0x7b96, 0x7b96, 0x41ce, 0x5290, 0x7b96, 0x7b96, 0x6b34, 0x316d, 0xdd26, 0xfde4, 0xfde4, 0x7305, 0x0000, 
    0x0000, 0x41ea, 0x7b96, 0x7b96, 0x6b55, 0x316d, 0x6b34, 0x7b96, 0x7b96, 0x5a92, 0x520b, 0xfde4, 0xfde4, 0xfde4, 0x2923, 0x0000, 
    0x0000, 0x62f1, 0x7b96, 0x7b96, 0x5ab2, 0x39ad, 0x7396, 0x7b96, 0x7b96, 0x41ef, 0x8b69, 0xfde4, 0xfde4, 0xdd45, 0x0000, 0x0000, 
    0x0841, 0x7396, 0x7b96, 0x7b96, 0x4a0f, 0x5250, 0x7b96, 0x7b96, 0x7375, 0x316d, 0xccc6, 0xfde4, 0xfde4, 0x8ba6, 0x0000, 0x0000, 
    0x3188, 0x7b96, 0x7b96, 0x7395, 0x398d, 0x62f3, 0x7b96, 0x7b96, 0x5aaf, 0x41cc, 0xfdc4, 0xfde4, 0xfde4, 0x41a3, 0x0000, 0x0000, 
    0x5aaf, 0x7b96, 0x7b96, 0x5acf, 0x41eb, 0x7396, 0x7b96, 0x7b96, 0x2946, 0x7b09, 0xfde4, 0xfde4, 0xed85, 0x0020, 0x0000, 0x0000, 
    0x6b32, 0x7395, 0x7395, 0x39c9, 0x2967, 0x7395, 0x7395, 0x7395, 0x0021, 0x8347, 0xed85, 0xed85, 0xa426, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 35;
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
uint16_t pixelColor = matrix.Color(255, 0, 255);

void setup() {
  Serial.begin(9600);
  matrix.begin();
  randomSeed(analogRead(2));
  displayGraphic(knarLogo);
  delay(1000);
  displayGraphic(matrexLogo);
  delay(1000);
  resetGame();
}

void loop() {
  currentMillis = millis();
  if (currentMillis - startMillis >= period)
  {
    matrix.fillScreen(0);
    leftPaddle();
    rightPaddle();
    checkCollisions();
    updateBall();
    drawScreen();
    startMillis = currentMillis;
  }
}

void displayGraphic(uint16_t graphicArray[]) {
  Serial.print(graphicArray[160]);
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      int coord = (16 * y) + x;
      matrix.drawPixel(x, y, graphicArray[coord]);
    }
  }
  matrix.show();
  delay(2000);
  matrix.fillScreen(0);
  matrix.show();
}

void introScreen() {
  displayGraphic(matrexLogo);
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
  
  introScreen();
  blinkBall();
}

void blinkBall() {
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
  leftPaddlePosition = (analogRead(paddle1Pin) / (float)1023) * 13;
}

void rightPaddle() {
  rightPaddlePosition = (analogRead(paddle2Pin) / (float)1023) * 13;
}

void checkCollisions() {
  //top wall
  if ((int)ballYPos <= 0 && ballYVector < 0) {
    ballYVector *= -1;
  }
  
  //bottom wall
  if ((int)ballYPos >= 15 && ballYVector > 0) {
    ballYVector *= -1;
  }
  
  //left/right walls
  if ((int)ballXPos <= 0 || (int)ballXPos >= 15) {
    resetGame();
  }

  //left paddle
  if ((int)ballXPos == 1 && ballXVector < 0) {
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
  if ((int)ballXPos == 14 && ballXVector > 0) {
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
    ballXPos += (float)ballXVector * (float)ballSpeed;
    ballYPos += (float)ballYVector * (float)ballSpeed;
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
