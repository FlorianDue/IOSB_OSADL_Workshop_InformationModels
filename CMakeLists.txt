cmake_minimum_required(VERSION 3.0.0)

if(NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR})
endif()

file(MAKE_DIRECTORY "${GENERATE_OUTPUT_DIR}")
set(GENERATE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/src_generated/")
include_directories("${GENERATE_OUTPUT_DIR}")

################################
#set the path to the directory that contains the temperature.bsd, temperature.csv and temperature.xml files 
###########################
set(INFORMATION_MODEL_DIR ${PROJECT_SOURCE_DIR}   )

ua_generate_nodeset_and_datatypes(
        NAME "temperature"
        FILE_BSD "${INFORMATION_MODEL_DIR}/heater.bsd"
        FILE_CSV "${INFORMATION_MODEL_DIR}/heater.csv"
        FILE_NS "${INFORMATION_MODEL_DIR}/heater.xml"
		NAMESPACE_MAP "2:http://IOSB:OSADL_Workshop.com"
        OUTPUT_DIR ${GENERATE_OUTPUT_DIR}
        INTERNAL
)

add_example(temperature temperature.c
            ${UA_NODESET_TEMPERATURE_SOURCES}
            ${UA_TYPES_TEMPERATURE_SOURCES}
            )
add_dependencies(temperature open62541-generator-ns-temperature)
