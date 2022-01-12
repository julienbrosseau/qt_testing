#include "level_selection.h"

#define BTN_MSG_EXIT_GAME   "Retour accueil"
#define HELP_MSG_EXIT_GAME  "Cliquer pour revenir au menu d'accueil"

#define BTN_MSG_INVENTORY   "Inventaire"
#define HELP_MSG_INVENTORY  "Cliquer pour afficher l'inventaire"

#define LABEL_WIDTH         500

/*!
 * \brief           Construct a new Level Selection:: Level Selection object
 * 
 * \param[in]       index: Index of the widget
 */
LevelSelection::LevelSelection(int index) : QWidget()
{
    int i;

    /* Set the widget number */
    LevelSelection::widgetIndex = index;

    /* Initialize elements of the level selection */
    LevelSelection::pScrollBar = new QScrollArea;
    LevelSelection::pScrollBar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    LevelSelection::pScrollBar->setWidgetResizable(true);
    
    LevelSelection::pFrameLevel = new QFrame;

    for (i = 0; i < NB_LEVELS; i++) {
        /* Initialize new button */
        LevelSelection::paButtonLevel[i] = new QPushButton("Niveau " + QString::number(i + 1));
        /* Set up new button */
        CMN_SetUpButton(LevelSelection::paButtonLevel[i], "Cliquer pour entre dans le niveau");
        /* Connect new button */
        QObject::connect(LevelSelection::paButtonLevel[i], SIGNAL(clicked()), this, SLOT(SlotSwitchWidget()));
    }

    /* Initialize elements of the navigation frame */
    LevelSelection::pFrameNavigation = new QFrame;

    LevelSelection::pButtonExit = new QPushButton(BTN_MSG_EXIT_GAME);
    CMN_SetUpButton(LevelSelection::pButtonExit, HELP_MSG_EXIT_GAME);
    QObject::connect(LevelSelection::pButtonExit, SIGNAL(clicked()),
                     this, SLOT(SlotSwitchWidget()));

    LevelSelection::pButtonInventory = new QPushButton(BTN_MSG_INVENTORY);
    CMN_SetUpButton(LevelSelection::pButtonInventory, HELP_MSG_INVENTORY);
    QObject::connect(LevelSelection::pButtonInventory, SIGNAL(clicked()),
                     this, SLOT(SlotSwitchWidget()));

    /* Initialize layouts */
    LevelSelection::pLayoutLevel = new QHBoxLayout;
    LevelSelection::pLayoutNavigation = new QHBoxLayout;
    LevelSelection::pLayoutMain = new QGridLayout;

    /* Set up level selection frame */
    for (i = 0; i < NB_LEVELS; i++) {
        LevelSelection::pLayoutLevel->addWidget(LevelSelection::paButtonLevel[i], 1, Qt::AlignCenter);
    }
    LevelSelection::pFrameLevel->setLayout(LevelSelection::pLayoutLevel);
    LevelSelection::pScrollBar->setWidget(LevelSelection::pFrameLevel);

    /* Set up navigation frame */
    LevelSelection::pLayoutNavigation->addWidget(LevelSelection::pButtonExit, 1, Qt::AlignLeft);
    LevelSelection::pLayoutNavigation->addWidget(LevelSelection::pButtonInventory, 1, Qt::AlignRight);
    LevelSelection::pFrameNavigation->setLayout(LevelSelection::pLayoutNavigation);

    /* Set up the whole */
    LevelSelection::pLayoutMain->addWidget(LevelSelection::pScrollBar, 0, 0, 14, 1);
    LevelSelection::pLayoutMain->addWidget(LevelSelection::pFrameNavigation, 15, 0, 1, 1);
    this->setLayout(LevelSelection::pLayoutMain);
}

/*!
 * \brief           Destroy the Level Selection:: Level Selection object
 */
LevelSelection::~LevelSelection()
{   
    int i;

    /* Delete elements of level selection frame */
    for (i = 0; i < NB_LEVELS; i++) {
        delete LevelSelection::paButtonLevel[i];
    }

    /* Delete elements of naviguation frame */
    delete LevelSelection::pButtonExit;
    delete LevelSelection::pButtonInventory;

    /* Delete layouts */
    delete LevelSelection::pLayoutLevel;
    delete LevelSelection::pLayoutNavigation;

    /* Delete frames */
    delete LevelSelection::pFrameLevel;
    delete LevelSelection::pFrameNavigation;

    delete LevelSelection::pScrollBar;
    delete LevelSelection::pLayoutMain;
}

/*!
 * \brief           Slot function which ask to switch the current widget to another one.
 *                  Connected with the signal 'SignalExitInterface'.
 */
void LevelSelection::SlotExitInterface(void)
{
    emit LevelSelection::SignalExitInterface(START_MENU);
}

/*!
 * \brief           Slot function which ask to switch the current widget to another one.
 *                  Connected with the signal 'SignalInventory'.
 */
void LevelSelection::SlotInventory(void)
{
    emit LevelSelection::SignalInventory(CHARAC_INTERFACE);
}

/*!
 * \brief           Slot function which ask to switch the current widget to another one.
 */
void LevelSelection::SlotSwitchWidget(void)
{
    int i;
    int index = 0;
    /* Get button signal sender */
    auto sender = this->sender();

    for (i = 0; i < NB_LEVELS; i++) {
        if (LevelSelection::pButtonExit == sender) {
            std::cout << "Go on 'Start Menu'" << std::endl;
            index = START_MENU;
        } else if (LevelSelection::pButtonInventory == sender) {
            std::cout << "Go on 'Interface'" << std::endl;
            index = CHARAC_INTERFACE;
        } else if (LevelSelection::paButtonLevel[i] == sender) {
            std::cout << "Go on 'Level " << i + 1 << "'" << std::endl;
            index = i + 2;
        }
    }

    emit LevelSelection::SignalSwitchWidget(index);
}
