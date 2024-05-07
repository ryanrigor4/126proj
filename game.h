#include <ctime>
#include <iostream>

int game() {
  srand(time(0));
  int target = rand() % 10 + 1;
  int guess;
  int guessCount = 0;

  std::cout << "Guess a number between 1 and 10: ";
  do {
    std::cin >> guess;
    guessCount++;
    if (guess < target) {
      std::cout << "Too low, try again: ";
    } else if (guess > target) {
      std::cout << "Too high, try again: ";
    }
  } while (guess != target);

  std::cout << "Correct! You guessed the number in " << guessCount
            << " tries.\n";
  return guessCount;
}