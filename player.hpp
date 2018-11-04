#include "framework.hpp"
#include "character.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class CPlayer : public CCharacter{

public:

  void checkKeyboard();
  void moveCamera();
private:
};
#endif
