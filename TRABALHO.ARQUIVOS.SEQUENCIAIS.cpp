#include <iostream>
#include <conio.h>
#include <cstring>
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

void ler_cidades(cidades cidade[], int qtdCidades){
	for (int i = 0; i < qtdCidades; i++){
        cout << "\n\nCodigo da Cidade " << (i+1) << ": "<< cidade[i].codigo;
        cout << "\nNome: "<< cidade[i].nome;
        cout << "\nEstado: "<<cidade[i].UF<< endl;
	}
}

void ler_servicos(servicos servico[], int qtdServicos){
	for (int i = 0; i < qtdServicos; i++){
        cout << "\n\nCodigo do Servico " << (i+1) << ": ";
        cin >> servico[i].codigo;
        cout << "\nDescricao: ";
        cin >> servico[i].descricao;
        cout << "\nValor Mao de Obra: "<< endl;
        cin >> servico[i].valor_mao_de_obra;
	}
}

void ler_pecas(pecas peca[], int qtdPecas){
	for (int i = 0; i < qtdPecas; i++){
        cout << "\n\nCodigo da Peca " << (i+1) << ": ";
        cin >> peca[i].codigo;
        cout << "\nDescricao: ";
        cin >> peca[i].descricao;
        cout << "\nQuantidade em Estoque: ";
        cin >> peca[i].quant_estoque;
        cout << "\nEstoque Minimo: ";
        cin >> peca[i].estoque_minimo;
        cout << "\nEstoque Maximo: ";
        cin >> peca[i].estoque_maximo;
        cout << "\nPreco Unitario: "<< endl;
        cin >> peca[i].preco_unitario;
	}
}

//2) Escreva uma funcao para permitir a inclusao de novos registros na tabela de Clientes.
//2.1) O programa devera garantir que o codigo do cliente a ser inserido não existe na tabela de Clientes.
//2.2) Quando o usuario digitar o codigo da cidade, o programa devera buscar este codigo na tabela de Cidades e exibir o nome da cidade e UF.
void inc_clientes(clientes cliente[], int qtdCliente, int &contCliente, cidades cidade[], int qtdCidades){ 
	
	if(qtdCidades == 0){
		cout<<"\n*** Nao ha cidades encontradas. Cadastre uma cidade antes para permitir a inclusao de um cliente! ***"<< endl;
		return;
	}
	
	for (int i = 0; i < qtdCliente; i++){
			
		clientes novoCliente;
		int validacao = 0, cod_encontrado = 0;
		
		cout << "\nInclusao do Cliente " << i+1 << ": ";
		
		do{
			cout << "\nCodigo do Cliente: ";
			cin >> cod_encontrado;
			
			int j = 0, f = contCliente - 1;
			int achou = 0;
			
			if (contCliente > 0){
				int m = (j + f) / 2;
				
				for (; f >= j && cod_encontrado != cliente[m].codigo; m = (j + f) / 2){
					if (cod_encontrado > cliente[m].codigo)
						j = m + 1;
					else
						f = m - 1;
				}
				
				if (f >= j && cod_encontrado == cliente[m].codigo)
					achou = 1;
			}
			
			if (achou == 1){
				cout << "\nEsse codigo ja existe. Tente novamente.";
				validacao = 0;
			}
			else{
				novoCliente.codigo = cod_encontrado;
				validacao = 1;
			}
			
		} while (validacao == 0);
		
		
		cout << "Nome do Cliente: ";
		cin >> novoCliente.nome;
		
		cout << "Endereco do Cliente: ";
		cin >> novoCliente.endereco;
		
		cout << "Telefone do Cliente: ";
		cin >> novoCliente.telefone;
		
		cout << "Codigo da Cidade do Cliente: ";
		cin >> novoCliente.codigo_cidade;
		
		
		int inicio = 0, fim = qtdCidades - 1;
		int cidadeEncontrada = 0;
		
		if (qtdCidades > 0){
			int meio = (inicio + fim) / 2;
			
			for (; fim >= inicio && novoCliente.codigo_cidade != cidade[meio].codigo; meio = (inicio + fim) / 2){
				if (novoCliente.codigo_cidade > cidade[meio].codigo)
					inicio = meio + 1;
				else
					fim = meio - 1;
			}
			
			if (fim >= inicio && novoCliente.codigo_cidade == cidade[meio].codigo){
				cout << "\nCidade: " << cidade[meio].nome;
				cout << "\nEstado: " << cidade[meio].UF;
				cidadeEncontrada = 1;
			}
			else{
				cidadeEncontrada = 0;
			}
		}
		
		if (cidadeEncontrada == 1){
			int aux;
			
			for (aux = contCliente; aux > 0 && cliente[aux - 1].codigo > novoCliente.codigo; aux--){
				cliente[aux] = cliente[aux - 1];
			}
			
			cliente[aux].codigo = novoCliente.codigo;

			strcpy(cliente[aux].nome, novoCliente.nome);

			strcpy(cliente[aux].endereco, novoCliente.endereco);

			strcpy(cliente[aux].telefone, novoCliente.telefone);

			cliente[aux].codigo_cidade = novoCliente.codigo_cidade;
			
			contCliente++;
			
			cout << "\nCliente cadastrado com sucesso!"<< endl;
		}
		else{
			cout << "\nCidade nao encontrada. Cliente nao cadastrado.";
		}
	}
}

