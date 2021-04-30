#pragma once

#include "i_operation.h"

class PowOp: public IOperation {
    std::string GetName() const override;
    double Apply(const std::vector<double> &args) const override;
    unsigned int GetArity() const override;
    virtual ~PowOp();
};

