# Install script for directory: /home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/yashwant/y_ws/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/msg" TYPE FILE FILES
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Accel.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/AccelStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/AccelWithCovariance.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/AccelWithCovarianceStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Inertia.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/InertiaStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Point.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Point32.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/PointStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Polygon.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/PolygonStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Pose2D.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Pose.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/PoseArray.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/PoseStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/PoseWithCovariance.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/PoseWithCovarianceStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Quaternion.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/QuaternionStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Transform.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/TransformStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Twist.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/TwistStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/TwistWithCovariance.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/TwistWithCovarianceStamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Vector3.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Vector3Stamped.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/Wrench.msg"
    "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/msg/WrenchStamped.msg"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/cmake" TYPE FILE FILES "/home/yashwant/y_ws/build/common_msgs-jade-devel/geometry_msgs/catkin_generated/installspace/geometry_msgs-msg-paths.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/yashwant/y_ws/devel/include/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/yashwant/y_ws/devel/share/common-lisp/ros/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/yashwant/y_ws/devel/lib/python2.7/dist-packages/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/yashwant/y_ws/devel/lib/python2.7/dist-packages/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/yashwant/y_ws/build/common_msgs-jade-devel/geometry_msgs/catkin_generated/installspace/geometry_msgs.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/cmake" TYPE FILE FILES "/home/yashwant/y_ws/build/common_msgs-jade-devel/geometry_msgs/catkin_generated/installspace/geometry_msgs-msg-extras.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/cmake" TYPE FILE FILES
    "/home/yashwant/y_ws/build/common_msgs-jade-devel/geometry_msgs/catkin_generated/installspace/geometry_msgsConfig.cmake"
    "/home/yashwant/y_ws/build/common_msgs-jade-devel/geometry_msgs/catkin_generated/installspace/geometry_msgsConfig-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs" TYPE FILE FILES "/home/yashwant/y_ws/src/common_msgs-jade-devel/geometry_msgs/package.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

