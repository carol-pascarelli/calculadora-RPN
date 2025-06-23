#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_INPUT 256

typedef struct {
    float dados[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, float valor) {
    if (p->topo < MAX - 1) {
        p->dados[++(p->topo)] = valor;
    } else {
        exit(EXIT_FAILURE);
    }
}

float pop(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[(p->topo)--];
    } else {
        exit(EXIT_FAILURE);
    }
}

int ehNumero(char *token) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        return 1;
    }
    return 0;
}

float avaliaRPN(char *expr) {
    Pilha p;
    inicializaPilha(&p);
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (ehNumero(token)) {
            push(&p, atof(token));
        } else {
            float b = pop(&p);
            float a = pop(&p);
            float res;
            if (strcmp(token, "+") == 0) res = a + b;
            else if (strcmp(token, "-") == 0) res = a - b;
            else if (strcmp(token, "x") == 0) res = a * b;
            else if (strcmp(token, "/") == 0) res = a / b;
            else exit(EXIT_FAILURE);
            push(&p, res);
        }
        token = strtok(NULL, " ");
    }
    return pop(&p);
}

int main() {
    char input[MAX_INPUT];
    printf("Digite a expressao em RPN:\n");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    float resultado = avaliaRPN(input);
    printf("Resultado: %.2f\n", resultado);
    return 0;
}
