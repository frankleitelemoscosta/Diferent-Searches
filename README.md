# Diferent-Search

# O Problema

<p style = "text-align = justify">
Esse projeto tem como desafio a implementação de três formas diferentes de caminhar pela matriz de entrada, aleatoriamente, fazendo uma busca em largura e fazendo uma busca em profundidade. Aqui surge a seguinte questão: como fazer tais caminhamentos?, desta pergunta nasce todas as outras discuções a respeito das contruções desenvolvidas neste projeto.
</p>

# Regras sobre o caminhamento

No labirinto (matriz) fornecido para o caminhamento existem 3 possíveis casos:
* Caso # : representa uma parede local onde não se pode caminhar e impede o código de prosseguir por este caminho.
* Caso 1 : representa uma casa onde se é possível caminhar sem nenhuma outra consequência.
* Caso * : representa um perigo, casas onde contém perigos não devem ser evitadas pelo código porém, sempre que o mesmo pisar em uma casa contendo perigo o mesmo retornará para o inicio do labirinto e esquecerá todas as casas exploradas
</p>
Deve-se ressaltar que em caso do código encontrar um perigo, o mesmo sumirá se transformando em um local onde se é possível andar sem quaisquer outras consequência (Caso 1).
</p>

# Desenvolvimento do Problema

<p style = "text-align = justify">
Para resolver o problema foi necessário trazer respostas aos seguintes questionamentos:
</p>

<ul>
    <li>
        Se for necessário entrar com uma grande quantidade de dados, qual estrutura de dados será capaz de suportar tal massa de dados?
    </li>
    <li>
        Como fazer o programa caminhar de maneira aleatória pela matriz de entrada?
    </li>
    <li> Tendo utilizado a matriz para desenvolver um dos métodos de busca, o que tem de ser feito para que se reinicie os dados desse matriz para que se tenha os dados da matriz de entrada?
    <li>
        Como fazer o programa caminhar pela matriz usando o método busca em profundidade?
    </li>
    <li>
        Como fazer o programa caminhar pela matriz usando o método de busca em largura?
    </li>
</ul>

# Lógica Implementada 

## Problemas relacionados a memória

<p style = "text-align = justify">
A memória é um recurso utilizado pelo Sistema Operacional para manter informações pertinentes a uma aplicação acessiveis para serem manipuladas, e causar algum efeito em uma aplicação em que o usuário requeriu, porem a mesma é um recurso limitado, e em aplicações com uso de uma grande quantidade de informações essa memória pode não suportar a necessidade de espaço necessária para o programa realizar suas operações, com isso uma alternativa que visa aproveitar esse espaço de maneira inteligente é o uso de alocação dinâmica dos espaços para colocar tal massa de dados.Sendo assim neste projeto foi utilizado diferentes estruturas em virtude do problema fornecido apenas algumas estruturas se adequam para atender as execuções a serem feitas para que os algoritmos sejam executados da maneira correta, no decorrer desta documentação será possível entender isso de forma mais clara, visto que vai ser mostrado que não seria possível fazer o algoritmo fornecer a saída correta se não fossem utilizado as estruturas de dados que foram utilizadas, em resumo a resposta para o primeiro questionamento é que essas estruturas são dinâmicas que não possuem alocação sequencial na memória, o que pode trazer um maior custo de acesso do dado na memória, mas que contornará o erro de 'segmentation fault' que pode vir ocorrer com uma estrutura linear, supondo que fosse alocado um vetor de 2000 casas de maneira linear, a memória vai ser separada pelo Sistema Operacional de maneira sequencial, ou seja cada endereço do vetor vai estar logo após ao atual fisicamente na memória, o que não ocorre na alocação dinâmica da memória, o que se tem é o Sistema Operacional separando espaços de memória aleatoriamente na RAM para alocar as informações o que aumenta o tempo de leitura do dado, mas minimiza o problema de conflito que ocorre com a estrutura linear, e torna o algoritmo um pouco mais tolerante a erros.
</p>

<a href = "https://pt.wikipedia.org/wiki/Ponteiro_(programa%C3%A7%C3%A3o)"><img src="./img/Miranha-e-as-ras.jpg" width = 100% alt="Miranha interpretando um ponteiro"></a>

## Caminhamento de maneira aleatória

