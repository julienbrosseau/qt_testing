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
        this->name = "Capuche décousue";
        this->damage = 0;
        this->defense = 0;
        break;
    
    case ARMOR_CHEST:
        this->name = "Chemise décousue";
        this->damage = 0;
        this->defense = 3;
        break;

    case ARMOR_LEGS:
        this->name = "Chausse trouée";
        this->damage = 0;
        this->defense = 1;
        break;
    
    case WEAPON:
        this->name = "Couteau rouillée";
        this->damage = 2;
        this->defense = 0;
        break;

    case NOTHING:
        this->name = "Emplacement vide";
        this->damage = 0;
        this->defense = 0;
        break;

    default:
        this->name = "Emplacement vide";
        this->damage = 0;
        this->defense = 0;
        break;
    }

    this->strength = 0;
    this->intellect = 0;
    this->agility = 0;
    this->critic = 0;
    this->haste = 0;

    this->xSlot = xSlot;
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
    this->xSlot = xSlot;
    this->name = name;

    /* Set main caracteristics */
    this->damage = damage;
    this->defense = defense;

    /* Set off caracteristics */
    this->strength = strength;
    this->intellect = intellect;
    this->agility = agility;
    this->critic = critic;
    this->haste = haste;
}

/*!
 * \brief           Show details of the equipment
 */
void Equipment::Print() const
{
    if (WEAPON == this->xSlot) {
        std::cout << "Arme : " << this->name << " (Dégats : " << this->damage << ")"
            << std::endl;
    
    } else {
        std::cout << "Armure : " << this->name << " (Défence : " << this->defense << ")"
            << std::endl;

    }
}