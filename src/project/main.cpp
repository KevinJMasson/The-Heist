#include<iostream>
#include"Game.h"



int main() {
  char in;
  Game g;
  do {
  g.playGame();
  std::cout << "Play again? y for yes, anything else for no.\n";
  std::cin >> in;
  std::cout << std::endl;
} while (in == 'y' || in == 'Y');

  return 0;
}
