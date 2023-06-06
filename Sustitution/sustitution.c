#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cstring>

/*Programa de cifrado de texto*/
/*Mediante sustitucion de alfabeto*/

char* clave;
char abecedario[27] = "abcdefghijklmnopqrstuvwxyz";
char TextoACifrar[1000];

/*Se valida si la letra recibida 
 corresponde a un caracter valido*/
int esLetra(char c){
    int esMayuscula = ( 65 <= c && c <= 90 );
    int esMinuscula = ( 97 <= c && c <= 122 );
    return esMayuscula || esMinuscula;
}

/*Se valida si la clave cumple con los parametros requeridos*/
int ValidacionClave() {
    
    //El alfabeto debe contener 26 letras
    if (strlen(clave) != 26){
        return 1;
    }
    //No debe poseer caracteres repetidos
    for (int i = 0; i < 26; i++)
    {
        for (int j = i+1; j < 27; j++)
        {
            if (!esLetra(clave[i]) || tolower(clave[i]) == tolower(clave[j]) )
            {
                return 1;
            }
            
        }
        
    }
    
    return 0;
}

/*Se codifica el mensaje*/
void codificar(){
   
    printf("Ciphertext: ");
    int n = strlen(TextoACifrar);
   
    //Se revisa letra por letra el texto
    for (int i = 0; i < n; i++)
    {
        
       char letra = TextoACifrar[i];
       int esMayuscula = (65 <= letra && letra <= 90);
       int posicion = -1;

        //Se localiza el indice de la letra leida
       for (int j = 0; j < 27; j++)
       {
            if (abecedario[j] == tolower(letra)){
                posicion = j;
                break;
            }
       }
        //Si es un caracter ajeno al alfabeto se imprime sin modificacion
        if (posicion == -1){
            printf("%c", letra);
        }
        
        //Si es mayuscula se imprime en mayuscula
       else if(esMayuscula){
        printf("%c", toupper(clave[posicion]));
       }
       else{
        printf("%c", clave[posicion]);
       }
    }
    printf("\n");
}

int main(int argc, char *argv[]){

    //Se valida la cantidad de argumentos
    //que se recibe en la linea de comandos
    if (argc != 2)
    {
        return 1;
    }
    
    printf("\n\n→→→→ BIENVENIDOS A \"1N¢R1PT4¢10N\"←←←←\n\n");
    clave = argv[1];

    
    if (ValidacionClave() == 1){
        printf("Error en la clave suministrada\n");
        return 1;    
    }

    for ( int i = 0; i < 27; i++){
        clave[i] = tolower(clave[i]);
    }

    printf("Plaintext: ");
    scanf("%[^\n]", TextoACifrar);
    codificar();
    return 0;

}




   