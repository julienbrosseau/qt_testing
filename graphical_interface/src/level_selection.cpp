#include "level_selection.h"

#define BTN_MSG_EXIT_GAME   "Retour accueil"
#define HELP_MSG_EXIT_GAME  "Cliquer pour revenir au menu d'accueil"
#define INDEX_EXIT_GAME     0

#define BTN_MSG_INVENTORY   "Inventaire"
#define HELP_MSG_INVENTORY  "Cliquer pour afficher l'inventaire"
#define INDEX_INVENTORY     6

LevelSelection::LevelSelection(int index) : QWidget()
{
    /* Set the widget number */
    LevelSelection::widgetIndex = index;

    /* Initialize elements of the level selection */
    LevelSelection::pFrameLevelSelection = new QFrame;
    LevelSelection::pLabelLevel1 = new QLabel("Level 1");

    /* Initialize elements of the navigation frame */
    LevelSelection::pFrameNavigation = new QFrame;
    LevelSelection::pButtonExit = new QPushButton(BTN_MSG_EXIT_GAME);
    CMN_SetUpButton(LevelSelection::pButtonExit, HELP_MSG_EXIT_GAME);
    QObject::connect(LevelSelection::pButtonExit, SIGNAL(clicked()),
                     this, SLOT(SlotExitInterface()));
    LevelSelection::pButtonInventory = new QPushButton(BTN_MSG_INVENTORY);
    CMN_SetUpButton(LevelSelection::pButtonInventory, HELP_MSG_INVENTORY);
    QObject::connect(LevelSelection::pButtonInventory, SIGNAL(clicked()),
                     this, SLOT(SlotInventory()));

    /* Initialize layouts */
    LevelSelection::pLayoutLevelSelection = new QHBoxLayout;
    LevelSelection::pLayoutNavigation = new QHBoxLayout;
    LevelSelection::pLayoutMain = new QGridLayout;

    /* Set up level selection frame */
    LevelSelection::pLayoutLevelSelection->addWidget(LevelSelection::pLabelLevel1, 1, Qt::AlignCenter);
    LevelSelection::pFrameLevelSelection->setLayout(LevelSelection::pLayoutLevelSelection);

    /* Set up navigation frame */
    LevelSelection::pLayoutNavigation->addWidget(LevelSelection::pButtonExit, 1, Qt::AlignLeft);
    LevelSelection::pLayoutNavigation->addWidget(LevelSelection::pButtonInventory, 1, Qt::AlignRight);
    LevelSelection::pFrameNavigation->setLayout(LevelSelection::pLayoutNavigation);

    /* Set up the whole */
    LevelSelection::pLayoutMain->addWidget(LevelSelection::pFrameLevelSelection, 0, 0, 14, 1);
    LevelSelection::pLayoutMain->addWidget(LevelSelection::pFrameNavigation, 15, 0, 1, 1);
    this->setLayout(LevelSelection::pLayoutMain);
}

LevelSelection::~LevelSelection()
{   
    /* Delete elements of level selection frame */
    delete LevelSelection::pLabelLevel1;

    /* Delete elements of naviguation frame */
    delete LevelSelection::pButtonExit;
    delete LevelSelection::pButtonInventory;

    /* Delete frames */
    delete LevelSelection::pFrameLevelSelection;
    delete LevelSelection::pFrameNavigation;

    delete LevelSelection::pLayoutMain;
}

void LevelSelection::SlotExitInterface(void)
{
    emit LevelSelection::SignalExitInterface(START_MENU);
}

void LevelSelection::SlotInventory(void)
{
    emit LevelSelection::SignalInventory(CHARAC_INTERFACE);
}
