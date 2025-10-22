# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-src"
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-build"
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/antoniocl53/Escritorio/uni/2/1c/poo/p3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
