#include "character.h"

/*!
 * \brief           Construct a new Character:: Character object
 */
Character::Character(void)
{
    Character::maxHeart = 100;
    Character::nbHeart = 100;
    Character::nbMana = 100;
    Character::pArmorHead = new Equipment(NOTHING);
    Character::pArmorChest = new Equipment(ARMOR_CHEST);
    Character::pArmorLegs = new Equipment(NOTHING);
    Character::pWeapon = new Equipment(WEAPON);
    Character::pInventory = new Inventory();
    Character::damage = Character::pWeapon->damage;
    Character::defense = Character::pArmorHead->defense + Character::pArmorChest->defense +
                         Character::pArmorLegs->defense;
    Character::strength = 0;
    Character::intellect = 0;
    Character::agility = 0;
    Character::critic = 0;
    Character::haste = 0;
}

/*!
 * \brief           Destroy the Character:: Character object
 */
Character::~Character(void)
{
    delete(Character::pArmorHead);
    delete(Character::pArmorChest);
    delete(Character::pArmorLegs);
    delete(Character::pWeapon);
    delete(Character::pInventory);
}

/*!
 * \brief           Update the number of hearts according to taken damages
 * 
 * \param[in]       nbDamage: Taken damage by the character
 */
void Character::GetDamages(int nbDamage)
{
    Character::nbHeart = std::max(0, Character::nbHeart - nbDamage);
}

/*!
 * \brief           Set damages to a target according to the current weapon
 *                  damages
 * \param[in]       target: Targeted character of the attack
 */
void Character::SetAttack(Character &target)
{
    target.GetDamages(Character::pWeapon->damage);
}

/*!
 * \brief           Update the number of hearts according to healing
 * 
 * \param[in]       nbHeart: Number of gained heart
 */
void Character::GetHealing(int nbHeart)
{
    Character::nbHeart = std::min(Character::maxHeart, Character::nbHeart + nbHeart);
}

/*!
 * \brief           Change the head armor of the character
 * 
 * \param[in]       name: Name of the head armor
 * \param[in]       defense: Defense of the head armor
 * \param[in]       strength: Strength bonus of the head armor
 * \param[in]       intellect: Intellect bonus of the head armor
 * \param[in]       agility: Agility bonus of head armor
 * \param[in]       critic: Critical strike of the head armor
 * \param[in]       haste: Haste bonus of the head armor
 */
void Character::ChangeArmorHead(std::string name, int defense, int strength, int intellect,
                                int agility, int critic, int haste)
{
    /* Store the old head armor */
    Equipment *pOldArmorHead = Character::pArmorHead;

    /* Change the old head armor by the new one */
    Character::pArmorHead->Change(ARMOR_HEAD, name, 0, defense,
                                  strength, intellect, agility, critic, haste);

    /* Update caracteristics according to both head armors */
    Character::UpdateCarac(pOldArmorHead, Character::pArmorHead);
}

/*!
 * \brief           Change the chest armor of the character
 * 
 * \param[in]       name: Name of the chest armor
 * \param[in]       defense: Defense of the chest armor
 * \param[in]       strength: Strength bonus of the chest armor
 * \param[in]       intellect: Intellect bonus of the chest armor
 * \param[in]       agility: Agility bonus of chest armor
 * \param[in]       critic: Critical strike of the chest armor
 * \param[in]       haste: Haste bonus of the chest armor
 */
void Character::ChangeArmorChest(std::string name, int defense, int strength, int intellect,
                                int agility, int critic, int haste)
{
    /* Store the old chest armor */
    Equipment *pOldArmorChest = Character::pArmorChest;

    /* Change the old chest armor by the new one */
    Character::pArmorChest->Change(ARMOR_CHEST, name, 0, defense,
                                   strength, intellect, agility, critic, haste);
    
    /* Update caracteristics according to both chest armors */
    Character::UpdateCarac(pOldArmorChest, Character::pArmorChest);
}

/*!
 * \brief           Change the legs armor of the character
 * 
 * \param[in]       name: Name of the legs armor
 * \param[in]       defense: Defense of the legs armor
 * \param[in]       strength: Strength bonus of the legs armor
 * \param[in]       intellect: Intellect bonus of the legs armor
 * \param[in]       agility: Agility bonus of legs armor
 * \param[in]       critic: Critical strike of the legs armor
 * \param[in]       haste: Haste bonus of the legs armor
 */
void Character::ChangeArmorLegs(std::string name, int defense, int strength, int intellect,
                                int agility, int critic, int haste)
{
    /* Store the old legs armor */
    Equipment *pOldArmorLegs = Character::pArmorLegs;

    /* Change the old legs armor by the new one */
    Character::pArmorLegs->Change(ARMOR_LEGS, name, 0, defense,
                                  strength, intellect, agility, critic, haste);
    
    /* Update caracteristics according to both legs armors */
    Character::UpdateCarac(pOldArmorLegs, Character::pArmorLegs);
}

/*!
 * \brief           Change the weapon of the character
 * 
 * \param[in]       name: Name of the weapon
 * \param[in]       damage: Damage of the weapon
 * \param[in]       strength: Strength bonus of the weapon
 * \param[in]       intellect: Intellect bonus of the weapon
 * \param[in]       agility: Agility bonus of the weapon
 * \param[in]       critic: Critical strike bonus of the weapon
 * \param[in]       haste: Haste bonus of the weapon
 */
void Character::ChangeWeapon(std::string name, int damage, int strength, int intellect,
                             int agility, int critic, int haste)
{   
    /* Store the old weapon */
    Equipment *pOldWeapon = Character::pWeapon;

    /* Change the old weapon by the new one */
    Character::pWeapon->Change(WEAPON, name, damage, 0,
                               strength, intellect, agility, critic, haste);

    /* Update caracteristics according to both weapons */
    Character::UpdateCarac(pOldWeapon, Character::pWeapon);
}

/*!
 * \brief           Update caracteristics according to the old equipment and the new one
 * 
 * \param[in]       pOldEquipment: Old equipment
 * \param[in]       pNewEquipment: New equipment
 */
void Character::UpdateCarac(Equipment *pOldEquipment, Equipment *pNewEquipment)
{
    Character::damage += pNewEquipment->damage - pOldEquipment->damage;
    Character::defense += pNewEquipment->defense - pOldEquipment->defense;
    Character::strength += pNewEquipment->strength - pOldEquipment->strength;
    Character::intellect += pNewEquipment->intellect - pOldEquipment->intellect;
    Character::agility += pNewEquipment->agility - pOldEquipment->agility;
    Character::critic += pNewEquipment->critic - pOldEquipment->critic;
    Character::haste += pNewEquipment->haste - pOldEquipment->haste;
}

/*!
 * \brief           Check if the character is alive
 * 
 * \retval          Result of the checking
 */
bool Character::IsAlive(void) const
{
    bool isAlive = 0 > Character::nbHeart;

    return isAlive;
}

/*!
 * \brief           Show details of the character
 */
void Character::Print() const
{
    std::cout << "Vie : " << Character::nbHeart << std::endl;
    std::cout << "Mana : " << Character::nbMana << std::endl;
    Character::pArmorHead->Print();
    Character::pArmorChest->Print();
    Character::pArmorLegs->Print();
    Character::pWeapon->Print();
}
