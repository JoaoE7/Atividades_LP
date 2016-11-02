# SuperTrunfo

Autores: João Emmanuel e Thales Renan

# Sobre o jogo

SuperTrunfo é um jogo baseado em turnos, onde cada jogador começa com n cartas cada um e logo após isso o jogador da vez selecionar uma carta e um atributo que será comparado com as cartas dos outros jogadores da mesa, ao final o jogador ganhador levará todas as cartas que estiverem sido colocadas na mesa. O jogo acaba quando resta apenas um jogador na mesa com todas as cartas.


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

Para executar use .bin/SuperTrunfo mas será necessario informar 3 parametros que são:
1 - Arquivo onde estão as definições das cartas (normalmente na pasta data)
2 - Número de jogadores da mesa
3 - Número de cartas que cada jogador terá no começo

Ex: .bin/SuperTrunfo data/cards.dat 3 4 
No exemplo a cima o jogo começará com 3 jogadores e cada um com 4 cartas na mão

# Lista dos tópicos estudados 
- Classes em c++
- Leitura de arquivo
- Algumas bibliotecas dadas em aula

# Implementações futuras
O jogo poderá ter uma IA simples para o jogador selecionar a sua melhor carta para jogar
Interface gráfica para visualização das rodadas.
