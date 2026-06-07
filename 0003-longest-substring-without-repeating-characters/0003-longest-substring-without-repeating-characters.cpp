#include <unordered_map>
#include <string>
#include <iterator>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int string_size = s.length();
        int longest_size=1;  //el minimo posible para un s no vació 1
        int size=0;        //se inicializa el size en 0. Este se obtandrá con la diferencia entre cotas izquierda y derecha

        const char * left = s.c_str(); //apuntador de solo lectura al inicio de la cadena
        
        if(*left == '\0'){
            return 0;           //si s es vació, pues se retorna 0
        }

        const char * right = left; 

        unordered_map<char, const char *> letters_map;
        
        //letters_map[*left] = left; si haces esto el entrarás al primer if y en casos de cadenas de tamaño 2 con chars diferentes, el resultado será simpre 1 y no 2.

    
        while(*right != '\0'){


            //si la dirección está mapeada y dentro de la ventana, ya hubo repetición
            if(letters_map.find(*right) != letters_map.end() && letters_map.at(*right) >= left){ 
                left = letters_map[*right]+1;   // se acutualiza la cota izquierda a la primera aparición de la letra que se repitió    
            }

            size = right - left + 1; //se suma 1 para contar el tamaño bruto de la subcadena 
            longest_size = (size > longest_size) ? size : longest_size;
            
            letters_map[*right] = right; //se actualiza de referencia de la última letra y movemos la cota derecha.
            ++right;
        
        }

        return longest_size;
    }

                
                


};


/*
int longest_size=1;
        int size=1;
        const char * left = s.c_str();
        
        if(*left == '\0'){
            return 0;
        }

        const char * right = left+1; 

        unordered_map<char, const char *> letters_map;
        
        letters_map[*left] = left;


        while(*left != '\0' && *right != '\0'){
            
            
            if(letters_map.find(*right) == letters_map.end()){
                letters_map[*right] = right;
                ++size;
                ++right;
                
            }
            
            else{
                ++left;
                right = left+1;
                size=1;
                
                letters_map.clear();
                letters_map[*left] = left;
            }

            longest_size = (size >= longest_size) ? size : longest_size;
        }

        return longest_size;
    }
*/


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna