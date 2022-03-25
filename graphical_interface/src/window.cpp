#include "window.h"

/*!
 * \brief           Constructor of the class "Window"
 */
Window::Window(void) : QMainWindow()
{
    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = GetSizeOfDesktop();

    /* Generate the window */
    this->setFixedSize(width - WIDTH_DELTA, height - HEIGHT_DELTA);

    /* Initialize the stack */
    Window::stack = new QStackedWidget(this);
    /* Initialize sections */
    Window::pStartMenu = new StartMenu(START_MENU);
    Window::pLevelSelection = new LevelSelection(LEVEL_SELEC);
    Window::pCharacterInterface = new CharacterInterface(CHARAC_INTERFACE);
    Window::section1 = new Section(3, "Section 1");
    Window::section2 = new Section(4, "Section 2");
    Window::section3 = new Section(5, "Section 3");
    Window::section4 = new Section(6, "Section 4");
    Window::section5 = new Section(7, "Section 5");

    /* Add sections to the stack */
    Window::stack->addWidget(Window::pStartMenu);
    Window::stack->addWidget(Window::pLevelSelection);
    Window::stack->addWidget(Window::pCharacterInterface);
    Window::stack->addWidget(Window::section1);
    Window::stack->addWidget(Window::section2);
    Window::stack->addWidget(Window::section3);
    Window::stack->addWidget(Window::section4);
    Window::stack->addWidget(Window::section5);

    /* Set up the section to display */
    this->setCentralWidget(Window::stack);
    Window::stack->setCurrentIndex(0);

    /* Connect each section to switch the current dispalyed section */
    QObject::connect(Window::pStartMenu, SIGNAL(SignalEnterInGame(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::pLevelSelection, SIGNAL(SignalSwitchWidget(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::pLevelSelection, SIGNAL(SignalInventory(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section1, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section2, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section3, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section4, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::section5, SIGNAL(SignalSwitchSection(int)),
                     this, SLOT(SlotDisplaySection(int)));
    QObject::connect(Window::pCharacterInterface, SIGNAL(SignalExitInterface(int)),
                     this, SLOT(SlotDisplaySection(int)));
    
    this->setStyleSheet(
        "QWidget {"
            "border: 1px solid black;"
            "color: red"
        "}"
    );
}

/*!
 * \brief           Destructor of the class "Window"
 */
Window::~Window(void)
{
    delete Window::pStartMenu;
    delete Window::pLevelSelection;
    delete Window::section1;
    delete Window::section2;
    delete Window::section3;
    delete Window::section4;
    delete Window::section5;
    delete Window::pCharacterInterface;
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
