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
    int volba;

         cout << "Vitej ve svete dobrodruzstvi zacni tim ze si vyber sveho statecneho hrdinu:\n";
    cout << "1 - Crusader\n";
    cout << "2 - Mage\n";
     cout << "3 - Hunter\n";
    cout << "4 - Warlock\n";
    cin >> volba;

 if(volba == 1) {
    cout << "Crusader zajimava volba doufam ze te bude provazet krestanska vira!!" << endl;
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
    cout << "Mage zajimava volba doufam ze te bude provazet kouzelna sila!!" << endl;
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
        cout << "Hunter dobra volba doufam ze te bude presna strela!!" << endl;
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

        p.playerClass = "Warlock pekna volba doufam ze ti bude dobre pomahat v ceste za dobrodruzstvim!!";

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


        cout << " ale pozor! narazil jsi na oskliveho skreta!" << endl;


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

     if (p.xp >= 10) {

        p.level = p.level + 1;

        p.maxHP = p.maxHP + 5;
        p.attack = p.attack + 1;

        p.hp = p.maxHP;

        cout << "LEVEL UP!" << endl;
    }

        break;
    }

    if (action == 2) {

        p.hp = p.hp + 5;
        if (p.hp > p.maxHP) {
         p.hp = p.maxHP;
    }
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
cout << "Po ceste si potkal drevenej obchod v lese\n";
    cout << "1 - Pujdes se dovnitr kouknout?\n";
    cout << "2 - Nebo budes pokracovat?\n";

int volba;
cin >> volba;

if (volba == 1) {

    cout << "Vstoupil jsi do obchodu..." << endl;

    cout << "Obchodnik ti nabizi:" << endl;
    cout << "1 - Maly lektvar zivotu (3 gold)" << endl;
    cout << "2 - Lektvar Alexanderske sily (10 gold)" << endl;

        int shopVolba;
             cin >> shopVolba;

    if (shopVolba == 1) {

        if (p.gold >= 3) {
            p.gold = p.gold - 3;
            p.hp = p.hp + 5;

            if (p.hp > p.maxHP) {
                p.hp = p.maxHP;
            }

            cout << "Koupil jsi healing potion!" << endl;
        }
        else {
            cout << "Nemas dost gold!" << endl;
        }
    }

 if (shopVolba == 2) {

        if (p.gold >= 10) {
            p.gold = p.gold - 10;
            p.attack = p.attack + 1;

            cout << "Zlepsil jsi svuj utok!" << endl;
        }
        else {
            cout << "Nemas dost gold!" << endl;
        }
    }
}


else if (volba == 2) {

    cout << "Pokracujes dal v ceste..." << endl;

}


}
    return 0;
}
