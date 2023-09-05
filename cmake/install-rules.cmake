install(
    TARGETS hms_exe
    RUNTIME COMPONENT hms_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
