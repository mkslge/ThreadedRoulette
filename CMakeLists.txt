cmake_minimum_required(VERSION 3.31)
project(Roulette)

set(CMAKE_CXX_STANDARD 20)

set(SHARED_SOURCES color.cpp
        color.h
        outcome.cpp
        outcome.h
        Utility/utility.cpp
        Utility/utility.h
        messenger.cpp
        messenger.h
        roulette.cpp
        roulette.h
        receiver.cpp
        receiver.h
        Utility/OperationCodes.cpp
        Utility/OperationCodes.h
)

add_executable(Server
        Server/server.cpp
        ${SHARED_SOURCES}
)

add_executable(Client
        Client/client.cpp
        ${SHARED_SOURCES}
        Utility/OperationCodes.cpp
        Utility/OperationCodes.h
)
