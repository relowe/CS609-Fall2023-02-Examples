
// File: parser.cpp
// Purpose: Implementation of the parser class.
#include "parser.h"
#include <iostream>

// construct a parser for a given lexer
Parser::Parser(Lexer *_lex) {
  // get the lexer
  this->_lex = _lex;

  // make sure the lexer has a token
  _lex->next();
}

// attempt to parse the program
Parse_Tree* Parser::parse() { return parse_Program(); }

////////////////////////////////////////
// Lexer Convenience Interface
////////////////////////////////////////

// return true if we have the given token in the buffer, false otherwise
bool Parser::has(Token tok) { return _lex->cur().tok == tok; }

// return true if we have the given token, report error otherwise
// this will terminate the program on error
bool Parser::must_be(Token tok) {
  // if we have this, everything is good
  if (has(tok)) {
    return true;
  }

  // if we make it here, that's an error
  std::cerr << "Parse Error: Unexpected Token " << _lex->cur() << std::endl;
  exit(-1);
}

// return the current token and advance the lexer
Lexer_Token Parser::consume() {
  Lexer_Token t = _lex->cur();
  _lex->next();

  return t;
}

////////////////////////////////////////
// Recursive Descent Parser Rules
////////////////////////////////////////

/*
< Program >    ::= < Statement > < Program' >

< Program' >   ::= < Statement > < Program' >
                   | ""
 */
Parse_Tree *Parser::parse_Program() {
  Program *result = new Program();
  
  // effectively, this reads statements until EOI
  while (not has(EOI)) {
    result->add(parse_Statement());
  }

  return result;
}

/*
< Statement >  ::= < Expression > NEWLINE
 */
// If a expression is followed by newline, then consume it and parse the
// expression if not the system will report the error and exit.
Parse_Tree* Parser::parse_Statement() {
  Parse_Tree *result = parse_Expression();
  if (must_be(NEWLINE)) {
    consume();
  }

  return result;
}

/*
< Expression > ::= < Term > < Expression' >
 */
Parse_Tree* Parser::parse_Expression() {
  Parse_Tree *left = parse_Term();
  return parse_Expression2(left);
}

/*
< Expression' > ::= PLUS < Term > < Expression' >
                    | MINUS < Term > < Expression' >
                    | ""
 */
Parse_Tree* Parser::parse_Expression2(Parse_Tree *left) {
  if (has(PLUS)) {
    // consume the plus
    consume();
    Add *result = new Add();
    result->left(left);
    result->right(parse_Term());
    return parse_Expression2(result);
  } else if (has(MINUS)) {
    // consume the minus
    consume();
    Subtract *result = new Subtract();
    result->left(left);
    result->right(parse_Term());
    return parse_Expression2(result);
  }

  // do nothing on ""
  return left;
}

/*
< Term >       ::=  < Factor > < Term' >
 */
Parse_Tree* Parser::parse_Term() {
  Parse_Tree *left = parse_Factor();
  return parse_Term2(left);
}

/*
< Term' >      ::=  TIMES < Factor > < Term' >
                  | DIVIDE < Factor > < Term' >
                  | MOD < Factor > < Term' >
                  | ""
 */
Parse_Tree* Parser::parse_Term2(Parse_Tree *left) {
  if (has(TIMES)) {
    consume();
    Multiply *result = new Multiply();
    result->left(left);
    result->right(parse_Factor());
    return parse_Term2(result);
  } else if (has(DIVIDE)) {
    consume();
    Divide *result = new Divide();
    result->left(left);
    result->right(parse_Factor());
    return parse_Term2(result);
  } else if (has(MOD)) {
    consume();
    Mod *result = new Mod();
    result->left(left);
    result->right(parse_Factor());
    return parse_Term2(result);
  }
  
  return left;
}

/*
< Factor >       ::= < Base > < Factor' >
 */
Parse_Tree* Parser::parse_Factor() {
  Parse_Tree *left = parse_Base();
  return parse_Factor2(left);
} 

/*
< Factor' >      ::= POW < Factor >
                     | ""
 */
Parse_Tree* Parser::parse_Factor2(Parse_Tree *left) {
  if (has(POW)) {
    consume();
    Power *result = new Power();
    result->left(left);
    result->right(parse_Factor());
    return result;
  }
  
  return left;
}

/*
< Base >         ::= LPAREN < Expression > RPAREN
                     | MINUS < Expression >
                     | < Number >
 */
Parse_Tree* Parser::parse_Base() {
  if (has(LPAREN)) {
    consume();
    Parse_Tree *result = parse_Expression();
    must_be(RPAREN);
    consume();
    return result;
  } else if (has(MINUS)) {
    consume();
    Negation *result = new Negation();
    result->child(parse_Expression());
    return result;
  } else {
    return parse_Number();
  }
}

/*
< Number >       ::= INTLIT
                     | REALLIT
 */
Parse_Tree* Parser::parse_Number() {
  if (has(INTLIT)) {
    return new Literal(consume());
  } else if (must_be(REALLIT)) {
    consume();
    return new Literal(consume());
  }
  
  return nullptr;
}