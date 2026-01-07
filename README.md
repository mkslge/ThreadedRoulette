# Roulette (Client/Server, C++20)

A simple client/server Roulette game written in **C++20** using **CMake**.  
The server spins a roulette wheel and evaluates bets sent by clients over UDP.

## Features

### Client
- Join the server
- Place a roulette bet (amount + color)
- Receive win/loss results
- Update local balance

### Server
- Accept join requests
- Generate roulette outcomes
- Evaluate bets and reply with win/loss messages
- Display a roulette spin animation (ASCII)

## Build

From the root directory of the project:

```bash
cmake -S . -B build
cmake --build build -j
```

Start the server...
```
    ./build/Server
```

Start the client...
```angular2html
    ./build/Client
```

### Requirements
- CMake (project declares CMake 3.31)
- C++20 compiler (Clang/GCC/MSVC)
- POSIX sockets (Linux/macOS recommended)

### Configure and Build

From the repository root:

```bash
cmake -S . -B build
cmake --build build -j


