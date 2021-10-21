# Installation of QT

sudo apt install qt5-default

# Build with QT

qmake -project

qmake -makefile

In the generated makefile add 
- *-lQt5Widgets* on the line with the keyword *LIBS*
- *-isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets* on the line with the keyword *INCPATH*

make
