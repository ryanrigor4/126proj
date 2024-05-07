#include "game.h"
#include "leaderBoard.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
  string input;
  bool end = false;
  leaderBoard board1;
  int score;
  string name;
  cout << "Welcome to the Number Guessing Game!" << endl;
  while (end != true) {
    cout << "1 - Play" << endl;
    cout << "2 - View Scores" << endl;
    cout << "3 - Quit" << endl;
    cin >> input;
    if(input == "1") {
      score = game();
      cout << "Your score is: " << score << endl;
      cout << "Enter name: ";
      cin >> name;
      playerScore playerToAdd;
      playerToAdd.setName (name);
      playerToAdd.setScore (score);
      cout << playerToAdd.getName() << endl;
      board1.addPlayer(playerToAdd);
    }
    else if(input == "2") {
      cout << "Scores" << endl;
      board1.displayLeaderBoard();
      cout << endl;
    }
    else if(input == "3") {
      end = true;
    }
    else{
      cout << "Invalid input" << endl;
    }
  }
}