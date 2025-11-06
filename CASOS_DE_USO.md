# CASOS DE USO - Sistema de Gestión de Estudiantes y Cursos

## Actor Principal
**Usuario del Sistema** (Administrador)

---

## Caso de Uso 1: Iniciar Sesión

### Descripción
El usuario debe autenticarse para acceder al sistema.

### Precondiciones
- El programa está en ejecución

### Flujo Principal
1. El sistema muestra la pantalla de inicio de sesión
2. El usuario ingresa su nombre de usuario
3. El usuario ingresa su contraseña
4. El sistema valida las credenciales
5. Si son correctas, el sistema muestra el menú principal
6. Si son incorrectas, el sistema muestra un mensaje de error

### Flujo Alternativo
- Si el usuario falla 3 veces, el sistema se cierra

### Postcondiciones
- El usuario tiene acceso al menú principal

---

## Caso de Uso 2: Ingresar Carrera

### Descripción
Permite registrar una nueva carrera en el sistema.

### Precondiciones
- El usuario ha iniciado sesión
- Se encuentra en el menú principal

### Flujo Principal
1. El usuario selecciona opción 1
2. El sistema solicita el código de la carrera
3. El usuario ingresa el código
4. El sistema verifica si el código ya existe
5. Si no existe, solicita los demás datos:
   - Nombre de la carrera
   - Jornada
   - Campus
   - Costo de inscripción
   - Mensualidad
6. El sistema guarda los datos en carrera.txt
7. El sistema pregunta si desea continuar
8. Si responde "S", vuelve al paso 2
9. Si responde "N", regresa al menú principal

### Flujo Alternativo
- Si el código ya existe:
  - El sistema muestra los datos existentes
  - No permite modificarlos
  - Pregunta si desea continuar

### Postcondiciones
- La carrera queda registrada en el archivo carrera.txt

---

## Caso de Uso 3: Ingresar Curso

### Descripción
Permite registrar un nuevo curso asociado a una carrera.

### Precondiciones
- El usuario ha iniciado sesión
- Existen carreras registradas

### Flujo Principal
1. El usuario selecciona opción 2
2. El sistema solicita el código del curso
3. El usuario ingresa el código
4. Si no existe, el sistema solicita:
   - Código de carrera (debe existir previamente)
   - Nombre del catedrático
   - Carnet del estudiante
   - Semestre
5. El sistema guarda los datos en curso.txt
6. Pregunta si desea continuar

### Postcondiciones
- El curso queda registrado en curso.txt

---

## Caso de Uso 4: Ingresar Estudiante

### Descripción
Permite registrar un nuevo estudiante.

### Precondiciones
- El usuario ha iniciado sesión
- Existen carreras registradas

### Flujo Principal
1. El usuario selecciona opción 3
2. El sistema solicita el carnet
3. El usuario ingresa el carnet
4. Si no existe, el sistema solicita:
   - Código de carrera
   - Nombre del estudiante
5. El sistema guarda los datos en estudiante.txt
6. Pregunta si desea continuar

### Postcondiciones
- El estudiante queda registrado en estudiante.txt

---

## Caso de Uso 5: Ingresar Catedrático

### Descripción
Permite registrar un nuevo catedrático.

### Precondiciones
- El usuario ha iniciado sesión
- Existen cursos registrados

### Flujo Principal
1. El usuario selecciona opción 4
2. El sistema solicita el ID del catedrático
3. El usuario ingresa el ID
4. Si no existe, el sistema solicita:
   - Código del curso
   - Nombre del catedrático
5. El sistema guarda los datos en catedratico.txt
6. Pregunta si desea continuar

### Postcondiciones
- El catedrático queda registrado en catedratico.txt

---

## Caso de Uso 6: Generar Reporte de Carreras

### Descripción
Muestra un listado de todas las carreras registradas.

### Precondiciones
- El usuario ha iniciado sesión
- Existen carreras registradas

### Flujo Principal
1. El usuario selecciona opción 5
2. El sistema lee el archivo carrera.txt
3. El sistema muestra en formato tabla:
   - Código
   - Nombre
   - Jornada
   - Campus
   - Inscripción
   - Mensualidad
4. El usuario presiona una tecla para continuar
5. El sistema regresa al menú principal

### Flujo Alternativo
- Si no hay carreras, muestra mensaje de archivo vacío

### Postcondiciones
- El usuario visualiza la información de todas las carreras

---

## Caso de Uso 7: Generar Reporte de Cursos

### Descripción
Muestra un listado de todos los cursos registrados.

### Precondiciones
- El usuario ha iniciado sesión
- Existen cursos registrados

### Flujo Principal
1. El usuario selecciona opción 6
2. El sistema muestra todos los cursos en formato tabla
3. El usuario presiona una tecla para continuar

