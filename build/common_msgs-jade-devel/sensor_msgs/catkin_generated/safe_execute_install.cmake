execute_process(COMMAND "/home/yashwant/y_ws/build/common_msgs-jade-devel/sensor_msgs/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/yashwant/y_ws/build/common_msgs-jade-devel/sensor_msgs/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
