
# Presentación Pipeline OpenGL

## Revisando la secuencia completa del temario que estructuramos para tu curso, hemos cubierto con imágenes la columna vertebral del pipeline y varios de sus detalles críticos:

1. **Arquitectura CPU vs GPU** (Baja latencia vs. Cómputo masivo SIMT)


2. **Fase 1 General** (Carga de RAM a VRAM, VBO y VAO)


3. **Fase 1 a Fondo** (Anatomía de memoria y parámetros de `glVertexAttribPointer`)


4. **Fase 1 a Fondo** (El VAO como registrador de estados)


5. **Máquina de Estados de OpenGL** (El panel global de perillas/switches)


6. **Fase 2 General** (Vertex Shader y ejecución en paralelo)


7. **Fase 2 a Fondo** (Las matrices MVP: Modelo, Vista y Proyección)


8. **Fase 3 General** (Primitive Assembly y la regla del triángulo coplanar)


9. **Fase 3 a Fondo** (Face Culling, orden de devanado CCW/CW y descarte)


10. **Fase 4 General** (Rasterización, evaluación de cobertura e interpolación baricéntrica)


11. **Fase 4 a Fondo** (Configuración vía CPU: `glViewport`, `glPolygonMode` y antialiasing)


12. **Fase 5 General** (Fragment Shader, paquetes de datos de fragmentos y coloreado)


13. **Fase 6 General** (Depth Test, Z-Buffer, Blending y Double Buffering con `glfwSwapBuffers`)



## Fases de la Presentación OpenGL Pipeline

1. **Fase 1:** La CPU prepara y sube los datos a la VRAM $\rightarrow$ Nacen los VBOs y VAOs.
2. **Fase 2:** La GPU toma cada vértice en paralelo y calcula su perspectiva 3D $\rightarrow$ Se ejecuta el Vertex Shader.
3. **Fase 3:** El hardware une los vértices para formar caras planas indeformables $\rightarrow$ Se exige el uso exclusivo de triángulos.
4. **Fase 4:** El hardware mapea los triángulos sobre la cuadrícula del monitor $\rightarrow$ Ocurre la Rasterización.
5. **Fase 5:** La GPU colorea e ilumina cada fragmento generado en paralelo $\rightarrow$ Se ejecuta el Fragment Shader.
6. **Fase 6:** Se descartan los elementos ocultos y se escribe en pantalla $\rightarrow$ Ocurre el Depth Test y la salida al Framebuffer.

Con las 6 etapas del pipeline ya cubiertas visual y programáticamente, ¿procedemos a crear la imagen didáctica de **Discretización (Continuo vs. Malla poligonal)** para los antecedentes teóricos de la presentación?


iPara lograr el máximo impacto pedagógico con tus alumnos de ingeniería, el ensamble óptimo sigue una estructura rigurosa de 3 pasos por cada tema: **Concepto clave $\rightarrow$ Infografía de Hardware/Memoria $\rightarrow$ Código esencial en C++/GLSL**.

Aquí tienes el mapa de ensamble completo, organizado en **3 bloques estructurados**, integrando exactamente todas las infografías generadas y los bloques de código:

---

### Bloque I: Fundamentos y Antecedentes Teóricos

1. **Slide 1: Título y Apertura** (Tema: Pipeline Gráfico de OpenGL para Ingeniería).
2. **Slide 2: La Discretización Matemática**
* *Concepto:* De la ecuación continua analítica a la malla poligonal.
* *Infografía:* `La Discretización: Del Continuo a la Malla Poligonal` (Esfera matemática vs. mallas LOD).


3. **Slide 3: Arquitectura de Cómputo (CPU vs. GPU)**
* *Concepto:* Baja latencia y pocos núcleos frente a rendimiento masivo SIMT.
* *Infografía:* `Arquitectura de Cómputo: CPU vs GPU` (Esquema de núcleos, caché y ALUs).


4. **Slide 4: El Modelo de Máquina de Estados de OpenGL**
* *Concepto:* OpenGL como panel de configuración global persistente.
* *Infografía:* `Entendiendo los Estados en OpenGL` (La consola de perillas/switches y el robot de dibujo).



---

### Bloque II: Las 6 Fases del Pipeline (Concepto $\rightarrow$ Imagen $\rightarrow$ Código)

#### Fase 1: Carga de Datos (CPU $\rightarrow$ VRAM)

5. **Slide 5: Fase 1 - Flujo General y Arquitectura**
* *Concepto:* Transferencia vía PCIe y nacimiento de buffers.
* *Infografía:* `Fase 1: Preparación y Carga de Datos (CPU a VRAM)`.


6. **Slide 6: Fase 1 a Fondo - Anatomía de Memoria y Punteros**
* *Concepto:* Desglose milimétrico de bytes, zancada (*stride*) y desplazamiento (*offset*).
* *Infografía:* `Fase 1: Anatomía de Memoria y glVertexAttribPointer`.


7. **Slide 7: Fase 1 a Fondo - El Rol del VAO**
* *Concepto:* El registrador de configuraciones que evita reconfiguraciones por frame.
* *Infografía:* `Fase 1: Entendiendo el VAO (Vertex Array Object)`.


