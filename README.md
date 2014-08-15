# QT image fading bug

[Bugreport](https://bugreports.qt-project.org/browse/QTBUG-38764) - resolved and
closed.

Building:

    qmake
    make

Usage: put png image with alpha channel in /tmp/logo0.png

    ./untitled1
    compare /tmp/logo0.png /tmp/logo1000.png -compose src logo_diff.png

See result logo\_diff.png file.

For example, this diff taken from Trolltech logo:
![logo](https://github.com/JIghtuse/qt-image-bug/raw/master/logo_diff.png)
