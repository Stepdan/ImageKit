AddTarget(NAME CoreUtil
    SOURCE_DIR
        ${SOURCE_ROOT}/Core/Util/
    SRC
        *.cpp
        *.h
    DEPS
    	CoreInt
        CoreMediaTypes
    QT_USE
        Core
        Widgets
)