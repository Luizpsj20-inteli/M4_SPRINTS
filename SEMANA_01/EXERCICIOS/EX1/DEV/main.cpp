//bibliotecas necessárias
#include <iostream>
#include <string>

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente
// entre dois valores mínimo e máximo e retorna esse valor

float converte_sensor(float valor, float minimo, float maximo) {
	float porcentagem = (valor - minimo) / (maximo - minimo) * 100;  //calculo da porcentagem
	if (porcentagem > 100) {   //função lógica
		return 100;
	} else if (porcentagem < 0) {
		return 0;
	} else {
		return porcentagem;
	}
}

// 2 - Faça uma função que simule a leitura de um sensor lendo o
// valor do teclado ao final a função retorna este valor

int ler_sensor() {
	int valor;
	std::cin >> valor;  // c input(cin), entrada do input
	return valor;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer
// em um vetor fornecido. Note que como C não possui vetores
// nativos da linguagem, lembre-se que você precisa passar o
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em
// uma área de memória fora do vetor

int medida(int *valores, int tamanho, int ult_posicao, int valor) {
	int posicao_atual = ult_posicao++;  //incrementa a variável i depois dela ser utilizada no comando.(para deixar mais simples do que o comando padrao.)

	if(posicao_atual < tamanho) {
		valores[posicao_atual] = valor;
	} else {
		throw std::invalid_argument( "A posição está além da capacidade." ); //retorna essa mensagem caso o argumento seja invalido.(utiliza-se o throw para um acontecimento exepcional, geralmente um erro)
	}

	return posicao_atual;
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a
// segunda é esta maior distância.


//pair é usado para combinar dois valores que podem ser de tipos diferentes.(me ajudaram nesse exercício, não sei usar 100% a função pair, estudar mais essa função e o código, perguntar para o prof.vitor.)

std::pair<std::string, int> direcao_maior_distancia(int distancia[4]) {
	// declarar as variáveis
	int tamanho = distancia[0]; // início do array
	int index_tamanho = 0;		

	// percorrer todo o vetor de distância para encontrar o maior valor
	for (int i = 0; i < 4; i++) {
		// se a distância for maior que todas as anteriores, atualizar o valor e index
		if (distancia[i] > tamanho) {
			tamanho = distancia[i];
			index_tamanho = i;
		}
	}

	// converter o index do maior valor para uma string
	std::string direcao;
	switch (index_tamanho) {
		case 0:
			direcao =  "direita";
		break;
		case 1:
			direcao =  "esquerda";
		break;
		case 2:
			direcao =  "frente";
		break;
		case 3:
			direcao =  "trás";
		break;
	}

	// retornar uma tupla com o string da maior direção e o tamanho
	return std::pair<std::string, int>(direcao, tamanho);
}

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e
// retorna verdadeiro ou falso

bool ler_comando() {
    //pergunta para o usuario
	std::cout << "Deseja continuar o mapeamento? Digite '1' para sim, '0' para não:";
	char pergunta; //char de character, aceitar só um character

	std::cin >> pergunta; //c input

//funçaõ logica
	if (pergunta ==  '1') {
		return true;
	} else {
		return false;
	}
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda",
// "Frente", "Tras").
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno
// para uma movimentação futura.
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja
// enviado pelo usuário.
//
//      Complete a função com a chamada das funções já criadas

int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = /// .. Chame a função de de leitura da medida para a "Direita"
		medida = converte_sensor(medida,0,830);
		posAtualVetor = // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = ler_comando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}

// NÃO CONSEGUI FAZER A QUESTÃO 6, DESCULPA!