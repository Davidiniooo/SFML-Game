#include"sprite.hpp"

#ifndef SHOT_HPP
#define SHOT_HPP

class CShot{

public:
  CShot();
  void init(float xPos, float yPos, float speed,float viewDirection);
  void move();
  void render();
private:
  float m_fxPos;
  float m_fyPos;

  float m_fviewDirection;
  float m_fspeed;

  CSprite m_shotSprite;
};
#endif
