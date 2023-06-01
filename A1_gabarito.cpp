#include <iostream>

// Questão 1:
struct Node {
    int data;
    Node *next;
};

void insert(Node *head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Função auxiliar para imprimir a lista (não era necessário)
void printList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Questão 2:
void remove(Node *head, int data) {
    Node *current = head;
    // Ponteiro 'previous' armazena informação do nó anterior no loop, 
    // para reajustar o ponteiro do nó anterior para que aponte ao próximo nó 
    // (o next do que foi deletado) corretamente
    Node *previous = nullptr;
    while (current != nullptr) {
        if (current->data == data) {
            if (previous == nullptr) {
                head = current->next;  // Ajuste no caso onde a head da lista é deletada
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Questão 3:
Node* switchFirstLast(Node *head) {
    Node *current = head;
    Node *previous = nullptr;    // Ponteiro para o nó anterior ao último nó, para reajustar seu ponteiro next
    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }
    previous->next = head;       // Faz o penúltimo nó apontar para o antigo primeiro
    current->next = head->next;  // Faz o antigo último nó apontar para o segundo nó
    head->next = nullptr;        // Faz o antigo primeiro nó apontar para null (já que agora é o último)
    return current;              // Retorna o antigo último nó como a nova head (já que ele aponta ao segundo nó)
}

// Questão 4:
Node* getIntersection(Node *head1, Node *head2) {
    Node *head = (Node*)malloc(sizeof(Node));
    Node *current1 = head1;
    Node *current2 = head2;
    while (current1 != nullptr) {
        while (current2 != nullptr) {
            if (current1->data == current2->data) {
                insert(head, current1->data);
            }
            current2 = current2->next;
        }
        current1 = current1->next;
        current2 = head2;  // Reinicia o ponteiro da lista 2 para seu nó inicial
    }
    return head->next;  // Pois a head é um nó vazio
}

// Questão 5:
// Função auxiliar para deletar a lista e liberar uso de memória 
void deleteEntireList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        Node *previous = current;
        current = next;
        free(previous);
    }
}

// Função auxiliar para checar, na inserção em uma lista, 
// se um nó com o mesmo dado já existe nela
bool insertWithRepetitionCheck(Node *head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->next = nullptr;

    Node *current = head;
    bool result = false;
    while (current->next != nullptr) {
        if (current->data == data) {  // Checa se já existe um nó com o mesmo dado na lista
            result = true;
        }
        current = current->next;
    }

    if (current->data == data) {  // Checa o último nó da lista, que não é checado no loop while
        result = true;
    }
    current->next = newNode;
    return result;
}

// Para checar repetição, cria uma lista auxiliar e insere nela os dados da lista original,
// checando se já existe um nó com o mesmo dado na lista auxiliar para cada inserção
bool CheckRepetition(Node *head) {
    Node *dummy = (Node*)malloc(sizeof(Node));  // Cria um nó vazio para ser a head de uma lista auxiliar
    Node *current = head;
    while (current != nullptr) {
        if (insertWithRepetitionCheck(dummy, current->data)) {
            deleteEntireList(dummy);
            return true;
        }
        current = current->next;
    }
    deleteEntireList(dummy);
    return false;
}

// Questão EXTRA:
int CheckCycleSize(Node *head) {
    Node *dummy = (Node*)malloc(sizeof(Node));  // Cria um nó vazio para ser a head de uma lista auxiliar
    Node *current = head;
    int repeated_value;
    bool repeated = false;
    while (current != nullptr) {
        if (insertWithRepetitionCheck(dummy, current->data)) {
            repeated_value = current->data;
            repeated = true;
            break;
        }
        current = current->next;
    }

    if (repeated == false) {
        deleteEntireList(dummy);
        return 0;
    }

    int size = 0;
    current = dummy->next;
    bool cycle_started = false;
    while (current->next != nullptr) {
        // Checa se o nó atual é a primeira aparição do valor repetido, 
        // ou seja, se o ciclo começou
        if (current->data == repeated_value) {   
            cycle_started = true;
        }
        // Se o ciclo já começou, incrementa o tamanho do ciclo
        if (cycle_started) {
            size++;
        }
        current = current->next;
    }

    deleteEntireList(dummy);
    return size;
}

int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 100000;
    for (int i = 0; i < 9; i++) {
        insert(head, 100001+i);
    }

    printList(head);
    std::cout << "Após deletar o nó com data = 100001:" << std::endl;
    remove(head, 100001);
    printList(head);
    std::cout << "Após trocar o primeiro e o último nó de posição:" << std::endl;
    head = switchFirstLast(head);
    printList(head);

    std::cout << "Após deletar alguns outros nós:" << std::endl;
    for (int i = 0; i < 5; i++) {
        remove(head, 100000+2*i);
    }
    printList(head);

    std::cout << "Gerando uma outra lista:" << std::endl;
    Node *head2 = (Node*)malloc(sizeof(Node));
    head2->data = 100000;
    for (int i = 0; i < 9; i++) {
        insert(head2, 100003+2*i);
    }
    printList(head2);

    std::cout << "Após gerar a interseção das duas listas:" << std::endl;
    Node *intersection = getIntersection(head, head2);
    printList(intersection);

    std::cout << "Após inserir um nó com dado repetido:" << std::endl;
    insert(intersection, 100003);
    insert(intersection, 100008);
    printList(intersection);

    std::cout << "Checando se há repetição na lista:" << std::endl;
    bool result = CheckRepetition(intersection);
    std::cout << result << std::endl;

    std::cout << "Checando o tamanho do ciclo na lista:" << std::endl;
    int size = CheckCycleSize(intersection);
    std::cout << size << std::endl;
}
