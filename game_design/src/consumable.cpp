#include "consumable.h"

/*!
 * \brief           Construct a new Consumable:: Consumable object
 * 
 * \param[in]       name: Name of the consumable
 * \param[in]       regenHealth: Regen value of health
 * \param[in]       regenMana: Regen value of mana
 */
Consumable::Consumable(std::string name, int regenHealth, int regenMana)
{
    this->name = name;
    this->regenHealth = regenHealth;
    this->regenMana = regenMana;
}

/*!
 * \brief           Show details of the consumable
 */
void Consumable::Print(void) const
{
    std::cout << "Consomable : " << this->name << " (Regain de vie : " << this->regenHealth <<
        " | Regain de mana : " << this->regenMana << std::endl;
}