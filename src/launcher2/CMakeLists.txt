
add_executable( glauncher2 launcher2.cxx )

target_link_libraries( glauncher2 ${GSTREAMER1_LIBRARIES} ${GLIB2_LIBRARIES} ${GTK2_LIBRARIES} )

target_include_directories( glauncher2 PUBLIC ${GSTREAMER1_INCLUDE_DIRS} ${GLIB2_INCLUDE_DIRS} ${GTK2_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/../include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
