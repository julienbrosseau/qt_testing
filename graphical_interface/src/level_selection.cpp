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
    
    LevelSelection::pFrameLevelSelection = new QFrame;

    LevelSelection::pTestButton = new QPushButton("Niveau " + QString::number(0));

    CMN_SetUpButton(LevelSelection::pTestButton, "Cliquer pour entrer dans le niveau");

    QObject::connect(LevelSelection::pTestButton, SIGNAL(clicked()),
                     this, SLOT(SlotSwitchWidget()));

    // for (i = 0; i < NB_LEVELS; i++) {
    //     LevelSelection::paLevelSelection[i]->pButton = new QPushButton("Niveau " + QString::number(i));
    //     LevelSelection::paLevelSelection[i]->indexSwitchedWidget = i;
    //     // LevelSelection::paLevelSelection[i]->SlotLevelSelectionFxn = &SlotLevelSelection;


    //     CMN_SetUpButton(LevelSelection::paLevelSelection[i]->pButton, "Cliquer pour entrer dans le niveau");
    //     LevelSelection::paLevelSelection[i]->pButton->setFixedWidth(LABEL_WIDTH);
        
    //     QObject::connect(LevelSelection::paLevelSelection[i]->pButton, SIGNAL(clicked()),
    //                      this, SLOT(SlotLevelSelection()));
    // }

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
    LevelSelection::pLayoutLevelSelection = new QHBoxLayout;
    LevelSelection::pLayoutNavigation = new QHBoxLayout;
    LevelSelection::pLayoutMain = new QGridLayout;

    /* Set up level selection frame */
    // for (i = 0; i < NB_LEVELS; i++) {
    //     LevelSelection::pLayoutLevelSelection->addWidget(
    //         LevelSelection::paLevelSelection[i]->pButton, 1, Qt::AlignCenter);
    // }
    LevelSelection::pLayoutLevelSelection->addWidget(LevelSelection::pTestButton, 1, Qt::AlignCenter);
    LevelSelection::pFrameLevelSelection->setLayout(LevelSelection::pLayoutLevelSelection);
    LevelSelection::pScrollBar->setWidget(LevelSelection::pFrameLevelSelection);

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
    // int i;

    /* Delete elements of level selection frame */
    // for (i = 0; i < NB_LEVELS; i++) {
    //     delete LevelSelection::paLevelSelection[i];
    // }
    delete LevelSelection::pTestButton;

    /* Delete elements of naviguation frame */
    delete LevelSelection::pButtonExit;
    delete LevelSelection::pButtonInventory;

    /* Delete layouts */
    delete LevelSelection::pLayoutLevelSelection;
    delete LevelSelection::pLayoutNavigation;

    /* Delete frames */
    delete LevelSelection::pFrameLevelSelection;
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
    int index = 0;
    auto sender = this->sender();

    if (LevelSelection::pButtonExit == sender) {
        std::cout << "Go on 'Start Menu'" << std::endl;
        index = START_MENU;
    } else if (LevelSelection::pButtonInventory == sender) {
        std::cout << "Go on 'Interface'" << std::endl;
        index = CHARAC_INTERFACE;
    } else if (LevelSelection::pTestButton == sender) {
        std::cout << "Go on 'Test'" << std::endl;
        index = 2;
    } else {
        std::cout << "Error, no matching button" << std::endl;
    }

    emit LevelSelection::SignalSwitchWidget(index);
}
