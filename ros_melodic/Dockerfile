# Use Ubuntu 18.04 as the base image
FROM ubuntu:18.04

# Set non-interactive mode
ENV DEBIAN_FRONTEND noninteractive

# Set the locale
ENV LANG C.UTF-8

# Install necessary packages
RUN apt-get update && apt-get install -y \
    gnupg2 \
    lsb-release \
    sudo \
    terminator \
    x11-apps \
    arduino

# Add ROS Melodic apt repository
RUN apt-get update && apt-get install -y \
    wget \
    && rm -rf /var/lib/apt/lists/*
RUN wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc
RUN apt-key add ros.asc
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu bionic main" > /etc/apt/sources.list.d/ros-latest.list'

# Install ROS Melodic Desktop Full and rosdep
RUN apt-get update && apt-get install -y \
    ros-melodic-desktop-full \
    ros-melodic-rosserial \
    ros-melodic-rosserial-arduino \
    python-rosdep\
    python-catkin-tools \
    ros-melodic-catkin

# Initialize rosdep
RUN rosdep init
RUN rosdep update

# Set up ROS environment variables
ENV ROS_DISTRO melodic
ENV ROS_ROOT /opt/ros/$ROS_DISTRO
ENV PATH $ROS_ROOT/bin:$PATH
ENV LD_LIBRARY_PATH /opt/ros/$ROS_DISTRO/lib

# Create a new user
ARG USER_NAME=cosserat
ARG USER_UID=1000
ARG USER_GID=1000
RUN groupadd --gid ${USER_GID} ${USER_NAME} \
    && useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USER_NAME} -d /home/ubuntu \
    && usermod -a -G video,dialout ${USER_NAME} \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USER_NAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USER_NAME \
    && chmod 0440 /etc/sudoers.d/$USER_NAME


# Switch to the new user
USER $USER_NAME

# Set up the workspace
RUN mkdir -p /home/ubuntu/catkin_ws/src
WORKDIR /home/ubuntu/catkin_ws/
RUN . /opt/ros/melodic/setup.sh && catkin_make 

WORKDIR /home/ubuntu/catkin_ws/

# Set up entrypoint to launch terminator
ENTRYPOINT ["bash", "-c", ". /home/ubuntu/catkin_ws/entrypoint.sh"]
