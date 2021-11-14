#ifndef START_MENU_H
#define START_MENU_H

#include <iostream>
#include <QtWidgets>

#include "common.h"

class StartMenu : public QWidget
{
Q_OBJECT

public:
    /* Constructor & Destructor */
    StartMenu(int index);
    ~StartMenu();

public slots:
    void SlotEnterInGame(void);

signals:
    void SignalEnterInGame(int index);

private:
    /* Private variables */
    int widgetIndex;

    /* Elements of interface frame */
    QFrame *pFrameInterface;
    QLabel *pLabelLogo;

    /* Elements of the nagivation frame */
    QFrame *pFrameNavigation;
    QPushButton *pButtonEnter;

    /* Layouts */
    QGridLayout *pLayoutInterface;
    QHBoxLayout *pLayoutNavigation;
    QGridLayout *pLayoutMain;
};

#endif /* START_MENU_H */