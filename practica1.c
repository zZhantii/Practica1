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

bool reset()
{
    char resetInput;
    bool done = false;
    bool shouldReset = false;

    do
    {
        printf("Vols calcular el preu per un altre vehicle (S)í o (N)o? Prem S o N: ");
        scanf(" %c", &resetInput);
        resetInput = tolower((unsigned char)resetInput);

        if (resetInput == 's' || resetInput == 'n')
        {
            done = true;
            shouldReset = (resetInput == 's');

            if (!shouldReset)
            {
                printf("\n╔═══════════════════════════════════════════════════╗\n");
                printf("║  Gràcies per utilitzar el nostre tarificador!     ║\n");
                printf("║         Fins la pròxima! - SafeCar                ║\n");
                printf("╚═══════════════════════════════════════════════════╝\n");
            }
        }
        else
        {
            printf("Prem S o N: ");
        }
    } while (!done);

    return shouldReset;
}

bool validatedInt(int value, int min, int max)
{
    return value >= min && value <= max;
}

bool validatedChar(char value, const char *validatedOptions)
{
    value = tolower((unsigned char)value);
    return strchr(validatedOptions, value) != NULL;
}

void menus(int type, char vehicleType)
{
    switch (type)
    {
    // EngineType
    case 3:
        printf("┌──────────────────────────────────┐\n");
        printf("│          Tipus de motor          │\n");
        printf("├──────────────────────────────────┤\n");
        printf("│ 1 - Combustió (diesel/gasolina)  │\n");
        printf("│ 2 - Híbrid                       │\n");
        printf("│ 3 - Elèctric                     │\n");
        printf("└──────────────────────────────────┘\n");
        printf("Escull la opció (1-3): ");
        break;
    // Uso
    case 5:
        printf("┌──────────────────────────────────┐\n");
        printf("│              Ús                  │\n");
        printf("├──────────────────────────────────┤\n");
        printf("│ 1 - Particular                   │\n");
        printf("│ 2 - Lloguer                      │\n");
        printf("│ 3 - Taxi                         │\n");
        printf("└──────────────────────────────────┘\n");
        printf("Escull la opció (1-3): ");
        break;
    // Engine capacity
    case 6:
        if (vehicleType == 'c')
        {
            printf("┌──────────────────────────────────┐\n");
            printf("│         Cilindrada Cotxe         │\n");
            printf("├──────────────────────────────────┤\n");
            printf("│ 1 - ≤ 1.000cc                    │\n");
            printf("│ 2 - 1.000cc - 2.000cc            │\n");
            printf("│ 3 - > 2.000cc                    │\n");
            printf("└──────────────────────────────────┘\n");
            printf("Escull la opció (1-3): ");
        }
        else
        {
            printf("┌──────────────────────────────────┐\n");
            printf("│          Cilindrada Moto         │\n");
            printf("├──────────────────────────────────┤\n");
            printf("│ 1 - ≤ 125cc                      │\n");
            printf("│ 2 - 126cc - 500cc                │\n");
            printf("│ 3 - 501cc - 1.000cc              │\n");
            printf("│ 4 - > 1.000cc                    │\n");
            printf("└──────────────────────────────────┘\n");
            printf("Escull la opció (1-4): ");
        }
        break;

    default:
        break;
    }
}

