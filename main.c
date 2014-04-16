#include <stdio.h>
#include <string.h>

typedef char * (func)(int x);

char * int_to_roman(int x)
{
    /*
    char result[10];
    int indice=0;
    while(x > 0)
    {
        if(x > 10)
        {
            x -= 10;
            result[indice] = 'X';
            indice++;
        } else if (x > 5) {
            x-=5;
            result[indice]='V';
            indice++;
        }
        else if(x==4)
        {
            x-=4;
            result[indice]='I';
            indice++;
            result[indice]='V';
            indice++;
        }
        else 
        {
            x-=1;
            result[indice]='I';
            indice++;
            result[indice]='X';
            indice++;
        }
    }
    result[indice]='\0';
    */
    char result[100];
    int indice=0;
    strcpy(result,"");
    while(x > 0)
    {
        if(x > 10)
        {
            x -= 10;
            strcat(result,'X');
        }
        else if(x > 5)
        {
            x -= 5;
            strcat(result,'V');
        }
        else
        {
            x -= 1;
            strcat(result,'I');
        }
    }
    return result;
}



void test(func *f, int x, char* result)
{
    if (strcmp(f(x),result)==0) {
        printf("passou\n");
    } else {
        printf("nao passou Valor esperado %s e valor resultante %s\n",result,f(x));
    }
}

int main()
{
    test(int_to_roman, 1, "I");
    test(int_to_roman, 2, "II");
    test(int_to_roman, 4, "IV");
    test(int_to_roman, 5, "V");
    test(int_to_roman, 9, "IX");
    test(int_to_roman, 40, "XL");
    test(int_to_roman, 50, "L");
}


/*
    if(x==1)
        return "I";
    else if(x==2)
        return "II";
    else if(x == 4)
        return "IV";
    else if(x==5)
        return "V";
    else if(x==9)
        return "IX";
    else if(x==40)
        return "XL";
    else
        return "!";
        
        =================
        
    char *result[10];
    int indice=0;
    while(x > 0)
    {
        if(x == 50)
        {
            x -= 50;
            result = "L";
            return result;
        }
        else if(x > 10)
        {
            x -= 10;
            result += "LS";
        }
        else if(x==2)
            return "II";
        else if(x == 4)
            return "IV";
        else if(x==5)
            return "V";
        else if(x==9)
            return "IX";
        else if(x==40)
            return "XL";
        else
            return "!";
    }
*/