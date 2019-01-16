#include"sprite.hpp"

#ifndef WEAPON_HPP
#define WEAPON_HPP
class CWeapon{

public:
  CWeapon();
  void init(const std::string texture,float xPos, float yPos);
  void setRotation(float degrees);
  void setPosition(float xPos,float yPos);
  void render();
  void shoot();
private:
  float m_fxPos;
  float m_fyPos;
  float m_fWidth;
  float m_fHeight;

  float m_fRotation;
  CSprite m_weaponSprite;

};
#endif
