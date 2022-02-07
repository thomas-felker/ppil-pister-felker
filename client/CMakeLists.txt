cmake_minimum_required(VERSION 3.21)
project(client)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

link_libraries(ws2_32 wsock32)

add_executable(client
        Cercle.cpp
        Cercle.h
        ClientDessin.cpp
        ClientDessin.h
        Erreur.cpp
        Erreur.h
        Forme.cpp
        Forme.h
        Groupe.cpp
        Groupe.h
        MaWinsock.cpp
        MaWinsock.h
        Polygone.cpp
        Polygone.h
        Segment.cpp
        Segment.h
        Triangle.cpp
        Triangle.h
        Vecteur2D.cpp
        Vecteur2D.h)
