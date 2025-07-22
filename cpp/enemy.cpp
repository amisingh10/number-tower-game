#include "enemy.h"

Enemy::Enemy(const std::vector<std::vector<int>>& digits,
             const std::vector<Operation>& operations,
             int damage,
             int speed,
             int distanceToPlayer)
    : digits(digits), operations(operations), damage(damage), speed(speed), distanceToPlayer(distanceToPlayer), destroyed(false) {}

std::vector<std::vector<int>> Enemy::getDigits() const {
    return digits;
}

std::vector<Operation> Enemy::getOperations() const {
    return operations;
}

int Enemy::countMasks() const {
    return static_cast<int>(digits.size());
}

int Enemy::getDamage() const {
    return damage;
}

int Enemy::getSpeed() const {
    return speed;
}

int Enemy::getDistance() const {
    return distanceToPlayer;
}

bool Enemy::isDestroyed() const {
    return destroyed;
}

void Enemy::advance() {
    distanceToPlayer -= speed;
    if (distanceToPlayer < 0) distanceToPlayer = 0;
}

bool Enemy::removeMask(const std::string& answer) {
    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i].size() < 2) continue;

        int a = digits[i][0];
        int b = digits[i][1];
        int result = 0;

        switch (operations[i]) {
            case Operation::ADD: result = a + b; break;
            case Operation::SUBTRACT: result = a - b; break;
            case Operation::MULTIPLY: result = a * b; break;
            case Operation::DIVIDE:
                if (b != 0) result = a / b;
                else continue;
                break;
        }

        std::ostringstream oss;
        oss << result;

        if (oss.str() == answer) {
            digits.erase(digits.begin() + i);
            operations.erase(operations.begin() + i);
            if (digits.empty()) destroy();
            return true;
        }
    }
    return false;
}

void Enemy::attackPlayer(Player& player) {
    player.loseHealth(damage);
}

void Enemy::destroy() {
    destroyed = true;
}
