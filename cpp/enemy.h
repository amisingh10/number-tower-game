#pragma once
#include <vector>
#include <string>
#include "player.h"
#include <sstream>

enum class Operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class Enemy {
private:
    std::vector<std::vector<int>> digits;
    std::vector<Operation> operations;
    int distanceToPlayer = 10;
    int damage;
    int speed;
    bool destroyed = false;

public:
    Enemy(const std::vector<std::vector<int>>& digits,
          const std::vector<Operation>& operations,
          int damage,
          int speed,
          int distanceToPlayer = 10);

    std::vector<std::vector<int>> getDigits() const;
    std::vector<Operation> getOperations() const;
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
