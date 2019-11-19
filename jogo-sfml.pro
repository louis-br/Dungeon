TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

DISTFILES += \
    Recursos/Fontes/vinque.ttf \
    Recursos/Personagens/enemies-2.gif \
    Recursos/Blocos/Tijolo.png \
    Recursos/Personagens/Arcade - Gradius II Vulcan Venture - Phoenix.png \
    Recursos/Personagens/DnDToD_Fighter.png \
    Recursos/Personagens/Guerreiro.png \
    Recursos/Personagens/NES - Rampage - George.png \
    Recursos/Personagens/NES - Rampage - Lizzie.png

HEADERS += \
    Blocos/Tijolo.h \
    Entidades/Entidade.h \
    Entidades/EntidadeFisica.h \
    Fases/DefesaInvasao.h \
    Fases/Fase.h \
    Gerenciadores/GerenciadorEntrada.h \
    Gerenciadores/GerenciadorFisico.h \
    Gerenciadores/GerenciadorGrafico.h \
    Listas/Lista.h \
    Listas/ListaEntidade.h \
    Listas/VetorEntidadeFisica.h \
    Personagens/Guerreiro.h \
    Personagens/Jogador.h \
    Personagens/Personagem.h \
    Principal/Menus/Menu.h \
    Principal/Jogo.h

SOURCES += \
    Blocos/Tijolo.cpp \
    Entidades/Entidade.cpp \
    Entidades/EntidadeFisica.cpp \
    Fases/DefesaInvasao.cpp \
    Fases/Fase.cpp \
    Gerenciadores/GerenciadorEntrada.cpp \
    Gerenciadores/GerenciadorFisico.cpp \
    Gerenciadores/GerenciadorGrafico.cpp \
    Listas/ListaEntidade.cpp \
    Listas/VetorEntidadeFisica.cpp \
    Personagens/Guerreiro.cpp \
    Personagens/Jogador.cpp \
    Personagens/Personagem.cpp \
    Principal/Menus/Menu.cpp \
    Principal/Jogo.cpp \
    Principal/main.cpp
