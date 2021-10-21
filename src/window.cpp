#include "window.h"

#define WIDTH_DELTA 100
#define HEIGHT_DELTA 100

/**
 * \brief           Constructor of the class "Window"
 */
Window::Window(void) : QWidget()
{
    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = Window::GetSizeOfDesktop();

    /* Generate a window */
    this->setFixedSize(width - WIDTH_DELTA, height - HEIGHT_DELTA);

    /* Initialize the button */
    Window::button = new QPushButton("Exit", this);
    
    /* Set up the button */
    Window::button->setToolTip("Close the window");
    Window::button->setFont(QFont("Courier", 12));
    Window::button->setCursor(Qt::PointingHandCursor);
    Window::button->move(60,50); /* TODO: Replace magic numbers */

    QObject::connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));
}

/**
 * \brief           Destructor of the class "Window"
 */
Window::~Window(void)
{
    delete Window::button;
}

/**
 * \brief           Get the size of the host desktop
 * \param[out]      width: Width of the host desktop
 * \param[out]      height: Height of the host desktop          
 */
std::tuple<int, int> Window::GetSizeOfDesktop(void)
{
    QRect desktop = QApplication::desktop()->screenGeometry();

    int width = desktop.width();
    int height = desktop.height();

    return std::make_tuple(width, height);
}
