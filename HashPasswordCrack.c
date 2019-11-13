#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>


//user input hash
int main(int argc, char *argv[]) 
{
    char *newhash; 
    
    int keylength = 6;
    int counter = 0;
    int counter_2 = 0;
    int counter_3 = 0;
    int counter_4 = 0;
    
    char keytry[1][keylength];
    char salt[1][2]; //array for salt
    char directory [1][53];
        //Check number of command line arguments. Needs 1, Hash
    if (argc != 2)
    {
        printf("Uhh Ohh Spaghettios! FAILURE \n");
        return 1;      
    }
    else
    {
    }
    
    for (int i = 0, n = 2; i < n; i ++)  //Write salt 
    {
        salt[0][i] = argv[1][i];                          
    }
    
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //create alphabet  
    strcpy(directory[0], alphabet);  //copy alphabet to array
   
    for (int i = 0, n = strlen(alphabet); i <= n + 1; i++) // First loop A
    {
        keytry[0][1] = 0;
        keytry[0][0] = directory[0][i];            
        printf("Checking %s Words\n", keytry[0]);             // Prints single letter keys
        newhash = crypt(keytry[0], salt[0]);        // Crypt function using salt
        
        if (strcmp(newhash, argv[1]) == 0) //Check if key attempt matches command input       
        {        
            printf("Password: %s \n", keytry[0]);            
            printf("Hash Password: %s \n", newhash);           
            return 0;            
        }           
        else if (counter >= 1)            // 2nd Loop AA
            {
                for (int j = 0, m = strlen(alphabet); j <= m; j++) 
                {
                    keytry[0][2] = 0; 
                    keytry[0][1] = directory[0][j];
                    newhash = crypt(keytry[0], salt[0]);        // Crypt function using salt
                    printf("2 %s \n", keytry[0]);            // Prints 2 letter keys
                    if (strcmp(newhash, argv[1]) == 0) //Check if key attempt matches command input
                    {
                        printf("Hash Password: %s \n", newhash);                             
                        printf("Password: %s \n", keytry[0]);                        
                        return 0;
                    }                    
                    else if (j == m)
                    {
                        counter_2 += 1;
                    }
                    else if (counter_2 >= 1)         // 3rd Loop AAA
                    {
                         for (int t = 0, b = strlen(alphabet); t <= b + 1; t++)
                        {
                            keytry[0][3] = 0;
                            keytry[0][2] = directory[0][t];
                            newhash = crypt(keytry[0], salt[0]);        // Crypt function using salt and key attempt
                            //printf("3 %s \n", keytry[0]);    // Prints 3 letter keys
                            if (strcmp(newhash, argv[1]) == 0) //Check if key attempt matches command input
                            {
                                printf("Hash Password: %s \n", newhash);                             
                                printf("Password: %s \n", keytry[0]);                        
                                return 0;
                            }
                            else if (t == b)
                            {
                                counter_3 += 1;
                            }
                             else if (counter_3 >= 1)        // 4th Loop
                             {
                                 for (int h = 0, k = strlen(alphabet); h <= k; h++)
                                 {
                                     keytry[0][4] = 0;
                                     keytry[0][3] = directory[0][h];
                                     newhash = crypt(keytry[0], salt[0]);        // Crypt function using salt and key attempt
                                    // printf("4 %s \n", keytry[0]);    // Prints 4 letter keys
                                    if (strcmp(newhash, argv[1]) == 0) //Check if key attempt matches command input
                                    {
                                        printf("Hash Password: %s \n", newhash);                             
                                        printf("Password: %s \n", keytry[0]);                        
                                        return 0;
                                    }
                                     else if (h == k)
                                     {
                                         counter_4 += 1;
                                     }
                                     else if (counter_4 >= 1)        //5th loop
                                     {
                                         for (int d = 0, x = strlen(alphabet) - 1; d <= x; d++)
                                         {
                                             keytry[0][5] = 0;
                                             keytry[0][4] = directory[0][d];
                                             newhash = crypt(keytry[0], salt[0]);        // Crypt function using salt and key attempt
                                            // printf("5 %s \n", keytry[0]);    // Prints 5 letter keys
                                            if (strcmp(newhash, argv[1]) == 0) //Check if key attempt matches command input
                                            {
                                                printf("Hash Password: %s \n", newhash);                             
                                                printf("Password: %s \n", keytry[0]);                        
                                                return 0;
                                            }
                                            else if (d == (x))
                                            {                                            
                                            }
                                         }
                                     }
                                 }
                             }
                         }
                    }
                }
        }
        else if (i == (n - 1))
        {
            i = -2;
            counter += 1;
        }
        else
        {           
        }
    }
}

