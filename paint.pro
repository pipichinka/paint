QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    geometry.cpp \
    help_window.cpp \
    line_option_dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    model_t.cpp \
    paint_action_fill_t.cpp \
    paint_action_line_t.cpp \
    paint_action_polygon_t.cpp \
    paint_action_star_t.cpp \
    paint_field_t.cpp \
    param_dialog.cpp

HEADERS += \
    geometry.hpp \
    help_window.hpp \
    line_option_dialog.hpp \
    mainwindow.hpp \
    model_t.hpp \
    paint_action_fill_t.hpp \
    paint_action_interface.hpp \
    paint_action_line_t.hpp \
    paint_action_polygon_t.hpp \
    paint_action_star_t.hpp \
    paint_field_t.hpp \
    param_dialog.hpp \
    view_interface_t.hpp

FORMS += \
    geometry.ui \
    help_window.ui \
    line_option_dialog.ui \
    mainwindow.ui \
    param_dialog.ui

RESOURCES = \
    paint.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
