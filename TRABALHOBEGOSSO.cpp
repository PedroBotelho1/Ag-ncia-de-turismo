#include <iostream>
#include <string>

using namespace std;


struct Pais {
    int codigo;
    string nome;
};

void leituraPais(struct Pais pax[], int &contadorPais) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo do país: ";
        cin >> pax[i].codigo;
        if (pax[i].codigo > 0) {
            cout << "Nome: ";
            cin.ignore();
            getline(cin, pax[i].nome);
        }
        else
            saida = 0;
    }
    contadorPais = i - 1;
}


//==========================================================


struct Cidades {
    int codigo;
    string nome;
    string UF;
    int cod_pais;
};

void leituraCidade(struct Cidades cid[], int &contadorCidade) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo da Cidade:  ";
        cin >> cid[i].codigo;
        if (cid[i].codigo > 0) {
            cout << "Nome: ";
            cin.ignore();
            getline(cin, cid[i].nome);
            cout << "UF: ";
            cin >> cid[i].UF;
            cout << "Código do país: ";
            cin >> cid[i].cod_pais;
        }
        else
            saida = 0;
    }
    contadorCidade = i - 1;
}


//==========================================================


struct Guias {
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int cod_cidade;
};

/*int busca_codigoGui(struct Guias guia[], int cod, int &contadorBusca_codigoGuia)
{
    int i = 0, f = contadorBusca_codigoGuia - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != guia[m].codigo; m = (i + f) / 2)
    {
        if (cod > guia[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == guia[m].codigo)
    {
        	cout << "ERRO, GUIA JA INSERIDO!" << endl;
        	return m;
    }
    else
        cout << "Guia ja inserido!";
}*/

int busca_codigoGuia(Guias guia[], int cod, int contadorGuia) {
    for (int i = 0; i < contadorGuia; ++i) {
        if (guia[i].codigo == cod) {
            return i; // C?digo encontrado
        }
    }
    return -1; // C?digo n?o encontrado
}

void buscar_cidade(struct Cidades cid[], int contadorCidade, int codigo_cidade, Pais pax[]) {
    for (int i = 0; i < contadorCidade; ++i) {
        if (cid[i].codigo == codigo_cidade) {
            cout << "\nCidade: " << cid[i].nome << endl; 
            cout << "UF: " << cid[i].UF <<endl; 
            cout << "País: " << pax[i].nome << endl;
        }
        else {
        	cout << "Código da cidade não encontrado." << endl;
		}
    }
}

void leituraGuia(Guias guia[], int &contadorGuia, Cidades cid[], int contadorCidade, Pais pax[]) { //Cidades cidades[], int contadorCidades
    
	int i = contadorGuia;
    
    for (int saida = 1; i < 20 && saida != 0; i++) {
        int codigo;
        do {
            cout << "\n\nCódigo do guia: ";
            cin >> codigo;
            if (codigo <= 0) {
                saida = 0;
                break;
            }
            if (busca_codigoGuia(guia, codigo, contadorGuia) != -1) {
                cout << "Código já existe. Digite um código único." << endl;
            }
        } while (busca_codigoGuia(guia, codigo, contadorGuia) != -1);
        
        if (saida == 0) {
            break;
        }

        guia[i].codigo = codigo;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, guia[i].nome);
        cout << "Endereço: ";
        getline(cin, guia[i].endereco);
        cout << "Telefone: ";
        getline(cin, guia[i].telefone);
        cout << "Código da cidade: ";
        cin >> guia[i].cod_cidade;
        cout << endl;

        buscar_cidade(cid, contadorCidade, guia[i].cod_cidade, pax); 
    }
    contadorGuia = i;
}



void inclusaoGuia(struct Guias S[], int contS, struct Guias T[], int contT, struct Guias A[], int &contA)
{
    int i = 0, j = 0, k = 0;
    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo && S[i].codigo != T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].cod_cidade = S[i].cod_cidade;
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].cod_cidade = T[j].cod_cidade;
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].cod_cidade = S[i].cod_cidade;
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].cod_cidade = T[j].cod_cidade;
        j++;
        k++;
    }
    contA = k;
}


//==========================================================


struct Clientes {
    int CPF;
    string nome;
    string endereco;
    int cod_cidade;
};

