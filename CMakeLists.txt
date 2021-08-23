cmake_minimum_required(VERSION 3.19)
project(AdvancedVersion)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvancedVersion main.cpp PayOff.cpp PayOff.h VanillaOption.cpp VanillaOption.h PayOffFactory.cpp PayOffFactory.h PayOffHelper.cpp PayOffHelper.h Bridge.cpp Bridge.h Random1.h Random1.cpp MonteCarloEngine.cpp MonteCarloEngine.h Options.h)