#include <iostream>

int main()
{
    int iniCadeia = 1;
    int contIf = 0;
    int contThen = 0;
    int iden = 0;
    int nun = 0;
    int contIden = 0;
    int contNun = 0;
    std::string teste = "iff\nthenn\nelse\n1234\n345546345\nint teste\n";

    for(int i = 0; i < teste.size(); i++){
        if(iniCadeia != 1){                                                                                                             //Verifica inicio de cadeia
            if((teste[i] != 32) && (teste[i] != '\n')){                                                                                 //Verifica fim da cadeia
                if(!((teste[i] >= 48 && teste[i] <= 57) || (teste[i] >= 65 && teste[i] <= 90) || (teste[i] >= 97 && teste[i] <= 122))){ //Verifica se a cadeia está entre caracteres aceitos
                    if(iden == 1){                                                                                                      //Verifica caracteres aceitos de identificador
                        std::cout<<"caracter invalido no identificador"<<std::endl;
                        break;
                    }else if(!(teste[i] >= 48 && teste[i] <= 57)){                                                                      //Verifica caracteres aceitos de inteiros
                        if(nun == 1){
                            std::cout<<"caracter invalido em inteiros"<<std::endl;
                            break;
                        }
                    }
                }
            }else{                                                                                                                      //Verifica tipo de dado encontrado ao fim da cadeia
                iniCadeia = 1;
                if(iden == 1){
                    contIden++;
                    iden = 0;
                }
                if(nun == 1){
                    contNun++;
                    nun = 0;
                }
            }
        }else{                                                                                                                          //Verifica inicio da cadeia
            if((teste[i] >= 65 && teste[i] <= 90) || (teste[i] >= 97 && teste[i] <= 122)){                                              //Verifica se inicio é letra
                if(teste[i] == 'i'){                                                                                                    //Inicio da verificação de if
                    if(teste[i+1] == 'f'){
                        if(teste[i+2] == '\n' || teste[i+2] == 32){
                            contIf++;
                            i = i+2;
                        }else{
                            iniCadeia = 0;
                            iden = 1;
                        }
                    }else{
                        iniCadeia = 0;
                        iden = 1;
                    }
                }else if(teste[i] == 't'){                                                                                              //Inicio da verificação de Then
                    if(teste[i+1] == 'h'){
                        if(teste[i+2] == 'e'){
                            if(teste[i+3] == 'n'){
                                if(teste[i+4] == '\n' || teste[i+2] == 32){
                                    contThen++;
                                    i = i+4;
                                }else{
                                    iniCadeia = 0;
                                    iden = 1;
                                }
                            }else{
                                iniCadeia = 0;
                                iden = 1;
                            }
                        }else{
                            iniCadeia = 0;
                            iden = 1;
                        }
                    }else{
                        iden = 1;
                        iniCadeia = 0;
                    }
                }else{                                                                                                                 //Se não encontrado if ou then marca como identificador
                    iden = 1;
                    iniCadeia = 0;
                }
            }else if((teste[i] >= 48 && teste[i] <= 57)){                                                                              //Verifica inicio da cadeia como inteiro
                    nun = 1;
                    iniCadeia = 0;
            }else{
                std::cout<<"caracter invalido em inicio da cadeia"<<std::endl;
                break;
            }
        }
    }

    std::cout<<"If: "<<contIf<<std::endl;
    std::cout<<"Then: "<<contThen<<std::endl;
    std::cout<<"Inteiro: "<<contNun<<std::endl;
    std::cout<<"Identificador: "<<contIden<<std::endl;

    return 0;
}
