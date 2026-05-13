#include <iostream>
#include <conio.h>
using namespace std;

struct cidades{
	int codigo;
	char nome[30];
	char UF[2];
};

struct clientes{
	int codigo;
	char nome[30];
	char endereco[30];
	char telefone[15];
	int codigo_cidade;
};

struct veiculos{
	char placa[8];
	char modelo[20];
	char marca[15];
	int ano;
	int codigo_cliente;
};

struct servicos{
	int codigo;
	char descricao[50];
	float valor_mao_de_obra;
};

struct pecas{
	int codigo;
	char descricao[50];
	int quant_estoque;
	int estoque_minimo;
	int estoque_maximo;
	int preco_unitario;
};

struct mecanicos{
	int codigo;
	char nome[30];
	char especialidade[30];
	char telefone[15];
};

struct ordem_de_servico{
	int codigo;
	char placa_veiculo[10];
	int codigo_mecanico;
	char data[10];
	int codigo_servico;
	int codigo_peca;
	int quantidade_peca;
};

void ler_cidades(cidades cidade[], int &qtdCidades){
	for (int i = 0; i < qtdCidades; i++){
        cout << "\n\nCodigo da Cidade " << (i+1) << ": ";
        cin >> cidade[i].codigo;
        cout << "Nome: ";
        cin >> cidade[i].nome;
        cout << "Estado: ";
        cin >> cidade[i].UF;
	}
}

void ler_servicos(servicos servico[], int &qtdServicos){
	for (int i = 0; i < qtdServicos; i++){
        cout << "\n\nCodigo do Servico " << (i+1) << ": ";
        cin >> servico[i].codigo;
        cout << "Descricao: ";
        cin >> servico[i].descricao;
        cout << "Valor Mao de Obra: ";
        cin >> servico[i].valor_mao_de_obra;
	}
}

void ler_pecas(pecas peca[], int &qtdPecas){
	for (int i = 0; i < qtdPecas; i++){
        cout << "\n\nCodigo da Peca " << (i+1) << ": ";
        cin >> peca[i].codigo;
        cout << "Descricao: ";
        cin >> peca[i].descricao;
        cout << "Quantidade em Estoque: ";
        cin >> peca[i].quant_estoque;
        cout << "Estoque Minimo: ";
        cin >> peca[i].estoque_minimo;
        cout << "Estoque Maximo: ";
        cin >> peca[i].estoque_maximo;
        cout << "Preco Unitario: ";
        cin >> peca[i].preco_unitario;
	}
}

//2) Escreva uma funcao para permitir a inclusao de novos registros na tabela de Clientes.
//2.1) O programa devera garantir que o codigo do cliente a ser inserido não existe na tabela de Clientes.
//2.2) Quando o usuario digitar o codigo da cidade, o programa devera buscar este codigo na tabela de Cidades e exibir o nome da cidade e UF.
void inc_clientes(clientes cliente[], int &qtdClientes){ 
	
}

//3) Escreva uma funcao para permitir a inclusao de novos registros na tabela de Veiculos.
//3.1) O programa devera garantir que a placa do veiculo a ser inserido nao existe na tabela de Veiculos.
//3.2) Quando o usuario digitar o codigo do cliente, o programa devera buscar este codigo na tabela de Clientes e exibir o nome do cliente.
void inc_veiculos(veiculos veiculo[], int &qtdVeiculos){
	
}

void inc_mecanicos(mecanicos mecanico[], int &qtdMecanicos){
	
}

void abrir_ordem_servico(ordem_de_servico ordem_servico[], int &qtdOrdens){
	
}

void consulta_pecas(pecas peca[], int &qtdPecas){
	
}

void exibir_pecas_abaixo_minimo(pecas peca[], int &qtdPecas){
	
}

void arrecadacao_ordens(ordem_de_servico ordem_servico[], int &qtdOrdens){
	
}

int main(){
	cidades cidade[10];
	clientes cliente[10];
	veiculos veiculo[10];
	servicos servico[10];
	pecas peca[10];
	mecanicos mecanico[10];
	ordem_de_servico ordem_servicos[10];
	
	int qtdCidades = 0,  qtdClientes = 0,  qtdVeiculos = 0,  qtdServicos = 0,  qtdPecas = 0,  qtdMecanicos = 0,  qtdOrdens = 0;
	
	int opcao = 0;
	
	
	do{
	cout<<"MENU - OFICINA MECANICA" << endl;
	cout<<"\n1 - Ler Cidades";
	cout<<"\n2 - Ler Servicos";
	cout<<"\n3 - Ler Pecas";
	cout<<"\n4 - Inclusao de Novos Registros na Tabela Clintes";
	cout<<"\n5 - Inclusao de Novos Registros na Tabela Veiculos";
	cout<<"\n6 - Inclusao de Novos Registros na Tabela Mecanicos";
	cout<<"\n7 - Abertura de uma Ordem de Servico";
	cout<<"\n8 - Consultar Dados de Determinada Peca";
	cout<<"\n9 - Exibir Pecas Abaixo do Estoque Minimo";
	cout<<"\n10 - Valor Arrecadado com Todas Ordens de Servico";
	cout<<"\n0 - Sair";
	
	cout<<"Digite a opcao desejada: ";
	cin>>opcao;
	
		switch(opcao){
			case 1:
				ler_cidades(cidade, qtdCidades);
			break;
		
		
			case 2:
				ler_servicos(servico, qtdServicos);
			break;	
		
		
			case 3:
				ler_pecas(peca, qtdPecas);
			break;	
		
		
			case 4:
				inc_clientes(cliente, qtdClientes);
			break;
			
		
			case 5:
				inc_veiculos(veiculo, qtdVeiculos);
			break;
				
		
			case 6:
				inc_mecanicos(mecanico, qtdMecanicos);
			break;
				
		
			case 7:
				abrir_ordem_servico(ordem_servicos, qtdOrdens);
			break;	
			
		
			case 8:
				consulta_pecas(peca, qtdPecas);
			break;	
			
		
			case 9:
				exibir_pecas_abaixo_minimo(peca, qtdPecas);
			break;
				
		
			case 10:
				arrecadacao_ordens(ordem_servicos, qtdOrdens);
			break;	
		}
	}
	while(opcao != 0);
	
	return 0;
}

