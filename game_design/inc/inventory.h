#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
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
    void AddEquipment(equipmentSlot_t xSlot, std::string name, int damage, int defence,
                      int strength=0, int intellect=0, int agility=0, int critic=0, int haste=0);
    void AddConsumable(std::string name, int regenHealth, int regenMana);
    void AddTradeskill(std::string name);
    void RemoveEquipment(std::string name);
    void RemoveConsumable(std::string name);
    void RemoveTradeskill(std::string name);

    void Print(void) const;

    std::vector<Equipment> axEquipments;
    std::vector<Consumable> axConsumables;
    std::vector<Tradeskill> axTraderskills;

private:
    int getIndex(itemType_t xType, std::string name) const;
 
};

#endif /* INVENTORY_H */
