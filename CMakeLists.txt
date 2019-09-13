cmake_minimum_required(VERSION 3.13.4)
project(type-traits-AlejandroMamaniAndia199802)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(tyope-traits-AlejandroMamaniAndia199802 main.cpp node.h self_list.h traits_list.h test/tester.cpp test/tester.h mock/mocker.cpp mock/mocker.h  )