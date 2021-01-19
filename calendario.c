#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

// GABRIELA VITORINO//

// Programa que exibe Calendário a partir do ano digitado após 1582 //

// Protótipos da funções: //
 int calculo_aureo(int g); 
 int calculo_seculo(int c); 
 int calculo_epacta(int e);
 int calculo_f1(int x);
 int calculo_f2(int z);
 int calculo_luacheia(int n);
 int calculo_dompascoa(int d);
 int calculo_dia(int dia);
 int calculo_mes(int mes);
 int calculo_anobissexto(int ano);
 int calculo_diasemana(int k);
 int printa_calendario(int num_dias);
 
    // Declarando variáveis globais//
    int c = 0, g = 0, e = 0, x = 0, z = 0, n = 0, d = 0;  // sendo 'g' o número áureo, 'c' o século, 'e' o epacta, 'x' e 'z' os fatores de correção//  
    int  y = 0, dia = 0, mes = 0, ano = 0, bissexto = 0, k = 0, num_dias = 0; // sendo 'y' o ano e 'k' o dia da semana em que cai a páscoa //
    int  i, j, loop, loop1, loop2, loop3;
    int jan, fev, mar, abr, mai, jun, jul, agos, set, out, nov, dez; //variáveis para fazer loop //
    char *meses_do_ano[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    int main(void){ // Função principal //
     setlocale(LC_ALL, "Portuguese"); // para funcionar o cedilha do mês de março//

         
           scanf("%d", &y); // Lê o ano digitado pelo usuário //

           g = calculo_aureo(g);
               c = calculo_seculo(c);
                  x = calculo_f1(x);
                    z = calculo_f2(z);
                      e = calculo_epacta(e);
                        n = calculo_luacheia(n);  
                          d =  calculo_dompascoa(d);
                           dia = calculo_dia(dia);
                              mes = calculo_mes(mes);
                                ano = calculo_anobissexto(ano);
                                  k = calculo_diasemana(k);
                                   num_dias = printa_calendario(num_dias);


                              
    return 0;
    }


            int calculo_aureo(int g){ // Função que calcula o número áureo //
               g = (y%19) + 1;
   
                return(g);
            }


                  int calculo_seculo(int c){ // Função que calcula o século //
                    c = (y/100) + 1;
   
                      return(c);
                   }

                        int calculo_f1(int x){ // Função que calcula o fator de correção 1 //
                           c = calculo_seculo(c);
                               x = ( (3*c) / 4) - 12; 
                            return(x);
                        }


                              int calculo_f2(int z){ // Função que calcula o fator de correção 2 //
                               c = calculo_seculo(c);
                                  z = ( ((8*c) + 5) / 25) - 5; 

                                   return(z);
                              }



                                 int calculo_epacta(int e){ // Função que calcula o epacta //
                                    x = calculo_f1(x);
                                       z = calculo_f2(z);
                                          g = calculo_aureo(g);
                                         
                                            e =  (( (11*g) + 20 + z - x)  % 30); 

                                              if( (e == 25 && g > 11)  || (e == 24) ){
                                                  e = e + 1; 
                                             }
                                             
                                    return(e);
                                 }   


                                      int calculo_luacheia(int n){  // Cálculo da lua cheia //
                                          e = calculo_epacta(e);
                                             n = 44 - e;

                                                if(n < 21){
                                                   n = n + 30; 
                                                }
                                                 
                                                 return(n);
                                       } 

                                                   int calculo_dompascoa(int d){
                                                      x = calculo_f1(x);
                                                         d = ( (5*y) / 4) - (x + 10); 
                                                            return(d);
                                                   }

                           
                                                      	/*Dia e mês da Páscoa: Faça N receber (N + 7) menos o resto da
                                                          divisão de (D + N) por 7. 
                                                          Se N > 31, a Páscoa será no dia (N - 31) de abril,
                                                           caso contrário será em N de março. */

                                                      int calculo_dia(int dia){
                                                         n = calculo_luacheia(n);
                                                            d = calculo_dompascoa(d);

                                                               n =  (n + 7) -  ((d + n)% 7) ; 

                                                                     if( n > 31){
                                                                       dia = (n - 31); // EM ABRIL //

                                                                     }else{
                                                                       dia = n;  // EM MARÇO //
                                                                     }
      
                                                                        return(dia);
                                                      } 


                                                            int calculo_mes(int mes){ // Calcula o mês da páscoa //
                                                                n = calculo_luacheia(n);
                                                                   d = calculo_dompascoa(d);

                                                                        n =  (n + 7) -  ((d + n)% 7) ;

                                                                           if( n > 31){
                                                                               mes = 4; // EM ABRIL //

                                                                           }else{
                                                                               mes = 3;  // EM MARÇO //
                                                                           }

                                                                               return(mes);   
                                                                                 
                                                               }

                                                                         int calculo_anobissexto(int ano){
                                                                            ano = y;

                                                                              if(ano%100 == 0){
                                                                                 ano = (ano/100);

                                                                              }if(ano%4 == 0){
                                                                                 bissexto = 1;

                                                                              }else{
                                                                                 bissexto = 0;
                                                                              }

                                                                              return(bissexto);
                                                                         }

      int calculo_diasemana(int k){
         d = calculo_dia(dia);
           mes = calculo_mes(mes);
             
                 k = (dia + (2*mes) + ((3*(mes+1))/5) + y + (y/4) - (y/100) + (y/400) + 2) %7; //Prova de que a páscoa cai no domingo - teste//
             

                        //Quantos dias se passaram da páscoa até 1 de janeiro//
                            if (mes == 3){ //se a páscoa for em março//
                              num_dias = (dia + 28 + 30 + bissexto); //número de dias que se passaram de 1 de janeiro até o dia da páscoa, somando os dias de março, fevereiro e janeiro//
                  
                           }else if (mes == 4){ //se a páscoa for em abril//
                              num_dias = (dia + 31 + 28 + 30 + bissexto); //número de dias que se passaram de 1 de janeiro até o dia da páscoa, somando os dias de abril, março, fevereiro e janeiro//
                           }

                                
                                 ///DECREMENTANDO A DATA DA PÁSCOA ATÉ CHEGAR EM PRIMEIRO DE JANEIRO//
                                 while (num_dias > 0){
                                    for(j = 0; j < 7;  j++){
                                       num_dias--;
                                    }
                                    //semana++; //calcula o NÚMERO DE SEMANAS QUE SE PASSARAM DE 1 DE JANEIRO ATÉ A DATA DA PÁSCOA//
                                 }

         
       return(k);                                                       
      }

                        

                     int printa_calendario(int num_dias){ //Função que printa o calendário: //

                        // chama funções que serão usadas: //
                        ano = calculo_anobissexto(ano);
                        k = calculo_diasemana(k);
               
                        // Printando o Calendário: //                    
                        printf("Calendario do ano %d\n", y);  

                          
                              // Printando os dias no Calendário //
                              
                                
                                       switch(num_dias){ // Para cada dia da semana em que um ano começa há um calendário diferente //

                              case 0:

                                 for(j = 0; j < 1; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");
                     
                                                      // JANEIRO E FEVEREIRO //
                                                   

                                                          for(jan = 1; jan <= 7; jan++){ // PRIMEIRA SEMANA DE JANEIRO //
                                                             printf(" 0%d ", jan);
                                                          }
                                                             printf("|| ");

                                                         for(i = 1; i <= 3; i++){ // Quando há dias vazios no calendário o laço preenche com '--' //  
                                                             printf(" -- ");
                                                          }

                                                          // fevereiro começa no SÁBADO, pois quando janeiro começa na QUARTA, termina na SEXTA//
                                                         for(fev = 1; fev <= 4; fev++){ // PRIMEIRA SEMANA DE FEVEREIRO //
                                                             printf(" 0%d ", fev);
                                                          }
                                                            printf("|");
                                                            printf("\n| ");

                                                         for(jan = 8; jan <= 9; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                         for(jan = 10; jan <= 14; jan++){ 
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 5; fev <= 9; fev++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" 0%d ", fev);
                                                         }

                                                         for(fev = 10; fev <= 11; fev++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");


                                                         for(jan = 15; jan <= 21; jan++){ // TERCEIRA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 12; fev <= 18; fev++){ // TERCEIRA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jan = 22; jan <= 28; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                            }

                                                            printf("|| ");

                                                         for(fev = 19; fev <= 25; fev++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //"quinta semana" = quinta linha //

                                                         for(jan = 29; jan <= 31; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                         for(i = 1; i <= 4; i++){ 
                                                            printf(" -- ");
                                                         }

                                                            printf("|"); 
                                                            printf("| ");
                                                            
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                              if(bissexto == 1){ // se o ano for bissexto fevereiro vai até o dia 29 // 

                                                         for(fev = 26; fev <= 29; fev++){ // "QUINTA SEMANA" DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                          }

                                                         for(i = 1; i <= 3; i++){ 
                                                            printf(" -- ");
                                                         }
                                                               
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                               //SEXTA LINHA: //
                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");

                                              
                  
                                                   
                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //
                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mar = 1; mar <= 3; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(abr = 1; abr <= 7; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 4; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                            printf(" 10 ");
                                                            printf("|| ");
            
                                                      for(abr = 8; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 14; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 11; mar <= 17; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 15; abr <= 21; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 18; mar <= 24; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 22; abr <= 28; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 25; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                            printf("|| ");
                                                            
                              
                                                      for(abr = 29; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");

                            

                        }
                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 5; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 2; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 6; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                      for(mai = 10; mai <= 12; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 3; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 13; mai <= 19; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 10; jun <= 16; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 20; mai <= 26; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 17; jun <= 23; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 27; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");


                                                      for(jun = 24; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                            // SEXTA LINHA //
                                                            

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");
                            }

                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 

                                                         for(jul = 1; jul <= 7; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 4; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 8; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <= 14; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                            
                                                            printf("|| ");

                                                         for(agos = 5; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 11; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(jul = 15; jul <= 21; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                         
                                                         for(agos = 12; agos <= 18; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 22; jul <=28; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 19; agos <= 25; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 29; jul <=31; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                         
                                                         for(i = 1; i <= 4; i++){
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(agos = 26; agos <= 31; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }
                                                            printf(" -- ");

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");


                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|");

                                                            printf("\n");                 
                            }


                            for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|| ");
                                                            printf(" -- ");
                                                         

                                                         for(out = 1; out <= 6 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }                                                            
                                                            printf("|\n| ");

                                                          for(set = 2; set <= 8; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 7; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }

                                                         for(out = 10; out <= 13 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                            
                                                            printf("|\n| ");
                                                            printf(" 09 ");

                                                         for(set = 10; set <= 15; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 14; out <= 20; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n| ");
                                                         
                                                         for(set = 16; set <= 22; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 21; out <= 27; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n| ");

                                                         for(set = 23; set <= 29; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }
                                                            printf("|| ");

                                                         for(out = 28; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                         
                                                            printf("|\n| ");
                                                            printf(" 30 ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|");
                                                            printf("\n");


                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //

                                                         
                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }


                                                         for(nov = 1; nov <= 3; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }  
                                                            printf(" 01 ");
                                                            printf("|\n| ");

                                                         for(nov = 4; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                            printf(" 10 ");
                                                            printf("|| ");

                                                         for(dez = 2; dez <= 8; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                            printf("|\n| ");

                                                         for(nov = 11; nov <= 17; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");
                                                            printf(" 09 ");

                                                         for(dez = 10; dez <= 15; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n| ");

                                                         for(nov = 18; nov <= 24; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            
                                                            printf("|| ");

                                                         for(dez = 16; dez <= 22; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n| ");
                                                         
                                                         
                                                         for(nov = 25; nov <= 30; nov++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf(" -- ");
                                                            printf("|| ");

                                                          for(dez = 23; dez <= 29 ; dez++){  
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");
                                                         
                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(dez = 30; dez <= 31; dez++){  
                                                            printf(" %d ", dez);
                                                         }
                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            // sexta linha //
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                             

                                        }
                                        
                                    }
                                    
                                              if(bissexto == 0){

                                                      for(fev = 26; fev<= 28; fev++){ //fim do mes de fevereiro //
                                                        printf(" %d ", fev);
                                                      }

                                                      for(i= 1; i<= 4; i++){
                                                        printf(" -- ");
                                                      }
                                                        printf("|\n| ");

                                                       // sexta linha //
                                                      for(i = 1; i<= 7; i++){
                                                         printf(" -- ");
                                                      }
                                                         printf("|| ");

                                                      for(i = 1; i<= 7; i++){
                                                         printf(" -- ");
                                                      }
                                                         printf("|\n");

                              
                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }
                                                      
                                                      for(mar = 1; mar <= 4; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                      
                                                             printf("|| ");

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }

                                                      // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 01 ");
                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 5; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 11; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 2; abr <= 8; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 12; mar <= 18; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
                                                            printf(" 09 ");
            
                                                      for(abr = 10; abr <= 15; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 19; mar <= 25; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 16; abr <= 22; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 26; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }     
                                                            printf(" -- ");
                                                            printf("|| ");

                                                      for(abr = 23; abr <= 29; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                       
                                                            printf("|");
                                                            printf("\n| ");
                                                            
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("||  30 ");

                                                       for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");

                            }

                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                            printf(" -- ");
                                                         
                                                      for(mai = 1; mai <= 6; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 3; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 7; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                      for(mai = 10; mai <= 13; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 4; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }
                                                            printf(" 10 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 14; mai <= 20; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 11; jun <= 17; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 21; mai <= 27; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 18; jun <= 24; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 28; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                        
                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");


                                                      for(jun = 25; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
  
                                                            printf(" -- ");
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");
                                                            
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");
                                                      
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|");
                                                            printf("\n");
                            }

                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 01 ");
                                                            printf("|| ");

                                                         for(i = 1; i <=2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 5 ; agos++){  
                                                            printf(" 0%d ",agos);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 2; jul <= 8; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }
                                                            printf("|| ");
                                                            
                                                         for(jul = 6; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <= 12; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("| \n| ");
                                                             printf(" 09 ");

                                                         for(jul =  10; jul <= 15; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                            printf("|| ");
                                                            

                                                         for(agos = 13; agos <= 19; agos++){ 
                                                            printf(" %d ", agos);
                                                         }

                                                             printf("| \n| ");

                                                         for(jul = 16; jul <= 22; jul++){ 
                                                            printf(" %d ", jul);
                                                         }

                                                            printf("|");
                                                            printf("| ");

                                                         for(agos= 20; agos<= 26; agos++){  
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("| \n| ");

                                                         for(jul = 23; jul <= 29; jul++){ 
                                                            printf(" %d ", jul);
                                                         }
                 
                                                             printf("|| ");

                                                         for(agos = 27; agos <= 31; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                         for(i = 1; i <= 2; i++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n| ");
                                                          
                                                       //sexta linha //

                                                         for(agos = 30; agos <= 31; agos++){  
                                                            printf(" %d ", agos);
                                                         }

                                                         for(agos = 1; agos <= 5; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");
                                                            
                                                         for(agos = 1; agos <=7; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");

                                                                           
                            }


                           for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(set = 1; set <= 2; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 1; out <= 7; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                          for(set = 3; set <= 9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 8; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }

                                                         for(out = 10; out <= 14 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                            
                                                            printf("|\n| ");
                              
                                                         for(set = 10; set <= 16; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 15; out <= 21; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");
                                                         
                                                         for(set = 17; set <= 23; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 22; out <= 28; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                                                          
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(set = 24; set <= 30; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }
                                                            printf("|| ");
                                                            
                                                         for(out = 29; out <= 31; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                         for(i = 1; i <=4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");
                                                            printf("\n| ");
                                                                                                  
                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");                                                           
                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //
                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(nov = 1; nov <= 4; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 2 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 5; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 11; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 3; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 12; nov <= 18; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 10; nov <= 16; nov++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 19; nov <= 25; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 17; nov <= 23; nov++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(nov = 26; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                         for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 24; dez <= 30; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|");
                                                            printf("\n");

                                                            // sexta linha //
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("||  31 ");

                                                         for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                             
                                       }
                                    }
                                 }
                                                      break;

                              case -1: // se o mês começar em uma segunda - feira //

                                             
                                 for(j = 0; j < 1; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");
                     
                                                      // JANEIRO E FEVEREIRO //

                                                            printf(" -- ");
                                                   
                                                          for(jan = 1; jan <= 6; jan++){ // PRIMEIRA SEMANA DE JANEIRO //
                                                             printf(" 0%d ", jan);
                                                          }
                                                             printf("|| ");

                                                         for(i = 1; i <= 4; i++){ // Quando há dias vazios no calendário o laço preenche com '--' //  
                                                             printf(" -- ");
                                                          }

                                                         
                                                         for(fev = 1; fev <= 3; fev++){ // PRIMEIRA SEMANA DE FEVEREIRO //
                                                             printf(" 0%d ", fev);
                                                          }
                                                            printf("|");
                                                            printf("\n| ");

                                                         for(jan = 7; jan <=9; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                         for(jan = 10; jan <= 13; jan++){ 
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 4; fev <= 9; fev++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" 0%d ", fev);
                                                         }

                                                            printf(" 10 ");
                                                            printf("|");
                                                            printf("\n| ");


                                                         for(jan = 14; jan <= 20; jan++){ // TERCEIRA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 11; fev <= 17; fev++){ // TERCEIRA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jan = 21; jan <= 27; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                            }

                                                            printf("|| ");

                                                         for(fev = 18; fev <= 24; fev++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            

                                                         for(jan = 28; jan <= 31; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                         for(i = 1; i <= 3; i++){ 
                                                            printf(" -- ");
                                                         }

                                                            printf("|| "); 

                                                         
                                                         for(fev = 25; fev <= 28; fev++){ // "QUINTA SEMANA" DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                          }

                                                            
                                                            
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                             if(bissexto == 0){ // se o ano for bissexto fevereiro vai até o dia 29 // 

                                                         for(i = 1; i <= 3; i++){ 
                                                            printf(" -- ");
                                                         }
                                                               
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         //SEXTA LINHA: //
                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");
                                              
                                              
                                                   
                           for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //
                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mar = 1; mar <= 3; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(abr = 1; abr <= 7; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 4; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                            printf(" 10 ");
                                                            printf("|| ");
            
                                                      for(abr = 8; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 14; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 11; mar <= 17; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 15; abr <= 21; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 18; mar <= 24; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 22; abr <= 28; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 25; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                            printf("|| ");
                                                            
                              
                                                      for(abr = 29; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");
                           }

                        
                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 5; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 2; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 6; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                      for(mai = 10; mai <= 12; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 3; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 13; mai <= 19; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 10; jun <= 16; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 20; mai <= 26; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 17; jun <= 23; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 27; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");


                                                      for(jun = 24; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                            // SEXTA LINHA //
                                                            

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");
                            }

                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 

                                                         for(jul = 1; jul <= 7; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 4; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 8; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <= 14; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                            
                                                            printf("|| ");

                                                         for(agos = 5; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 11; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(jul = 15; jul <= 21; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                         
                                                         for(agos = 12; agos <= 18; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 22; jul <=28; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 19; agos <= 25; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 29; jul <=31; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                         
                                                         for(i = 1; i <= 4; i++){
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(agos = 26; agos <= 31; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }
                                                            printf(" -- ");

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");


                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|");

                                                            printf("\n");                 
                            }


                            for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|| ");
                                                            printf(" -- ");
                                                         

                                                         for(out = 1; out <= 6 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }                                                            
                                                            printf("|\n| ");

                                                          for(set = 2; set <= 8; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 7; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }

                                                         for(out = 10; out <= 13 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                            
                                                            printf("|\n| ");
                                                            printf(" 09 ");

                                                         for(set = 10; set <= 15; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 14; out <= 20; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n| ");
                                                         
                                                         for(set = 16; set <= 22; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 21; out <= 27; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n| ");

                                                         for(set = 23; set <= 29; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }
                                                            printf("|| ");

                                                         for(out = 28; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                         
                                                            printf("|\n| ");
                                                            printf(" 30 ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|");
                                                            printf("\n");


                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //

                                                         
                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }


                                                         for(nov = 1; nov <= 3; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }  
                                                            printf(" 01 ");
                                                            printf("|\n| ");

                                                         for(nov = 4; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                            printf(" 10 ");
                                                            printf("|| ");

                                                         for(dez = 2; dez <= 8; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                            printf("|\n| ");

                                                         for(nov = 11; nov <= 17; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");
                                                            printf(" 09 ");

                                                         for(dez = 10; dez <= 15; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n| ");

                                                         for(nov = 18; nov <= 24; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            
                                                            printf("|| ");

                                                         for(dez = 16; dez <= 22; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n| ");
                                                         
                                                         
                                                         for(nov = 25; nov <= 30; nov++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf(" -- ");
                                                            printf("|| ");

                                                          for(dez = 23; dez <= 29 ; dez++){  
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");
                                                         
                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(dez = 30; dez <= 31; dez++){  
                                                            printf(" %d ", dez);
                                                         }
                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            // sexta linha //
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                             

                                        }
                                        
                                    }
                                    
                                             }if(bissexto == 1){

                                                       //fim do mes de fevereiro //
                                                        printf(" 29 ");
                                                      

                                                      for(i= 1; i<= 2; i++){
                                                        printf(" -- ");
                                                      }
                                                        printf("|\n| ");

                                                       // sexta linha //
                                                      for(i = 1; i<= 7; i++){
                                                         printf(" -- ");
                                                      }
                                                         printf("|| ");

                                                      for(i = 1; i<= 7; i++){
                                                         printf(" -- ");
                                                      }
                                                         printf("|\n");

                              
                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }
                                                      
                                                      for(mar = 1; mar <= 2; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                      
                                                             printf("|| ");
                                                             printf(" -- ");

                                                      for(abr = 1; abr <= 6; abr++){  
                                                            printf(" 0%d ", abr);
                                                         }                                                            
                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 3; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 7; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 13; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 10; mar <= 16; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
                                                            
                                                      for(abr = 14; abr <= 20; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 17; mar <= 23; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 21; abr <= 27; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 24; mar <= 30; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }     
                                                            
                                                            printf("|| ");

                                                      for(abr = 28; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n|  31 ");
                                 
                                                       for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                      }
                                                      
                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");

                            }

                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }
                                                         
                                                      for(mai = 1; mai <= 4; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf(" 01 ");   
                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 5; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                      for(mai = 10; mai <= 11; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 2; jun <= 8; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 12; mai <= 18; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");
                                                            printf(" 09 ");
            
                                                      for(jun = 10; jun <= 15; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 19; mai <= 25; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 16; jun <= 22; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 26; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                        
                                                            printf(" -- ");
                                                            printf("|| ");

                                                      for(jun = 23; jun <= 29; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
  
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");
                                                            
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");
                                                      
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|");
                                                            printf("\n");
                            } 

                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 

                                                            printf(" -- ");
                                                         
                                                         // PRIMEIRA SEMANA DE JULHO //
                                                         for(jul = 1; jul <= 6; jul++){  
                                                            printf(" 0%d ", jul);
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 3; agos++){  
                                                            printf(" 0%d ",agos);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 7; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }
                                                         for(jul = 10; jul <= 13; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                            printf("|| ");
                                                            
                                                         for(jul = 4; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                             printf(" 10 ");
                                                             printf("| \n| ");

                                                         for(jul =  14; jul <= 20; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                            printf("|| ");
                                                            

                                                         for(agos = 11; agos <= 17; agos++){ 
                                                            printf(" %d ", agos);
                                                         }

                                                             printf("| \n| ");

                                                         for(jul = 21; jul <= 27; jul++){ 
                                                            printf(" %d ", jul);
                                                         }

                                                            printf("|");
                                                            printf("| ");

                                                         for(agos= 18; agos<= 24; agos++){  
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("| \n| ");

                                                         for(jul = 28; jul <= 31; jul++){ 
                                                            printf(" %d ", jul);
                                                         }

                                                         for(i = 1; i <= 3; i++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" -- ");
                                                         }
                 
                                                             printf("|| ");

                                                         for(agos = 25; agos <= 31; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }
                                                            printf("|\n| ");
                                                          
                                                       //sexta linha //
                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");
                                                            
                                                         for(agos = 1; agos <=7; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");

                                                                           
                            }


                           for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //
                                                         for(set = 1; set <= 7; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <= 2; i++){ 
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 5; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                          for(set = 8; set <= 9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }
                                                          for(set = 10; set <= 14; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 6; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }

                                                         for(out = 10; out <= 12 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                            
                                                            printf("|\n| ");
                              
                                                         for(set = 15; set <= 21; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 13; out <= 19; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");
                                                         
                                                         for(set = 22; set <= 28; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 20; out <= 26; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                                                          
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(set = 29; set <= 30; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <=5 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");
                                                            
                                                         for(out = 27; out <= 31; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                         for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");
                                                            printf("\n| ");
                                                                                                  
                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");                                                           
                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //
                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(nov = 1; nov <= 2; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 1; dez <= 7; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 3; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 8; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                         for(dez = 10; dez <= 14; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 10; nov <= 16; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 15; dez <= 21; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 17; nov <= 23; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            printf("|| ");

                                                         for(nov = 22; nov <= 28; nov++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(nov = 24; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                      
                                                            printf("|| ");

                                                         for(dez = 29; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                         for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");
                                                            printf("\n");

                                                            // sexta linha //
                                                            printf("| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");
                                                         
                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|");
                                                            printf("\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                            
                                       } 
                                    }

                                    break;
                                       
                         case -2: // quando janeiro começa em uma terça - feira //

                            for(j = 0; j < 1; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");
                     
                                                      // JANEIRO E FEVEREIRO //
                                                      
                                                         for(i = 1; i <= 2; i++){ // Para os dias vazios no calendário //  
                                                            printf(" -- ");
                                                          }

                                                          for(jan = 1; jan <= 5; jan++){ // PRIMEIRA SEMANA DE JANEIRO //
                                                             printf(" 0%d ", jan);
                                                          }
                                                             printf("|| ");

                                                         for(i = 1; i <= 5; i++){ // Quando há dias vazios no calendário o laço preenche com '--' //  
                                                             printf(" -- ");
                                                          }

                                                         for(jan = 1; jan <= 2; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");

                                                         for(jan = 6; jan <= 9; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                         for(jan = 10; jan <= 12; jan++){ 
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(loop1 = 3; loop1 <= 9; loop1++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" 0%d ", loop1);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");


                                                         for(jan = 13; jan <= 19; jan++){ // TERCEIRA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(loop2 = 10; loop2 <= 16; loop2++){ // TERCEIRA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop2);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jan = 20; jan <= 26; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                            }

                                                            printf("|| ");

                                                         for(loop3 = 17; loop3 <= 23; loop3++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop3);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //"quinta semana" = quinta linha //

                                                         for(jan = 27; jan <= 31; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                         for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|"); 
                                                            printf("| ");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                      if(bissexto == 0){  

                                                         for(fev = 24; fev <= 28; fev++){ // "QUINTA SEMANA" DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                         for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }
                                                               
                                                            printf("|\n| ");

                                                       //SEXTA LINHA: //
                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");                           
                        

                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //
                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mar = 1; mar <= 2; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                            printf(" 0%d ", mar);
                                                      }
                                                            printf("|| ");
                                                            printf(" -- ");


                                                      for(abr = 1; abr <= 6; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 3; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");
            
                                                      for(abr = 7; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 13; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 10; mar <= 16; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                      
                                                      for(abr = 14; abr <= 20; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");
                                         
                                                      for(mar = 17; mar <= 23; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                      
            
                                                      for(abr = 21; abr <= 27; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 24; mar <= 30; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 28; abr <= 30; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");
                                                            printf("|  31 ");

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                          
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
               
                                                            printf("|");
                                                            printf("\n");
                            } 
 
                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 4; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 5; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                      for(mai = 10; mai <= 11; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 2; jun <= 8; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(jun = 12; jun <= 18; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }  
                                                            printf("|| ");
                                                            printf(" 09 ");

                                                      for(mai = 10; mai <= 15; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|\n| ");
            
                                                      for(jun = 19; jun <= 25; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|");
                                                            printf("| ");

                                                      for(mai = 16; mai <= 22; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|\n| ");

                                                      for(jun = 26; jun <= 31; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf(" -- ");
                                                            printf("|| ");
                                                            

                                                      for(mai = 23; mai <= 29; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|");
                                                            printf("\n| ");

                                                      for(i = 1; i <= 7; i++){ 
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");
                                                            printf(" 30 ");
                                                      
                                                       for(i = 1; i <= 6; i++){ 
                                                            printf(" -- ");
                                                      }
                                                             printf("|\n");

                            }

                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 
 
                                                            printf(" -- ");
                                                         
                                                         for(jul = 1; jul <= 6; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 3; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 7; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <= 13; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 4; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                            printf(" 10 ");
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(jul = 14; jul <= 20; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                         
                                                         for(agos = 11; agos <= 17; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 21; jul <= 27; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 18; agos <= 24; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 28; jul <= 31; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                         for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(agos = 25; agos <= 31; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|");


                                                            printf("\n");                 
                            }


                            for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                         for(set = 1; set <= 7; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 5 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(set = 8; set <= 9; set++){  
                                                            printf(" 0%d ", set);
                                                         }

                                                         for(set = 10; set <= 14; set++){  
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 6; out <= 9; out++){  
                                                            printf(" 0%d ", out);
                                                         }
                                                         for(out = 10; out <= 12; out++){  
                                                            printf(" %d ", out);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(set = 15; set <= 21; set++){  
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 13; out <= 19; out++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", out);
                                                         }
                                                         

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(set = 22; set <= 28; set++){  
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 20; out <= 26; out++){  
                                                            printf(" %d ", out);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(set = 29; set <= 30; set++){ 
                                                            printf(" %d ", set);
                                                         }
                                                         
                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 27; out <= 31; out++){  
                                                            printf(" %d ", out);
                                                         }

                                                          for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");

                                                            printf("\n");

                                                            // sexta linha //
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            
                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                     }

                                                      for(nov = 1; nov <= 2; nov++){ 
                                                            printf(" 0%d ", nov);
                                                      }
                                                            printf("|| ");
                                                          
                                                      for(dez = 1; dez <= 7; dez++){ 
                                                            printf(" 0%d ", dez);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(nov = 3; nov <= 9; nov++){ 
                                                             printf(" 0%d ", nov);
                                                      }
                                                             printf("|| ");
            
                                                      for(dez = 8; dez <= 9; dez++){ 
                                                            printf(" 0%d ", dez);
                                                      }

                                                      for(dez = 10; dez <= 14; dez++){ 
                                                            printf(" %d ", dez);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(nov = 10; nov <= 16; nov++){ 
                                                            printf(" %d ", nov);
                                                      }
                                                            printf("|| ");
                                                      
                                                      for(dez = 15; dez <= 21; dez++){ 
                                                         printf(" %d ", dez);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");
                                         
                                                      for(dez = 17; dez <= 23; dez++){ 
                                                            printf(" %d ", dez);
                                                      }
                                                            printf("|| ");
                                                      
            
                                                      for(dez = 22; dez <= 28; dez++){
                                                            printf(" %d ", dez);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(nov = 24; nov <= 30; nov++){ 
                                                            printf(" %d ", nov);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(dez = 29; dez <= 31; dez++){ 
                                                            printf(" %d ", dez);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n| ");
                                                            

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                          
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
               
                                                            printf("|");
                                                            printf("\n");

                                                         printf("|-----------------------------||-----------------------------|\n");               
                            }
                            
                         }if(bissexto == 1){

                                 for(fev = 24; fev <= 29; fev++){
                                    printf(" %d ",fev);
                                 }
                                    printf(" -- ");
                                    printf("|\n| ");

                                 for(i= 1; i <= 7; i++){
                                    printf(" -- ");
                                 }
                                    printf("|| ");

                                 for(i= 1; i <= 7; i++){
                                    printf(" -- ");
                                 }

                                    printf("|\n"); 

                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //

                                                      for(i = 1; i <= 6; i++){ 
                                                             printf(" -- ");
                                                      }
                                                             printf(" 01 ");
                                                             printf("|| ");

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(abr = 1; abr <= 5; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 2; mar <= 8; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 6; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 12; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                            printf(" 09 ");

                                                      for(mar = 10; mar <= 15; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 13; abr <= 19; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 16; mar <= 22; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 20; abr <= 26; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 23; mar <= 29; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                            printf("|| ");

                                                      for(abr = 27; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                      for(mar = 30; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");
                            }

                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 3; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      
                                                      for(jun = 1; jun <= 7; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 4; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
  
                                                             printf(" 10 ");
                                                             printf("|| ");
            
                                                      for(jun = 8; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 14; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 11; mai <= 17; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 15; jun <= 21; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 18; mai <= 24; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 22; jun <= 28; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 25; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");


                                                      for(jun = 29; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");
                                                            printf("\n");

                                                            // SEXTA LINHA //
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|");
                                                            printf("\n");
                            }

                              for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <=2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <= 5; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 2; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 6; jul <=9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <=12; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 3; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(jul = 13; jul <= 19; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                         
                                                         for(agos = 10; agos <= 16; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 20; jul <= 26; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 17; agos <= 23; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(jul = 27; jul <= 31; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                         for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                          

                                                         for(agos = 24; agos <= 30; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("||  31 ");

                                                         for(agos = 1; agos <= 6; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 
                            }

                            
                           for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //             
                                                            printf(" -- ");

                                                         for(set = 1; set <= 6; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 4; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                          for(set = 7; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                          for(set = 10; set <= 13; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 5; out <= 9; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                         for(out = 10; out <= 11; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(set = 14; set <= 20; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 12; out <= 18; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");
                                                         
                                                         for(set = 21; set <= 27; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 19; out <= 25; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(set = 28; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 26; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf(" -- ");
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|");
                                                            printf("\n");


                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //


                                                         for(i = 1; i <= 6; i++){ 
                                                            printf(" -- ");
                                                         }  
                                                            printf(" 01 ");
                                                            printf("|| ");
                                                            printf(" -- ");

                                                         for(dez = 1; dez <= 6 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 2; nov <= 8; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 7; nov <= 9; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                         for(nov = 10; nov <= 13; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");
                                                            printf(" 09 ");

                                                         for(nov = 10; nov <= 15; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 14; nov <= 20; nov++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }             

                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");

                                                         for(nov = 16; nov <= 22; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 21; nov <= 27; nov++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                            printf("|");
                                                            printf("\n");
                                                            printf("| ");


                                                         for(nov = 23; nov <= 29; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                            printf("|| ");

                                                         for(dez = 28; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                          for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                                                            // sexta linha //
                                                            printf("|  30 ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                            } 
                         }
                     }
                                              
                        break;
                                                   

                              case -3: // SE O ANO COMEÇAR EM UMA QUARTA-FEIRA: //
                                for(j = 0; j < 1; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");
                     
                                                      // JANEIRO E FEVEREIRO //
                                                      
                                                         for(i = 1; i <= 3; i++){ // Para os dias vazios no calendário //  
                                                            printf(" -- ");
                                                          }

                                                          for(jan = 1; jan <= 4; jan++){ // PRIMEIRA SEMANA DE JANEIRO //
                                                             printf(" 0%d ", jan);
                                                          }
                                                             printf("|| ");

                                                         for(i = 1; i <=6; i++){ // Quando há dias vazios no calendário o laço preenche com '--' //  
                                                             printf(" -- ");
                                                          }

                                                          // fevereiro começa no SÁBADO, pois quando janeiro começa na QUARTA, termina na SEXTA//
                                                            printf(" 01 "); // PRIMEIRA SEMANA DE FEVEREIRO //
                                                            printf("|");
                                                            printf("\n| ");

                                                         for(jan = 5; jan <= 9; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                         for(jan = 10; jan <= 11; jan++){ 
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(loop1 = 2; loop1 <= 8; loop1++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" 0%d ", loop1);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");


                                                         for(jan = 12; jan <= 18; jan++){ // TERCEIRA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                            printf(" 09 ");

                                                         for(loop2 = 10; loop2 <= 15; loop2++){ // TERCEIRA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop2);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jan = 19; jan <= 25; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                            }

                                                            printf("|| ");

                                                         for(loop3 = 16; loop3 <= 22; loop3++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop3);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //"quinta semana" = quinta linha //

                                                         for(jan = 26; jan <= 31; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf(" -- ");
                                                            printf("|"); 
                                                            printf("| ");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                               if(bissexto == 1){ // se o ano for bissexto fevereiro vai até o dia 29 // 

                                                                  for(fev = 23; fev <= 29; fev++){ // "QUINTA SEMANA" DE FEVEREIRO //
                                                                    printf(" %d ", fev);
                                                                   }
                                                               
                                                            printf("|\n| ");

                                                               //SEXTA LINHA: //
                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");
                                                      

                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //

                                                      for(mar = 1; mar <= 7; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <=3; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(abr = 1; abr <= 4; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 8; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 14; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 5; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 11; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 15; mar <= 21; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 12; abr <= 18; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 22; mar <= 28; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 19; abr <= 25; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 29; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                      for(abr = 26; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");

                            }

                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 2; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <=3-2; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 6; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 3; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 7; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 13; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 10; mai <= 16; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 14; jun <= 20; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 17; mai <= 23; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 21; jun <= 27; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 24; mai <= 30; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");


                                                      for(jun = 28; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                                                            // SEXTA LINHA //
                                                            printf("|  31 ");

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                            }

                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <=3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <=4; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=6 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 5; jul <=9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <=11; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 2; agos <=8; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 12; jul <=18; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                             printf(" 09 ");

                                                         
                                                         for(agos = 10; agos <=15; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 19; jul <=25; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 16; agos <=22; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 26; jul <=31; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                            printf(" -- ");
                                                            printf("|| ");

                                                         for(agos = 23; agos <= 29; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(agos = 30; agos <= 31; agos++){  
                                                            printf(" %d ", agos);
                                                         }

                                                         for(agos = 1; agos <= 5; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("\n");                 
                            }


                            for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                         for(i = 1; i <=2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(set = 1; set <=5; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=3 + 1 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 3 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");


                                                          for(set = 6; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                          for(set = 10; set <=12; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 4; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf(" 10 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 13; set <=19; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 11; out <= 17; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 20; set <= 26; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 18; out <= 24; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 27; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <=3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 25; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");


                           }

                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //


                                                         for(nov = 1; nov <= 7; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 5 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 8; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 14; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 6; nov <= 9; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                         for(nov = 10; nov <= 12; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 15; nov <= 21; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 13; nov <= 19; nov++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 22; nov <= 28; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 20; nov <= 26; nov++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 29; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                         
                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 27; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                          for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");

                                                            printf("\n");

                                                            // sexta linha //
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                             

                            }
                           
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                             //se o ano NÃO for bissexto //
                              }if(bissexto == 0){ // se o ano não for bissexto fevereiro vai até o dia 28// 
                                   
                                                          for(fev = 23; fev <= 28; fev++){ // "QUINTA SEMANA" DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                          }          
                                                            printf(" -- ");
                                                            printf("|\n");
                                                            printf("| ");

                                                               //SEXTA LINHA: //
                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");


                  for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //

                                                      for(i = 1; i <=6; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf(" 01 "); // PRIMEIRA SEMANA DE MARÇO //
                                                            printf("|| ");
                                                            

                                                      for(i = 1; i <=3-1; i++){  
                                                            printf(" -- ");
                                                      }

                                                             

                                                      for(abr = 1; abr <= 5; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 2; mar <= 8; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(mar = 6; mar <= 9; mar++){ // SEGUNDA SEMANA DE ABRIL //
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 12; mar++){ // SEGUNDA SEMANA DE ABRIL //
                                                             printf(" %d ", mar);
                                                      }                                                 
                                                      
                                                            printf("|\n");
                                                            printf("| ");
                                                            printf(" 09 "); // TERCEIRA SEMANA DE MARÇO //
                                                      
                                                      for(mar = 10; mar <= 15; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 13; abr <= 19; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                                                                                                                                    

                                                      for(mar = 16; mar <= 22; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                      
            
                                                      for(abr = 20; abr <= 26; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");


                                                      for(mar = 23; mar <= 29; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      
                                                            printf("|| ");

                                                      for(abr = 27; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr); 
                                                      }

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                       // SEXTA LINHA //

                                                      for(mar = 30; mar <= 31; mar++){ 
                                                            printf(" %d ", mar);
                                                      }

                                                       for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");
                                                         

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");                       
                            }


                for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <=3 + 1; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 3; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      

                                                      for(jun = 1; jun <= 7; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 4; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                             printf(" 10 ");
                                                             printf("|| ");
            
                                                      for(jun = 8; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 14; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }


                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 11; mai <= 17; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 15; jun <= 21; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 18; mai <= 24; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 22; jun <= 28; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 25; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");


                                                      for(jun = 29; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                                                            // SEXTA LINHA //

                                                            
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                            }


                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <=3 - 1 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <=5; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 2; agos++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", agos);
                                                         }
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 6; jul <=9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <= 12; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                         


                                                         for(agos = 3; agos <=9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 13; jul <=19; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 10; agos <=16; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 20; jul <= 26; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 17; agos <=23; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 27; jul <=31; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                         for(agos = 1; agos <= 2; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(agos = 24; agos <= 30; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                          
                                                            printf(" 31 ");
                                                         

                                                         for(agos = 1; agos <= 6; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|");

                                                            printf("\n");                 
                            }


                             for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                          
                                                         
                                                            printf(" -- ");

                                                         for(set = 1; set <=6; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=3; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 4 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");


                                                          for(set = 7; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                          for(set = 10; set <=13; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 5; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }

                                                         for(out = 10; out <= 11 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                            
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 14; set <= 20; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 12; out <= 18; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 21; set <= 27; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 19; out <= 25; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 28; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <=4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 26; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                            printf(" -- ");
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");


                           }


                           for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //


                                                         for(nov = 1; nov <= 6; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|| ");
                                                            printf(" -- ");
                                                         
                                                         for(dez = 1; dez <= 6 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 2; nov <= 8; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }


                                                            printf("|| ");

                                                         for(nov = 7; nov <= 9; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 13; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                            printf(" 09 ");

                                                         for(nov = 10; nov <= 15; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 14; dez <= 20; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 16; nov <= 22; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 21; dez <= 27; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 23; nov <= 29; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 28; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                          for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|");

                                                            printf("\n");

                                                            // sexta linha //
                                                            printf("|  30 ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                             
                           }
                              
                      }                        
                                            break;
                                            
                              
                              case -4: // SE JANEIRO COMEÇAR NUMA QUINTA - FEIRA  //

                               for(j = 0; j < 2; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");

                                                       for(i = 1; i <= 4; i++){ // Para os dias vazios no calendário //  
                                                            printf(" -- ");
                                                          }

                                                          for(jan = 1; jan <= 3; jan++){ // PRIMEIRA SEMANA DE JANEIRO //
                                                             printf(" 0%d ", jan);
                                                          }
                                                             printf("|| ");

                                                         for(jan = 1; jan <= 7; jan++){ // PRIMEIRA SEMANA DE FEVEREIRO // 
                                                             printf(" 0%d ", jan);
                                                          }

                                                          // fevereiro começa no SÁBADO, pois quando janeiro começa na QUARTA, termina na SEXTA//
                                                            
                                                            printf("|");
                                                            printf("\n| ");


                                                         for(jan = 4; jan <= 9; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                            printf(" 10 ");
                                                            printf("|| ");

                                                         for(loop1 = 8; loop1 <= 9; loop1++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" 0%d ", loop1);
                                                         }
                                                         for(loop1 = 10; loop1 <= 14; loop1++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop1);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");


                                                         for(jan = 11; jan <= 17; jan++){ // TERCEIRA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");


                                                         for(loop2 = 15; loop2 <= 21; loop2++){ // TERCEIRA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop2);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jan = 18; jan <= 24; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                            }

                                                            printf("|| ");

                                                         for(loop3 = 22; loop3 <= 28; loop3++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", loop3);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //"quinta semana" = quinta linha //

                                                         for(jan = 25; jan <= 31; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }
                                                            printf("|"); 
                                                            printf("| ");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                 if(bissexto == 1){ // se o ano for bissexto fevereiro vai até o dia 29 // 

                                                            // "QUINTA SEMANA" DE FEVEREIRO //
                                                            printf(" 29 ");                         

                                                         //SEXTA LINHA: //
                                                         for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");

                                                  


                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // MARÇO E ABRIL: //

                                                            printf(" -- ");

                                                      for(mar = 1; mar <= 6; mar++){  // PRIMEIRA SEMANA DE MARÇO //
                                                            printf(" 0%d ", mar);
                                                      }
                                                            
                                                            printf("|| ");
                                                            

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                      }

                                                      for(abr = 1; abr <= 3; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 7; mar <= 9; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 13; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                             printf(" %d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(abr = 4; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                             printf(" 0%d ", abr);
                                                      }
                                                             printf(" 10 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 14; mar <= 20; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }     
                                                            printf("|| ");                                            
  
                                                      for(abr = 11; abr <= 17; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                             printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");
            
                        
                                                      for(mar = 21; mar <= 27; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                      
            
                                                      for(abr = 18; abr <= 24; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");


                                                      for(mar = 28; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");
                                                      

                                                      for(abr = 25; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr); 
                                                      }

                                                            printf(" -- ");
                                                            printf("|\n");
                                                            printf("| ");

                                                       // SEXTA LINHA //

                                                      

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");
                                                         

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");                       
                            }

                             for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <=6; i++){  
                                                            printf(" -- ");
                                                         }

                                                         // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 01 ");
                                                      
                                                             printf("|| ");

                                                      for(i = 1; i <=2; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 5; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 2; mai <= 8; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                             printf("|| ");
                                                             
            
                                                      for(jun = 6; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 12; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                            printf(" 09 ");

                                                      for(mai = 10; mai <= 15; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 13; jun <= 19; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 16; mai <= 22; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 20; jun <= 26; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 23; mai <= 29; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");


                                                      for(jun = 27; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                                                            // SEXTA LINHA //
                                                            
                                                            printf("| ");

                                                            
                                                      for(mai = 30; mai <= 31; mai++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", mai);
                                                      }


                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                            }


                             for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <= 3; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(agos = 1; agos <= 7; agos++){  // PRIMEIRA SEMANA DE AGOSTO //
                                                            printf(" 0%d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                           

                                                         for(jul = 4; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                             printf(" 10 ");
                                                             printf("|| ");

                                                         for(agos = 8; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 14; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 11; jul <= 17; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 15; agos <= 21; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 18; jul <= 24; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 22; agos <= 28; agos++){  
                                                            printf(" %d ", agos);
                                                          }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 25; jul <= 31; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 29; agos <= 31; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                         

                                                         for(jul = 1; jul <= 4; jul++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 

                            }


                              for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                          
                                                         for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(set = 1; set <=4; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 2 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");


                                                          for(set = 5; set <= 9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                          for(set = 10; set <=11; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 3; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
          
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 12; set <= 18; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 10; out <= 16; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 19; set <= 25; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 17; out <= 23; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 26; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <=2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 24; out <= 30; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                            printf(" 31 ");

                                                         for(i = 1; i <=6 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");
                           }



                            for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //

                                                            printf(" -- ");

                                                         for(nov = 1; nov <= 6; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                               
                                                            printf("|| ");

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 4 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 7; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 13; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            printf("|| ");

                                                         for(dez = 5; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                         for(dez = 10; dez <= 11; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                           

                                                         for(nov = 14; nov <= 20; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 12; dez <= 18; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 21; nov <= 27; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 19; dez <= 25; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 28; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                         for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 26; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf(" -- ");
                                                            printf("|\n");

                                                            // sexta linha //
                                                           
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                            }


                            }if(bissexto == 0){ // se o ano não for bissexto //

                                                        

                                                         //SEXTA LINHA: //
                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <=7; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("| ");
                                                            printf("\n");
                                                      

                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");


                              // MARÇO E ABRIL: //

                                                      for(mar = 1; mar <= 7; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <=3; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(abr = 1; abr <= 4; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 8; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 14; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 5; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                      for(abr = 10; abr <= 11; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 15; mar <= 21; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 12; abr <= 18; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 22; mar <= 28; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 19; abr <= 25; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 29; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                      for(abr = 26; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");

                            }

                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <=5; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(mai = 1; mai <= 2; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      
                                                            printf(" -- ");
                                                         

                                                      for(jun = 1; jun <= 6; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 3; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 7; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 13; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 10; mai <= 16; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 14; jun <= 20; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 17; mai <= 23; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 21; jun <= 27; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 24; mai <= 30; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");


                                                      for(jun = 28; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                                                            // SEXTA LINHA //
                                                            printf("|  31 ");

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                            }


                             for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <= 4; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }


                                                         // PRIMEIRA SEMANA DE AGOSTO //
                                                            printf(" 01 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 5; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                         for(jul = 10; jul <= 11; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 2; agos <= 8; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 12; jul <= 18; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                             printf(" 09 ");

                                                         for(agos = 10; agos <= 15; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 19; jul <= 25; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 16; agos <= 22; agos++){  
                                                            printf(" %d ", agos);
                                                          }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 26; jul <= 31; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf(" -- ");
                                                             printf("|| ");

                                                         for(agos = 23; agos <= 29; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 1; jul <= 7; jul++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                   

                                                            //sexta linha //

                                                         for(agos = 30; agos <= 31; agos++){  
                                                            printf(" %d ", agos);
                                                         }


                                                         for(agos = 1; agos <= 5; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 

                            }


                             for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //
    

                                                         for(set = 1; set <= 2; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" -- ");
                                                         }

                                                         for(set = 1; set <= 5; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 3 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");


                                                          for(set = 6; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                          for(set = 10; set <=12; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 4; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            printf(" 10 ");
                                                                                                                        
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 13; set <= 19; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 11; out <= 17; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 20; set <= 26; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 18; out <= 24; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 27; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 25; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");


                           }


                           for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //


                                                         for(nov = 1; nov <= 7; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
  
                                                            printf("|| ");

                  
                                                         for(dez = 1; dez <= 2; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" -- ");
                                                         }
                                                         for(dez = 1; dez <= 5; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 8; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 14; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(nov = 6; nov <= 9; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 12; nov++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                            

                                                         for(nov = 15; nov <= 21; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 13; dez <= 19; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 22; nov <= 28; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 20; dez <= 26; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 29; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }


                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }
   
                                                            printf("|| ");

                                                         for(dez = 27; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         } 

                                                          for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }


                                                            printf("| ");
                                                            printf("\n");
                                                            printf("| ");

                                                            // sexta linha //
                                                      
                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                             
                           }
                     }
                                                      break;
                            
                                          
                     case -5: // SE JANEIRO COMEÇAR NUMA SEXTA - FEIRA  //
                        for(j = 0; j < 1; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");
                     
                                                      // JANEIRO E FEVEREIRO //
                                                      
                                                         for(i = 1; i <= 5; i++){ // Para os dias vazios no calendário //  
                                                            printf(" -- ");
                                                          }

                                                          for(jan = 1; jan <= 2; jan++){ // PRIMEIRA SEMANA DE JANEIRO //
                                                             printf(" 0%d ", jan);
                                                          }
                                                             printf("|| ");
                                                             printf(" -- ");

                                                         for(fev = 1; fev <= 6; fev++){ // PRIMEIRA SEMANA DE FEVEREIRO //
                                                             printf(" 0%d ", fev);
                                                          }

                                                            printf("|");
                                                            printf("\n| ");

                                                         for(jan = 3; jan <= 9; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 7; fev <= 9; fev++){ 
                                                            printf(" 0%d ", fev);
                                                         }

                                                         for(fev = 10; fev <= 13; fev++){ 
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jan = 10; jan <= 16; jan++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");


                                                         for(fev = 14; fev <= 20; fev++){ // TERCEIRA SEMANA DE FEVEIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");     

                                                         for(jan = 17; jan <= 23; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 21; fev <= 27; fev++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //"quinta semana" = quinta linha //

                                                         for(jan = 24; jan <= 30; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }
        
                          
                                        if (bissexto == 1){ // SE O ANO FOR BISSEXTO //

                                                            printf("|| ");

                                                         for(fev = 28; fev <=29; fev++){ // última semana de fevereiro //
                                                            printf(" %d ", fev);
                                                         }

                                                         for(i = 1; i <= 5; i++){
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|  31 "); // último dia de janeiro //

                                                          for(i = 1; i <= 6; i++){
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
               

               for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // MARÇO E ABRIL: //

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }

                                                      for(mar = 1; mar <= 5; mar++){  // PRIMEIRA SEMANA DE MARÇO //
                                                            printf(" 0%d ", mar);
                                                      }
                                                            
                                                            printf("|| ");
                                                            

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }

                                                      for(abr = 1; abr <= 2; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 6; mar <= 9; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 12; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                             printf(" %d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(abr = 3; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                             printf(" 0%d ", abr);
                                                      }
                                                           
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 13; mar <= 19; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }     
                                                            printf("|| ");                                            
  
                                                      for(abr = 10; abr <= 16; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                             printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");
            
                        
                                                      for(mar = 20; mar <= 26; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                      
            
                                                      for(abr = 17; abr <= 23; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");


                                                      for(mar = 27; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(abr = 24; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr); 
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                       // SEXTA LINHA //

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");
                                                         

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");                       
                            }

                        for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(mai = 1; mai <= 7; mai++){    // PRIMEIRA SEMANA DE MAIO //
                                                            printf(" 0%d ", mai); 
                                                         }
                                                             printf("|| ");

                                                      for(i = 1; i <=3; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 4; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 8; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                      for(mai = 10; mai <= 14; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 5; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 11; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                            

                                                      for(mai = 15; mai <= 21; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 12; jun <= 18; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 22; mai <= 28; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 19; jun <= 25; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                      
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 29; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");


                                                      for(jun = 26; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                       // SEXTA LINHA //      

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                            }

                           for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <= 2; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");
                                                            printf(" -- ");

                                                         for(agos = 1; agos <= 6 ; agos++){  
                                                            printf(" 0%d ", agos);
                                                         }

                                                         // PRIMEIRA SEMANA DE AGOSTO //
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 3; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }
                                                            
                                                            printf("|| ");

                                                         for(agos = 7; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 13; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 10; jul <= 16; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                            

                                                         for(agos = 14; agos <= 20; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 17; jul <= 23; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 21; agos <= 27; agos++){  
                                                            printf(" %d ", agos);
                                                          }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 24; jul <= 30; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                         
                                                             printf("|| ");

                                                         for(agos = 28; agos <= 31; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }
                                      
                                                         for(i= 1; i<= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                   

                                                            //sexta linha //
                                                            printf(" 31 ");

                                                         for(agos = 1; agos <= 6; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 

                            }


                            
                           for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //               
                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }                              

                                                         for(set = 1; set <=3; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <=6; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 4; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf(" 10 ");
                                                            printf("|| ");

                                                         for(out = 2; out <= 8; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ", out);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 11; set <= 17; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                            printf(" 09 ");

                                                         for(out = 10; out <= 15; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 18; set <= 24; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 16; out <= 22; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 25; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf(" -- ");
                                                            printf("|| ");
                                                         
                                                         for(out = 23; out <= 29; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 30; out <= 31; out++){  
                                                            printf(" %d ", out);
                                                         }

                                                         for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");

                           }

                           for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //


                                                         for(nov = 1; nov <= 2; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" -- ");
                                                         }

                                                         for(nov = 1; nov <= 5; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                            
                                                            printf("|| ");
                                                         
                                                         for(dez = 1; dez <= 4 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 3 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 6; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                         for(nov = 10; nov <= 12; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 4; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                            printf(" 10 ");
                                                            printf("|\n");
                                                            printf("| ");
                                                            
                                                         for(nov = 13; nov <= 19; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 11; dez <= 17; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 20; nov <= 26; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 18; dez <= 24; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 27; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                         
                                                          for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 25; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");

                                                            // sexta linha //
                                                            

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                                                            
                           }
                            }if(bissexto == 0){ // SE O ANO NÃO FOR BISSEXTO //

                                                            printf("|"); 
                                                            printf("|  28 ");
                                                            
                                                         for(i = 1; i <= 6; i++){ 
                                                            printf(" -- ");
                                                         }
                                                            printf("|"); 
                                                            printf("\n");
                                                            printf("|  31 ");

                                                         for(i = 1; i <= 6; i++){ 
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){ 
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                            for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // MARÇO E ABRIL: //
                                                            printf(" -- ");

                                                      for(mar = 1; mar <= 6; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(abr = 1; abr <= 3; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 7; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 13; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 4; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }
                                                            printf(" 10 ");
                                                      

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 14; mar <= 20; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 11; abr <= 17; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 21; mar <= 27; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 18; abr <= 24; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 28; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                      for(abr = 25; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                            printf(" -- ");
                                                      
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");

                            }

                for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(i = 1; i <=6; i++){  
                                                            printf(" -- ");
                                                         }

                                                         // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 01 ");
                                                             printf("|| ");

                                                      for(i = 1; i <=2; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(jun = 1; jun <= 5; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 2; mai <= 8; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 6; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 12; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                            printf(" 09 ");

                                                      for(mai = 10; mai <= 15; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 13; jun <= 19; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 16; mai <= 22; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 20; jun <= 26; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 23; mai <= 29; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                            printf("|| ");


                                                      for(jun = 27; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            // SEXTA LINHA //      

                                                      for(mai = 30; mai <= 31; mai++){  
                                                            printf(" %d ", mai);
                                                      }

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                            }

                            
                             for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <= 3; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");

                                                         for(agos = 1; agos <= 7 ; agos++){  
                                                            printf(" 0%d ", agos);
                                                         }

                                                         // PRIMEIRA SEMANA DE AGOSTO //
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 4; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }
                                                            printf(" 10 ");
                                                            printf("|| ");

                                                         for(agos = 8; agos <= 9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 14; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 11; jul <= 17; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                            

                                                         for(agos = 15; agos <= 21; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 18; jul <= 24; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 22; agos <= 28; agos++){  
                                                            printf(" %d ", agos);
                                                          }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 25; jul <= 31; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                         
                                                             printf("|| ");

                                                         for(agos = 29; agos <= 31; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }
                                      
                                                         for(jul = 1; jul <= 4; jul++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                   

                                                            //sexta linha //

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(agos = 1; agos <= 7; agos++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 

                            }

                            
                             for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //
    

                                                         for(set = 1; set <= 3; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" -- ");
                                                         }

                                                         for(set = 1; set <= 4; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(out = 1; out <= 2 ; out++){  // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");


                                                          for(set = 5; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                          for(set = 10; set <=11; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 3; out <= 9 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                                                                               
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 12; set <= 18; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 10; out <= 16; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 19; set <= 25; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 17; out <= 23; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 26; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                         for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 24; out <= 30; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                            printf(" 31 ");

                                                         for(i = 1; i <=6 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");

                             }

                              for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //

                                                            printf(" -- ");

                                                         for(nov = 1; nov <= 6; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                               
                                                            printf("|| ");

                                                         for(i = 1; i <= 3 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 4 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 7; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 13; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            printf("|| ");

                                                         for(dez = 5; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                         for(dez = 10; dez <= 11; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                           

                                                         for(nov = 14; nov <= 20; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 12; dez <= 18; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 21; nov <= 27; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 19; dez <= 25; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 28; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                         for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 26; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf(" -- ");
                                                            printf("|\n");

                                                            // sexta linha //
                                                           
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");

                                              }
                            }            
                                                          
             }



                  break;


                                                  
                        case -6: // SE O ANO COMEÇAR EM UM SÁBADO

                            for(j = 0; j < 1; j++){// for que percorre os meses do ano para printar o calendário //   

                                  printf("|-----------------------------||-----------------------------|\n");
                                  printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                                  printf("|-----------------------------||-----------------------------|\n");  
                                  printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                                  printf("| ");
                     
                                                      // JANEIRO E FEVEREIRO //
                                                      
                                                         for(i = 1; i <= 6; i++){ // Para os dias vazios no calendário //  
                                                            printf(" -- ");
                                                          }

                                                           // PRIMEIRA SEMANA DE JANEIRO //
                                                          
                                                             printf(" 01 ");
                                                             printf("|| ");

                                                         for(i = 1; i <= 2; i++){ // Para os dias vazios no calendário //  
                                                            printf(" -- ");
                                                          }

                                                         for(fev = 1; fev <= 5; fev++){ // PRIMEIRA SEMANA DE FEVEREIRO //
                                                             printf(" 0%d ", fev);
                                                          }

                                                            printf("|");
                                                            printf("\n| ");

                                                         for(jan = 2; jan <= 8; jan++){ // SEGUNDA SEMANA DE JANEIRO //
                                                            printf(" 0%d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 6; fev <= 9; fev++){ 
                                                            printf(" 0%d ", fev);
                                                         }

                                                         for(fev = 10; fev <= 12; fev++){ 
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            printf(" 09 ");

                                                         for(jan = 10; jan <= 15; jan++){ // SEGUNDA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");


                                                         for(fev = 13; fev <= 19; fev++){ // TERCEIRA SEMANA DE FEVEIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");     

                                                         for(jan = 16; jan <= 22; jan++){ // QUARTA SEMANA DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 20; fev <= 26; fev++){ // QUARTA SEMANA DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                            //"quinta semana" = quinta linha //

                                                         for(jan = 23; jan <= 29; jan++){ // "QUINTA SEMANA" DE JANEIRO //
                                                            printf(" %d ", jan);
                                                         }

                                                            printf("|| ");

                                                         for(fev = 27; fev <= 28; fev++){ // "QUINTA SEMANA" DE FEVEREIRO //
                                                            printf(" %d ", fev);
                                                         }
        
                           if(bissexto == 0){ // SE O ANO NÃO FOR BISSEXTO //
                                                            
                                                         for(i = 1; i <= 5; i++){ 
                                                            printf(" -- ");
                                                         }
                                                            printf("|"); 
                                                            printf("\n| ");

                                                         for(jan = 30; jan <= 31; jan++){ 
                                                            printf(" %d ", jan);
                                                         }

                                                         for(i = 1; i <= 5; i++){ 
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){ 
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");

                        for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // MARÇO E ABRIL: //
                                                           

                                                      for(mar = 1; mar <= 2; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                              printf(" -- ");
                                                      }

                                                      for(mar = 1; mar <= 5; mar++){ // PRIMEIRA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                      for(abr = 1; abr <= 2; abr++){ // PRIMEIRA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mar = 6; mar <= 9; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 12; mar++){ // SEGUNDA SEMANA DE MARÇO //
                                                             printf(" %d ", mar);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(abr = 3; abr <= 9; abr++){ // SEGUNDA SEMANA DE ABRIL //
                                                            printf(" 0%d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 13; mar <= 19; mar++){ // TERCEIRA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(abr = 10; abr <= 16; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 20; mar <= 26; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(abr = 17; abr <= 23; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mar = 27; mar <= 31; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                      for(abr = 24; abr <= 30; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                          
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|| ");

                                                       for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");
                              } 

                              
                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                      for(mai = 1; mai <= 7; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }
                                                             printf("|| ");

                                                      for(i = 1; i <= 3; i++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" -- ");
                                                      }

                                                      for(jun = 1; jun <= 4; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 8; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                      for(mai = 10; mai <= 14; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 5; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                      for(jun = 10; jun <= 11; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 15; mai <= 21; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 12; jun <= 18; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 22; mai <= 28; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 19; jun <= 25; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 29; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }

                                                       for(i = 1; i <= 4; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                      for(jun = 26; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                      for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      // SEXTA LINHA //

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");

                                                      
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|\n");
                            }


                            for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 


                                                         for(i = 1; i <=5 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(jul = 1; jul <= 2; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                            printf("|| ");
                                                            printf(" -- "); 

                                                         for(agos = 1; agos <= 6; agos++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", agos);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 3; jul <= 9; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 7; agos <=9; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 13; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 10; jul <=16; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                             
                                                         for(agos = 14; agos <= 20; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 17; jul <= 23; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 21; agos <= 27; agos++){  // QUARTA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 24; jul <= 30; jul++){  // "QUINTA" SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                            
                                                            printf("|| ");

                                                         for(agos = 28; agos <= 31; agos++){  // "QUINTA" SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                         for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                            printf(" 31 ");

                                                            //sexta linha //

                                                         for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                
                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 
                            }

                            
                            for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //

                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(set = 1; set <= 3; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 6  ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         // PRIMEIRA SEMANA DE OUTUBRO //
                                                            printf(" 01 ");
                                                            printf("|\n");
                                                            printf("| ");


                                                          for(set = 4; set <= 9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }
                                                            printf(" 10 ");
                                                            printf("|| ");
                                                         
                                                         for(out = 2; out <= 8 ; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ",out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 11; set <= 17; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");

                                                          // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" 09 ");
                                                         
                                                         for(out = 10; out <= 15; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 18; set <= 24; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|");
                                                            printf("| ");
                                                         
                                                         for(out = 16; out <= 22; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 25; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf(" -- ");
                                                            printf("|| ");

                                                         for(out = 23; out <= 29; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(out = 30; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                         for(i = 1; i <= 5 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                             
                                                            printf("|\n");

                           }
                           
                           

                           for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //

                                                         for(nov = 1; nov <= 2; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" -- ");
                                                         }

                                                         for(nov = 1; nov <= 5; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                               
                                                            printf("|| ");

                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 3 ; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 6; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 12; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }
                                                            printf("|| ");

                                                         for(dez = 4; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }
                                                            printf(" 10 ");
                                                            printf("|\n");
                                                            printf("| ");
                                                           

                                                         for(nov = 13; nov <= 19; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 11; dez <= 17; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 20; nov <= 26; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 18; dez <= 24; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 27; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                         for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 25; dez <= 31; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|\n");

                                                            // sexta linha //
                                                           
                                                            printf("| ");

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");
                                                            printf("\n");
                              }

                           } if(bissexto == 1){ // SE O ANO FOR BISSEXTO //

                                                            printf(" 29 ");

                                                         for(i = 1; i <= 4; i++){ 
                                                            printf(" -- ");
                                                          }         

                                                            printf("|\n");
                                                            printf("| ");
                                                         // sexta linha //
                                                         for(jan = 30; jan <= 31; jan++){ 
                                                            printf(" %d ", jan);
                                                          }       

                                                         for(i = 1; i <= 5; i++){ 
                                                            printf(" -- ");
                                                          }    
                                                           
                                                            printf("|| ");
                                                         
                                                         for(i = 1; i <= 7; i++){ 
                                                            printf(" -- ");
                                                          } 

                                                            printf("| \n");
                                      

                         for(j = 2; j < 3; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // MARÇO E ABRIL: //

                                                      for(i = 1; i <=3; i++){  
                                                            printf(" -- ");
                                                      }
                                                      
                                                      for(mar = 1; mar <= 4; mar++){   // PRIMEIRA SEMANA DE MARÇO // 
                                                             printf(" 0%d ", mar);
                                                      }
                                                      
                                                            printf("|| ");
                                                            

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf(" 01 ");
                                                            printf("|\n| ");

                                                      for(mar = 5; mar <= 9; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                            printf(" 0%d ", mar);
                                                      }

                                                      for(mar = 10; mar <= 11; mar++){  // SEGUNDA SEMANA DE MARÇO // 
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                            
                                                      
                                                      for(abr = 2; abr <= 8; abr++){ // TERCEIRA SEMANA DE ABRIL //
                                                             printf(" 0%d ", abr);
                                                      }
  
                                                             printf("|\n");
                                                             printf("| ");                                           

                                                      for(mar = 12; mar <= 18; mar++){ // QUARTA SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");
                                                            printf(" 09 ");
                                                      
            
                                                      for(abr = 10; abr <= 15; abr++){ // QUARTA SEMANA DE ABRIL //
                                                            printf(" %d ", abr);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");


                                                      for(mar = 19; mar <= 25; mar++){ // "QUINTA" SEMANA DE MARÇO //
                                                            printf(" %d ", mar);
                                                      }
                                                            printf("|| ");

                                                      for(abr = 16; abr <= 22; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr); 
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      
                                                      for(mar = 26; mar <= 31; mar++){ 
                                                            printf(" %d ", mar);
                                                      }

                                                            printf(" -- ");
                                                            printf("|| ");

                                                      for(abr = 23; abr <= 29; abr++){ // "QUINTA" SEMANA DE ABRIL //
                                                            printf(" %d ", abr); 
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");
                                                            printf(" 30 ");

                                                      // SEXTA LINHA //

                                                      for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|\n");                       
                            }

                            
                              
                            for(j = 4; j < 5; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                    // MAIO E JUNHO: //

                                                    
                                                            printf(" -- ");
                         
                                                      for(mai= 1; mai<= 6; mai++){ // PRIMEIRA SEMANA DE MAIO //
                                                            printf(" 0%d ", mai);
                                                      }
                                                            printf("|| ");

                                                      for(i = 1; i <= 4; i++){ 
                                                            printf(" -- ");
                                                      }
                                                      for(jun = 1; jun <= 3; jun++){ // PRIMEIRA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      for(mai = 7; mai <= 9; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" 0%d ", mai);
                                                      }

                                                      for(mai = 10; mai <= 13; mai++){ // SEGUNDA SEMANA DE MAIO //
                                                             printf(" %d ", mai);
                                                      }
  
                                                             printf("|| ");
            
                                                      for(jun = 4; jun <= 9; jun++){ // SEGUNDA SEMANA DE JUNHO //
                                                            printf(" 0%d ", jun);
                                                      }
                                                            printf(" 10 ");
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 14; mai <= 20; mai++){ // TERCEIRA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");
            
                                                      for(jun = 11; jun <= 17; jun++){ // TERCEIRA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 21; mai <= 27; mai++){ // QUARTA SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }
                                                      
                                                            printf("|| ");

                                                      for(jun = 18; jun <= 24; jun++){ // QUARTA SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }
                                                            printf("|\n");
                                                            printf("| ");

                                                      for(mai = 28; mai <= 31; mai++){ // "QUINTA" SEMANA DE MAIO //
                                                            printf(" %d ", mai);
                                                      }

                                                       for(i = 1; i <= 3; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf("|| ");

                                                      for(jun = 25; jun <= 30; jun++){ // "QUINTA" SEMANA DE JUNHO //
                                                            printf(" %d ", jun);
                                                      }

                                                     
                                                            printf(" -- ");
                                                            printf("|\n");
                                                            printf("| ");
                                                      
                                                      // SEXTA LINHA //

                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }
                                                            printf("|| ");

                                                      
                                                      for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                      }

                                                            printf("|\n");
                            }

                            
                           for(j = 6; j < 7; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                                 //JULHO E AGOSTO // 

                                                         for(i = 1; i <= 6 ; i++){  
                                                            printf(" -- ");
                                                         }
                                                            printf(" 01 ");
                                                            printf("|| ");

                                                          for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(agos = 1; agos <= 5; agos++){  // PRIMEIRA SEMANA DE AGOSTO //
                                                            printf(" 0%d ", agos);
                                                         }
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 2; jul <= 8; jul++){  // PRIMEIRA SEMANA DE JULHO //
                                                            printf(" 0%d ", jul);
                                                         }
                                                            printf("|| ");

                                                         for(agos = 6; agos <= 9 ; agos++){  
                                                            printf(" 0%d ", agos);
                                                         }

                                                         for(agos = 10; agos <= 12; agos++){  
                                                            printf(" %d ", agos);
                                                         }

                                                         // PRIMEIRA SEMANA DE AGOSTO //
                                                            
                                                            printf("|\n");
                                                            printf("| ");
                                                            printf(" 09 ");

                                                         for(jul = 10; jul <= 15; jul++){  // SEGUNDA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                            
                                                            printf("|| ");

                                                         for(agos = 13; agos <= 19; agos++){  // SEGUNDA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 16; jul <= 22; jul++){  // TERCEIRA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");
                                                            

                                                         for(agos = 20; agos <= 26; agos++){  // TERCEIRA SEMANA DE AGOSTO//
                                                            printf(" %d ", agos);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(jul = 23; jul <= 29; jul++){  
                                                            printf(" %d ", jul);
                                                         }

                                                             printf("|| ");

                                                         for(agos = 27; agos <= 31; agos++){  
                                                            printf(" %d ", agos);
                                                          }

                                                         for(i = 1; i <= 2; i++){  
                                                            printf(" -- ");
                                                          }

                                                            printf("|\n");
                                                            printf("| ");


                                                         for(jul = 30; jul <= 31; jul++){  // QUARTA SEMANA DE JULHO //
                                                            printf(" %d ", jul);
                                                         }
                                                         
                                                         for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }
                                                         
                                                             printf("|| ");
                                 
                                                         for(i = 1; i <= 7; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");                 

                            }


                            
                           for(j = 8; j < 9; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // SETEMBRO E OUTUBRO //               
                                                         for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }                              

                                                         for(set = 1; set <= 2; set++){  // PRIMEIRA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 1; out <= 7; out++){  
                                                            printf(" 0%d ", out);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 3; set <=9; set++){  // SEGUNDA SEMANA DE SETEMBRO //
                                                            printf(" 0%d ", set);
                                                         }

                                                            printf("|| ");

                                                         for(out = 8; out <= 9; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" 0%d ", out);
                                                         }

                                                         for(out = 10; out <= 14; out++){  // SEGUNDA SEMANA DE OUTUBRO //
                                                            printf(" %d ", out);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 10; set <= 16; set++){  // TERCEIRA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                            
                                                         for(out = 15; out <= 21; out++){  // TERCEIRA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");
                                                         
                                                         for(set = 17; set <= 23; set++){  // QUARTA SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 22; out <= 28; out++){  // QUARTA SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(set = 24; set <= 30; set++){  // "QUINTA" SEMANA DE SETEMBRO //
                                                            printf(" %d ", set);
                                                         }

                                                            printf("|| ");
                                                         
                                                         for(out = 29; out <= 31; out++){  // "QUINTA" SEMANA DE OUTUBRO //
                                                            printf(" %d ",out);
                                                         }

                                                         
                                                         for(i = 1; i <= 4 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }  

                                                            printf("|| ");

                                                         for(i = 1; i <=7 ; i++){  
                                                            printf(" -- ");
                                                         }  
                                                            printf("|\n");

                           }

                           for(j = 10; j < 11; j++){// for que percorre os meses do ano para printar o calendário //   
                              printf("|-----------------------------||-----------------------------|\n");
                              printf("|%-29s||%-29s|\n", meses_do_ano[j], meses_do_ano[j+1]); // o -29 serve para alinhar o texto à esquerda //
                              printf("|-----------------------------||-----------------------------|\n");  
                              printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");  // printa os dias da semana no calendário //
                              printf("| ");

                              // NOVEMBRO E DEZEMBRO //


                                                         for(nov = 1; nov <= 3; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" -- ");
                                                         }

                                                         for(nov = 1; nov <= 4; nov++){  // PRIMEIRA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }
                                                            
                                                            printf("|| ");
                                                         
                                                         for(i = 1; i <= 5; i++){  
                                                            printf(" -- ");
                                                         }

                                                         for(dez = 1; dez <= 2; dez++){  // PRIMEIRA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ",dez);
                                                         }
                                                            
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 5; nov <= 9; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" 0%d ", nov);
                                                         }

                                                         for(nov = 10; nov <= 11; nov++){  // SEGUNDA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 3; dez <= 9; dez++){  // SEGUNDA SEMANA DE DEZEMBRO //
                                                            printf(" 0%d ", dez);
                                                         }

                                                            printf("|\n");
                                                            printf("| ");
                                                            
                                                         for(nov = 12; nov <= 18; nov++){  // TERCEIRA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 10; dez <= 16; dez++){  // TERCEIRA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");

                                                         for(nov = 19; nov <= 25; nov++){  // QUARTA SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                            printf("|| ");

                                                         for(dez = 17; dez <= 23; dez++){  // QUARTA SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }
                                                         
                                                            printf("|\n");
                                                            printf("| ");


                                                         for(nov = 26; nov <= 30; nov++){  // "QUINTA" SEMANA DE NOVEMBRO //
                                                            printf(" %d ", nov);
                                                         }

                                                         
                                                          for(i = 1; i <= 2 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");

                                                         for(dez = 24; dez <= 30; dez++){  // "QUINTA" SEMANA DE DEZEMBRO //
                                                            printf(" %d ", dez);
                                                         }

                                                            printf("|");
                                                            printf("\n| ");
                                                            

                                                            // sexta linha //
                                                            

                                                         for(i = 1; i <= 7 ; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|| ");
                                                            printf(" 31 ");

                                                         for(i = 1; i <= 6; i++){  
                                                            printf(" -- ");
                                                         }

                                                            printf("|\n");
                                                            printf("|-----------------------------||-----------------------------|\n");                          
                               }

                           }
                        }

                  break;              
            }
       }
    }

   return (num_dias);
}

    // GABRIELA VITORINO //

    