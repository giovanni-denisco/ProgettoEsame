# 0 "/home/Giovanni/CLionProjects/ProgettoEsame/functions.cpp"
# 1 "/home/Giovanni/CLionProjects/ProgettoEsame/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/Giovanni/CLionProjects/ProgettoEsame/functions.cpp"

# 1 "/home/Giovanni/CLionProjects/ProgettoEsame/functions.h" 1





int Factorial(int n);
# 3 "/home/Giovanni/CLionProjects/ProgettoEsame/functions.cpp" 2

int Factorial(int n) {
    int result = 1;
    if (n == 0)
        result = 1;
    else {
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
    }
    return result;
}
