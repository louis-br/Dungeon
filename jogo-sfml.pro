TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
    Gerenciadores/GerenciadorEntrada.cpp \
    Gerenciadores/GerenciadorFisico.cpp \
    Gerenciadores/GerenciadorGrafico.cpp \
    Entidade.cpp \
    EntidadeFisica.cpp \
    Jogo.cpp \
    main.cpp

HEADERS += \
    Gerenciadores/GerenciadorEntrada.h \
    Gerenciadores/GerenciadorFisico.h \
    Gerenciadores/GerenciadorGrafico.h \
    Entidade.h \
    EntidadeFisica.h \
    Jogo.h