int busca_codigoCliente(Clientes cli[], int cod, int contadorCliente) {
    for (int i = 0; i < contadorCliente; ++i) {
        if (cli[i].CPF == cod) {
            return i; // Código encontrado
        }
    }
    return -1; // Código não encontrado
}

void leituraCliente(Clientes cli[], int &contadorCliente, Cidades cid[], int contadorCidade, Pais pax[]) { 
    int i = contadorCliente;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        int codigo;
        do {
            cout << "\n\nCPF do Cliente: ";
            cin >> codigo;
            if (codigo <= 0) {
                saida = 0;
                break;
            }
            if (busca_codigoCliente(cli, codigo, contadorCliente) != -1) {
                cout << "Código já existe. Digite um código único." << endl;
            }
        } while (busca_codigoCliente(cli, codigo, contadorCliente) != -1);
        
        if (saida == 0) {
            break;
        }

        cli[i].CPF = codigo;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, cli[i].nome);
        cout << "Endereço: ";
        getline(cin, cli[i].endereco);
        cout << "Código da cidade: ";
        cin >> cli[i].cod_cidade;

        buscar_cidade(cid, contadorCidade, cli[i].cod_cidade, pax); // Mostra informações da cidade
    }
    contadorCliente = i;
}

void inclusaoCliente(struct Clientes S[], int contS, struct Clientes T[], int contT, struct Clientes A[], int &contA)
{
    int i = 0, j = 0, k = 0;
    for (; i < contS && j < contT; k++)
    {
        if (S[i].CPF < T[j].CPF && S[i].CPF != T[j].CPF)
        {
            A[k].CPF = S[i].CPF;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].cod_cidade = S[i].cod_cidade;
            i++;
        }
        else
        {
            A[k].CPF = T[j].CPF;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].cod_cidade = T[j].cod_cidade;
            j++;
        }
    }
    while (i < contS)
    {
        A[k].CPF = S[i].CPF;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].cod_cidade = S[i].cod_cidade;
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].CPF = T[j].CPF;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].cod_cidade = T[j].cod_cidade;
        j++;
        k++;
    }
    contA = k;
}


void exclusaoCliente(Clientes S[], int contS, int T[], int contT, Clientes A[], int &contA)
{
    int i = 0, j = 0, k = 0;
    while (i < contS && j < contT)
    {
        if (S[i].CPF != T[j])
        {
            A[k].CPF = S[i].CPF;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].cod_cidade = S[i].cod_cidade;
            i++;
            k++;
        }
        else
        {
            j++;
        }
    }
    // Se o array T[] ainda tiver elementos, mas S[] não, copie os elementos restantes de S[]
    while (i < contS)
    {
        A[k].CPF = S[i].CPF;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].cod_cidade = S[i].cod_cidade;
        i++;
        k++;
    }
    contA = k;
}


//==========================================================


