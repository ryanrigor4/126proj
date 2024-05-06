#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "binaryTree.h"
#include "playerScore.h"
#include <list>

class leaderBoard {
public:
  void addPlayer(const playerScore &player);
  void displayLeaderBoard();

private:
  binaryTree<playerScore *> scores;
  list<playerScore *> names[26];
};

void leaderBoard::addPlayer(const playerScore &player) {
  playerScore temp = player;
  scores.insert(&temp);
  names[temp.getName()[0] - 'A' % 26].push_back(&temp);
}

void leaderBoard::displayLeaderBoard() { scores.inorderTraverse(); }

#endif