#include "enemy.h"


Enemy::Enemy(const std::vector<std::vector<int>>& digits, const std::vector<Operation> operations, int numOfMasks, int damage, int speed, bool destroyed)
    : digits(digits), operations(operations), numOfMasks(numOfMasks), damage(damage), speed(speed), destroyed(destroyed) {}

std::vector<std::vector<int>> Enemy::getDigits() const {
    return digits;
}

std::vector<Operation> Enemy::getOperations() const {
    return operations;
}

int Enemy::countMasks() const {
    return numOfMasks;
}

int Enemy::getDamage() const {
    return damage;
}

int Enemy::getSpeed() const {
    return speed;
}

bool Enemy::isDestroyed() const {
    return destroyed;
}

void Enemy::attackPlayer() {
    // attack logic (need player first)
}

void Enemy::loseMask() {
    numOfMasks--;
    if (numOfMasks == 0) {
        destroy();
    }
}

void Enemy::destroy() {
    destroyed = true;
}