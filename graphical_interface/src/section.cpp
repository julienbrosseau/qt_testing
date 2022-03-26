#include "section.h"

#define BTN_MSG_EXIT_LEVEL   "Quitter le niveau"
#define HELP_MSG_EXIT_LEVEL  "Cliquer pour quitter le niveau"

#define NB_ENEMIES 2

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

    int width;
    int height;

    /* Get the size of the host desktop */
    std::tie(width, height) = CMN_GetSizeOfDesktop();

    Section::characPointX = ((width - WIDTH_DELTA) / 2) - (CHARAC_WIDTH / 2);
    Section::characPointY = height - HEIGHT_DELTA - CHARAC_HEIGHT - START_POINT_Y;;

    Section::characWidth = CHARAC_WIDTH;
    Section::characHeight = CHARAC_HEIGHT;
    Section::characPen = 1;

    /* Initialize elements of the interface frame */
    Section::pFrameLevel = new QFrame;
    Section::pShape = new MoveCharacter(this);

    /* Initialize elements of the navigation frame */
    Section::pFrameNavigation = new QFrame;
    Section::pButtonExit = new QPushButton(BTN_MSG_EXIT_LEVEL);
    CMN_SetUpButton(Section::pButtonExit, HELP_MSG_EXIT_LEVEL);
    QObject::connect(Section::pButtonExit, SIGNAL(clicked()),
                     this, SLOT(SlotExitLevel()));
    
    /* Initialize layouts */
    Section::pLayoutLevel = new QGridLayout;
    Section::pLayoutNavigation = new QHBoxLayout;
    Section::pLayoutMain = new QGridLayout;

    /* Set up level frame */
    Section::pLayoutLevel->addWidget(Section::pShape, 0, 0, 1, 1);
    Section::pFrameLevel->setLayout(Section::pLayoutLevel);

    /* Set up navigation frame */
    Section::pLayoutNavigation->addWidget(Section::pButtonExit, 1, Qt::AlignCenter);
    Section::pFrameNavigation->setLayout(Section::pLayoutNavigation);

    /* Set up the whole */
    Section::pLayoutMain->addWidget(Section::pFrameLevel, 0, 0, 14, 1);
    Section::pLayoutMain->addWidget(Section::pFrameNavigation, 15, 0, 1, 1);
    this->setLayout(Section::pLayoutMain);

}

/*!
 * \brief           Destructor of the class "Section"
 */
Section::~Section(void)
{
    delete Section::pExitButton;
    delete Section::pShape;

    /* Delete elements of navigation frame */
    delete Section::pButtonExit;

    /* Delete layouts */
    delete Section::pLayoutNavigation;
    delete Section::pLayoutLevel;

    /* Delete frames */
    delete Section::pFrameNavigation;
    delete Section::pFrameLevel;

    delete Section::pLayoutMain;
}

/*!
 * \brief           Painting the character to the focused window
 * 
 * \param[in]       event:
 */
void Section::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    /* Initialize and define the size of the ellipse */
    QRectF characRect(Section::characPointX, Section::characPointY, 
                      Section::characWidth, Section::characHeight);
    
    /* Initialize and define the size of the ellipse */
    QRectF aEnemiesRect[NB_ENEMIES];

    for (int i = 0; i < NB_ENEMIES; i++) {
        QRectF enemyRect(Section::pShape->pointX + (i * 50), Section::pShape->pointY, 
                         Section::characWidth, Section::characHeight);
        aEnemiesRect[i] = enemyRect;
    }

    /* Initialize and define the border the ellipse */
    QPen penEllipse(Qt::black);
    penEllipse.setWidth(Section::characPen);

    /* Initilize the drawing session */
    QPainter painter;
    painter.begin(this);
    painter.setPen(penEllipse);
    /* Daw the character */
    painter.setBrush(Qt::blue);
    painter.drawEllipse(characRect);
    /* Draw enemies */
    painter.setBrush(Qt::red);
    for (int i = 0; i < NB_ENEMIES; i++) {
        painter.drawEllipse(aEnemiesRect[i]);
    }
    /* Ending the drawing session */
    painter.end();
}

/*!
 * \brief           Slot function which ask to switch the current section with the next one.
 *                  Connected with the signal 'askToDisplaySection'.
 */
void Section::SlotExitLevel(void)
{   
    emit Section::SignalExitLevel(LEVEL_SELEC);
}