<p style = "text-align = justify">
Para caminhar de maneira aleatória pela matriz de entrada foi utilizado um recurso da biblioteca time, que é a função rand que seleciona um valor dentro de um intervalo determinado pelo programador e determina um número com base nesse intervalo pegando como base o tempo em segundos desde 1 de Janeiro de 1970 até os tempos atuais. E utilizando a técnica de usar um escopo maior de números, o qual foi extraido do <a href="https://github.com/mpiress/GenerateDataToMaze">GenerateDataToMaze</a> do Michel Pires de número maior do que apenas dois números sendo 0 ou 1 para somar ou subtrair para mudar a linha e a coluna e fazer o algoritmo mudar de posição até que seja encontrado a interrogação, o qual se faz o parametro de parada para o algoritmo, o problema que foi observado foi este:
</p>

<img src="./img/dois-numeros.png" width = 30% alt="imagem com dois números">

<p style = "text-align = justify">
Inicialmente foi utilizado a função <i>rand()%2</i> o que vai decidir um número de 0 a 1, ou seja, seria retornado 0 ou 1, isso seria perfeito se o método de escolha da biblioteca time não tendece tanto a repetir um mesmo resultado quando se tem um número menor de possibilidades, nesse caso seria apenas duas possibilidades, e se mostrou ineficiente visto que era retornado muitas vezes apenas uma das possibilidades, porem quando foi apresentado um escopo maior de números como mostra a imagem abaixo: 
</p>

<img src="./img/range-com-muitos-numeros.png" width = 80% alt="imagem do range com mais de 20 num">

<p style = "text-align = justify">
Assim o intervalo agora para que fosse decidido entre 0 ou 1 é maior, aumentando o número de possibilidades e tornando o algorítmo um pouco mais randômico.
</p>

<p style = "text-align = justify">
Na medida que se foi sendo decidido o valor retornado, que tambem contava com o valor -1, pois estamos considerando que vamos caminhar em todas as direções possiveis foi sendo verificado se tinha chegado até uma posição onde a interrogação estava, sendo assim o que ocorreu foi que a cada iteração do algoritmo foi sendo somado um, subtraido um ou permanecendo com o mesmo valor da linha ou coluna que no caso do algoritmo ocorria quando se somava zero a linha ou coluna, e verificado a toda alteração os respectivos indices que foram sendo obtidos, tomando as devidas verificações para que também não houvesse estouro de memória ao acessar posições inexistentes que ultrapassavam os limites da matriz de entrada, alem de evitar as paredes. 
</p>

## Caminhamento em profundidade (DFS): 

<p style = "text-align = justify">
O algoritmo de caminhamento em profundidade vem da ideia de examinar uma direção até não ser possível mais caminhar pela mesma, no nosso caso o parametro de parada são paredes ou os limites da matriz, ou seja, se acaso se deparar com esta situação o programa tem de redecidir para onde deve ir.
</p>

<img src="./img/image (1).png" width = 40% alt="Miranha e as paredes">

<p style = "text-align = justify">
Um caso especial trouxe a necessidade de usar uma estrutura de dados, visto que se nos deparassemos com a situação onde o programa caminhasse até uma posição cercada de paredes, e como a casa antecessora já foi visitada, não podemos tomar a direção da mesma, sendo assim foi necessário usar uma pilha e ir empilhando as posições passadas, e quando chegassemos nessa situação basta ir desempilhando as posições e verificando os vizinhos até que fosse possível encontrar uma direção possível de caminhar.Tendo resolvido estes problemas, consegue-se realizar uma busca em profundidade por uma matriz qualquer de entrada, dando fim a pergunta inicial de como usar o método de caminhamento em profundidade.
</p>

<img src="./img/miranha-e-as-paredes.png" width = 40% alt="Miranha e as paredes">

## Caminhamento em Largura (BFS): 

<p style = "text-align = justify">
A ideia do caminhamento em largura faz juz ao nome que recebeu, a ideia é literalmente realizar uma verificação aos vizinhos da posição corrente, o que se observado iteração a iteração é possivel perceber que as posições visitadas dão a percepção de que se "desenha" a largura da matriz. O BFS começa a partir de um vértice inicial e visita todos os vértices vizinhos desse vértice antes de se mover para os vértices vizinhos dos vizinhos. Esse processo continua até que todos os vértices alcançáveis tenham sido visitados, veja:
</p>


<img src="./img/BFS-visita.jpeg" width = 35% alt="BFS">

</br>

<img src="./img/BFS.jpeg" width = 35% alt="BFS">

<p style = "text-align = justify">
    Para auxilio no caminhamento da matriz da maneira em largura, utilizamos a estrutura de dados Fila (queue), para manter o controle dos vertices que devem ou já foram visitados, com finalidade de não repetir caminhos previamente analisados.
