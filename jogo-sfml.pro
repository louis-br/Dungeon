TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

DISTFILES += \
    Recursos/Fontes/vinque.ttf \
    Recursos/Personagens/Original/enemies-2.gif \
    Recursos/Fundos/Background.png \
    Recursos/Fundos/Forest.png \
    Recursos/Fundos/Fundo1.png \
    Recursos/Fundos/Fundo4.png \
    Recursos/Fundos/Fundo6.png \
    Recursos/Obstaculos/SpiderWeb.png \
    Recursos/Obstaculos/stalactite4.png \
    Recursos/Personagens/Original/Anaos.png \
    Recursos/Personagens/Original/Arcade - Gradius II Vulcan Venture - Phoenix.png \
    Recursos/Personagens/Original/DnDToD_Fighter.png \
    Recursos/Personagens/Original/NES - Rampage - George.png \
    Recursos/Personagens/Original/NES - Rampage - Lizzie.png \
    Recursos/Personagens/10.png \
    Recursos/Personagens/3.png \
    Recursos/Personagens/Anao.png \
    Recursos/Personagens/Anao2.png \
    Recursos/Personagens/Anao3.png \
    Recursos/Personagens/Guerreiro.png \
    Recursos/Personagens/Inimigo1.png \
    Recursos/Personagens/Personagem.png \
    Recursos/Personagens/Personagem2.png \
    Recursos/Personagens/spider.png \
    Recursos/Plataformas/Grass.png \
    Recursos/Plataformas/Plataforma1.png \
    Recursos/Plataformas/Plataforma2.png \
    Recursos/Plataformas/Plataforma3.png \
    Recursos/Plataformas/PlataformaMediaBaixa.png \
    Recursos/Plataformas/PlataformaPequenaBaixa.png \
    Recursos/Plataformas/PlataformaPequenaGrande.png \
    Recursos/Plataformas/PlataformaPequenaMedia.png \
    Recursos/Plataformas/Tijolo.png \
    Recursos/Fases/Cenario_OutOfCave.dat

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
    Listas/MapaRecursos.h \
    Listas/VetorEntidadeFisica.h \
    Personagens/Cavaleiro.h \
    Personagens/CavaleiroAntigo.h \
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
    Personagens/Cavaleiro.cpp \
    Personagens/CavaleiroAntigo.cpp \
    Personagens/Jogador.cpp \
    Personagens/Personagem.cpp \
    Principal/Menus/Menu.cpp \
    Principal/Jogo.cpp \
    Principal/main.cpp
