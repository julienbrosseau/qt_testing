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
    for (i = 0; i < NB_LEVELS; i++) {
        LevelSelection::aLevelSelection[i].pButton = new QPushButton("Niveau " + QString::number(i));
        LevelSelection::aLevelSelection[i].indexSwitchedWidget = i;
        LevelSelection::aLevelSelection[i].SlotSwitchWidgetFxn = &LevelSelection::SlotSwitchWidget;


        CMN_SetUpButton(LevelSelection::aLevelSelection[i].pButton, "Cliquer pour entrer dans le niveau");
        LevelSelection::aLevelSelection[i].pButton->setFixedWidth(LABEL_WIDTH);
        QObject::connect(LevelSelection::aLevelSelection[i].pButton, SIGNAL(clicked()),
                         this, SLOT(SlotLevelSelection(int)));
    }

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
    for (i = 0; i < NB_LEVELS; i++) {
        LevelSelection::pLayoutLevelSelection->addWidget(
            LevelSelection::paLevelSelection[i], 1, Qt::AlignCenter);
    }
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
    int i;

    /* Delete elements of level selection frame */
    for (i = 0; i < NB_LEVELS; i++) {
        delete LevelSelection::paLevelSelection[i];
    }

    /* Delete elements of naviguation frame */
    delete LevelSelection::pButtonExit;
    delete LevelSelection::pButtonInventory;

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

void LevelSelection::SlotLevelSelection(int index)
{
    emit LevelSelection::SignalLevelSelection(index);
}
