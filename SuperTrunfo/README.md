# SuperTrunfo

Autores: Jo�o Emmanuel e Thales Renan

# Sobre o jogo

SuperTrunfo � um jogo baseado em turnos, onde cada jogador come�a com n cartas cada um e logo ap�s isso o jogador da vez selecionar uma carta e um atributo que ser� comparado com as cartas dos outros jogadores da mesa, ao final o jogador ganhador levar� todas as cartas que estiverem sido colocadas na mesa. O jogo acaba quando resta apenas um jogador na mesa com todas as cartas.


# Como compilar

Para compilar o SuperTrunfo use:
```
g++ -Wall -std=c++11 -I include src/main.cpp src/class.cpp -o bin/SuperTrunfo
```
Depois execute com:
```
./bin/SuperTrunfo
```

# Parametros de linha de comando

Para executar use .bin/SuperTrunfo mas ser� necessario informar 3 parametros que s�o:
1 - Arquivo onde est�o as defini��es das cartas (normalmente na pasta data)
2 - N�mero de jogadores da mesa
3 - N�mero de cartas que cada jogador ter� no come�o

Ex: .bin/SuperTrunfo data/cards.dat 3 4 
No exemplo a cima o jogo come�ar� com 3 jogadores e cada um com 4 cartas na m�o

# Lista dos t�picos estudados 
- Classes em c++
- Leitura de arquivo
- Algumas bibliotecas dadas em aula

# Implementa��es futuras
O jogo poder� ter uma IA simples para o jogador selecionar a sua melhor carta para jogar
Interface gr�fica para visualiza��o das rodadas.
