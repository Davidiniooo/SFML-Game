#include "framework.hpp"
#include "character.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class CPlayer{

public:
  CPlayer(CCharackter* character);
  void checkKeyboard();
private:
  CCharackter* m_playerCharacter;
};
#endif
