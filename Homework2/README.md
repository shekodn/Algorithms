#TAREA #2
El objetivo de esta tarea es que repases algunos de los conceptos básicos de programación y estructuras de datos a través de un ejercicio de programación, y que comiences a relacionar esto con la técnica de análisis de algoritmos que estamos aprendiendo en el curso. Específicamente, repasarás y pondrás en práctica los conceptos de archivos texto en C++, búsqueda y Hashing. Por otro lado, esta tarea es también una oportunidad para que aprendas y uses las herramientas más básicas de STL en caso de que no las conozcas.

**CASO A RESOLVER**
---
Se requiere un programa que sirva para BUSCAR UN DATO en un archivo de texto. El contexto de aplicación será considerando que se requiere saber si una matrícula de un alumno del Tec, pertenece o no a un egresado EXATEC. El programa pedirá al usuario la matrícula a buscar e indicará si ésta es de un egresado EXATEC o no. El programa permitirá buscar tantas matrículas como el usuario desee. Las matrículas serán manejadas como números enteros (sin anteponer A0). Para realizar este proceso, el programa utilizará un archivo que contiene las matrículas de los egresados a considerar (en la realidad, en el Tec hay más de 200 mil EXATECs, pero el archivo de prueba que se te proporciona será una simulación con miles de datos). Este archivo contiene una matrícula por renglón, y las matriculas aparecen en forma aleatoria (no ordenadas). El archivo deberá cargarse a memoria una sola vez al iniciar la ejecución del programa, y las búsquedas se realizarán sobre la estructura de datos en que se guarden.

Como puedes observar, el caso es un simple problema de búsqueda, y puede ser resuelto de múltiples formas. Para esta tarea, tomaremos 3 propuestas de solución, las implementaremos y las evaluaremos con las herramientas de análisis de algoritmos que estás aprendiendo.


**Propuesta de solucion #1**
---
Cargar los datos del archivo en un arreglo de enteros, y realizar la búsqueda secuencial de la matrícula directamente sobre el arreglo, comparando dato por dato hasta encontrarlo, o bien, hasta llegar al final del arreglo sin encontrarlo. Este algoritmo simplemente va accesando en el arreglo dato por dato, haciendo la comparación y desechándolos mientras no se encuentre la matrícula que se busca. Define el tamaño del arreglo con un valor constante que puedas adaptar en el código dependiendo de la cantidad de datos que tenga el archivo de datos con el que se hará la prueba.
 
**Propuesta de solucion #2**
---
Cargar todos los datos del archivo en un vector de STL, ordenar los datos por medio del algoritmo de ordenamiento que provee STL, y finalmente realizar la búsqueda de la matrícula, pero aplicando el proceso de la búsqueda binaria sobre el vector ya ordenado.

**Propuesta de solucion #3**
---
Cargar todos los datos del archivo en una tabla de hash y aplicar la búsqueda sobre la tabla. La tabla debe ser implementada con las siguientes condiciones:
 La tabla será un arreglo estático de 1000 posiciones.
 La función de hashing a utilizar es una función que selecciona a los últimos 3 dígitos de la matrícula como valor de posición
en la tabla.

 Se utilizará encadenamiento externo para administrar las colisiones. Los datos de cada posición en la tabla serán
almacenados en una lista de STL, considerando el orden de llegada, es decir, NO será una lista ordenada. La búsqueda implicará una búsqueda secuencial aleatoria en la lista.
