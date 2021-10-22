#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <QtWidgets>

class Section : public QWidget
{
Q_OBJECT

public:
    /* Constructors */
    Section(int index, QString name);
    ~Section();

public slots:
    void SlotSwitchSection(void);

signals:
    void SignalSwitchSection(int index);

private:
    /* Private variables */
    QPushButton *button;
    int indexSection;
};

#endif /* SECTION_H */
