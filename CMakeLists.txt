cmake_minimum_required(VERSION 3.20)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "" FORCE)

project(MeuJogoSFML)

# --- REGRAS PARA LIMPAR OS AVISOS DO SFML 2.5.1 ---
# Oculta o aviso "Compatibility with CMake < 3.10"
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)
set(CMAKE_POLICY_DEFAULT_CMP0177 OLD)
# --------------------------------------------------
# --------------------------------------------------

# As suas configurações anteriores
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
)
FetchContent_MakeAvailable(SFML)

add_executable(MeuJogoFinal main.cpp)
target_link_libraries(MeuJogoFinal PRIVATE sfml-graphics sfml-window sfml-system)