#include "player.h"
#include <algorithm>

Player::Player(int health): health(health) {}

int Player::getHealth() const {
    return health;
}

int Player::getScore() const {
    return score;
}

void Player::gainHealth(int amount) {
    health = std::min(maxHealth, health + amount);
}

void Player::loseHealth(int amount) {
    health = std::max(0, health - amount);
}

void Player::addScore(int amount) {
    score += amount;
}