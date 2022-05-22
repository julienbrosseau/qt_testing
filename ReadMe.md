# Investigate & Test possibilities of the integration of QT library

Version: v1.0

## Abstract

The goal of this project is to investigate and test possibilites of the integration of QT in a project.

I have never used it before and I will try to make something with it.

## Requirements

- CMake (version used for this project - 3.10.2)
- QT (version used for this project - 5.9.5)

### Installation of QT

```bash
$ sudo apt install qt5-default
```

### Build with QT

```bash
$ qmake -project
$ qmake -makefile
```

In the generated makefile add 
- *-lQt5Widgets* on the line with the keyword *LIBS*
- *-isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets* on the line with the keyword *INCPATH*

```bash
$ make
```

### Installation of CMake

```bash
$ sudo apt install cmake
```

### Build with CMake

```bash
$ mkdir local-build
$ cd local-build
$ cmake ..
$ make
```
