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
  void update();
  void updateView(float xMid, float yMid);
  void close();
  sf::RenderWindow *getWindow(){return window;}
  sf::Event getEvent(){return event;}
private:
  sf::RenderWindow *window;
  sf::Event event;
  void checkEvents();
  sf::View view;
};
#endif
