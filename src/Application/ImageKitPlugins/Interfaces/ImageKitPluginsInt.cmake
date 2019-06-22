AddTarget(NAME ImageKitPluginsInt
    SOURCE_DIR
        ${SOURCE_ROOT}/Application/ImageKitPlugins/Interfaces/
    SRC
        *.cpp
        *.h
    DEPS
    	CoreInt
    	CoreUtil
    QT_USE
        Core
        Widgets
)