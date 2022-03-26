/*!*************************************************************************************************
 * \file            move_character.cpp
 * \author          Julien Brosseau (https://github.com/julienbrosseau)
 * \brief           File based on https://www.badprog.com/c-qt-framework-moving-a-shape-with-arrow-keys 
 **************************************************************************************************/

#include "move_character.h"

/*!
 * \brief           Construct a new Move Character:: Move Character object
 * 
 */
MoveCharacter::MoveCharacter(QWidget *parent = Q_NULLPTR) : QWidget(parent)
{
    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = CMN_GetSizeOfDesktop();

    MoveCharacter::pointX = START_POINT_X;
    MoveCharacter::pointY = height - HEIGHT_DELTA - CHARAC_HEIGHT - START_POINT_Y;
    MoveCharacter::step = 5;
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
    // case Qt::Key_Down:
    //     MoveCharacter::pointY += MoveCharacter::step;
    //     qDebug() << "Down";
    //     this->parentWidget()->update();
    //     break;

    case Qt::Key_Left:
        MoveCharacter::pointX -= MoveCharacter::step;
        // qDebug() << "Left";
        this->parentWidget()->update();
        break;

    case Qt::Key_Right:
        MoveCharacter::pointX += MoveCharacter::step;
        // qDebug() << "Right";
        this->parentWidget()->update();
        break;

    // case Qt::Key_Up:
    //     MoveCharacter::pointY -= MoveCharacter::step;
    //     qDebug() << "Up";
    //     this->parentWidget()->update();
    //     break;

    default:
        break;
    }
}
