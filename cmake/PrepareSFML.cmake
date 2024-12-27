include(FetchContent)

FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.2
  GIT_SHALLOW ON
)

FetchContent_MakeAvailable(SFML)


add_library(ThirdpartySFML INTERFACE)

target_link_libraries(ThirdpartySFML
  INTERFACE
    sfml-system
    sfml-main
    sfml-graphics
    sfml-window
)


add_library(Thirdparty::SFML ALIAS ThirdpartySFML)
