cmake_minimum_required(VERSION 3.0.0)
project(part2gui VERSION 0.1.0)

include_directories(D:/vcpkg/installed/x64-windows/include)
link_directories(D:/vcpkg/installed/x64-windows/lib)

add_executable(part2gui main.cpp)

find_package(FLTK CONFIG REQUIRED)
target_link_libraries(part2gui PRIVATE fltk fltk_gl fltk_forms fltk_images)

# TARGET_LINK_LIBRARIES(part2gui
    # fltk
# )