#include "section.h"

/*!
 * \brief           Constructor of the class "Section"
 *
 * \param[in]       index: Index of the section
 * \param[in]       name: Name of the section
 */
Section::Section(int index, QString name) : QWidget()
{
    /* Set the number of the section */
    Section::indexSection = index;

    /* Initialize the button */
    Section::pExitButton = new QPushButton(name, this);
    
    /* Set up the button */
    Section::pExitButton->setToolTip("Switch section");
    Section::pExitButton->setFont(QFont("Courier", 12));
    Section::pExitButton->setCursor(Qt::PointingHandCursor);
    Section::pExitButton->move(60,50); /* TODO: Replace magic numbers */

    QObject::connect(Section::pExitButton, SIGNAL(clicked()),
                     this, SLOT(SlotSwitchSection()));
}

/*!
 * \brief           Destructor of the class "Section"
 */
Section::~Section(void)
{
    delete Section::pExitButton;
}

/*!
 * \brief           Slot function which ask to switch the current section with the next one.
 *                  Connected with the signal 'askToDisplaySection'.
 */
void Section::SlotSwitchSection(void)
{   
    int nextIndex = (Section::indexSection + 1) % 6; /* TODO: Replace magic numbers */

    emit Section::SignalSwitchSection(nextIndex);
}