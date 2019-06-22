AddTarget(NAME ImageKitFactory
    SOURCE_DIR
        ${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitFactory/
    SRC
        *.cpp
        *.h
    DEPS
    	ImageKitPluginsInt
    QT_USE
        Core
        Widgets
)