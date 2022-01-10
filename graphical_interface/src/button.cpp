#include "button.h"

Button::Button() : QObject()
{
    Button::pButton = new QPushButton("Button");

    Button::pButton->setToolTip("Help button");
    Button::pButton->setFont(QFont("Courier", 12));
    Button::pButton->setCursor(Qt::PointingHandCursor);

    QObject::connect(Button::pButton, SIGNAL(clicked()),
                     this, SLOT(SlotSwitchWidget()));

    Button::indexSwitchedWidget = 0;
}

void Button::SlotSwitchWidget(void)
{
    emit Button::SignalSwitchWidget(Button::indexSwitchedWidget);
}