#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <QtWidgets>

typedef enum indexWidget
{
    START_MENU       = 0U,
    LEVEL_SELEC      = 1U,
    CHARAC_INTERFACE = 6U
} indexWidget_t;

void CMN_SetUpButton(QPushButton *pButton, QString help);

#endif /* COMMON_H */
