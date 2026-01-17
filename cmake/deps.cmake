execute_process(COMMAND
    git clone 
    https://github.com/wxWidgets/wxWidgets.git 
    --branch v3.3.1 
    ${CUSTOM_TARGET_DIR}
)

include_directories(third_party/wxWidgets/include)
