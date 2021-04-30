cmake_minimum_required(VERSION 3.17)
project(PolishCalc___OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(PolishCalc___OOP main.cpp Calculator.cpp Calculator.h Tokenizer.cpp Tokenizer.h i_node.h DoubleNode.cpp DoubleNode.h OperatorNode.cpp OperatorNode.h Parser.cpp Parser.h utils.h utils.h utils.cpp i_operation.h AddOp.cpp AddOp.h Multi.cpp Multi.h DivOp.cpp DivOp.h SubOp.cpp SubOp.h PowOp.cpp PowOp.h)
