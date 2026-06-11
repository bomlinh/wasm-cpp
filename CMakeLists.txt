cmake_minimum_required(VERSION 3.10.0)
project(c_sample VERSION 0.1.0 LANGUAGES C CXX)

add_executable(sample_embind sample_embind.cpp)

if(EMSCRIPTEN)
    # Build a modularized browser module with an explicit factory name.
    target_link_options(sample_embind PRIVATE
        "SHELL:--bind"  # <--- must have for emscripten binding
        "SHELL:-sMODULARIZE=1"
        "SHELL:-sEXPORT_NAME=createSample1"
        # "SHELL:-sEXPORTED_FUNCTIONS=['_main','_sayHello','_sayHello2']" <--- must be deleted 'cause of binding
        "SHELL:-sEXPORTED_RUNTIME_METHODS=['ccall']"
        "SHELL:-sINVOKE_RUN=0"
        "SHELL:-sENVIRONMENT=web,worker,node"
    )
    set_target_properties(sample_embind PROPERTIES OUTPUT_NAME "sample_embind")
    set_target_properties(sample_embind PROPERTIES SUFFIX ".js")
endif()
