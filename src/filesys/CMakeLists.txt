
add_library(filesys SHARED filesys_mgr.cxx )

target_link_libraries(filesys stdc++fs)

target_include_directories(filesys PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>/../include
  $<INSTALL_INTERFACE:include>
)

#add_subdirectory(test)
