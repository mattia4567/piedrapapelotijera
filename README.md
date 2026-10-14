# 🎮 Piedra, Papel o Tijera — Actividad 7

**Materia:** Laboratorio de Programación (LPR) — 5.º año  
**Institución:** E.E.S.T. N.º 1 “Eduardo Ader” — Vicente López  
**Actividad:** Mini juego Piedra, Papel o Tijera con persistencia de datos (`struct` + `fstream`)  
**Estudiante(s):** [Completar nombre y apellido]  
**Grupo:** 3.º [A/B]  
**Año:** 2026

## Descripción

Aplicación de consola en C++ para jugar Piedra, Papel o Tijera contra una elección aleatoria de la computadora. Cada partida se guarda en `src/historial_partidas.txt`, y el menú permite consultar el historial aunque se cierre y vuelva a ejecutar el programa.

## Funcionalidades

1. Jugar una partida contra la IA.
2. Registrar ID, nombre, elección del jugador, elección de la IA y resultado.
3. Guardar los registros en disco usando `ofstream` con `ios::app`.
4. Leer y mostrar los registros mediante `ifstream`.
5. Conservar las partidas anteriores entre ejecuciones.

## Estructura del repositorio

```text
piedrapapelotijera/
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── src/
│   ├── main.cpp
│   └── historial_partidas.txt
├── docs/
│   ├── InformeEEST1_LPR2026_ACT07_G03_[ApellidoNombre]_Informe_v1.0.0.pdf
│   ├── CHANGELOG.md
│   └── manuales/
│       ├── manual_programador_v1.0.0.md
│       ├── manual_programador_v1.0.0.pdf
│       ├── manual_usuario_v1.0.0.md
│       └── manual_usuario_v1.0.0.pdf
└── capturas/
    ├── jugada_consola.png
    └── archivo_disco.png
```

## Requisitos

- Windows 10/11.
- Visual Studio Code (o una terminal).
- Compilador `g++` compatible con C++11, por ejemplo MinGW-w64.

## Compilar y ejecutar en PowerShell

Abrí la terminal en la carpeta raíz `piedrapapelotijera` y ejecutá:

```powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
.\src\piedrapapelotijera.exe
```

El programa utiliza la ruta relativa `src/historial_partidas.txt`; por eso debe ejecutarse desde la carpeta raíz del proyecto, como muestran los comandos anteriores.

## Evidencias

Guardá capturas reales de tu ejecución en la carpeta `capturas/`:

- `jugada_consola.png`: menú y una partida jugada.
- `archivo_disco.png`: contenido de `src/historial_partidas.txt` abierto en el editor.

No incluyas capturas inventadas: ejecutá el programa y tomalas desde tu computadora.

## Documentación

- Informe académico: `docs/InformeEEST1_LPR2026_ACT07_G03_[ApellidoNombre]_Informe_v1.0.0.pdf`.
- Manual del programador y manual del usuario: carpeta `docs/manuales/`.
- Historial de cambios: `docs/CHANGELOG.md`.

## Repositorios remotos

- GitHub: [pegar URL pública del repositorio]
- GitLab: [pegar URL pública del repositorio]

Completá los enlaces reales antes de entregar.
