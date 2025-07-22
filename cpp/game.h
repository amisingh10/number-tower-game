#pragma once
#include "player.h"
#include "enemy.h"
#include <vector>
#include <string>
#include <utility>

enum class Difficulty { EASY, NORMAL, HARD };

class Game {
private:
    Player player;
    std::vector<Enemy> enemies;
    Difficulty difficulty;
    int level;
    bool gameOver;
    int tickCount;
    std::string answerBuffer;

    std::pair<std::vector<std::vector<int>>, std::vector<Operation>> generateMasks(int num);

public:
    Game(Difficulty difficulty);

    void start();
    void update();
    void draw();
    void spawn();
    void handleInput();
    void checkAnswer();
    void checkCollision();
    bool isGameOver() const;
};
