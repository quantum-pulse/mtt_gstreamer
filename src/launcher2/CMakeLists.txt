
add_executable( glauncher2 launcher2.cxx )

target_link_libraries( glauncher2 ${GSTREAMER1_LIBRARIES} ${GLIB2_LIBRARIES} ${GTK3_LIBRARIES} )

target_include_directories( glauncher2 PUBLIC ${GSTREAMER1_INCLUDE_DIRS} ${GLIB2_INCLUDE_DIRS} ${GTK3_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>/include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
