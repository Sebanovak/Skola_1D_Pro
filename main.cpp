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

void levelUp(player &p) {
    while (p.xp >= p.level * 20) {
        p.xp -= p.level * 20;
        p.level++;
        p.maxHP += 3;
        p.attack += 1;
        p.hp = p.maxHP;

        cout << "\nLEVEL UP! Jsi level " << p.level << "!\n";
    }
}

bool dropGold(Enemy &e, player &p) {
    if (rand() % 2 == 0) {
        p.gold += e.goldReward;
        cout << "Ziskal jsi " << e.goldReward << " zlata!\n";
        return true;
    }
    return false;
}

int main() {
    srand(time(0));

    player p;
    int volba;

    cout << "Vitej ve svete dobrodruzstvi:\n";
    cout << "1 - Crusader\n2 - Mage\n3 - Hunter\n4 - Warlock\n";
    cin >> volba;

    if (volba == 1) p = {"Crusader",12,12,3,3,10,1,0,4};
    if (volba == 2) p = {"Mage",6,6,10,10,10,1,0,2};
    if (volba == 3) p = {"Hunter",8,8,6,6,10,1,0,3};
    if (volba == 4) p = {"Warlock",7,7,12,12,10,1,0,3};

    Enemy skret = {"Skret",10,10,2,5,3};

    cout << "Narazil jsi na skreta!\n";

    while (p.hp > 0 && skret.hp > 0) {
        int akce;
        cin >> akce;

        if (akce == 1) skret.hp -= p.attack;
        if (akce == 2) {
            p.hp += 5;
            if (p.hp > p.maxHP) p.hp = p.maxHP;
        }

        if (skret.hp <= 0) break;

        p.hp -= skret.attack;
        if (p.hp <= 0) return 0;
    }

    p.xp += skret.xpReward;
    dropGold(skret, p);
    levelUp(p);

    cout << "\nKam se vydas?\n1 les\n2 jeskyne\n3 hory\n";
    int cestavolba;
    cin >> cestavolba;

    if (cestavolba == 1) {
        Enemy vlk = {"Vlk",15,15,3,8,5};

        while (p.hp > 0 && vlk.hp > 0) {
            int akce;
            cin >> akce;

            if (akce == 1) vlk.hp -= p.attack;
            if (akce == 2) {
                p.hp += 5;
                if (p.hp > p.maxHP) p.hp = p.maxHP;
            }

            if (vlk.hp <= 0) break;

            p.hp -= vlk.attack;
            if (p.hp <= 0) return 0;
        }

        p.xp += vlk.xpReward;
        dropGold(vlk, p);
        levelUp(p);
    }

    else if (cestavolba == 2) {
        Enemy kostlivec = {"Kostlivec",20,20,4,12,8};

        while (p.hp > 0 && kostlivec.hp > 0) {
            int akce;
            cin >> akce;

            if (akce == 1) kostlivec.hp -= p.attack;
            if (akce == 2) {
                p.hp += 5;
                if (p.hp > p.maxHP) p.hp = p.maxHP;
            }

            if (kostlivec.hp <= 0) break;

            p.hp -= kostlivec.attack;
            if (p.hp <= 0) return 0;
        }

        p.xp += kostlivec.xpReward;
        dropGold(kostlivec, p);
        levelUp(p);
    }

    cout << "\nBOJ SE 3 MONSTRY!\n";

    Enemy m1 = enemies[rand() % enemies.size()];
    Enemy m2 = enemies[rand() % enemies.size()];
    Enemy m3 = enemies[rand() % enemies.size()];

    while (p.hp > 0 && (m1.hp > 0 || m2.hp > 0 || m3.hp > 0)) {

        int akce;
        cin >> akce;

        if (akce == 1) {
            if (m1.hp > 0) m1.hp -= p.attack;
            else if (m2.hp > 0) m2.hp -= p.attack;
            else if (m3.hp > 0) m3.hp -= p.attack;
        }

        if (akce == 2) {
            p.hp += 5;
            if (p.hp > p.maxHP) p.hp = p.maxHP;
        }

        if (m1.hp > 0) p.hp -= m1.attack;
        if (m2.hp > 0) p.hp -= m2.attack;
        if (m3.hp > 0) p.hp -= m3.attack;

        if (p.hp <= 0) return 0;
    }

    cout << "\nPokracujes dal...\n";

    // RANDOM ENEMY
    Enemy randomEnemy = enemies[rand() % enemies.size()];

    cout << "Narazil jsi na: " << randomEnemy.name << "!\n";

    while (p.hp > 0 && randomEnemy.hp > 0) {

        int akce;
        cin >> akce;

        if (akce == 1) randomEnemy.hp -= p.attack;

        if (akce == 2) {
            p.hp += 5;
            if (p.hp > p.maxHP) p.hp = p.maxHP;
        }

        if (randomEnemy.hp <= 0) break;

        p.hp -= randomEnemy.attack;
        if (p.hp <= 0) return 0;
    }

    p.xp += randomEnemy.xpReward;
    dropGold(randomEnemy, p);
    levelUp(p);

    cout << "\n!!! FINAL BOSS CHRONOBOT !!!\n";

    Enemy boss = {"CHRONOBOT", 60, 60, 10, 100, 100};

    while (p.hp > 0 && boss.hp > 0) {

        int akce;
        cin >> akce;

        if (akce == 1) boss.hp -= p.attack;

        if (akce == 2) {
            p.hp += 5;
            if (p.hp > p.maxHP) p.hp = p.maxHP;
        }

        if (boss.hp <= 0) break;

        p.hp -= boss.attack;
        if (p.hp <= 0) return 0;
    }

    cout << "\n!!! VYHRAL JSI CELOU HRU !!!\n";
    return 0;
}