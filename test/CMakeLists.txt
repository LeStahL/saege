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

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/tools)

set(NODE_MODEL_SRC
    NodeModelTest.cpp 
    ${PROJECT_SOURCE_DIR}/model/graph/Graph.cpp
    ${PROJECT_SOURCE_DIR}/model/graph/Node.cpp
    ${PROJECT_SOURCE_DIR}/model/graph/NodeModel.cpp
)

add_executable(NodeModelTest ${NODE_MODEL_SRC}) 
target_link_libraries(NodeModelTest Qt5::Widgets Qt5::Gui)

set(MATRIX_MODEL_SRC
    MatrixModelTest.cpp 
    ${PROJECT_SOURCE_DIR}/model/Matrix.cpp
    ${PROJECT_SOURCE_DIR}/model/MatrixModel.cpp
    ${PROJECT_SOURCE_DIR}/model/MatrixView.cpp
    ${PROJECT_SOURCE_DIR}/tools/ColorProvider.cpp
)

add_executable(MatrixModelTest ${MATRIX_MODEL_SRC}) 
target_link_libraries(MatrixModelTest Qt5::Widgets Qt5::Gui)
