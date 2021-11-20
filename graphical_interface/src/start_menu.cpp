#include "start_menu.h"

#define BTN_MSG_ENTER_IN_GAME   "Entrer en jeu"
#define HELP_MSG_ENTER_IN_GAME  "Cliquer pour commencer le jeu"

StartMenu::StartMenu(int index) : QWidget()
{
    /* Set the widget number */
    StartMenu::widgetIndex = index;

    /* Initialize elements of the interface frame */
    StartMenu::pFrameInterface = new QFrame;
    StartMenu::pLabelLogo = new QLabel("Logo slot");

    /* Initialize elements of the navigation frame */
    StartMenu::pFrameNavigation = new QFrame;
    StartMenu::pButtonEnter = new QPushButton(BTN_MSG_ENTER_IN_GAME);
    CMN_SetUpButton(StartMenu::pButtonEnter, HELP_MSG_ENTER_IN_GAME);
    QObject::connect(StartMenu::pButtonEnter, SIGNAL(clicked()),
                     this, SLOT(SlotEnterInGame()));

    /* Initialize layouts */
    StartMenu::pLayoutInterface = new QGridLayout;
    StartMenu::pLayoutNavigation = new QHBoxLayout;
    StartMenu::pLayoutMain = new QGridLayout;

    /* Set up interface frame */
    StartMenu::pLayoutInterface->addWidget(StartMenu::pLabelLogo, 0, 0, 1, 1);
    StartMenu::pFrameInterface->setLayout(StartMenu::pLayoutInterface);

    /* Set up navigation frame */
    StartMenu::pLayoutNavigation->addWidget(StartMenu::pButtonEnter, 1, Qt::AlignCenter);
    StartMenu::pFrameNavigation->setLayout(StartMenu::pLayoutNavigation);

    /* Set up the whole */
    StartMenu::pLayoutMain->addWidget(StartMenu::pFrameInterface, 0, 0, 14, 1);
    StartMenu::pLayoutMain->addWidget(StartMenu::pFrameNavigation, 15, 0, 1, 1);
    this->setLayout(StartMenu::pLayoutMain);
}

StartMenu::~StartMenu()
{
    /* Delete elements of navigation frame */
    delete StartMenu::pButtonEnter;

    /* Delete elements of interface frame */
    delete StartMenu::pLabelLogo;

    /* Delete layouts */
    delete StartMenu::pLayoutNavigation;
    delete StartMenu::pLayoutInterface;

    /* Delete frames */
    delete StartMenu::pFrameNavigation;
    delete StartMenu::pFrameInterface;

    delete StartMenu::pLayoutMain;
}

void StartMenu::SlotEnterInGame(void)
{
    emit StartMenu::SignalEnterInGame(LEVEL_SELEC);
}