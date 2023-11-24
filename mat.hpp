#ifndef SRC_MAT_H_
#define SRC_MAT_H_


class matrice2
{
    private:
        int colonne;
        int ligne;
        int **mat;
    public:
        matrice2();
        matrice2(int l,int c);
        matrice2(const matrice2 &m);
        ~matrice2();
        matrice2 &operator+(const matrice2 &);
        matrice2 &operator-(const matrice2 &);
        matrice2 &operator*(const matrice2 &);
        matrice2 &operator^(int);
        void operator=(const matrice2 &);
        void afficher();
};


#endif