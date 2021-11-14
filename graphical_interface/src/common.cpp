#include "common.h"

void CMN_SetUpButton(QPushButton *pButton, QString help)
{
    pButton->setToolTip(help);
    pButton->setFont(QFont("Courier", 12));
    pButton->setCursor(Qt::PointingHandCursor);
}
