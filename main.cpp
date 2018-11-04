#include"framework.hpp"
#include"game.hpp"
#include<iostream>
int main() {

  g_pFramework->init(1500,1000);

  CGame Game;
  Game.init();
  Game.run();
  return 0;
}
