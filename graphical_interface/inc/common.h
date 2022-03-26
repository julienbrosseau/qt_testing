#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <QtWidgets>

/* Refering to window size */
#define WIDTH_DELTA 100
#define HEIGHT_DELTA 100
/* Refering to character */
#define CHARAC_WIDTH 100
#define CHARAC_HEIGHT 100
/* Refering to level design */
#define START_POINT_X 100
#define START_POINT_Y 100

typedef enum indexWidget
{
    START_MENU = 0,
    LEVEL_SELEC,
    CHARAC_INTERFACE
} indexWidget_t;

void CMN_SetUpButton(QPushButton *pButton, QString help);
std::tuple<int, int> CMN_GetSizeOfDesktop(void);

#endif /* COMMON_H */
