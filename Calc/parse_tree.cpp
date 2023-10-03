// File: parse_tree.cpp
// Purpose: Implementation of the parse_tree classes.
#include <iostream>
#include <iomanip>
#include "parse_tree.h"

//////////////////////////////////////////
// Base types of operators
//////////////////////////////////////////
Parse_Tree *UnaryOp::child() const
{
  return _child;  
}

// mutator of the child
void UnaryOp::child(Parse_Tree *_child)
{
  this->_child = _child;
}

// access and mutators for left child
Parse_Tree *BinaryOp::left() const
{
  return _left;
}

void BinaryOp::left(Parse_Tree *_left)
{
  this->_left = _left;
}

Parse_Tree *BinaryOp::right() const
{
  return _right;
}

void BinaryOp::right(Parse_Tree *_right)
{
  this->_right = _right;
}


// add a child to the list
void NaryOp::add(Parse_Tree *child)
{
  _children.push_back(child);
}

// access the ends of the Nary operation
std::vector<Parse_Tree*>::const_iterator NaryOp::begin() const
{
  return _children.begin();
}

std::vector<Parse_Tree*>::const_iterator NaryOp::end() const
{
  return _children.end();
}


//////////////////////////////////////////
// Operations of Calc
//////////////////////////////////////////
void Program::print(int indent)
{
  std::cout << std::setw(indent) << "";
  std::cout << "Program" << std::endl; 

  // print the children
  for(auto itr = begin(); itr != end(); itr++) {
    (*itr)->print(indent + 1);
  }  
}


void Add::print(int indent)
{
  right()->print(indent+1);  
  std::cout << std::setw(indent) << "";
  std::cout << "+" << std::endl;
  left()->print(indent+1);
}


void Subtract::print(int indent)
{
  right()->print(indent+1);  
  std::cout << std::setw(indent) << "";
  std::cout << "-" << std::endl;
  left()->print(indent+1);
}


void Multiply::print(int indent)
{
  right()->print(indent+1);  
  std::cout << std::setw(indent) << "";
  std::cout << "*" << std::endl;
  left()->print(indent+1);
}


void Divide::print(int indent)
{
  right()->print(indent+1);  
  std::cout << std::setw(indent) << "";
  std::cout << "/" << std::endl;
  left()->print(indent+1);
}


void Mod::print(int indent)
{
  right()->print(indent+1);  
  std::cout << std::setw(indent) << "";
  std::cout << "MOD" << std::endl;
  left()->print(indent+1);
}


void Power::print(int indent)
{
  right()->print(indent+1);  
  std::cout << std::setw(indent) << "";
  std::cout << "^" << std::endl;
  left()->print(indent+1);
}


void Negation::print(int indent)
{
  std::cout << std::setw(indent) << "";
  std::cout << "- (Neg)" << std::endl;
  child()->print(indent+1);
}


Literal::Literal(const Lexer_Token &_tok)
{
  this->_tok = _tok;
}


void Literal::print(int indent)
{
  std::cout << std::setw(indent) << "";
  std::cout << _tok.lexeme << std::endl;
}