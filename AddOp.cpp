#include "AddOp.h"
#include <iostream>

using namespace std;

string AddOp::GetName() const {return "+";}
double AddOp::Apply(const vector<double> &args) const {return args.at(0) + args.at(1);}
unsigned int AddOp::GetArity() const {return 2;}
AddOp::~AddOp() {cout << "~AddOp" << '\n';}