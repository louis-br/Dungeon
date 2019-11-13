TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

DISTFILES += \
    Recursos/Fontes/vinque.ttf

HEADERS += \
    Entidades/Entidade.h \
    Entidades/EntidadeFisica.h \
    Entidades/Fase.h \
    Fases/Fase.h \
    Gerenciadores/GerenciadorEntrada.h \
    Gerenciadores/GerenciadorFisico.h \
    Gerenciadores/GerenciadorGrafico.h \
    Listas/Lista.h \
    Listas/ListaEntidade.h \
    Principal/Menus/Menu.h \
    Principal/Jogo.h

SOURCES += \
    Entidades/Entidade.cpp \
    Entidades/EntidadeFisica.cpp \
    Entidades/Fase.cpp \
    Fases/Fase.cpp \
    Gerenciadores/GerenciadorEntrada.cpp \
    Gerenciadores/GerenciadorFisico.cpp \
    Gerenciadores/GerenciadorGrafico.cpp \
    Listas/ListaEntidade.cpp \
    Principal/Menus/Menu.cpp \
    Principal/Jogo.cpp \
    Principal/main.cpp