struct Pacote {
    int codigo;
    string descricao;
    int cod_guia;
    float valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

int busca_codigoPacote(struct Pacote pac[], int cod, int contadorPacote) {
    for (int i = 0; i < contadorPacote; ++i) {
        if (pac[i].codigo == cod) {
            return i; // C?digo encontrado
        }
    }
    return -1; // C?digo n?o encontrado
}

void buscar_Guia_Pacote(struct Guias guia[], int contadorGuia, int codigo_guia, struct Cidades cid[], struct Pais pax[]) {
     for (int i = 0; i < contadorGuia; ++i) {
    	if (guia[i].codigo == codigo_guia) {
            cout << "\nNome do guia: " << guia[i].nome << endl; 
            cout << "Nome da cidade: " << cid[i].nome <<endl; 
            cout << "Nome do País: " << pax[i].nome << endl;
        }
        else {
        	cout << "Código do guia não encontrado." << endl;
		}
    }
}

void leituraPacote(struct Pacote pac[], int &contadorPacote, struct Guias guia[], int contadorGuia, struct Cidades cid[], struct Pais pax[]) { //Cidades cidades[], int contadorCidades
    
	int i = contadorPacote;
    
    for (int saida = 1; i < 20 && saida != 0; i++) {
        int codigo;
        do {
            cout << "\n\nCódigo do pacote: ";
            cin >> codigo;
            if (codigo <= 0) {
                saida = 0;
                break;
            }
            if (busca_codigoPacote(pac, codigo, contadorPacote) != -1) {
                cout << "Código já existe. Digite um código único." << endl;
            }
        } while (busca_codigoPacote(pac, codigo, contadorPacote) != -1);
        
        if (saida == 0) {
            break;
        }

        pac[i].codigo = codigo;
        cout << "Descrição: ";
        cin.ignore();
        getline(cin, pac[i].descricao);
        cout << "Código do guia: ";
        cin >> pac[i].cod_guia;
        cout << "Valor por pessoa: ";
        cin >> pac[i].valor_por_pessoa;
        cout << "Total de participantes: ";
        cin >> pac[i].total_participantes;
        cout << "Quantidade máxima de participantes: ";
        cin >> pac[i].quant_max_participantes;
        
        buscar_Guia_Pacote(guia, contadorGuia, guia[i].codigo, cid, pax);
    }
    contadorPacote = i;
}

void inclusaoPacote(struct Pacote S[], int contS, struct Pacote T[], int contT, struct Pacote A[], int &contA)
{
    int i = 0, j = 0, k = 0;
    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo && S[i].codigo != T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            A[k].cod_guia = S[i].cod_guia;
            A[k].valor_por_pessoa = S[i].valor_por_pessoa;
            A[k].total_participantes = S[i].total_participantes;
            A[k].quant_max_participantes = S[i].quant_max_participantes;
            i++;
        }
        else
        {
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            A[k].cod_guia = S[i].cod_guia;
            A[k].valor_por_pessoa = S[i].valor_por_pessoa;
            A[k].total_participantes = S[i].total_participantes;
            A[k].quant_max_participantes = S[i].quant_max_participantes;
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        A[k].descricao = S[i].descricao;
        A[k].cod_guia = S[i].cod_guia;
        A[k].valor_por_pessoa = S[i].valor_por_pessoa;
        A[k].total_participantes = S[i].total_participantes;
        A[k].quant_max_participantes = S[i].quant_max_participantes;
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = S[i].codigo;
        A[k].descricao = S[i].descricao;
        A[k].cod_guia = S[i].cod_guia;
        A[k].valor_por_pessoa = S[i].valor_por_pessoa;
        A[k].total_participantes = S[i].total_participantes;
        A[k].quant_max_participantes = S[i].quant_max_participantes;
        j++;
        k++;
    }
    contA = k;
}


void consultaPacote(struct Pacote pac[], int contadorPacote) {
	int codigo;
	cout << "\nDigite o código do pacote que deseja consultar: ";
	cin >> codigo;
	bool encontrado = false;
	
	for (int i = 0; i <= contadorPacote; i++) {
		if (pac[i].codigo == codigo) { 
		float valor_total_arrecadado = pac[i].valor_por_pessoa * pac[i].total_participantes;
			cout << "\nCódigo: " << pac[i].codigo << endl;
			cout << "\nDescrição: " << pac[i].descricao << endl;
			cout << "\nCódigo do Guia: " << pac[i].cod_guia << endl;
			cout << "\nValor por Pessoa: " << pac[i].valor_por_pessoa << endl;
			cout << "\nTotal de participantes: " << pac[i].total_participantes << endl;
			cout << "\nQuantidade Máxima de Participantes: " << pac[i].quant_max_participantes << endl;
			cout << "\nValor Total Arrecadado: " << valor_total_arrecadado << endl;
			encontrado = true;
			break;
		}
	}
	
	if(!encontrado) {
		cout << "Pacote com código " << codigo << " não encontrado.";
	}
}

void exibirPacotesCompletamenteVendidos(Pacote pac[], int contadorPacote) {
	cout << "\n\n****PACOTES COMPLETAMENTE VENDIDOS****" << endl;
	bool encontrado = false;
	
	for(int i = 0; i <= contadorPacote; i++) {
		if (pac[i].total_participantes == pac[i].quant_max_participantes) {
			float valor_total_arrecadado = pac[i].valor_por_pessoa * pac[i].total_participantes;
			encontrado = true;
			cout << "\nCódigo: " << pac[i].codigo << endl;
			cout << "\nDescrição: " << pac[i].descricao << endl;
			cout << "\nCódigo do Guia: " << pac[i].cod_guia << endl;
			cout << "\nValor Total Arrecadado: " << valor_total_arrecadado << endl;
		}
	}
	
	if (!encontrado) {
		cout << "Nenhum pacote completamente vendido encontrado." << endl;
	}
}

