#include "mask.h"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

Mask::Mask(const std::vector<int>& digits, Operator op)
    : digits(digits), op(op) {}

int Mask::evaluate() const {
    if (digits.empty()) {
        throw std::runtime_error("mask is empty");
    }

    int result = digits[0];
    for (size_t i = 1; i < digits.size(); ++i) {
        switch (op) {
            case Operator::ADD:
                result += digits[i];
                break;
            case Operator::SUBTRACT:
                result -= digits[i];
                break;
            case Operator::MULTIPLY:
                result *= digits[i];
                break;
            case Operator::DIVIDE:
                if (digits[i] == 0) {
                    throw std::runtime_error("division by zero");
                }
                result /= digits[i];
                break;
        }
    }
    return result;
}

std::string Mask::to_string() const {
    if (digits.empty()) return "";

    std::ostringstream oss;
    oss << digits[0];
    char symbol;
    switch (op) {
        case Operator::ADD: symbol = '+'; break;
        case Operator::SUBTRACT: symbol = '-'; break;
        case Operator::MULTIPLY: symbol = '*'; break;
        case Operator::DIVIDE: symbol = '/'; break;
    }

    for (size_t i = 1; i < digits.size(); ++i) {
        oss << " " << symbol << " " << digits[i];
    }

    return oss.str();
}

const std::vector<int>& Mask::getDigits() const {
    return digits;
}

Operator Mask::getOperator() const {
    return op;
}

Mask Mask::generateMask(int numDigits, Operator op) {
    std::vector<int> digits;
    digits.reserve(numDigits);
    for (int i = 0; i < numDigits; ++i) {
        digits.push_back(std::rand() % 10 + 1); // exclude 0
    }
    return Mask(digits, op);
}
