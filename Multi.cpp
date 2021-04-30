#include "Multi.h"
#include <iostream>

using namespace std;

string MulOp::GetName() const {return "*";}
double MulOp::Apply(const vector<double> &args) const {return args[0] * args[1];}
unsigned int MulOp::GetArity() const {return 2;}
MulOp::~MulOp() {cout << "~MulOp" << '\n';}