/*int busca_pacote(struct Pacote S[], int cod, int &contadorBusca_pacote, struct Guias guia, struct Cidades cid, struct Pais pac)
{
    int i = 0, f = contadorBusca_pacote - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != pac[m].cod_guia; m = (i + f) / 2)
    {
        if (cod > pac[m].cod_guia)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == guia[m].codigo)
    {
        	cout << "Nome do Guia: " << guia[i].nome;
            cout << "Nome da Cidade: " << cid[i].nome;
            cout << "Nome do Pa?s: " << pac[i].nome;
        return m;
    }
    else
        return -1;
    cout << "\n\n C?digo do Guia n?o Encontrado";
}*/


//==========================================================


struct Vendas {
    int codigo;
    int CPF_cliente;
    int cod_pacote;
    int quantidade_pessoas;
    float valor_total;
};

void buscar_Clientes_Vendas(Vendas ven[], Clientes cli[], int contadorCliente, Cidades cid[], int cpf) {
	int teste = 0;
    for (int i = 0; i <= contadorCliente; i++) {
        if (ven[i].CPF_cliente == cpf) {
            cout << "\nNome do cliente: " << cli[i].nome << endl;
			cout << "\nNome da Cidade: " << cid[i].nome << endl;
			teste = 1;
     	}
	}
		if(teste == 0)
		cout << "CPF não encontrado." << endl;
}

//////////////////////////////////////////////////////////////////////////////////

void buscar_CodigoPacote_Vendas(struct Vendas ven[], struct Pacote pac[], int contadorPacote, struct Guias guia[]) {
	for (int i = 0; i < contadorPacote; ++i) {
        if (ven[i].cod_pacote == pac[i].codigo) {
        	cout << "Descrição: " << pac[i].descricao << endl;
        	cout << "Nome do Guia: " << guia[i].nome << endl;
        	cout << "Valor por Pessoa: " << pac[i].valor_por_pessoa << endl;
        	return;
		}
    }  
	cout << "Código da cidade não encontrado." << endl;
}

//////////////////////////////////////////////////////////////////////////////////

bool adicionarParticipantes(Pacote &pacote, int quantidade_pessoas) {
    if (pacote.total_participantes + quantidade_pessoas > pacote.quant_max_participantes) {
        cout << "Erro: Quantidade de participantes excede o limite permitido." << endl;
        return false;
    }
    pacote.total_participantes += quantidade_pessoas;
    return true;
}

void calcularValorTotal(Vendas venda[], Pacote pacote[], int i, int catedral) {
    venda[i].valor_total = venda[i].quantidade_pessoas * pacote[i].valor_por_pessoa;
    
}

/*float calcularValorTotal(Vendas venda[], Pacote pacote[], int i) {
    venda[i].valor_total = venda[i].quantidade_pessoas * pacote[i].valor_por_pessoa;
    return venda[i].valor_total;
}*/

//////////////////////////////////////////////////////////////////////////////////


void leituraVendas(struct Vendas ven[], Pacote pac[], int contadorPacote, struct Guias guia[], int &contadorVendas, struct Clientes cli[], int contadorCliente, struct Cidades cid[]) {
    int i = 0, cpf = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo da Venda:  ";
        cin >> ven[i].codigo;
        if (ven[i].codigo > 0) {
            cout << "CPF do cliente: ";
            cin >> ven[i].CPF_cliente;
            buscar_Clientes_Vendas(ven, cli, contadorCliente, cid, ven[i].CPF_cliente);
            cout << endl;
            
            cout << "Código do Pacote: ";
            cin >> ven[i].cod_pacote;
            buscar_CodigoPacote_Vendas(ven, pac, contadorPacote, guia);
            cout << endl;
            
            cout << "Quantidade de pessoas: ";
            cin >> ven[i].quantidade_pessoas;
            //adicionarParticipantes(pac, quantidade_pessoas);
            cout << endl;
           	
			ven[i].valor_total = ven[i].quantidade_pessoas * pac[i].valor_por_pessoa;
            cout << "Valor total: " << ven[i].valor_total;
		}
		else {
            saida = 0;
        }
    } 
    contadorVendas = i - 1;
}

