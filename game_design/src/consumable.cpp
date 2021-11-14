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
    Consumable::name = name;
    Consumable::regenHealth = regenHealth;
    Consumable::regenMana = regenMana;
}

/*!
 * \brief           Show details of the consumable
 */
void Consumable::Print(void) const
{
    std::cout << "Consomable : " << Consumable::name << " (Regain de vie : " << 
        Consumable::regenHealth << " | Regain de mana : " << Consumable::regenMana << std::endl;
}