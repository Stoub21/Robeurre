# Utiliser l'image de base OSRF ROS humble-desktop
FROM osrf/ros:humble-desktop

# Installer les outils nécessaires
RUN apt-get update && apt-get install -y \
    x11-apps

COPY bashrc_custom /root/.bashrc

# Commande par défaut à exécuter lors du démarrage du conteneur
CMD ["bash"]

# Commandes à exécuter lors de la construction de l'image
RUN cd ~ \
    sudo apt install -y ros-humble-joy &&\
    mkdir -p ros2_ws/src/ && \
    cd ros2_ws/src/ && \
    git clone https://github.com/Ar-Ray-code/ps_ros2_common.git && \
    cd ~/ros2_ws/