AddTarget(EXECUTABLE NAME ImageKit
    SOURCE_DIR
        ${SOURCE_ROOT}/Application/ImageKit/
    SRC
        *.cpp
        *.h
        *.qrc
    UI_FILES
        ${SOURCE_DIR}/*.ui
    DEPS
        ImageKitUI
    QT_USE
        Core
        Widgets
)