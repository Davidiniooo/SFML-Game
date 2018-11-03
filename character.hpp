#include"framework.hpp"
#include"sprite.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define UP 1
#define DOWN -1
#define LEFT -1
#define RIGHT 1
#define NO 0

class CCharacter{
public:

  CCharacter(float acceleration, float maxVelocity);
  void init(const std::string texture,float xPos, float yPos);
  void render();
  void move(int leftright, int updown);
  sf::Vector2f getPos();
private:
  float m_fxPos;
  float m_fyPos;

  float m_fAcceeration;
  float m_fMaxVelocity;

  float m_fxVelocity;
  float m_fyVelocity;

  CSprite m_playerSprite;
};
#endif