void inclusaoVendas(struct Vendas S[], int contS, struct Vendas T[], int contT, struct Vendas A[], int &contA)
{
    int i = 0, j = 0, k = 0;
    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo && S[i].codigo != T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            A[k].CPF_cliente = S[i].CPF_cliente;
            A[k].cod_pacote = S[i].cod_pacote;
            A[k].quantidade_pessoas = S[i].quantidade_pessoas;
            A[k].valor_total = S[i].valor_total;
            i++;
        }
        else
        {
            A[k].codigo = S[i].codigo;
            A[k].CPF_cliente = S[i].CPF_cliente;
            A[k].cod_pacote = S[i].cod_pacote;
            A[k].quantidade_pessoas = S[i].quantidade_pessoas;
            A[k].valor_total = S[i].valor_total;
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        A[k].CPF_cliente = S[i].CPF_cliente;
        A[k].cod_pacote = S[i].cod_pacote;
        A[k].quantidade_pessoas = S[i].quantidade_pessoas;
        A[k].valor_total = S[i].valor_total;
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = S[i].codigo;
        A[k].CPF_cliente = S[i].CPF_cliente;
        A[k].cod_pacote = S[i].cod_pacote;
        A[k].quantidade_pessoas = S[i].quantidade_pessoas;
        A[k].valor_total = S[i].valor_total;
        j++;
        k++;
    }
    contA = k;
}

void exibirVendas(Vendas ven[], int contadorVendas, Pacote pac[], int contadorPacotes, Clientes cli[], int contadorClientes) {
    float valor_total_vendido = 0.0;
    
    for(int i = 0; i <= contadorVendas; i++) {
    	if(ven[i].codigo > 0) {
    		cout << "\nCódigo: " << ven[i].codigo << endl;
        
        string nome_cliente;
        for (int j = 0; j <= contadorClientes; j++) {
            if (cli[j].CPF == ven[i].CPF_cliente) {
                nome_cliente = cli[j].nome;
                break;
            }
        }
        
        cout << "Nome do Cliente: " << nome_cliente << endl;
        
        string descricao_pacote;
        for(int j = 0; j <= contadorPacotes; j++) {
            if(pac[j].codigo == ven[i].cod_pacote) {
                descricao_pacote = pac[j].descricao;
                break;
            }
        }
        
        cout << "Descrição do Pacote: " << descricao_pacote << endl;
        cout << "Quantidade de Pessoas: " << ven[i].quantidade_pessoas << endl;
        cout << "Valor Total: R$" << ven[i].valor_total << endl;
        
        
        valor_total_vendido += ven[i].valor_total;
		}
    }
    
    cout << "\n\nValor total Vendido: R$" << valor_total_vendido <<endl;
    
}


//==========================================================

