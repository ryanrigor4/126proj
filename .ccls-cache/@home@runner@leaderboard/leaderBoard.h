#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "binaryTree.h"
#include "playerScore.h"
#include <list>

class leaderBoard {
public:
  void addPlayer(playerScore &player);
  void displayLeaderBoard();

private:
  binaryTree<playerScore *> scores;
  list<playerScore *> names[26];
};

void leaderBoard::addPlayer(playerScore &player) {
  playerScore *temp = new playerScore;
  temp->setScore(player.getScore());
  temp->setName(player.getName());
  scores.insert(temp);
  //names[temp.getName()[0] - 'A' % 26].push_back(&temp);
}

void leaderBoard::displayLeaderBoard() { 
  scores.inorderTraverse();
}

#endif