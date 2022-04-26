#ifndef ARDUINO1_H
#define ARDUINO1_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino1
{
public:     //méthodes de la classe Arduino
    Arduino1();
    int connect_arduino1(); // permet de connecter le PC à Arduino
    int close_arduino1(); // permet de femer la connexion
    int write_to_arduino1( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduino1();  //recevoir des données de la carte Arduino
    QSerialPort* getserial1();   // accesseur
    QString getarduino_port_name1();
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;  // contenant les données lues à partir d'Arduino


};
#endif // ARDUINO1_H
