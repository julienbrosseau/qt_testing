/*!*************************************************************************************************
 * \file            move_character.cpp
 * \author          Julien Brosseau (https://github.com/julienbrosseau)
 * \brief           File based on https://www.badprog.com/c-qt-framework-moving-a-shape-with-arrow-keys 
 **************************************************************************************************/

#include "move_character.h"

/*!
 * \brief           Construct a new Move Character:: Move Character object
 * 
 * \param[in]       parent: QWidget parent of the class
 */
MoveCharacter::MoveCharacter(QWidget *parent) : QWidget(parent)
{
    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = CMN_GetSizeOfDesktop();

    MoveCharacter::pointX = width - WIDTH_DELTA;
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
 * \brief           Check if there is a collision between the character and enemies
 * 
 * \retval          true: There is a collision
 * \retval          false: There is not a collision
 */
bool MoveCharacter::CheckCollision(int numberOfEnnemies)
{
    bool isCollision = false;

    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = CMN_GetSizeOfDesktop();

    /* Define collision points */
    int collisionBefore = ((width - WIDTH_DELTA) / 2) - (CHARAC_WIDTH / 2);
    int collisionAfter = ((width - WIDTH_DELTA) / 2) + (CHARAC_WIDTH / 2);

    /* Check if there is a collision */
    int leftCollision = MoveCharacter::pointX;
    int rightCollision = MoveCharacter::pointX + CHARAC_WIDTH;

    for (int i = 0; i < numberOfEnnemies; i++) {
        /* Check the left collision of an ennemy */
        if ((collisionBefore < leftCollision + (i * 50)) && 
                (collisionAfter > leftCollision + (i * 50))) {
            isCollision = true;
        }
        /* Check the right collision with an ennemy */
        if ((collisionBefore < rightCollision + (i * 50)) && 
                (collisionAfter > rightCollision + (i * 50))) {
            isCollision = true;
        }
    }

    return isCollision;
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
        MoveCharacter::pointX += MoveCharacter::step;
        // qDebug() << "Left";
        this->parentWidget()->update();
        // std::cout << "Ca bouge" << std::endl;
        if (true == MoveCharacter::CheckCollision(NB_ENEMIES)) {
            std::cout << "Ca touche" << std::endl;
        }
        break;

    case Qt::Key_Right:
        MoveCharacter::pointX -= MoveCharacter::step;
        // qDebug() << "Right";
        this->parentWidget()->update();
        // std::cout << "Ca bouge" << std::endl;
        if (true == MoveCharacter::CheckCollision(NB_ENEMIES)) {
            std::cout << "Ca touche" << std::endl;
        }
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
