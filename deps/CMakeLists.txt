include(FetchContent)

option(USE_SYSTEM_DEPS CACHE OFF)
option(LINK_DEPS_STATIC CACHE ON)

# Don't build shared libs if we want to link to deps statically
if(LINK_DEPS_STATIC)
  set(BUILD_SHARED_LIBS OFF)
else()
  set(BUILD_SHARED_LIBS ON)
endif()

message(STATUS "Fetching third party libraries")
#======================================

# SFML
set(SFML_VERSION "2.5.1")
FetchContent_Declare(
    sfml
    GIT_REPOSITORY  "https://github.com/SFML/SFML.git"
    GIT_TAG         "${SFML_VERSION}"
)

add_subdirectory(sfml)

#======================================
message(STATUS "Fetching thirdparty libraries done")