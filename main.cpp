#include "main.hpp"
#include "mat.cpp"


int main()
{
    matrice2 mat1(3, 3);
    matrice2 mat2(mat1);
    matrice2 mat3 = mat1 + mat2;
    matrice2 mat4 = mat1 - mat2;
    matrice2 mat5 = mat1 * mat2;
    matrice2 mat6 = mat1 ^ 3;
    matrice2 mat7(3,3);
    mat7 = mat1;
    cout << "Matrice1 :" << endl;
    mat1.afficher();
    cout << "Matrice2 :" << endl;
    mat2.afficher();
    cout << "Addition :" << endl;
    mat3.afficher();
    cout << "Soustraction :" << endl;
    mat4.afficher();
    cout << "Multiplication :" << endl;
    mat5.afficher();
    cout << "Puissance :" << endl;
    mat6.afficher();
    cout << "Assignation :" <<endl;
    mat7.afficher();

    /*auto start = chrono::high_resolution_clock::now();

    matrice2 m1(1000,1000);
    matrice2 m3(1000,1000);
    m3=m1^500;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::seconds>(stop - start);
    cout << "Temps d'execution : " << duration.count() << " secondes" <<endl;
    */
}
