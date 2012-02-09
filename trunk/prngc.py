# !/usr/bin/env python
# −∗− coding:utf−8 −∗−
'''
trab CPS
Jorge Pereira - 12063
MESI
Implementação de um gerador de numeros pseudo-aleatorios, implementada
com o objectivo de associar a simplicidade da sintaxe da linguagem Python
com a eficiencia da linguagem C.
Estudo realizado num computador com as seguintes caracteristicas:
Processador Intel Core2 Duo T6500 @ 2.10GHz
4GB DDR2
Windows 7 64bit
***** TESTES *****
qtd elementos -> tempo(s):
1000 -> 0.00
10000 -> 0.00
100000 -> 0.01
1000000 -> 0.04
10000000 -> 0.50
*******************
Os valores obtidos são iguais aos da implementacao em C.
'''
import sys
from ctypes import *

libcprng = CDLL( "./libcprng.so" )

if len(sys.argv)> 1:
    cprng = libcprng.prng(int(sys.argv[1]))
else:
    print "Nao foi fornecido o numero de elementos a gerar!"
    print "Utilizacao: python prngc.py <qtd elementos a gerar>"
