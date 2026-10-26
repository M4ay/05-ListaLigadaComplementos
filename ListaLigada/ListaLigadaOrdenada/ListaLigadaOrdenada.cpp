#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	
	// Tarefa 5 -----
	// Aloque o novo nó e leia seu valor.
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	// Crie dois ponteiros auxiliares
	NO* atual = primeiro;
	NO* anterior = NULL;

	// Use um laço while para encontrar a posição correta. 
	// Dentro do laço, avance os ponteiros.
	while (atual != NULL && atual->valor < novo->valor)
	{
		anterior = atual;
		atual = atual->prox;
	}

	// Verifique se o elemento já existe. 
	// Se sim, informe o usuário e libere a memória do novo nó.
	if (atual != NULL && atual->valor == novo->valor)
	{
		cout << "Elemento ja existe na lista." << endl;
		free(novo);
		return;
	}

	// Caso contrário
	// Se anterior == NULL: significa que a lista estava vazia... 
	if (anterior == NULL)
	{
		primeiro = novo; //... ou o novo elemento deve ser o primeiro.
	}

	else // Senão (anterior != NULL)
	{
		// O elemento será inserido no meio ou no fim
		anterior->prox = novo;
	}

	// Finalmente, conecte o resto da lista
	novo->prox = atual;
}

void excluirElemento()
{
	int numero;

	// Tarefa 7 -----
	// Peça o número a ser excluído.
	cout << "Digite o elemento a ser excluido: ";
	cin >> numero;

	NO* atual = primeiro;
	NO* anterior = NULL;

	// Use a mesma lógica de travessia com anterior e atual da inserção ordenada para encontrar o elemento.
	while (atual != NULL && atual->valor < numero)
	{
		anterior = atual;
		atual = atual->prox;
	}

	// Se durante a busca atual->valor se tornar maior que o número procurado, você já sabe que o elemento não existe. 
	if (atual == NULL || atual->valor != numero)
	{
		// Informe o usuário e encerre a função.
		cout << "Elemento nao encontrado." << endl;
		return;
	}

	// Se encontrar o elemento, realize a exclusão tratando os dois casos clássicos.
	
	// O elemento é o primeiro (anterior == NULL)
	if (anterior == NULL)
	{
		primeiro = atual->prox;
	}

	// O elemento está no meio ou no fim (anterior != NULL)
	else
	{
		anterior->prox = atual->prox;
	}

	// Não se esqueça de usar free(atual) para liberar a memória do nó excluído.
	free(atual);
	cout << "Elemento excluido." << endl;
}

void buscarElemento()
{
	int numero;

	// Tarefa 6 -----
	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;

	// Percorra a lista com um ponteiro aux.
	NO* aux = primeiro;
	while (aux != NULL)
	{
		// Se aux->valor == numero, encontrou. Exiba "ENCONTRADO" e saia da função.
		if (aux->valor == numero)
		{
			cout << "ENCONTRADO" << endl;
			return;
		}
		// Se aux->valor > numero, não encontrado. Exiba "ELEMENTO NAO ENCONTRADO" e saia da função.
		if (aux->valor > numero)
		{
			// Se o laço terminar, significa que o número não foi encontrado.
			cout << "ELEMENTO NAO ENCONTRADO" << endl;
			return;
		}
		aux = aux->prox;
	}
