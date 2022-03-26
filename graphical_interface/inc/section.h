#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <QtWidgets>
#include <QPainter>

#include "move_character.h"

class Section : public QWidget
{
Q_OBJECT

public:
    /* Constructors */
    Section(int index, QString name);
    ~Section();

    /* Public variables */
    QPushButton *pExitButton;
    MoveCharacter *pShape;

protected:
    void paintEvent(QPaintEvent *event);

private:
    /* Elements of level frame */
    QFrame *pFrameLevel;

    /* Elements of the nagivation frame */
    QFrame *pFrameNavigation;
    QPushButton *pButtonExit;

    /* Layouts */
    QGridLayout *pLayoutLevel;
    QHBoxLayout *pLayoutNavigation;
    QGridLayout *pLayoutMain;

    /* Private variables */
    int indexSection;
    int characWidth;
    int characHeight;
    int characPen;

public slots:
    void SlotExitLevel(void);

signals:
    void SignalExitLevel(int index);
};

#endif /* SECTION_H */