//3) Escreva uma funcao para permitir a inclusao de novos registros na tabela de Veiculos.
//3.1) O programa devera garantir que a placa do veiculo a ser inserido nao existe na tabela de Veiculos.
//3.2) Quando o usuario digitar o codigo do cliente, o programa devera buscar este codigo na tabela de Clientes e exibir o nome do cliente.
void inc_veiculos(veiculos veiculo[], int qtdVeiculo, int &contVeiculo, clientes cliente[], int qntCliente){
	
	if(contVeiculo == 0){
		cout<<"\n*** Nao ha clientes encontrados. Cadastre um cliente antes para permitir a inclusao de um veiculo! ***"<< endl;
		return;
	}
	
	for (int i = 0; i < qtdVeiculo; i++){
		
		veiculos novoVeiculo;
		int validacao = 0;
		char placa_encontrada[8];
		
		cout << "\nInclusao do Veiculo " << i+1 << ": ";
		
		do{
			cout << "\nCodigo do Veiculo: ";
			cin >> placa_encontrada;	
			
			int j = 0, f = contVeiculo - 1;
			int achou = 0;
			
			if (contVeiculo > 0){
				int m = (j + f) / 2;
				
				for (; f >= j && strcmp(placa_encontrada, veiculo[m].placa) != 0; m = (j + f) / 2){
					if (strcmp(placa_encontrada, veiculo[m].placa) > 0)
						j = m + 1;
					else
						f = m - 1;
				}
				
				if (f >= j && strcmp(placa_encontrada, veiculo[m].placa) == 0)
					achou = 1;
			}
			
			if (achou == 1){
				cout << "\nEsse codigo ja existe. Tente novamente."<< endl;
				validacao = 0;
			}
			else{
				strcpy(novoVeiculo.placa, placa_encontrada);
				validacao = 1;
			}
			
		} while (validacao == 0);
		
		cout << "Placa do Veiculo: ";
		cin >> novoVeiculo.placa;
		
		cout << "Modelo do Veiculo: ";
		cin >> novoVeiculo.modelo;
		
		cout << "Marca do Veiculo: ";
		cin >> novoVeiculo.marca;
		
		cout << "Ano do Veiculo: ";
		cin >> novoVeiculo.ano;
		
		cout << "Codigo do Cliente do Veiculo: ";
		cin >> novoVeiculo.codigo_cliente;
		
		
		int inicio = 0, fim = qntCliente - 1;
		int clienteEncontrado = 0;
		
		if (qntCliente > 0){
			int meio = (inicio + fim) / 2;
			
			for (; fim >= inicio && novoVeiculo.codigo_cliente != cliente[meio].codigo; meio = (inicio + fim) / 2){
				if (novoVeiculo.codigo_cliente > cliente[meio].codigo)
					inicio = meio + 1;
				else
					fim = meio - 1;
			}
			
			if (fim >= inicio && novoVeiculo.codigo_cliente == cliente[meio].codigo){
				cout << "\nCliente: " << cliente[meio].nome;
				clienteEncontrado = 1;
			}
		}
		
		if (qntCliente == 1){
			int aux;
			
			for (aux = contVeiculo; aux > 0 && strcmp(veiculo[aux - 1].placa, novoVeiculo.placa) > 0; aux--){
				veiculo[aux] = veiculo[aux - 1];
			}
			
			strcpy(veiculo[aux].placa, novoVeiculo.placa);

			strcpy(veiculo[aux].modelo, novoVeiculo.modelo);

			strcpy(veiculo[aux].marca, novoVeiculo.marca);

			veiculo[aux].ano = novoVeiculo.ano;

			veiculo[aux].codigo_cliente = novoVeiculo.codigo_cliente;
			
			contVeiculo++;
			
			cout << "\nVeiculo cadastrado com sucesso!"<< endl;
		}
		else{
			cout << "\nCliente nao encontrado. Veiculo nao cadastrado."<< endl;
		}
	}
}

