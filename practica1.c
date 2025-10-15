#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define CURRENT_YEAR 2025

/* Practica1 - Programació I (2025-2026)
 * Autors: Santiago Lozada
 * Estratègia: lectura validada de cada parámetre amb bucles while i scanf, aplicació successiva de percentatges
 */

// Mejorar implementacion del while, no repetir tanto while, crear una funcion para reciclar
// Cambiar 0 y 1 por bools

char vehicleType;

const char *validateOptions = "cmsn";

bool validatedInt(int value, int min, int max)
{
    return value >= min && value <= max;
}

bool validatedChar(char value)
{
    value = tolower((unsigned char)value);
    return strchr(validateOptions, value) != NULL;
}

void getValidatedInput(int type, void* value)
{
    bool done = false;
    do
    {
        // VehicleType
        if (type == 1)
        {
            char *charValue = (char *)value;
            if (validatedChar(*charValue))
            {
                printf("Carácter válido: %c\n", *charValue);
                done = true;
            }
            else
            {
                printf("Prem C o M: ");
                scanf(" %c", charValue);
            }
            
        }
        // Age
        else if (type == 2)
        {
            int *intValue = (int *)value;
            if (validatedInt(*intValue, 18, 80))
            {
                printf("Número válido: %d\n", *intValue);
                done = true;
            }
            else
            {
                printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni majors de 80: ");
                scanf("%d", intValue);
            }
        } 
        // EngineType
        else if (type == 3) 
        {
            int *intValue = (int *)value;
            if (validatedInt(*intValue, 1, 3)) {
                printf("Número válido: %d\n", *intValue);
                done = true;
            } else {
                printf("Escull la opció 1, 2 o 3: ");
                scanf("%d", intValue);
            }
        }
        
        // Year Manufacture
        else if (type == 4) {
            int *intValue = (int *)value;
            if (validatedInt(*intValue, 1970, CURRENT_YEAR)) {
                printf("Número válido: %d\n", *intValue);
                done = true;
            } else {
                printf("Introdueix un any entre 1970 i 2025: ");
                scanf("%d", intValue);
            }
        }
        // Us
        else if (type == 5)
        {
            int *intValue = (int *)value;
            if (validatedInt(*intValue, 1, 3))
            {
                printf("Número válido: %d\n", *intValue);
                done = true;
            }
            else
            {
                printf("Escull la opció 1, 2 o 3: ");
                scanf("%d", intValue);
            }
        }
        // EngineCapacity
        else if (type == 6)
        {
            int *intValue = (int *)value;
            if (vehicleType == 'c') {
                if (validatedInt(*intValue, 1, 3))
                {
                    printf("Número válido: %d\n", *intValue);
                    done = true;
                }
                else
                {
                    printf("Escull la opció 1, 2 o 3: ");
                    scanf("%d", intValue);
                }
            } else if (vehicleType == 'm')
            {
                if (validatedInt(*intValue, 1, 4))
                {
                    printf("Número válido: %d\n", *intValue);
                    done = true;
                }
                else
                {
                    printf("Escull la opció 1, 2, 3 o 4: ");
                    scanf("%d", intValue);
                }
            }
            
            
        }

    } while (!done);
}


char vehicleType;
int age;
int engineType;
int manufactureYear;
int uso;
int EngineCapacity;
char reset;

