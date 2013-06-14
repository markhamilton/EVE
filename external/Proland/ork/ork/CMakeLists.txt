set(LIBNAME "ork")

# Sources
include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/libraries" "${PROJECT_SOURCE_DIR}/libraries/*")
file(GLOB SOURCE_FILES *.cpp */*.cpp)

# Libraries
set(LIBS GLEW glut pthread stb_image tinyxml)
if(UNIX)
	set(LIBS ${LIBS} rt)
endif(UNIX)

# Static or shared?
set(LIBTYPE STATIC)
if(BUILD_SHARED)
	set(LIBTYPE SHARED)
endif(BUILD_SHARED)

# Create a static library
add_library(${LIBNAME} ${LIBTYPE} ${SOURCE_FILES})
target_link_libraries(${LIBNAME} ${LIBS})

# Adds SO Version and subversion. To be added to ensure ABI/API compatibility.
#SET_TARGET_PROPERTIES(${LIBNAME} PROPERTIES SOVERSION ${ORK_VERSION_MAJOR} VERSION ${ORK_VERSION})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

link_directories(${PROJECT_SOURCE_DIR}/lib)

# Install headers
FOREACH(subdir core math render resource scenegraph taskgraph ui util)
  FILE(GLOB include-files ${subdir}/*.h)
  INSTALL(FILES ${include-files} DESTINATION include/ork/${subdir})
ENDFOREACH(subdir)

# Install library
INSTALL(TARGETS ork LIBRARY DESTINATION ${LIB_INSTALL_DIR} ARCHIVE DESTINATION ${LIB_INSTALL_DIR})

SET(ORK_CFLAGS "-DORK_API= -DTIXML_USE_STL")

CONFIGURE_FILE(ork.pc.in ${PROJECT_BINARY_DIR}/ork.pc @ONLY)
INSTALL(FILES ${PROJECT_BINARY_DIR}/ork.pc DESTINATION ${LIB_INSTALL_DIR}/pkgconfig)
