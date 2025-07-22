#pragma once
#include <vector>
#include <string>
#include "player.h"
#include "mask.h"

class Enemy {
private:
    std::vector<Mask> masks;
    int distanceToPlayer;
    int damage;
    int speed;
    bool destroyed;

public:
    Enemy(const std::vector<Mask>& masks,
          int damage,
          int speed,
          int distanceToPlayer = 10);

    int countMasks() const;
    int getDamage() const;
    int getSpeed() const;
    int getDistance() const;
    bool isDestroyed() const;

    void advance();
    bool removeMask(const std::string& answer);
    void attackPlayer(Player& player);
    void destroy();
};
