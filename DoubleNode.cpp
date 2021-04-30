#include "DoubleNode.h"
#include <iostream>

using namespace std;

void DoubleNode::Act(stack<double> &s) const {s.push(value_);}
DoubleNode::~DoubleNode() {cout << "~DoubleNode" << '\n';}