8. **Slide 8: Fase 1 - Código Fuente**
* *Código C++:* `glGenBuffers`, `glBindVertexArray`, `glBufferData` y `glVertexAttribPointer`.



#### Fase 2: Vertex Shader y Transformaciones 3D

9. **Slide 9: Fase 2 - Procesamiento en Paralelo**
* *Concepto:* Ejecución masiva de un hilo por vértice y cálculo de `gl_Position`.
* *Infografía:* `Fase 2: Procesamiento Paralelo y el Vertex Shader`.


10. **Slide 10: Fase 2 a Fondo - La Cadena MVP**
* *Concepto:* Espacio Local $\rightarrow$ Mundo $\rightarrow$ Vista (Cámara) $\rightarrow$ Clip Space.
* *Infografía:* `Las Tres Matrices de Transformación (MVP)`.


11. **Slide 11: Fase 2 - Código Fuente**
* *Código GLSL:* Programa del Vertex Shader (`shader.vert`).
* *Código C++:* Construcción de matrices con GLM y pase de `uniform mat4`.



#### Fase 3: Ensamblado de Primitivas (Primitive Assembly)

12. **Slide 12: Fase 3 - Ensamblado y la Regla del Triángulo**
* *Concepto:* Agrupación de vértices y garantía de coplanaridad indeformable.
* *Infografía:* `Fase 3: Ensamblado de Primitivas (Primitive Assembly)`.


13. **Slide 13: Fase 3 a Fondo - Descarte de Caras Traseras (Face Culling)**
* *Concepto:* Regla de devanado (CCW / CW) y descarte geométrico previo a rasterizar.
* *Infografía:* `Optimización en Fase 3: Descarte de Caras Traseras (Face Culling)`.


14. **Slide 14: Fase 3 - Código Fuente**
* *Código C++:* `glEnable(GL_CULL_FACE)`, `glFrontFace(GL_CCW)` y llamadas de dibujo `glDrawArrays`.



#### Fase 4: Rasterización y Proyección a Pantalla

15. **Slide 15: Fase 4 - De Geometría Continua a Fragmentos Discretos**
* *Concepto:* Pruebas de cobertura de píxeles e interpolación baricéntrica de atributos.
* *Infografía:* `Fase 4: La Rasterización`.


16. **Slide 16: Fase 4 a Fondo - El Espacio Canónico NDC y la Pantalla**
* *Concepto:* Por qué NDC es un cubo 3D $[-1, 1]^3$ y cómo $X, Y$ van a píxeles mientras $Z$ va al buffer.
* *Infografía:* `El Espacio Canónico NDC a la Pantalla de Píxeles`.


17. **Slide 17: Fase 4 a Fondo - Configuración del Rasterizador vía CPU**
* *Concepto:* Control de `glViewport`, modos de polígono (`GL_LINE` / `GL_FILL`) y multisampling.
* *Infografía:* `Configuración de la Rasterización (Vía CPU)`.


18. **Slide 18: Fase 4 - Código Fuente**
* *Código C++:* `glViewport`, `glPolygonMode` y directivas de interpolación en GLSL.



#### Fase 5: Fragment Shader y Sombreado

19. **Slide 19: Fase 5 - El Fragment Shader en Acción**
* *Concepto:* Paquete de datos del fragmento, cálculo de textura/iluminación y descarte anticipado.
* *Infografía:* `Fase 5: El Fragment Shader y los Fragmentos`.


20. **Slide 20: Fase 5 - Código Fuente**
* *Código GLSL:* Programa del Fragment Shader con texturizado, `discard` e iluminación básica.
* *Código C++:* Enlace de unidades de textura (`glActiveTexture`, `glBindTexture`).



#### Fase 6: Pruebas por Muestra y Framebuffer

21. **Slide 21: Fase 6 - Depth Test y Doble Búfer**
* *Concepto:* Comparación de profundidad $Z$, pruebas de oclusión, mezcla (*blending*) y `glfwSwapBuffers`.
* *Infografía:* `Fase 6: Depth Test y Salida al Framebuffer`.


22. **Slide 22: Fase 6 - Código Fuente**
* *Código C++:* `glEnable(GL_DEPTH_TEST)`, configuración de `glBlendFunc`, `glClear` y ciclo de refresco.



---

### Bloque III: Síntesis y Cierre

23. **Slide 23: Resumen del Pipeline Completo** (Cuadro sinóptico de entradas, salidas y responsables CPU/GPU).
24. **Slide 24: Conclusión y Preguntas** (Cierre formal de la sesión).

---

¿Te parece adecuada esta distribución secuencial de 24 diapositivas para proceder a compilar la presentación interactiva?



## Compilación de la presentación
Voy a compilar la presentación completa en un único archivo HTML autocontenido con las dimensiones estándar de 1280×720 para cada diapositiva. Integraré la estructura exacta solicitada: portada institucional, diapositivas teóricas de antecedentes con sus diagramas, y cada una de las 6 fases estructurada rigurosamente en la tríada: Teoría en viñetas $\rightarrow$ Infografía didáctica $\rightarrow$ Bloques de código fuente.


