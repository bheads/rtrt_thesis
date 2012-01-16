
 CONFIG -= app_bundle

QMAKE_CXXFLAGS += -sse -sse2 -fopenmp

LIBS += -lpthread -lgflags -lglog -framework Cocoa -framework AGL -framework OpenGL -lglfw -lgomp

QT -= core gui

SOURCES += \
    rtrt.cpp \
    modules/cmdflags.cpp \
    modules/window.cpp \
    modules/image.cpp \
    modules/basiccamera.cpp \
    raytracer.cpp \
    modules/world.cpp \
    modules/objects/object.cpp \
    modules/objects/sphere.cpp \
    modules/random.cpp \
    modules/objects/light.cpp \
    modules/vec_func.cpp \
    modules/performancecounter.cpp \
    modules/performancemonitor.cpp \
    modules/inputhandler.cpp \
    modules/input.cpp \
    modules/objects/triangle.cpp

HEADERS += \
    cmdflags.h \
    modules/window.h \
    modules/image.h \
    modules/basiccamera.h \
    raytracer.h \
    modules/world.h \
    modules/objects/object.h \
    modules/objects/sphere.h \
    modules/random.h \
    modules/objects/light.h \
    modules/vec4.h \
    modules/vec_func.h \
    modules/performancecounter.h \
    modules/performancemonitor.h \
    modules/inputhandler.h \
    modules/input.h \
    modules/objects/triangle.h

































































