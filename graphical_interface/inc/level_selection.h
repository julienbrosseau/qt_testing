#ifndef LEVEL_SELECTION_H
#define LEVEL_SELECTION_H

#include <iostream>
#include <QtWidgets>

#include "common.h"

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

signals:
    void SignalExitInterface(int index);
    void SignalInventory(int index);

private:
    /* Private variables */
    int widgetIndex;

    /* Elements of interface frame */
    QFrame *pFrameLevelSelection;
    QLabel *pLabelLevel1;

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