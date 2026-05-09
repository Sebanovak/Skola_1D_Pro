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
    Player p;

cout << "Vyber si classu:\n";
    cout << "1 - Crusader\n";
    cout << "2 - Mage\n";

    int volba;
    cin >> volba;

else if(volba == 1) {
    p.PlayerClass = "Crusader";

    p.maxHP = 12;
    p.hp = 12;

    p.maxMana = 3;
    p.mana = 3;

    p.attack = 4;

    p.gold = 10;
    p.level = 1;
    p.xp = 0;
}
if (volba == 2) {
    p.PlayerClass = "Mage";

    p.maxHP = 6;
    p.hp = 6;

    p.maxMana = 10;
    p.mana = 10;

    p.attack = 2;

    p.gold = 10;
    p.level = 1;
    p.xp = 0;
}
    return 0;
}