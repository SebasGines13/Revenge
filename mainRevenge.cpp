#include <iostream>
using namespace std;
#include <stdlib.h>
#include <locale.h>
#include <ctime>
#include "rlutil.h"
#include "dibujaDado.h"


//CONSTANTES
const int JUGADORES=2;
const int INICIO=1;
const int FIN=6;
const int RONDAS = 5;
const int INI_OBJETIVO = 1;
const int FIN_OBJETIVO = 12;
const int POS_X_DADO = 17;
const int POS_Y_DADO = 19;


//CABECERA DE FUNCIONES
int Menu();
void Presentacion();
void Estadisticas (int PuntajeMax, string NombreMax);
void Creditos();
void Salir(int &confirm);
void Reglas();
void OpcionIncorrecta();
void Jugar(int &PuntajeMax,string &NombreMax);
void PedirNombres(string &jugador1,string &jugador2);
void JugadorInicial(string &jugador1,string &jugador2);
int numeroAleatorio(int inicio, int fin);
void SumSeleccionada(int (*)[4], int jugador, int ronda, string &jugador1, string &jugador2);
bool es_tirada_exitosa(int N1, int N2);
void Puntaje(int (*)[4], int turno, bool &ganador, string &jugador1, string &jugador2);


//FUNCION PRINCIPAL
int main(){
    setlocale(LC_CTYPE, "Spanish");
    srand(time(NULL));
    int PuntajeMax=0;
    string NombreMax={};
    int opcion;
    Presentacion();

    do {
        opcion = Menu();
        switch (opcion){
            case 0:
                Salir(opcion);
                break;
            case 1:
                Jugar(PuntajeMax, NombreMax);
                break;
            case 2:
                Estadisticas(PuntajeMax, NombreMax);
                break;
            case 3:
                Creditos();
                break;
            case 4:
                Reglas();
                break;
            default:
                OpcionIncorrecta();
                break;
        }
    } while (opcion !=0);

    return 0;
}

//FUNCION PARA EL MENU
int Menu(){
    int op;
    system("cls");
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "\t______  _____  _   _  _____  _   _  _____  _____ " << endl;
    cout << "\t| ___ \\|  ___|| | | ||  ___|| \\ | ||  __ \\|  ___|" << endl;
    cout << "\t| |_/ /| |__  | | | || |__  |  \\| || |  \\/| |__  " << endl;
    cout << "\t|    / |  __| | | | ||  __| | . ` || | __ |  __| " << endl;
    cout << "\t| |\\ \\ | |___ \\ \\_/ /| |___ | |\\  || |_\\ \\| |___ " << endl;
    cout << "\t\\_| \\_|\\____/  \\___/ \\____/ \\_| \\_/ \\____/\\____/" << endl;
    cout << "\n---------------------------------------------------------------" << endl;

    rlutil::setColor(rlutil::WHITE);
    cout << "\n\n\t1 - JUGAR" << endl;
    cout << "\t2 - ESTADISTICAS" << endl;
    cout << "\t3 - CREDITOS" << endl;
    cout << "\t4 - REGLAS DE JUEGO" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "\t0 - SALIR " << endl;
    cin >> op;
    return op;
}

void Presentacion(){
    int i = 1;
    do{
    system("cls");

    switch (i)
    {
    case 1: rlutil::setColor(rlutil::YELLOW);
        break;
    case 2: rlutil::setColor(rlutil::GREEN);
        break;
    case 3: rlutil::setColor(rlutil::BLUE);
        break;
    case 4: rlutil::setColor(rlutil::BROWN);
        break;
    case 5: rlutil::setColor(rlutil::LIGHTRED);
        break;
    case 6: rlutil::setColor(rlutil::RED);
        break;
    case 7: rlutil::setColor(rlutil::LIGHTMAGENTA);
        break;
    case 8: rlutil::setColor(rlutil::LIGHTBLUE);
        break;
    }

    cout << "\n---------------------------------------------------------------" << endl;
    Sleep(20);
    cout << "\t______  _____  _   _  _____  _   _  _____  _____ " << endl;
    Sleep(20);
    cout << "\t| ___ \\|  ___|| | | ||  ___|| \\ | ||  __ \\|  ___|" << endl;
    Sleep(20);
    cout << "\t| |_/ /| |__  | | | || |__  |  \\| || |  \\/| |__  " << endl;
    Sleep(20);
    cout << "\t|    / |  __| | | | ||  __| | . ` || | __ |  __| " << endl;
    Sleep(20);
    cout << "\t| |\\ \\ | |___ \\ \\_/ /| |___ | |\\  || |_\\ \\| |___ " << endl;
    Sleep(20);
    cout << "\t\\_| \\_|\\____/  \\___/ \\____/ \\_| \\_/ \\____/\\____/" << endl;
    Sleep(20);
    cout << "\n---------------------------------------------------------------" << endl;
    Sleep(20);
    i++;
    } while (i <9);
    rlutil::setColor(rlutil::WHITE);
    cout << "\n\n\t\tPresione una tecla para iniciar el juego !!" << endl;
    rlutil::anykey();
}


