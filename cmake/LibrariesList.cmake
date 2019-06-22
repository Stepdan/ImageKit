# Список общих библиотек
set(COMMON_LIBS_ROOT     ${THIRDPARTY_ROOT}/common)
set(COMMON_LIBS_PATH     ${COMMON_LIBS_ROOT}/lib)

set(COMMON_LIBS)
list(APPEND COMMON_LIBS "zlib")
list(APPEND COMMON_LIBS "libtiff")
list(APPEND COMMON_LIBS "libjpeg")
list(APPEND COMMON_LIBS "libwebp")
list(APPEND COMMON_LIBS "libjasper")
list(APPEND COMMON_LIBS "libpng")
list(APPEND COMMON_LIBS "IlmImf")
list(APPEND COMMON_LIBS "ittnotify")
list(APPEND COMMON_LIBS "libprotobuf")

# Список Dlib библиотек
set(DLIB_ROOT          ${THIRDPARTY_ROOT}/dlib)
set(DLIB_INCLUDES_PATH ${DLIB_ROOT}/include)
set(DLIB_LIBS_PATH     ${DLIB_ROOT}/lib)

set(DLIB_LIBS)
list(APPEND DLIB_LIBS "dlib")

# Список OpenCV библиотек
set(OPENCV_ROOT          ${THIRDPARTY_ROOT}/opencv)
set(OPENCV_INCLUDES_PATH ${OPENCV_ROOT}/include)
set(OPENCV_LIBS_PATH     ${OPENCV_ROOT}/lib)

set(OPENCV_LIBS)
list(APPEND OPENCV_LIBS "opencv_core330")
list(APPEND OPENCV_LIBS "opencv_flann330")
list(APPEND OPENCV_LIBS "opencv_imgproc330")
list(APPEND OPENCV_LIBS "opencv_imgcodecs330")
list(APPEND OPENCV_LIBS "opencv_ml330")
list(APPEND OPENCV_LIBS "opencv_photo330")
list(APPEND OPENCV_LIBS "opencv_calib3d330")
list(APPEND OPENCV_LIBS "opencv_dnn330")
list(APPEND OPENCV_LIBS "opencv_features2d330")
list(APPEND OPENCV_LIBS "opencv_highgui330")
list(APPEND OPENCV_LIBS "opencv_objdetect330")
list(APPEND OPENCV_LIBS "opencv_shape330")
list(APPEND OPENCV_LIBS "opencv_stitching330")
list(APPEND OPENCV_LIBS "opencv_superres330")
list(APPEND OPENCV_LIBS "opencv_video330")
list(APPEND OPENCV_LIBS "opencv_videoio330")
list(APPEND OPENCV_LIBS "opencv_videostab330")