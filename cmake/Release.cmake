include(CPack)

set(CPACK_PACKAGE_NAME "parabolic-antenna-calculator")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_VENDOR "ISET")

if (WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
elseif (APPLE)
    set(CPACK_GENERATOR "DragNDrop")
elseif (UNIX)
    set(CPACK_GENERATOR "TGZ")
endif ()