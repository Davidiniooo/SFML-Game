#include"framework.hpp"
#include"game.hpp"
#include<iostream>
int main() {

  g_pFramework->init(1900,1200);
  
  CGame Game;
  Game.run();
  return 0;
}
