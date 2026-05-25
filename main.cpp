#include <iostream>
#include <string>

using namespace std;

struct player {
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
struct Enemy {
    string name;

    int hp;
    int maxHP;

    int attack;

    int xpReward;
    int goldReward;
 };

int main() {
    player p;

cout << "Vitej ve svete dobrodruzstvi zacni tim ze si vyber sveho statecneho hrdinu:\n";
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
Enemy skret;

skret.name = "Skret";
skret.maxHP = 10;
skret.hp = 10;
skret.attack = 2;
skret.xpReward = 5;
skret.goldReward = 3;


 cout << "narazil jsi na oskliveho skreta!" << endl;


while (p.hp > 0 && skret.hp > 0) {

    int action;

    cout << "1 - Attack" << endl;
    cout << "2 - Heal" << endl;

    cin >> action;

    if (action == 1) {

        skret.hp = skret.hp - p.attack;

        cout << "Uderil jsi skreta!" << endl;
        cout << "Skret ma " << skret.hp << " HP." << endl;
    }

    if (skret.hp <= 0) {

        cout << "Skret byl porazen!" << endl;
    p.xp = p.xp + skret.xpReward;
    p.gold = p.gold + skret.goldReward;

    cout << "Ziskal jsi XP a gold!" << endl;

        break;
    }

    if (action == 2) {

        p.hp = p.hp + 5;

        cout << "Vylecil ses!" << endl;
        cout << "Mas " << p.hp << " HP." << endl;
    }

    p.hp = p.hp - skret.attack;

    cout << "Skret te uderil!" << endl;
    cout << "Mas " << p.hp << " HP." << endl;

    if (p.hp <= 0) {

        cout << "Prohral jsi!" << endl;

        break;
    }
}
    return 0;
}
