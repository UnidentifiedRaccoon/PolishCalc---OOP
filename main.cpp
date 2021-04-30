#include <iostream>
#include <cmath>


#include "Calculator.h"
#include "Tokenizer.h"

#include "AddOp.h"
#include "SubOp.h"
#include "Multi.h"
#include "DivOp.h"
#include "PowOp.h"

#include "utils.h"

Parser *DefaultParser() {
    auto p = new Parser();
    p->RegisterOp(new AddOp());
    p->RegisterOp(new MulOp());
    p->RegisterOp(new SubOp());
    p->RegisterOp(new DivOp());
    p->RegisterOp(new PowOp());
    return p;
}

Calculator *DefaultCalc() {
    auto t = new Tokenizer(' ');
    return new Calculator(t, DefaultParser());
}

void AssertEqualDoubles(double a, double b, int line = __LINE__) {
    if (std::abs(a - b) < 0.0001) {
        // OK
    } else {
        std::cout << line << "] FAIL " << a << " != " << b << std::endl;
        exit(-1);
    }
}

void AssertTrue(bool a) {
    if (!a) {
        std::cout << "FAIL expected true but got false";
        exit(-1);
    }
}

void test_0() {
    std::cout << "test_0: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("0"), 0.0);
    delete calc;
    std::cout << "test_0: " << "OK" << '\n';

}


void test_1() {
    std::cout << "test_1: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("1 2 3 42"), 42.0);
    delete calc;
    std::cout << "test_1: " << "OK" << '\n';
}

void test_tokenizer() {
    std::cout << "test_tokenizer: " << "START" << '\n';
    Tokenizer t(' ');
    auto res = t.tokenize("1 2 3 4 5");
    std::vector<std::string> expected{"1", "2", "3", "4", "5"};
    for (int i = 0; i < expected.size(); i++) {
        if (res[i] != expected[i]) {
            std::cout << "FAIL at i=" << i << " res[i]='" << res[i] << "' exp[i]"
                      << expected[i] << std::endl;
            exit(-1);
        }
    }
    std::cout << "test_tokenizer: " << "OK" << '\n';
}

void test_number_parser() {
    std::cout << "test_number_parser: " << "START" << '\n';
    AssertTrue(IsNumber("42.13"));
    AssertTrue(IsNumber("-1"));
    AssertTrue(IsNumber("+42"));

    AssertTrue(!IsNumber("+"));
    AssertTrue(!IsNumber("-"));
    std::cout << "test_number_parser: " << "OK" << '\n';
}

void test_Operation() {
    std::cout << "test_Operation: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("1 2 +"), 3);
    delete calc;
    std::cout << "test_Operation: " << "OK" << '\n';
}

void test_AddOp() {
    std::cout << "test_AddOp: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("1 2 4 + +"), 7);
    delete calc;
    std::cout << "test_AddOp: " << "OK" << '\n';
}

void test_SubOp() {
    std::cout << "test_SubOp: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("1 2 4 - -"), 1);
    delete calc;
    std::cout << "test_SubOp: " << "OK" << '\n';
}

void test_MultiOp() {
    std::cout << "test_MultiOp: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("1 2 4 * *"), 8);
    delete calc;
    std::cout << "test_MultiOp: " << "OK" << '\n';
}

void test_DivOp() {
    std::cout << "test_DivOp: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("1 2 4 / /"), 2);
    delete calc;
    std::cout << "test_DivOp: " << "OK" << '\n';
}

void test_PowOp() {
    std::cout << "test_DivOp: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("5 2 3 ^ ^"), 390625);
    delete calc;
    std::cout << "test_DivOp: " << "OK" << '\n';
}

void test_arithmetic() {
    std::cout << "test_arithmetic: " << "START" << '\n';
    auto calc = DefaultCalc();
    AssertEqualDoubles(calc->eval("5 1 2 + 4 * + 2 ^"), 289);
    // 15 7 1 1 + - / 3 * 2 1 1 + + 1
    AssertEqualDoubles(calc->eval("15 7 1 1 + - / 3 * 2 1 1 + + -"), 13.0);
    delete calc;
    std::cout << "test_arithmetic: " << "OK" << '\n';
}



int main() {
    test_0();
    test_1();
    test_number_parser();
    test_tokenizer();
    test_AddOp();
    test_SubOp();
    test_MultiOp();
    test_DivOp();
    test_PowOp();
    test_arithmetic();

    std::cout << "OK" << std::endl;
    return 0;
}