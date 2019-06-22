AddTarget(NAME CoreMediaTypes
    SOURCE_DIR
        ${SOURCE_ROOT}/Core/MediaTypes/
    SRC
        *.cpp
        *.h
    DEPS
    	CoreInt
    QT_USE
        Core
        Widgets
)