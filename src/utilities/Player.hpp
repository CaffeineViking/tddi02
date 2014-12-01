#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "Random.hpp"
#include "Weapon.hpp"
#include "../entities/Entity.hpp"

class Unit;
class Player{
    private:
        sf::Color color_;
        std::vector<std::pair<Weapon*, int>> weaponList_; // Vector of weapon and ammunition of each of them
        std::vector<Unit*> team_;
        int unitCounter_{-1};
        int currentWeapon_{0};
    public:
        Player(sf::Color col) : color_{col}{}
        sf::Color getColor(){return color_;};
        Unit* getRandomUnit();
        Unit* getNextUnit();
        const std::vector<Unit*>& getTeam(){return team_;};
        void insertUnit(Unit*);
        Weapon* selectWeapon(int weaponID);
        int getCurrentWeapon();
        ~Player() = default;
};
#endif
