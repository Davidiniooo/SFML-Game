#include"sprite.hpp"
#include <string>
class CBlock{

public:
  CBlock();
  void init(std::string inputImage,float xPos,float yPos,float width,float height);
  CSprite getCSprite(){return m_blockSprite;};
  void render();

protected:

  float m_fxPos;
  float m_fyPos;
  float m_fWidth;
  float m_fHeight;
  CSprite m_blockSprite;
  
};
