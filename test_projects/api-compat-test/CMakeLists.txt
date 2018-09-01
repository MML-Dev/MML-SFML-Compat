
set(COMPAT_SOURCES api_usage_system.cpp api_usage_audio.cpp api_usage_network.cpp api_usage_window.cpp api_usage_graphics.cpp)
add_library(api_usage_reference  STATIC ${COMPAT_SOURCES})
add_library(api_usage_mml_compat STATIC ${COMPAT_SOURCES})
target_include_directories(api_usage_reference PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/SFML/include")
target_include_directories(api_usage_mml_compat PRIVATE "${CMAKE_SOURCE_DIR}/MML/include")
