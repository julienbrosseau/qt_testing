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
MoveCharacter::MoveCharacter() : QWidget()
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
 * \brief           Painting the character to the focused window
 * 
 * \param[in]       event:
 */
void MoveCharacter::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    /* Initialize and define the size of the ellipse */
    QRectF rectangle(MoveCharacter::pointX, MoveCharacter::pointY, MoveCharacter::ellipseWidth,
                     MoveCharacter::ellipseHeight);
    /* Initialize and define the border the ellipse */
    QPen pen_ellipse(Qt::black);
    pen_ellipse.setWidth(MoveCharacter::ellipsePen);
    /* Initilize and draw the ellipse */
    QPainter painter;
    painter.begin(this);
    painter.setPen(pen_ellipse);
    painter.setBrush(Qt::cyan);
    painter.drawEllipse(rectangle);
    painter.end();
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
        QWidget::update();
        break;

    case Qt::Key_Left:
        MoveCharacter::pointX -= MoveCharacter::step;
        qDebug() << "Left";
        QWidget::update();
        break;

    case Qt::Key_Right:
        MoveCharacter::pointX += MoveCharacter::step;
        qDebug() << "Right";
        QWidget::update();
        break;

    case Qt::Key_Up:
        MoveCharacter::pointY -= MoveCharacter::step;
        qDebug() << "Up";
        QWidget::update();
        break;

    default:
        break;
    }
}
