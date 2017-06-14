#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>




using namespace std;

const int quantPalavras = 5;

//"banco de dados de palavras" - SOOOQUENAOO
char banco[quantPalavras][30]{
"cachorro",
"computador",
"cadeira",
"automovel",
"edificio" };

//Variaveis globais
char palavraSort[30];
char palavraDigitada[30];
int cont;
char letrasDigitadas[26];
int contLetrasDigitadas =0;	
int contadorDeErros;	
int contadorDeAcertos=0;
bool aux = true;
int EntraJogo;
//Funções

//////////////////////////////////////////////////////
////				CORES						/////
//ENUMERAÇÃO QUE DEFINE A ESTRUTURA DO TIPO DE CORES.
enum COLORS {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
	LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
	LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE 
};

typedef enum COLORS color;

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void textcolor(color iColor) {			//FUNÇÃO TEXTCOLOR: DEFINE A COR DE PRIMEIRO PLANO DOS TEXTOS
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
	return;
}

void textbackground(color iColor) {		//FUNÇÃO TEXTBACKGROUND: DEFINE A COR DE FUNDO DAS FONTES.
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
	return;
}

//////////////////////////////////////////////////////
void Copia (int indice){ //Copia palavra do banco para um vetor
	for (int i = 0; i <30 ; i++){
		palavraSort[i] = banco[indice] [i];
	}
}

//Imprimindo palavras digitadas 
void ImprimePalavraDigit(){
		cout<<"\n     "<<strlen(palavraSort)<<" letras"<<endl;
	for (int i = 0; i <strlen(palavraSort); i++){
	
		cout<<palavraDigitada[i]<< " " ;
		
	}
}



//Verifica em qual pósição do vetor se encontra a letra e substitui
void substitui(char letra){
	for (int i =0; i <strlen(palavraSort); i++){
		if (palavraSort[i] == letra){ 
				palavraDigitada[i] = letra;
				contadorDeAcertos++;
		}
	}
}

//Sorteia as palavras
int Sorteia(){
	srand(time (NULL)); //retorna hora atual, para não ser sorteado apenas o numero 1
	return rand() % quantPalavras;
}



//Limpa as palavras que serão inseridas
void LimpaPalavraDigitada(){	
	for (int i=0; i<strlen(palavraSort); i++){
		palavraDigitada[i] = '_';
	}
}


bool  verificaLetra(char letra, char vetor[26]){
	for (int i =0; i <strlen(vetor); i++){
		if (letra == vetor[i]){ //Verifica se letra se encontra no vetor digitado
			return true;
		}
	}
	return false; 
}

//Imprime as letras para não repetir as letras
void ImprimeLetrasDigitadas(char letras[26]){
	cout<<endl<<"Letras digitadas: ";
	for (int i = 0; i < strlen(letras) ; i++){
		cout<<letrasDigitadas[i]<<" ,";	
	}	
}

//Verificar se a palavra foi completa
bool palavraCompleta(){
	for (int i=0; i < strlen(palavraSort) ; i++){
		if (palavraDigitada[i] == palavraSort[i]){
			return true;
		}
		else {
			return false;
		}
	}
	
}


void Parabens(){
	
		gotoxy(7,4);	cout<<"Parabens você acertou a palavra!"<<endl<<endl<<endl;
	
		gotoxy(16,7); cout<<"\\õ/"<<endl;
		gotoxy(16,8); cout<<" |"<<endl;
		gotoxy(16,9); cout<<"/ \\"<<endl;
		textcolor(LIGHT_CYAN); gotoxy(7,12); cout<<"Agora, És um Homem Livre!!!"<<endl;
			textcolor(GREEN);
			cout<<"\n\nPalavra digitada: "<<palavraSort<<endl<<endl<<endl;
			textcolor(WHITE);
	
}

