
add_library(gstcore SHARED gst_manager.cxx )

target_link_libraries(gstcore filesys ${GSTREAMER1_LIBRARIES} ${GLIB2_LIBRARIES} ${GTK2_LIBRARIES} )

target_include_directories( gstcore PUBLIC ${GSTREAMER1_INCLUDE_DIRS} ${GLIB2_INCLUDE_DIRS} ${GTK2_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/../include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
