// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main() {
    // basicIO();
    // Your cpp code here
    int numOfCases;
    long long int vec[10002];
    scanf("%d", &numOfCases);

    for (int caseNo = 1; caseNo<=numOfCases; caseNo++) {
        long long int a, b, c, d, e, f, n;
        scanf("%lld %lld %lld %lld %lld %lld %lld ", &a, &b, &c, &d, &e, &f, &n);
        
        for(long long int i = 0; i<=n; i++) {
            if(i==0) 
                vec[i] = a;
            else if(i==1) 
                vec[i] = b;
            else if(i==2) 
                vec[i] = c;
            else if(i==3) 
                vec[i] = d;
            else if(i==4) 
                vec[i] = e;
            else if(i==5) 
                vec[i] = f;
            else 
                vec[i] = vec[i-1] + vec[i-2] + vec[i-3] + vec[i-4] + vec[i-5] + vec[i-6];
            
            vec[i] = vec[i] % 10000007;
            
        }
        printf("Case %d: %lld\n", caseNo, vec[n]);
    }
    return 0;
}

// int subset(int arr[], int n)
// {
//   int sum = 0;
//   for(int i=0; i<n; i++) {
//     sum += arr[i];
//   }
//   int halfsum = sum / 2;
  
//   vector<vector<bool>> table(n+1, vector<bool>(halfsum+1, false));
  
//   for(int i=0; i<=n; i++) {
//     table[i][0] = true;
//   }
//   for(int i=1; i<=halfsum; i++) {
//     table[0][i] = false;
//   }
  
//   for(int i=1; i<=n; i++) {
//     for(int j=1; j<=halfsum; j++) {
//       if(arr[i-1]<=j) {
//         table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
//       } else{
//         table[i][j] = table[i-1][j];
//       }
//     }
//   }
//   int s1=0, s2=0;
//   for(int j=halfsum; j>=0; j--) {
//     if(table[n][j]){
//       s1=j;
//       break;
//     }
//   }
//   s2 = sum - s1;
//   return max(s1,s2);
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     int arr[2];
//     for(int i = 0; i<n; i++) {
//       scanf("%d", &arr[i]);
//     }
//     printf("%d\n", subset(arr,n));
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int remove_duplicates(int *arr, int size_of_the_array)
// {
//     if (size_of_the_array == 0) {
//         printf("The array is empty\n");
//         return 0;
//     }
//     else if (size_of_the_array == 1) {
//         printf("There can't be duplicates\n");
//         return size_of_the_array;
//     }

//     int current_index = 1;
//     for (int i = 1; i < size_of_the_array; i++) {
//         if (arr[i - 1] != arr[i]) {
//             arr[current_index] = arr[i];
//             current_index++;
//         }
//     }
//     cout << "total elements: " << current_index << "\n";
//     return current_index;
// }

// int main(int argc, char const *argv[])
// {
//     int size_of_array;
//     // int arr[10] = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
//     int arr[1] = {1};
//     size_of_array = sizeof(arr);
//     size_of_array = size_of_array / 4;
//     size_of_array = remove_duplicates(arr, size_of_array);
//     if (size_of_array != 0) {
//         cout << "Printing array: ";
//         for (int i = 0; i < size_of_array; i++) {
//             cout << arr[i] << " ";
//         }
//     }

//     return 0;
// }
