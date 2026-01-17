function(CUSTOM_DEPS CUSTOM_TARGET_DIR)
execute_process(COMMAND
    git clone 
    https://github.com/wxWidgets/wxWidgets.git 
    --branch v3.3.1 
    ${CUSTOM_TARGET_DIR}
)
endfunction()
