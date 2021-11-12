#ifndef TRADESKILL_H
#define TRADESKILL_H

#include <iostream>
#include <QtWidgets>

class Tradeskill
{
public:
    /* Constructor */
    Tradeskill(QString name);

    /* Public function */
    void Print(void) const;

    QString name;

};

#endif /* TRADESKILL_H */