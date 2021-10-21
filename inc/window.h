#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <tuple>
#include <QtWidgets>

class Window : public QWidget
{
public:
    /* Constructors */
    Window(void);
    ~Window(void);

private:
    /* Private function */
    std::tuple<int, int> GetSizeOfDesktop(void);
    
    /* Private variables */
    QPushButton *button;
};

#endif /* WINDOW_H */
