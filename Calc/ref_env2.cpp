// File: ref_env.cpp
// Purpose: A reference environment class implementation.
#include <map>
#include <string>
#include "parse_tree.h"
#include "ref_env.h"

Ref_Env::Ref_Env() : Ref_Env(nullptr)
{
  // nothing to do here
}


Ref_Env::Ref_Env(Ref_Env *_parent) {
  parent(_parent);
}


// Add a name to the current scope
void Ref_Env::declare(const std::string &name)
{
  _symbol_table[name] = EvalResult();
}


// Bind a value to a name
void Ref_Env::set(const std::string &name, const EvalResult &value)
{
  EvalResult *ptr = lookup(name);
  
  if(ptr!= nullptr) {
    //inserting in an enclosing scope
    *ptr = value;
  } else {
    //inserting in a local scope
    _symbol_table[name] = value;
  }
}

// Retrieve a bound name
EvalResult Ref_Env::get(const std::string &name)
{
  EvalResult *ptr = lookup(name);
  
  if(ptr != nullptr) {
    return *ptr;
  }

  // if we make it here, we did not find the variable
  EvalResult result;
  result.set_type(UNDEFINED);
  return result;
}


// Access the parent
Ref_Env *Ref_Env::parent() {
  return _parent;
}

// Modify the parent
void Ref_Env::parent(Ref_Env *_parent)
{
  this->_parent = _parent;
}


// Lookup a name recursively
EvalResult* Ref_Env::lookup(const std::string &name)
{
  if(_symbol_table.find(name) != _symbol_table.end()) {
    // we have found the varaible
    return &(_symbol_table[name]);
  }

  // if we don't have it, maybe our parent does
  if(parent() != nullptr) {
    return parent()->lookup(name);
  }

  return nullptr;
}