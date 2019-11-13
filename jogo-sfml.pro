TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

DISTFILES += \
    Recursos/Fontes/vinque.ttf

HEADERS += \
    Gerenciadores/GerenciadorEntrada.h \
    Gerenciadores/GerenciadorFisico.h \
    Gerenciadores/GerenciadorGrafico.h \
    Listas/Lista.h \
    Listas/ListaEntidade.h \
    Entidade.h \
    EntidadeFisica.h \
    Jogo.h \
    Menu.h

SOURCES += \
    Gerenciadores/GerenciadorEntrada.cpp \
    Gerenciadores/GerenciadorFisico.cpp \
    Gerenciadores/GerenciadorGrafico.cpp \
    Listas/ListaEntidade.cpp \
    Entidade.cpp \
    EntidadeFisica.cpp \
    Jogo.cpp \
    main.cpp \
    Menu.cpp
