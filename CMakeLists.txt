cmake_minimum_required(VERSION 3.19)
project(linked_hash_map C)

set(CMAKE_C_STANDARD 11)

add_executable(linked_hash_map main.c linked_hash_map_entry.h linked_hash_map_struct.h linked_hash_map_put.c linked_hash_map_put.h linked_hash_map_utils.c linked_hash_map_utils.h linked_hash_map.c linked_hash_map.h linked_hash_map_get.c linked_hash_map_get.h linked_hash_map_remove.c linked_hash_map_remove.h tests.c tests.h)