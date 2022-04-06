# CMakeList.txt : CMake project for Server_Socket, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Server_Socket "Server_Socket.cpp" "Server_Socket.h" "Player.h" "Player.cpp" "Starter.cpp" "Starter.h")

# TODO: Add tests and install targets if needed.
