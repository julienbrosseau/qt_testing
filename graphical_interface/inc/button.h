#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <QtWidgets>

class Button : public QObject
{

public:
    /* Constructor & Destructor */
    Button();
    ~Button();

    /* Public variables */
    QPushButton *pButton;
    int indexSwitchedWidget;

public slots:
    void SlotSwitchWidget(void);

signals:
    void SignalSwitchWidget(int index);

};

#endif /* BUTTON_H */