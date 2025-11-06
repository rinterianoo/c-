# INSTRUCCIONES DE COMPILACIÓN - Sistema de Gestión

## ⚠️ IMPORTANTE: Necesitas un Compilador de C++

El código está listo, pero necesitas instalar un compilador de C++ para Windows.

---

## OPCIÓN 1: MinGW-w64 (Recomendado para principiantes)

### Instalación:
1. Descarga MinGW-w64 desde: https://www.mingw-w64.org/downloads/
2. O usa el instalador de MSYS2: https://www.msys2.org/
3. Durante la instalación, asegúrate de agregar al PATH

### Instalación con MSYS2 (más fácil):
1. Descarga MSYS2: https://www.msys2.org/
2. Instala MSYS2
3. Abre "MSYS2 MSYS" desde el menú inicio
4. Ejecuta:
   ```bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   ```
5. Agrega a tu PATH de Windows:
   `C:\msys64\mingw64\bin`

### Verificar instalación:
```powershell
g++ --version
```

### Compilar:
```powershell
cd "c:\Users\HP\OneDrive - Universidad Mariano Gálvez\Documentos\GitHub\c++"
g++ Proyecto1_Mejorado.cpp -o Proyecto1.exe
```

### Ejecutar:
```powershell
.\Proyecto1.exe
```

---

## OPCIÓN 2: Visual Studio Community (Profesional)

### Instalación:
1. Descarga Visual Studio Community: https://visualstudio.microsoft.com/es/downloads/
2. Durante la instalación, selecciona:
   - "Desarrollo para el escritorio con C++"
3. Espera a que se instale (puede tomar tiempo)

### Compilar desde Developer Command Prompt:
1. Busca "Developer Command Prompt for VS" en el menú inicio
2. Navega a la carpeta:
   ```cmd
   cd "c:\Users\HP\OneDrive - Universidad Mariano Gálvez\Documentos\GitHub\c++"
   ```
3. Compila:
   ```cmd
   cl Proyecto1_Mejorado.cpp
   ```

### Ejecutar:
```cmd
Proyecto1_Mejorado.exe
```

---

## OPCIÓN 3: Code::Blocks (IDE completo con compilador incluido)

### Instalación:
1. Descarga Code::Blocks con MinGW: http://www.codeblocks.org/downloads
2. Descarga la versión: `codeblocks-20.03mingw-setup.exe`
3. Instala normalmente

### Uso:
1. Abre Code::Blocks
2. File → New → Project → Console Application
3. Copia el contenido de `Proyecto1_Mejorado.cpp`
4. Presiona F9 para compilar y ejecutar

---

## OPCIÓN 4: Dev-C++ (Más simple para estudiantes)

### Instalación:
1. Descarga Dev-C++: https://sourceforge.net/projects/orwelldevcpp/
2. Instala normalmente (incluye MinGW)

### Uso:
1. Abre Dev-C++
2. File → New → Source File
3. Copia el contenido de `Proyecto1_Mejorado.cpp`
4. File → Save As → `Proyecto1.cpp`
5. Execute → Compile & Run (F11)

---

## OPCIÓN 5: Online (Sin instalación)

Si quieres probar el código sin instalar nada:

### OnlineGDB:
1. Ve a: https://www.onlinegdb.com/online_c++_compiler
2. Copia el contenido de `Proyecto1_Mejorado.cpp`
3. Pega en el editor
4. Click en "Run"

⚠️ **NOTA:** Algunas funciones como `gotoxy()` y `Sleep()` pueden no funcionar en compiladores online porque dependen de Windows.

---

## SOLUCIÓN RÁPIDA RECOMENDADA

### Para estudiantes que quieren empezar YA:

1. **Descarga Dev-C++** (5 minutos de instalación)
   - Link: https://sourceforge.net/projects/orwelldevcpp/
   - Incluye compilador
   - Interfaz simple
   - No requiere configuración

2. **Abre el archivo**
   - File → Open → Selecciona `Proyecto1_Mejorado.cpp`

3. **Compila y ejecuta**
   - Presiona F11
   - ¡Listo!

---

## VERIFICACIÓN DE INSTALACIÓN

Después de instalar cualquier compilador, verifica en PowerShell:

```powershell
# Para MinGW o Dev-C++:
g++ --version

# Para Visual Studio:
cl
```

Si ves información de versión, ¡está instalado correctamente!

---

## PROBLEMAS COMUNES

### Error: "g++ no se reconoce como comando"
**Solución:** Necesitas agregar el compilador al PATH de Windows

1. Presiona `Win + R`
2. Escribe `sysdm.cpl` y presiona Enter
3. Ve a "Opciones avanzadas" → "Variables de entorno"
4. En "Variables del sistema", busca "Path"
5. Click en "Editar"
6. Click en "Nuevo"
7. Agrega la ruta donde instalaste el compilador:
   - MinGW: `C:\MinGW\bin`
   - MSYS2: `C:\msys64\mingw64\bin`
   - Dev-C++: `C:\Program Files (x86)\Dev-Cpp\MinGW64\bin`
8. Click "Aceptar" en todo
9. Reinicia PowerShell

### Error al compilar por las funciones de Windows
El código usa funciones específicas de Windows:
- `gotoxy()` - para posicionar cursor
- `Sleep()` - para pausas
- `system("cls")` - para limpiar pantalla
- `system("color 8A")` - para colores

Estas funciones SÍ funcionan en Windows con cualquier compilador.

### Error: "windows.h: No such file or directory"
**Solución:** Estás usando un compilador que no es para Windows o no está bien configurado.
Reinstala MinGW o Dev-C++.

---

## COMPILACIÓN MANUAL (Una vez instalado el compilador)

### Usando PowerShell:

```powershell
# Navegar a la carpeta
cd "c:\Users\HP\OneDrive - Universidad Mariano Gálvez\Documentos\GitHub\c++"

# Compilar
g++ Proyecto1_Mejorado.cpp -o Proyecto1.exe

# Ejecutar
.\Proyecto1.exe

# O todo en una línea:
g++ Proyecto1_Mejorado.cpp -o Proyecto1.exe; if ($?) { .\Proyecto1.exe }
```

---

## ARCHIVOS DEL PROYECTO

Una vez que compiles y ejecutes, se crearán automáticamente:

```
C:\
├── carrera.txt      (Datos de carreras)
├── curso.txt        (Datos de cursos)
├── estudiante.txt   (Datos de estudiantes)
└── catedratico.txt  (Datos de catedráticos)
```

---

## CREDENCIALES DEL SISTEMA

- **Usuario:** admin
- **Contraseña:** 1234

---

## SIGUIENTE PASO

1. ✅ Instala un compilador (recomiendo Dev-C++ para facilidad)
2. ✅ Abre `Proyecto1_Mejorado.cpp`
3. ✅ Compila y ejecuta
4. ✅ Usa las credenciales: admin / 1234
5. ✅ Prueba todas las opciones del menú

---

## SOPORTE

Si tienes problemas:
1. Verifica que el compilador esté en el PATH
2. Asegúrate de estar en Windows (el código usa funciones de Windows)
3. Revisa que el archivo no tenga errores de codificación (debe ser ANSI o UTF-8)

¡Buena suerte! 🚀
