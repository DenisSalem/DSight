cmake_minimum_required(VERSION 3.0.2)

find_program(PYTHON "python")

if(DEFINED USE_GLFW3)
find_package(OpenGL REQUIRED)
endif()

if (PYTHON)
    set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
    set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
    set(OUTPUT      "${CMAKE_CURRENT_BINARY_DIR}/build/PythonBinding")
    set(PYTHON_HEADER_DIR "python3.6m")
    
    configure_file(${SETUP_PY_IN} ${SETUP_PY})
    configure_file("python.hpp.in" "python.hpp")
    
    add_custom_command(
		OUTPUT ${OUTPUT}
        COMMAND ${CMAKE_COMMAND} -E touch ${OUTPUT}
    )

    install(CODE "execute_process(COMMAND ${PYTHON} ${SETUP_PY} install --user)")
endif()
