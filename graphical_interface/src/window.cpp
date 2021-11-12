#include "window.h"

#define WIDTH_DELTA 100
#define HEIGHT_DELTA 100

/*!
 * \brief           Constructor of the class "Window"
 */
Window::Window(void) : QMainWindow()
{
    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = Window::GetSizeOfDesktop();

    /* Generate the window */
    this->setFixedSize(width - WIDTH_DELTA, height - HEIGHT_DELTA);

    /* Initialize the stack */
    Window::stack = new QStackedWidget(this);
    /* Initialize sections */
    Window::section1 = new Section(1, "Section 1");
    Window::section2 = new Section(2, "Section 2");
    Window::section3 = new Section(3, "Section 3");
    Window::section4 = new Section(4, "Section 4");

    /* Add sections to the stack */
    Window::stack->addWidget(Window::section1);
    Window::stack->addWidget(Window::section2);
    Window::stack->addWidget(Window::section3);
    Window::stack->addWidget(Window::section4);

    /* Set up the section to display */
    this->setCentralWidget(Window::stack);
    Window::stack->setCurrentIndex(0);

    /* Connect each section to switch the current dispalyed section */
    QObject::connect(Window::section1, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section2, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section3, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section4, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));

}

/*!
 * \brief           Destructor of the class "Window"
 */
Window::~Window(void)
{
    delete Window::section1;
    delete Window::section2;
    delete Window::section3;
    delete Window::section4;
}

/*!
 * \brief           Slot to switch the displayed section
 *
 * \param[in]       index: Index of the section to diplay
 */
void Window::SlotDisplaySection(int index)
{
    Window::stack->setCurrentIndex(index);
}

/*!
 * \brief           Get the size of the host desktop
 * 
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