TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    util/matrix.cpp \
    shader/shaderprogram.cpp \
    models/mesh.cpp \
    models/objmodelloader.cpp \
    models/loader.cpp \
    entity/entity.cpp \
    renderer/entityrenderer.cpp \
    shader/staticshader.cpp \
    entity/camera.cpp \
    util/string_util.cpp \
    models/model.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lglfw
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lglfw
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lglfw

INCLUDEPATH += $$PWD/../../../../usr/include/GLFW
DEPENDPATH += $$PWD/../../../../usr/include/GLFW

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../lib/release/ -lGL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../lib/debug/ -lGL
else:unix: LIBS += -L$$PWD/../../../../lib/ -lGL


unix|win32: LIBS += -lGLEW

unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/ -lsoil2

INCLUDEPATH += $$PWD/SOIL2
DEPENDPATH += $$PWD/SOIL2

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/libsoil2.a

HEADERS += \
    util/matrix.h \
    shader/shaderprogram.h \
    models/mesh.h \
    models/objmodelloader.h \
    models/loader.h \
    entity/entity.h \
    renderer/entityrenderer.h \
    shader/staticshader.h \
    entity/camera.h \
    util/coloro.h \
    util/string_util.h \
    models/model.h


DISTFILES += \
    shader/simple.vsh \
    shader/simple.frag


