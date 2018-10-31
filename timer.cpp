#include"timer.hpp"


CTimer::CTimer(){

}

float CTimer::getElapsed(){
  elapsed = clock.getElapsedTime();
  float timeasfloat= elapsed.asMilliseconds();
  reset();

  return timeasfloat;
}
void CTimer::reset(){
  clock.restart();
}
