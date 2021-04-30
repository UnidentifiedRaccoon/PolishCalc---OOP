#include "Tokenizer.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> Tokenizer::tokenize(const string &text) const {
  vector<string> tokens{};
  istringstream input(text);
  for (string token; getline(input, token, delimiter_); /*nothing to do*/) {
    tokens.push_back(token);
  }
  return tokens;
}

Tokenizer::~Tokenizer() {cout << "~Tokenizer" << '\n';}
