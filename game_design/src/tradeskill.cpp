#include "tradeskill.h"

/*!
 * \brief           Construct a new Tradeskill:: Tradeskill object
 * 
 * \param[in]       name: Name of the tradeskill item
 */
Tradeskill::Tradeskill(std::string name)
{
    Tradeskill::name = name;
}

/*!
 * \brief           Show details of the tradeskill item
 */
void Tradeskill::Print(void) const
{
    std::cout << "Objet d'artisanat : " << Tradeskill::name << std::endl;
}
