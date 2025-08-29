#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
using namespace std;

// Estructura para los juegos
struct Juego {
    int codigo;
    string nombre;
    double precio;
    string plataforma;
};

// Variables globales
extern Juego catalogo[12];
extern int carrito[12];
extern int cantidades[12];
extern int itemsEnCarrito;

// Funciones
void mostrarMenu();
void mostrarCatalogo();
void agregarAlCarrito();
void mostrarCarrito();
void calcularTotal();
void limpiarCarrito();

#endif