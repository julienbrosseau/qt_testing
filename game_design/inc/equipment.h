#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <QtWidgets>

/*!
 * \brief           Enumerate of equipement slot
 */
typedef enum equipmentSlot
{
    ARMOR_HEAD,
    ARMOR_CHEST,
    ARMOR_LEGS,
    WEAPON,
    NOTHING
} equipmentSlot_t;

/*!
 * \brief           Class 'Equipement'
 */
class Equipment
{
public:
    /* Constructors */
    Equipment(equipmentSlot_t xSlot);

    /* Public functions */
    void Change(equipmentSlot_t xSlot, QString name, int damage, int defence, int strength=0,
                int intellect=0, int agility=0, int critic=0, int haste=0);
    void Print(void) const;

    /* Public variables */
    equipmentSlot_t xSlot;
    QString name;
    int damage;
    int defense;
    int strength;
    int intellect;
    int agility;
    int critic;
    int haste;
};

#endif /* EQUIPMENT_H */
