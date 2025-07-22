#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:

    int health;
    int maxHealth = 200;
    int score = 0;

public:

    Player(int health);

    int getHealth() const;
    int getScore() const;
    void gainHealth(int amount);
    void loseHealth(int amount);
    void addScore(int amount);

};

#endif