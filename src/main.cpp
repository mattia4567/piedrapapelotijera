/*
   ====================================================================
   Materia: Laboratorio de Programación (LPR) — 5.º Año
   Institución: E.E.S.T. N.º 1 "Eduardo Ader" — Vicente López
   Archivo: src/main.cpp
   Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
   ====================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Estructura que agrupa los datos de una partida.
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones.
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();
string nombreEleccion(int opcion);
int obtenerSiguienteID();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int contadorID = obtenerSiguienteID();
    int opcion = 0;

    cout << "=====================================================\n";
    cout << " LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA\n";
    cout << " Estudiante: Federico Mattia \n";
    cout << "=====================================================\n";

    do {
        cout << "\n--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---\n";
        cout << "1. Jugar partida (Piedra, Papel o Tijera)\n";
        cout << "2. Ver historial de partidas guardadas en disco (.txt)\n";
        cout << "3. Salir del sistema\n";
        cout << "Ingrese una opcion (1-3): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\\n');
            cout << "\n[ERROR] Debe ingresar un numero.\n";
            opcion = 0;
            continue;
        }

        if (opcion == 1) {
            jugarPartida(contadorID);
        } else if (opcion == 2) {
            leerHistorialDisco();
        } else if (opcion == 3) {
            cout << "\n[SISTEMA] Saliendo... Las partidas guardadas permanecen en disco.\n";
        } else {
            cout << "\n[ERROR] Opcion invalida. Reintente.\n";
        }
    } while (opcion != 3);

    return 0;
}

string nombreEleccion(int opcion) {
    if (opcion == 1) return "Piedra";
    if (opcion == 2) return "Papel";
    if (opcion == 3) return "Tijera";
    return "";
}

// Busca el último ID registrado para evitar repetir IDs al volver a abrir el programa.
int obtenerSiguienteID() {
    ifstream archivo("src/historial_partidas.txt");
    string idStr, jugador, elJug, elIA, resultado;
    int mayorID = 0;

    if (!archivo.is_open()) {
        return 1; // Todavía no existe el historial.
    }

    while (getline(archivo, idStr, ',') &&
           getline(archivo, jugador, ',') &&
           getline(archivo, elJug, ',') &&
           getline(archivo, elIA, ',') &&
           getline(archivo, resultado)) {
        try {
            int id = stoi(idStr);
            if (id > mayorID) mayorID = id;
        } catch (...) {
            // Ignora una línea cuyo ID no sea numérico.
        }
    }

    archivo.close();
    return mayorID + 1;
}

void jugarPartida(int& contadorID) {
    Partida p;
    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---\n";
    cout << "Ingrese su nombre / nickname: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\\n');
    getline(cin, p.jugador);

    if (p.jugador.empty()) {
        p.jugador = "Jugador";
    }

    int opcJugador = 0;
    do {
        cout << "\nElija su jugada:\n";
        cout << "1. Piedra\n";
        cout << "2. Papel\n";
        cout << "3. Tijera\n";
        cout << "Opcion (1-3): ";

        if (!(cin >> opcJugador)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\\n');
            opcJugador = 0;
        }

        if (opcJugador < 1 || opcJugador > 3) {
            cout << "[ERROR] Ingrese 1, 2 o 3.\n";
        }
    } while (opcJugador < 1 || opcJugador > 3);

    p.eleccionJugador = nombreEleccion(opcJugador);

    int opcIA = (rand() % 3) + 1;
    p.eleccionIA = nombreEleccion(opcIA);

    cout << "\n[JUGADA] " << p.jugador << " eligio: " << p.eleccionJugador << "\n";
    cout << "[JUGADA] La IA eligio: " << p.eleccionIA << "\n";

    if (p.eleccionJugador == p.eleccionIA) {
        p.resultado = "Empate";
    } else if ((p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
               (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
               (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel")) {
        p.resultado = "Victoria";
    } else {
        p.resultado = "Derrota";
    }

    cout << "=> RESULTADO: " << p.resultado << "!\n";
    guardarEnDisco(p);
}

void guardarEnDisco(const Partida& p) {
    // ios::app agrega la partida al final sin borrar los registros anteriores.
    ofstream archivo("src/historial_partidas.txt", ios::app);

    if (!archivo.is_open()) {
        cerr << "[ERROR] No se pudo abrir src/historial_partidas.txt para guardar.\n";
        cerr << "Ejecute el programa desde la carpeta raiz del proyecto.\n";
        return;
    }

    // Formato CSV simple: ID,nombre,eleccion jugador,eleccion IA,resultado
    // Se reemplazan comas del nombre para no romper la lectura delimitada.
    string jugadorSeguro = p.jugador;
    for (size_t i = 0; i < jugadorSeguro.size(); ++i) {
        if (jugadorSeguro[i] == ',') jugadorSeguro[i] = ' ';
    }

    archivo << p.idPartida << ","
            << jugadorSeguro << ","
            << p.eleccionJugador << ","
            << p.eleccionIA << ","
            << p.resultado << "\n";

    if (!archivo) {
        cerr << "[ERROR] Ocurrio un problema al escribir el historial.\n";
    } else {
        cout << "[DISCO] Partida guardada en 'src/historial_partidas.txt'.\n";
    }

    archivo.close();
}

void leerHistorialDisco() {
    ifstream archivo("src/historial_partidas.txt");

    if (!archivo.is_open()) {
        cout << "\n[AVISO] Todavia no hay un historial. Juegue una partida primero.\n";
        return;
    }

    cout << "\n=====================================================\n";
    cout << " HISTORIAL DE PARTIDAS RECUPERADO DESDE DISCO\n";
    cout << "=====================================================\n";

    string idStr, jugador, elJug, elIA, resultado;
    int total = 0;

    while (getline(archivo, idStr, ',') &&
           getline(archivo, jugador, ',') &&
           getline(archivo, elJug, ',') &&
           getline(archivo, elIA, ',') &&
           getline(archivo, resultado)) {
        ++total;
        cout << "Partida #" << idStr
             << " | Jugador: " << jugador
             << " | " << elJug << " vs " << elIA
             << " | Resultado: " << resultado << "\n";
    }

    archivo.close();

    if (total == 0) {
        cout << "[AVISO] El archivo de historial esta vacio.\n";
    } else {
        cout << "\n[SISTEMA] Total de registros leidos: " << total << "\n";
    }
    cout << "=====================================================\n";
}
