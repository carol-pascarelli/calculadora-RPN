# calculadora-RPN

&emsp; Esta atividade tem como intuito uma implementação simples de uma calculadora RPN usando C e aplicando alguns conceitos de pilha. A calculadora lê uma expressão matemática no formato RPN, avalia e imprime o resultado no terminal.

## Objetivo

* Ler uma expressão RPN da entrada padrão (ex. 3 4 + 5 x)
* Separar os números e os operadores 
* Usar uma pilha para armazenar os operandos 
* Avaliar a expressão seguindo a lógica RPN
* Imprimir o resultado final


## Código explicado 

### 1. TAD Pilha
O código define um TAD (Tipo Abstrato de Dados) para a pilha com as seguintes operações:
- `inicializaPilha()`
- `push(pilha, valor)`
- `pop(pilha)`
- `estaVazia(pilha)`

### 2. Leitura da Expressão
A entrada do usuário é lida como uma string única, depois é separada em tokens usando `strtok()`.

### 3. Avaliação
Para cada token:
- Se for número → é convertido para `float` e empilhado
- Se for operador (`+`, `-`, `x`, `/`) → desempilha dois valores, aplica a operação e empilha o resultado

### 4. Resultado
Ao final da expressão, o topo da pilha contém o resultado, que é impresso na tela.


## Como executar 

&emsp; Clone o repositório deste projeto, entre na pasta e execute 

**gcc main.c -o main** 

para compilar o código e em seguida 

**./main**

&emsp; Após isso, digite uma expressão em RPN (ex. 3 4 + 5 x) e cheque o resultado (resultado esperado do exemplo: 35.00)
