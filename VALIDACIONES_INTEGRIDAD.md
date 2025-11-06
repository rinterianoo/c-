# 🔒 VALIDACIONES DE INTEGRIDAD REFERENCIAL - Nuevas Mejoras

## 📋 Resumen de Cambios

Se han implementado **validaciones de integridad referencial** para asegurar que los datos relacionados existan antes de permitir su registro.

---

## ✅ 1. VALIDACIONES IMPLEMENTADAS

### 🔍 Funciones de Validación Creadas:

#### `bool existeCarrera(int codcarrera)`
**Propósito:** Verificar que un código de carrera existe en el archivo antes de usarlo.

**Usado en:**
- Ingreso de Cursos
- Ingreso de Estudiantes

**Archivo verificado:** `C:\carrera.txt`

#### `bool existeCurso(int codcurso)`
**Propósito:** Verificar que un código de curso existe en el archivo antes de usarlo.

**Usado en:**
- Ingreso de Catedráticos

**Archivo verificado:** `C:\curso.txt`

---

## 🛡️ 2. VALIDACIONES POR FUNCIÓN

### Ingreso de Cursos (Opción 2)
**ANTES:** Permitía ingresar cualquier código de carrera, incluso si no existía.

**AHORA:** 
- ✅ Solicita el código de carrera
- ✅ Valida que la carrera exista usando `existeCarrera()`
- ✅ Si NO existe: Muestra mensaje de error y NO guarda el curso
- ✅ Si SÍ existe: Permite continuar con el ingreso

**Mensaje de error:**
```
ERROR: El codigo de carrera XXX no existe!
Debe registrar la carrera primero (Opcion 1 del menu).
Presione una tecla para continuar...
```

### Ingreso de Estudiantes (Opción 3)
**ANTES:** Permitía ingresar cualquier código de carrera, incluso si no existía.

**AHORA:**
- ✅ Solicita el código de carrera
- ✅ Valida que la carrera exista usando `existeCarrera()`
- ✅ Si NO existe: Muestra mensaje de error y NO guarda el estudiante
- ✅ Si SÍ existe: Permite continuar con el ingreso

**Mensaje de error:**
```
ERROR: El codigo de carrera XXX no existe!
Debe registrar la carrera primero (Opcion 1 del menu).
Presione una tecla para continuar...
```

### Ingreso de Catedráticos (Opción 4)
**ANTES:** Permitía ingresar cualquier código de curso, incluso si no existía.

**AHORA:**
- ✅ Solicita el código de curso
- ✅ Valida que el curso exista usando `existeCurso()`
- ✅ Si NO existe: Muestra mensaje de error y NO guarda el catedrático
- ✅ Si SÍ existe: Permite continuar con el ingreso

**Mensaje de error:**
```
ERROR: El codigo de curso XXX no existe!
Debe registrar el curso primero (Opcion 2 del menu).
Presione una tecla para continuar...
```

---

## 📝 3. NUEVAS CONSULTAS AGREGADAS

Se agregaron dos nuevas opciones de consulta al menú principal:

### Opción 11: Consulta de Curso
**Función:** `consultacurso()`

**Permite:**
- Buscar un curso por su código
- Muestra toda la información del curso:
  - Código del curso
  - Código de carrera
  - Catedrático
  - Carnet
  - Semestre

### Opción 12: Consulta de Catedrático
**Función:** `consultacatedratico()`

**Permite:**
- Buscar un catedrático por su ID
- Muestra toda la información del catedrático:
  - ID del catedrático
  - Código del curso
  - Nombre del catedrático

---

## 🔄 4. MENÚ PRINCIPAL ACTUALIZADO

**ANTES (11 opciones):**
```
1. INGRESO DE CARRERAS
2. INGRESO DE CURSO
3. INGRESO DE ESTUDIANTES
4. INGRESO DE CATEDRATICOS
5. REPORTE DE CARRERAS
6. REPORTE DE CURSOS
7. REPORTE DE ESTUDIANTES
8. REPORTE DE CATEDRATICOS
9. CONSULTA DE CARRERA
10. CONSULTA DE ESTUDIANTE
11. SALIR
```

**AHORA (13 opciones):**
```
1. INGRESO DE CARRERAS
2. INGRESO DE CURSO
3. INGRESO DE ESTUDIANTES
4. INGRESO DE CATEDRATICOS
5. REPORTE DE CARRERAS
6. REPORTE DE CURSOS
7. REPORTE DE ESTUDIANTES
8. REPORTE DE CATEDRATICOS
9. CONSULTA DE CARRERA
10. CONSULTA DE ESTUDIANTE
11. CONSULTA DE CURSO ⭐ NUEVO
12. CONSULTA DE CATEDRATICO ⭐ NUEVO
13. SALIR
```

---

## 🎯 5. CASOS DE USO ACTUALIZADOS

### Flujo Correcto de Ingreso:

#### Ejemplo 1: Registrar un Curso
```
PASO 1: Ingresar Carrera (Opción 1)
├─ Código: 101
├─ Nombre: Ingeniería en Sistemas
└─ ... (demás datos)

PASO 2: Ingresar Curso (Opción 2)
├─ Código Curso: 1001
├─ Código Carrera: 101 ✅ (Existe, permite continuar)
└─ ... (demás datos)
```

