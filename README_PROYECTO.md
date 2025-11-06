# Sistema de Gestión de Estudiantes y Cursos

## Descripción
Sistema completo para administrar carreras universitarias, cursos, estudiantes y catedráticos utilizando estructuras en C++ y archivos de texto para persistencia de datos.

## Características Implementadas

### ✅ 1. Inicio de Sesión
- **Usuario:** admin
- **Contraseña:** 1234
- Máximo 3 intentos de autenticación
- Bloqueo automático después de 3 intentos fallidos

### ✅ 2. Cuatro Estructuras Relacionadas
1. **datoscarrera**: Información de carreras (código, nombre, jornada, campus, inscripción, mensualidad)
2. **datoscurso**: Información de cursos (código curso, código carrera, catedrático, carnet, semestre)
3. **datosestudiante**: Información de estudiantes (carnet, código carrera, nombre)
4. **datoscatedratico**: Información de catedráticos (ID, código curso, nombre)

### ✅ 3. Menú Principal
El sistema cuenta con 11 opciones:
1. Ingreso de Carreras
2. Ingreso de Cursos
3. Ingreso de Estudiantes
4. Ingreso de Catedráticos
5. Reporte de Carreras
6. Reporte de Cursos
7. Reporte de Estudiantes
8. Reporte de Catedráticos
9. Consulta de Carrera
10. Consulta de Estudiante
11. Salir

### ✅ 4. Creación de Ficheros (void crear())
Crea automáticamente 4 archivos de texto en C:\:
- `carrera.txt`
- `curso.txt`
- `estudiante.txt`
- `catedratico.txt`

### ✅ 5. Funciones de Ingreso de Datos
Cuatro funciones void para el ingreso:
- `ingresocarreras()`: Registra nuevas carreras
- `ingresocursos()`: Registra nuevos cursos
- `ingresoestudiantes()`: Registra nuevos estudiantes
- `ingresocatedraticos()`: Registra nuevos catedráticos

**Características:**
- Validación de duplicados por código/carnet/ID
- Si existe, muestra los datos
- Si no existe, permite ingreso nuevo
- Opción para continuar ingresando (S/N)

### ✅ 6. Funciones de Reporte
Cuatro funciones void para reportes:
- `reportecarreras()`: Lista todas las carreras con formato tabular
- `reportecursos()`: Lista todos los cursos
- `reporteestudiantes()`: Lista todos los estudiantes
- `reportecatedraticos()`: Lista todos los catedráticos

**Características:**
- Formato de tabla con columnas alineadas
- Encabezados descriptivos
- Manejo de errores si no existe el archivo

### ✅ 7. Funciones de Consulta
Dos funciones void para consultas:
- `consultacarrera()`: Busca una carrera por código
- `consultaestudiante()`: Busca un estudiante por carnet

**Características:**
- Búsqueda por clave primaria
- Muestra información completa del registro
- Mensaje si no se encuentra

### ✅ 8. Casos de Uso Documentados
Se incluyen 11 casos de uso principales en el encabezado del código:
1. Inicio de Sesión
2. Ingreso de Carreras
3. Ingreso de Cursos
4. Ingreso de Estudiantes
5. Ingreso de Catedráticos
6. Reporte de Carreras
7. Reporte de Cursos
8. Reporte de Estudiantes
9. Reporte de Catedráticos
10. Consulta de Carrera
11. Consulta de Estudiante

## Mejoras Implementadas

### Correcciones de Errores
1. **Rutas de archivos corregidas**: Cambiado de `c:archivo.txt` a `c:\\archivo.txt` para compatibilidad con Windows
2. **Ingreso de datos corregido**: Agregado `cin.ignore()` después de leer números antes de `cin.getline()`
3. **Visualización correcta**: Los datos se muestran en las posiciones correctas al encontrar un registro existente

### Validaciones
- Verificación de usuario y contraseña
- Validación de duplicados antes de insertar
- Verificación de existencia de archivos
- Manejo de errores de escritura

### Interfaz Mejorada
- Mensajes claros y descriptivos
- Formato tabular en reportes
- Pausas con `getch()` para lectura
- Código de colores (cyan sobre gris)

## Compilación

### Con g++ (MinGW en Windows)
```bash
g++ Proyecto1_Mejorado.cpp -o Proyecto1.exe
```

### Con Visual Studio
1. Abrir Developer Command Prompt
2. Ejecutar:
```bash
cl Proyecto1_Mejorado.cpp
```

## Ejecución
```bash
.\Proyecto1.exe
```

## Credenciales de Acceso
- **Usuario:** admin
- **Contraseña:** 1234

## Estructura de Archivos
```
c:\carrera.txt      -> Almacena las carreras
c:\curso.txt        -> Almacena los cursos
c:\estudiante.txt   -> Almacena los estudiantes
c:\catedratico.txt  -> Almacena los catedráticos
```

## Notas Importantes
1. Los archivos se crean automáticamente en C:\ al ejecutar el programa por primera vez
2. Los datos se almacenan en formato binario
3. No eliminar los archivos .txt mientras el programa está en uso
4. El sistema valida códigos/carnets duplicados automáticamente

## Ejemplo de Uso

### 1. Registrar una Carrera
1. Seleccionar opción 1
2. Ingresar código (ej: 101)
3. Ingresar nombre (ej: Ingeniería en Sistemas)
4. Ingresar jornada (ej: Matutina)
5. Ingresar campus (ej: Central)
6. Ingresar inscripción (ej: 500)
7. Ingresar mensualidad (ej: 1200)

### 2. Consultar una Carrera
1. Seleccionar opción 9
2. Ingresar código de carrera (ej: 101)
3. Ver información completa

### 3. Ver Reporte de Carreras
1. Seleccionar opción 5
2. Ver listado completo en formato tabla

## Autor
Universidad Mariano Gálvez
Programación en C++
2025
