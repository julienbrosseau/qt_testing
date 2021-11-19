#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include "equipment.h"
#include "inventory.h"

/**
 * \brief           Class of a character
 */
class Character
{
public:
    /* Constructors & Destructor */
    Character();
    ~Character();

    /* Public functions */
    void GetDamages(int nbDamage);
    void SetAttack(Character &target);
    void GetHealing(int nbHeart);
    void ChangeArmorHead(std::string name, int defense, int strength, int intellect, int agility,
                              int critic, int haste);
    void ChangeArmorChest(std::string name, int defense, int strength, int intellect, int agility,
                              int critic, int haste);
    void ChangeArmorLegs(std::string name, int defense, int strength, int intellect, int agility,
                              int critic, int haste);
    void ChangeWeapon(std::string name, int damage, int strength, int intellect, int agility,
                              int critic, int haste);
    bool IsAlive(void) const;
    void Print(void) const;

    /* Public variable */
    Inventory *pInventory;

    Equipment *pArmorHead;
    Equipment *pArmorChest;
    Equipment *pArmorLegs;
    Equipment *pWeapon;

    int nbHeart;
    int nbMana;

    int damage;
    int defense;
    int strength;
    int intellect;
    int agility;
    int critic;
    int haste;

private:
    /* Private variables */
    int maxHeart;

    void UpdateCarac(Equipment *pOldEquipment, Equipment *pNewEquipment);
};

#endif /* CHARACTER_H */