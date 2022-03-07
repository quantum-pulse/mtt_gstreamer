
add_executable( glauncher1 launcher1.cxx )

target_link_libraries( glauncher1 ${GSTREAMER1_LIBRARIES} ${GLIB2_LIBRARIES} ${GTK3_LIBRARIES} )

target_include_directories( glauncher1 PUBLIC ${GSTREAMER1_INCLUDE_DIRS} ${GLIB2_INCLUDE_DIRS} ${GTK3_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>/../include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
