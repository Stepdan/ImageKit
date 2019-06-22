AddTarget(NAME ImageCore
    SOURCE_DIR
        ${SOURCE_ROOT}/Application/ImageCore/
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