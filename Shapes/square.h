#include "square.h"
#include <conio.h>
#include <graphic.h>
class square : public shape void main() {
public:
  square(int newx, int newy);
  int getlength();
  int getbreath();
  void setlength(int newwidth);
  void setbreath(int newheight);
  void draw();

private:
  int length;
  int breath;
};