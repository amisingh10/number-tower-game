#include "enemy.h"
#include <sstream>

Enemy::Enemy(const std::vector<Mask>& masks,
             int damage,
             int speed,
             int distanceToPlayer)
    : masks(masks), damage(damage), speed(speed),
      distanceToPlayer(distanceToPlayer), destroyed(false) {}

int Enemy::countMasks() const {
    return static_cast<int>(masks.size());
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
    for (size_t i = 0; i < masks.size(); ++i) {
        int result = masks[i].evaluate();

        std::ostringstream oss;
        oss << result;

        if (oss.str() == answer) {
            masks.erase(masks.begin() + i);
            if (masks.empty()) destroy();
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
