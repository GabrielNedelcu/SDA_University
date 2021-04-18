#include <bits/stdc++.h>

using namespace std;

class Student{

    public:
        char nume[30];
        char prenume[30];
        int nota1;
        int nota2;
        int nota3;
        int nota4;
        int nota5;

        Student(char mNume[30], char mPrenume[30], int mNota1, int mNota2,
                int mNota3, int mNota4, int mNota5){
            strcpy(nume, mNume);
            strcpy(prenume, mPrenume);
            nota1=mNota1;
            nota2=mNota2;
            nota3=mNota3;
            nota4=mNota4;
            nota5=mNota5;
        }

        int bursaMerit();
        int bursaPerformanta();

    private:
        double medie();
        int integralist();
};

double Student::medie(){
    double medie;
    medie=(double)(nota1+nota2+nota3+nota4+nota5)/5;
    return medie;
}

int Student::integralist(){
    if(nota1<5||nota2<5||nota3<5||nota4<5||nota5<5)
        return 0;
    return 1;
}

int Student::bursaMerit(){
    if(medie()>8&&medie()<9.8&&integralist())
        return 1;
    return 0;
}

int Student::bursaPerformanta(){
    if(medie()>=9.80&&integralist())
        return 1;
    return 0;
}

int main(){
    int n;
    char nume[30];
    char prenume[30];
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    int nota5;

    int numar_burse_merit=0;
    int numar_burse_performanta=0;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nume>>prenume>>nota1>>nota2>>nota3>>nota4>>nota5;
        Student student(nume, prenume, nota1, nota2, nota3, nota4, nota5);

        if(student.bursaMerit())
            numar_burse_merit++;
        if(student.bursaPerformanta())
            numar_burse_performanta++;

    }

    cout<<numar_burse_merit<<" "<<numar_burse_performanta;

    return 0;
}
