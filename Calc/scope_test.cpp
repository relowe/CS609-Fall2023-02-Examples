/* Consider the following calc program
x = 1   # ref 1
y = 2

fun f() # ref 2
  x = 3
  z = 6
  q = 7

  fun g()  # ref 3
     z = 12
     h = 21
     y = 1
  end fun

  g()
end fun

f()


    Ref 1     Ref 2    Ref 3
x   3         3        3
y   1         1        1
z   Undef     12       12
q   Undef     7        7
h   Undef     Undef    21
*/
#include <iostream>
#include "ref_env.h"
#include "parse_tree.h"

void print_result(EvalResult val) {
  if(val.type() == UNDEFINED) {
    std::cout << "Undef";
  } else {
    std::cout << val.as_integer();
  }
}

int main() {
  Ref_Env ref1; 
  Ref_Env ref2(&ref1); 
  Ref_Env ref3(&ref2);
  EvalResult value;

  value.set(1);
  ref1.set("x", value);

  value.set(2);
  ref1.set("y", value);

  value.set(3);
  ref2.set("x", value);

  value.set(6);
  ref2.set("z", value);

  value.set(7);
  ref2.set("q", value);

  value.set(12);
  ref3.set("z", value);

  value.set(21);
  ref3.set("h", value);

  value.set(1);
  ref3.set("y", value);

  std::cout << "x: ";
  print_result(ref1.get("x")); 
  std::cout << ", ";
  print_result(ref2.get("x")); 
  std::cout << ", ";
  print_result(ref3.get("x")); 
  std::cout << std::endl;
  
  std::cout << "y: ";
  print_result(ref1.get("y")); 
  std::cout << ", ";
  print_result(ref2.get("y")); 
  std::cout << ", ";
  print_result(ref3.get("y")); 
  std::cout << std::endl;
  
  std::cout << "z: ";
  print_result(ref1.get("z")); 
  std::cout << ", ";
  print_result(ref2.get("z")); 
  std::cout << ", ";
  print_result(ref3.get("z")); 
  std::cout << std::endl;
  
  std::cout << "q: ";
  print_result(ref1.get("q")); 
  std::cout << ", ";
  print_result(ref2.get("q")); 
  std::cout << ", ";
  print_result(ref3.get("q")); 
  std::cout << std::endl;
  
  std::cout << "h: ";
  print_result(ref1.get("h")); 
  std::cout << ", ";
  print_result(ref2.get("h")); 
  std::cout << ", ";
  print_result(ref3.get("h")); 
  std::cout << std::endl;
}