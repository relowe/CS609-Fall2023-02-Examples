  // File: parse_tree.cpp
// Purpose: Implementation of the parse_tree classes.
#include "parse_tree.h"
#include <iomanip>
#include <iostream>
#include <cmath>

    //////////////////////////////////////////
    // Evaluation Result Type
    //////////////////////////////////////////
    // set the value and infer the type
    void
    EvalResult::set(int _i) {
  _type = INTEGER;
  this->_i = _i;
}

void EvalResult::set(double _d) {
  _type = REAL;
  this->_d = _d;
}

// retrieve results as types
int EvalResult::as_integer() {
  if (_type == INTEGER) {
    return _i;
  } else {
    // TODO: This may be invalid later on
    return (int)_d;
  }
}

double EvalResult::as_real() {
  if (_type == REAL) {
    return _d;
  } else {
    // TODO: This may be invalid later on
    return (double)_i;
  }
}

// retrieve type
EvalType EvalResult::type() { return _type; }

//////////////////////////////////////////
// Base types of operators
//////////////////////////////////////////
UnaryOp::~UnaryOp()
{
  delete child();  
}

Parse_Tree *UnaryOp::child() const { return _child; }

// mutator of the child
void UnaryOp::child(Parse_Tree *_child) { this->_child = _child; }

BinaryOp::~BinaryOp()
{
  delete left();
  delete right();
}

// access and mutators for left child
Parse_Tree *BinaryOp::left() const { return _left; }

void BinaryOp::left(Parse_Tree *_left) { this->_left = _left; }

Parse_Tree *BinaryOp::right() const { return _right; }

void BinaryOp::right(Parse_Tree *_right) { this->_right = _right; }

NaryOp::~NaryOp() {
  for(auto itr = begin(); itr != end(); itr++) {
    delete *itr;
  }
}

// add a child to the list
void NaryOp::add(Parse_Tree *child) { _children.push_back(child); }

// access the ends of the Nary operation
std::vector<Parse_Tree *>::const_iterator NaryOp::begin() const {
  return _children.begin();
}

std::vector<Parse_Tree *>::const_iterator NaryOp::end() const {
  return _children.end();
}

//////////////////////////////////////////
// Operations of Calc
//////////////////////////////////////////

EvalResult Program::eval() {
  EvalResult result;

  // the program executes its children and returns the last eval result
  for (auto itr = begin(); itr != end(); itr++) {
    result = (*itr)->eval();
  }

  return result;
}

void Program::print(int indent) {
  std::cout << std::setw(indent) << "";
  std::cout << "Program" << std::endl;

  // print the children
  for (auto itr = begin(); itr != end(); itr++) {
    (*itr)->print(indent + 1);
  }
}

EvalResult Add::eval() {
  EvalResult result;
  EvalResult l = left()->eval();
  EvalResult r = right()->eval();

  // implement type coercion rules
  // TODO: This might become more complicated
  if (l.type() == REAL or r.type() == REAL) {
    // real evaluation
    double x = l.as_real() + r.as_real();
    result.set(x);
  } else {
    // integer evaluation
    int x = l.as_integer() + r.as_integer();
    result.set(x);
  }

  return result;
}

void Add::print(int indent) {
  right()->print(indent + 1);
  std::cout << std::setw(indent) << "";
  std::cout << "+" << std::endl;
  left()->print(indent + 1);
}

EvalResult Subtract::eval() {
  EvalResult result;
  EvalResult l = left()->eval();
  EvalResult r = right()->eval();

  // implement type coercion rules
  // TODO: This might become more complicated
  if (l.type() == REAL or r.type() == REAL) {
    // real evaluation
    double x = l.as_real() - r.as_real();
    result.set(x);
  } else {
    // integer evaluation
    int x = l.as_integer() - r.as_integer();
    result.set(x);
  }
  return result;
}

void Subtract::print(int indent) {
  right()->print(indent + 1);
  std::cout << std::setw(indent) << "";
  std::cout << "-" << std::endl;
  left()->print(indent + 1);
}

EvalResult Multiply::eval() {

  EvalResult result;
  EvalResult l=left()->eval();
  EvalResult r=right()->eval();
  if(l.type()==REAL or r.type()==REAL){
    double x = l.as_real() * r.as_real();
    result.set(x);
  }
  else{
    int x = l.as_integer() * r.as_integer();
    result.set(x);
  }
  return result;
}

void Multiply::print(int indent) {
  right()->print(indent + 1);
  std::cout << std::setw(indent) << "";
  std::cout << "*" << std::endl;
  left()->print(indent + 1);
}

EvalResult Divide::eval() {
  EvalResult result;
  EvalResult l=left()->eval();
  EvalResult r=right()->eval();
  if (l.type() == REAL or r.type() == REAL) {
    // real evaluation
    double x = l.as_real() / r.as_real();
    result.set(x);
  } else {
    // integer evaluation
    int x = l.as_integer() / r.as_integer();
    result.set(x);
  }

  return result;
}

void Divide::print(int indent) {
  right()->print(indent + 1);
  std::cout << std::setw(indent) << "";
  std::cout << "/" << std::endl;
  left()->print(indent + 1);
}

EvalResult Mod::eval() {
  EvalResult result;

  // TODO: Implement type errors, for now, always do int
  EvalResult l=left()->eval();
  EvalResult r=right()->eval();
  
  // integer evaluation
  int x = l.as_integer() % r.as_integer();
  result.set(x);

  return result;
}

void Mod::print(int indent) {
  right()->print(indent + 1);
  std::cout << std::setw(indent) << "";
  std::cout << "MOD" << std::endl;
  left()->print(indent + 1);
}

EvalResult Power::eval() {
  EvalResult result;
  EvalResult l = left()->eval();
  EvalResult r = right()->eval();

  // Power always yields a real
  result.set(pow(l.as_integer(), r.as_integer()));
  return result;
}

void Power::print(int indent) {
  right()->print(indent + 1);
  std::cout << std::setw(indent) << "";
  std::cout << "^" << std::endl;
  left()->print(indent + 1);
}

EvalResult Negation::eval() {
  EvalResult result;
  EvalResult x = child()->eval();

  if(x.type() == INTEGER) {
    result.set(-x.as_integer());
  } else {
    result.set(-x.as_real());
  }
  
  return result;
}

void Negation::print(int indent) {
  std::cout << std::setw(indent) << "";
  std::cout << "- (Neg)" << std::endl;
  child()->print(indent + 1);
}

EvalResult Literal::eval() {
  EvalResult result;

  if(_tok.tok == INTLIT) {
    result.set(std::stoi(_tok.lexeme));
  } else {
    result.set(std::stof(_tok.lexeme));
  }
  
  return result;
}

Literal::Literal(const Lexer_Token &_tok) { this->_tok = _tok; }

void Literal::print(int indent) {
  std::cout << std::setw(indent) << "";
  std::cout << _tok.lexeme << std::endl;
}