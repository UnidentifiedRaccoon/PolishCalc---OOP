#include <cmath>
#include <iostream>
#include "PowOp.h"

using namespace std;

string PowOp::GetName() const {return "^";}
double PowOp::Apply(const std::vector<double> &args) const {return pow(args.at(1), args.at(0));}
unsigned int PowOp::GetArity() const {return 2;}
PowOp::~PowOp() {cout << "~PowOp" << '\n';}

