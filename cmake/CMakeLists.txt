# ---------------------------------------------------------------------------
# GET_ABSOLUTE_SOURCES
# Given a list of sources, return the corresponding absolute paths
# 'varname': name of the var the list of absolute paths should be stored into
# 'sources': list of source files

macro(GET_ABSOLUTE_SOURCES varname sources)

  set(${varname})
  foreach(file ${sources})
    get_filename_component(abs_file ${file} ABSOLUTE)
    if(NOT EXISTS ${abs_file})
      set(abs_file "${PROJECT_SOURCE_DIR}/${file}")
    endif(NOT EXISTS ${abs_file})
    set(${varname} ${${varname}} ${abs_file})
  endforeach(file)

endmacro(GET_ABSOLUTE_SOURCES)

# ---------------------------------------------------------------------------
# GET_RELATIVE_SOURCES
# Given a list of sources, return the corresponding relative paths to
# a directory.
# 'varname': name of the var the list of absolute paths should be stored into
# 'dir': path to the dir we want relative path from
# 'sources': list of *absolute* path to the source files

macro(GET_RELATIVE_SOURCES varname dir sources)

  get_filename_component(dir_abs ${dir} ABSOLUTE)

  set(${varname})
  foreach(file ${sources})
    file(RELATIVE_PATH rel_file "${dir}" "${file}")
    set(${varname} ${${varname}} ${rel_file})
  endforeach(file)

endmacro(GET_RELATIVE_SOURCES)

if (USE_GTK OR USE_GTK3)
get_absolute_sources(abs_gtk_cpp_sources "${GTK_SRCS};${GTK_HDRS}")
get_relative_sources(rel_gtk_cpp_sources "${eiskaltdcpp-gtk_SOURCE_DIR}/po" "${abs_gtk_cpp_sources}")
file(MAKE_DIRECTORY "${eiskaltdcpp-gtk_BINARY_DIR}/po")
set(gtk_cpp_files_from "${eiskaltdcpp-gtk_BINARY_DIR}/po/eiskaltdcpp-gtk_cpp_srcs.txt")
string(REGEX REPLACE ";" "\n" gtk_cpp_contents "${rel_gtk_cpp_sources}")
file(WRITE "${gtk_cpp_files_from}" "${gtk_cpp_contents}")

get_absolute_sources(abs_gtk_ui_sources "${GTK_UI}")
get_relative_sources(rel_gtk_ui_sources "${eiskaltdcpp-gtk_SOURCE_DIR}/po" "${abs_gtk_ui_sources}")
set(gtk_ui_files_from "${eiskaltdcpp-gtk_BINARY_DIR}/po/eiskaltdcpp-gtk_ui_srcs.txt")
string(REGEX REPLACE ";" "\n" gtk_ui_contents "${rel_gtk_ui_sources}")
file(WRITE "${gtk_ui_files_from}" "${gtk_ui_contents}")
endif (USE_GTK OR USE_GTK3)
