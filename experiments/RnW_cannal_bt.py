#!/usr/bin/env python
# -*- coding: utf-8 -*-
import bluetooth

def connect_to_device(device_address):
    try:
        sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        sock.connect((device_address, 1))
        print("Connected to device")
        return sock
    except bluetooth.btcommon.BluetoothError as e:
        print("Error connecting to device:", e)
        return None

def send_data(sock, data):
    try:
        sock.send(data)
        print("Data sent successfully")
    except bluetooth.btcommon.BluetoothError as e:
        print("Error sending data:", e)



def receive_data(sock, buffer_size=1024):
    try:
        data = sock.recv(buffer_size)
        print("Received data:", data.decode())
    except bluetooth.btcommon.BluetoothError as e:
        print("Error receiving data:", e)

def main():
    # Remplacez 'XX:XX:XX:XX:XX:XX' par l'adresse MAC de votre appareil Bluetooth
    device_address = '98:D3:B1:FE:06:D1'

    sock = connect_to_device(device_address)
    if not sock:
        return

    # Exemple d'envoi de données
    send_data(sock, b'Hello from Python!')

    # Exemple de réception de données
    receive_data(sock)

    # Fermeture de la connexion
    sock.close()

if __name__ == "__main__":
    main()
