import random

n = 17576 * 10
m = 3
resultado = ""
for i in range(n):
  palabra = ""
  for n in range(m):
    palabra += chr(random.randint(ord('A'), ord('Z')))
  if i:
    resultado += " "
  resultado += palabra

apariciones = resultado.count("IPN")
print("Apariciones de IPN: ", apariciones)
