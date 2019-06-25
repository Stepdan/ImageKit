AddTarget(NAME ImageKitUtil
    SOURCE_DIR
		${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitUtil/
    SRC
        *.cpp
        *.h
    UI_FILES
        ${SOURCE_DIR}/UI/*.ui
    SUBDIRS
    	UI/
    DEPS
    	ImageKitPluginsInt
    QT_USE
        Core
        Widgets
)
