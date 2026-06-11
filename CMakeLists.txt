cmake_minimum_required(VERSION 3.10.0)
project(c_sample VERSION 0.1.0 LANGUAGES C CXX)

add_executable(sample1 sample1.cpp)

if(EMSCRIPTEN)
    # Build a modularized browser module with an explicit factory name.
    target_link_options(sample1 PRIVATE
        "SHELL:-sMODULARIZE=1"
        "SHELL:-sEXPORT_NAME=createSample1"
        "SHELL:-sEXPORTED_FUNCTIONS=['_main','_sayHello','_sayHello2']"
        "SHELL:-sEXPORTED_RUNTIME_METHODS=['ccall']"
        "SHELL:-sINVOKE_RUN=0"
        "SHELL:-sENVIRONMENT=web,worker,node"
    )
    set_target_properties(sample1 PROPERTIES OUTPUT_NAME "sample1")
    set_target_properties(sample1 PROPERTIES SUFFIX ".js")
endif()
