#include <iostream>
#include <ctime>
#include <cstring>
#include<time.h>
#include<iomanip>
# define N 10

using namespace std;

struct Capitao  //Perfil e dados dos jogadores
{
    char nome[100];
    int placar;
    int xtiro;
    char ytiro;
    int vida_usuario = 1, vida_inimigo = 1;
    int li=0, co=0, l=0, c=0;
    int x=0;
    char y=0;
    char campo[10][10];
    char inimigo[10][10];
    char cpu[10][10];
    int selec = 0;
};
    
struct Capitao jogador;

int preenchesubmarino(int subL, int subC)
{
    cout << endl;
    subL = subL-1;
    subC = subC - 65;
    if (jogador.campo[subL][subC] == '+' && jogador.campo[subL+1][subC] == '+' && jogador.campo[subL-1][subC] == '+' && jogador.campo[subL][subC+1] == '+' && jogador.campo[subL][subC-1] == '+')
    {
        jogador.campo[subL][subC] = 'S';
        return 1;
    }
    else
    {
        cout << "Posicao invalida, por favor digite novamente" << endl;
        return -1;
    }              
}
    
int escolha ()
{
    cout << "Deseja jogar novamente?" << endl;
    cout << "Digite 1 para sim / Digite 2 para nao" << endl;
    cin >> jogador.selec;
    if (jogador.selec == 1){
        jogador.vida_usuario = 1; 
        jogador.vida_inimigo = 1;
        return 1; 
    }
    else if (jogador.selec == 2){
        return -1;
        }     
}

void TabelaInterface(char campo[N][N], char cpu[N][N]){
    cout << setw(2) << "       TRIPULACAO ALIADA                                       TRIPULACAO INIMIGA  "  << endl;
    cout << setw(2) << "    A  B  C  D  E  F  G  H  I  J                             A  B  C  D  E  F  G  H  I  J" << endl;
    for(int l=0;l<10;l++){
        cout<< setw(2) << (l+1) << " ";
        for(int c = 0; c < 10; c++)
        {
            cout<< setw(2) << campo[l][c] <<  " ";
        }
        cout << "                        ";
        cout<< setw(2) << (l+1) << " ";
        for (int c = 0; c < 10; c++)
        {
            cout << setw(2) << cpu[l][c]<<" ";
        } 
        cout << endl;
        }
    cout << setw(3) << "^<><><><><><><><><><>^                                   ^<><><><><><><><><><>^"<< endl;
    cout << setw(3) << "^ Capitao " << jogador.nome << "     ^                                   ^ Inimigo Caveira    ^" << endl;
    cout << setw(3) << "^ Vida: " << jogador.vida_usuario << "            ^                                   ^ Vida: " << jogador.vida_inimigo << "           ^"<< endl;
    cout << setw(3) << "^<><><><><><><><><><>^                                   ^<><><><><><><><><><>^"<< endl; 
    cout << endl;

}

void introducao ()
{   
    cout << "Bem-vindo ao Batalha Naval" << endl;
    cout << endl;
    cout << "Qual seu nome?" << endl;
    fflush(stdin);
    cin >> jogador.nome;
}