void inc_mecanicos(mecanicos mecanico[], int qtdMecanico, int &contMecanico){
	for(int i = 0; i < qtdMecanico; i++){
		int validacao = 0, cod_digitado = 0;
		int aux = contMecanico;
		cout<<"\nInclusao do Mecanico "<<i+1<<": "<< endl;
		
		do{
			cout<<"Codigo do Mecanico: ";
			cin>>cod_digitado;
			
			int j = 0, f = contMecanico - 1;
			int achou = 0;
			
			if(contMecanico > 0){
				int m = (j + f) / 2;
				for(; f >= j && cod_digitado != mecanico[m].codigo; m =  (j + f) / 2){
					if(cod_digitado > mecanico[m].codigo){
						j = m + 1;
					}
					else{
						f = m - 1;
					}
				}
				 if(f >= j && cod_digitado == mecanico[m].codigo){
					achou = 1;
				}
			}
			if(achou == 1){	
				cout<<"Esse codigo ja existe. Tente Novamente."<< endl;
				validacao = 0;
				}
			else{
				mecanico[aux].codigo = cod_digitado;
				validacao = 1;	
				}
			}
		while (validacao == 0);	
		
		cin.ignore();
		cout<<"Nome: ";
		cin.getline(mecanico[aux].nome, 30);
		
		cout<<"Especialidade: ";
		cin.getline(mecanico[aux].especialidade, 30);
		
		cout<<"Telefone: ";
		cin.getline(mecanico[aux].telefone, 15);
		
		contMecanico++;
		cout<<"Mecanico Cadastrado com Sucesso."<< endl;
		}
	}
	
