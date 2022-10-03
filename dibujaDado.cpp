#include <iostream>
using namespace std;
#include "rlutil.h"
#include "dibujaDado.h"

//CONSTANTES
const int POS_X_DADO = 17;
const int POS_Y_DADO = 19;


void dado1(int seleccionado, int x, int y){
    int dadoSeleccionado = x;   // Variable temporal para no perder el nro. del dado
    if (x > 6){ // Comparo con mayor de 6 ya que si son mas dados stock, tengo que realizar un enter para mostrarlos y pasar a la siguiente fila.
        x = (x - 6) * POS_X_DADO; // Posiciono eje x debajo de la primera linea de 6 dados.
        y += 10; // Posiciono eje y debajo de la primera linea de 6 dados.
    } else x *= POS_X_DADO; // Posiciono eje x de acuerdo al dado que sea, si el primero va primero en la fila, si es el segundo tiene que ubicarse luego del primero y asi...

    rlutil::locate(x,y++);
    if (seleccionado == 1) rlutil::setColor(rlutil::LIGHTRED);
    else rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "  Dado " << dadoSeleccionado << ": 1"<< endl;
    rlutil::locate(x,y++);
    cout << " ___________" << endl;
    rlutil::locate(x,y++);
    cout << "|           |"<< endl;
    rlutil::locate(x,y++);
    cout << "|     #     |"<< endl;
    rlutil::locate(x,y++);
    cout << "|           |"<< endl;
    rlutil::locate(x,y++);
    cout << "|___________|"<< endl;
    rlutil::setColor(rlutil::WHITE);

}

void dado2(int seleccionado, int x, int y){
    int dadoSeleccionado = x;   // Variable temporal para no perder el nro. del dado
    if (x > 6){ // Comparo con mayor de 6 ya que si son mas dados stock, tengo que realizar un enter para mostrarlos y pasar a la siguiente fila.
        x = (x - 6) * POS_X_DADO; // Posiciono eje x debajo de la primera linea de 6 dados.
        y += 10; // Posiciono eje y debajo de la primera linea de 6 dados.
    } else x *= POS_X_DADO; // Posiciono eje x de acuerdo al dado que sea, si el primero va primero en la fila, si es el segundo tiene que ubicarse luego del primero y asi...

    rlutil::locate(x,y++);
    if (seleccionado == 1) rlutil::setColor(rlutil::LIGHTRED);
    else rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "  Dado " << dadoSeleccionado << ": 2";
    rlutil::locate(x,y++);
    cout << " ___________" << endl;
    rlutil::locate(x,y++);
    cout << "|        #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|           |"<< endl;
    rlutil::locate(x,y++);
    cout << "|  #        |"<< endl;
    rlutil::locate(x,y++);
    cout << "|___________|"<< endl;
    rlutil::setColor(rlutil::WHITE);

}

void dado3(int seleccionado,  int x, int y){
    int dadoSeleccionado = x;   // Variable temporal para no perder el nro. del dado
    if (x > 6){ // Comparo con mayor de 6 ya que si son mas dados stock, tengo que realizar un enter para mostrarlos y pasar a la siguiente fila.
        x = (x - 6) * POS_X_DADO; // Posiciono eje x debajo de la primera linea de 6 dados.
        y += 10; // Posiciono eje y debajo de la primera linea de 6 dados.
    } else x *= POS_X_DADO; // Posiciono eje x de acuerdo al dado que sea, si el primero va primero en la fila, si es el segundo tiene que ubicarse luego del primero y asi...

    rlutil::locate(x,y++);
    if (seleccionado == 1) rlutil::setColor(rlutil::LIGHTRED);
    else rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "  Dado " << dadoSeleccionado << ": 3";
    rlutil::locate(x,y++);
    cout << " ___________" << endl;
    rlutil::locate(x,y++);
    cout << "|        #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|     #     |"<< endl;
    rlutil::locate(x,y++);
    cout << "|  #        |"<< endl;
    rlutil::locate(x,y++);
    cout << "|___________|"<< endl;
    rlutil::setColor(rlutil::WHITE);

}

