cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(dr_libs C)

add_library(dr_wav STATIC "dr_libs/dr_wav.h" "dr_wav_impl.c")
add_library(dr_flac STATIC "dr_libs/dr_flac.h" "dr_flac_impl.c")
add_library(dr_mp3 STATIC "dr_libs/dr_mp3.h" "dr_mp3_impl.c")