# Ejercicio 1
- 2,269.745 MB
- Si (Disco Duro)
- Si (USB)
- Si (RAM)

# Ejercicio 2
Tiempos para generar votos aleatorios:
- ./gen 7000 out  0.02s user 0.01s system 93% cpu 0.023 total
- ./gen 70000 out  0.09s user 0.01s system 98% cpu 0.105 total
- ./gen 700000 out  0.72s user 0.06s system 94% cpu 0.821 total
- ./gen 7000000 out  6.59s user 0.28s system 94% cpu 7.280 total

- El servidor soporta aproximadamente 63 peticiones por segundo

# Ejercicio 3
¿Sería aceptable en esta aplicación utilizar un **timestamp** que solo incluya la variable segundos $\texttt{time_t}$?
- No porque incrementa la probabilidad de que se repita un identificador.

¿Existe la posibilidad de que el servidor devuelva un **timestamp** repetido a dos votantes distintos?
- Con microsegundos podria existir una diminuta probabilidad de que se repita.

¿Por qué es necesario en esta aplicación distribuida el uso de la función $\texttt{fsync()}$ después de ejecutar la función $\texttt{write}$ en el lado del servidor?
- Para que la base de datos no se descincronice.

# Ejercicio 4
¿Cuál fue el tiempo que tardó en enviar las 10000 votaciones con validación?
- 3m30.514s

¿Cuál fue el tiempo que tardó en enviar las 10000 votaciones sin validación?
- 2m15.341s

¿Es posible en los casos A y B atender a setenta millones de votos en el periodo de doce horas?
- No es posible porque tomaría 408 horas en el primer caso y 265 horas en el segundo.

¿En qué proporción irá creciendo el tiempo de respuesta en el servidor conforme aumenta el número de votos (pruebe con 5,000 y 20,000 votos e infiera)?
- Con validación tardó 2m0s para enviar 5,000 votos y 10m para enviar 20,000. El tiempo es proporcional a $O(n \log n)$.
- Sin validación tardó 1m08s para enviar 5,000 votos y 4m30s para enviar 20,000. El tiempo es proporcional a $O(n)$.

# Ejercicio 5
Con el uso del trie, ¿cuánto tiempo tardó en enviar 10,000 votos?
- Tardó 2m30s

¿Cuánto tardaría en procesar 70 millones de votos?
- 291 horas aproximadamente

¿Cuánto espacio de memoria RAM ocupa con 10,000 votos?
- 332 kB

¿Cuánto espacio de memoria RAM ocupa con los 70 millones de votos?
- 2.2 GB
