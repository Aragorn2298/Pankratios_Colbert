
#include<stdlib.h>
#include<stdio.h>

/*El Tiempo de ejecucion del Merge Sort es \Theta(nLogn) en los 3 casos que serian
 * (peor, medio y el mejor) como el merge sort siempre divide los arreglos por mitad y siempre toma un tiempo lineal para
 * hacer merge las dos mitades*/


void unir(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // Crear Arreglos temporales
    int izq[n1], der[n2];

    // Copiar datos a los arreglos temporales
    for (i = 0; i < n1; i++)
        izq[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        der[j] = arr[m + 1+ j];

    // Unir los arreglos temporales en orden arr[l...r]
    i = 0; // indice inicial del primer subarr
    j = 0; // indice inicial del segundo subarr
    k = l; // indice inicial del arreglo unido
    while (i < n1 && j < n2)
    {
        if (izq[i] <= der[j])
        {
            arr[k] = izq[i];
            i++;
        }
        else
        {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    /* Copiar los elementos restantes izq[], */
    while (i < n1)
    {
        arr[k] = izq[i];
        i++;
        k++;
    }

    /* Copiar los elementos restantes de der[]*/
    while (j < n2)
    {
        arr[k] = der[j];
        j++;
        k++;
    }
}

/* l es para el indice izq y r es para el indice der del arr que sera ordenado*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        // ordenar primera y segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        unir(arr, l, m, r);
    }
}

void impArr(int *A, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main()
{
    int arr[] = {13,56,21,12,5,8};
    int tamarr = sizeof(arr)/sizeof(arr[0]);

    printf("Arreglo dado: \n");
    impArr(arr, tamarr);

    mergeSort(arr, 0, tamarr - 1);

    printf("\nArreglo ordenado: \n");
    impArr(arr, tamarr);
    return 0;
}