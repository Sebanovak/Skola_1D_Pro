#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player {
    string name;
    int hp, maxHp;
    int mana, maxMana;
    int gold;
    int level;
    int xp;
    int attack;
};

struct Enemy {
    string name;
    int hp;
    int attack;
    int xp;
    int gold;
    bool boss;
};

void levelUp(Player &p) {
    while (p.xp >= p.level * 20) {
        p.xp -= p.level * 20;
        p.level++;
        p.maxHp += 5;
        p.attack += 1;
        p.maxMana += 2;
        p.hp = p.maxHp;
        p.mana = p.maxMana;

        cout << "\n=== LEVEL UP! Jsi level " << p.level << " ===\n";
    }
}

void heal(Player &p) {
    p.hp += 5;
    if (p.hp > p.maxHp) p.hp = p.maxHp;
}

bool goldDrop(Player &p, Enemy &e) {
    if (e.boss || rand() % 2 == 0) {
        p.gold += e.gold;
        cout << "Ziskal jsi " << e.gold << " zlata!\n";
        return true;
    }
    cout << "Monstrum nemelo zlato.\n";
    return false;
}

void fight(Player &p, vector<Enemy> enemies, string story) {
    cout << "\n" << story << "\n";

    for (auto e : enemies) {

        cout << "\nNarazil jsi na: " << e.name << "!\n";

        while (p.hp > 0 && e.hp > 0) {

            cout << "\nHP: " << p.hp << " | " << e.name << " HP: " << e.hp << "\n";
            cout << "1 utok  2 heal\n";

            int a;
            cin >> a;

            if (a == 1) e.hp -= p.attack;
            else heal(p);

            if (e.hp > 0) p.hp -= e.attack;

            if (p.hp <= 0) {
                cout << "PROHRA!\n";
                exit(0);
            }
        }

        cout << e.name << " porazen!\n";
        p.xp += e.xp;
        goldDrop(p, e);
        levelUp(p);
    }
}

// CHRONOBOT BOSSMECHANIKA
void chronobot(Player &p) {

    Enemy b = {"CHRONOBOT", 60, 8, 50, 50, true};

    int phase = 0;

    cout << "\n!!! FINAL BOSS CHRONOBOT !!!\n";

    while (p.hp > 0 && b.hp > 0) {

        cout << "\nHP: " << p.hp << " | BOSS: " << b.hp << "\n";
        cout << "1 utok 2 heal\n";

        int a;
        cin >> a;

        if (a == 1) b.hp -= p.attack;
        else heal(p);

        if (b.hp <= 0) break;

        int dmg;

        if (phase == 0) dmg = 3;
        else if (phase == 1) dmg = 6;
        else if (phase == 2) dmg = 10;
        else dmg = 15;

        cout << "Chronobot utoci za " << dmg << "\n";
        p.hp -= dmg;

        phase = (phase + 1) % 4;

        if (p.hp <= 0) {
            cout << "PROHRA!\n";
            exit(0);
        }
    }

    cout << "\n!!! VYHRA !!!\n";
}

int main() {
    srand(time(0));

    Player p;

    cout << "Vyber classu (1-4): ";
    int c;
    cin >> c;

    if (c == 1) p = {"Paladin", 25, 25, 10, 10, 10, 1, 0, 4};
    if (c == 2) p = {"Mage", 15, 15, 20, 20, 10, 1, 0, 3};
    if (c == 3) p = {"Hunter", 18, 18, 12, 12, 10, 1, 0, 5};
    if (c == 4) p = {"Warlock", 20, 20, 15, 15, 10, 1, 0, 4};

    // MAPA SPLNUJICI ZADANI (16 KROKU)
    string map[16] = {
        "V","M","M","2M","MB","V","M","2M","M","MB","V","2M","M","3M","V","HB"
    };

    for (int i = 0; i < 16; i++) {

        cout << "\n--- KROK " << i+1 << " ---\n";

        if (map[i] == "V") {
            cout << "VESNICE\n1 heal 2 attack +1\n";
            int x; cin >> x;
            if (x == 1) p.hp = p.maxHp;
            if (x == 2) p.attack++;
        }

        else if (map[i] == "M") {
            fight(p, {{"Goblin",10,3,5,4,false}}, "Les...");
        }

        else if (map[i] == "2M") {
            fight(p, {
                {"Ork",15,5,8,6,false},
                {"Bandita",12,4,6,5,false}
            }, "Prepad!");
        }

        else if (map[i] == "3M") {
            fight(p, {
                {"Zombie",10,3,5,3,false},
                {"Zombie",10,3,5,3,false},
                {"Skeleton",12,4,6,4,false}
            }, "Horda!");
        }

        else if (map[i] == "MB") {
            fight(p, {{"Troll",30,6,20,15,true}}, "Mini boss!");
        }

        else if (map[i] == "HB") {
            chronobot(p);
        }
    }

    cout << "\nDOHRANO!\n";
}