AddTarget(NAME ImageKitCore
    SOURCE_DIR
        ${SOURCE_ROOT}/Application/ImageKitCore/
    SRC
        *.cpp
        *.h
    SUBDIRS
        Core/
        Interfaces/
        Undo/
    DEPS
        CoreInt
        CoreUtil
        ProcInt
    QT_USE
        Core
        Widgets
)