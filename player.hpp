#include "framework.hpp"
#include "character.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class CPlayer{

public:
  CPlayer(CCharacter* player);
  void checkKeyboard();
  void moveCamera();
private:
  CCharacter* m_pCharacter;
};
#endif