void imprimeMenuPrincipal(){
	
	for (int i =0; i< 80 ; i++){	//Esquerda para Direita(SUPERIOR)
		textbackground(LIGHT_CYAN);
		gotoxy(i,1);
		Sleep(20);
		printf(" " );
		
		
	}
	
	
	for (int j =0; j< 25 ; j++){  //Cima PAra Baixo(DIREITA)
		textbackground(LIGHT_GRAY);
		Sleep(20);
		gotoxy(80,j);
		printf(" " );
		
	}
	
		
	for (int i =0; i< 25 ; i++){	//Cima para baixo (ESQUERDA)
		textbackground(LIGHT_GRAY);
		gotoxy(1,i);
		Sleep(20);
		printf(" " );
		
		
	}
	
		
	for (int k =0; k< 80 ; k++){		//Esquerda para direita (INFERIOR)
		textbackground(LIGHT_CYAN);
		Sleep(20);
		gotoxy(25,0);
		printf(" " );	
	}
	
	
	gotoxy(7,6);
	textbackground(BLACK);
	textcolor(LIGHT_GRAY);
	 gotoxy(7,6);       cout<<"     \ | /    \n";
	 gotoxy(7,7);		cout<<"   ___\|/____	\n";
	 gotoxy(7,8);		cout<<"    /      \\ \n";
     gotoxy(7,9);		cout<<"   / __  __ \\\n";
	 gotoxy(7,10);		cout<<"  /  ^   ^   \\\n";
	 gotoxy(7,11);		cout<<"  \\    >     /\n";
	 gotoxy(7,12);		cout<<"   \\   __@  /\n";
	 gotoxy(7,13);		cout<<"    \\______/\n";
	 gotoxy(7,14);		cout<<"       /||\\ \n";
	 gotoxy(7,15);		cout<<"        /\\ \n";
	
	
		textbackground(BLACK);
		textcolor(CYAN);
		Sleep(300);
		gotoxy(35,5);
		cout<<"BEM VINDO AO"<<endl;
		gotoxy(35,6);
		textcolor(LIGHT_CYAN);
		Sleep(500);
		cout<<"JOGO DA FORCA"<<endl;
		textcolor(WHITE);
		Sleep(1000);
		gotoxy(34,10);
		textcolor(LIGHT_CYAN); cout<<"1"; textcolor(LIGHT_GRAY); cout<<" - ENTRAR NO JOGO"<<endl<<endl;
		gotoxy(34,11);
		textcolor(LIGHT_CYAN); cout<<"0"; textcolor(LIGHT_GRAY); cout<<" - SAIR"<<endl<<endl;
		cin>>EntraJogo;
		
		textbackground(BLACK);
		textcolor(WHITE);
	textbackground(BLACK);
}



