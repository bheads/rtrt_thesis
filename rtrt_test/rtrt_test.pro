QT -= core gui

QMAKE_CXXFLAGS += -sse -sse2 -fopenmp

INCLUDEPATH += ../rtrt

LIBS += -lunittest++

SOURCES += \
    test_math_vec4.cpp \
    test_math_vec_func.cpp \
    main.cpp \
    ../rtrt/modules/vec_func.cpp

HEADERS += \
    ../rtrt/modules/vec4.h \
    ../rtrt/modules/vec_func.h



