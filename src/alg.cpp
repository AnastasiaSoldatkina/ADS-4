// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int Z = 0;
    for (int i = 0; i < len; i++) {
        for (int a = len - 1; a > i; a--) {
            if (arr[i] + arr[a] == value) {
                Z++;
            }
        }
    }
    return Z;
}
int countPairs2(int *arr, int len, int value) {
    int i = 0;
    int w = 0;
    int G = 0;
    while (i < len) {
        w = i+1;
        while (w < len) {
            if (arr[i] + arr[w] == value) {
                G++;
            }
            w++;
        }
        i++;
    }
    return G;
}
int cbinsearch(int* arr, int size, int value) {
int i = 0;
    int j = size;
    int d = 0;
    int Res = 0;
    while (i < j) {
        int x = i + (j - i) / 2;
        if (i == j - 1) {
            break;
        }
        d = x;
        if (arr[x] == value) {
            while (arr[x] == value) {
                x++;
            }
            j = x;
            x = d;
            while (arr[x] == value) {
                x--;
            }
            i = x;
            Res = j - i - 1;
            break;
        }
        if (arr[x] < value) {
            i = x;
            x++;
        } else {
            j = x-1;
            x--;
        }
    }
    return Res;
}
int countPairs3(int *arr, int len, int value) {
int c = 0;
    int Con = 0;
    int min = 0;
    while (arr[c] < value - arr[c]) {
        min = value - arr[c];
        Con = Con + cbinsearch(arr, len, min);
        c++;
    }
    if (value % 2 == 0) {
        min = value/2;
        int r = cbinsearch(arr, len, min) - 1;
        while (r > 0) {
            Con = Con + r;
            r--;
        }
    }
    return Con;
}
