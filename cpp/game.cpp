#include "game.h"
#include "mask.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(Difficulty difficulty)
    : difficulty(difficulty),
      player(difficulty == Difficulty::EASY ? 150 :
             difficulty == Difficulty::NORMAL ? 100 : 50),
      level(1), gameOver(false), tickCount(0), answerBuffer("") {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Game::start() {
    std::cout << "Game start\n";
    while (!gameOver) {
        draw();
        handleInput();
        update();
        checkAnswer();
        checkCollision();
    }
    std::cout << "Game over! Final Score: " << player.getScore() << "\n";
}

void Game::update() {
    tickCount++;
    for (Enemy& enemy : enemies) {
        enemy.advance();
    }

    if (tickCount % 5 == 0) {
        spawn();
    }
}

std::vector<Mask> Game::generateMasks(int num) {
    std::vector<Mask> masks;
    masks.reserve(num);

    for (int i = 0; i < num; ++i) {
        Operator op = static_cast<Operator>(std::rand() % 4);
        int numDigits = 2 + (std::rand() % 2);  // 2 or 3 digits
        masks.emplace_back(Mask::generateMask(numDigits, op));
    }

    return masks;
}

void Game::spawn() {
    int damage = 10 + (level * 2);
    int masks = 1 + (level / 2);
    int speed = 1 + (level / 5);
    auto enemyMasks = generateMasks(masks);

    enemies.emplace_back(enemyMasks, damage, speed);
}

void Game::handleInput() {
    std::string input;
    std::cout << "Type answer: ";
    std::getline(std::cin, input);

    if (!input.empty()) {
        answerBuffer = input;
    }
}

void Game::checkAnswer() {
    for (Enemy& enemy : enemies) {
        if (enemy.countMasks() > 0 && enemy.removeMask(answerBuffer)) {
            player.addScore(10);
            answerBuffer.clear();
            return;
        }
    }
}

void Game::checkCollision() {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if (it->getDistance() <= 0) {
            int totalDamage = it->getDamage() * it->countMasks();
            player.loseHealth(totalDamage);
            it = enemies.erase(it);
        } else {
            ++it;
        }
    }

    if (player.getHealth() <= 0) {
        gameOver = true;
    }
}

void Game::draw() {
    std::cout << "\nHealth: " << player.getHealth()
              << " | Score: " << player.getScore() << "\n";
    std::cout << "Enemies:\n";
    for (const Enemy& e : enemies) {
        std::cout << " - Enemy [Distance: " << e.getDistance()
                  << ", Masks: " << e.countMasks() << "]\n";
    }
}

bool Game::isGameOver() const {
    return gameOver;
}
