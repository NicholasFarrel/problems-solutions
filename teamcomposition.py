#este problema em si é bem simples, o que realmente é interessante, é a prova da solução.
#primeiro, vejamos as ideias enquanto resolvemos, ao final apresento a prova.
t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    #nossa resposta será o mínimo entre os valores a, b e o piso da divisão de (a + b) por 4
    ans = min (a, b, (a + b) // 4)
    print(ans)


#imagine que acabamos de decidir todos os grupos de 4, de maneira optimal (quantidade máxima) e que sobraram alguns colegas de trabalho sem equipe 

#CASO1
    #se sobraram 0, 1, 2 ou 3 pessoas, como conseguimos distribuir o restante precisamente em grupos de 4
    #temos que o total de grupos neste caso foi exatamente (a + b) // 4 (obrigatoriamente este também é o máximo atingível nessa situação)

#CASO2
    #se sobraram x >= 4 pessoas, sabemos que todas elas tem que ter a mesma carreira (se temos 2 carreiras diferentes neste conjunto, podemos formar grupo, o que gera absurdo)
    #agora, se é possível trocar um dos 4 programadores(sem perda de generalidade) por algum matemático de um grupo já montado, 
    #temos então 4 pessoas ( 3 p + 1 m) para formar mais um grupo (o que implicaria que nossa distribuição inicial não era optimal, gerando absurdo)
    #Logo, se não é possível trocar, quer dizer que cada um dos grupos montados possui apenas um matemático (não podemos colocar programador em seu lugar),
    #assim, total de grupos = total de matemáticos, e obviamente |matemáticos| < |programadores| (pois a cada grupo temos 1 m e 3 p)
    #Neste Caso2 o resultado seria o número de matemáticos

#dos casos 1, 2 vimos que MaxGrupos = min(a, b, (a + b) // 4)