# 📂 EXPLICACIÓN DE RUTAS DE ARCHIVOS

## 📍 ¿Dónde se guardan los archivos del programa?

### **RUTA ACTUAL:** `C:\` (Raíz del disco C)

Los archivos se guardan en:
```
C:\carrera.txt       ← Información de carreras
C:\curso.txt         ← Información de cursos  
C:\estudiante.txt    ← Información de estudiantes
C:\catedratico.txt   ← Información de catedráticos
```

---

## 🔍 ¿Cómo verificar si los archivos se crearon?

### Opción 1: Explorador de Windows
1. Abre el Explorador de Windows (`Win + E`)
2. En la barra de dirección escribe: `C:\`
3. Busca los archivos:
   - `carrera.txt`
   - `curso.txt`
   - `estudiante.txt`
   - `catedratico.txt`

### Opción 2: Desde PowerShell
```powershell
# Ver si existen los archivos
ls C:\*.txt

# O específicamente:
Test-Path C:\carrera.txt
Test-Path C:\curso.txt
Test-Path C:\estudiante.txt
Test-Path C:\catedratico.txt
```

### Opción 3: Desde CMD
```cmd
dir C:\*.txt
```

---

## 📖 Explicación de la ruta `c:\\`

### ¿Por qué doble diagonal invertida (`\\`)?

En C++, la barra invertida `\` es un **carácter de escape**, por lo que necesitas escribirla doble:

```cpp
// ❌ INCORRECTO - No funciona
fopen("c:\carrera.txt", "r");

// ✅ CORRECTO - Funciona
fopen("c:\\carrera.txt", "r");

// ✅ ALTERNATIVA - También funciona (barra normal)
fopen("c:/carrera.txt", "r");
```

### Desglose de la ruta:

```
"c:\\carrera.txt"
  │   │        │
  │   │        └─ Nombre del archivo
  │   └─ Doble barra (escape de \)
  └─ Unidad C
```

---

## 🔧 ¿Cómo cambiar la ruta de guardado?

### Para guardar en otra ubicación, modifica estas líneas en la función `crear()`:

#### Ejemplo 1: Guardar en el Escritorio
```cpp
// Usuario: HP
fopen("C:\\Users\\HP\\Desktop\\carrera.txt", "r");
```

#### Ejemplo 2: Guardar en una carpeta específica
```cpp
// Primero debes crear la carpeta "DatosUniversidad" en C:\
fopen("C:\\DatosUniversidad\\carrera.txt", "r");
```

#### Ejemplo 3: Guardar en la misma carpeta del programa
```cpp
// Usa ruta relativa (punto significa "carpeta actual")
fopen(".\\carrera.txt", "r");
// o simplemente:
fopen("carrera.txt", "r");
```

#### Ejemplo 4: Guardar en otra unidad (D:, E:, etc.)
```cpp
fopen("D:\\MisArchivos\\carrera.txt", "r");
```

---

## 📝 Código completo para cambiar la ruta

### UBICACIÓN EN EL CÓDIGO:
**Líneas:** Aproximadamente 240-290 (función `crear()`)

### BUSCA ESTAS LÍNEAS Y MODIFÍCALAS:

```cpp
void crear()
{
	// ===== CAMBIAR ESTA RUTA =====
	Fcarrera = fopen("c:\\carrera.txt", "r");  // ← LÍNEA A MODIFICAR
	if(!Fcarrera)
	{
		Fcarrera = fopen("c:\\carrera.txt", "w");  // ← LÍNEA A MODIFICAR
		// ... resto del código
	}
	// ... (repetir para los otros 3 archivos)
}
```

### EJEMPLO DE MODIFICACIÓN (Guardar en D:\Universidad\):

```cpp
void crear()
{
	// ===== CARRERA =====
	Fcarrera = fopen("D:\\Universidad\\carrera.txt", "r");
	if(!Fcarrera)
	{
		Fcarrera = fopen("D:\\Universidad\\carrera.txt", "w");
		printf("\nArchivo creado en D:\\Universidad\\carrera.txt");
	}
	// ... etc.
}
```

**⚠️ IMPORTANTE:** Si cambias a otra carpeta, debes:
1. **Crear la carpeta primero** (ej: `D:\Universidad\`)
2. **Cambiar la ruta en TODAS las funciones** (crear, ingreso, reporte, consulta)

---

## 🔍 ¿Dónde más aparece la ruta en el código?

La ruta `c:\\archivo.txt` aparece en **TODAS estas funciones**:

### 1. Función `crear()` (línea ~240)
```cpp
fopen("c:\\carrera.txt", "r");
fopen("c:\\curso.txt", "r");
fopen("c:\\estudiante.txt", "r");
fopen("c:\\catedratico.txt", "r");
```

### 2. Función `ingresocarreras()` (línea ~300)
```cpp
F=fopen("c:\\carrera.txt","r+");
```

### 3. Función `ingresocursos()` (línea ~360)
```cpp
F=fopen("c:\\curso.txt","r+");
```

### 4. Función `ingresoestudiantes()` (línea ~420)
```cpp
F=fopen("c:\\estudiante.txt","r+");
```

### 5. Función `ingresocatedraticos()` (línea ~470)
```cpp
F=fopen("c:\\catedratico.txt","r+");
```

### 6. Función `reportecarreras()` (línea ~530)
```cpp
F=fopen("c:\\carrera.txt","r");
```

### 7. Función `reportecursos()` (línea ~580)
```cpp
F=fopen("c:\\curso.txt","r");
```

### 8. Función `reporteestudiantes()` (línea ~630)
```cpp
F=fopen("c:\\estudiante.txt","r");
```

### 9. Función `reportecatedraticos()` (línea ~680)
```cpp
F=fopen("c:\\catedratico.txt","r");
```

### 10. Función `consultacarrera()` (línea ~740)
```cpp
F=fopen("c:\\carrera.txt","r");
```

### 11. Función `consultaestudiante()` (línea ~790)
```cpp
F=fopen("c:\\estudiante.txt","r");
```

---

## 🛠️ Herramienta: Buscar y Reemplazar

### Para cambiar TODAS las rutas de una vez:

En VS Code:
1. Presiona `Ctrl + H` (Buscar y reemplazar)
2. En "Buscar": `c:\\carrera.txt`
3. En "Reemplazar con": `TU_NUEVA_RUTA\\carrera.txt`
4. Click en "Reemplazar todo"
5. Repetir para curso.txt, estudiante.txt, catedratico.txt

---

## 📊 Modos de apertura de archivos

| Modo | Significado | Uso en el programa |
|------|-------------|-------------------|
| `"r"` | **Read** (Lectura) | Verificar si existe, consultas, reportes |
| `"w"` | **Write** (Escritura) | Crear archivo nuevo (¡BORRA contenido!) |
| `"r+"` | **Read/Write** (Lectura y escritura) | Buscar Y agregar datos |
| `"a"` | **Append** (Agregar al final) | No usado en este programa |

### Ejemplo en el código:

```cpp
// Modo "r" - Solo lectura (para verificar)
F=fopen("c:\\carrera.txt","r");

