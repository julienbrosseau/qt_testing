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
    void ChangeArmorHead(QString name, int defense, int strength, int intellect, int agility,
                              int critic, int haste);
    void ChangeArmorChest(QString name, int defense, int strength, int intellect, int agility,
                              int critic, int haste);
    void ChangeArmorLegs(QString name, int defense, int strength, int intellect, int agility,
                              int critic, int haste);
    void ChangeWeapon(QString name, int damage, int strength, int intellect, int agility,
                              int critic, int haste);
    bool IsAlive(void) const;
    void Print(void) const;

    /* Public variable */
    Inventory *pInventory;

    /* Public variables */
    Equipment *pArmorHead;
    Equipment *pArmorChest;
    Equipment *pArmorLegs;
    Equipment *pWeapon;

private:
    /* Private variables */
    int maxHeart;
    int nbHeart;
    int nbMana;

};

#endif /* CHARACTER_H */