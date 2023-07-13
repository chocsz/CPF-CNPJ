#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

  int option;
  int cpf [11];
  srand(time(NULL));

  printf("Insira 1 para gerar um CPF aleatório válido;\n");
  printf("Insira 2 para gerar um CPF válido de um estado específico;\n");
  printf("Insira 3 para validar um CPF;\n");
  printf("Insira 4 para recuperar o estado de um CPF;\n");
  printf("Insira 5 para gerar um CNPJ válido;\n");
  printf("Insira 6 para validar um CNPJ.\n\n");
  scanf("%d", &option);

  if(option == 2) {
    char state [2];
    printf("\nInsira a sigla do estado de emissão do CPF gerado: ");
    scanf("%s", state);
  
    if(!strcmp(state, "RS")) cpf[8] = 0;
    if(!strcmp(state, "DF")) cpf[8] = 1;
    if(!strcmp(state, "GO")) cpf[8] = 1;
    if(!strcmp(state, "MT")) cpf[8] = 1; 
    if(!strcmp(state, "MS")) cpf[8] = 1;
    if(!strcmp(state, "TO")) cpf[8] = 1;
    if(!strcmp(state, "AM")) cpf[8] = 2;
    if(!strcmp(state, "PA")) cpf[8] = 2;
    if(!strcmp(state, "RR")) cpf[8] = 2;
    if(!strcmp(state, "AP")) cpf[8] = 2;
    if(!strcmp(state, "AC")) cpf[8] = 2;
    if(!strcmp(state, "RO")) cpf[8] = 2;
    if(!strcmp(state, "CE")) cpf[8] = 3;
    if(!strcmp(state, "MA")) cpf[8] = 3;
    if(!strcmp(state, "PI")) cpf[8] = 3;
    if(!strcmp(state, "PA")) cpf[8] = 4;
    if(!strcmp(state, "PE")) cpf[8] = 4;
    if(!strcmp(state, "AL")) cpf[8] = 4;
    if(!strcmp(state, "RN")) cpf[8] = 4;
    if(!strcmp(state, "SE")) cpf[8] = 5;
    if(!strcmp(state, "BA")) cpf[8] = 5;
    if(!strcmp(state, "MG")) cpf[8] = 6;
    if(!strcmp(state, "ES")) cpf[8] = 7;
    if(!strcmp(state, "RJ")) cpf[8] = 7;
    if(!strcmp(state, "SP")) cpf[8] = 8;
    if(!strcmp(state, "SC")) cpf[8] = 9;
    if(!strcmp(state, "PR")) cpf[8] = 9;
  } //inserindo o estado no cpf

  if(option == 3 || option == 4) {
    size_t cpf1;
    int number;
    printf("\nInsira o CPF: ");
    scanf("%lu", &cpf1);
    for(int i = 0; cpf1 > 0; i++) {
      cpf[10-i] = cpf1 % 10;
      cpf1 /= 10;
    }
  } //lendo o cpf
  
  if(option == 1 || option == 2 || option == 3) {
    int trocado = 0;
    do {
      trocado = 1;
      int dv1 = 0;
      int dv2 = 0;
      
      for(int i = 0; i < sizeof(cpf)/sizeof(int) && option != 3; i++) {
        if(option == 2 && i != 8) 
          cpf[i] = rand() % 10;
        
        if(option == 1) 
          cpf[i] = rand() % 10;
        } 
      
      for(int i = 0; i < 9; i++) {
        dv1 += cpf[i] * (10-i);
      } //contando dv1

      if(dv1 < 2) dv1 = 0;
      else {
        dv1 = dv1 % 11;
        dv1 = 11 - dv1; 
      } //operando dv1

      if(dv1 != cpf[9] && option == 3) {
        trocado = 0;
        printf("\nO CPF inserido é inválido.");
      } //dv1 falso para option3
      
      if(dv1 == cpf[9]) { //dv2
        
        for(int i = 0; i < 10; i++) {
          dv2 += cpf[i] * (11-i);
        } //contando dv2

        if(dv2 < 2) dv2 = 0;
        else {
          dv2 = dv2 % 11;
          dv2 = 11 - dv2; 
        } //operando dv2

        if(dv2 == cpf[10] && option != 3) { //se o valor for válido
          printf("\nCPF: ");
      
          for(int i = 0; i < sizeof(cpf)/sizeof(int); i++) { 
            if(i == 3 || i == 6) printf(".");
            if(i == 9) printf("-");
            printf("%d", cpf[i]);
          } //printando o cpf
          trocado = 0;
        }
        if(option == 3) {
          trocado = 0;
          if(dv2 == cpf[10]) printf("\nO CPF inserido é válido.");
            else printf("\nO CPF inserido é inválido.");
        }
      }      
    } while(trocado);
  } //calculando validadores
  
  if(option == 4) { printf("\nO CPF");
    switch(cpf[8]) {
      case 0: printf(" é de RS."); break; 
      case 1: printf(" é de DF, GO, MT, MS ou TO."); break; 
      case 2: printf(" é de AM, PA, RR, AP, AC ou RO."); break; 
      case 3: printf(" é de CE, MA ou PI."); break; 
      case 4: printf(" é de PA, PE, AL ou RN."); break; 
      case 5: printf(" é de BA ou SE."); break; 
      case 6: printf(" é de MG."); break; 
      case 7: printf(" é de RJ ou ES."); break; 
      case 8: printf(" é de SP."); break; 
      case 9: printf(" é de PR ou SC.");
    }
  } //tirando o estado

  if(option == 5 || option == 6) {
    int trocado;
    int cnpj[14];
    
    do {
      trocado = 0;
      int dv1 = 0;
      int dv2 = 0;
      int peso = 5;
    
      if(option == 6) {
        size_t cnpj1;
        
        printf("\nInsira o CNPJ: ");
        scanf("%lu", &cnpj1);
      
        for(int i = 0; cnpj1 > 0; i++) {
          cnpj[13-i] = cnpj1 % 10;
          cnpj1 /= 10;
        }
      }

      if(option == 5) {
        for(int i = 0; i < 14; i++) {
          cnpj[i] = rand() % 10;
        }
      }
      
      for(int i = 0; i < 12; i++) {
        if(i == 4) peso = 9;
        dv1 += cnpj[i] * peso;
        peso--;
      }
      dv1 = dv1 % 11;
    
      if(dv1 == 1 || dv1 == 0) 
        dv1 = 0;
      else 
        dv1 = 11 - dv1;
      
      if(dv1 != cnpj[12]) {
        if(option == 5) trocado = 1;
        if(option == 6) printf("\n O CNPJ é inválido.");
      }
      
      if(dv1 == cnpj[12]) {
        peso = 6;
        
        for(int i = 0; i < 13; i++) {
          if(i == 5) peso = 9;
          dv2 += cnpj[i] * peso;
          peso--;
        }
        dv2 = dv2 % 11;

        if(dv2 == 1 || dv2 == 0) 
          dv2 = 0;
        else 
          dv2 = 11 - dv2;

        if(cnpj[13] != dv2) {
          if(option == 6) printf("\nO CNPJ é inválido.");
          else trocado = 1;
        }
        if(cnpj[13] == dv2) {
          if(option == 6) printf("\nO CNPJ inserido é válido.");
          else { 
            printf("\nCNPJ: ");
            for(int i = 0; i < 14; i++) {
              if(i == 2 || i == 5) printf(".");
              if(i == 8) printf("/");
              if(i == 12) printf("-");
              printf("%d", cnpj[i]);
            }
          }
        }
      }  
    } while(trocado);
  } //cnpj
  
  return 0;
}
