cmake_minimum_required(VERSION 3.21)
project(maquette_prof)

set(CMAKE_CXX_STANDARD 14)

include_directories(clientdessin/clientdessin)

link_libraries(ws2_32 wsock32)

add_executable(maquette_prof
        clientdessin/clientdessin/ClientDessin.cpp
        clientdessin/clientdessin/ClientDessin.h
        clientdessin/clientdessin/Croix.cpp
        clientdessin/clientdessin/Croix.h
        clientdessin/clientdessin/Erreur.cpp
        clientdessin/clientdessin/Erreur.h
        clientdessin/clientdessin/Forme.cpp
        clientdessin/clientdessin/Forme.h
        clientdessin/clientdessin/MaWinsock.cpp
        clientdessin/clientdessin/MaWinsock.h
        clientdessin/clientdessin/Rond.cpp
        clientdessin/clientdessin/Rond.h
        clientdessin/clientdessin/TestBidon.cpp
        clientdessin/clientdessin/TestClientDessin1.cpp
        clientdessin/clientdessin/TestClientDessin2.cpp)