void getValidatedInput(int type, void *value, const char *validatedOptions, char vehicleType)
{
    bool done = false;
    char *charValue;
    int *intValue;

    do
    {
        switch (type)
        {
        case 1: // VehicleType
            if (!done)
            {
                printf("Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
            }
            charValue = (char *)value;
            if (scanf(" %c", charValue) == 1)
            {
                *charValue = tolower((unsigned char)*charValue);
                if (validatedChar(*charValue, validatedOptions))
                {
                    done = true;
                }
                else
                {
                    printf("Prem C o M: \n");
                }
            }
            break;

        case 2: // Age
            if (!done)
            {
                printf("Edat conductor (18-80): ");
            }
            intValue = (int *)value;
            if (scanf("%d", intValue) == 1)
            {
                if (validatedInt(*intValue, 18, 80))
                {
                    done = true;
                }
                else
                {
                    printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni majors de 80: \n");
                }
            }
            else
            {
                printf("Error: Has d'introduir un número: \n");
            }
            break;

        case 3: // EngineType
            if (!done)
            {
                menus(type, vehicleType);
            }
            intValue = (int *)value;
            if (scanf("%d", intValue) == 1)
            {
                if (validatedInt(*intValue, 1, 3))
                {
                    done = true;
                }
                else
                {
                    printf("Opció no vàlida. Escull entre 1 i 3: \n");
                }
            }
            else
            {
                printf("Error: Has d'introduir un número: \n");
            }
            break;

        case 4: // Year Manufacture
            if (!done)
            {
                printf("Any de fabricació del vehicle (1970-2025): ");
            }
            intValue = (int *)value;
            if (scanf("%d", intValue) == 1)
            {
                if (validatedInt(*intValue, 1970, CURRENT_YEAR))
                {
                    done = true;
                }
                else
                {
                    printf("Any no vàlid. Ha d'estar entre 1970 i %d: \n", CURRENT_YEAR);
                }
            }
            else
            {
                printf("Error: Has d'introduir un número: \n");
            }
            break;

        case 5: // Us (solo para coches)
            if (!done)
            {
                menus(type, vehicleType);
            }
            intValue = (int *)value;
            if (scanf("%d", intValue) == 1)
            {
                if (validatedInt(*intValue, 1, 3))
                {
                    done = true;
                }
                else
                {
                    printf("Opció no vàlida. Escull entre 1 i 3: \n");
                }
            }
            else
            {
                printf("Error: Has d'introduir un número: \n");
            }
            break;

        case 6: // EngineCapacity
            if (!done)
            {
                menus(type, vehicleType);
            }
            intValue = (int *)value;
            if (scanf("%d", intValue) == 1)
            {
                if (vehicleType == 'c')
                {
                    if (validatedInt(*intValue, 1, 3))
                    {
                        done = true;
                    }
                    else
                    {
                        printf("Opció no vàlida. Escull entre 1 i 3: \n");
                    }
                }
                else if (vehicleType == 'm')
                {
                    if (validatedInt(*intValue, 1, 4))
                    {
                        done = true;
                    }
                    else
                    {
                        printf("Error: Opció no vàlida. Escull entre 1 i 4: \n");
                    }
                }
            }
            else
            {
                printf("Error: Has d'introduir un número: \n");
            }
            break;
        }

        while (getchar() != '\n')
            ; // Limpiar buffer

    } while (!done);
}

void applyAgeModifier(float *prices, int age)
{
    if (age >= 18 && age <= 24)
    {
        *prices *= 1.7f;
    }
    else if (age >= 25 && age <= 29)
    {
        *prices *= 1.3f;
    }
    else if (age >= 30 && age <= 39)
    {
        *prices *= 1.1f;
    }
    else if (age >= 60 && age <= 80)
    {
        *prices *= 1.2f;
    }
}

void applyEngineTypeModifier(float *prices, int engineType)
{
    if (engineType == 2)
    { 
        *prices *= 0.9f;
    }
    else if (engineType == 3)
    { 
        *prices *= 0.8f;
    }
}

void applyYearModifier(float *prices, bool *showAllRisks, int manufactureYear)
{
    int vehicleAge = CURRENT_YEAR - manufactureYear;
    if (vehicleAge > 10)
    {
        *showAllRisks = false;
        *prices *= 1.1f;
    }
}

void applyUseModifier(float *prices, int uso)
{
    if (uso == 2)
    { 
        *prices *= 1.05f;
    }
    else if (uso == 3)
    { 
        *prices *= 1.1f;
    }
}

void applyEngineCapacityModifier(float *prices, int vehicleType, int EngineCapacity)
{
    if (vehicleType == 'c')
    {
        if (EngineCapacity == 2)
        {
            *prices *= 1.1f;
        }
        else if (EngineCapacity == 3)
        {
            *prices *= 1.2f;
        }
    }
    else
    {
        if (EngineCapacity == 2)
        {
            *prices *= 1.1f;
        }
        else if (EngineCapacity == 3)
        {
            *prices *= 1.15f;
        }
        else if (EngineCapacity == 4)
        {
            *prices *= 1.3f;
        }
    }
}

void displayPrices(float basic, float advanced, float riskWithDed,
                   float riskWithoutDed, bool showAllRisks, char vehicleType)
{
    float monthlyMod = 1.06f;
    float quarterlyMod = 1.04f;
    float semiannualMod = 1.02f;
    float annualMod = 1.00f;

    printf("\nEls preus de l'assegurança pel teu %s són els següents:\n",
           vehicleType == 'c' ? "cotxe" : "moto");

    if (vehicleType == 'c' && showAllRisks)
    {
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("| %-13s | %-13s | %-15s | %-28s | %-22s |\n",
               "Fraccionament", "Tercers bàsic", "Tercers avançat",
               "Tot risc amb franquícia (200€)", "Tot risc sense franquícia");
        printf("----------------------------------------------------------------------------------------------------------------\n");

        printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
               "MENSUAL", basic * monthlyMod, advanced * monthlyMod,
               riskWithDed * monthlyMod, riskWithoutDed * monthlyMod);

        printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
               "TRIMESTRAL", basic * quarterlyMod, advanced * quarterlyMod,
               riskWithDed * quarterlyMod, riskWithoutDed * quarterlyMod);

        printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
               "SEMESTRAL", basic * semiannualMod, advanced * semiannualMod,
               riskWithDed * semiannualMod, riskWithoutDed * semiannualMod);

        printf("| %-13s | %13.2f € | %15.2f € | %28.2f € | %22.2f € |\n",
               "ANUAL", basic * annualMod, advanced * annualMod,
               riskWithDed * annualMod, riskWithoutDed * annualMod);
        printf("----------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("---------------------------------------------------\n");
        printf("| %-13s | %-13s | %-15s |\n",
               "Fraccionament", "Tercers bàsic", "Tercers avançat");
        printf("---------------------------------------------------\n");

        printf("| %-13s | %13.2f € | %15.2f € |\n",
               "MENSUAL", basic * monthlyMod, advanced * monthlyMod);

        printf("| %-13s | %13.2f € | %15.2f € |\n",
               "TRIMESTRAL", basic * quarterlyMod, advanced * quarterlyMod);

        printf("| %-13s | %13.2f € | %15.2f € |\n",
               "SEMESTRAL", basic * semiannualMod, advanced * semiannualMod);

        printf("| %-13s | %13.2f € | %15.2f € |\n",
               "ANUAL", basic * annualMod, advanced * annualMod);
        printf("---------------------------------------------------\n");
    }

    if (!showAllRisks)
    {
        printf("* No assegurem a tot risc vehicles de més de 10 anys.\n");
    }
}

