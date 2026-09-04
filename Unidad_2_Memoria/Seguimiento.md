# Unidad 2 - Datos y memoria

## Actividad 1: Hola mundo

### 1. ¿Para qué sirven los breakpoints?

Un breakpoint es una marca en una línea de código que hace que el depurador detenga la ejecución justo antes de ejecutarla

### 2. ¿Para qué se usa la ventana de depuración Autos?

La ventana "Autos" muestra automáticamente las variables relevantes en la línea actual y en las inmediatamente anteriores/siguientes, Visual Studio las elige de manera automatica.

## Actividad 2: Paso por valor y paso por referencia

### Predicción:

- `modificarPorValor(a)` dentro imprime 10 y 15, pero por fuera `a` sigue valiendo 10.
- `modificarPorReferencia(b)` dentro imprime 10 y 15 y fuera, `b` vale 15.
- `modificarPorPuntero(&c)` dentro imprime 10 y 15, pero ahora afuera `c` vale 15.

### ¿Qué diferencias observas en el comportamiento de a, b y c tras cada llamada?

`a` no cambia. `b` y `c` cambian. Las tres funciones hacen lo mismo internamente y las tres imprimen lo mismo dentro, la diferencia sólo se nota al volver a `main()`.

### ¿Por qué ocurre esta diferencia?

Por **sobre qué dirección de memoria trabaja cada función**:

- **Paso por valor:** al llamar `modificarPorValor(a)` se reserva en el stack frame de la función una
  **variable nueva `n`** y se le **copia** el contenido de `a`. Son dos celdas distintas con
  direcciones distintas. `n += 5` modifica la copia; al retornar, el frame se descarta y la copia
  desaparece. *(Compruébalo: `&n` ≠ `&a`.)*
- **Paso por referencia (`int &n`):** `n` **no es una variable nueva**, es un **alias** de `b`. Todo
  acceso a `n` es un acceso a la misma dirección de `b`. `n += 5` es literalmente `b += 5`.
  *(Compruébalo: `&n` **==** `&b`.)*
- **Paso por puntero (`int *n`):** se pasa **por valor una dirección**. `n` sí es una variable nueva,
  pero contiene la dirección de `c`; el operador `*` te lleva a la celda de `c`, y ahí es donde se
  suma. *(Compruébalo: `&n` ≠ `&c`, pero `n` **==** `&c`.)*