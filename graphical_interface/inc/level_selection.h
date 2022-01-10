#ifndef LEVEL_SELECTION_H
#define LEVEL_SELECTION_H

#include <iostream>
#include <QtWidgets>

#include "common.h"

#define NB_LEVELS 5

typedef struct button
{
    QPushButton *pButton;
    int indexSwitchedWidget;
    void (*SlotSwitchWidgetFxn)(int);
} button_t;

class LevelSelection : public QWidget
{
Q_OBJECT

public:
    /* Constructor & Desctructor */
    LevelSelection(int index);
    ~LevelSelection();

    /* Public functions */

public slots:
    void SlotExitInterface(void);
    void SlotInventory(void);
    void SlotSwitchWidget(int index);

signals:
    void SignalExitInterface(int index);
    void SignalInventory(int index);
    void SignalSwitchWidget(int index);

private:
    /* Private variables */
    int widgetIndex;

    /* Elements of interface frame */
    QScrollArea *pScrollBar;
    QFrame *pFrameLevelSelection;
    button_t aLevelSelection[NB_LEVELS];

    /* Elements of the nagivation frame */
    QFrame *pFrameNavigation;
    QPushButton *pButtonExit;
    QPushButton *pButtonInventory;

    /* Layouts */
    QHBoxLayout *pLayoutLevelSelection;
    QHBoxLayout *pLayoutNavigation;
    QGridLayout *pLayoutMain;
};

#endif /* LEVEL_SELECTION_H */