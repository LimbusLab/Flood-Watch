#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;

float xzThresh = 0.4;
float yThresh = 9.90;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  X = 0;
  Y = 0;
  Z = 0;
  int numberReadings = 10;
  for (int j = 0; j < numberReadings; j++) {
    X += abs(CircuitPlayground.motionX());
    Y += abs(CircuitPlayground.motionY());
    Z += abs(CircuitPlayground.motionZ());
    delay(50);
  }
  X = X / numberReadings;
  Y = Y / numberReadings;
  Z = Z / numberReadings;

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);

  if (X < xzThresh && Z < xzThresh && Y >= yThresh) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i,   0, 255,   0);
    }
  }
  else if(X >= xzThresh && Z < xzThresh){
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i,   255, 0,   0);
    }
  }
  else if(Z >= xzThresh && X < xzThresh){
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i,   0, 0,   255);
    }
  }
  else if(Z >= xzThresh && X >= xzThresh){
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i,   255, 0,   255);
    }
  }
  else CircuitPlayground.clearPixels();

  //delay(500);
}