// Modo "w" - Escritura (crear archivo)
F=fopen("c:\\carrera.txt","w");

// Modo "r+" - Lectura y escritura (buscar y agregar)
F=fopen("c:\\carrera.txt","r+");
```

---

## ❓ Preguntas Frecuentes

### 1. **¿Por qué no veo los archivos en C:\?**
- Puede que no tengas permisos
- Ejecuta el programa como Administrador
- O cambia la ruta a tu carpeta de usuario

### 2. **¿Los archivos son de texto normal?**
- **NO**, son archivos **binarios**
- No puedes abrirlos con Notepad y leerlos
- Contienen estructuras de C++ en formato binario

### 3. **¿Cómo ver el contenido de los archivos?**
- Usa las opciones de **REPORTE** del programa (opciones 5-8)
- O usa las opciones de **CONSULTA** (opciones 9-10)

### 4. **¿Qué pasa si borro los archivos?**
- Pierdes todos los datos
- Al ejecutar el programa nuevamente, se crearán vacíos

### 5. **¿Puedo tener el programa en una carpeta y los datos en otra?**
- **SÍ**, solo cambia las rutas en el código
- Ejemplo: programa en Desktop, datos en Documents

---

## 📌 Recomendación

### **Para un proyecto escolar/universitario:**

Cambia la ruta a tu carpeta de usuario:

```cpp
// En lugar de c:\\carrera.txt, usa:
"C:\\Users\\HP\\Documents\\Universidad\\carrera.txt"

// Primero crea la carpeta:
// C:\Users\HP\Documents\Universidad\
```

### **Ventajas:**
✅ No necesitas permisos de administrador  
✅ Fácil acceso desde el explorador  
✅ Puedes hacer backup fácilmente  
✅ Más organizado  

---

## 📚 Resumen

| Aspecto | Valor |
|---------|-------|
| **Ruta actual** | `C:\` |
| **Archivos creados** | carrera.txt, curso.txt, estudiante.txt, catedratico.txt |
| **Formato** | Binario (no texto plano) |
| **Modo creación** | "w" (write) |
| **Modo ingreso** | "r+" (read/write) |
| **Modo reporte** | "r" (read) |
| **Total de ocurrencias** | ~24 veces en el código |

---

## 🎯 Próximos pasos

1. ✅ Compila el programa
2. ✅ Ejecútalo
3. ✅ Ingresa algunos datos
4. ✅ Verifica que los archivos se crearon en `C:\`
5. ✅ Si quieres cambiar la ruta, usa buscar/reemplazar

¡Ya sabes todo sobre las rutas de archivos del programa! 🚀
