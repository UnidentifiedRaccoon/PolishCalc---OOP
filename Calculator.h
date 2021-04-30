#pragma once

#include "Parser.h"
#include "Tokenizer.h"
#include <string>

class Calculator {
    Tokenizer *tokenizer_;
    Parser *parser_;

public:
    explicit Calculator(Tokenizer *tokenizer, Parser *parser);
    double eval(const std::string &text) const;
    ~Calculator();
};