#include <iostream>

int main()
{
    int iniCadeia = 1;
    int contIf = 0;
    int contThen = 0;
    int iden = 1;
    int contIden = 0;
    int contNun = 0;
    std::string teste = "if\nthen\nelse\n1234 ";

    for(int i = 0; i < teste.size(); i++){
        if(iniCadeia != 1){
            if(teste[i] != 32 || teste[i] != '\n'){
                if(!((teste[i] >= 48 && teste[i] <= 57) || (teste[i] >= 65 && teste[i] <= 90) || (teste[i] >= 97 && teste[i] <= 122))){
                    if(iden == 1){
                        std::cout<<"caracter invalido no identificador"<<std::endl;
                        break;
                    }
                }else if (!((teste[i] >= 48 && teste[i] <= 57))){
                    if(nun == 1){
                        std::cout<<"caracter invalido em inteiros"<<std::endl;
                        break;
                    }
                   }
            }else{
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
        }else{
            if((teste[i] >= 65 && teste[i] <= 90) || (teste[i] >= 97 && teste[i] <= 122)){
                if(teste[i] == 'i'){
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
                }else if(teste[i] == 't'){
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
            }else if((teste[i] >= 48 && teste[i] <= 57)){
                nun = 1;
                iniCadeia = 0;
            }
        }
    }

    std::cout<<"If: "<<contIf<<std::endl;
    std::cout<<"Then: "<<contThen<<std::endl;
    std::cout<<"Inteiro: "<<contNun<<std::endl;
    std::cout<<"Identificador: "<<contIden<<std::endl;

    return;
}
