// // // // #include <cstdio>
// // // // #include <cstdlib>
// // // // #include <ctime>
// // // // #include <string>

// // // // const int maxn = 1e5 + 8;

// // // // void wait(double t) {
// // // // 	const int p = CLOCKS_PER_SEC;
// // // // 	const int now = clock();
// // // // 	t *= p;
// // // // 	for (int i = now; i < now + t; i = clock());
// // // // }


// // // // int main() {
// // // // 	// while (true) {
// // // // 	// 	system("a.exe");
// // // // 	// 	wait(0.1);
// // // // 	// }
// // // // 	int n = 10;
// // // // 	scanf("%d", &n);
// // // // 	// printf("%d", system("a.exe 1 3"));
// // // // 	for (int i = 1; i <= n; i++) {
// // // // 		for (int j = 1; j <= n; j++) {
// // // // 			char s[100];
// // // // 			sprintf(s, "a.exe %d %d", i, j);
// // // // 			printf("%d\t", system(s));
// // // // 		}
// // // // 		putchar(10);
// // // // 	}
// // // // 	// f(f1(), f2());
// // // // 	// print("eqfihb", 199);
// // // // }

// // // #include <stdio.h>
// // // #include <errno.h>
// // // #include <stdlib.h>

// // // int main(void)
// // // {
// // //     // // parsing with error handling
// // //     // const char *p = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
// // //     // printf("Parsing '%s':\n", p);
// // //     // char *end;
// // //     // for (double f = strtod(p, &end); p != end; f = strtod(p, &end))
// // //     // {
// // //     //     printf("'%.*s' -> ", (int)(end-p), p);
// // //     //     p = end;
// // //     //     if (errno == ERANGE){
// // //     //         printf("range error, got ");
// // //     //         errno = 0;
// // //     //     }
// // //     //     printf("%f\n", f);
// // //     // }

// // //     // // parsing without error handling
// // //     // printf("\"  -0.0000000123junk\"  -->  %g\n", strtod("  -0.0000000123junk", NULL));
// // //     // printf("\"junk\"                 -->  %g\n", strtod("junk", NULL));
// // // 	char s[100], *end;
// // // 	scanf("%s", s);
// // // 	double x = strtod(s, &end);
// // // 	printf("%lf", x); 
// // // }

// // #include <cstdio>
// // #include <string>

// // const int maxn = 1e5 + 8;

// // struct Animal {
// //     std::string name;
// // };

// // struct Dog : Animal {
// //     int x;
// // } a;

// // int main() {
// //     a.x = 1;
// //     a.name = "";
// // }
 


// #include <bits/stdc++.h>
// using namespace std;

// //  next;
// // struct Node {
// //     int a[10];
// //     iterator begin() {
// //         return a;
// //     }

// //     iterator operator++() {
// //         return a + 1;
// //     }
// // } a;

// #include <type>
// int main() {
//     // a = {1, 2, 3, 5, 6, 8};
//     // auto x = a.a;
//     // next(x);
//     // cout << *x;
//     ull x = 1;
//     for (int i = 0; i < 18; i++) {
//         printf("%llu, ", x);
//         x *= 10; 
//         const ull x = 100000000000000000;
//     }
// }
// #include <BigInteger>
// #include <vector>


// int main() {
//     std::vector<int> a;
//     a=a;
// }