void  Estadisticas (int PuntajeMax, string NombreMax){
    system("cls");
    if(PuntajeMax==0){
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<<endl<<"------------------------------------------------"<<endl<<endl;
        cout<<"\tNo existe un record registrado al momento"<<endl;
        cout<<endl<<"------------------------------------------------"<<endl;
        rlutil::setColor(rlutil::WHITE);
    }
    else{
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<<endl<<"--------------------------------------------------------------------------"<<endl<<endl;
        cout<<"\tEl record lo tiene "<<NombreMax <<" con "<< PuntajeMax << " puntos." <<endl;
        cout<<endl<<"--------------------------------------------------------------------------"<<endl;
        rlutil::setColor(rlutil::WHITE);
    }
    system("pause");
}
//FUNCION PARA CREDITOS
void Creditos(){
    system("cls");
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "---------------------------------------------------------" << endl;
    cout << "EQUIPO: "<< endl;
    cout << "\tMichingans"<< endl;
    cout << "---------------------------------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "INTEGRANTES: "<< endl;
    cout << "\tCamila Denise Goncalves\t- Legajo: 25504"<< endl;
    cout << "\tJesús Altamirano\t- Legajo: 25412"<< endl;
    cout << "\tJuan Martín Varano\t- Legajo: 25640"<< endl;
    cout << "\tAlan Leonel Caero\t- Legajo: 23970"<< endl;
    cout << "\tSebastián Gines \t- Legajo: 25496"<< endl;
    cout << "---------------------------------------------------------" << endl;
    system("pause");
}

//FUNCION PARA MOSTRAR LAS REGLAS DEL JUEGO

void Reglas(){
    system("cls");
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "REGLAS DEL JUEGO:" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl<< endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "\t1- Revenge es un juego de dados para 2 personas."<< endl<< endl;
    cout << "\t2- Ambos participantes inician la partida con 6 dados de 6 caras cada uno y hay 2 dados de 12 caras que se comparten."<< endl<< endl;
    cout << "\t3- El juego consta de 5 rondas que incluyen una tirada de cada participante (10 tiradas en total)." << endl<< endl;
    cout << "\t4- En cada turno, el jugador que le toque, primero lanza los 2 dados de 12 caras. El resultado de ambos dados se suma" << endl;
    cout << "\t   y eso da como resultado el número objetivo. Luego el jugador lanza los dados de 6 caras y debe intentar sumar" << endl;
    cout << "\t   su numero objetivo con los valores que le hayan tocado en la tirada de dados de 6 caras, seleccionando los que desee." << endl;
    cout << "\t   Ejemplo: Si cuando tira los dados de 12 caras le sale un 10 y un 7, su número objetivo serï¿½an 17. " << endl;
    cout << "\t   Y si en la tirada de dados de 6 caras le sale 6,6,2,1,4,5, puede seleccionar el 6, el 4, el 5 y el 2 para llegar a su número objetivo (17)." << endl<< endl;
    cout << "\t5- En caso de que no haya posibilidad de sumar el número objetivo, el jugador debe presionar un 0 para pasar al siguiente turno."<< endl<< endl;
    cout << "\t6- Si el jugador suma con los dados de 6 caras su número objetivo, se declara tirada exitosa y automáticamente le transfiere "<< endl;
    cout << "\t   a su contrincante la cantidad de dados que haya seleccionado para llegar al número objetivo. "<< endl;
    cout << "\t   Caso contrario NO es tirada exitosa y dicho jugador recibe un dado de su contrincante (siempre y cuando su contrincante "<< endl;
    cout << "\t   tenga mas de 1 dado en poseción) "<< endl<< endl;
    cout << "\t7- El jugador solo obtiene puntaje si tiene una tirada exitosa. El mismo se calcula de la siguiente manera: número objetivo x cantidad de dados seleccionados."<< endl<< endl;
    cout << "\t8- Si el jugador tiene tiene una tirada exitosa utilizando todos los dados de 6 caras que haya tirado, automáticamente"<< endl;
    cout << "\t   se le suman 10.000 puntos y gana el juego (no continuan las rondas pendientes, si es que las hay)."<< endl<< endl;
    cout << "\t9- El juego lo gana quien al final de las 5 rondas tiene la mayor cantidad de puntos o el jugador que se quede sin dados. "<< endl<< endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "CREDITOS" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl<< endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "\t- Juego inventado por Angel Simón. Levemente inspirado en el juego Mafia y probablemente en otros juegos." << endl << endl;
    system("pause");
}

