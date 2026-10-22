#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

// Tarefa 1 -----
// Adicionar o ponteiro "ultimo"
NO* primeiro = NULL;
NO* ultimo = NULL;

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

	// Tarefa 2 -----
	// Ao limpar a lista, o ponteiro ultimo também deve ser resetado para NULL.
	primeiro = NULL;
	ultimo = NULL;
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
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	// Tarefa 3 -----
	if (primeiro == NULL) // Se a lista estiver vazia
	{
		// O primeiro e o ultimo recebem novo
		primeiro = novo;
		ultimo = novo;
	}
	else // Caso contrário
	{	
		ultimo->prox = novo; // ultimo->prox aponta para novo.
		ultimo = novo; // ultimo é atualizado para novo.
	}
}

// Tarefa 4 -----
// Modifique sua função de exclusão da atividade anterior. 
// O que acontece com o ponteiro ultimo se o usuário excluir o elemento que está no final da lista? 
// Você precisará encontrar o penúltimo nó para que ele se torne o novo ultimo.
void excluirElemento()
{
	int valor;
	cout << "Digite o elemento a ser excluido: ";
	cin >> valor;

	NO* atual = primeiro;
	NO* anterior = NULL;

	// Percorre a lista para encontrar o elemento
	while (atual != NULL && atual->valor != valor)
	{
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL)
	{
		cout << "O elemento nao foi encontrado." << endl;
		return;
	}

	if (anterior == NULL)
	{
		// Excluindo o primeiro elemento
		primeiro = atual->prox;
		if (primeiro == NULL)
		{
			ultimo = NULL; // Lista vazia
		}
	}
	else
	{
		anterior->prox = atual->prox;
		if (atual == ultimo)
		{
			// O penultimo vira o ultimo
			ultimo = anterior;
		}
	}

	free(atual);
	cout << "Elemento excluido." << endl;
}

void buscarElemento()
{
	int valor;
	cout << "Digite o elemento a ser buscado: ";
	cin >> valor;

	NO* aux = primeiro;
	while (aux != NULL)
	{
		if (aux->valor == valor)
		{
			cout << "Elemento encontrado." << endl;
			return;
		}
		aux = aux->prox;
	}
	cout << "Elemento nao encontrado." << endl;
}