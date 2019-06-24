cmake_minimum_required(VERSION 3.7)

project(ImageKit)

find_package(Qt5Core)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install/")
set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od")

if (MSVC_VERSION GREATER_EQUAL "1900")
	include(CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
	if (_cpp_latest_flag_supported)
		add_compile_options("/std:c++latest")
	endif()
endif()

########
# Пути #
########

include_directories(${CMAKE_SOURCE_DIR})

set(REPO_ROOT       ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ROOT      ${REPO_ROOT}/cmake)
set(SOURCE_ROOT     ${REPO_ROOT}/src)

set(THIRDPARTY_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

# Module path
set(CMAKE_MODULE_PATH
	${CMAKE_ROOT}
	${SOURCE_ROOT}
)

###############
# Configuring #
###############

# cmake functions
include(${CMAKE_ROOT}/Target.cmake)
#include(${FOUNDATION_ROOT}/LinkLibraries.cmake)
#include(${CMAKE_ROOT}/ProductConfig.cmake)

# Подключение библиотек
# Core
include (${SOURCE_ROOT}/Core/Types/CoreTypes.cmake)
include (${SOURCE_ROOT}/Core/Interfaces/CoreInt.cmake)
include (${SOURCE_ROOT}/Core/MediaTypes/CoreMediaTypes.cmake)
include (${SOURCE_ROOT}/Core/Util/CoreUtil.cmake)

# Proc
include (${SOURCE_ROOT}/Proc/SettingsEffect/SettingsEffect.cmake)
include (${SOURCE_ROOT}/Proc/Interfaces/ProcInt.cmake)
include (${SOURCE_ROOT}/Proc/ProcUtil/ProcUtil.cmake)
include (${SOURCE_ROOT}/Proc/Effects/EffectsFactory/EffectsFactory.cmake)
include (${SOURCE_ROOT}/Proc/Effects/EffectsCV/EffectsCV.cmake)

# Util
include (${SOURCE_ROOT}/Util/Util.cmake)

# ImageKit
include (${SOURCE_ROOT}/Application/ImageKitCore/ImageKitCore.cmake)
include (${SOURCE_ROOT}/Application/ImageKitPlugins/Interfaces/ImageKitPluginsInt.cmake)
include (${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitUtil/ImageKitUtil.cmake)
include (${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitFactory/ImageKitFactory.cmake)
include (${SOURCE_ROOT}/Application/ImageKitPlugins/ImageKitEffects/ImageKitEffects.cmake)
include (${SOURCE_ROOT}/Application/ImageKitUI/ImageKitUI.cmake)

# Application
include (${SOURCE_ROOT}/Application/ImageKit/ImageKit.cmake)
