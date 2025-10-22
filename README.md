# Proyecto Robot

Este proyecto implementa un programa en C llamado `robot`. Este README incluye instrucciones paso a paso para usuarios con poca experiencia en compilación y ejecución de programas en C.

## Requisitos

- Compilador de C (`gcc`)
- Terminal o consola
- Archivos del proyecto: `main.c`, `cola.c`, `mapa.c`, `auxiliares.c`

## Instrucciones

Sigue estos pasos en la terminal:

```bash
# 1. Abrir la terminal
# Linux/macOS: abre "Terminal"
# Windows: abre "Símbolo del sistema" o "PowerShell"

# 2. Navegar a la carpeta del proyecto
cd /ruta/a/tu/proyecto

# 3. Compilar el proyecto
gcc main.c cola.c mapa.c auxiliares.c -o robot

# 4. Ejecutar el programa
./robot
# En Windows puede ser robot.exe

# 5. Qué hacer si hay errores
# Verifica que todos los archivos .c estén en la misma carpeta
# Asegúrate de tener gcc instalado (gcc --version)
# Lee los mensajes de error para identificar problemas
