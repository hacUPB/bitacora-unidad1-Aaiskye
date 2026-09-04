# Unidad 2 - Datos y memoria

## Actividad 1: Hola mundo

### 1. ¿Para qué sirven los breakpoints?

Un breakpoint es una marca en una línea de código que hace que el depurador detenga la ejecución justo antes de ejecutarla

### 2. ¿Para qué se usa la ventana de depuración Autos?

La ventana "Autos" muestra automáticamente las variables relevantes en la línea actual y en las inmediatamente anteriores/siguientes, Visual Studio las elige de manera automática.

## Actividad 2: Paso por valor y paso por referencia

### Predicción:

- `modificarPorValor(a)` dentro imprime 10 y 15, pero por fuera `a` sigue valiendo 10.
- `modificarPorReferencia(b)` dentro imprime 10 y 15 y fuera, `b` vale 15.
- `modificarPorPuntero(&c)` dentro imprime 10 y 15, pero ahora afuera `c` vale 15.

### ¿Qué diferencias observas en el comportamiento de a, b y c tras cada llamada?

`a` no cambia. `b` y `c` cambian. Las tres funciones hacen lo mismo internamente y las tres imprimen lo mismo dentro, la diferencia sólo se nota al volver a `main()`.

### ¿Por qué ocurre esta diferencia?

- Paso por valor: al llamar `modificarPorValor(a)` se reserva en el stack de la función una variable nueva y se le copia el contenido de `a`. Son dos celdas distintas con 
  direcciones distintas.
- Paso por referencia (`int &n`): `n` no es una variable nueva, es un alias de `b`. Todo
  acceso a `n` es un acceso a la misma dirección de `b`.
- Paso por puntero (`int *n`): se pasa por valor una dirección que contiene la dirección de `c`; el operador `*` lleva a la celda de `c`, y ahí es donde se
  suma.

## Actividad 4

### Experimento 1: ¿Qué ocurre? ¿Por qué?

El programa imprime la dirección y luego termina con una violación de acceso.

Por qué: Porque se intenta escribir en una zona en la que no se tienen permiso de escritura, es una forma de proteger el ejecutable.

### Experimento 2: ¿Qué ocurre? ¿Por qué?

En este caso la excepción se da porque se intenta modificar una variable de tipo ´const´ lo cual también esta prohibido por seguridad del software.

### Experimento 3: ¿Qué ocurre? ¿Por qué?

En este caso no hay errores de ejecución porque se están modificando variables en posiciones de memoria con permisos de lectura y escritura.

### Experimento 4: ¿Qué ocurre? ¿Por qué?

En este experimento hay errores de compilación porque se esta intentando acceder a una variable que vive en el interior de una función y a la que no se puede acceder desde el ´main()´

### Experimento 6:

En este caso el error en tiempo de ejecución se debe a que después de liberar la memoria del ´Heap´ se debería asignar un a `nullptr`. para evitar problemas posteriores.


