# Arduino Piano Tiles

This is a repository for an Arduino Project, which consists on making a playable Piano Tiles game using buttons, a buzzer and a dot matrix.


## Materials

- Arduino Uno REV-3
- Dot Matrix 1588bs
- 4 Buttons
- A buzzer
- 16 male-to-male cables for the Matrix, 8 for the Buttons and 2 for the buzzer

## Authors

- [@Dorabyte-Dev](https://github.com/Dorabyte-Dev)
- [@ecaturla2003](https://github.com/ecaturla2003-coder)

## PianoTiles – El Castillo Ambulante

Objetivo del proyecto

Desarrollar un prototipo que simule un juego tipo Piano Tiles utilizando una dot matrix, botones y un buzzer, donde al bajar una luz en la matriz el usuario debe pulsar el botón correspondiente para reproducir una nota musical. La melodía seleccionada está basada en el leitmotiv de El Castillo Ambulante.

## Equipo y roles

[Emilio Caturla]	Montaje físico, pruebas en Tinkercad, investigación y definición de notas MIDI, frecuencias y melodía.
[Álvaro Morales]	Desarrollo del código, lógica de iluminación y detección de botones, investigación de componentes electrónicos y funcionamiento del sistema.

## Plan de sprints

El proyecto se organizó en dos sprints principales, con objetivos concretos:

[Sprint 1] — Montaje e investigación

Investigar los componentes: dot matrix, buzzer, botones.
Intentar simular el proyecto en Fritzing (limitado por falta de ejecución de código).
Crear prototipo básico en físico.
Probar combinaciones de sonido con buzzer en Tinkercad.
Identificar notas MIDI, frecuencias y estructura de la melodía.

[Sprint 2] — Integración y correcciones

Programar la dot matrix con movimiento descendente de luces.
Resolver errores de conexión y reconfigurar el esquema.
Integrar la lógica de botones.
Completar y ajustar la melodía para reproducirse correctamente.
Preparar el prototipo final para que luz, sonido y pulsadores se sincronicen.

##Bitácora de trabajo (por sesiones)

[Sesión 1] — Intento de simulación

Se intenta recrear el proyecto en Fritzing para probar el circuito antes de montarlo.
Se descubre que Fritzing no permite ejecutar código, por lo que no es útil para testear la dot matrix.
Tinkercad tampoco ofrece dot matrix, así que no puede simularse completamente.
Decisión: montar directamente el prototipo físico.

[Sesión 2] — Montaje inicial del prototipo

Se monta la dot matrix, el buzzer y los botones en protoboard.
El prototipo no funciona correctamente: varias columnas de la matriz no se encienden.
Se revisa el cableado sin éxito; se detecta un comportamiento anómalo en el display.

[Sesión 3] — Identificación del problema y corrección

Se pide ayuda al profesor para analizar el error.
Descubrimos que el esquema que estábamos siguiendo correspondía a un modelo de dot matrix diferente, con pines reorganizados.
Muchas conexiones estaban mal asignadas.
Se corrige todo el cableado siguiendo el pinout correcto.
Tras la reparación, la dot matrix funciona de forma estable.

[Sesión 4] — División del trabajo y avance

Se divide oficialmente el trabajo:
Álvaro se encarga de la lógica de programación para que la matriz encienda y desplace luces por columnas simulando “tiles”.
Emilio monta un prototipo con buzzer e investiga cómo implementar la canción.
En Tinkercad se prueban frecuencias, notas MIDI y combinaciones de duración.
Se establecen reglas: 0 = silencio, repetición = aumenta duración, etc.

[Sesión 5] — Integración parcial y melodía

La dot matrix empieza a comportarse correctamente: las luces bajan de forma ordenada.
Se completan las definiciones de notas MIDI y sus frecuencias para Arduino.
Se prepara la melodía completa del proyecto.
Se ajustan tonos (arriba/abajo) y duraciones (duplicaciones) para adaptarla al ritmo del juego.

## Problemas encontrados y decisiones tomadas

Imposibilidad de simular la dot matrix
➜ Se decidió pasar directamente a montaje físico.

La dot matrix no encendía columnas completas
➜ Se revisó el esquema y, con ayuda del profesor, se detectó que seguíamos el pinout incorrecto de otra matriz.
➜ Decisión: rehacer el cableado completo siguiendo el modelo correcto.

Dificultad para ajustar la melodía al buzzer
➜ Se realizaron pruebas intensivas en Tinkercad para validar tonos y duraciones antes de implementarlo.

Necesidad de dividir el trabajo
➜ Emilio: parte sonora + montaje.
➜ Álvaro: lógica de programación y funcionamiento interno del dispositivo.

## Estado actual del proyecto

Dot matrix funcionando correctamente con iluminación descendente.
Notas MIDI, frecuencias y melodía casi definidas.
Buzzer probando sonidos de manera estable.
Prototipo físico montado y en funcionamiento parcial.

## Tareas pendientes

Terminar la implementación completa de la canción en el buzzer.

Sincronizar:
Dot matrix
Pulsadores
Sonido

Ajustar tiempos para que luz + botón + nota se ejecuten de forma fluida.

Integración final de todo el sistema en un único sketch funcional.
