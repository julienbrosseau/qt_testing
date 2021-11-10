#include "character.h"

/*!
 * \brief           Construct a new Character:: Character object
 */
Character::Character(void)
{
    this->maxHeart = 100;
    this->nbHeart = 100;
    this->nbMana = 100;
    this->armorHead = new Equipment(NOTHING);
    this->armorChest = new Equipment(ARMOR_CHEST);
    this->armorLegs = new Equipment(NOTHING);
    this->weapon = new Equipment(WEAPON);
    this->inventory = new Inventory();
}

/*!
 * \brief           Destroy the Character:: Character object
 */
Character::~Character(void)
{
    delete(this->armorHead);
    delete(this->armorChest);
    delete(this->armorLegs);
    delete(this->weapon);
    delete(this->inventory);
}

/*!
 * \brief           Update the number of hearts according to taken damages
 * 
 * \param[in]       nbDamage: Taken damage by the character
 */
void Character::GetDamages(int nbDamage)
{
    this->nbHeart = std::max(0, this->nbHeart - nbDamage);
}

/*!
 * \brief           Set damages to a target according to the current weapon
 *                  damages
 * \param[in]       target: Targeted character of the attack
 */
void Character::SetAttack(Character &target)
{
    target.GetDamages(this->weapon->damage);
}

/*!
 * \brief           Update the number of hearts according to healing
 * 
 * \param[in]       nbHeart: Number of gained heart
 */
void Character::GetHealing(int nbHeart)
{
    this->nbHeart = std::min(this->maxHeart, this->nbHeart + nbHeart);
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
    this->armorHead->Change(ARMOR_HEAD, name, 0, defense,
                            strength, intellect, agility, critic, haste);
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
    this->armorChest->Change(ARMOR_CHEST, name, 0, defense,
                            strength, intellect, agility, critic, haste);
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
    this->armorLegs->Change(ARMOR_LEGS, name, 0, defense,
                            strength, intellect, agility, critic, haste);
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
    this->weapon->Change(WEAPON, name, damage, 0, strength, intellect, agility, critic, haste);
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
    std::cout << "Vie : " << this->nbHeart << std::endl;
    std::cout << "Mana : " << this->nbMana << std::endl;
    this->armorHead->Print();
    this->armorChest->Print();
    this->armorLegs->Print();
    this->weapon->Print();
}
