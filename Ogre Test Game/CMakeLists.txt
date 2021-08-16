cmake_minimum_required (VERSION 3.8)

add_executable (ogretest "Ogre Test Game.cpp" "Ogre Test Game.h" "gr.h" "gr.cpp")
target_link_libraries(ogretest OgreMain OgreBites OgreGLSupport OgreOverlay OgreRTShaderSystem)
