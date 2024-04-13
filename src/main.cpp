#include <iostream>
#include <iomanip>
#include <cmath>

int getHeightUserInput() {
  std::cout << "Enter the height of the tower in meters: ";
  int height{};
  std::cin >> height;
  return height;
}

double getCurrentHeight(int seconds, int height) {
  const float GRAVITY = 9.81f;
  const float secondsFloat = static_cast<float>(seconds);
  const double distanceFallen = GRAVITY * (secondsFloat * secondsFloat) / 2.0;
  return height - distanceFallen;
}

void printCurrentHeight(int seconds, double height) {
  if (height <= 0.0) {
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
  } else {
    std::cout << "At " << seconds << " seconds, the ball is at height: ";
    if (height == std::round(height)) {
      std::cout << std::fixed << std::setprecision(0) << height << " meters\n";
    } else {
      std::cout << std::fixed << std::setprecision(1) << height << " meters\n";
    }
  }
}

int main() {
  const int initial_height{ getHeightUserInput() };
  const int INITIAL_SECONDS = 5;
  double currentHeight{};
  for (int i = 0; i <= INITIAL_SECONDS; i++) {
    currentHeight = getCurrentHeight(i, initial_height);
    printCurrentHeight(i, currentHeight);
  }
  return 0;
}
