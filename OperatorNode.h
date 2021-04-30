#pragma once

#include "i_node.h"
#include "i_operation.h"

class OperatorNode : public INode {
  IOperation* operation_;

 public:
  explicit OperatorNode(IOperation* operation);
  void Act(std::stack<double>& s) const override;
  virtual ~OperatorNode();
};