//FUNCION PARA SALIR
void Salir(int &confirm){
    system("cls");
    cout << "\n\t\t¿Está seguro que desea salir?" << endl << endl; // Confirmaciï¿½n para salir
    cout << "Para salir del juego presione: 0 \t\t Para cancelar presione: 1" << endl; // 0 para confirmar y 1 para regresar al menu.
    cin >> confirm;
    if(confirm==0) {
        cout << "\n\n\tGracias por jugar conmigo :)" << endl;
    } else confirm = 1;
}

//FUNCION PARA VALIDAR EL INGRESO DE OPCION CORRECTA EN EL MENU
void OpcionIncorrecta(){

    cout << "\n\nIngrese una opción válida..." << endl;
    system("pause");
}


void Jugar(int &PuntajeMax,string &NombreMax ){
    bool ganador = false;
    int ronda=1, turno;
    int mJugador[JUGADORES][4] = {0};
    string NombreGanador;
    int PuntajeGanador;
    string jugador1;
    string jugador2;

     // MATRIZ CON INFORMACION DE JUGADORES
    /*
    MATRIZ CON INFORMACION DE LOS JUGADORES
    Posicion 0: numObjetivo
    Posicion 1: sumaSeleccionada
    Posicion 2: dadosStock
    Posicion 3: puntaje
    Posicion 4: cantDadosElegidos
    */

    //Inicializo en 6 los dados stocks de los jugadores.
    for (int i = 0; i < JUGADORES; i++){
        mJugador[i][2] = 6;
    }


    //Pido nombres de los jugadores y lo guardo en el vector de nombres de jugadores.
    PedirNombres(jugador1, jugador2);

    //Determino el orden de los jugadores usando para ello la posición del vector. Posición 0 es el jugador 1 y posicion 1 es el jugador 2.
    JugadorInicial(jugador1, jugador2);
    for (int i = 0; i < JUGADORES; i++){
        mJugador[i][2] = 6;
    }

    do
    {
        turno=0;
        do
        {
            SumSeleccionada(mJugador, turno, ronda, jugador1, jugador2); // Función encargada de mostrar los dados y gran parte del juego en 1 turno
            Puntaje(mJugador, turno, ganador, jugador1, jugador2); // Función que calcula los puntajes de acuerdo a lo jugado y chequea si existe un ganador ese turno.
            turno ++; // Incremento el turno para que juegue el siguiente jugador.
        } while (!ganador && turno < JUGADORES); // Mientras no exista un ganador, se sigue jugando
        ronda ++; //Incremento la ronda

    } while (!ganador && ronda <= RONDAS); // Ejecuto hasta que se acaben las rondas o exista un ganador


    // Calculo quien es el ganador
    if (mJugador[0][3] > mJugador[1][3]) // Si el puntaje del jugador 1 es mayor al del jugador 2
    {
        if (ganador) {
            rlutil::setColor(rlutil::LIGHTGREEN); // Mensaje especial en caso de que haya ganado por quedarse sin dados
            cout << "\nFELICITACIONES!!" << endl;
            cout << "\nEl juego ha terminado ya que " << jugador1 << " se quedó sin dados y ganó con " << mJugador[0][3] << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        else {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\nFELICITACIONES!!" << endl;
            cout << "\nEl ganador es " << jugador1 << " con " << mJugador[0][3] << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        PuntajeGanador=mJugador[0][3];
        NombreGanador=jugador1;
    }   else if (mJugador[0][3] < mJugador[1][3]){ // Sino gano el jugador 2
        if (ganador) {
            rlutil::setColor(rlutil::LIGHTGREEN); // Mensaje especial en caso de que haya ganado por quedarse sin dados
            cout << "\nFELICITACIONES!!" << endl;
            cout << "\nEl juego ha terminado ya que "<< jugador2 << " se quedó sin dados, por lo tanto ganó con " << mJugador[1][3] << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        else {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\nFELICITACIONES!!" << endl;
            cout << "\nEl ganador es " << jugador2 << " con " << mJugador[1][3] << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        PuntajeGanador=mJugador[1][3];
        NombreGanador=jugador2;
    }else {
        rlutil::setColor(rlutil::YELLOW);
        cout << "\nHubo un empate con " << mJugador[0][3] << " puntos :( " << endl; // Sino fue empate!
        cout << "\t¿Revancha?" << endl << endl; // Sino fue empate!
        rlutil::setColor(rlutil::WHITE);
    }
    system("pause");

    if (PuntajeGanador>PuntajeMax){  //Funcion para actualizar estadísticas según el puntaje del ganador
        PuntajeMax=PuntajeGanador;
        NombreMax=NombreGanador;
    }

}



//FUNCION PARA PEDIR NOMBRES
void PedirNombres(string &jugador1,string &jugador2){

    system("cls");
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "---------------------------------------------------------" << endl;
    cout << "JUGADORES: "<< endl;
    cout << "---------------------------------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "\tIngrese el nombre del jugador nro 1: ";
    cin >> jugador1;
    cout << "\tIngrese el nombre del jugador nro 2: ";
    cin >> jugador2;
    cout << endl;
    system("pause");
}


//FUNCION PARA DETERMINAR EL JUGADOR INICIAL
void JugadorInicial(string &jugador1, string &jugador2){
    int tirada1, tirada2;
    bool NTirada=false;
    string aux;

    system("cls");
    do{
        if(NTirada==false){ // Bandera que valida la primera tirada de dados para decidir el jugador inicial. Es para evitar que se repita la cabecera.
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "CADA JUGADOR LANZARA 1 DADO DE 6 CARAS PARA DETERMINAR EL JUGADOR INICIAL "<< endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        rlutil::setColor(rlutil::WHITE);
        tirada1 = numeroAleatorio(INICIO,FIN); // Función que arroja un número aleatorio entre 1 y 6
        cout << "\t"<< jugador1 << " lanza su dado y obtiene un " << tirada1 << endl;
        tirada2 = numeroAleatorio(INICIO,FIN); // Función que arroja un número aleatorio entre 1 y 6
        cout << "\t"<< jugador2 << " lanza su dado y obtiene un " << tirada2 << endl;
        NTirada=true;
        }
        if( tirada1==tirada2){ // En caso de que lancen el mismo número, se repite la tirada
            rlutil::setColor(rlutil::LIGHTBLUE);
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "\tEMPATE!" << endl;
            cout << "\tSE REPITE LA TIRADA" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            rlutil::setColor(rlutil::WHITE);
            tirada1 = numeroAleatorio(INICIO,FIN);
            cout << "\t"<< jugador1 << " lanza su dado y obtiene un " << tirada1 << endl;
            tirada2 = numeroAleatorio(INICIO,FIN);
            cout << "\t"<< jugador2 << " lanza su dado y obtiene un " << tirada2 << endl;
        }
    } while (tirada1 == tirada2); // Se repiten las tiradas mientras que los número seran iguales.

    cout << "\n-----------------------------------------------------------------------------\n\n";

    if (tirada2 > tirada1) // En caso de que la tirada del jugador 2 sea mayor a la del jugador 1, los cambio de posiciï¿½n para que el jugador 2 ahora sea el primero en jugar.
        {
            aux = jugador1;
            jugador1 = jugador2;
            jugador2 = aux;
        }
    cout << "\tEl jugador inicial es " << jugador1 << endl << endl; // Muestro cual es el jugador inicial.
    system("pause");


}


int numeroAleatorio(int inicio, int fin)
{
    return rand() % (fin - inicio + 1) + inicio; // Función para calcular un numero aleatorio.
}


bool es_tirada_exitosa(int N1, int N2){ // Función para evaluar si la sumaObjetivo es igual a la suma de los valores de los dados seleccionados.
    return N1==N2;
}


void SumSeleccionada(int (*M)[4], int jugador, int ronda, string &jugador1, string &jugador2){
    int mDados[M[jugador][2]][2] = {0}; // Matriz de dados, donde la primera posicion guarda el valor del dado y la segunda si fue seleccionado o no.
    int i, y=0, dadoSeleccionado=1;
    int AcuPuntos=0,dado;


    M[jugador][4] = 0; //Inicializo la cantDadosElegidos del jugador.
    M[jugador][0] = 0; //Inicializo el numero Objetivo del jugador.
    system("cls");

    // INICIO CABECERA
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "-------------------------------------------------------------------------------------------------------------------"<< endl;
    cout << "\tRonda: " << ronda;
    if (jugador == 0) cout << "\t\t\t\t\t\t\t\t\tTurno de: " << jugador1 << endl;
    else cout << "\t\t\t\t\t\t\t\t\tTurno de: " << jugador2 << endl ;
    cout << "-------------------------------------------------------------------------------------------------------------------"<< endl;
    cout << "\t\tJugador 1: " << jugador1 <<" ------->"<< "\tPuntaje: "<< M[0][3];
    rlutil::locate(65,4);
    cout << "\t\tDados Stock: "<< M[0][2] << endl;
    cout << "\t\tJugador 2: " << jugador2 <<" ------->"<< "\tPuntaje: "<< M[1][3];
    rlutil::locate(65,5);
    cout << "\t\tDados Stock: "<< M[1][2] << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------"<< endl << endl;
    rlutil::setColor(rlutil::WHITE);
    // FIN CABECERA


    cout << "Se lanzan los 2 dados de 12 caras... " << endl << endl;
    for(i=1;i<=2;i++){                      //FOR PARA MOSTRAR AMBOS NUMEROS DE 12 CARAS Y LUEGO EL NUMERO OBJETIVO
       dado= numeroAleatorio(INI_OBJETIVO,FIN_OBJETIVO);
       cout<<"\t Dado "<<i<<": "<<dado << " \t";
       M[jugador][0]+=dado;
    }
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout <<endl<<"\t\tNUMERO OBJETIVO: "<<M[jugador][0]<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "-------------------------------------------------------------------------------------------------------------------"<< endl<< endl;
    cout << "Se van a lanzar " << M[jugador][2] << " dados... ";
    cout << "\t\t\tReferencias del color del dado: ";
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << " Disponible";
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "\tSeleccionado" << endl << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "-------------------------------------------------------------------------------------------------------------------"<< endl;
    for ( i = 0; i < M[jugador][2]; i++) // Ciclo lanzando dados de acuerdo a la cantidad de dados stock
    {
        mDados[i][0] = numeroAleatorio(INICIO, FIN); // Asigno tirada de dados en la matriz de dados
        DibujaDado(mDados[i][0], 0, i+1, POS_Y_DADO); // Función para dibujar el dado, se le pasa como primer parametro el numero del dado, el estado de seleccionado o no y luego la posicion x e y.
    };

    rlutil::locate(POS_X_DADO, (y++) + POS_X_DADO + POS_Y_DADO);

    while (AcuPuntos != M[jugador][0] && dadoSeleccionado!=0)
    {
        cout << " * Ingrese el dado seleccionado ('0' para finalizar el turno): ";
        cin >> dadoSeleccionado;

        if (dadoSeleccionado <= M[jugador][2] && dadoSeleccionado > 0){ // Solicito dados hasta que se ingrese un 0 y valido que el dado seleccionado no sea mayor a los stock.
            if (mDados[dadoSeleccionado-1][1]==0)
            {
                mDados[dadoSeleccionado-1][1] = 1;
                M[jugador][4] ++;
                AcuPuntos+=mDados[dadoSeleccionado-1][0]; //Acumulo los valores de dados seleccionados
                rlutil::setColor(rlutil::LIGHTBLUE);
                cout << "\tSuma " << mDados[dadoSeleccionado-1][0] << " ------> Acumula: " << AcuPuntos;
                rlutil::setColor(rlutil::WHITE);
                DibujaDado(mDados[dadoSeleccionado-1][0], 1, dadoSeleccionado, POS_Y_DADO);
                rlutil::locate(POS_X_DADO+25, (y++) + POS_X_DADO + POS_Y_DADO); // Me coloco para poner en la misma linea que lo acumulado.
                if(M[jugador][0] - AcuPuntos < 0){
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << "\tSE PASO DEL NUMERO OBJETIVO" << endl; // si se paso del número objetivo, se informa y sale.
                    rlutil::setColor(rlutil::WHITE);
                    dadoSeleccionado=0;
                }
                else{
                        if (M[jugador][0] - AcuPuntos != 0) // Es para que no muestre Le falta 0 para llegar al objetivo
                        {
                        rlutil::setColor(rlutil::LIGHTCYAN);
                            cout << "\t\tLe falta " << M[jugador][0] - AcuPuntos << " para llegar al objetivo. " << endl;
                            rlutil::setColor(rlutil::WHITE);
                            y++; //Para dar un salto más de linea
                            rlutil::locate(POS_X_DADO, (y++) + POS_X_DADO + POS_Y_DADO);
                        }
                    }

            } else {
                    rlutil::locate(POS_X_DADO, (y++) + POS_X_DADO + POS_Y_DADO);
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << "\tEl dado " << mDados[dadoSeleccionado-1][0] << " ya ha sido seleccionado..." << endl;
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(POS_X_DADO, (y++) + POS_X_DADO + POS_Y_DADO);
                    }
        } else {
            if (dadoSeleccionado!=0) {
            rlutil::locate(POS_X_DADO, (y++) + POS_X_DADO + POS_Y_DADO);
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\tIngrese un dado válido..." << endl;
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(POS_X_DADO, (y++) + POS_X_DADO + POS_Y_DADO);
            }
        }
    }
    cout << endl <<"---------------------------------------------------------------------------------------------------------------"<< endl;
    if (dadoSeleccionado==0) // Si salio del ciclo con 0, no fue tirada exitosa
    {
        cout << endl << "La tirada no ha sido exitosa ------> ";
    } else {
        cout << endl << "La tirada ha sido exitosa ------> " ;
        M[jugador][1] = AcuPuntos; // Acumulo los valores de los dados logrados en la matriz de jugador (SumSeleccionada)
    }
}


void Puntaje(int (*M)[4], int jugador, bool &ganador, string &jugador1, string &jugador2){
    if (es_tirada_exitosa(M[jugador][0],M[jugador][1])) //Si es tirada exitosa
    {
        M[jugador][3] += M[jugador][1] * M[jugador][4]; //Calculo el puntaje: sumaSeleccionada * cantDadosElegidos
        M[jugador][2] -= M[jugador][4]; //Resto a los dados stock los cantDadosElegidos

        if (jugador==0) //Si es el jugador 1, le sumo los cantDadosElegidos al jugador 2
        {
            M[jugador+1][2] += M[jugador][4];
            cout << jugador1 << " este turno acumula "<< M[jugador][1] * M[jugador][4] << " puntos, resta " << M[jugador][4] << " dados y se los pasa a " << jugador2 << endl << endl;
        } else {
            M[jugador-1][2] += M[jugador][4]; //Si es el jugador 2, le sumo los cantDadosElegidos al jugador 1
            cout << jugador2 << " este turno acumula "<< M[jugador][1] * M[jugador][4] << " puntos, resta " << M[jugador][4] << " dados y se los pasa a " << jugador1 << endl << endl;
        }

        if (M[jugador][2]==0) //Si se quedo sin dados es el ganador
        {
            M[jugador][3] += 10000;
            ganador=true;
        }
    }else {
        if (jugador==0) // Si no es tirada exitosa y es el turno del jugador 1
        {
            if (M[jugador+1][2] > 1) // Se valida que los datosStock del jugador 2 sean menor que 1
            {
                M[jugador][2] ++; // Le sumo un dado al jugador 1
                M[jugador+1][2] --; // Le resto un dado al jugador 2
                cout << jugador1 << " suma 1 dado y se le resta a " << jugador2 << endl << endl;
            } else cout << jugador1 << " no suma dados ya que " << jugador2 << " tiene 1 solo dado" <<  endl << endl;
        }else { // Entonces es el turno del jugador 2
            if (M[jugador-1][2] > 1) // Se valida que los datosStock del jugador 1 sean menor que 1
            {
                M[jugador][2] ++; // Le sumo un dado al jugador 2
                M[jugador-1][2] --; // Le resto un dado al jugador 1
                cout << jugador2 << " suma 1 dado y se le resta a " << jugador1 << endl << endl;
            } else cout << jugador2 << " no suma dados ya que " << jugador1 << " tiene 1 solo dado" <<  endl << endl;
        }
    }
    system("pause");
}