int main()
{
    printf("TARIFICADOR ASEGURADORAS SAFECAR\n");

    // VehicleType
    printf("Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
    scanf(" %c", &vehicleType);
    getValidatedInput(1, &vehicleType);

    // Age
    printf("Edat conductor (18-80): ");
    scanf("%d", &age);
    getValidatedInput(2, &age);

    // EngineType
    printf("Tipus de motor\n");
    printf("1 - Combustió (diesel o gasolina)\n");
    printf("2 - Híbrid\n");
    printf("3 - Elèctric\n");
    printf("Escull la opció 1, 2 o 3: ");
    scanf("%d", &engineType);
    getValidatedInput(3, &engineType);

    // Year manufacture
    printf("Any de fabricació del vehicle (1970-2025): ");
    scanf("%d", &manufactureYear);
    getValidatedInput(4, &manufactureYear);

    // Uso
    printf("Ús:\n");
    printf("1 - Particular\n");
    printf("2 - Lloguer\n");
    printf("3 - Taxi\n");
    printf("Escull la opció 1, 2 o 3: ");
    getValidatedInput(5, &uso);

    // Engine capacity

    if (vehicleType == 'c') {
        // Car
        printf("Tipus de motor:\n");
        printf("1 - Menys o igual de 1.000cc\n");
        printf("2 - Més de 1.000 i menys o igual de 2.000cc\n");
        printf("3 - Més de 3.000cc\n");
        printf("Escull la opció 1, 2 o 3: ");
        getValidatedInput(6, &EngineCapacity);
    } else if (vehicleType == 'm') {
        // Bike
        printf("Tipus de motor:\n");
        printf("1 - Menys de 125cc\n");
        printf("2 - Menys de 500cc\n");
        printf("3 - Menys de 1000cc\n");
        printf("4 - Més de 1000cc\n");
        printf("Escull la opció 1, 2, 3 o 4: ");
        getValidatedInput(6, &EngineCapacity);
    }

    // Reset

    printf("Vols calcular el preu per un altre vehicle (S)í o (N)o? Prem S o N: ");
    scanf(" %c", &reset);
    // reset();

    // int reset = false;

    // float basicThirdPartyBase = 0.0;
    // float advancedThirdPartyBase = 0.0;
    // float totalRiskWithDeductibleBase = 0.0;
    // float totalRiskWithoutDeductibleBase = 0.0;



//     while (!reset)
//     {
//         char inputUser, lowerInputUser;
//         char vehicle[10];
//         int correctInput = false;
//         int attempt = false;

//         while (!correctInput)
//         {
//             if (attempt == true)
//             {
//                 printf("Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
//             }
//             else
//             {
//                 printf("Prem C o M: ");
//             }

//             if (scanf(" %c", &inputUser))
//             {
//                 lowerInputUser = tolower(inputUser);
//                 if (lowerInputUser == 'c' || lowerInputUser == 'm')
//                 {
//                     if (lowerInputUser == 'c')
//                     {
//                         strcpy(vehicle, "Cotxe");
//                         basicThirdPartyBase = 200;
//                         advancedThirdPartyBase = 230;
//                         totalRiskWithDeductibleBase = 330;
//                         totalRiskWithoutDeductibleBase = 400;
//                     }

//                     if (lowerInputUser == 'm')
//                     {
//                         strcpy(vehicle, "Moto");
//                         basicThirdPartyBase = 100;
//                         advancedThirdPartyBase = 120;
//                         totalRiskWithDeductibleBase = 200;
//                         totalRiskWithoutDeductibleBase = 300;
//                     }

//                     correctInput = 1;
//                 }
//                 else
//                 {
//                     attempt++;
//                 }
//             }
//             else
//             {
//                 while (getchar() != '\n')
//                     ;
//             }
//         }

//         int age = 0;
//         correctInput = false;
//         attempt = false;

//         while (!correctInput)
//         {
//             if (attempt == true)
//             {
//                 printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni majors de 80: ");
//             }
//             else
//             {
//                 printf("No assegurem a menors de 18 ni majors de 80: ");
//             }

//             if (scanf("%d", &age))
//             {
//                 if (age >= 18 && age <= 80)
//                 {
//                     if (age >= 18 && age <= 24)
//                     {
//                         basicThirdPartyBase *= 1.7;
//                         advancedThirdPartyBase *= 1.7;
//                         totalRiskWithDeductibleBase *= 1.7;
//                         totalRiskWithoutDeductibleBase *= 1.7;
//                     }
//                     else if (age >= 25 && age <= 29)
//                     {
//                         basicThirdPartyBase *= 1.3;
//                         advancedThirdPartyBase *= 1.3;
//                         totalRiskWithDeductibleBase *= 1.3;
//                         totalRiskWithoutDeductibleBase *= 1.3;
//                     }
//                     else if (age >= 30 && age <= 39)
//                     {
//                         basicThirdPartyBase *= 1.1;
//                         advancedThirdPartyBase *= 1.1;
//                         totalRiskWithDeductibleBase *= 1.1;
//                         totalRiskWithoutDeductibleBase *= 1.1;
//                     }
//                     else if (age >= 40 && age <= 59)
//                     {
//                     }
//                     else if (age >= 60 && age <= 80)
//                     {
//                         basicThirdPartyBase *= 1.2;
//                         advancedThirdPartyBase *= 1.2;
//                         totalRiskWithDeductibleBase *= 1.2;
//                         totalRiskWithoutDeductibleBase *= 1.2;
//                     }

//                     correctInput = 1;
//                 }
//                 else
//                 {
//                     attempt++;
//                 }
//             }
//             else
//             {
//                 while (getchar() != '\n')
//                     ;
//             }
//         }

//         int typeMotor = 0;
//         correctInput = false;
//         attempt = false;

//         while (!correctInput)
//         {
//             if (attempt == true)
//             {
//                 printf("Tipus de motor\n");
//                 printf("1 - Combustió (diesel o gasolina)\n");
//                 printf("2 - Híbrid\n");
//                 printf("3 - Elèctric\n");
//                 printf("Escull l'opció del teu vehicle: ");
//             }
//             else
//             {
//                 printf("Has d'escollir una opcion valida");
//                 printf("Tipus de motor\n");
//                 printf("1 - Combustió (diesel o gasolina)\n");
//                 printf("2 - Híbrid\n");
//                 printf("3 - Elèctric\n");
//                 printf("Escull l'opció del teu vehicle: ");
//             }

//             if (scanf("%d", &typeMotor))
//             {
//                 switch (typeMotor)
//                 {
//                 case 1:

//                     correctInput = 1;
//                     break;
//                 case 2:
//                     basicThirdPartyBase *= 0.9;
//                     advancedThirdPartyBase *= 0.9;
//                     totalRiskWithDeductibleBase *= 0.9;
//                     totalRiskWithoutDeductibleBase *= 0.9;
//                     correctInput = 1;

//                     break;
//                 case 3:
//                     basicThirdPartyBase *= 0.8;
//                     advancedThirdPartyBase *= 0.8;
//                     totalRiskWithDeductibleBase *= 0.8;
//                     totalRiskWithoutDeductibleBase *= 0.8;

//                     correctInput = 1;
//                     break;

//                 default:
//                     attempt++;
//                     break;
//                 }
//             }
//             else
//             {
//                 while (getchar() != '\n')
//                     ;
//             }
//         }

//         int ageManufacture = 0;
//         correctInput = false;
//         attempt = false;

//         while (!correctInput)
//         {
//             if (attempt == true)
//             {
//                 printf("Any de fabricació del vehicle (1970 - 2025): ");
//             }
//             else
//             {
//                 printf("Introdueix un any entre 1970 i 2025: ");
//             }

//             if (scanf("%d", &ageManufacture))
//             {
//                 if (ageManufacture >= 1970 && ageManufacture <= CURRENT_YEAR)
//                 {
//                     int vehicleAge = CURRENT_YEAR - ageManufacture;
//                     if (vehicleAge > 10)
//                     {
//                         totalRiskWithDeductibleBase = 0;
//                         totalRiskWithoutDeductibleBase = 0;
//                         basicThirdPartyBase *= 1.1;
//                         advancedThirdPartyBase *= 1.1;
//                     }

//                     correctInput = 1;
//                 }
//                 else
//                 {
//                     attempt++;
//                 }
//             }
//             else
//             {
//                 while (getchar() != '\n')
//                     ;
//             }
//         }

//         if (lowerInputUser == 'c')
//         {
//             int vehicleUse = 0;
//             correctInput = false;
//             attempt = false;

//             while (!correctInput)
//             {
//                 if (attempt == true)
//                 {
//                     printf("Ús\n");
//                     printf("1 - Particular\n");
//                     printf("2 - Lloguer\n");
//                     printf("3 - Taxi\n");
//                     printf("Escull l'opció del teu vehicle: ");
//                 }
//                 else
//                 {
//                     printf("Has d'escollir una opcion valida\n");
//                     printf("Tipus de motor\n");
//                     printf("1 - Particular\n");
//                     printf("2 - Lloguer\n");
//                     printf("3 - Taxi\n");
//                     printf("Escull l'opció del teu vehicle: ");
//                 }

//                 if (scanf("%d", &vehicleUse))
//                 {
//                     switch (vehicleUse)
//                     {
//                     case 1:
//                         correctInput = 1;
//                         break;
//                     case 2:
//                         basicThirdPartyBase *= 1.05;
//                         advancedThirdPartyBase *= 1.05;
//                         totalRiskWithDeductibleBase *= 1.05;
//                         totalRiskWithoutDeductibleBase *= 1.05;

//                         correctInput = 1;
//                         break;
//                     case 3:
//                         basicThirdPartyBase *= 1.1;
//                         advancedThirdPartyBase *= 1.1;
//                         totalRiskWithDeductibleBase *= 1.1;
//                         totalRiskWithoutDeductibleBase *= 1.1;

//                         correctInput = 1;
//                         break;

//                     default:
//                         attempt++;
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     while (getchar() != '\n')
//                         ;
//                 }
//             }
//         }

//         int engine = 0;
//         correctInput = false;
//         attempt = false;

//         while (!correctInput)
//         {
//             if (attempt == true && lowerInputUser == 'c')
//             {
//                 printf("Ús\n");
//                 printf("1 - Menys o igual de 1.000cc\n");
//                 printf("2 - Més de 1.000 i menys o igual de 2.000cc\n");
//                 printf("3 - Més de 3.000cc\n");
//                 printf("Escull l'opció del teu vehicle: ");
//             }
//             else
//             {
//                 printf("Has d'escollir una opcion valida\n");
//                 printf("Tipus de motor\n");
//                 printf("1 - Menys o igual de 1.000cc\n");
//                 printf("2 - Més de 1.000 i menys o igual de 2.000cc\n");
//                 printf("3 - Més de 3.000cc\n");
//                 printf("Escull l'opció del teu vehicle: ");
//             }

//             if (attempt == true && lowerInputUser == 'm')
//             {
//                 printf("Ús\n");
//                 printf("1 - Menys de 125cc\n");
//                 printf("2 - Menys de 500cc\n");
//                 printf("3 - Menys de 1000cc\n");
//                 printf("4 - Més de 1000cc\n");
//                 printf("Escull l'opció del teu vehicle: ");
//             }
//             else
//             {
//                 printf("Has d'escollir una opcion valida\n");
//                 printf("Tipus de motor\n");
//                 printf("1 - Menys de 125cc\n");
//                 printf("2 - Menys de 500cc\n");
//                 printf("3 - Menys de 1000cc\n");
//                 printf("4 - Més de 1000cc\n");
//                 printf("Escull l'opció del teu vehicle: ");
//             }

//             if (scanf("%d", &engine))
//             {
//                 switch (engine)
//                 {
//                 case 1:
//                     correctInput = 1;
//                     break;
//                 case 2:
//                     if (lowerInputUser == 'c')
//                     {
//                         basicThirdPartyBase *= 1.1;
//                         advancedThirdPartyBase *= 1.1;
//                         totalRiskWithDeductibleBase *= 1.1;
//                         totalRiskWithoutDeductibleBase *= 1.1;
//                     }

//                     if (lowerInputUser == 'm')
//                     {
//                         basicThirdPartyBase *= 1.1;
//                         advancedThirdPartyBase *= 1.1;
//                         totalRiskWithDeductibleBase *= 1.1;
//                         totalRiskWithoutDeductibleBase *= 1.1;
//                     }
//                     correctInput = 1;
//                     break;
//                 case 3:
//                     if (lowerInputUser == 'c')
//                     {
//                         basicThirdPartyBase *= 1.2;
//                         advancedThirdPartyBase *= 1.2;
//                         totalRiskWithDeductibleBase *= 1.2;
//                         totalRiskWithoutDeductibleBase *= 1.2;
//                     }

//                     if (lowerInputUser == 'm')
//                     {
//                         basicThirdPartyBase *= 1.15;
//                         advancedThirdPartyBase *= 1.15;
//                         totalRiskWithDeductibleBase *= 1.15;
//                         totalRiskWithoutDeductibleBase *= 1.15;
//                     }
//                     correctInput = 1;
//                     break;

//                 case 4:
//                     if (lowerInputUser == 'm')
//                     {
//                         basicThirdPartyBase *= 1.3;
//                         advancedThirdPartyBase *= 1.3;
//                         totalRiskWithDeductibleBase *= 1.3;
//                         totalRiskWithoutDeductibleBase *= 1.3;
//                         correctInput = 1;
//                     }
//                     break;

//                 default:
//                     attempt++;
//                     break;
//                 }
//             }
//             else
//             {
//                 while (getchar() != '\n')
//                     ;
//             }
//         }

//         float basicThirdPartyMonth = basicThirdPartyBase * 1.06f;
//         float advancedThirdPartyMonth = advancedThirdPartyBase * 1.06f;
//         float totalRiskWithDeductibleMonth = totalRiskWithDeductibleBase * 1.06f;
//         float totalRiskWithoutDeductibleMonth = totalRiskWithoutDeductibleBase * 1.06f;

//         float basicThirdPartyTrimestral = basicThirdPartyBase * 1.04f;
//         float advancedThirdPartyTrimestral = advancedThirdPartyBase * 1.04f;
//         float totalRiskWithDeductibleTrimestral = totalRiskWithDeductibleBase * 1.04f;
//         float totalRiskWithoutDeductibleTrimestral = totalRiskWithoutDeductibleBase * 1.04f;

//         float basicThirdPartySemestral = basicThirdPartyBase * 1.02f;
//         float advancedThirdPartySemestral = advancedThirdPartyBase * 1.02f;
//         float totalRiskWithDeductibleSemestral = totalRiskWithDeductibleBase * 1.02f;
//         float totalRiskWithoutDeductibleSemestral = totalRiskWithoutDeductibleBase * 1.02f;

//         float basicThirdPartyYear = basicThirdPartyBase;
//         float advancedThirdPartyYear = advancedThirdPartyBase;
//         float totalRiskWithDeductibleYear = totalRiskWithDeductibleBase;
//         float totalRiskWithoutDeductibleYear = totalRiskWithoutDeductibleBase;

//         printf("----------------------------------------------------------------------------------------------------------------\n");

//         if (lowerInputUser == 'c')
//         {
//             printf("| %-13s | %-13s | %-15s | %-28s | %-22s |\n",
//                    "Fraccionament", "Tercers bàsic", "Tercers avançat",
//                    "Tot risc amb franquícia (200€)", "Tot risc sense franquícia");
//             printf("----------------------------------------------------------------------------------------------------------------\n");

//             printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
//                    "MENSUAL", basicThirdPartyMonth, advancedThirdPartyMonth,
//                    totalRiskWithDeductibleMonth, totalRiskWithoutDeductibleMonth);

//             printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
//                    "TRIMESTRAL", basicThirdPartyTrimestral, advancedThirdPartyTrimestral,
//                    totalRiskWithDeductibleTrimestral, totalRiskWithoutDeductibleTrimestral);

//             printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
//                    "SEMESTRAL", basicThirdPartySemestral, advancedThirdPartySemestral,
//                    totalRiskWithDeductibleSemestral, totalRiskWithoutDeductibleSemestral);

//             printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
//                    "ANUAL", basicThirdPartyYear, advancedThirdPartyYear,
//                    totalRiskWithDeductibleYear, totalRiskWithoutDeductibleYear);
//         }
//         else
//         {
//             printf("| %-13s | %-13s | %-15s |\n",
//                    "Fraccionament", "Tercers bàsic", "Tercers avançat");
//             printf("---------------------------------------------------------------\n");

//             printf("| %-13s | %13.2f € | %15.2f € |\n",
//                    "MENSUAL", basicThirdPartyMonth, advancedThirdPartyMonth);
//             printf("| %-13s | %13.2f € | %15.2f € |\n",
//                    "TRIMESTRAL", basicThirdPartyTrimestral, advancedThirdPartyTrimestral);
//             printf("| %-13s | %13.2f € | %15.2f € |\n",
//                    "SEMESTRAL", basicThirdPartySemestral, advancedThirdPartySemestral);
//             printf("| %-13s | %13.2f € | %15.2f € |\n",
//                    "ANUAL", basicThirdPartyYear, advancedThirdPartyYear);
//         }

//         printf("----------------------------------------------------------------------------------------------------------------\n");

//         char inputUser2, lowerInputUser2;
//         correctInput = false;
//         attempt = false;

//         while (!correctInput)
//         {
//             if (attempt == true)
//             {
//                 printf("Vols calcula el preu per un altre vehicle (S)í o (N)o? Prem S o N: ");
//             }
//             else
//             {
//                 printf("Prem S o N: ");
//             }

//             if (scanf(" %c", &inputUser2))
//             {
//                 lowerInputUser2 = tolower(inputUser2);
//                 if (lowerInputUser2 == 's' || lowerInputUser2 == 'n')
//                 {
//                     if (lowerInputUser2 == 'n')
//                     {
//                         printf("Moltes gràcies per utilitzar el nostre tarificador. Fins la pròxima! Assegurances SafeCar");
//                         correctInput = 1;
//                         reset = 1;
//                     }

//                     correctInput = 1;
//                 }
//                 else
//                 {
//                     attempt++;
//                 }
//             }
//             else
//             {
//                 while (getchar() != '\n')
//                     ;
//             }
//         }
//     }
}