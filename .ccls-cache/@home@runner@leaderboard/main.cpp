#include "game.h"
#include "leaderBoard.h"
#include <iostream>

int main() {
  std::string input;
  bool end = false;
  leaderBoard board1;
  int score;
  std::string name;
  std::cout << "Welcome to the Number Guessing Game!" << std::endl;
  while (end != true) {
    std::cout << "1 - Play" << std::endl;
    std::cout << "2 - View Scores" << std::endl;
    std::cout << "3 - Quit" << std::endl;
    std::cin >> input;
    if(input == "1") {
      score = game();
      std::cout << "Your score is: " << score << std::endl;
      std::cout << "Enter name: ";
      std::cin >> name;
      playerScore playerToAdd(name, score);
      board1.addPlayer(playerToAdd);
    }
    else if(input == "2") {
      std::cout << "Scores" << std::endl;
      board1.displayLeaderBoard();
      std::cout << std::endl;
    }
    else if(input == "3") {
      end = true;
    }
    else{
      std::cout << "Invalid input" << std::endl;
    }
  }
}