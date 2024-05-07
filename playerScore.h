#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <string>

using namespace std;

class playerScore {
public:
  playerScore();
  playerScore(string name, const int score);
  void setScore(const int score);
  void setName(const string name);
  int getScore();
  string getName();
  friend ostream &operator<<(ostream &os, const playerScore &player);
  playerScore operator>(const playerScore &other);
  void operator=(const playerScore &copy);
private:
  int score;
  string name;
};

playerScore::playerScore() {
  score = 0;
  name = "";
}

playerScore::playerScore(string name, const int score) {
  this->score = score;
  this->name = name;
}

void playerScore::setScore(const int score) { 
  this->score = score; 
}

void playerScore::setName(const string name) { 
  this->name = name; 
}

int playerScore::getScore() { 
  return this->score; 
}

string playerScore::getName() { 
  return this->name; 
}

ostream &operator<<(ostream &os, playerScore *player) {
  string out = player->getName() + " " + to_string(player->getScore());
  os << out;
  return os;
}

playerScore playerScore::operator>(const playerScore &other) {
  if (score > other.score) {
    return *this;
  } else {
    return other;
  }
}

void playerScore::operator=(const playerScore& copy) {
  score = copy.score;
  name = copy.name;
}

#endif