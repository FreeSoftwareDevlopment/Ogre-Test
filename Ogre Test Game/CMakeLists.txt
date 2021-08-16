cmake_minimum_required (VERSION 3.8)

add_executable (CMakeTarget "Ogre Test Game.cpp" "Ogre Test Game.h")
target_link_libraries(CMakeTarget OgreMain OgreBites OgreGLSupport OgreOverlay freetype)
