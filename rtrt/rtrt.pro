
QMAKE_CXXFLAGS += -sse -sse2 -fopenmp

LIBS += -lpthread -lgflags -lglog -framework Cocoa -framework AGL -framework OpenGL -lglfw -lgomp

QT -= core gui

SOURCES += \
    rtrt.cpp \
    modules/cmdflags.cpp \
    modules/window.cpp \
    modules/image.cpp \
    modules/vec_func.cpp

HEADERS += \
    cmdflags.h \
    modules/window.h \
    modules/image.h \
    modules/vec4.h \
    modules/vec_func.h










