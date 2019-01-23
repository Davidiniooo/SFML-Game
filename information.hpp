#ifndef INFORMATION_HPP
#define INFORMATION_HPP

#include<list>
#include"shot.hpp"
#include"character.hpp"
#include"obstacle.hpp"
#include"singleton.hpp"

#define g_pInformation CInformation::Get()

class CInformation : public TSingleton<CInformation>
{
friend class CGame;
public:
  CInformation();
  void addShot(CShot* pShot);
  void addObstacle(CObstacle* pObstacle);
  void addCharacter(CCharacter* m_pCharacter);

private:

  std::list<CCharacter*> characterList;
  std::list<CObstacle*> obstacleList;
  std::list<CShot*> shotList;

};
#endif
