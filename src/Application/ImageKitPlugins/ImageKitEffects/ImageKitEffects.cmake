AddTarget(NAME ImageKitEffects
    SOURCE_DIR
        ${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitEffects/
    SRC
        *.cpp
        *.h
        *.qrc
    UI_FILES
        ${SOURCE_DIR}/*.ui
        ${SOURCE_DIR}/UI/*.ui
    SUBDIRS
        UI/
    DEPS
        ImageKitPluginsFactory
    QT_USE
        Core
        Widgets
)