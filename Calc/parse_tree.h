 // File: parse_tree.h
// Purpose: Contain the definitions of the parse tree classes.
#include <vector>
#include "lexer.h"

//////////////////////////////////////////
// Pure Virtual Parse Tree Class
//  (abstract)
//////////////////////////////////////////
class Parse_Tree {
public:
  // debug method to print the parse tree at a given indentation
  virtual void print(int indent)=0;
};


//////////////////////////////////////////
// Base types of operators
//////////////////////////////////////////
class UnaryOp : public Parse_Tree {
public:
  // access to the child
  virtual Parse_Tree *child() const;

  // mutator of the child
  virtual void child(Parse_Tree *_child);
private:
  Parse_Tree *_child;
};


class BinaryOp : public Parse_Tree {
public:
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
  virtual void print(int indent);
};


class Add : public BinaryOp {
public:
  virtual void print(int indent);
};


class Subtract : public BinaryOp {
public:
  virtual void print(int indent);
};


class Multiply : public BinaryOp {
public:
  virtual void print(int indent);
};


class Divide : public BinaryOp {
public:
  virtual void print(int indent);
};


class Mod : public BinaryOp {
public:
  virtual void print(int indent);
};


class Power : public BinaryOp {
public:
  virtual void print(int indent);
};


class Negation : public UnaryOp {
public:
  virtual void print(int indent);
};


class Literal : public Parse_Tree {
public:
  Literal(const Lexer_Token &_tok);

  virtual void print(int indent);
private:
  Lexer_Token _tok;
};