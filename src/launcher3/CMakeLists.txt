
add_executable( glauncher3 launcher3.cxx )

target_link_libraries( glauncher3 ${GSTREAMER1_LIBRARIES} ${GLIB2_LIBRARIES} ${GTK2_LIBRARIES} )

target_include_directories( glauncher3 PUBLIC ${GSTREAMER1_INCLUDE_DIRS} ${GLIB2_INCLUDE_DIRS} ${GTK2_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/../include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
