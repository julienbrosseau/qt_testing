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

    Section::ellipseWidth = 100;
    Section::ellipseHeight = 100;
    Section::ellipsePen = 1;

    /* Initialize the button */
    Section::pExitButton = new QPushButton(name, this);
    
    /* Set up the button */
    Section::pExitButton->setToolTip("Switch section");
    Section::pExitButton->setFont(QFont("Courier", 12));
    Section::pExitButton->setCursor(Qt::PointingHandCursor);
    Section::pExitButton->move(60,50); /* TODO: Replace magic numbers */

    QObject::connect(Section::pExitButton, SIGNAL(clicked()),
                     this, SLOT(SlotSwitchSection()));

    Section::pShape = new MoveCharacter(this);

}

/*!
 * \brief           Destructor of the class "Section"
 */
Section::~Section(void)
{
    delete Section::pExitButton;
    delete Section::pShape;
}

/*!
 * \brief           Painting the character to the focused window
 * 
 * \param[in]       event:
 */
void Section::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    /* Initialize and define the size of the ellipse */
    QRectF rectangle(Section::pShape->pointX, Section::pShape->pointY, 
                     Section::pShape->ellipseWidth, Section::pShape->ellipseHeight);

    /* Initialize and define the border the ellipse */
    QPen penEllipse(Qt::black);
    penEllipse.setWidth(Section::pShape->ellipsePen);

    /* Initilize and draw the ellipse */
    QPainter painter;
    painter.begin(this);
    painter.setPen(penEllipse);
    painter.setBrush(Qt::cyan);
    painter.drawEllipse(rectangle);
    painter.end();
}

/*!
 * \brief           Slot function which ask to switch the current section with the next one.
 *                  Connected with the signal 'askToDisplaySection'.
 */
void Section::SlotSwitchSection(void)
{   
    int nextIndex = (Section::indexSection + 1) % 8; /* TODO: Replace magic numbers */

    emit Section::SignalSwitchSection(nextIndex);
}