//Imprime dependendendo da quantidade de erros
void imprimeForca(int letrasErradas){
	
	switch(letrasErradas){
			
	case 0:
		
			system("cls");	
			
			cout<<" _____________________________         \n" ; 
			cout<<" |                            |\n";
			cout<<" |                            |\n";
			cout<<" |                            \n";
			cout<<" |\n";
			cout<<" |\n";
			cout<<" |__\n\n\n";
		
		
				break;
	case 1:
			
			cout<<" _____________________________         \n" ; 
			cout<<" |                            |\n";
			cout<<" |                            |\n";
			cout<<" |                            Õ \n";
			cout<<" |\n";
			cout<<" |\n";
			cout<<" |__\n\n\n";
			
			break;
		
	case 2:
			cout<<" _____________________________         \n";
			cout<<" |                            |\n";
			cout<<" |                            |\n";
			cout<<" |                            Õ \n";
			cout<<" |                            | \n";
			cout<<" |\n";
			cout<<" |\n";
			cout<<" |__\n\n\n";
			
		
		

		break;	
		
	case 3:
		
			
			cout<<" _____________________________         \n";
			cout<<" |                            |\n";
			cout<<" |                            |\n";
			cout<<" |                            Õ \n";
			cout<<" |                            |\\ \n";
			cout<<" |\n";
			cout<<" |\n";
			cout<<" |__\n\n\n";
		break;		
	
	case 4:
		
			cout<<" _____________________________         \n";
			cout<<" |                            |\n";
			cout<<" |                            |\n";
			cout<<" |                            Õ \n";
			cout<<" |                           /|\\ \n";
			cout<<" |\n";
			cout<<" |\n";
			cout<<" |__\n\n\n";

		break;	
		
	case 5:

			cout<<" _____________________________         \n";
			cout<<" |                            |\n";
			cout<<" |                            |\n";
			cout<<" |                            Õ \n";
			cout<<" |                           /|\\ \n";
			cout<<" |                             \\   \n";
			cout<<" |\n";
			cout<<" |__\n\n\n";
			
		break;	
		
	case 6:
			
			gotoxy(0,50);
			cout<<"\n\n";
			textcolor(WHITE);
			textbackground(RED);
			cout<<endl<<"You  Dead! "<<endl<<endl;
			Sleep(1000);
			textbackground(BLACK);
			textcolor(WHITE);
			Sleep(300);
			cout<<" _____________________________         \n";
			Sleep(300);
			cout<<" |                            |\n";
			Sleep(300);
			cout<<" |                            |\n";
			
			Sleep(300);
			cout<<" |                            ";	textcolor(RED);	cout<<"Õ \n";	textcolor(WHITE);
			Sleep(300);
			cout<<" |                           ";textcolor(RED);	cout<<"/|\\ \n"; textcolor(WHITE);
			Sleep(300);
			cout<<" |                           ";textcolor(RED);	cout<<"/ \\  \n"; textcolor(WHITE);
			
			cout<<" |\n";
			Sleep(300);
			cout<<" |__	                    ";Sleep(500); textbackground(RED); cout<<"     \n\n\n";	textcolor(WHITE);		
						
			Sleep(2000);
			textbackground(BLACK);
			textcolor(WHITE);
			cout<<"A palavra Correta era: "; textcolor(GREEN); cout<<palavraSort<<endl<<endl;
			textcolor(WHITE);
			cout<<"Tente Novamente!"<<endl<<endl<<endl<<endl;	
	
		break;				
	}
}




//----------------------- MAIN -------------------------------------------

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	//Variaveis
	char letra; //Letra digitada
	contadorDeErros = 0;	
	
	int IndPalavra = Sorteia(); // Esta sorteando as palavras
	Copia (IndPalavra);
	
	LimpaPalavraDigitada(); //Limpa as palavras digitadas para não ter lixo de memoria
			
	//Enquanto for menor que as tentativas
	imprimeMenuPrincipal();
		
	while(EntraJogo != 0){	
		while (contadorDeErros < 6 and  contadorDeAcertos < strlen(palavraSort)){ 
		
		
			system("cls");
					
			imprimeForca(contadorDeErros);
			ImprimePalavraDigit();
			
			cout<<endl<<endl<<"Tentativas Restantes: "<<6 - contadorDeErros<<endl;
			ImprimeLetrasDigitadas(letrasDigitadas);
			cout<<endl<<endl;
			
			cout<<endl<<endl<<"Digite uma letra: "<<endl;
			cin>>letra;
			
			letra = tolower(letra); //Deixa minusculo
			
			if (verificaLetra(letra, letrasDigitadas)) { // se a letra ja tiver sido digitada no vetor de letrasDigitadas
				cout<<"Letra ja foi digitada! Tente novamente"<<endl<<endl;
				system("pause");
				}
				//Se a letra nao foi digitada, ela precisa ser tratada
			else{
				letrasDigitadas [contLetrasDigitadas] = letra;
				contLetrasDigitadas ++;
				if(verificaLetra(letra, palavraSort)){
						substitui(letra);
					}
				else{
					cout<<"Letra Incorrreta, tente novamente! "<<endl;
					contadorDeErros++;
				}	
			}
	
			if (contadorDeErros == 6){
				system("cls");
				imprimeForca(contadorDeErros);
				
			}
			else {
				system("cls");
				Parabens();
				
			}	
		}
		
		
	}
	system("cls");
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(35,25);
	cout<<"See You Later :) "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	textbackground(BLACK);
	textcolor(BLACK);
}
	


	
