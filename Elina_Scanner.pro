TEMPLATE = app
TARGET = Elina_Scanner
QT += core \
    gui \
    sql \
    network
HEADERS += read_label.h \
    change_label.h \
    network_test.h \
    apografi.h \
    fortosi_new_1a.h \
    fortosi_progress_1_2.h \
    fortosi_progress_1_1.h \
    fortosi_progress_1.h \
    fortosi_new_1_1.h \
    fortosi_new_1_b.h \
    constants.h \
    fortosi_new_1.h \
    fortosi_sel.h \
    elina_scanner.h \
    rewrap_sc.h \
    return_roll.h \
    apografi_comment.h \
    fortosi_sel_1.h
SOURCES += read_label.cpp \
    change_label.cpp \
    network_test.cpp \
    apografi.cpp \
    fortosi_new_1a.cpp \
    fortosi_progress_1_2.cpp \
    fortosi_progress_1_1.cpp \
    fortosi_progress_1.cpp \
    fortosi_new_1_1.cpp \
    fortosi_new_1_b.cpp \
    fortosi_new_1.cpp \
    fortosi_sel.cpp \
    main.cpp \
    elina_scanner.cpp \
    rewrap_sc.cpp \
    return_roll.cpp \
    apografi_comment.cpp \
    fortosi_sel_1.cpp
FORMS += read_label.ui \
    change_label.ui \
    apografi.ui \
    fortosi_new_1a.ui \
    fortosi_progress_1_2.ui \
    fortosi_progress_1_1.ui \
    fortosi_progress_1.ui \
    fortosi_new_1_1.ui \
    fortosi_new_1_b.ui \
    fortosi_new_1.ui \
    fortosi_sel.ui \
    elina_scanner.ui \
    rewrap_sc.ui \
    return_roll.ui \
    apografi_comment.ui \
    fortosi_sel_1.ui
RESOURCES +=

DISTFILES +=
