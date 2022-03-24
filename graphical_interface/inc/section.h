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

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void SlotSwitchSection(void);

signals:
    void SignalSwitchSection(int index);

private:
    /* Private variables */
    int indexSection;
    int ellipseWidth;
    int ellipseHeight;
    int ellipsePen;

public:
    /* Public variables */
    QPushButton *pExitButton;
    MoveCharacter *pShape;

};

#endif /* SECTION_H */
