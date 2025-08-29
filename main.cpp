#include "main.h"
#include <iostream>
#include <string>

// Catálogo de 12 juegos (4 categorías x 3 juegos)
Juego catalogo[12] = {
    // Acción
    {101, "Call of Duty", 69.99, "PS5"},
    {102, "Assassins Creed", 59.99, "Xbox"},
    {103, "Doom Eternal", 39.99, "PC"},
    // Aventura
    {201, "Zelda Tears", 69.99, "Switch"},
    {202, "Horizon West", 49.99, "PS5"},
    {203, "Tomb Raider", 29.99, "PC"},
    // Deportes
    {301, "FIFA 24", 69.99, "Xbox"},
    {302, "NBA 2K24", 59.99, "PS5"},
    {303, "F1 23", 49.99, "PC"},
    // Estrategia
    {401, "Civilization VI", 39.99, "PC"},
    {402, "Age of Empires", 59.99, "Xbox"},
    {403, "Total War", 49.99, "PC"}
};

// Variables del carrito
int carrito[12] = {0}; // índices de juegos en carrito
int cantidades[12] = {0}; // cantidades de cada juego
int itemsEnCarrito = 0;

int main() {
    cout << "=== TIENDA DE VIDEOJUEGOS ===" << endl;

    int opcion;

    do {
        mostrarMenu();
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarCatalogo();
                break;
            case 2:
                agregarAlCarrito();
                break;
            case 3:
                mostrarCarrito();
                break;
            case 4:
                calcularTotal();
                break;
            case 5:
                limpiarCarrito();
                break;
            case 0:
                cout << "¡Gracias por tu visita!" << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }

        if(opcion != 0) {
            cout << "\nPresiona Enter...";
            cin.ignore();
            cin.get();
        }

    } while(opcion != 0);

    return 0;
}

void mostrarMenu() {
    cout << "\n--- MENU ---" << endl;
    cout << "1. Ver catalogo" << endl;
    cout << "2. Agregar al carrito" << endl;
    cout << "3. Ver carrito" << endl;
    cout << "4. Calcular total con descuentos" << endl;
    cout << "5. Limpiar carrito" << endl;
    cout << "0. Salir" << endl;
}

void mostrarCatalogo() {
    cout << "\n--- CATALOGO DE JUEGOS ---" << endl;
    cout << "Codigo  Nombre                Precio    Plataforma" << endl;
    cout << "------------------------------------------------" << endl;

    for(int i = 0; i < 12; i++) {
        cout << catalogo[i].codigo << "     "
             << catalogo[i].nombre << "        $"
             << catalogo[i].precio << "    "
             << catalogo[i].plataforma << endl;
    }
}

void agregarAlCarrito() {
    if(itemsEnCarrito >= 10) {
        cout << "Carrito lleno (máximo 10 ítems)" << endl;
        return;
    }

    int codigo, cantidad;
    cout << "Código del juego: ";
    cin >> codigo;
    cout << "Cantidad: ";
    cin >> cantidad;

    // Buscar el juego
    int indiceJuego = -1;
    for(int i = 0; i < 12; i++) {
        if(catalogo[i].codigo == codigo) {
            indiceJuego = i;
            break;
        }
    }

    if(indiceJuego == -1) {
        cout << "Juego no encontrado" << endl;
        return;
    }
    carrito[itemsEnCarrito] = indiceJuego;
    cantidades[itemsEnCarrito] = cantidad;
    itemsEnCarrito++;
    cout << "Juego agregado al carrito" << endl;
}

void mostrarCarrito() {
    if(itemsEnCarrito == 0) {
        cout << "Carrito vacío" << endl;
        return;
    }

    cout << "\n--- CARRITO ---" << endl;
    cout << "Juego                 Cantidad  Precio    Subtotal" << endl;
    cout << "------------------------------------------------" << endl;

    double total = 0;
    for(int i = 0; i < itemsEnCarrito; i++) {
        int indice = carrito[i];
        double subtotal = catalogo[indice].precio * cantidades[i];
        total += subtotal;

        cout << catalogo[indice].nombre << "     "
             << cantidades[i] << "         $"
             << catalogo[indice].precio << "    $"
             << subtotal << endl;
    }

    cout << "------------------------------------------------" << endl;
    cout << "TOTAL: $" << total << endl;
}

void calcularTotal() {
    if(itemsEnCarrito == 0) {
        cout << "Carrito vacio" << endl;
        return;
    }

    int tipoCliente;
    cout << "Tipo de cliente:" << endl;
    cout << "0. Regular (0%)" << endl;
    cout << "1. Plata (8%)" << endl;
    cout << "2. Oro (15%)" << endl;
    cout << "Opcion: ";
    cin >> tipoCliente;

    double descuento = 0;
    switch(tipoCliente) {
        case 1: descuento = 0.08; break;  // 8%
        case 2: descuento = 0.15; break;  // 15%
        default: descuento = 0.0; break;  // 0%
    }

    double totalSinDescuento = 0;
    for(int i = 0; i < itemsEnCarrito; i++) {
        int indice = carrito[i];
        totalSinDescuento += catalogo[indice].precio * cantidades[i];
    }

    double totalConDescuento = totalSinDescuento * (1 - descuento);

    cout << "\n--- RESUMEN ---" << endl;
    cout << "Total sin descuento: $" << totalSinDescuento << endl;
    cout << "Descuento aplicado: " << (descuento * 100) << "%" << endl;
    cout << "TOTAL A PAGAR: $" << totalConDescuento << endl;
}

void limpiarCarrito() {
    itemsEnCarrito = 0;
    for(int i = 0; i < 12; i++) {
        carrito[i] = 0;
        cantidades[i] = 0;
    }
    cout << "Carrito limpiado" << endl;
}