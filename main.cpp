#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
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
vector<Enemy> enemies = {

    {"Goblin", 12, 12, 3, 6, 4},
    {"Ork", 25, 25, 6, 18, 10},
    {"Bandita", 18, 18, 5, 10, 6},
    {"Zombie", 16, 16, 3, 9, 5},
    {"Troll", 35, 35, 7, 25, 20},
    {"Duch", 20, 20, 4, 12, 8},
    {"Pavouk", 14, 14, 4, 8, 5},
    {"Demon", 40, 40, 8, 30, 25},
    {"Rytir", 30, 30, 6, 20, 15},

    {"Vlcek", 10, 10, 2, 5, 3},
    {"Skret Elite", 22, 22, 5, 14, 8},
    {"Bandit Leader", 28, 28, 6, 18, 12},
    {"Undead Knight", 32, 32, 7, 22, 15},
    {"Forest Beast", 26, 26, 6, 16, 10},
    {"Cave Bat", 15, 15, 3, 8, 5},
    {"Dark Mage", 38, 38, 8, 28, 20},
    {"Golem", 45, 45, 9, 35, 25},
    {"Assassin", 24, 24, 7, 18, 12},
    {"Hell Hound", 30, 30, 7, 20, 15},
    {"CHRONOBOT", 40, 40, 6, 50, 50}
};
int main() {
    player p;
    int volba;

    cout << "Vitej ve svete dobrodruzstvi:\n";
    cout << "1 - Crusader\n2 - Mage\n3 - Hunter\n4 - Warlock\n";
    cin >> volba;

    if (volba == 1) {
        p = {"Crusader",12,12,3,3,10,1,0,4};
    }
    else if (volba == 2) {
        p = {"Mage",6,6,10,10,10,1,0,2};
    }
    else if (volba == 3) {
        p = {"Hunter",8,8,6,6,10,1,0,3};
    }
    else if (volba == 4) {
        p = {"Warlock",7,7,12,12,10,1,0,3};
    }

    Enemy skret;
    skret.name = "Skret";
    skret.maxHP = 10;
    skret.hp = 10;
    skret.attack = 2;
    skret.xpReward = 5;
    skret.goldReward = 3;

    cout << "Narazil jsi na skreta!\n";

    while (p.hp > 0 && skret.hp > 0) {

        int akce;
        cout << "1 - Attack\n2 - Heal\n";
        cin >> akce;

        if (akce == 1) {
            skret.hp -= p.attack;
            cout << "Uderil jsi skreta!\n";
        }

        if (akce == 2) {
            p.hp += 5;
            if (p.hp > p.maxHP) p.hp = p.maxHP;
            cout << "Vylecil ses!\n";
        }

        if (skret.hp <= 0) break;

        p.hp -= skret.attack;

        cout << "Skret te uderil! HP: " << p.hp << "\n";

        if (p.hp <= 0) {
            cout << "Prohral jsi!\n";
            return 0;
        }
    }

    cout << "Skret byl porazen!\n";
    p.xp += skret.xpReward;
    p.gold += skret.goldReward;

    cout << "Obchod...\n";
    cout << "1 heal potion (3 gold)\n2 attack boost (10 gold)\n";

    int shop;
    cin >> shop;

    if (shop == 1 && p.gold >= 3) {
        p.gold -= 3;
        p.hp += 5;
        if (p.hp > p.maxHP) p.hp = p.maxHP;
    }

    if (shop == 2 && p.gold >= 10) {
        p.gold -= 10;
        p.attack += 1;
    }

    cout << "Kam se vydas?\n1 les\n2 jeskyne\n";

    int cestavolba;
    cin >> cestavolba;

    if (cestavolba == 1) {

        Enemy vlk;
        vlk.name = "Vlk";
        vlk.hp = 15;
        vlk.attack = 3;
        vlk.xpReward = 8;
        vlk.goldReward = 5;

        cout << "Narazil jsi na vlka!\n";

        while (p.hp > 0 && vlk.hp > 0) {

            int akce;
            cout << "1 - Attack\n2 - Heal\n";
            cin >> akce;

            if (akce == 1) {
                vlk.hp -= p.attack;
                cout << "Uderil jsi vlka!\n";
            }

            if (akce == 2) {
                p.hp += 5;
                if (p.hp > p.maxHP) p.hp = p.maxHP;
            }

            if (vlk.hp <= 0) break;

            p.hp -= vlk.attack;
            cout << "Vlk te kousl! HP: " << p.hp << "\n";

            if (p.hp <= 0) {
                cout << "Prohral jsi!\n";
                return 0;
            }
        }

        cout << "Vlk byl porazen!\n";
    }

    else if (cestavolba == 2) {

        Enemy kostlivec;
        kostlivec.name = "Kostlivec";
        kostlivec.hp = 20;
        kostlivec.attack = 4;
        kostlivec.xpReward = 12;
        kostlivec.goldReward = 8;

        cout << "Narazil jsi na kostlivce!\n";

        while (p.hp > 0 && kostlivec.hp > 0) {

            int akce;
            cout << "1 - Attack\n2 - Heal\n";
            cin >> akce;

            if (akce == 1) {
                kostlivec.hp -= p.attack;
                cout << "Uderil jsi kostlivce!\n";
            }

            if (akce == 2) {
                p.hp += 5;
                if (p.hp > p.maxHP) p.hp = p.maxHP;
            }

            if (kostlivec.hp <= 0) break;

            p.hp -= kostlivec.attack;

            cout << "Kostlivec te zasahl! HP: " << p.hp << "\n";

            if (p.hp <= 0) {
                cout << "Prohral jsi!\n";
                return 0;
            }
        }

        cout << "Kostlivec byl porazen!\n";
    }
cout << "\nDorazil jsi do druhe vesnice.\n";
cout << "1 - Odpocinout (+10 HP) za 5 gold\n";
cout << "2 - Zvysit max HP (+5) za 10 gold\n";
cout << "3 - Zvysit utok (+1) za 10 gold\n";
cout << "4 - Pokracovat dal\n";

int vesnice2;
cin >> vesnice2;

if (vesnice2 == 1) {
    if (p.gold >= 5) {
        p.gold -= 5;
        p.hp += 10;

        if (p.hp > p.maxHP) {
            p.hp = p.maxHP;
        }

        cout << "Odpocinul sis.\n";
    }
}

else if (vesnice2 == 2) {
    if (p.gold >= 10) {
        p.gold -= 10;
        p.maxHP += 5;
        p.hp = p.maxHP;

        cout << "Max HP zvyseno.\n";
    }
}

else if (vesnice2 == 3) {
    if (p.gold >= 10) {
        p.gold -= 10;
        p.attack += 1;

        cout << "Utok zvysen.\n";
    }
}Enemy troll;
troll.name = "Troll";
troll.maxHP = 35;
troll.hp = 35;
troll.attack = 7;
troll.xpReward = 25;
troll.goldReward = 20;

cout << "\nPred tebou se objevil MiniBoss Troll!\n";

while (p.hp > 0 && troll.hp > 0) {

    int akce;
    cout << "1 - Attack\n";
    cout << "2 - Heal\n";
    cin >> akce;

    if (akce == 1) {
        troll.hp -= p.attack;
        cout << "Zasahl jsi Trolla!\n";
    }

    if (akce == 2) {
        p.hp += 5;

        if (p.hp > p.maxHP) {
            p.hp = p.maxHP;
        }
    }

    if (troll.hp <= 0) {
        cout << "Troll byl porazen!\n";

        p.xp += troll.xpReward;
        p.gold += troll.goldReward;

        break;
    }

    p.hp -= troll.attack;

    cout << "Troll te zasahl!\n";
    cout << "Mas " << p.hp << " HP\n";
   
    if (p.hp <= 0) {
    cout << "Prohral jsi!\n";
    return 0;
}
}
Enemy goblin1 = {"Goblin",12,12,3,6,4};
Enemy goblin2 = {"Goblin",12,12,3,6,4};

cout << "\nPrepadli te dva Goblini!\n";

while (p.hp > 0 && (goblin1.hp > 0 || goblin2.hp > 0)) {

    int cil;

    cout << "Koho chces utocit?\n";
    cout << "1 - Goblin 1\n";
    cout << "2 - Goblin 2\n";
    cin >> cil;

    if (cil == 1 && goblin1.hp > 0) {
        goblin1.hp -= p.attack;
    }

    if (cil == 2 && goblin2.hp > 0) {
        goblin2.hp -= p.attack;
    }

    if (goblin1.hp > 0) {
        p.hp -= goblin1.attack;
    }

    if (goblin2.hp > 0) {
        p.hp -= goblin2.attack;
    }

    cout << "Mas " << p.hp << " HP\n";

    if (p.hp <= 0) {
        cout << "Prohral jsi!\n";
        return 0;
    }
}

cout << "Porazil jsi oba Gobliny!\n";


Enemy demon;
demon.name = "Demon";
demon.maxHP = 40;
demon.hp = 40;
demon.attack = 8;
demon.xpReward = 30;
demon.goldReward = 25;

cout << "\nPred tebou se objevil MiniBoss Demon!\n";

while (p.hp > 0 && demon.hp > 0) {

    int akce;
    cout << "1 - Attack\n";
    cout << "2 - Heal\n";
    cin >> akce;

    if (akce == 1) {
        demon.hp -= p.attack;
        cout << "Zasahl jsi Demona!\n";
    }

    if (akce == 2) {
        p.hp += 5;

        if (p.hp > p.maxHP) {
            p.hp = p.maxHP;
        }
    }

    if (demon.hp <= 0) {
        cout << "Demon byl porazen!\n";

        p.xp += demon.xpReward;
        p.gold += demon.goldReward;

        break;
    }

    p.hp -= demon.attack;

    cout << "Demon te zasahl!\n";
    cout << "Mas " << p.hp << " HP\n";

    if (p.hp <= 0) {
        cout << "Prohral jsi!\n";
        return 0;
    }
}
    return 0;

}