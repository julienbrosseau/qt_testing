#ifndef MOVE_CHARACTER_H
#define MOVE_CHARACTER_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>

class MoveCharacter : public QWidget
{
    Q_OBJECT

public:
    MoveCharacter(QWidget *parent);
    ~MoveCharacter();

protected:
    void keyPressEvent(QKeyEvent *keyEvent);

public:
    int pointX;
    int pointY;
    int step;
    int ellipseWidth;
    int ellipseHeight;
    int ellipsePen;
};

#endif /* MOVE_CHARACTER_H */