#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <QtWidgets>
#include <vector>

#include "equipment.h"
#include "consumable.h"
#include "tradeskill.h"

/*!
 * \brief           Enumerate of item type 
 */
typedef enum itemType
{
    EQUIPMENT,
    CONSUMABLE,
    TRADESKILL
} itemType_t;

/*!
 * \brief           Class 'Inventory'
 */
class Inventory
{
public:
    /* Constructor */
    Inventory();

    /* Public functions */
    void AddEquipment(equipmentSlot_t xSlot, QString name, int damage, int defence,
                      int strength=0, int intellect=0, int agility=0, int critic=0, int haste=0);
    void AddConsumable(QString name, int regenHealth, int regenMana);
    void AddTradeskill(QString name);
    void RemoveEquipment(QString name);
    void RemoveConsumable(QString name);
    void RemoveTradeskill(QString name);

    void Print(void) const;

    std::vector<Equipment> axEquipments;
    std::vector<Consumable> axConsumables;
    std::vector<Tradeskill> axTraderskills;

private:
    int getIndex(itemType_t xType, QString name) const;
 
};

#endif /* INVENTORY_H */
