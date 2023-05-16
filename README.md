<h1>Diferent-Search</h1>

<h2>O Problema</h2>

<p style = "text-align = justify">
Esse projeto tem como desafio a implementação de três formas diferentes de caminhar pela matriz de entrada, aleatoriamente, fazendo uma busca em largura e fazendo uma busca em profundidade. Aqui surge a seguinte questão: como fazer tais caminhamentos?, desta pergunta nasce todas as outras discuções a respeito das contruções desenvolvidas neste projeto.
</p>


<h2>Desenvolvimento do Problema</h2>

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
</ul>

<p style = "text-align = justify">
A memória é um recurso utilizado pelo Sistema Operacional para manter informações pertinentes a uma aplicação acessiveis para serem manipuladas, e causar algum efeito em uma aplicação em que o usuário requeriu, porem a mesma é um recurso limitado, e em aplicações com uso de uma grande quantidade de informações essa memória pode não suportar a necessidade de espaço necessária para o programa realizar suas operações, com isso uma alternativa que visa aproveitar esse espaço de maneira inteligente é o uso de alocação dinâmica dos espaços para colocar tal massa de dados.Sendo assim neste projeto foi utilizado diferentes estruturas em virtude do problema fornecido apenas algumas estruturas se adequam para atender as execuções a serem feitas para que os algoritmos sejam executados da maneira correta, no decorrer desta documentação será possível entender isso de forma mais clara, visto que vai ser mostrado que não seria possível fazer o algoritmo fornecer a saída correta se não fossem utilizado as estruturas de dados que foram utilizadas, em resumo a resposta para o primeiro questionamento é que essas estruturas são dinâmicas que não possuem alocação sequencial na memória, o que pode trazer um maior custo de acesso do dado na memória, mas que contornará o erro de segmentation fault que pode vir ocorrer com uma estrutura linear, supondo que fosse alocado um vetor de 2000 casas de maneira linear, a memória vai ser separada pelo Sistema Operacional de maneira sequencial, ou seja cada endereço do vetor vai estar logo após ao atual fisicamente na memória, o que não ocorre na alocação dinâmica da memória, o que ocorre é que o Sistema Operacional separa espaços de memória aleatoriamente na RAM para alocar as informações o que aumenta o tempo de leitura do dado, mas minimiza o problema de conflito que ocorre com a estrutura dinâmica, e torna o algoritmo um pouco mais tolerante a erros.
</p>

<p style = "text-align = justify">
Para caminhar de maneira aleatória pela matriz de entrada foi utilizado um recurso da biblioteca time, que é a função rand que seleciona um valor dentro de um intervalo determinado pelo programador e determina um número com base desse intervalo pegando como base no tempo em segundos desde 1 de Janeiro de 1970 até os tempos atuais. E utilizando a técnica de utilizar um escopo maior, o qual foi extraido do <a href="https://github.com/mpiress/GenerateDataToMaze">algoritmo de geração de matrizes</a> do Michel Pires de número do que apenas dois números ou 0 ou 1 para somar ou subtrair para mudar a linha e a coluna e fazer o algoritmo mudar de posição até que seja encontrado a interrogação, o qual se faz o parametro de parada para o algoritmo
</p>
