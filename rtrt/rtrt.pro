
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
    modules/ray.cpp \
    raytracer.cpp \
    modules/world.cpp \
    modules/objects/object.cpp \
    modules/objects/sphere.cpp \
    modules/random.cpp \
    modules/objects/light.cpp

HEADERS += \
    cmdflags.h \
    modules/window.h \
    modules/image.h \
    modules/color.h \
    modules/basiccamera.h \
    modules/ray.h \
    raytracer.h \
    modules/world.h \
    modules/objects/object.h \
    modules/objects/sphere.h \
    modules/random.h \
    modules/objects/light.h


















































