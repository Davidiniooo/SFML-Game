#include "framework.hpp"
#include "character.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class CPlayer{

public:
  CPlayer(CCharacter* character);
  void checkKeyboard();
  void moveCamera();
private:
  CCharacter* m_playerCharacter;
};
#endif
