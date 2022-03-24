#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <QtWidgets>

typedef enum indexWidget
{
    START_MENU = 0,
    LEVEL_SELEC,
    CHARAC_INTERFACE
} indexWidget_t;

void CMN_SetUpButton(QPushButton *pButton, QString help);

#endif /* COMMON_H */
