/*!
 * \file            move_character.cpp
 * \author          Julien Brosseau (https://github.com/julienbrosseau)
 * \brief           File based on https://www.badprog.com/c-qt-framework-moving-a-shape-with-arrow-keys 
 */
 
#include "move_character.h"
#include <QPainter>
#include <QDebug>

/*!
 * \brief           Construct a new Move Character:: Move Character object
 * 
 */
MoveCharacter::MoveCharacter(QWidget *parent = Q_NULLPTR) : QWidget(parent)
{
    MoveCharacter::pointX = 200;
    MoveCharacter::pointY = 100;
    MoveCharacter::step = 10;
    MoveCharacter::ellipseWidth = 100;
    MoveCharacter::ellipseHeight = 100;
    MoveCharacter::ellipsePen = 1;
    QWidget::setFocusPolicy(Qt::StrongFocus);
}

/*!
 * \brief           Destroy the Move Character:: Move Character object
 * 
 */
MoveCharacter::~MoveCharacter()
{

}

/*!
 * \brief           Get key press events to move character
 * 
 * \param[in]       keyEvent: key event (directional arrows)
 */
void MoveCharacter::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_Down:
        MoveCharacter::pointY += MoveCharacter::step;
        qDebug() << "Down";
        this->parentWidget()->update();
        break;

    case Qt::Key_Left:
        MoveCharacter::pointX -= MoveCharacter::step;
        qDebug() << "Left";
        this->parentWidget()->update();
        break;

    case Qt::Key_Right:
        MoveCharacter::pointX += MoveCharacter::step;
        qDebug() << "Right";
        this->parentWidget()->update();
        break;

    case Qt::Key_Up:
        MoveCharacter::pointY -= MoveCharacter::step;
        qDebug() << "Up";
        this->parentWidget()->update();
        break;

    default:
        break;
    }
}
