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
  int partition(string unsortedNames[], int low, int high);
  void quickSort(string unsortedNames[], int low, int high);
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
    string unsortedNames[names[i].size()];
    int index = 0;
    for (auto it = names[i].begin(); it != names[i].end(); it++) {
      unsortedNames[index] = (*it)->getName();
      index++;
    }
    quickSort(unsortedNames, 0, names[i].size() - 1);
    for (int j = 0; j < names[i].size(); j++) {
      for (auto it = names[i].begin(); it != names[i].end(); it++) {
        if ((*it)->getName() == unsortedNames[j]) {
          cout << *(*it) << endl;
        }
      }
    }
  }
}


int leaderBoard::partition(string unsortedNames[], int low, int high) {
  string pivot = unsortedNames[high];
  int i = low - 1;
  for (int j = low; j <= high; j++) {
    if (unsortedNames[j] < pivot) {
      i++;
      swap(unsortedNames[i], unsortedNames[j]);
    }
  }
  swap(unsortedNames[i + 1], unsortedNames[high]);
  return i + 1;
}

void leaderBoard::quickSort(string unsortedNames[], int low, int high) {
  if (low < high) {
    int pivot = partition(unsortedNames, low, high);
    quickSort(unsortedNames, low, pivot - 1);
    quickSort(unsortedNames, pivot + 1, high);
  }
}

#endif