AddTarget(NAME EffectsCV
    SOURCE_DIR
        ${SOURCE_ROOT}/Proc/Effects/EffectsCV/
    SRC
        *.cpp
        *.h
    DEPS
    	CoreInt
    	CoreUtil
    	ProcInt
    	EffectsFactory
    	SettingsEffects
)