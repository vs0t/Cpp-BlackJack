cmake_minimum_required(VERSION 3.16)
project(blackjack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(inc)

#add_executable(blackjack2 ./app/CardTest.cpp ./src/Card.cpp ./src/Deck.cpp ./src/Player.cpp)

# Include the local googletest directory
add_subdirectory(build/_deps/googletest-src)

enable_testing()

add_subdirectory(tests)
