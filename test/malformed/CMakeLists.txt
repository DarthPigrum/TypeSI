try_compile(FUNCTION_CALL ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/function_call.cpp)
if(FUNCTION_CALL)
    message(WARNING "malformed function call succeeded")
endif()

try_compile(ADDITION ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/addition.cpp)
if(ADDITION)
    message(WARNING "malformed addition succeeded")
endif()

try_compile(ADDITION_ASSIGNMENT ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/addition_assignment.cpp)
if(ADDITION_ASSIGNMENT)
    message(WARNING "malformed addition assignment succeeded")
endif()

try_compile(SUBTRACTION ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/subtraction.cpp)
if(SUBTRACTION)
    message(WARNING "malformed subtraction succeeded")
endif()

try_compile(SUBTRACTION_ASSIGNMENT ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/subtraction_assignment.cpp)
if(SUBTRACTION_ASSIGNMENT)
    message(WARNING "malformed subtraction assignment succeeded")
endif()

try_compile(MULTIPLICATION_ASSIGNMENT ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/multiplication_assignment.cpp)
if(MULTIPLICATION_ASSIGNMENT)
    message(WARNING "malformed multiplication assignment succeeded")
endif()

try_compile(DIVISION_ASSIGNMENT ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/division_assignment.cpp)
if(DIVISION_ASSIGNMENT)
    message(WARNING "malformed division assignment succeeded")
endif()