/*
void abrir_ordem_servico(ordem_de_servico ordem_servico[], int qtdOrdens){
	
}

void consulta_pecas(pecas peca[], int qtdPecas){
	
}

void exibir_pecas_abaixo_minimo(pecas peca[], int qtdPecas){
	
}

void arrecadacao_ordens(ordem_de_servico ordem_servico[], int qtdOrdens){
	
}
*/
int main(){
	cidades cidade[10];
	clientes cliente[10];
	veiculos veiculo[10];
	servicos servico[10];
	pecas peca[10];
	mecanicos mecanico[10];
	ordem_de_servico ordem_servicos[10];
	
	int qtdCidades = 0,  qtdCliente = 0,  qtdVeiculo = 0,  qtdServicos = 0,  qtdPecas = 0,  qtdMecanico = 0,  qtdOrdens = 0;
	int contCliente = 0, contVeiculo = 0, contMecanico = 0;
	/*
	cidade[0].codigo = 1;
    strcpy(cidade[0].nome, "Assis");
    strcpy(cidade[0].UF, "SP");

    cidade[1].codigo = 2;
    strcpy(cidade[1].nome, "Marilia");
    strcpy(cidade[1].UF, "SP");

    cidade[2].codigo = 3;
    strcpy(cidade[2].nome, "Bauru");
    strcpy(cidade[2].UF, "SP");
    qtdCidades = 3;
	*/
	int opcao = 0;
	cout<<"=============================="<< endl;
	cout<<"            MENU  " << endl;
	cout<<"       OFICINA MECANICA"<< endl;
	cout<<"=============================="<< endl;
	do{
	cout<<"\n1. Ler Cidades";
	cout<<"\n2. Ler Servicos";
	cout<<"\n3. Ler Pecas";
	cout<<"\n4. Inclusao de Clientes";
	cout<<"\n5. Inclusao de Veiculos";
	cout<<"\n6. Inclusao de Mecanicos";
	cout<<"\n7. Abertura de Ordem de Servico";
	cout<<"\n8. Consultar Peca";
	cout<<"\n9. Exibir Pecas Abaixo do Estoque Minimo";
	cout<<"\n10. Valor Arrecadado com Todas Ordens de Servico";
	cout<<"\n0. Sair"<< endl;
	
	cout<<"\nDigite a opcao desejada: ";
	cin>>opcao;
	
		switch(opcao){
			case 1:
				cout<<"\nLeitura dos Dados das Cidades: "<< endl;
				ler_cidades(cidade, qtdCidades);
			break;
		
		
			case 2:
				cout<<"\nLeitura dos Dados dos Veiculos: "<< endl;
				ler_servicos(servico, qtdServicos);
			break;	
		
		
			case 3:
				cout<<"\nLeitura dos Dados das Pecas: "<< endl;
				ler_pecas(peca, qtdPecas);
			break;	
		
		
			case 4:
				cout<<"Quantos Registros de Clientes Voce Deseja Incluir? ";
				cin>>qtdCliente;
				inc_clientes(cliente, qtdCliente, contCliente, cidade, qtdCidades);
			break;
			
		
			case 5:
				cout<<"Quantos Registros de Veiculos Voce Deseja Incluir? ";
				cin>>qtdVeiculo;
				inc_veiculos(veiculo, qtdVeiculo, contVeiculo, cliente, qtdCliente);
			break;
		
		
			case 6:
				cout<<"Quantos Registros de Mecanicos Voce Deseja Incluir?";
				cin>>qtdMecanico;
				inc_mecanicos(mecanico, qtdMecanico, contMecanico);
			break;
				
			/*	
			case 7:
				cout<<"Quantas Ordens de Servico Voce Deseja Abrir?";
				cin>>qtdOrdens;
				abrir_ordem_servico(ordem_servicos, qtdOrdens);
			break;	
			
		
			case 8:
				cout<<"Quantas Pecas Voce Deseja Consultar?";
				cin>>qtdMecanicos;
				consulta_pecas(peca, qtdPecas);
			break;	
			
		
			case 9:
				cout<<"Quantas Pecas Abaixo do Estoque Minimo Voce Deseja Exibir?";
				cin>>qtdMecanicos;
				exibir_pecas_abaixo_minimo(peca, qtdPecas);
			break;
				
		
			case 10:
				cout<<"Valor Total Arrecadado Com Todas as Ordens de Servicos: ";
				arrecadacao_ordens(ordem_servicos, qtdOrdens);
			break;
			*/
			default:
				cout<<"Opcao Invalida.";	
		}
	}
	while(opcao != 0);
	
	return 0;
}