void dado4(int seleccionado, int x, int y){
    int dadoSeleccionado = x;   // Variable temporal para no perder el nro. del dado
    if (x > 6){ // Comparo con mayor de 6 ya que si son mas dados stock, tengo que realizar un enter para mostrarlos y pasar a la siguiente fila.
        x = (x - 6) * POS_X_DADO; // Posiciono eje x debajo de la primera linea de 6 dados.
        y += 10; // Posiciono eje y debajo de la primera linea de 6 dados.
    } else x *= POS_X_DADO; // Posiciono eje x de acuerdo al dado que sea, si el primero va primero en la fila, si es el segundo tiene que ubicarse luego del primero y asi...

    rlutil::locate(x,y++);
    if (seleccionado == 1) rlutil::setColor(rlutil::LIGHTRED);
    else rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "  Dado " << dadoSeleccionado << ": 4";
    rlutil::locate(x,y++);
    cout << " ___________" << endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|           |"<< endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|___________|"<< endl;
    rlutil::setColor(rlutil::WHITE);

}

void dado5(int seleccionado, int x, int y){
    int dadoSeleccionado = x;   // Variable temporal para no perder el nro. del dado
    if (x > 6){ // Comparo con mayor de 6 ya que si son mas dados stock, tengo que realizar un enter para mostrarlos y pasar a la siguiente fila.
        x = (x - 6) * POS_X_DADO; // Posiciono eje x debajo de la primera linea de 6 dados.
        y += 10; // Posiciono eje y debajo de la primera linea de 6 dados.
    } else x *= POS_X_DADO; // Posiciono eje x de acuerdo al dado que sea, si el primero va primero en la fila, si es el segundo tiene que ubicarse luego del primero y asi...

    rlutil::locate(x,y++);
    if (seleccionado == 1) rlutil::setColor(rlutil::LIGHTRED);
    else rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "  Dado " << dadoSeleccionado << ": 5";
    rlutil::locate(x,y++);
    cout << " ___________" << endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|     #     |"<< endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|___________|"<< endl;
    rlutil::setColor(rlutil::WHITE);

}

void dado6(int seleccionado, int x, int y){
    int dadoSeleccionado = x;   // Variable temporal para no perder el nro. del dado
    if (x > 6){ // Comparo con mayor de 6 ya que si son mas dados stock, tengo que realizar un enter para mostrarlos y pasar a la siguiente fila.
        x = (x - 6) * POS_X_DADO; // Posiciono eje x debajo de la primera linea de 6 dados.
        y += 10; // Posiciono eje y debajo de la primera linea de 6 dados.
    } else x *= POS_X_DADO; // Posiciono eje x de acuerdo al dado que sea, si el primero va primero en la fila, si es el segundo tiene que ubicarse luego del primero y asi...

    rlutil::locate(x,y++);
    if (seleccionado == 1) rlutil::setColor(rlutil::LIGHTRED);
    else rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "  Dado " << dadoSeleccionado << ": 6";
    rlutil::locate(x,y++);
    cout << " ___________" << endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|  #     #  |"<< endl;
    rlutil::locate(x,y++);
    cout << "|___________|"<< endl;
    rlutil::setColor(rlutil::WHITE);

}

void DibujaDado(int dado,int seleccionado, int x, int y)
{
    switch (dado)
        {
        case 1:
            dado1(seleccionado, x, y);
            break;
        case 2:
            dado2(seleccionado, x, y);
            break;
        case 3:
            dado3(seleccionado, x, y);
            break;
        case 4:
            dado4(seleccionado, x, y);
            break;
        case 5:
            dado5(seleccionado, x, y);
            break;
        case 6:
            dado6(seleccionado, x, y);
            break;
        }
}
