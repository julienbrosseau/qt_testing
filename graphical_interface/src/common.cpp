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
