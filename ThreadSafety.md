

# Introduction #

# Reference counting #

# Mutexes #

# Platform-specific notes #

## Win32 ##

## POSIX ##

## Other platforms ##

In order to port CppEvents to different threading API, the following should be done:
  1. Create new directory for platform-specific files under 'Cpp/Events/' directory.
  1. Modify file 'Cpp/Events/Config.hpp' and add preprocessor code for detecting your platform and setting `PLATFORM_DIR` macro to the name of directory for platform-specific files.
  1. Implement `AtomicReferenceCounter` class in the file 'AtomicReferenceCounter.hpp.inl' using corresponding API for atomic operations.
  1. Implement static functions of the `Threading` class in the file 'Threading.cpp.inl'