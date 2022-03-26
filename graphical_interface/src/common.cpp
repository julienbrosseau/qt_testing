#include "common.h"

/*!
 * \brief           Set up the button passed in parameter
 * 
 * \param[in]       pButton: Button to set up
 * \param[in]       help: Help text of the button
 */
void CMN_SetUpButton(QPushButton *pButton, QString help)
{
    pButton->setToolTip(help);
    pButton->setFont(QFont("Courier", 12));
    pButton->setCursor(Qt::PointingHandCursor);
}

/*!
 * \brief           Get the size of the host desktop
 * 
 * \param[out]      width: Width of the host desktop
 * \param[out]      height: Height of the host desktop          
 */
std::tuple<int, int> CMN_GetSizeOfDesktop(void)
{
    QRect desktop = QApplication::desktop()->screenGeometry();

    int width = desktop.width();
    int height = desktop.height();

    return std::make_tuple(width, height);
}
