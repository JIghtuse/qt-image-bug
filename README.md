# QT image fading bug
Trying to determine if this is a bug or not.

Building:

    qmake
    make

Usage: put png image with alpha channel in /tmp/logo0.png

    ./untitled1
    compare /tmp/logo0.png /tmp/logo1000.png -compose src logo_diff.png

See result logo\_diff.png file.