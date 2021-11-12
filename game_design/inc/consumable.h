#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
#include <QtWidgets>

/*!
 * \brief           Class 'Consumable'
 */
class Consumable
{
public:
    /* Constructor */
    Consumable(QString name, int regenHealth, int regenMana);

    /* Public function */
    void Print(void) const;

    /* Public variables */
    QString name;
    int regenHealth;
    int regenMana;

};

#endif /* CONSUMABLE_H */