#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
trab CPS
Jorge Pereira - 12063
MESI
Estudo realizado com um computador com as seguintes caracteristicas:
Processador Intel Core2 Duo T6500 @ 2.10GHz
4GB DDR2
Windows 7 64bit
'''
import math
import time
import random

# Funcao que efectua a troca de dois valores
# Obtida em http://www.openbookproject.net/thinkcs/python/english2e/ch11.html
def swap(a, b):
    temp = a
    a = b
    b = temp

time1 = time.clock() # inicio da contagem

T = [] # Tabela(array) T inicializada sem elementos
x = 0
digits = [0 for x in range(10)] # Array digits que vai permitir contar e limitar o numero de digitos, de 0 a 9, a 100.
print digits
while x < 1000:
    r = random.randint(0,9) # digitos gerados aleatoriamente de 0 a 9 (http://docs.python.org/library/random.html)
    if(digits[r] < 100): # condicao que verifica se já existem 100 elementos da tabela com digitos de 0 a 9
        digits[r] += 1 # incrementa o numero se nao existirem
        T.append(r) # e adiciona na tabela T
        x += 1 # incrementa o valor de x para gerar menos 1 numero
        pass
    pass

p = random.randint(0,999) # p é gerado aleatoriamente

for j in range(pow(2,9)): # vamos considerar um numero de 8 bits (256)
    if(p<1000):
        z1=T[p]
        swap(T[p], T[0])
    else:
        z1=T[0]

    if(p<999):
        z2=T[p+1]
        swap(T[p+1], T[0])
    else:
        z2=T[0]    

    if(p<998):
        z3=T[p+2]
        swap(T[p+2], T[0])
    else:
        z3=T[0]    

    if(p<997):
        z4=T[p+3]
        swap(T[p+3], T[0])
    else:
        z4=T[0]

    # calculo de n
    n = (z1 << 12) | (z2 << 8) | (z3 << 4) | z4

    # calculo de p
    p = z1 * pow(10, 2) + z2 * pow(10, 1) + z3 * 10

    # output dos numeros aleatorios gerados
    print 'j:',j, '|', 'n', n, '|', 'p =', p    
    pass

time2 = time.clock() # termino da contagem do tempo da geração dos numeros aleatorios
print 'tempo total: ', time2 - time1, ' segundos'
