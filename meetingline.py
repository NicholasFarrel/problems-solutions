#este problema quer x tal que max(ti + |a[i] - x|) seja mínimo, ou seja, que o tempo para a reunião começar seja mínimo
#para isso, vamos tentar descobrir T, o tempo mínimo que todos levam para se encontrar, assim, podemos construir x
        #Tome um determinado T
        #Seja d[i] o tempo máximo que a pessoa i leva para VIAJAR até x => d[i] = T - t[i]
        #logo, dada uma pessoa a[i], sabemos que x está no intervalo a[i] - d[i], a[i] + d[i]
        #imagine o vetor intervalo[i] = [x[i] - d[i], x[i] + d[i]] = [x[i] + t[i] - T, x[i] - t[i] + T]
        #se todos estes intervalos possuírem interseção, temos que é possível todos chegarem em tempo t aos pontos da interseção

        #se temos intervalos (a1, b1), (a2, b2), ...., (an, bn) e ak = max(ai) e bk = min(bi):
            #todos possuem interseção (ak, bk) se e somente se ak <= bk


t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    t = list(map(int, input().split()))

    #setar a resposta como seu mínimo possível
    T = max(t)
    
    #achar o maior começo de intervalo
    a = max(x[i] + t[i] - T for i in range(n))

    #achar o maior final de intervalo
    b = min(x[i] - t[i] + T for i in range(n))

    #cada vez que eu aumento 'e' em T, tenho que a diminui em 'e' e b aumenta em 'e'
    #então cada vez que o tempo aumenta 'e', a e b se aproximam simetricamente, logo, se encontrarão no ponto médio entre a e b = (a + b) / 2

    print((a + b)/2)



