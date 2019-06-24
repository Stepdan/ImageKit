AddTarget(NAME ImageKitUtil
    SOURCE_DIR
		${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitUtil/
    SRC
        *.cpp
        *.h
    DEPS
    	ImageKitPluginsInt
    QT_USE
        Core
        Widgets
)
