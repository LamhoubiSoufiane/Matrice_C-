
#include "main.hpp"
#include "mat.hpp"

using namespace std;


matrice2::matrice2()
{
    colonne=3;
    ligne=3;
    mat=new int*[ligne];
    for(int i=0;i<ligne;i++)
    {
        mat[i]=new int [colonne];
        for(int j=0;j<colonne;j++)
        {
            mat[i][j]=(rand() % 50 + 1);
        }
    }
}

matrice2::matrice2(int l,int c)
{
    colonne=c;
    ligne=l;
    mat=new int*[ligne];
    for(int i=0;i<ligne;i++)
    {
        mat[i]=new int[colonne];
        for(int j=0;j<colonne;j++)
        {
            mat[i][j]=(rand() % 10 + 1);
        }
    }
}

matrice2::matrice2(const matrice2 &m)
{
    colonne=m.colonne;
    ligne=m.ligne;
    mat=new int*[ligne];
    for(int i=0;i<ligne;i++)
    {
        mat[i]=new int[colonne];
        for(int j=0;j<colonne;j++)
        {
            mat[i][j]=m.mat[i][j];
        }
    }
}

matrice2::~matrice2()
{
    for(int i=0;i<ligne;i++) delete[] mat[i]; 
    delete[] mat;
}

matrice2 &matrice2::operator+(const matrice2 &m)
{
    if((ligne != m.ligne) || (colonne != m.colonne)) 
    {
        cout<<"Erreur, les deux matrices n ont pas les meme dimensions"<<endl;
        return *new matrice2(0,0);
    }
    matrice2 *res=new matrice2(ligne,colonne);
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            res->mat[i][j] = mat[i][j] + m.mat[i][j];
        }
    }
    return *res;
}

matrice2 &matrice2::operator-(const matrice2 &m)
{
    if((ligne != m.ligne) || (colonne != m.colonne)) 
    {
        cout<<"Erreur, les deux matrices n ont pas les meme dimensions"<<endl;
        return *new matrice2(0,0);
    }
    matrice2 *res=new matrice2(ligne,colonne);
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            res->mat[i][j] = mat[i][j] - m.mat[i][j];
        }
    }
    return *res;
}

matrice2 &matrice2::operator*(const matrice2 &m)
{
    if(colonne != m.ligne)
    {
        cout<<"Erreur, le nombre de ligne de la 1ere matrice doit correspondre au nombre de colonne de la 2eme matrice"<<endl;
        return *new matrice2(0,0);
    }
    matrice2 *res=new matrice2(ligne,m.colonne);
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<m.colonne;j++)
        {
            res->mat[i][j]=0;
            for(int k=0;k<colonne;k++)
            {
                res->mat[i][j] += mat[i][k] * m.mat[k][j];
            }
            
        }
    }
    return *res;
}

matrice2 &matrice2::operator^(int puiss)
{
    if(colonne != ligne)
    {
        cout<<"Erreur, il s'agit pas d une matrice carré"<<endl;
        return *this;
    }
    else 
    {
        matrice2 *tmp=new matrice2(this->ligne,this->colonne);
        *tmp=*this;
        while (puiss > 1)
        {
            *tmp=(*this) * (*tmp);
            cout<<"puiss == "<<puiss<<endl;
            puiss--;
        }
        return *tmp;
    }
}

void matrice2::operator=(const matrice2 &m)
{
    if((ligne != m.ligne) || (colonne != m.colonne)) 
    {
        cout<<"Erreur, les deux matrices n ont pas les meme dimensions"<<endl;
        exit(1);
    }
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            this->mat[i][j] = m.mat[i][j];
        }
    }
}

void matrice2::afficher()
{
    for(int i=0;i<ligne;i++)
    {
        for(int j=0;j<colonne;j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    
}


