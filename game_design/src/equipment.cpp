#include "equipment.h"

/*!
 * \brief           Construct a new Equipment:: Equipment object
 * 
 * \param[in]       xSlot: Equipment slot
 */
Equipment::Equipment(equipmentSlot_t xSlot)
{
    switch (xSlot)
    {
    case ARMOR_HEAD:
        Equipment::name = "Capuche décousue";
        Equipment::damage = 0;
        Equipment::defense = 0;
        break;
    
    case ARMOR_CHEST:
        Equipment::name = "Chemise décousue";
        Equipment::damage = 0;
        Equipment::defense = 2;
        break;

    case ARMOR_LEGS:
        Equipment::name = "Chausse trouée";
        Equipment::damage = 0;
        Equipment::defense = 1;
        break;
    
    case WEAPON:
        Equipment::name = "Couteau rouillée";
        Equipment::damage = 2;
        Equipment::defense = 0;
        break;

    case NOTHING:
        Equipment::name = "Emplacement vide";
        Equipment::damage = 0;
        Equipment::defense = 0;
        break;

    default:
        Equipment::name = "Emplacement vide";
        Equipment::damage = 0;
        Equipment::defense = 0;
        break;
    }

    Equipment::strength = 0;
    Equipment::intellect = 0;
    Equipment::agility = 0;
    Equipment::critic = 0;
    Equipment::haste = 0;

    Equipment::xSlot = xSlot;
}

/*!
 * \brief           Change the equipment accroding to parameters
 * 
 * \param[in]       xSlot: define the slot of the equipment
 * \param[in]       name: define the name of the equipement
 * \param[in]       damage: define the damage of the equipment
 * \param[in]       defence: define the defence of the equipment
 * \param[in]       strength: define the strength bonus of the equipment (default value: 0)
 * \param[in]       intellect: define the intellect bonus of the equipment (default value: 0)
 * \param[in]       agility: define the agility bonus of the equipment (default value: 0)
 * \param[in]       critic: define the critical strike bonus of the equipment (default value: 0)
 * \param[in]       haste: define the haste bonus of the equipment (default value: 0)
 */
void Equipment::Change(equipmentSlot_t xSlot, std::string name, int damage, int defence,
                       int strength, int intellect, int agility, int critic, int haste)
{
    /* Set the description of the equipment */
    Equipment::xSlot = xSlot;
    Equipment::name = name;

    /* Set main caracteristics */
    Equipment::damage = damage;
    Equipment::defense = defense;

    /* Set off caracteristics */
    Equipment::strength = strength;
    Equipment::intellect = intellect;
    Equipment::agility = agility;
    Equipment::critic = critic;
    Equipment::haste = haste;
}

/*!
 * \brief           Show details of the equipment
 */
void Equipment::Print() const
{
    if (WEAPON == Equipment::xSlot) {
        std::cout << "Arme : " << Equipment::name << " (Dégats : " << Equipment::damage << ")"
            << std::endl;
    
    } else {
        std::cout << "Armure : " << Equipment::name << " (Défence : " << Equipment::defense << ")"
            << std::endl;

    }
}