</p>

# Análise de tempo de Execução

<img src="./img/dados empiricos do programa com todos os métodos.png" width = 90% alt="Dados empiricos">

<p style = "text-align = justify">
Esta captura mostra o tempo de execução do algoritmo com os três métodos de caminhamento sendo executados simultaneamente, fazendo uma média destes resultados teremos que na maoiria dos casos este algoritmo termina em 0,022847 segundos.Fazendo uma análise separada teremos diferenças significativas com relação ao tempo de execução do algoritmo,  veja:
</p>

<img src="./img/performace-rodando-o-algoritmo-com-uma-50-por-50.png" width = 90% alt="Dados empiricos">


# Conclusões

<p style = "text-align = justify">
Diante dos diferentes cenários de busca aqui relatados é possível perceber que de acordo com a forma que se busca um dado teremos um tempo distinto até chegarmos a um determinado resultado, alem de não ser esperado podemos ter um tendenciamento a determinada conduta apesar de não ser esperado ser assim, como se mostrou o algoritmo de busca em profundidade, Dos três métodos aqui discutidos e apresentados conseguimos determinar custo apenas para dois deles, visto que não conseguimos fazer previsões com relação a entrada no algoritmo de bernoulli, não sabemos quais são a quantidade máxima de passos que serão realizados, sendo assim temos uma grande variação do tempo quando executamos o algoritmo randomico, veja:
</p>

<p style = "text-align = justify">
porem ainda sim é possível inferir quais serão a quantidade de passos realizados pela máquina até que a interrogação seja encontrado para os outros dois métodos, veja que os tempos de execução mostram uma pequena variação:
</p>

<p style = "text-align = justify">
Portanto observando as estruturas aqui utilizadas a forma com que se busca um dado pode mudar muito não só no aspecto da implementação, mas tambem no custo que pode ser gerado para a máquina executar tal busca, variando não só com o tamanho da entrada, mas tambem com relação a organização dos dados, pois de acordo com o lugar que a interrogação se encotrava, ou a quantidade de perigos que o algoritmo passava, o tempo de execução muda.
</p>

# Instruções de Compilação do Programa

<p style = "text-align = justify">
Este projeto esta utilizando um arquivo de configuração, este arquivo possui comandos que poderiam ser rodados em terminal para executar o programa, porem tal arquivo é utilizado com o objetivo de diminuir a necessidade de usar grandes diretivas, para compilar, limpar ou rodar o programa, para realizar tais ações esse make file se utiliza dos comandos: 

<table border="1">
      <tr><td><u>gcc (nome dos arquivos) -o  (nome do executável)</u></td></tr>
      <tr><td><u>rm -rf (nome do executável)</u></td></tr>
      <tr><td><u>./(nome do executável)</u></td></tr>
</table>

</p>

<p>
    <i>Este código possui um arquivo Makefile que facilita a compilação e execução do programa</br>As diretrizes de execução deste
    Make file são:<i>
    <table border="1">
      <tr><td><u>make clean</u></td> <td>Apaga a última compilação realizada contida na pasta build</td></tr>
      <tr><td><u>make</u></td> <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build.</td></tr>
      <tr><td><u>make run</u></td> <td>Executa o programa da pasta build após o programa já estar compilado </td></tr>
    </table>
    <i>Para a execução do programa utilize <u>make</u> para realizar a compilação e logo após utilize <u>make run</u> para executar o programa</i>
</p>

# Referencias
CORMEN, Thomas H. Algoritmos: Teoria e Prática. 3. ed. Rio de Janeiro: Editora Elsevier, 2012.

# Autores

Frank Leite Lemos Costa, Leandro Sousa Costa, João Pedro Freitas alunos de Engenharia da Computação no <a href = "https://www.cefetmg.br/">CEFET</a>, 3° período.

<table>
    <tr>
        <td align = "center" width="50%">
            <a href="https://www.linkedin.com/in/frank-leite-6a6a84198/"><img src="./img/linkedin.png" alt="" style="width: 50% "></a>
        </td>
        <td align = "center">
            <a href = "https://wa.me/+5531996449587"><img src="./img/whatsapp.png" alt="" style="width: 50% "></a>
        </td>
    </tr>
    <tr>
        <td align = "center" width="50%">
            Linkedin
        </td>
        <td align = "center">
            +55(31) 99644-9587
            <p>Click na foto do whatsapp você será redirecionado diretamente a um chat comigo</p>
        </td>
    </tr>
</table>
