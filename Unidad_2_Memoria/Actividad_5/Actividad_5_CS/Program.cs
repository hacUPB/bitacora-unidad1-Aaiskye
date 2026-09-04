namespace Actividad_5_CS
{
    using System;
    public class Punto
    {
        public int x;
        public int y;
        public string name;
        // Constructor
        public Punto(string _name, int _x, int _y)
        {
            name = _name;
            x = _x;
            y = _y;
            Console.WriteLine($"Constructor: Punto {name}({x}, {y}) creado.");
        }
        // Método para imprimir valores
        public void Imprimir()
        {
            Console.WriteLine($"Punto {name}({x}, {y})");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Objeto original
            Punto original = new Punto("original", 70, 80);
            original.Imprimir();
            Punto copia = original;
            copia.name = "copia";
            copia.x = 100;
            copia.y = 200;
            copia.Imprimir();
            original.Imprimir();
            // Coloca breakpoints en la creación de 'original' y en la línea de la copia.
            // Observa que 'copia' es una copia independiente de 'original'. ¿Lo es?
        }
    }
}
