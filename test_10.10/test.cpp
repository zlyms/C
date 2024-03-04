#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
// ¸´ÖÆ²¿·Ö×Ö·û´®
int main() {

    char str[30] = { 0 };
    cin.getline(str, sizeof(str));

    int m;
    cin >> m;
    int i, j;
    char str2[30] = { 0 };
    char* p = str2;
    int len = strlen(str);
    // write your code here......
    for (i = m - 1; i < len; i++)
    {
        *p = str[i];
        p++;

    }
    for (j = 0; j < m; j++)
    {
        printf("%c", str2[j]);
    }

    return 0;
}

#include <iostream>
using namespace std;

// write your code here......


//int main() {
//
//    int m, n;
//    cin >> m;
//    cin >> n;
//    int* p1 = &n;
//    int tem = n;
//    int* p2 = &m;
//    *p1 = *p2;
//    *p2 = tem;
//
//
//
//    // write your code here......
//
//
//    cout << m << " " << n << endl;
//
//    return 0;
//}