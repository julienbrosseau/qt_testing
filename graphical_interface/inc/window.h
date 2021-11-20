#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <tuple>
#include <QtWidgets>

#include "section.h"
#include "start_menu.h"
#include "level_selection.h"
#include "character_interface.h"

class Window : public QMainWindow
{
Q_OBJECT

public:
    /* Constructors */
    Window(void);
    ~Window();

public slots:
    void SlotDisplaySection(int index);

private:
    /* Private function */
    std::tuple<int, int> GetSizeOfDesktop(void);

    /* Private variables */
    QStackedWidget *stack;

public:
    /* Public variables */
    StartMenu *pStartMenu;
    LevelSelection *pLevelSelection;
    Section *section1;
    Section *section2;
    Section *section3;
    Section *section4;
    CharacterInterface *pCharacterInterface;
};

#endif /* WINDOW_H */
