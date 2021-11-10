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
    characterOne.inventory->AddConsumable(healthPotion.name, healthPotion.regenHealth,
                                          healthPotion.regenMana);
    characterOne.inventory->AddTradeskill(leather.name);
 
    return app.exec();
}