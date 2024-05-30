#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <string>

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
    int numOfMasks;
    int damage;
    int speed;
    bool destroyed;

public:

    Enemy(const std::vector<std::vector<int>>& digits, std::vector<Operation> operations, int numOfMasks, int damage, int speed, bool destroyed);

    std::vector<std::vector<int>> getDigits() const;
    std::vector<Operation> getOperations() const;
    int countMasks() const;
    int getDamage() const;
    int getSpeed() const;
    bool isDestroyed() const;

    void attackPlayer();
    void loseMask();
    void destroy();

};

#endif