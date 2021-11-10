#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
#include <string>

/*!
 * \brief           Class 'Consumable'
 */
class Consumable
{
public:
    /* Constructor */
    Consumable(std::string name, int regenHealth, int regenMana);

    /* Public function */
    void Print(void) const;

    /* Public variables */
    std::string name;
    int regenHealth;
    int regenMana;

};

#endif /* CONSUMABLE_H */