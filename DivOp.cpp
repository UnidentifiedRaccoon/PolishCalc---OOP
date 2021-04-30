#include "DivOp.h"
#include <iostream>

using namespace std;

string DivOp::GetName() const {return "/";}
// TODO: check zero-div Exception
double DivOp::Apply(const vector<double> &args) const {return args[1] / args[0];}
unsigned int DivOp::GetArity() const {return 2;}
DivOp::~DivOp() {cout << "~DivOp" << '\n';}