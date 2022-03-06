cmake_minimum_required(VERSION 3.21)
project(client)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

include_directories(.)

link_libraries(ws2_32 wsock32)

add_executable(client
        formes/Cercle.cpp
        formes/Cercle.h
        client/ClientDessin.cpp
        client/ClientDessin.h
        Erreur.cpp
        Erreur.h
        formes/Forme.cpp
        formes/Forme.h
        formes/Groupe.cpp
        formes/Groupe.h
        client/Winsock.cpp
        client/Winsock.h
        formes/Polygone.cpp
        formes/Polygone.h
        formes/Segment.cpp
        formes/Segment.h
        formes/Triangle.cpp
        formes/Triangle.h
        formes/Vecteur2D.cpp
        formes/Vecteur2D.h main.cpp main.h libgraphique/LibrairieGraphique.cpp libgraphique/LibrairieGraphique.h libgraphique/awt.cpp libgraphique/awt.h formes/Matrice.cpp formes/Matrice.h sauvegarde/Format.cpp sauvegarde/Format.h sauvegarde/txt.cpp sauvegarde/txt.h)
