# Manual del programador — v1.0.0

## 1. Propósito

Este documento explica la organización y el funcionamiento interno del mini juego Piedra, Papel o Tijera desarrollado en C++ para la Actividad 7 de Laboratorio de Programación.

## 2. Requisitos técnicos

- Compilador `g++` con soporte para C++11.
- Biblioteca estándar de C++.
- Terminal de PowerShell o una terminal compatible.
- Ejecutar desde la carpeta raíz del repositorio para que la ruta relativa del historial sea correcta.

## 3. Archivos principales

- `src/main.cpp`: contiene la estructura `Partida`, el menú, la lógica del juego y las funciones de lectura y escritura.
- `src/historial_partidas.txt`: almacena las partidas en formato de texto separado por comas.
- `.gitignore`: evita subir ejecutables y configuraciones locales.
- `docs/CHANGELOG.md`: registra las versiones y cambios.

## 4. Estructura de datos

La estructura `Partida` agrupa cinco campos:

- `idPartida`: identificador numérico.
- `jugador`: nombre o nickname.
- `eleccionJugador`: Piedra, Papel o Tijera.
- `eleccionIA`: elección aleatoria de la computadora.
- `resultado`: Victoria, Derrota o Empate.

Usar una estructura permite pasar los datos de una partida como una sola entidad, en lugar de enviar varias variables independientes.

## 5. Funciones principales

- `main()`: inicializa la semilla aleatoria, calcula el próximo ID y muestra el menú.
- `nombreEleccion(int opcion)`: transforma 1, 2 o 3 en el nombre de la jugada.
- `obtenerSiguienteID()`: lee los registros existentes y obtiene un ID siguiente.
- `jugarPartida(int& contadorID)`: solicita el nombre, valida la jugada, genera la opción de la IA, calcula el resultado y llama al guardado.
- `guardarEnDisco(const Partida& p)`: abre el historial con `ofstream` y `ios::app`, escribe el registro y cierra el archivo.
- `leerHistorialDisco()`: abre el historial con `ifstream`, recupera cada campo y muestra los registros.

## 6. Persistencia

`ofstream` permite escribir en un archivo. La opción `ios::app` agrega información al final del archivo, en vez de reemplazar las partidas previas. `ifstream` permite leer el archivo guardado. Los datos permanecen en el disco después de cerrar el programa.

El formato de cada línea es:

```text
ID,nombre,eleccionJugador,eleccionIA,resultado
```

Las comas que se escriban en el nombre se reemplazan por espacios para mantener la separación de campos.

## 7. Compilación y ejecución

Desde la raíz del repositorio:

```powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
.\src\piedrapapelotijera.exe
```

## 8. Pruebas recomendadas

1. Compilar sin errores.
2. Jugar una partida con cada opción posible.
3. Comprobar los resultados: Piedra vence a Tijera, Papel vence a Piedra y Tijera vence a Papel.
4. Consultar la opción 2 y verificar que aparezca la partida.
5. Cerrar y volver a abrir el ejecutable; verificar que el historial continúe.
6. Comprobar que el siguiente ID no se repita.

## 9. Consideraciones y límites

El archivo usa un formato CSV sencillo separado por comas, no un analizador CSV completo. El programa está pensado para ejecutarse desde la carpeta raíz del proyecto. Si se ejecuta desde otra ubicación, la ruta relativa `src/historial_partidas.txt` podría no encontrarse.

## 10. Autoría

Estudiante(s): [Completar nombre y apellido]  
Curso: 5.º año, 3.º [A/B]  
Institución: E.E.S.T. N.º 1 “Eduardo Ader” — Vicente López  
Versión: 1.0.0
