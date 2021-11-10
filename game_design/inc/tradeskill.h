#ifndef TRADESKILL_H
#define TRADESKILL_H

#include <iostream>
#include <string>

class Tradeskill
{
public:
    /* Constructor */
    Tradeskill(std::string name);

    /* Public function */
    void Print(void) const;

    std::string name;

};

#endif /* TRADESKILL_H */