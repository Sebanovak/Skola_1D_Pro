#include <iostream>
#include <string>

using namespace std;

struct Player {
    string PlayerClass;

    int maxHP;
    int hp;

    int maxMana;
    int mana;

    int gold;

    int level;
    int xp;

    int attack;
};

int main() {
    player p;

    p.PlayerClass = "Crusader";

      p.maxHP = 10;
    p.hp = 10;

    p.maxMana = 5;
    p.mana = 5;

    p.gold = 10;

    p.level = 1;
    p.xp = 0;

    p.attack = 3;

    return 0;
}