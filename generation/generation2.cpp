
#include <iostream>
#include <stdlib.h>
#include <string>

int max_depth;

/*
 * Generate random strings in the language described
 * below:
 *  1.) s -> e
 *  2.) e -> e + e
 *  3.) e -> e - e
 *  4.) e -> e * e
 *  5.) e -> e / e
 *  6.) e -> n
 *  7.) n -> nd 
 *  8.) n -> d
 *  9.) d -> 0
 * 10.) d -> 1
 */

// randomly select an integer [min, max]
int select_rule(int min, int max, int depth) {
    if(depth >= max_depth) {
        return max;
    }
    return rand() % (max-min + 1) + min;
}


///////////////////////////////////////////////////////////////////////////
// Non-Terminal Functions
///////////////////////////////////////////////////////////////////////////
std::string s(int depth);
std::string e(int depth);
std::string n(int depth);
std::string d(int depth);

std::string s(int depth)
{
    return e(depth);
}


std::string e(int depth)
{
 /* E's rules:
  *  2.) e -> e + e
  *  3.) e -> e - e
  *  4.) e -> e * e
  *  5.) e -> e / e
  *  6.) e -> n
  */
  switch(select_rule(2,6,depth)) {
      case 2:
        return e(depth+1) + " + " + e(depth+1);
        break;
      case 3:
        return e(depth+1) + " - " + e(depth+1);
        break;
      case 4:
        return e(depth+1) + " * " + e(depth+1);
        break;
      case 5:
        return e(depth+1) + " / " + e(depth+1);
        break;
      case 6:
        return n(depth);
        break;
  }   
  return "";
}


std::string n(int depth)
{
  /*
   *  7.) n -> nd 
   *  8.) n -> d
   */  
  switch(select_rule(7, 8, depth)) {
      case 7:
        return n(depth+1) + d(depth);
        break;
      case 8:
        return d(depth);
  }
  return "";
}


std::string d(int depth)
{
  /*
   *  9.) d -> 0
   * 10.) d -> 1
   */
  switch(select_rule(9, 10, depth)) {
      case 9:
        return "0";
        break;
      case 10:
        return "1";
        break;
  }

  return "";
}


int main()
{
    /* forever loop */
    for(;;) {
        std::cout << "Max Depth=";
        std::cin >> max_depth;
        std::cout << s(1) << std::endl;
    }
}