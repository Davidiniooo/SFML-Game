#include"game.hpp"
#include<iostream>


void CGame::run(){

  CCharackter Solider(0.1f);
  Solider.init("test.png",100,10);

  CPlayer Player(&Solider);

  float secondsGone = 0;

  while(g_pFramework->getWindow()->isOpen()==true)
    {

      g_pFramework->update();
      secondsGone += g_pTimer->getElapsed();
      std::cout << secondsGone << '\n';
      handleEvents();
      Player.checkKeyboard();
      Solider.render();
      g_pFramework->render();
    }

}

CGame::CGame(){}

void CGame::handleEvents(){

  switch (g_pFramework->getEvent().type)
  {
    case (sf::Event::Closed):
    {
      g_pFramework->close();
    }
      break;

  }
}
