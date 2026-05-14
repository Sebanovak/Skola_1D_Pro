#include <iostream>
#include <string>

using namespace std;

struct Player {
    string playerClass;

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

cout << "Vyber si sveho hrdinu:\n";
    cout << "1 - Crusader\n";
    cout << "2 - Mage\n";
     cout << "3 - Hunter\n";
    cout << "4 - Warlock\n";

    int volba;
    cin >> volba;

 if(volba == 1) {
    p.playerClass = "Crusader";

    p.maxHP = 12;
    p.hp = 12;

    p.maxMana = 3;
    p.mana = 3;

    p.attack = 4;

    p.gold = 10;
    p.level = 1;
    p.xp = 0;
}
else if(volba == 2) {
    p.playerClass = "Mage";

    p.maxHP = 6;
    p.hp = 6;

    p.maxMana = 10;
    p.mana = 10;

    p.attack = 2;

    p.gold = 10;
    p.level = 1;
    p.xp = 0;
}
    else if (volba == 3) {

        p.playerClass = "Hunter";

        p.maxHP = 8;
        p.hp = 8;

        p.maxMana = 6;
        p.mana = 6;

        p.attack = 3;

        p.gold = 10;
        p.level = 1;
        p.xp = 0;
    }
        else if (volba == 4) {

        p.playerClass = "Warlock";

        p.maxHP = 7;
        p.hp = 7;

        p.maxMana = 12;
        p.mana = 12;

        p.attack = 3;

        p.gold = 10;
        p.level = 1;
        p.xp = 0;
    }

    return 0;
}
