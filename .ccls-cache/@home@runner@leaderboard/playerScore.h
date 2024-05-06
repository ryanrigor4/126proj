#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <string>

using namespace std;

class playerScore {
public:
  playerScore();
  playerScore(const string name, const int score);
  void setScore(const int score);
  void setName(const string name);
  int getScore();
  string getName();
  friend ostream &operator<<(ostream &os, const playerScore &player);
  playerScore operator>(const playerScore &other);

private:
  int score;
  string name;
};

playerScore::playerScore() {
  score = 0;
  name = "";
}

playerScore::playerScore(const string name, const int score) {
  this->score = score;
  this->name = name;
}

void playerScore::setScore(const int score) { this->score = score; }

void playerScore::setName(const string name) { this->name = name; }

int playerScore::getScore() { return score; }

string playerScore::getName() { return name; }

ostream &operator<<(ostream &os, const playerScore &player) {
  playerScore temp = player;
  string out = temp.getName() + " " + to_string(temp.getScore());
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

#endif