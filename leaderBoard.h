#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "binaryTree.h"
#include "playerScore.h"
#include <list>
#include <iostream>

using namespace std;

class leaderBoard {
public:
  void addPlayer(playerScore &player);
  void displayLeaderBoard();
  void byScores();
  void byName();
private:
  binaryTree<playerScore *> scores;
  list<playerScore *> names[26];
};

void leaderBoard::addPlayer(playerScore &player) {
  playerScore *temp = new playerScore;
  temp->setScore(player.getScore());
  temp->setName(player.getName());
  scores.insert(temp);
  names[tolower(temp->getName()[0]) % 25].push_back(temp);
}

void leaderBoard::displayLeaderBoard() { 
  int input = 0;
  while (input != 3) {
    cout << "1 - Display by score" << endl;
    cout << "2 - Display by name" << endl;
    cout << "3 - Cancel" << endl;
    cin >> input;
    switch (input) {
      case 1:
        cout << "Scores:" << endl;
        byScores();
        break;
      case 2:
        cout << "Scores:" << endl;
        byName();
        break;
      case 3:
        break;
      default:
        cout << "Invalid input" << endl;
        break;
    }
  }
}

void leaderBoard::byScores() {
  scores.inorderTraverse();
}

void leaderBoard::byName() {
  for (int i = 0; i < 26; i++) {
    for (auto it = names[i].begin(); it != names[i].end(); it++) {
      cout << *(*it) << endl;
    }
  }
}

#endif