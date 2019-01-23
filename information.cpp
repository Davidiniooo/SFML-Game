#include"information.hpp"

CInformation::CInformation(){

}
void CInformation::addShot(CShot* pShot){
  shotList.push_back(pShot);
}

void CInformation::addObstacle(CObstacle* pObstacle){
  obstacleList.push_back(pObstacle);
}

void CInformation::addCharacter(CCharacter* pCharacter){
  characterList.push_back(pCharacter);
}
