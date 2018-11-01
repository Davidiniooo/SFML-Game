#include "framework.hpp"
#include "character.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class CPlayer{

public:
  CPlayer(CCharackter* character);
  void checkKeyboard();
  void moveCamera();
private:
  CCharackter* m_playerCharacter;
};
#endif
