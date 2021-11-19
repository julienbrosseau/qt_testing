#include <iostream>
#include <QApplication>

#include "window.h"
#include "character.h"
#include "consumable.h"
#include "tradeskill.h"

/*!
 * \brief           Main function
 */
int main(int argc, char *argv[])
{   
    std::cout << "Starting program ..." << std::endl;

    /* Generate the application */
    QApplication app(argc, argv);

    /* Generate and diplay the window */
    Window window;
    window.show();

    /* Create a character */
    Character characterOne;
    std::cout << "Personnage - détails :" << std::endl;
    characterOne.Print();

    /* Create a consumable */
    Consumable healthPotion = Consumable("Fiole de vie", 10, 0);
    healthPotion.Print();

    /* Create a tradeskill item */
    Tradeskill leather = Tradeskill("leather");
    leather.Print();

    /* Add items to the inventory */
    characterOne.pInventory->AddConsumable(healthPotion.name, healthPotion.regenHealth,
                                          healthPotion.regenMana);
    characterOne.pInventory->AddTradeskill(leather.name);

    /* Diplay character one */
    window.pCharacterInterface->DisplayCharacterInterface(&characterOne);
    window.pCharacterInterface->DisplayCharacterCaracteristic(&characterOne);

    return app.exec();
}