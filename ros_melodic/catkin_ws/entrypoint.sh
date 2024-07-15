#!/bin/bash

# Lancer Arduino
arduino &

# Attendre un certain temps pour que l'utilisateur ait le temps de travailler avec Arduino
sleep 1

# Récupérer le PID du processus Arduino
arduino_pid=$(pidof java)

# Terminer le processus Arduino
kill $arduino_pid

# Naviguer vers le répertoire de travail
cd ~/catkin_ws

# Construire le projet catkin
catkin_make
catkin_make install
source /home/ubuntu/catkin_ws/devel/setup.bash

# Naviguer vers le répertoire des bibliothèques Arduino
cd /home/ubuntu/sketchbook/libraries

# Supprimer le dossier ros_lib s'il existe déjà
rm -rf ros_lib

# Générer les bibliothèques ROS pour Arduino
rosrun rosserial_arduino make_libraries.py .

# Naviguer vers le répertoire de travail
cd ~/catkin_ws

# Lancer terminator avec bash
terminator -ux bash
