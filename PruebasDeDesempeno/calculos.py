import math

MAX = 1e8
i = 1

seno = 0
coseno = 0
tangente = 0
logaritmo = 0
raizCuadrada = 0

while i < MAX:
	seno += math.sin(i)
	coseno += math.cos(i)
	tangente += math.tan(i)
	logaritmo += math.log(i)
	raizCuadrada += math.sqrt(i)
	i += 1
