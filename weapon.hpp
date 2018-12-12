#include"sprite.hpp"

class CWeapon{

public:
  CWeapon();
  void init(const std::string texture,float xPos, float yPos);
  void setRotation(float degrees);
  void render();
  void shoot();
private:
  float m_fxPos;
  float m_fyPos;

  float m_fRotation;
  CSprite m_weaponSprite;
};
