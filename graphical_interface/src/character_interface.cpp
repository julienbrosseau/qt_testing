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

    /* Initialize elements of the character frame */
    CharacterInterface::pFrameCharacter = new QFrame;
    CharacterInterface::pLabelHead = new QLabel("Head slot");
    CharacterInterface::pLabelChest = new QLabel("Chest slot");
    CharacterInterface::pLabelLegs = new QLabel("Legs slot");
    CharacterInterface::pLabelWeapon = new QLabel("Weapon slot");
    CharacterInterface::pLabelDisplay = new QLabel("Display character");

    /* Initialize elements of the character caracteristics */
    CharacterInterface::pFrameCarac = new QFrame;
    CharacterInterface::pLabelGeneral = new QLabel("Général");
    CharacterInterface::pLabelHealth = new QLabel("Health: N/A");
    CharacterInterface::pLabelMana = new QLabel("Mana: N/A");
    CharacterInterface::pLabelDamage = new QLabel("Damage: N/A");
    CharacterInterface::pLabelDefense = new QLabel("Defense: N/A");
    CharacterInterface::pLabelAttributes = new QLabel("Attribut");
    CharacterInterface::pLabelStrength = new QLabel("Strength: N/A");
    CharacterInterface::pLabelIntellect = new QLabel("Intellect: N/A");
    CharacterInterface::pLabelAgility = new QLabel("Agility: N/A");
    CharacterInterface::pLabelCritic = new QLabel("Critical Strike: N/A");
    CharacterInterface::pLabelHaste = new QLabel("Haste: N/A");

    /* Initialize elements of the inventory frame */
    CharacterInterface::pFrameInventory = new QFrame;
    CharacterInterface::pLabelInventory = new QLabel("Inventory");

    /* Initialize elements of the navigation frame */
    CharacterInterface::pFrameNavigation = new QFrame;
    CharacterInterface::pButtonExit = new QPushButton("Retour", this);
    CMN_SetUpButton(CharacterInterface::pButtonExit, "Cliquer pour retourner au choix des niveaux");
    QObject::connect(CharacterInterface::pButtonExit, SIGNAL(clicked()),
                     this, SLOT(SlotExitInterface()));

    /* Initialize layouts */
    CharacterInterface::pLayoutCharacter = new QGridLayout;
    CharacterInterface::pLayoutCarac = new QVBoxLayout;
    CharacterInterface::pLayoutInventory = new QHBoxLayout;
    CharacterInterface::pLayoutNavigation = new QHBoxLayout;
    CharacterInterface::pLayoutMain = new QGridLayout;

    /* Set up character frame */
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelHead, 0, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelChest, 1, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelLegs, 2, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelWeapon, 3, 0, 1, 1);
    CharacterInterface::pLayoutCharacter->addWidget(CharacterInterface::pLabelDisplay, 0, 1, 4, 4);
    CharacterInterface::pFrameCharacter->setLayout(CharacterInterface::pLayoutCharacter);

    /* Set up caracteristics frame */
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelGeneral, 1, Qt::AlignCenter);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelHealth, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelMana, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelDamage, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelDefense, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelAttributes, 1, Qt::AlignCenter);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelStrength, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelIntellect, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelAgility, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelCritic, 1, Qt::AlignLeft);
    CharacterInterface::pLayoutCarac->addWidget(CharacterInterface::pLabelHaste, 1, Qt::AlignLeft);
    CharacterInterface::pFrameCarac->setLayout(CharacterInterface::pLayoutCarac);

    /* Set up inventory frame */
    CharacterInterface::pLayoutInventory->addWidget(CharacterInterface::pLabelInventory);
    CharacterInterface::pFrameInventory->setLayout(CharacterInterface::pLayoutInventory);

    /* Set up navigation frame */
    CharacterInterface::pLayoutNavigation->addWidget(CharacterInterface::pButtonExit, 1, Qt::AlignLeft);
    CharacterInterface::pFrameNavigation->setLayout(CharacterInterface::pLayoutNavigation);

    /* Set up the whole */
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameCharacter, 0, 0, 14, 3);
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameCarac, 0, 3, 14, 1);
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameInventory, 0, 4, 14, 4);
    CharacterInterface::pLayoutMain->addWidget(CharacterInterface::pFrameNavigation, 15, 0, 1, 8);
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

    /* Delete elements of caracteristic frame */
    delete CharacterInterface::pLabelGeneral;


    /* Delete elements of inventory frame */
    delete CharacterInterface::pLabelInventory;
    delete CharacterInterface::pLabelHealth;
    delete CharacterInterface::pLabelMana;
    delete CharacterInterface::pLabelDamage;
    delete CharacterInterface::pLabelDefense;
    delete CharacterInterface::pLabelAttributes;
    delete CharacterInterface::pLabelStrength;
    delete CharacterInterface::pLabelIntellect;
    delete CharacterInterface::pLabelAgility;
    delete CharacterInterface::pLabelCritic;
    delete CharacterInterface::pLabelHaste;

    /* Delete layouts */
    delete CharacterInterface::pLayoutNavigation;
    delete CharacterInterface::pLayoutCharacter;
    delete CharacterInterface::pLayoutCarac;
    delete CharacterInterface::pLayoutInventory;

    /* Delete frames */
    delete CharacterInterface::pFrameNavigation;
    delete CharacterInterface::pFrameCharacter;
    delete CharacterInterface::pFrameCarac;
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
 * \brief           Display caracteristics of the character passed in parameter in the interface 
 * 
 * \param[in]       pCharacter: Pointer to the character to display (for its caracteristics)
 */
void CharacterInterface::DisplayCharacterCaracteristic(Character *pCharacter)
{
    /* General */
    CharacterInterface::pLabelHealth->setText("Vie: " + QString::number(pCharacter->nbHeart));
    CharacterInterface::pLabelMana->setText("Mana: " + QString::number(pCharacter->nbMana));
    CharacterInterface::pLabelDamage->setText("Dégât: " + QString::number(pCharacter->damage));
    CharacterInterface::pLabelDefense->setText("Défense: " + QString::number(pCharacter->defense));
    
    /* Attributes */
    CharacterInterface::pLabelStrength->setText("Force: " + QString::number(pCharacter->strength));
    CharacterInterface::pLabelIntellect->setText("Intelligence: " + QString::number(pCharacter->intellect));
    CharacterInterface::pLabelAgility->setText("Agilité: " + QString::number(pCharacter->agility));
    CharacterInterface::pLabelCritic->setText("Score Critique: " + QString::number(pCharacter->critic));
    CharacterInterface::pLabelHaste->setText("Hâte: " + QString::number(pCharacter->haste));
}

/*!
 * \brief           Slot function which ask to switch the current widget to another one.
 *                  Connected with the signal 'SignalExitInterface'.
 */
void CharacterInterface::SlotExitInterface(void)
{
    emit CharacterInterface::SignalExitInterface(LEVEL_SELEC);
}
