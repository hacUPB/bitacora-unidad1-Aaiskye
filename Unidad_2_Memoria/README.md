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

En este caso la excepción se da porque se intenta modificar una variable de tipo `const` lo cual también esta prohibido por seguridad del software.

### Experimento 3: ¿Qué ocurre? ¿Por qué?

En este caso no hay errores de ejecución porque se están modificando variables en posiciones de memoria con permisos de lectura y escritura.

### Experimento 4: ¿Qué ocurre? ¿Por qué?

En este experimento hay errores de compilación porque se esta intentando acceder a una variable que vive en el interior de una función y a la que no se puede acceder desde el ´main()´

### Experimento 6:

En este caso el error en tiempo de ejecución se debe a que después de liberar la memoria del `Heap` se debería asignar un a `nullptr`. para evitar problemas posteriores.

## Actividad 5

### 1. Explica qué ocurre al copiar un objeto en C++ y en C#. ¿Qué diferencias encuentras?

En `C++` la copia es un objeto independiente con su espacio en memoria mientras que en `C#` es una referencia al objeto original.

### 2. ¿Qué es `copia` en C++ y en C#? ¿Es una copia independiente de `original`?

No, no es una copia independiente del original, es una referencia.

## Actividad integradora

## Actividad 6:

## Actividad 7: Objetos en el heap

Direcciones de memoria:
- `&pStack`	**0x0000003ff82ff8c8**
- `pHeap`		**0x000001bb4512b470**

**Reflexiona sobre lo siguiente**:

1. Explicación de la diferencia entre objetos creados en el stack y en el heap.
2. `pStack` ¿Es un objeto o una referencia a un objeto?
3. `pHeap` ¿Es un objeto o una referencia a un objeto? Si es una referencia, ¿A qué objeto hace referencia?
4. Observa en Memory1 (Debug->Windows->Memory->Memory1) el contenido de la dirección de memoria de `pHeap`, recuerda escribir en la entrada de texto de Memory1 la dirección de memoria de `&pHeap` y presionar Enter. Compara el contenido de memoria con el contenido de `pHeap` en la pestaña de Locals (Debug->Windows->Locals). ¿Qué observas? ¿Qué significa esto?

## Actividad 8: Funciones y objetos en C++

1. ¿Qué ocurre después de llamar a la función `cambiarNombre`?

El nombre de `original` no cambia porque la función utiliza una copia de `original`. La segunda llamada a `original.imprimir()` sigue mostrando `Punto original(70, 80)`.

¿Por qué aparece el mensaje `Destructor: Punto cambiado(70, 80) destruido.`?

Aparece porque la función `cambiarNombre` trabaja con copia que solo existe al interior de la función, por eso al salir de la función el objeto copia `p` se destruye, llamando su destructor `~Punto()`

2. ¿Por qué `original` sigue existiendo luego de llamar `cambiarNombre`?

direcciones de memoria:
- `original`	**0x0000005300b2fab8**
- `p`		**0x0000005300b2fc88**

porque lo que se destruyo fue la copia `p`. como se puede ver son objetos completamente distintos almacenados en diferentes direcciones de memoria. por lo que el destructor de `original` no se ejecuta.

3. ¿En qué parte del mapa de memoria se encuentra `original` y en qué parte se encuentra `p`? ¿Son el mismo objeto? (recuerda usar siempre el depurador para responder estas preguntas).

Ambos se encuentran en el Stack pero se encuentran en diferentes posiciones de memoria, como ya sabemos son dos objetos distintos.

### Después de las modificaciones:

### Direcciones de memoria:

- `p` (apunta a)->	0x0000005d896ff928 
- `original`		0x0000005d896ff928

1. ¿Qué ocurre ahora? ¿Por qué?

Ahora `p` esta apuntando a la dirección de memoria de `original`. Entonces los cambios que se hacen a `p` se hacen también en `original`, y por eso ahora si cambia `name` y esto se ve en el mensaje
en pantalla.

2. En este caso ¿Cuál es la diferencia entre pasar un objeto por valor, por referencia y por puntero?

Como se dijo anteriormente ahora no se trata de una copia con sus atributos y métodos propios, sino que se realizan sobre una dirección de memoria.

### Nota:

Aunque se realizan dos modificaciones, una para hacer la diferenciación entre paso por referencia y por puntero. el pantallazo, los datos de memoria y las conclusiones son las mismas, por lo cual se hacen 
solo sobre el paso por puntero.

## Actividad 9: Objetos con miembros estáticos y variables de instancia

### Direcciones de memoria:

- `&c1`			0x000000b2b413f534 {valor=6 }
- `&c2`			0x000000b2b413f554 {valor=11 }
- `c3` (apunta a)-> 	0x000001ec54109b00 {valor=16 }

En este caso no se puede observar el atributo `total` porque es un atributo de tipo **static**. lo cual lo convierte en un atributo propio de la clase `Contador` y lo comparten los 3 objetos.

Por otro lado los atributos `valor` se encuentran al interior de cada objeto y ocupan su propio espacio en memoria. mientras que `total` se encuentra en la zona de variables `Globales` y `Estaticas`