### Postcondiciones
- El usuario visualiza la información de todos los cursos

---

## Caso de Uso 8: Generar Reporte de Estudiantes

### Descripción
Muestra un listado de todos los estudiantes registrados.

### Precondiciones
- El usuario ha iniciado sesión
- Existen estudiantes registrados

### Flujo Principal
1. El usuario selecciona opción 7
2. El sistema muestra todos los estudiantes en formato tabla
3. El usuario presiona una tecla para continuar

### Postcondiciones
- El usuario visualiza la información de todos los estudiantes

---

## Caso de Uso 9: Generar Reporte de Catedráticos

### Descripción
Muestra un listado de todos los catedráticos registrados.

### Precondiciones
- El usuario ha iniciado sesión
- Existen catedráticos registrados

### Flujo Principal
1. El usuario selecciona opción 8
2. El sistema muestra todos los catedráticos en formato tabla
3. El usuario presiona una tecla para continuar

### Postcondiciones
- El usuario visualiza la información de todos los catedráticos

---

## Caso de Uso 10: Consultar Carrera

### Descripción
Permite buscar y visualizar información específica de una carrera.

### Precondiciones
- El usuario ha iniciado sesión
- Existen carreras registradas

### Flujo Principal
1. El usuario selecciona opción 9
2. El sistema solicita el código de la carrera
3. El usuario ingresa el código
4. El sistema busca en carrera.txt
5. Si encuentra el registro, muestra toda la información
6. El usuario presiona una tecla para continuar

### Flujo Alternativo
- Si no encuentra la carrera, muestra mensaje "¡Carrera no encontrada!"

### Postcondiciones
- El usuario visualiza información detallada de la carrera consultada

---

## Caso de Uso 11: Consultar Estudiante

### Descripción
Permite buscar y visualizar información específica de un estudiante.

### Precondiciones
- El usuario ha iniciado sesión
- Existen estudiantes registrados

### Flujo Principal
1. El usuario selecciona opción 10
2. El sistema solicita el carnet del estudiante
3. El usuario ingresa el carnet
4. El sistema busca en estudiante.txt
5. Si encuentra el registro, muestra toda la información
6. El usuario presiona una tecla para continuar

### Flujo Alternativo
- Si no encuentra el estudiante, muestra mensaje "¡Estudiante no encontrado!"

### Postcondiciones
- El usuario visualiza información detallada del estudiante consultado

---

## Caso de Uso 12: Salir del Sistema

### Descripción
Permite cerrar el programa de forma controlada.

### Precondiciones
- El usuario ha iniciado sesión
- Se encuentra en el menú principal

### Flujo Principal
1. El usuario selecciona opción 11
2. El sistema cierra todos los archivos abiertos
3. El sistema finaliza la ejecución

### Postcondiciones
- El programa se cierra correctamente
- Todos los datos quedan guardados en los archivos

---

## Diagrama de Casos de Uso (Texto)

```
+----------------------------------------------------------+
|                  SISTEMA DE GESTIÓN                      |
|                                                          |
|  Usuario -----> (Iniciar Sesión)                        |
|    |                                                     |
|    |-------> (Ingresar Carrera)                         |
|    |-------> (Ingresar Curso)                           |
|    |-------> (Ingresar Estudiante)                      |
|    |-------> (Ingresar Catedrático)                     |
|    |                                                     |
|    |-------> (Reporte de Carreras)                      |
|    |-------> (Reporte de Cursos)                        |
|    |-------> (Reporte de Estudiantes)                   |
|    |-------> (Reporte de Catedráticos)                  |
|    |                                                     |
|    |-------> (Consultar Carrera)                        |
|    |-------> (Consultar Estudiante)                     |
|    |                                                     |
|    +-------> (Salir del Sistema)                        |
|                                                          |
+----------------------------------------------------------+
```

## Relaciones entre Estructuras

```
Carrera (1) ----< (N) Curso
Carrera (1) ----< (N) Estudiante
Curso (1) ----< (N) Catedrático

Donde:
- Una Carrera puede tener muchos Cursos
- Una Carrera puede tener muchos Estudiantes
- Un Curso puede tener muchos Catedráticos
```

## Validaciones del Sistema

1. **Autenticación**
   - Usuario: admin
   - Contraseña: 1234
   - Máximo 3 intentos

2. **Duplicados**
   - No permite códigos de carrera duplicados
   - No permite códigos de curso duplicados
   - No permite carnets duplicados
   - No permite IDs de catedrático duplicados

3. **Archivos**
   - Crea automáticamente archivos si no existen
   - Valida apertura correcta de archivos
   - Muestra mensajes de error si falla lectura/escritura

4. **Entrada de Datos**
   - Limpia buffer después de leer números
   - Permite texto con espacios en nombres
   - Valida tipos de datos numéricos
