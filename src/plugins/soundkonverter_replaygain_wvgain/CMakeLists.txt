project(soundkonverter_replaygain_wvgain)

if (KF5_BUILD)
    find_package(KF5 REQUIRED COMPONENTS WidgetsAddons)
else ()
    find_package(KDE4 REQUIRED)
    include (KDE4Defaults)
    include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} )
endif ()

set(soundkonverter_replaygain_wvgain_SRCS
   soundkonverter_replaygain_wvgain.cpp
 )

if (KF5_BUILD)
    add_library(soundkonverter_replaygain_wvgain MODULE ${soundkonverter_replaygain_wvgain_SRCS})
    target_link_libraries(soundkonverter_replaygain_wvgain KF5::WidgetsAddons soundkonvertercore )
else ()
    kde4_add_plugin(soundkonverter_replaygain_wvgain ${soundkonverter_replaygain_wvgain_SRCS})
    target_link_libraries(soundkonverter_replaygain_wvgain ${KDE4_KDEUI_LIBS} soundkonvertercore )
endif ()

########### install files ###############

install(TARGETS soundkonverter_replaygain_wvgain DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES soundkonverter_replaygain_wvgain.desktop DESTINATION ${SERVICES_INSTALL_DIR})
