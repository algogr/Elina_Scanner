TEMPLATE = app
TARGET = Elina_Scanner
QT += core \
    gui \
    sql \
    network
HEADERS += fortosi_progress_1_2.h \
    fortosi_progress_1_1.h \
    fortosi_progress_1.h \
    fortosi_new_1_1.h \
    fortosi_new_1_b.h \
    constants.h \
    fortosi_new_1.h \
    fortosi_sel.h \
    elina_scanner.h
SOURCES += fortosi_progress_1_2.cpp \
    fortosi_progress_1_1.cpp \
    fortosi_progress_1.cpp \
    fortosi_new_1_1.cpp \
    fortosi_new_1_b.cpp \
    fortosi_new_1.cpp \
    fortosi_sel.cpp \
    main.cpp \
    elina_scanner.cpp
FORMS += fortosi_progress_1_2.ui \
    fortosi_progress_1_1.ui \
    fortosi_progress_1.ui \
    fortosi_new_1_1.ui \
    fortosi_new_1_b.ui \
    fortosi_new_1.ui \
    fortosi_sel.ui \
    elina_scanner.ui
RESOURCES += 
