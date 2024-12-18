# Printf

El proyecto **Printf** forma parte del currículum de 42 y tiene como objetivo implementar una versión personalizada de la función estándar `printf` de la biblioteca C estándar. Este proyecto ayuda a comprender el manejo de cadenas, la gestión de memoria, y la manipulación de argumentos variables.

---

## 🚀 Descripción del Proyecto

El objetivo principal es recrear el comportamiento de la función `printf` permitiendo el uso de especificadores de formato básicos. La implementación debe ser eficiente y cumplir con los requisitos establecidos por el proyecto.

---

## 🔧 Especificaciones

### Funcionalidades Principales
- Soporte para los siguientes especificadores de formato:
  - `%c`: Imprime un carácter.
  - `%s`: Imprime una cadena.
  - `%d`/`%i`: Imprime un número entero con signo en base 10.
  - `%u`: Imprime un número entero sin signo en base 10.
  - `%x`/`%X`: Imprime un número en formato hexadecimal (minúsculas/mayúsculas).
  - `%%`: Imprime el carácter `%`.

### Restricciones
- No se permite usar la función original `printf`.
- Deben manejarse casos extremos como cadenas vacías, enteros negativos, y números grandes.
- Se debe garantizar un comportamiento robusto ante entradas incorrectas.

---

## 📁 Estructura del Proyecto

```plaintext
printf/
├── srcs/           # Código fuente principal
├── includes/       # Archivos de cabecera
├── tests/          # Casos de prueba
├── Makefile        # Sistema de compilación
└── README.md       # Documentación
```

---

## 🛠️ Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/cacharri/printf.git
   cd printf
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Incluye la biblioteca generada en tu proyecto:
   - Compila tu archivo de prueba junto con `libftprintf.a`:
     ```bash
     gcc -o test test.c libftprintf.a
     ```

4. Ejecuta tu programa de prueba:
   ```bash
   ./test
   ```

---

## 🌟 Características

- Manejo eficiente de argumentos variables con `va_list`.
- Soporte para múltiples especificadores de formato.
- Diseño modular para facilitar la comprensión y el mantenimiento del código.

---
