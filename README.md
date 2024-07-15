# Robeurt

## Project

Le projet global est de faire une structure de développement pour la préparation à la [Coupe de France de Robotique](https://www.coupederobotique.fr/) en utilisant une vue aierienne du plateau, des communications de control [ROS](https://www.ros.org/) et de l'apprentissage par renforcement.

Pour cela je vais utiliser : 
- Une carte [Nvidia Jetson Nano](https://www.nvidia.com/fr-fr/autonomous-machines/embedded-systems/jetson-nano/product-development/) qui traitera les images en prendra les décision pour le robot, elle servira aussi à la phase d'entraînement de l'IA.
- Une carte arduina pour simuler le robot, dans la plupart des cas les robots sont commandé par des cartes raspberry py mais dans un premier temps j'utiliserai une carte arduino avec une connection bluetooth.

## Le développement

Pendant la phase de développement je vais utiliser en plus un ordinateur portable sous Linux pour me connecter par SSH à la carte Jetson Nano.

La Jetson Nano utilise un OS Nvidia basé sur Ubuntu 18.04, ainsi nous devrons utiliser [ROS Melodic](https://wiki.ros.org/melodic). 

## Setup le bluetooth

```
sudo rfcomm connect hci0 98:D3:B1:FE:06:D1 1
```

- Launch the node by wire (change the port) `rosrun rosserial_python serial_node.py /dev/ttyACM0`

- Launch the node by wireless (change the port) `rosrun rosserial_python serial_node.py _port:=/dev/rfcomm0 _baud:=115200`

[Rosserial tuto](https://wiki.ros.org/rosserial_arduino/Tutorials/Hello%20World)

[Wireless compilation tutorial](https://www.instructables.com/Program-an-Arduino-Wireless-Over-Bluetooth/)

[AT datasheet](https://lastminuteengineers.com/hc05-at-commands-tutorial/#at-addr)

## Build robot URDF

J'ai d'abord [dessiner mon robot sur Onshape](https://cad.onshape.com/documents/5759622d91be2239c6115d4e/w/7e204c6ac7b5b0b0d6e45d1a/e/18a27936fa900e54efb5002d).

Puis j'ai utilier le package [Onshape to robot](https://onshape-to-robot.readthedocs.io/en/latest/index.html) Pour générer le fichier urdf.

![vue du robot par urdf](/image/visu_urdf_2.png)


[Onshape to robot](https://onshape-to-robot.readthedocs.io/en/latest/)