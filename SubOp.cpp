#include "SubOp.h"
#include <iostream>

using namespace std;

std::string SubOp::GetName() const {return "-";}
double SubOp::Apply(const std::vector<double> &args) const {return args.at(0) - args.at(1);}
unsigned int SubOp::GetArity() const {return 2;}
SubOp::~SubOp() {cout << "~SubOp" << '\n';}
