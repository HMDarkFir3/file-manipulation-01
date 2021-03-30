#include <stdio.h>
#include <stdlib.h>

//Global variables
char product1[20];
char product2[20];
char product3[20];
int amount1 = 0;
int amount2 = 0;
int amount3 = 0;

//Utils ------------------------------------------------------|X*
void clearScreen() { // Limpa tela
    system("cls");
}

void jumpLine() { // Pula linha
    printf("\n");
}
// -----------------------------------------------------------|X*

// Menu Options ----------------------------------------------|O*
// 1 --|--
void dataEntries() { // Entrada de dados
    int change;
    char file[20];

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Escrever no arquivo");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    backHere:


    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            clearScreen();

            FILE *f;

            f = fopen("product.txt", "r+");

            if(f == NULL) {
                f = fopen("product.txt", "w");
                f = fopen("product.txt", "r+");
            }

            printf("\tDigite o 1 produto: ");
            scanf("%s", &product1);

            printf("\tDigite a quantidade de %s: ", product1);
            scanf("%d", &amount1);

            jumpLine(); // Pula linha

            printf("\tDigite o 2 produto: ");
            scanf("%s", &product2);

            printf("\tDigite a quantidade de) %s: ", product2);
            scanf("%d", &amount2);

            jumpLine(); // Pula linha

            printf("\tDigite o 3 produto: ");
            scanf("%s", &product3);

            printf("\tDigite a quantidade de %s: ", product3);
            scanf("%d", &amount3);

            // Produto 1
            fwrite(&product1, sizeof(product1), 1, f);
            fwrite(&amount1, sizeof(amount1), 1, f);

            // Produto 2
            fwrite(&product2, sizeof(product2), 1, f);
            fwrite(&amount2, sizeof(amount2), 1, f);

            //Produto 3
            fwrite(&product3, sizeof(product3), 1, f);
            fwrite(&amount3, sizeof(amount3), 1, f);

            fclose(f);

            clearScreen();
            dataEntries();
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataEntries();
            break;
    }

}

// 2 --|--
void dataList() { // Listar dados
    int change;

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Listar dados");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            clearScreen();

            FILE *f;

            f = fopen("product.txt", "r");

            if(f == NULL) {
                printf("\tNenhum arquivo encontrado.");
                Sleep(2000);
                clearScreen();
                dataList();
            }

            printf("\tProdutos:\n");

            fread(&product1, sizeof(product1), 1, f);
            fread(&amount1, sizeof(amount1), 1, f);
            printf("\t%s: %d unidades\n", product1, amount1);

            fread(&product2, sizeof(product2), 1, f);
            fread(&amount2, sizeof(amount2), 1, f);
            printf("\t%s: %d unidades\n", product2, amount2);

            fread(&product3, sizeof(product3), 1, f);
            fread(&amount3, sizeof(amount3), 1, f);
            printf("\t%s: %d unidades\n", product3, amount3);

            jumpLine();

            fclose(f);

            dataList();
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            clearScreen();
            dataList();
            break;
    }
}

// 3 --|--
void dataSearchName() { // Pesquisar dados por nome
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Pesquisar dados por nome");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\tPesquisa de dados por nome");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataSearchName();
            break;
    }
}

// 4 --|--
void dataSearchLetter() { //Pesquisar dados por letra
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Pesquisar dados por letra");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\tPesquisa de dados por letra");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataSearchLetter();
            break;
    }
}

// 5 --|--
void dataEdit() { // Alterar dados
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Alterar dados");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\Alterar dados");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataEdit();
            break;
    }
}

// 6 --|--
void dataDelete() { // Excluir dados
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Excluir dados");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\Excluir dados");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataDelete();
            break;
    }
}

// 7 --|--
void quit() { // Fechar o programa
    clearScreen();
    printf("\tFinalizando o programa...");
    Sleep(3000);
    exit(0);
}
// ----------------------------------------------------------|O*

// Build Menu -----------------------------------------------|X*
void buildMenuTopLine() {
    //Menu Top --------------------------------------------|
    printf("\t%c", 201);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 187);

    jumpLine();
}

void buildMenuItem(char str[]) {
    int countLetters = 0;

    for(int i = 0; i < 36; i++) {
        if(str[i] == '\0') {
            break;
        } else {
            countLetters++;
        }
    }

    printf("\t%c", 186);
    printf("%s", str);

    while(countLetters < 36) {
        printf("%c", 32);
        countLetters++;
    }

    printf("%c", 186);
}

void buildMenuBottomLine() {
    //Menu Bottom -----------------------------------------|
    printf("\t%c", 200);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 188);

    jumpLine(); //
}

void menu() {
    //Variavel
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu Item -------------------------------------------|
    buildMenuItem(" 1 - Entrada de dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Listar dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 3 - Pesquisar dados por nome");
    jumpLine(); // Pula linha
    buildMenuItem(" 4 - Pesquisar dados pela 1 letra");
    jumpLine(); // Pula linha
    buildMenuItem(" 5 - Alterar dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 6 - Excluir dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 7 - Sair");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            dataEntries();
            break;
        case 2:
            clearScreen();
            dataList();
            break;
        case 3:
            dataSearchName();
            break;
        case 4:
            dataSearchLetter();
            break;
        case 5:
            dataEdit();
            break;
        case 6:
            dataDelete();
            break;
        case 7:
            quit();
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            menu();
            break;
    }
}
// ----------------------------------------------------------|X*

// Home -----------------------------------------------------|O*
int main() {
    menu();
    return 0;
}
// ----------------------------------------------------------|O*
