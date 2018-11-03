#include"framework.hpp"
#include"character.hpp"
#include"player.hpp"
#include"block.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class CGame
{
public:
  CGame();
  void init();
  void run();
  void handleEvents();

private:
  CBlock background[29][29];
};
#endif
