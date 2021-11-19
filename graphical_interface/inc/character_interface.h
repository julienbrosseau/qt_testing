#ifndef CHARACTER_INTERFACE_H
#define CHARACTER_INTERFACE_H

#include <iostream>
#include <QtWidgets>

#include "common.h"
#include "character.h"

class CharacterInterface : public QWidget
{
Q_OBJECT

public:
    /* Constructor & Destructor */
    CharacterInterface(int index);
    ~CharacterInterface();

    /* Public functions */
    void DisplayCharacterInterface(Character *pCharacter);
    void DisplayCharacterCaracteristic(Character *pCharacter);

public slots:
    void SlotExitInterface(void);

signals:
    void SignalExitInterface(int index);

private:
    /* Private variables */
    int widgetIndex;

    /* Elements of the naviguation frame */
    QFrame *pFrameNavigation;
    QPushButton *pButtonExit;

    /* Elements of the character frame */
    QFrame *pFrameCharacter;
    QLabel *pLabelHead;
    QLabel *pLabelChest;
    QLabel *pLabelLegs;
    QLabel *pLabelWeapon;
    QLabel *pLabelDisplay;

    /* Elements of the character caracteristics */
    QFrame *pFrameCarac;
    QLabel *pLabelGeneral;
    QLabel *pLabelHealth;
    QLabel *pLabelMana;
    QLabel *pLabelDamage;
    QLabel *pLabelDefense;
    QLabel *pLabelAttributes;
    QLabel *pLabelStrength;
    QLabel *pLabelIntellect;
    QLabel *pLabelAgility;
    QLabel *pLabelCritic;
    QLabel *pLabelHaste;

    /* Elements of the inventory frame */
    QFrame *pFrameInventory;
    QLabel *pLabelInventory;

    /* Layouts */
    QHBoxLayout *pLayoutNavigation;
    QGridLayout *pLayoutCharacter;
    QVBoxLayout *pLayoutCarac;
    QHBoxLayout *pLayoutInventory;
    QGridLayout *pLayoutMain;
};

#endif /* CHARACTER_INTERFACE_H */