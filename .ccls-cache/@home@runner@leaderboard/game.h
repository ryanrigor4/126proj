#include <ctime>
#include <iostream>
#include <queue>
#include <stack>

struct GuessInfo {
  int guess;
  std::string message;
  GuessInfo(int g, const std::string &m) : guess(g), message(m) {}
};

int game() {
  srand(time(0));
  int target = rand() % 10 + 1;
  int guess;
  int guessCount = 0;
  std::queue<GuessInfo> guessQueue;
  std::stack<GuessInfo> guessStack;

  std::cout << "Guess a number between 1 and 10 (enter 'h' for history): ";
  do {
    std::string input;
    std::cin >> input;
    if (input == "h") {
      if (!guessStack.empty()) {
        std::cout << "History of guesses:" << std::endl;
        std::stack<GuessInfo> tempStack = guessStack;
        while (!tempStack.empty()) {
          GuessInfo info = tempStack.top();
          std::cout << "Guess: " << info.guess << ", Message: " << info.message
                    << std::endl;
          tempStack.pop();
        }

        std::cout
            << "Guess a number between 1 and 10 (enter 'h' for history): ";

      } else {
        std::cout << "No guesses made yet." << std::endl;
      }
      continue;
    }

    try {
      guess = std::stoi(input);
      guessCount++;
      GuessInfo newGuess(guess, "");
      if (guess < target) {
        newGuess.message = "Too low";
        std::cout << "Too low, try again: ";
      } else if (guess > target) {
        newGuess.message = "Too high";
        std::cout << "Too high, try again: ";
      } else {
        newGuess.message = "Correct!";
        std::cout << "Correct! You guessed the number in " << guessCount
                  << " tries.\n";
      }
      guessQueue.push(newGuess);
      guessStack.push(newGuess);
    } catch (std::invalid_argument &e) {
      std::cout << "Invalid input, try again: ";
    }
  } while (guess != target);

  std::cout << "Your score is: " << guessCount << std::endl;

  std::cout << "Summary of guesses:" << std::endl;
  while (!guessQueue.empty()) {
    GuessInfo info = guessQueue.front();
    std::cout << "Guess: " << info.guess << ", Message: " << info.message
              << std::endl;
    guessQueue.pop();
  }

  return guessCount;
}
