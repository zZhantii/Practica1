#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    printf("TARIFICADOR ASEGURADORAS SAFECARR");

    int reset = 0;

    float basicThirdPartyBase = 0.0;
    float advancedThirdPartyBase = 0.0;
    float totalRiskWithDeductibleBase = 0.0;
    float totalRiskWithoutDeductibleBase = 0.0;

    float basicThirdParty = 0.0;
    float advancedThirdParty = 0.0;
    float totalRiskWithDeductible = 0.0;
    float totalRiskWithoutDeductible = 0.0;

        while (!reset)
    {
        // Choose C or M
        char inputUser, lowerInputUser;
        char vehicle[10];
        int correctInput = 0;
        int attempt = 0;

        while (!correctInput)
        {
            if (attempt == 0)
            {
                printf("Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
            }
            else
            {
                printf("Prem C o M: ");
            }

            if (scanf(" %c", &inputUser))
            {
                lowerInputUser = tolower(inputUser);
                if (lowerInputUser == 'c' || lowerInputUser == 'm')
                {
                    if (lowerInputUser == 'c') {
                        strcpy(vehicle, "Cotxe");
                        basicThirdPartyBase = 200;
                        advancedThirdPartyBase = 230;
                        totalRiskWithDeductibleBase = 330;
                        totalRiskWithoutDeductibleBase = 400;

                        // printf("Valores coche:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdPartyBase);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdPartyBase);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductibleBase);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductibleBase);
                    }

                    if (lowerInputUser == 'm')
                    {
                        strcpy(vehicle, "Moto");
                        basicThirdPartyBase = 100;
                        advancedThirdPartyBase = 120;
                        totalRiskWithDeductibleBase = 200;
                        totalRiskWithoutDeductibleBase = 300;

                        // printf("Valores moto:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdPartyBase);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdPartyBase);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductibleBase);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductibleBase);
                    }

                    correctInput = 1;
                }
                else
                {
                    attempt++;
                }
            }
            else
            {
                while (getchar() != '\n')
                    ;
            }
        }

        // Age
        int age = 0;
        correctInput = 0;
        attempt = 0;

        while (!correctInput)
        {
            if (attempt == 0)
            {
                printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni majors de 80: ");
            }
            else
            {
                printf("No assegurem a menors de 18 ni majors de 80: ");
            }

            if (scanf("%d", &age))
            {
                if (age >= 18 && age <= 80)
                {
                    if (age >= 18 && age <= 24) {
                        basicThirdParty *= 1.7;
                        advancedThirdParty *= 1.7;
                        totalRiskWithDeductible *= 1.7;
                        totalRiskWithoutDeductible *= 1.7;
                    }
                    else if (age >= 25 && age <= 29)
                    {
                        basicThirdParty *= 1.3;
                        advancedThirdParty *= 1.3;
                        totalRiskWithDeductible *= 1.3;
                        totalRiskWithoutDeductible *= 1.3;
                    }
                    else if (age >= 30 && age <= 39)
                    {
                        basicThirdParty *= 1.1;
                        advancedThirdParty *= 1.1;
                        totalRiskWithDeductible *= 1.1;
                        totalRiskWithoutDeductible *= 1.1;
                    }
                    else if (age >= 40 && age <= 59)
                    {
                    
                    }
                    else if (age >= 60 && age <= 80)
                    {
                        basicThirdParty *= 1.2;
                        advancedThirdParty *= 1.2;
                        totalRiskWithDeductible *= 1.2;
                        totalRiskWithoutDeductible *= 1.2;
                    }

                    correctInput = 1;
                }
                else
                {
                    attempt++;
                }
            }
            else
            {
                while (getchar() != '\n');
            }
        }

        // Type Motor of vehicle
        int typeMotor = 0;
        correctInput = 0;
        attempt = 0;

        while (!correctInput)
        {
            if (attempt == 0)
            {
                printf("Tipus de motor\n");
                printf("1 - Combustió (diesel o gasolina)\n");
                printf("2 - Híbrid\n");
                printf("3 - Elèctric\n");
                printf("Escull l'opció del teu vehicle: ");
            }
            else
            {
                printf("Has d'escollir una opcion valida");
                printf("Tipus de motor\n");
                printf("1 - Combustió (diesel o gasolina)\n");
                printf("2 - Híbrid\n");
                printf("3 - Elèctric\n");
                printf("Escull l'opció del teu vehicle: ");
            }

            if (scanf("%d", &typeMotor))
            {
                switch (typeMotor)
                {
                case 1:
                    // printf("motor de combustion");

                    correctInput = 1;
                    break;
                case 2:
                    // printf("motor de hybrido");
                    basicThirdParty *= 0.9;
                    advancedThirdParty *= 0.9;
                    totalRiskWithDeductible *= 0.9;
                    totalRiskWithoutDeductible *= 0.9;
                    correctInput = 1;

                    // printf("Valores con porcentaje:\n");
                    // printf("Basic Third Party: %.2f\n", basicThirdParty);
                    // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                    // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                    // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    break;
                case 3:
                    // printf("motor de electrico");
                    basicThirdParty *= 0.8;
                    advancedThirdParty *= 0.8;
                    totalRiskWithDeductible *= 0.8;
                    totalRiskWithoutDeductible *= 0.8;

                    // printf("Valores con porcentaje:\n");
                    // printf("Basic Third Party: %.2f\n", basicThirdParty);
                    // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                    // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                    // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    correctInput = 1;
                    break;

                default:
                    attempt++;
                    break;
                }
            }
            else
            {
                while (getchar() != '\n')
                    ;
            }
        }

        // year of manufacture
        int ageManufacture = 0;
        correctInput = 0;
        attempt = 0;

        while (!correctInput)
        {
            if (attempt == 0)
            {
                printf("Any de fabricació del vehicle (1970 - 2025): ");
            }
            else
            {
                printf("Introdueix un any entre 1970 i 2025: ");
            }

            if (scanf("%d", &ageManufacture))
            {
                if (ageManufacture >= 1970 && ageManufacture <= 2025)
                {
                    int vehicleAge = 2025 - ageManufacture;
                    if (vehicleAge > 10) {
                        totalRiskWithDeductible = 0;
                        totalRiskWithoutDeductible = 0;
                        basicThirdParty *= 1.1;
                        advancedThirdParty *= 1.1;
                    }

                    correctInput = 1;
                }
                else
                {
                    attempt++;
                }
            }
            else
            {
                while (getchar() != '\n')
                    ;
            }
        }

        if (lowerInputUser == 'c') {
            // vehicle use
            int vehicleUse = 0;
            correctInput = 0;
            attempt = 0;

            while (!correctInput)
            {
                if (attempt == 0)
                {
                    printf("Ús\n");
                    printf("1 - Particular\n");
                    printf("2 - Lloguer\n");
                    printf("3 - Taxi\n");
                    printf("Escull l'opció del teu vehicle: ");
                }
                else
                {
                    printf("Has d'escollir una opcion valida\n");
                    printf("Tipus de motor\n");
                    printf("1 - Particular\n");
                    printf("2 - Lloguer\n");
                    printf("3 - Taxi\n");
                    printf("Escull l'opció del teu vehicle: ");
                }

                if (scanf("%d", &vehicleUse))
                {
                    switch (vehicleUse)
                    {
                    case 1:
                        // printf("Particular");
                        correctInput = 1;
                        break;
                    case 2:
                        // printf("Lloguer");
                        basicThirdParty *= 1.05;
                        advancedThirdParty *= 1.05;
                        totalRiskWithDeductible *= 1.05;
                        totalRiskWithoutDeductible *= 1.05;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                        correctInput = 1;
                        break;
                    case 3:
                        // printf("Taxi");
                        basicThirdParty *= 1.1;
                        advancedThirdParty *= 1.1;
                        totalRiskWithDeductible *= 1.1;
                        totalRiskWithoutDeductible *= 1.1;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                        correctInput = 1;
                        break;

                    default:
                        attempt++;
                        break;
                    }
                }
                else
                {
                    while (getchar() != '\n')
                        ;
                }
            }
        }

        
        // displacement
        int engine = 0;
        correctInput = 0;
        attempt = 0;

        while (!correctInput)
        {
            if (attempt == 0)
            {
                printf("Ús\n");
                printf("1 - Menys o igual de 1.000cc\n");
                printf("2 - Més de 1.000 i menys o igual de 2.000cc\n");
                printf("3 - Més de 3.000cc\n");
                printf("Escull l'opció del teu vehicle: ");
            }
            else
            {
                printf("Has d'escollir una opcion valida\n");
                printf("Tipus de motor\n");
                printf("1 - Menys o igual de 1.000cc\n");
                printf("2 - Més de 1.000 i menys o igual de 2.000cc\n");
                printf("3 - Més de 3.000cc\n");
                printf("Escull l'opció del teu vehicle: ");
            }

            if (scanf("%d", &engine))
            {
                switch (engine)
                {
                case 1:
                    // printf("Menys o igual de 1.000cc");
                    if (lowerInputUser == 'm')
                    {
                        basicThirdParty *= 1.1;
                        advancedThirdParty *= 1.1;
                        totalRiskWithDeductible *= 1.1;
                        totalRiskWithoutDeductible *= 1.1;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    }
                    correctInput = 1;
                    break;
                case 2:
                    // printf("Més de 1.000 i menys o igual de 2.000cc");
                    if (lowerInputUser == 'c')
                    {
                        basicThirdParty *= 1.1;
                        advancedThirdParty *= 1.1;
                        totalRiskWithDeductible *= 1.1;
                        totalRiskWithoutDeductible *= 1.1;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    }

                    if (lowerInputUser == 'm')
                    {
                        basicThirdParty *= 1.15;
                        advancedThirdParty *= 1.15;
                        totalRiskWithDeductible *= 1.15;
                        totalRiskWithoutDeductible *= 1.15;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    }
                    correctInput = 1;
                    break;
                case 3:
                    // printf("Més de 3.000cc");
                    if (lowerInputUser == 'c') {
                        basicThirdParty *= 1.2;
                        advancedThirdParty *= 1.2;
                        totalRiskWithDeductible *= 1.2;
                        totalRiskWithoutDeductible *= 1.2;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    }

                    if (lowerInputUser == 'm')
                    {
                        basicThirdParty *= 1.3;
                        advancedThirdParty *= 1.3;
                        totalRiskWithDeductible *= 1.3;
                        totalRiskWithoutDeductible *= 1.3;
                        correctInput = 1;

                        // printf("Valores con porcentaje:\n");
                        // printf("Basic Third Party: %.2f\n", basicThirdParty);
                        // printf("Advanced Third Party: %.2f\n", advancedThirdParty);
                        // printf("Total Risk With Deductible: %.2f\n", totalRiskWithDeductible);
                        // printf("Total Risk Without Deductible: %.2f\n", totalRiskWithoutDeductible);
                    }
                    correctInput = 1;
                    break;

                default:
                    attempt++;
                    break;
                }
            }
            else
            {
                while (getchar() != '\n');
            }
        }

        // display
        float basicThirdPartyMonth = basicThirdPartyBase * 1.06;
        float advancedThirdPartyMonth = advancedThirdPartyBase * 1.06;
        float totalRiskWithDeductibleMonth = totalRiskWithDeductibleBase * 1.06;
        float totalRiskWithoutDeductibleMonth = totalRiskWithoutDeductibleBase;

        float basicThirdPartyTrimestral = basicThirdPartyBase * 1.04;
        float advancedThirdPartyTrimestral = advancedThirdPartyBase * 1.04;
        float totalRiskWithDeductibleTrimestral = totalRiskWithDeductibleBase * 1.04;
        float totalRiskWithoutDeductibleTrimestral = totalRiskWithoutDeductibleBase;

        float basicThirdPartySemestral = basicThirdPartyBase * 1.02;
        float advancedThirdPartySemestral = advancedThirdPartyBase * 1.02;
        float totalRiskWithDeductibleSemestral = totalRiskWithDeductibleBase * 1.02;
        float totalRiskWithoutDeductibleSemestral = totalRiskWithoutDeductibleBase;

        float basicThirdPartyYear = basicThirdPartyBase;
        float advancedThirdPartyYear = advancedThirdPartyBase;
        float totalRiskWithDeductibleYear = totalRiskWithDeductibleBase;
        float totalRiskWithoutDeductibleYear = totalRiskWithoutDeductibleBase;

        printf("----------------------------------------------------------------------------------------------------------------\n");

        if (lowerInputUser == 'c')
        {
            // COCHE
            printf("| %-13s | %-13s | %-15s | %-28s | %-22s |\n",
                   "Fraccionament", "Tercers bàsic", "Tercers avançat",
                   "Tot risc amb franquícia (200€)", "Tot risc sense franquícia");
            printf("----------------------------------------------------------------------------------------------------------------\n");

            printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
                   "MENSUAL", basicThirdPartyMonth, advancedThirdPartyMonth,
                   totalRiskWithDeductibleMonth, totalRiskWithoutDeductibleMonth);
            printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
                   "TRIMESTRAL", basicThirdPartyTrimestral, advancedThirdPartyTrimestral,
                   totalRiskWithDeductibleTrimestral, totalRiskWithoutDeductibleTrimestral);
            printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
                   "SEMESTRAL", basicThirdPartySemestral, advancedThirdPartySemestral,
                   totalRiskWithDeductibleSemestral, totalRiskWithoutDeductibleSemestral);
            printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
                   "ANUAL", basicThirdPartyYear, advancedThirdPartyYear,
                   totalRiskWithDeductibleYear, totalRiskWithoutDeductibleYear);
        }
        else
        {
            // MOTO 
            printf("| %-13s | %-13s | %-15s |\n",
                   "Fraccionament", "Tercers bàsic", "Tercers avançat");
            printf("---------------------------------------------------------------\n");

            printf("| %-13s | %13.2f € | %15.2f € |\n",
                   "MENSUAL", basicThirdPartyMonth, advancedThirdPartyMonth);
            printf("| %-13s | %13.2f € | %15.2f € |\n",
                   "TRIMESTRAL", basicThirdPartyTrimestral, advancedThirdPartyTrimestral);
            printf("| %-13s | %13.2f € | %15.2f € |\n",
                   "SEMESTRAL", basicThirdPartySemestral, advancedThirdPartySemestral);
            printf("| %-13s | %13.2f € | %15.2f € |\n",
                   "ANUAL", basicThirdPartyYear, advancedThirdPartyYear);
        }

        printf("----------------------------------------------------------------------------------------------------------------\n");

        // Reset
        char inputUser2, lowerInputUser2;
        correctInput = 0;
        attempt = 0;

        while (!correctInput)
        {
            if (attempt == 0)
            {
                printf("Vols calcula el preu per un altre vehicle (S)í o (N)o? Prem S o N: ");
            }
            else
            {
                printf("Prem S o N: ");
            }

            if (scanf(" %c", &inputUser))
            {
                lowerInputUser = tolower(inputUser);
                if (lowerInputUser == 's' || lowerInputUser == 'n')
                {
                    if (lowerInputUser == 'n')
                    {
                        printf("Moltes gràcies per utilitzar el nostre tarificador. Fins la pròxima! Assegurances SafeCar");
                        correctInput = 1;
                        reset = 1;
                    }

                    correctInput = 1;
                }
                else
                {
                    attempt++;
                }
            }
            else
            {
                while (getchar() != '\n')
                    ;
            }
        }
    }
}