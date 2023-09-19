
#include <iostream>
#include <stdlib.h>
#include <string>

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
int select_rule(int min, int max) {
    return rand() % (max-min + 1) + min;
}


///////////////////////////////////////////////////////////////////////////
// Non-Terminal Functions
///////////////////////////////////////////////////////////////////////////
std::string s();
std::string e();
std::string n();
std::string d();

std::string s()
{
    return e();
}


std::string e()
{
 /* E's rules:
  *  2.) e -> e + e
  *  3.) e -> e - e
  *  4.) e -> e * e
  *  5.) e -> e / e
  *  6.) e -> n
  */
  switch(select_rule(2,6)) {
      case 2:
        return e() + " + " + e();
        break;
      case 3:
        return e() + " - " + e();
        break;
      case 4:
        return e() + " * " + e();
        break;
      case 5:
        return e() + " / " + e();
        break;
      case 6:
        return n();
        break;
  }   
  return "";
}


std::string n()
{
  /*
   *  7.) n -> nd 
   *  8.) n -> d
   */  
  switch(select_rule(7, 8)) {
      case 7:
        return n() + d();
        break;
      case 8:
        return d();
  }
  return "";
}


std::string d()
{
  /*
   *  9.) d -> 0
   * 10.) d -> 1
   */
  switch(select_rule(9, 10)) {
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
    std::cout << s() << std::endl;
}