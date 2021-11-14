#include "character_interface.h"

/*!
 * \brief           Construct a new Character Interface:: Character Interface object
 * 
 * \param[in]       index: Index of the widget
 */
CharacterInterface::CharacterInterface(int index) : QWidget()
{
    /* Set the widget number */
    CharacterInterface::widgetIndex = index;
    
    /* Initialize elements of the navigation frame */
    CharacterInterface::pFrameNavigation = new QFrame;
    CharacterInterface::pButtonExit = new QPushButton("Exit", this);
    CMN_SetUpButton(CharacterInterface::pButtonExit, "Exit frame");
    QObject::connect(CharacterInterface::pButtonExit, SIGNAL(clicked()),
                     this, SLOT(SlotExitInterface()));

    /* Initialize elements of the character frame */
    CharacterInterface::pFrameCharacter = new QFrame;
    CharacterInterface::pLabelHead = new QLabel("Head slot");
    CharacterInterface::pLabelChest = new QLabel("Chest slot");
    CharacterInterface::pLabelLegs = new QLabel("Legs slot");
    CharacterInterface::pLabelWeapon = new QLabel("Weapon slot");
    CharacterInterface::pLabelDisplay = new QLabel("Display character");
    CharacterInterface::pLabelCarac = new QLabel("Caracteristics");

    /* Initialize elements of the inventory frame */
    CharacterInterface::pFrameInventory = new QFrame;
    CharacterInterface::pLabelInventory = new QLabel("Inventory");

    /* Initialize layouts */
    CharacterInterface::pLayoutNavigation = new QHBoxLayout;
    CharacterInterface::pLayoutCharacter = new QGridLayout;
    CharacterInterface::pLayoutInventory = new QHBoxLayout;
    CharacterInterface::pLayoutMain = new QGridLayout;

    /* Set up navigation frame */
    CharacterInterface::pLayoutNavigation->addWidget(CharacterInterface::pButtonExit, 1,
                                                     Qt::AlignLeft);
    CharacterInterface::pFrameNavigation->setLayout(CharacterInterface::pLayoutNavigation);

    /* Set up character frame */
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelHead, 0, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelChest, 1, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelLegs, 2, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelWeapon, 3, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelDisplay, 0, 1, 4, 4);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelCarac, 0, 5, 4, 2);
    CharacterInterface::pFrameCharacter->setLayout(CharacterInterface::pLayoutCharacter);

    /* Set up inventory frame */
    CharacterInterface::pLayoutInventory->addWidget(CharacterInterface::pLabelInventory);
    CharacterInterface::pFrameInventory->setLayout(CharacterInterface::pLayoutInventory);

    /* Set up the whole */
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameNavigation, 0, 0, 1, 3);
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameCharacter, 1, 0, 14, 2);
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameInventory, 1, 2, 14, 1);
    this->setLayout(CharacterInterface::pLayoutMain);
}

/*!
 * \brief           Destroy the Character Interface:: Character Interface object
 */
CharacterInterface::~CharacterInterface()
{
    /* Delete elements of navigation frame */
    delete CharacterInterface::pButtonExit;

    /* Delete elements of character frame */
    delete CharacterInterface::pLabelHead;
    delete CharacterInterface::pLabelChest;
    delete CharacterInterface::pLabelLegs;
    delete CharacterInterface::pLabelWeapon;
    delete CharacterInterface::pLabelDisplay;
    delete CharacterInterface::pLabelCarac;

    /* Delete elements of inventory frame */
    delete CharacterInterface::pLabelInventory;

    /* Delete layouts */
    delete CharacterInterface::pLayoutNavigation;
    delete CharacterInterface::pLayoutCharacter;
    delete CharacterInterface::pLayoutInventory;

    /* Delete frames */
    delete CharacterInterface::pFrameNavigation;
    delete CharacterInterface::pFrameCharacter;
    delete CharacterInterface::pFrameInventory;

    delete CharacterInterface::pLayoutMain;
}

/*!
 * \brief           Display the character passed in parameter in the interface
 * 
 * \param[in]       pCharacter: Pointer to the character to display
 */
void CharacterInterface::DisplayCharacterInterface(Character *pCharacter)
{
    CharacterInterface::pLabelHead->setText(QString::fromStdString(pCharacter->pArmorHead->name));
    CharacterInterface::pLabelChest->setText(QString::fromStdString(pCharacter->pArmorChest->name));
    CharacterInterface::pLabelLegs->setText(QString::fromStdString(pCharacter->pArmorLegs->name));
    CharacterInterface::pLabelWeapon->setText(QString::fromStdString(pCharacter->pWeapon->name));
}

/*!
 * \brief           Slot function which ask to switch the current widget to another one.
 *                  Connected with the signal 'SignalExitInterface'.
 */
void CharacterInterface::SlotExitInterface(void)
{   
    int nextIndex = 0; //CharacterInterface::widgetIndex + 1;
    
    emit CharacterInterface::SignalExitInterface(nextIndex);
}
