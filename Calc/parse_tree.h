 // File: parse_tree.h
// Purpose: Contain the definitions of the parse tree classes.
#ifndef PARSE_TREE_H
#define PARSE_TREE_H
#include <vector>
#include "lexer.h"

//////////////////////////////////////////
// Evaluation Result Type 
//////////////////////////////////////////
enum EvalType {INTEGER, REAL};

class EvalResult {
public:
  // set the value and infer the type
  virtual void set(int _i);
  virtual void set(double _d);

  // retrieve results as types
  virtual int as_integer();
  virtual double as_real();

  // retrieve type
  virtual EvalType type();

private:
  int _i;         // integer field
  double _d;      // real field
  EvalType _type; // the type of the result
};

//////////////////////////////////////////
// Pure Virtual Parse Tree Class
//  (abstract)
//////////////////////////////////////////
class Parse_Tree {
public:
  // evaluate the parse tree
  virtual EvalResult eval()=0;

  // debug method to print the parse tree at a given indentation
  virtual void print(int indent)=0;
};


//////////////////////////////////////////
// Base types of operators
//////////////////////////////////////////
class UnaryOp : public Parse_Tree {
public:
  // destructor
  ~UnaryOp();

  // access to the child
  virtual Parse_Tree *child() const;

  // mutator of the child
  virtual void child(Parse_Tree *_child);
private:
  Parse_Tree *_child;
};


class BinaryOp : public Parse_Tree {
public:
  // destructor
  ~BinaryOp();

  // access and mutators for left child
  virtual Parse_Tree *left() const;
  virtual void left(Parse_Tree *_left);

  // access and mutators for right child
  virtual Parse_Tree *right() const;
  virtual void right(Parse_Tree *_right);
private:
  Parse_Tree *_left;
  Parse_Tree *_right;
};


class NaryOp : public Parse_Tree {
public:
  ~NaryOp();

  // add a child to the list
  virtual void add(Parse_Tree *child);

  // access the ends of the Nary operation
  std::vector<Parse_Tree*>::const_iterator begin() const;
  std::vector<Parse_Tree*>::const_iterator end() const;
private:
  std::vector<Parse_Tree *> _children;
};


//////////////////////////////////////////
// Operations of Calc
//////////////////////////////////////////
class Program : public NaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Add : public BinaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Subtract : public BinaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Multiply : public BinaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Divide : public BinaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Mod : public BinaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Power : public BinaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Negation : public UnaryOp {
public:
  virtual EvalResult eval();
  virtual void print(int indent);
};


class Literal : public Parse_Tree {
public:
  Literal(const Lexer_Token &_tok);

  virtual EvalResult eval();
  virtual void print(int indent);
private:
  Lexer_Token _tok;
};
#endif