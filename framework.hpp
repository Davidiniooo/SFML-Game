#include"timer.hpp"

#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework>
{
public:
  CFramework();
  void init(int width,int height);
  void render();
  void checkEvents();
  sf::RenderWindow *getWindow(){return window;}
private:
  sf::RenderWindow *window;
  sf::Event event;
};
#endif
