# Pruebas Desempeño

Para medir el tiempo utilizar `time` en sistema linux antes de ejecutar el programa, e.g:

```bash
time ./output

real    0m29.969s
user    0m29.016s
sys     0m0.109s
```
## Tiempo de ejecución

| Programa       | C             | C++   | Java  | Python|
| -------------  |:-------------:|:-----:|:-----:|:-----:|
| Busqueda Cadena| 0.03          | 0.05  | 2.39  | 0.92  |
| Calculo        | 8.52          | 8.21  | 14.57 | 104.05|

Tabal 1. Tiempo medido en segundos

## Veces mas Rápido

| Programa       | C             | C++   | Java  | Python|
| -------------  |:-------------:|:-----:|:-----:|:-----:|
| Busqueda Cadena| 1             | 1.66  | 79.66 | 30.66 |
| Calculo        | 1.03          | 1     | 1.77  | 12.67|

Tabla 2. La referencia tiene 1 como valor, siendo el mas rápido, como se puede observar en la tabla 1.