void batalha_naval () //Jogo
{
    jogador.placar = 0; //Placar
    jogador.campo[N][N]; //parametro por matriz
    jogador.cpu[N][N];  //parametro por matriz
    
    // Agua inimiga
    
    for(jogador.l = 0; jogador.l <= 10; jogador.l++)
    {
        for(jogador.c = 0; jogador.c <= 10; jogador.c++)
        {
            jogador.inimigo[jogador.l][jogador.c] = '+';
        }
    }

        //Posicionar navios inimigos
        int SubA, SubB;

        srand(time(NULL));
        for (int i = 0; i < 2; i++)
        {   
            SubA = (rand()%7) + 1;
            SubB = (rand()%7) + 1;
            jogador.inimigo[SubA][SubB] = 'S';
        }

        int H1, H2;

        for (int i = 0; i < 2; i++)
        {
            H1 = (rand()%10) + 2;
            H2 = (rand()%10) + 2;
           if (jogador.inimigo[H1][H2] == '+' && jogador.inimigo[H1-1][H2] == '+' && jogador.inimigo[H1][H2-1] == '+' && jogador.inimigo[H1][H2+1] == '+')
           {   
               if (jogador.inimigo[H1-1][H2-1] == '+' && jogador.inimigo[H1-1][H2+1] == '+' && jogador.inimigo[H1][H2-2] == '+' && jogador.inimigo[H1][H2+2] == '+')
               {
                    jogador.inimigo[H1][H2] = 'H';
                    jogador.inimigo[H1-1][H2] = 'H';
                    jogador.inimigo[H1][H2-1] = 'H';
                    jogador.inimigo[H1][H2+1] = 'H'; 
               }
           }
            else
            {
                   i--;
            }
        }
        
    //Preenchimento AGUA
    for(jogador.l = 0; jogador.l < 10; jogador.l++)
    {
        for(jogador.c = 0; jogador.c < 10; jogador.c++)
        {
            jogador.campo[jogador.l][jogador.c] = '+';
        }
    }
    //Saida tabela
    cout << endl;
    cout << setw(2) << "  Tabela Usuario  "  << endl;
    cout << setw(2) << "    A  B  C  D  E  F  G  H  I  J" << endl;
    for(jogador.l=0;jogador.l<10;jogador.l++){
        cout<< setw(2) << (jogador.l+1) << " ";
        for(jogador.c=0;jogador.c<10;jogador.c++){ 
            cout<< setw(2) << jogador.campo[jogador.l][jogador.c] <<  " " ;
        }
        cout << endl;
    }
    //zerar vetor tabela ataque

    for(jogador.li = 0; jogador.li <= 10; jogador.li++)
    {
        for(jogador.co = 0; jogador.co <= 10; jogador.co++)
        {
            jogador.cpu[jogador.li][jogador.co] = '+';
        }
    }

     // Navios do Usuario
    for (int i = 0; i < 2; i++)
    {
        do{
            cout << "Posicione a linha e coluna do seu submarino" << endl;
            cin >> jogador.x >> jogador.y;
        }while (preenchesubmarino(jogador.x, jogador.y) == -1);
    }
    

     
    
   
    int posicaoHL;
    char posicaoHC;
    cout << endl;
    cout << "Posicione a linha e coluna do seu Hidro-aviao" << endl;
    for (int i = 0; i < 2; i++)
    {
       cin >> posicaoHL >> posicaoHC;
       posicaoHC = posicaoHC - 65;
       posicaoHL = posicaoHL - 1;
       if (jogador.campo[posicaoHL][posicaoHC] == '+' &&
             jogador.campo[posicaoHL-2][posicaoHC] == '+' && jogador.campo[posicaoHL+1][posicaoHC] == '+' && jogador.campo[posicaoHL-1][posicaoHC-1] == '+')
       {
           if ( jogador.campo[posicaoHL-1][posicaoHC+1] == '+' &&  jogador.campo[posicaoHL+1][posicaoHC-1] == '+' && jogador.campo[posicaoHL+1][posicaoHC+1] == '+' &&
                jogador.campo[posicaoHL][posicaoHC+2] == '+')
           {
               if (jogador.campo[posicaoHL][posicaoHC-2] == '+' && jogador.campo[0][posicaoHC] == '+' &&
                jogador.campo[posicaoHL][0] == '+' && jogador.campo[1][posicaoHC] == '+')
               {
                    jogador.campo[posicaoHL][posicaoHC] = 'H';
                    jogador.campo[posicaoHL-1][posicaoHC] = 'H';
                    jogador.campo[posicaoHL][posicaoHC-1] = 'H';
                    jogador.campo[posicaoHL][posicaoHC+1] = 'H';
               }    
           }
       } 
       else
       {
            i--; 
            cout << "Posicao invalida, por favor digite novamente" << endl;
            
       }
       
    } 

    //Condicao para continuar jogando


    while (jogador.vida_usuario != 0 && jogador.vida_inimigo != 0)
    {
        cout << endl;
	//Tentativa usuario
        do {
            TabelaInterface(jogador.campo, jogador.cpu);
            cout << endl;
            cout << "Informe a Linha e Coluna para ataque:" << endl;  
            cout << "(linha de 1 a 10) (coluna de A a J)" << endl;
            cin >> jogador.xtiro >> jogador.ytiro;         
            jogador.xtiro = jogador.xtiro-1;
            jogador.ytiro = jogador.ytiro-65;
            cout << jogador.xtiro << endl;
            
            if(jogador.xtiro < 10 && jogador.xtiro >=0 &&
                jogador.ytiro < 10 && jogador.ytiro >=0)
            {
                if (jogador.inimigo[jogador.xtiro][jogador.ytiro] == '+')
                {
                    jogador.inimigo[jogador.xtiro][jogador.ytiro] = '#';
                    jogador.cpu[jogador.xtiro][jogador.ytiro] = '#';
                    cout << endl;
                    cout << endl;
                    cout << "ALIADOS-----------------Sua bola de canhao passou perto, mas voce errou!" << endl;
                    cout << endl;
                    jogador.placar++;
                }
                else if (jogador.inimigo[jogador.xtiro][jogador.ytiro] == 'S')
                {
                    jogador.inimigo[jogador.xtiro][jogador.ytiro] = 'X';
                    jogador.cpu[jogador.xtiro][jogador.ytiro] = 'X';
                    cout << "ALIADOS-----------------Parabens! Voce afundou um SUBMARINO." << endl;
                    cout << "ALIADOS-----------------Receba mais uma vida pelos serviÃ§os" << endl;
                    cout << endl;
                    jogador.vida_usuario++;
                    jogador.vida_inimigo--;
                    jogador.placar++;
                }
                else if (jogador.inimigo[jogador.xtiro][jogador.ytiro] == 'H')
                {
                    jogador.inimigo[jogador.xtiro][jogador.ytiro] = 'X';
                    jogador.cpu[jogador.xtiro][jogador.ytiro] = 'X';
                    cout << endl;
                    cout << endl;
                    cout << "ALIADOS-----------------Parabens! Voce acertou um HIDRO-AVIAO." << endl;
                    cout << endl;
                    jogador.vida_inimigo--;
                    jogador.placar++;    
                }
                else if (jogador.inimigo[jogador.xtiro][jogador.ytiro] != 'X' && jogador.inimigo[jogador.xtiro][jogador.ytiro] != 'H' && jogador.cpu[jogador.xtiro][jogador.ytiro] != '+')
                {
                    cout << "VOCE DEU UM TIRO EM UM LOCAL REPETIDO OU INVALIDO, ATIRE NOVAMENTE!" << endl;
                    cout << "A TABELA DE TIROS ESTA AI PARA LHE AJUDAR..." << endl;
                    cout << "SEMPRE QUE REPETIR UM TIRO, SEU OPONENTE GANHA UMA RODADA DE TIRO A SUA FRENTE" << endl;
                    system("pause");
                } 
            }
        }
        while (jogador.inimigo[jogador.xtiro][jogador.ytiro] != '#' && jogador.inimigo[jogador.xtiro][jogador.ytiro] != 'X');
        
    //tentativa Maquina
        int lmaquina, cmaquina;
        lmaquina = (rand()%7) + 1;
        cmaquina = (rand()%7) + 1;
        while(jogador.inimigo[lmaquina][cmaquina] == '#' && jogador.inimigo[lmaquina][cmaquina] == 'S' && jogador.inimigo[lmaquina][cmaquina] == 'H')
        {
        lmaquina = (rand()%7) + 1;
        cmaquina = (rand()%7) + 1;
        }    
        if(lmaquina < 10 && lmaquina >=0 &&
	        cmaquina < 10 && cmaquina >=0)
        { 
		    if (jogador.inimigo[lmaquina][cmaquina] == '+')
            {
                jogador.campo[lmaquina][cmaquina] = '#';
                cout << endl;
                cout << endl;
                cout << " INIMIGO-----------------Nenhuma embarcacao sua foi acertada!" << endl;
                cout << " INIMIGO-----------------Mas tome cuidado, o inimigo esta proximo!" << endl;
                cout << endl;
            }
            if (jogador.inimigo[lmaquina][cmaquina] == 'S')
            {
                jogador.campo[lmaquina][cmaquina] = 'X';
                cout << endl;
                cout << endl;
                cout << " INIMIGO-----------------O inimigo Caveira afundou seu SUBMARINO!" << endl;
                cout << " INIMIGO-----------------Voce perdera uma vida pelo deslize" << endl;
                cout << endl;
                jogador.vida_usuario--;
            }
            if (jogador.inimigo[lmaquina][cmaquina] == 'H')
            {
                jogador.campo[lmaquina][cmaquina] = 'X';
                cout << endl;
                cout << endl;
                cout << " INIMIGO-----------------O inimigo Caveira acertou parte do seu Hidro-aviao" << endl;
                cout << " INIMIGO-----------------Voce perdera uma vida pelo deslize" << endl;
                cout << endl;
                jogador.vida_usuario--;
            }
            }
        }
    //CondiÃ§oes de vitoria ou derrota
   	    if(jogador.vida_usuario == 0){
    	    system("cls");
            cout << "----------------FIM DO JOGO------------" << endl;
            cout << "Jogador: " << jogador.nome << endl << "Naufragou apos: " << jogador.placar << " jogadas" << endl;
            cout << endl;
            cout << "Verifique onde o inimigo escondeu suas tropas" << endl;
            cout << endl;
            cout << endl;
            cout << setw(2) << "  TRIPULACAO INIMIGA  " << endl;
            cout << setw(2) << "    A  B  C  D  E  F  G  H  I  J" <<endl;
            for(int l=0;l<10;l++){
                cout << setw(2) <<(l+1)<<" ";
                for(int c=0;c<10;c++){
                    cout << setw(2) <<jogador.inimigo[l][c]<<" ";
                }
            cout << endl;
            }
        }
        else if(jogador.vida_inimigo == 0){
            system("cls");
            cout << "----------------FIM DO JOGO------------" << endl;
            cout << "----------PARABENS PELA VITORIA---------" << endl; 
            cout << "Jogador: " << jogador.nome << endl << "Venceu apos: " << jogador.placar << " jogadas" << endl;
            cout << endl;
            cout << "Verifique onde o inimigo escondeu suas tropas" << endl;
            cout << endl;
            cout << endl;
            cout << setw(2) << "  Tabela Inimigo  " << endl;
            cout << setw(2) << "    A  B  C  D  E  F  G  H  I  J" <<endl;
            for(int l=0;l<10;l++){
                cout << setw(2) <<(l+1)<<" ";
                for(int c=0;c<10;c++){
                    cout << setw(2) <<jogador.inimigo[l][c]<<" ";
                }
            cout << endl;
            }
        }
        cout << endl;
    }
int main ()
{
    do
    {
        system("cls");
        setlocale(LC_ALL,"portuguese");
        introducao();
        system("cls");
        batalha_naval();
    }while(escolha()== 1);
system("pause");
return 0;   
}
