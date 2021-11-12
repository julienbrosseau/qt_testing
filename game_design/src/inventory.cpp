#include <bits/stdc++.h>

#include "inventory.h"

/*!
 * \brief           Construct a new Inventory:: Inventory object
 */
Inventory::Inventory()
{
}

/*!
 * \brief           Add an equipment to the inventory
 * 
 * \param[in]       xSlot: Define the slot of the equipment
 * \param[in]       name: Define the name of the equipement
 * \param[in]       damage: Define the damage of the equipment
 * \param[in]       defence: Define the defence of the equipment
 * \param[in]       strength: Define the strength bonus of the equipment (default value: 0)
 * \param[in]       intellect: Define the intellect bonus of the equipment (default value: 0)
 * \param[in]       agility: Define the agility bonus of the equipment (default value: 0)
 * \param[in]       critic: Define the critical strike bonus of the equipment (default value: 0)
 * \param[in]       haste: Define the haste bonus of the equipment (default value: 0)
 */
void Inventory::AddEquipment(equipmentSlot_t xSlot, QString name, int damage, int defence,
                             int strength, int intellect, int agility, int critic, int haste)
{
    Equipment newEquipment = Equipment(xSlot);
    newEquipment.Change(xSlot, name, damage, defence, strength, intellect, agility, critic, haste);

    this->axEquipments.push_back(newEquipment);
}

/*!
 * \brief           Add a consumable to the inventory
 * 
 * \param[in]       name: Name of the consumable
 * \param[in]       regenHealth: Regen value of health
 * \param[in]       regenMana: Regen value of mana
 */
void Inventory::AddConsumable(QString name, int regenHealth, int regenMana)
{
    Consumable newConsumable = Consumable(name, regenHealth, regenMana);

    this->axConsumables.push_back(newConsumable);
}

/*!
 * \brief           Add a tradeskill item to the inventory
 * 
 * \param[in]       name: Name of the tradeskill item
 */
void Inventory::AddTradeskill(QString name)
{
    Tradeskill newTradeskill = Tradeskill(name);

    this->axTraderskills.push_back(newTradeskill);
}

/*!
 * \brief           Remove the equipment item according to its name
 * 
 * \param[in]       name: Name of the item
 */
void Inventory::RemoveEquipment(QString name)
{
    /* Get the index of the item to erase */
    int index = Inventory::getIndex(EQUIPMENT, name);
    /* Erase the desired item */
    this->axEquipments.erase(this->axEquipments.begin() + index);
}

/*!
 * \brief           Remove the consumable item according to its item
 * 
 * \param[in]       name: Name of the item
 */
void Inventory::RemoveConsumable(QString name)
{
    /* Get the index of the item to erase */
    int index = Inventory::getIndex(CONSUMABLE, name);
    /* Erase the desired item */
    this->axConsumables.erase(this->axConsumables.begin() + index);
}

/*!
 * \brief           Remove the tradeskill item acording to its name
 * 
 * \param[in]       name: Name of the item
 */
void Inventory::RemoveTradeskill(QString name)
{
    /* Get the index of the item to erase */
    int index = Inventory::getIndex(TRADESKILL, name);
    /* Erase the desired item */
    this->axTraderskills.erase(this->axTraderskills.begin() + index);
}

/*!
 * \brief           Get the index of the vector according to the type of item ans the name of the
 *                  item
 * 
 * \param[in]       xType: Type of the item
 * \param[in]       name: Name of the item
 * \retval          Return the index of the item in the vector
 */
int Inventory::getIndex(itemType_t xType, QString name) const
{
    int index = INT_MAX;
    int iter;

    switch (xType)
    {
    case EQUIPMENT:
        for (iter = 0; iter != this->axEquipments.size(); iter++) {
            if (name == this->axEquipments[iter].name) {
                index = iter;
                break;
            }
        }
        break;
    
    case CONSUMABLE:
        for (iter = 0; iter != this->axConsumables.size(); iter++) {
            if (name == this->axConsumables[iter].name) {
                index = iter;
                break;
            }
        }
        break;
    
    case TRADESKILL:
        for (iter = 0; iter != this->axTraderskills.size(); iter++) {
            if (name == this->axTraderskills[iter].name) {
                index = iter;
                break;
            }
        }
        break;
    
    default:
        index = -1;
        break;
    }

    /* Check if the item is find */
    if (INT_MAX == index) {
        index = -1;
    }

    return index;
}