int main()
{
    bool continueProgram = true;

    char vehicleType;
    int age;
    int engineType;
    int manufactureYear;
    int uso;
    int EngineCapacity;
    const char *validateOptions = "cm";

    float basicThirdParty;
    float advancedThirdParty;
    float riskWithDeductible;
    float riskWithoutDeductible;

    bool showAllRisks = true;

    printf("\n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("║     TARIFICADOR ASSEGURANCES SAFECAR     ║\n");
    printf("║            Benvinguts/des!               ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    while (continueProgram)
    {
        // VehicleType
        // printf("Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
        getValidatedInput(1, &vehicleType, validateOptions, '\0');

        if (vehicleType == 'c')
        {
            basicThirdParty = 200.0f;
            advancedThirdParty = 230.0f;
            riskWithDeductible = 330.0f;
            riskWithoutDeductible = 400.0f;
        }
        else
        {
            basicThirdParty = 100.0f;
            advancedThirdParty = 120.0f;
            riskWithDeductible = 200.0f;
            riskWithoutDeductible = 300.0f;
        }

        // Age
        // printf("Edat conductor (18-80): ");
        getValidatedInput(2, &age, NULL, vehicleType);

        applyAgeModifier(&basicThirdParty, age);
        applyAgeModifier(&advancedThirdParty, age);
        applyAgeModifier(&riskWithDeductible, age);
        applyAgeModifier(&riskWithoutDeductible, age);

        // EngineType
        getValidatedInput(3, &engineType, NULL, vehicleType);

        applyEngineTypeModifier(&basicThirdParty, engineType);
        applyEngineTypeModifier(&advancedThirdParty, engineType);
        applyEngineTypeModifier(&riskWithDeductible, engineType);
        applyEngineTypeModifier(&riskWithoutDeductible, engineType);

        // Year manufacture
        // printf("Any de fabricació del vehicle (1970-2025): ");
        getValidatedInput(4, &manufactureYear, NULL, vehicleType);

        applyYearModifier(&basicThirdParty, &showAllRisks, manufactureYear);
        applyYearModifier(&advancedThirdParty, &showAllRisks, manufactureYear);
        applyYearModifier(&riskWithDeductible, &showAllRisks, manufactureYear);
        applyYearModifier(&riskWithoutDeductible, &showAllRisks, manufactureYear);

        // Uso
        if (vehicleType == 'c')
        {
            getValidatedInput(5, &uso, NULL, vehicleType);
            applyUseModifier(&basicThirdParty, uso);
            applyUseModifier(&advancedThirdParty, uso);
            applyUseModifier(&riskWithDeductible, uso);
            applyUseModifier(&riskWithoutDeductible, uso);
        }

        // Engine capacity
        getValidatedInput(6, &EngineCapacity, NULL, vehicleType);

        applyEngineCapacityModifier(&basicThirdParty, vehicleType, EngineCapacity);
        applyEngineCapacityModifier(&advancedThirdParty, vehicleType, EngineCapacity);
        applyEngineCapacityModifier(&riskWithDeductible, vehicleType, EngineCapacity);
        applyEngineCapacityModifier(&riskWithoutDeductible, vehicleType, EngineCapacity);

        displayPrices(basicThirdParty, advancedThirdParty,
                      riskWithDeductible, riskWithoutDeductible,
                      showAllRisks, vehicleType);

        continueProgram = reset();

        if (continueProgram)
        {
            vehicleType = '\0';
            age = 0;
            engineType = 0;
            manufactureYear = 0;
            uso = 0;
            EngineCapacity = 0;
        }
    }
}