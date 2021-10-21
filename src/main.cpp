#include <iostream>

// int main(void)
// {
//     std::cout << "Hello World !" << std::endl;
// }

#include <QApplication>

#include "window.h"
 
int main(int argc, char *argv[])
{   
    /* Generate the application */
    QApplication app(argc, argv);

    Window window;
    
    window.show();
 
    return app.exec();
}