### 1. ¿Qué puedes concluir de los miembros estáticos y de instancia de una clase en C++? ¿Cómo se gestionan en memoria? ¿Qué ventajas y desventajas tienen? ¿Cuándo es útil utilizarlos?

Los miembros estáticos son muy útiles para llevar un conteo de las instancias de la clase o si cada objeto debe tener por ejemplo un identificador secuencial, por lo cual la variable estática podría funcionar de semilla o como contador.

### Algunas desventajas:

- Genera acoplamiento.
- Dificulta las pruebas ya que el orden en que se ejecutan las instrucciones se vuelve importante.

### 2. En el programa, en qué segmento de memoria se están almacenando c1, c2, c3 y Contador::total? Ten especial cuidado con la respuesta que das para el caso de c3, piensa de nuevo, qué es c3 y qué está almacenando. Ahora, responde de nuevo, en qué segmento de la memoria se está almacenando c3 y en qué segmento de la memoria se está almacenando el objeto al que apunta c3.

`c1`, `c2` y `c3` están almacenados en el **Stack**. Mientras que `total` esta almacenado en la región de variables estáticas, por fuera de los objetos. Ahora. `c3` es de tipo 'Contador*' y en memoria esta almacenado en el **Stack** pero el objeto al que esta apuntando se encuentra en el **Heap** porque se construyo utilizando **new**.

## Actividad 10: Explorando el ciclo de vida de un objeto

1. Explica el ciclo de vida de un objeto en el stack versus uno en el heap.

El compilador reserva el espacio de memoria en el `stack` cuando se crea el objeto, mensaje en pantalla `Constructor: Punto(100, 200) creado.`. vive mientras estamos al interior del bloque. pero al salir de la llave `}` se ejecuta automáticamente el destructor y se lee en la consola `Destructor: Punto(100, 200) destruido.`. Ahora ya no se puede ver en el inspector.

`pDinamico` se crea con **new** por lo que se reserva un espacio en el `heap`. vive mientras el código esta en ejecución o hasta que liberemos ese espacio en memoria con **delete**

### Primera modificación:

1. No compila porque pBloque2 no esta definido en ese bloque. el objeto nace y se destruye al salir de las llaves.

### Segunda modificación:

1. ¿Por qué el objeto `pBloque` se destruye al salir del bloque y `pBloque2` no? Recuerda de nuevo, `pBloque2` es un objeto o es una referencia a un objeto?

`pBloque` es un objeto y esta almacenado en el `stack`. su ciclo de vida depende del primer bloque entre llaves. por eso se destruye al salir. Por otro lado `pBloque2` es un puntero. apunta a la dirección donde se almaceno el objeto de tipo Punto que se creo con **new**. como `pBloque2` se declaro por fuera de la segunda llave sobrevive al salir del segundo bloque. y lo mas importante es que `pBloque2` apunta a un objeto en el `heap` que se debe liberar con un **delete**

2. ¿En qué parte de la memoria se almacena `pBloque2`? ¿En qué parte de la memoria se almacena el objeto al que apunta `pBloque2`?

`pBloque2` se almacena en el `stack`, su valor es la dirección de memoria de un objeto almacenado en el `heap`

## Actividad integradora de aplicación

### 1. Diagnóstico del problema (análisis):

Error 1: Fuga de memoria. El constructor hace new int[3] y la clase no tiene destructor, así que nunca hay un delete[]. El objeto `heroe` vive en el `stack` y sólo guarda ahí la dirección del `array`; las **estadisticas** están en el heap. Al salir de `simularEncuentro()` el `stack` el objeto desaparece, pero las estadísticas en el `heap` sólo se libera con `delete`. El bloque queda reservado y ya se perdió el puntero a esa dirección. Entonces cada NPC creado reserva espacio en el `heap` para las **estadisticas** y la RAM crece sin parar.

Error 2: Personaje copiaHeroe = heroe; usa el constructor de copia implícito, que copia miembro a miembro. nombre se copia de verdad, pero `estadisticas` es un puntero: se copia la dirección. Quedan dos objetos en el `stack` apuntando a las mismas estadisticas en el `heap`. Entonces la solución debe cubrir tanto al `original` como a la `copia`. Si arreglamos el Error 1 con un destructor, ambos objetos harán `delete` sobre la misma dirección esto llevaría a otro error.

### 2. Solución y refactorización (síntesis y creación):

Quitar la memoria dinámica. El tamaño es fijo y conocido en compilación, así que las `estadisticas` no tiene por qué estar en el `heap`.

```
int estadisticas[3];   // y no int* estadisticas; y luego estadisticas = new int[3];
```

Esto corrige los dos errores sin agregar problemas en tiempo de ejecución con un `delete`. Una mejora de calidad de vida es mostrar por la consola las `estadisticas` aprovechando que la función ya existe.

### 3. Justificación de la Solución:

No hay fugas porque no se reserva en el `heap`. Las `estadisticas` son del objeto y mueren con él. Además, al copiar miembro a miembro, las `estadisticas` se copian elemento a elemento, no como dirección. Cada Personaje tiene su propio espacio en memoria.

Segundo, si no comparten puntero y sin `delete` en ninguna parte, las `estadisticas` de cada personaje son independientes.

