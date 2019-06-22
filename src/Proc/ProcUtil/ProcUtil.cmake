AddTarget(NAME ProcUtil
    SOURCE_DIR
        ${SOURCE_ROOT}/Proc/ProcUtil/
    SRC
        *.cpp
        *.h
    DEPS
    	CoreInt
    	CoreUtil
)