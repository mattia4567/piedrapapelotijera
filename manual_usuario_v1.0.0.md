# Manual del usuario — v1.0.0

## 1. ¿Qué es el programa?

Es un mini juego de consola de Piedra, Papel o Tijera. El usuario juega contra una elección aleatoria de la computadora. Cada partida se guarda en un archivo para poder consultarla más tarde.

## 2. Cómo iniciar el juego

1. Abrí la carpeta `piedrapapelotijera` en Visual Studio Code.
2. Abrí una terminal en la carpeta raíz.
3. Compilá el programa con:

   ```powershell
   g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
   ```

4. Ejecutalo con:

   ```powershell
   .\src\piedrapapelotijera.exe
   ```

## 3. Opciones del menú

- **1. Jugar partida:** permite ingresar un nombre y elegir Piedra, Papel o Tijera.
- **2. Ver historial:** muestra las partidas guardadas previamente.
- **3. Salir:** termina el programa sin borrar los datos guardados.

## 4. Cómo jugar

1. Elegí la opción 1.
2. Escribí tu nombre o nickname y presioná Enter.
3. Ingresá 1 para Piedra, 2 para Papel o 3 para Tijera.
4. El programa muestra la jugada del usuario, la de la IA y el resultado.

Reglas:

- Piedra le gana a Tijera.
- Tijera le gana a Papel.
- Papel le gana a Piedra.
- Si ambos eligen lo mismo, hay empate.

## 5. Cómo consultar las partidas anteriores

Volvé al menú y elegí la opción 2. El programa lee `src/historial_partidas.txt` y muestra las partidas registradas. También podés abrir ese archivo desde el explorador de archivos o desde Visual Studio Code.

## 6. ¿Se borran los datos al cerrar?

No. Las partidas se escriben en el disco. Por eso, al cerrar y volver a abrir el ejecutable, el historial sigue disponible.

## 7. Problemas frecuentes

- **No se encuentra `g++`:** instalá/configurá un compilador C++ y verificá que `g++` esté disponible en la terminal.
- **No se guarda el historial:** ejecutá el programa desde la carpeta raíz `piedrapapelotijera` y verificá que exista `src/`.
- **La opción no es válida:** ingresá solamente los números indicados en el menú.
- **El historial está vacío:** jugá una partida y después seleccioná la opción 2.

## 8. Datos de la entrega

Estudiante(s): [Completar nombre y apellido]  
Curso: 5.º año, 3.º [A/B]  
Versión: 1.0.0