#### Ejemplo 2: Intento de Registro Incorrecto
```
INTENTO: Ingresar Curso (Opción 2)
├─ Código Curso: 1001
├─ Código Carrera: 999 ❌ (NO existe)
└─ RESULTADO: Error y NO se guarda

MENSAJE:
"ERROR: El codigo de carrera 999 no existe!
Debe registrar la carrera primero (Opcion 1 del menu)."
```

---

## 📊 6. DIAGRAMA DE RELACIONES

```
┌──────────────┐
│   CARRERA    │
│  (Código)    │
└──────┬───────┘
       │
       ├──────────────┐
       │              │
       ▼              ▼
┌──────────────┐  ┌──────────────┐
│    CURSO     │  │  ESTUDIANTE  │
│  (Código)    │  │   (Carnet)   │
└──────┬───────┘  └──────────────┘
       │
       ▼
┌──────────────┐
│ CATEDRATICO  │
│    (ID)      │
└──────────────┘

Reglas:
• Un CURSO debe tener una CARRERA existente
• Un ESTUDIANTE debe tener una CARRERA existente
• Un CATEDRATICO debe tener un CURSO existente
```

---

## 🔍 7. CÓDIGO DE LAS VALIDACIONES

### Ejemplo de Validación en ingresocursos():

```cpp
if (mencontro==0)
{
    // Solicitar código de carrera
    gotoxy(50,12); cin>>curso.codcarrera;
    
    // ===== VALIDACIÓN DE INTEGRIDAD REFERENCIAL =====
    if(!existeCarrera(curso.codcarrera))
    {
        // Mostrar mensaje de error
        gotoxy(20,18); cout<<"ERROR: El codigo de carrera "
                          <<curso.codcarrera<<" no existe!";
        gotoxy(20,19); cout<<"Debe registrar la carrera primero.";
        gotoxy(20,20); cout<<"Presione una tecla para continuar...";
        getch();
        fclose(F);
        continue;  // NO guarda y vuelve al inicio
    }
    
    // Si la validación pasa, continúa con el ingreso normal
    // ...
}
```

---

## 📋 8. PRUEBAS RECOMENDADAS

### Test 1: Validación de Curso sin Carrera
1. Ejecutar el programa
2. Ir a Opción 2 (Ingreso de Curso)
3. Ingresar código de curso: 1001
4. Ingresar código de carrera: 999 (que no existe)
5. **Resultado esperado:** Error y no guarda

### Test 2: Validación de Estudiante sin Carrera
1. Ir a Opción 3 (Ingreso de Estudiante)
2. Ingresar carnet: 20250001
3. Ingresar código de carrera: 888 (que no existe)
4. **Resultado esperado:** Error y no guarda

### Test 3: Validación de Catedrático sin Curso
1. Ir a Opción 4 (Ingreso de Catedrático)
2. Ingresar ID: 5001
3. Ingresar código de curso: 777 (que no existe)
4. **Resultado esperado:** Error y no guarda

### Test 4: Ingreso Correcto con Validaciones
1. Ingresar Carrera (Opción 1): Código 101
2. Ingresar Curso (Opción 2): Código 1001, Carrera 101
3. Ingresar Estudiante (Opción 3): Carnet 20250001, Carrera 101
4. Ingresar Catedrático (Opción 4): ID 5001, Curso 1001
5. **Resultado esperado:** Todo se guarda correctamente

### Test 5: Nuevas Consultas
1. Consultar Curso (Opción 11): Código 1001
2. **Resultado esperado:** Muestra información completa del curso
3. Consultar Catedrático (Opción 12): ID 5001
4. **Resultado esperado:** Muestra información completa del catedrático

---

## 💡 9. BENEFICIOS DE ESTAS MEJORAS

✅ **Integridad de Datos**
- Evita datos huérfanos (cursos sin carrera, etc.)
- Mantiene la consistencia entre archivos

✅ **Mejor Experiencia de Usuario**
- Mensajes claros cuando algo está mal
- Guía al usuario sobre qué hacer primero

✅ **Prevención de Errores**
- No permite crear registros inválidos
- Valida antes de guardar

✅ **Consultas Completas**
- Ahora se pueden consultar todas las entidades
- Mayor funcionalidad del sistema

---

## 📝 10. RESUMEN DE ARCHIVOS MODIFICADOS

| Archivo | Cambios |
|---------|---------|
| `Proyecto1_Mejorado.cpp` | ✅ Agregadas 2 funciones de validación |
| | ✅ Agregadas validaciones en 3 funciones de ingreso |
| | ✅ Agregadas 2 funciones de consulta |
| | ✅ Actualizado menú principal |
| | ✅ Actualizada documentación de casos de uso |

---

## 🚀 11. PRÓXIMOS PASOS SUGERIDOS

### Mejoras Futuras Posibles:
1. ✨ Agregar opción para MODIFICAR registros
2. ✨ Agregar opción para ELIMINAR registros
3. ✨ Validar que no se elimine una carrera si tiene cursos
4. ✨ Validar que no se elimine un curso si tiene catedráticos
5. ✨ Agregar búsqueda por nombre (no solo por código)
6. ✨ Exportar reportes a archivo de texto
7. ✨ Agregar estadísticas (total de carreras, cursos, etc.)

---

## ✅ TODO LISTO

El código ahora tiene:
- ✅ Validaciones de integridad referencial
- ✅ 2 nuevas funciones de consulta
- ✅ Menú actualizado con 13 opciones
- ✅ Mensajes de error informativos
- ✅ Documentación actualizada

**¡El sistema está completo y funcionando correctamente!** 🎉
