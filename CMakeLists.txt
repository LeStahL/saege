# SAEGE - ShAdEr Graph Editor v1.57 "BINGE" 
# Copyright (C) 2019  Alexander Kraus <nr4@z10.info>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.8)

project(saege)

if(WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\5.12.1\\msvc2017_64")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)

set(SAEGE_SRC
    ui/MainWindow.ui
    ui/MainWindow.cpp
    ui/EditorPage/EditorPage2D/EditorPage2D.ui
    ui/EditorPage/EditorPage2D/EditorPage2D.cpp
    ui/EditorPage/EditorPage2D/EditorScene2D.cpp
    Saege.cpp
)

add_executable(saege-v1.57-binge ${SAEGE_SRC})
target_link_libraries(saege-v1.57-binge Qt5::Widgets Qt5::Gui)
