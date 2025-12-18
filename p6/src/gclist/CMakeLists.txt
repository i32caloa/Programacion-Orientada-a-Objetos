add_library(gclist gclist.cc)

target_include_directories(gclist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(gclist catalog stage persons)

add_executable(gclist1-main gclist1-main.cc)
target_link_libraries(gclist1-main gclist catalog stage persons)

add_executable(gclist2-main gclist2-main.cc)
target_link_libraries(gclist2-main gclist catalog stage persons)

add_executable(gclist-main3 gclist-main3.cc)
target_link_libraries(gclist-main3 gclist catalog stage persons)