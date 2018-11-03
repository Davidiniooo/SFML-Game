#include"block.hpp"

CBlock::CBlock(){
  m_fxPos = 0;
  m_fyPos = 0;
  m_fWidth = 0;
  m_fHeight =0;
}

void CBlock::init(std::string inputImage,float xPos,float yPos,float width,float height){
  m_blockSprite.init(inputImage,width,height);

}

void CBlock::render(){
  m_blockSprite.render();
}
