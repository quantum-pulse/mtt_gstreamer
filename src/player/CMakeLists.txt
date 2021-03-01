
add_executable(player gstPlayer.cxx)

target_link_libraries(player gstcore)

target_include_directories( player PUBLIC gstcore 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/../include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
