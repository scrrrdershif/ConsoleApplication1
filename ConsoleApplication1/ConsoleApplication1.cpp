// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <locale.h>


class Character {
private:
    std::string name;  // Приватное поле: имя персонажа
    int health;        // Приватное поле: уровень здоровья
    int MAXhealth;     // Приватное поле: лимит здоровья
    int attack;        // Приватное поле: уровень атаки
    int defense;       // Приватное поле: уровень защиты

public:
    // Конструктор для инициализации данных
    Character(const std::string& n, int h, int mh ,int a, int d)
        : name(n), health(h),MAXhealth(mh), attack(a), defense(d)  {
    }

    // Метод для получения уровня здоровья
    int getHealth() const {
        return health;
    }

    // Метод для вывода информации о персонаже
    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", MAXHP: " << MAXhealth
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    // Метод для атаки другого персонажа
    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }
    void heal(int amount) {
        health = health + amount;
        if (health>=MAXhealth) {
            health = MAXhealth;
            std::cout << name << " was healed for " << amount << " HP! Now it is " <<health<< "!" <<std::endl;
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");
    // Создаем объекты персонажей
    Character hero("Волшебник", 100,100, 20, 10);

    Character monster("Гарпия", 50,50, 15, 5);

    // Выводим информацию о персонажах
    hero.displayInfo();
    monster.displayInfo();

    // Герой атакует монстра
    hero.attackEnemy(monster);
    monster.displayInfo();

    hero.heal(20);


    return 0;
    
}



