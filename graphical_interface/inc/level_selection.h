#ifndef LEVEL_SELECTION_H
#define LEVEL_SELECTION_H

#include <iostream>
#include <QtWidgets>

#include "common.h"

#define NB_LEVELS 5

typedef void (*switchWidgetCallback_t)(int index);

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
    void SlotSwitchWidget(void);

signals:
    void SignalExitInterface(int index);
    void SignalInventory(int index);
    void SignalSwitchWidget(int index);

private:
    /* Private variables */
    typedef struct button
    {
        QPushButton *pButton;
        int indexSwitchedWidget;
    } button_t;

    int widgetIndex;

    /* Elements of interface frame */
    QScrollArea *pScrollBar;
    QFrame *pFrameLevel;
    QPushButton *paButtonLevel[NB_LEVELS];

    /* Elements of the nagivation frame */
    QFrame *pFrameNavigation;
    QPushButton *pButtonExit;
    QPushButton *pButtonInventory;

    /* Layouts */
    QHBoxLayout *pLayoutLevel;
    QHBoxLayout *pLayoutNavigation;
    QGridLayout *pLayoutMain;
};

#endif /* LEVEL_SELECTION_H */