int main() {
	setlocale(LC_ALL, "portuguese");
	
	
	//////////////////////PA?S//////////////////////
	Pais pax[20];
	int contadorPais;
	
	
	//////////////////////CIDADES//////////////////////
	Cidades cid[20];
	int contadorCidade;
	
	
	//////////////////////GUIAS//////////////////////
	struct Guias arqGuiasS[20], arqGuiasT[20], arqGuiasA[20];
	int contadorGuiasS, contGuiasT, contGuiasA, cont;
	
	
	//////////////////////CLIENTES//////////////////////
	struct Clientes arqClienteS[20], arqClienteT[20], arqClienteA[20];
	int arqClientesT[20];
	int contadorClienteS, contClienteT, contClienteA;
	
	
	//////////////////////PACOTE//////////////////////
	struct Pacote arqPacoteS[20], arqPacoteT[20], arqPacoteA[20];
	int contadorPacoteS, contPacoteT, contPacoteA;
	
	
	//////////////////////VENDAS//////////////////////
	struct Vendas arqVendasS[20], arqVendasT[20], arqVendasA[20];
	int contadorVendasS, contVendasT, contVendasA;
	
	
	
	int opcao = 30;
    while(opcao != 0) {
        cout << "\n\t** AGÊNCIA DE TURISMO **" << endl;
        cout << "-----------------------------------------------------"<< endl;
        cout << "| [1] - Leitura dos Países:                          |"<< endl;
        cout << "| [2] - Leitura das Cidades:                         |"<< endl;
        cout << "| [3] - Leitura dos Guias:                           |"<< endl;
        cout << "| [4] - Leitura dos Clientes:                        |"<< endl;
        cout << "| [5] - Leitura dos Pacotes:                         |"<< endl;
        cout << "| [6] - Leitura dos Vendas:                          |"<< endl;
        cout << "| [7] - Inclusão de Novos Guias:                     |"<< endl;
        cout << "| [8] - Inclusão de Novos Clientes:                  |"<< endl;
        cout << "| [9] - Exclusão de Clientes:                        |"<< endl;
        cout << "| [10] - Inclusão de Pacotes:                        |"<< endl;
        cout << "| [11] - Consultar Pacote:                           |"<< endl;
        cout << "| [12] - Exibir Pacotes Completamente Vendidos:      |"<< endl;
        cout << "| [13] - Exibir Vendas:                              |"<< endl;
        cout << "-----------------------------------------------------"<< endl; 
        
        cout << "[0] - Sair" << endl;
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                system("cls");
                cout << "Leitura de Países:" << endl;
                leituraPais(pax, contadorPais);
                break;
                
            case 2:
				system("cls");
				cout << "Leitura de Cidades:" << endl;
				leituraCidade(cid, contadorCidade);
				break;
				
			case 3:
				system("cls");
				contadorGuiasS = 0;
				cout << "Leitura de Guias:" << endl;
				leituraGuia(arqGuiasS, contadorGuiasS, cid, contadorCidade, pax);
				break;
				
			case 4: 
				system("cls");
				cout << "Leitura de Clientes:" << endl;
				leituraCliente(arqClienteS, contadorClienteS, cid, contadorCidade, pax);
				break;
				
			case 5: 
				system("cls");
				cout << "Leitura de Pacotes:" << endl;
				leituraPacote(arqPacoteS, contadorPacoteS, arqGuiasS, contadorGuiasS, cid, pax);
				break;
			
			case 6: 
				system("cls");
				contadorVendasS = 0;
				cout << "Leitura de Vendas:" << endl;
				leituraVendas(arqVendasS, arqPacoteS, contadorPacoteS, arqGuiasS, contadorVendasS, arqClienteS, contadorClienteS, cid);
				break;
				
			case 7: 
				system("cls");
				cout << "Inclusão de Guias:" << endl;
    			leituraGuia(arqGuiasS, contadorGuiasS, cid, contadorCidade, pax);
				inclusaoGuia(arqGuiasS, contadorGuiasS, arqGuiasT, contGuiasT, arqGuiasA, contGuiasA);
				break;
				
			case 8:
				system("cls");
				cout << "Inclusão de Clientes" << endl;
				leituraCliente(arqClienteS, contadorClienteS, cid, contadorCidade, pax);
				inclusaoCliente(arqClienteS, contadorClienteS, arqClienteT, contClienteT, arqClienteA, contClienteA);
				break;
				
			case 9:
				system("cls");
                for (contClienteT = 0; contClienteT < 20 &&  arqClientesT[contClienteT - 1] > 0; contClienteT++){
        			cout << "\nInforme o Codigo do Registro a ser Excluido (finalize com 0): ";
        			cin >> arqClientesT[contClienteT];
    			}
    			contClienteT--;
    			exclusaoCliente(arqClienteS, contadorClienteS , arqClientesT, contClienteT, arqClienteA, contClienteA);
                break;
            
            case 10:
            	system("cls");
            	cout << "Inclusão de Pacotes:" << endl;
            	leituraPacote(arqPacoteS, contadorPacoteS, arqGuiasS, contadorGuiasS, cid, pax);
            	inclusaoPacote(arqPacoteS, contadorPacoteS, arqPacoteT, contPacoteT, arqPacoteA, contPacoteA);
				break;
				
			case 11: 
				system("cls");
				cout << "Consultar Pacote:" << endl;
				consultaPacote(arqPacoteS, contadorPacoteS);
				break;
				
			case 12:
				system("cls");
				cout << "Exibir Pacotes Completamente Vendidos:" << endl;
				exibirPacotesCompletamenteVendidos(arqPacoteS, contadorPacoteS);
				break;
				
			case 13:
				system("cls");
				cout << "Exibir Vendas:" << endl;
				exibirVendas(arqVendasS, contadorVendasS, arqPacoteS, contadorPacoteS, arqClienteS, contadorClienteS);
				break;
				
			case 0:
                cout << "Encerrando..." << endl;
                break;
        }
    }
    return 0;
}



