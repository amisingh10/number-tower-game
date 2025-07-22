#pragma once
#include <vector>
#include <string>

enum class Operator {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class Mask {
private:
    std::vector<int> digits;
    Operator op;

public:
    Mask(const std::vector<int>& digits, Operator op);
    int evaluate() const;
    std::string to_string() const;

    const std::vector<int>& getDigits() const;
    Operator getOperator() const;

    static Mask generateMask(int numDigits, Operator op);
};
