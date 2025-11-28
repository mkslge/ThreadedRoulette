cmake_minimum_required(VERSION 3.31)
project(Roulette)

set(CMAKE_CXX_STANDARD 20)

set(SHARED_SOURCES Models/color.cpp
        Models/color.h
        Models/outcome.cpp
        Models/outcome.h
        Utility/utility.cpp
        Utility/utility.h
        messenger.cpp
        messenger.h
        Utility/OperationCodes.cpp
        Utility/OperationCodes.h
        Utility/threadutil.cpp
        Utility/threadutil.h
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
        Utility/threadutil.cpp
        Utility/threadutil.h
        Client/clientinfo.cpp
        Client/clientinfo.h
)
