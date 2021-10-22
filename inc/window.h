#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <tuple>
#include <QtWidgets>
#include "section.h"

class Window : public QMainWindow //QWidget
{
Q_OBJECT

public:
    /* Constructors */
    Window(void);
    ~Window();

public slots:
    void SlotDisplaySection(int index);

private:
    /* Private function */
    std::tuple<int, int> GetSizeOfDesktop(void);

    /* Private variables */
    QStackedWidget *stack;
    Section *section1;
    Section *section2;
    Section *section3;
    Section *section4;
};

#endif /* WINDOW_H */
