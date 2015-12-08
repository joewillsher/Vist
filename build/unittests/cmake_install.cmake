# Install script for directory: /Users/JoeWillsher/developer/swift_llvm/llvm/unittests

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/ADT/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/Analysis/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/AsmParser/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/Bitcode/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/CodeGen/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/DebugInfo/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/ExecutionEngine/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/IR/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/LineEditor/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/Linker/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/MC/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/Option/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/ProfileData/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/Support/cmake_install.cmake")
  include("/Users/JoeWillsher/developer/swift_llvm/build/unittests/Transforms/cmake_install.cmake")

endif()

