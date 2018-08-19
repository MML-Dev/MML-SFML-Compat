
# Make sure MML_SFML_COMPAT is defined for project that don't use SFML's imported targets
add_definitions(-DMML_SFML_COMPAT)

set(SFML_ROOT "${MML_INSTALL_DIR}/lib/cmake/SFML")
set(IMGUI_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/ImGui")
add_subdirectory(ImGUI-SFML)

# SelbaWard has no build system!
# add_subdirectory(SelbaWard)

set(SFML_ROOT "${MML_INSTALL_DIR}/lib/cmake/SFML")
add_subdirectory(SFNUL)

# Thor uses old FindSFML.cmake
set(SFML_ROOT "${MML_INSTALL_DIR}")
add_subdirectory(Thor)

