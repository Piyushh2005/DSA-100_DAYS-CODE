#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);

    if (pos < 1 || pos > n + 1) {
        free(arr);
        return 0;
    }

    int idx = pos - 1;

    for (int i = n; i > idx; i--) {
        arr[i] = arr[i - 1];
    }

    arr[idx] = x;
    n++;

    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", arr[i]);
    }

    printf("\n");

    free(arr);
    return 0;
}