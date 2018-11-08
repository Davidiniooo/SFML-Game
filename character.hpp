#include"framework.hpp"
#include"sprite.hpp"
#include <math.h>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define UP 1
#define DOWN -1
#define LEFT -1
#define RIGHT 1
#define NO 0

#define ANIMPHASE_STANDING_RIGHT 0
#define ANIMPHASE_WALKING_RIGHT_1 1
#define ANIMPHASE_WALKING_RIGHT_2 2

#define ANIMPHASE_STANDING_LEFT 3
#define ANIMPHASE_WALKING_LEFT_1 4
#define ANIMPHASE_WALKING_LEFT_2 5

class CCharacter{
public:

  CCharacter();
  void init(const std::string texture,float xPos, float yPos,float acceleration, float maxVelocity);
  void render();
  sf::Vector2f getPos();
  void setViewDirection(float degrees);
  void move(int leftright, int updown);
protected:

  float m_fxPos;
  float m_fyPos;

  float m_fAcceeration;
  float m_fMaxVelocity;

  float m_fxVelocity;
  float m_fyVelocity;

  float m_fviewDirection;

  float m_fcurrentAnimPhase;
  CSprite m_pcharacterSprite;
};
#endif
