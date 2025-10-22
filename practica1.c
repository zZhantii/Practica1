#include <stdio.h>

#define CURRENT_YEAR 2025

float edadConductor(int edad) {
  if (edad >= 18 && edad <= 24) {
    return 0.70f;
  } else if (edad >= 25 && edad <= 29) {
    return 0.30f;
  } else if (edad >= 30 && edad <= 39) {
    return 0.10f;
  } else if (edad >= 40 && edad <= 59) {
    return 0.0f;
  } else if (edad >= 60 && edad <= 80) {
    return 0.20f;
  }
}

float tipoMotor(int opcion) {
  switch (opcion) {
  case 1:
    return 0.0f;
    break;

  case 2:
    return 0.10f;
    break;

  case 3:
    return 0.20f;
    break;

  default:
    return 0.0f;
    break;
  }
}

float usoVehiculo(int opcion) {
  switch (opcion) {
  case 1:
    return 0.0f;
    break;

  case 2:
    return 0.05f;
    break;

  case 3:
    return 0.1f;
    break;

  default:
    return 0.0f;
    break;
  }
}

float cilindradaVehiculo(int opcion, char tipo) {
  if (tipo == 'm' || tipo == 'M') {
    switch (opcion) {
    case 1:
      return 0.0f;
      break;

    case 2:
      return 0.10f;
      break;

    case 3:
      return 0.15f;
      break;

    case 4:
      return 0.3f;
      break;

    default:
      return 0.0f;
      break;
    }
  } else {
    switch (opcion) {
    case 1:
      return 0.0f;
      break;

    case 2:
      return 0.10f;
      break;

    case 3:
      return 0.20f;
      break;

    default:
      return 0.0f;
      break;
    }
  }
}

