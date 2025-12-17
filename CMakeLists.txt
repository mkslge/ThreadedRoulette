cmake_minimum_required(VERSION 3.31)
project(Roulette)

set(CMAKE_CXX_STANDARD 20)

set(SHARED_SOURCES

        Models/color.cpp
        Models/color.h

        Models/outcome.cpp
        Models/outcome.h

        Models/bet.cpp
        Models/bet.h

        Models/clientinfo.cpp
        Models/clientinfo.h

        Utility/utility.cpp
        Utility/utility.h

        messenger.cpp
        messenger.h

        Utility/OperationCodes.cpp
        Utility/OperationCodes.h

        Server/serverutility.cpp
        Server/serverutility.h

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
        Server/serverutility.cpp
        Server/serverutility.h
        Models/clientinfo.cpp
        Models/clientinfo.h
        Models/bet.cpp
        Models/bet.h
        Client/clientutility.cpp
        Client/clientutility.h
        Models/wheel.cpp
        Models/wheel.h
)