int main(void) {
  float tercerosbasicos = 0.0f;
  float tercerosAvanzados = 0.0f;
  float todoRiesgoConFranquicia = 0.0f;
  float todoRiesgoSinFranquicia = 0.0f;

  float porcentajeTotal = 1.0f;

  int intValue = 0;
  char charValue = ' ';

  int reset = 0;
  int hecho = 0;

  do {
    porcentajeTotal = 1.0f;
    hecho = 0;

    // Primer opcion
    printf("- Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");

    while (!hecho) {
      if (scanf(" %c", &charValue) == 1) {
        if (getchar() != '\n') {
          while (getchar() != '\n')
            ;
          printf("Només un caràcter. Prem C o M: ");
          continue;
        }

        if (charValue == 'c' || charValue == 'C' || charValue == 'm' ||
            charValue == 'M') {
          if (charValue == 'm' || charValue == 'M') {
            tercerosbasicos = 100.0f;
            tercerosAvanzados = 120.0f;
            todoRiesgoConFranquicia = 200.0f;
            todoRiesgoSinFranquicia = 300.0f;
          } else {
            tercerosbasicos = 200.0f;
            tercerosAvanzados = 230.0f;
            todoRiesgoConFranquicia = 330.0f;
            todoRiesgoSinFranquicia = 400.0f;
          }

          hecho = 1;
        } else {
          printf("Prem C o M: ");
          while (getchar() != '\n')
            ;
        }
      }
    }

    // Edad Conductor
    hecho = 0;

    printf("- Edat conductor (18-80): ");

    while (!hecho) {
      scanf("%d", &intValue);
      if (intValue >= 18 && intValue <= 80) {
        printf("porcentaje %f \n", porcentajeTotal);
        porcentajeTotal += edadConductor(intValue);
        printf("porcentaje %f \n", porcentajeTotal);
        hecho = 1;
      } else {
        printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni "
               "majors de 80: ");
        while (getchar() != '\n')
          ;
      }
    }

    // Motor
    hecho = 0;

    printf("┌──────────────────────────────────┐\n");
    printf("│          Tipus de motor          │\n");
    printf("├──────────────────────────────────┤\n");
    printf("│ 1 - Combustió (diesel/gasolina)  │\n");
    printf("│ 2 - Híbrid                       │\n");
    printf("│ 3 - Elèctric                     │\n");
    printf("└──────────────────────────────────┘\n");
    printf("Escull la opció (1-3): ");

    while (!hecho) {
      scanf("%d", &intValue);
      if (intValue >= 1 && intValue <= 3) {
        printf("porcentaje %f \n", porcentajeTotal);
        porcentajeTotal -= tipoMotor(intValue);
        printf("porcentaje %f \n", porcentajeTotal);
        hecho = 1;
      } else {
        printf("Escull la opció 1, 2 o 3: ");
        while (getchar() != '\n')
          ;
      }
    }

    // Año fabricación
    hecho = 0;
    int anyoFabricacion = 0;
    int esVehiculoAntiguo = 0;

    printf("- Any de fabricació del vehicle (1970-2025): ");

    while (!hecho) {
      scanf("%d", &intValue);
      if (intValue >= 1970 && intValue <= CURRENT_YEAR) {
        anyoFabricacion = intValue;

        if ((CURRENT_YEAR - intValue) > 10) {
          printf("porcentaje %f \n", porcentajeTotal);
          porcentajeTotal += 0.10f;
          printf("porcentaje %f \n", porcentajeTotal);
          esVehiculoAntiguo = 1;
        }

        hecho = 1;
      } else {
        printf("Introdueix un any entre 1970 i 2025: ");
        while (getchar() != '\n')
          ;
      }
    }

    // Uso
    if (charValue == 'c' || charValue == 'C') {
      hecho = 0;

      printf("┌──────────────────────────────────┐\n");
      printf("│              Ús                  │\n");
      printf("├──────────────────────────────────┤\n");
      printf("│ 1 - Particular                   │\n");
      printf("│ 2 - Lloguer                      │\n");
      printf("│ 3 - Taxi                         │\n");
      printf("└──────────────────────────────────┘\n");
      printf("Escull la opció (1-3): ");

      while (!hecho) {
        scanf("%d", &intValue);
        if (intValue >= 1 && intValue <= 3) {
          printf("porcentaje %f \n", porcentajeTotal);
          porcentajeTotal += usoVehiculo(intValue);
          printf("porcentaje %f \n", porcentajeTotal);
          hecho = 1;
        } else {
          printf("Escull la opció 1, 2 o 3: ");
          while (getchar() != '\n')
            ;
        }
      }
    }

    // Cilindrada
    hecho = 0;

    if (charValue == 'm' || charValue == 'M') {
      printf("┌──────────────────────────────────┐\n");
      printf("│          Cilindrada Moto         │\n");
      printf("├──────────────────────────────────┤\n");
      printf("│ 1 - ≤ 125cc                      │\n");
      printf("│ 2 - 126cc - 500cc                │\n");
      printf("│ 3 - 501cc - 1.000cc              │\n");
      printf("│ 4 - > 1.000cc                    │\n");
      printf("└──────────────────────────────────┘\n");
      printf("Escull la opció (1-4): ");

      while (!hecho) {
        scanf("%d", &intValue);
        if (intValue >= 1 && intValue <= 4) {
          printf("porcentaje %f \n", porcentajeTotal);
          porcentajeTotal += cilindradaVehiculo(intValue, charValue);
          printf("porcentaje %f \n", porcentajeTotal);
          hecho = 1;
        } else {
          printf("Escull la opció 1, 2, 3 o 4: ");
          while (getchar() != '\n')
            ;
        }
      }
    } else {
      printf("┌──────────────────────────────────┐\n");
      printf("│         Cilindrada Cotxe         │\n");
      printf("├──────────────────────────────────┤\n");
      printf("│ 1 - ≤ 1.000cc                    │\n");
      printf("│ 2 - 1.000cc - 2.000cc            │\n");
      printf("│ 3 - > 2.000cc                    │\n");
      printf("└──────────────────────────────────┘\n");
      printf("Escull la opció (1-3): ");

      while (!hecho) {
        scanf("%d", &intValue);
        if (intValue >= 1 && intValue <= 3) {
          printf("porcentaje %f \n", porcentajeTotal);
          porcentajeTotal += cilindradaVehiculo(intValue, charValue);
          printf("porcentaje %f \n", porcentajeTotal);
          hecho = 1;
        } else {
          printf("Escull la opció 1, 2 o 3: ");
          while (getchar() != '\n')
            ;
        }
      }
    }

    if (charValue == 'c' || charValue == 'C') {
      if (esVehiculoAntiguo) {

        printf("\n-------------------------------------------------------------"
               "-------\n");
        printf("| Fraccionament | Tercers bàsic | Tercers avançat |\n");
        printf("---------------------------------------------------------------"
               "-----\n");
        printf("| MENSUAL      | %11.2f€ | %13.2f€ |\n",
               (tercerosbasicos * porcentajeTotal) * 1.06,
               (tercerosAvanzados * porcentajeTotal) * 1.06);
        printf("| TRIMESTRAL   | %11.2f€ | %13.2f€ |\n",
               (tercerosbasicos * porcentajeTotal) * 1.04,
               (tercerosAvanzados * porcentajeTotal) * 1.04);
        printf("| SEMESTRAL    | %11.2f€ | %13.2f€ |\n",
               (tercerosbasicos * porcentajeTotal) * 1.02,
               (tercerosAvanzados * porcentajeTotal) * 1.02);
        printf("| ANUAL        | %11.2f€ | %13.2f€ |\n",
               (tercerosbasicos * porcentajeTotal),
               (tercerosAvanzados * porcentajeTotal));
        printf("---------------------------------------------------------------"
               "-----\n");
        printf("NOTA: Els vehicles de més de 10 anys no poden contractar tot "
               "risc.\n");
      } else {
        // Para vehículos nuevos: mostrar todas las opciones
        printf("\n-------------------------------------------------------------"
               "---------------------------------------------------\n");
        printf("| Fraccionament | Tercers bàsic | Tercers avançat | Tot risc "
               "amb franquícia (200€) | Tot risc sense franquícia |\n");
        printf("---------------------------------------------------------------"
               "-------------------------------------------------\n");
        printf("| MENSUAL      | %11.2f€ | %13.2f€ | %27.2f€ | %23.2f€ |\n",
               (tercerosbasicos * porcentajeTotal) * 1.06,
               (tercerosAvanzados * porcentajeTotal) * 1.06,
               (todoRiesgoConFranquicia * porcentajeTotal) * 1.06,
               (todoRiesgoSinFranquicia * porcentajeTotal) * 1.06);
        printf("| TRIMESTRAL   | %11.2f€ | %13.2f€ | %27.2f€ | %23.2f€ |\n",
               (tercerosbasicos * porcentajeTotal) * 1.04,
               (tercerosAvanzados * porcentajeTotal) * 1.04,
               (todoRiesgoConFranquicia * porcentajeTotal) * 1.04,
               (todoRiesgoSinFranquicia * porcentajeTotal) * 1.04);
        printf("| SEMESTRAL    | %11.2f€ | %13.2f€ | %27.2f€ | %23.2f€ |\n",
               (tercerosbasicos * porcentajeTotal) * 1.02,
               (tercerosAvanzados * porcentajeTotal) * 1.02,
               (todoRiesgoConFranquicia * porcentajeTotal) * 1.02,
               (todoRiesgoSinFranquicia * porcentajeTotal) * 1.02);
        printf("| ANUAL        | %11.2f€ | %13.2f€ | %27.2f€ | %23.2f€ |\n",
               (tercerosbasicos * porcentajeTotal),
               (tercerosAvanzados * porcentajeTotal),
               (todoRiesgoConFranquicia * porcentajeTotal),
               (todoRiesgoSinFranquicia * porcentajeTotal));
        printf("---------------------------------------------------------------"
               "-------------------------------------------------\n");
      }
    } else {
      printf("\n------------------------------------------------\n");
      printf("| Fraccionament | Tercers bàsic | Tercers avançat |\n");
      printf("------------------------------------------------\n");
      printf("| MENSUAL      | %11.2f€ | %13.2f€ |\n",
             (tercerosbasicos * porcentajeTotal) * 1.06,
             (tercerosAvanzados * porcentajeTotal) * 1.06);
      printf("| TRIMESTRAL   | %11.2f€ | %13.2f€ |\n",
             (tercerosbasicos * porcentajeTotal) * 1.04,
             (tercerosAvanzados * porcentajeTotal) * 1.04);
      printf("| SEMESTRAL    | %11.2f€ | %13.2f€ |\n",
             (tercerosbasicos * porcentajeTotal) * 1.02,
             (tercerosAvanzados * porcentajeTotal) * 1.02);
      printf("| ANUAL        | %11.2f€ | %13.2f€ |\n",
             tercerosbasicos * porcentajeTotal,
             tercerosAvanzados * porcentajeTotal);
      printf("------------------------------------------------\n");
    }

    // Reinicio
    printf("- Vols calcular el preu per un altre vehicle (S)í o (N)o? Prem S o "
           "N: ");

    hecho = 0;

    while (!hecho) {
      if (scanf(" %c", &charValue) == 1) {
        if (getchar() != '\n') {
          while (getchar() != '\n')
            ;
          printf("Només un caràcter. Prem S o N: ");
          continue;
        }

        if (charValue == 's' || charValue == 'S') {
          reset = 1;
          hecho = 1;
        } else if (charValue == 'n' || charValue == 'N') {
          reset = 0;
          hecho = 1;
        } else {
          printf("Prem S o N: ");
          while (getchar() != '\n')
            ;
        }
      }
    }

    if (reset == 0) {
      printf("\n╔═══════════════════════════════════════════════════╗\n");
      printf("║  Gràcies per utilitzar el nostre tarificador!     ║\n");
      printf("║         Fins la pròxima! - SafeCar                ║\n");
      printf("╚═══════════════════════════════════════════════════╝\n");
    }

  } while (reset == 1);
}
